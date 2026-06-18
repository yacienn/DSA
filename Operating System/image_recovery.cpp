#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

struct FileSignature {
    std::string extension;
    std::vector<std::uint8_t> header;
    std::vector<std::uint8_t> footer;
    std::size_t extraBytesAfterFooter;
};

int main() {
    const std::string drivePath = "\\\\.\\H:";

    HANDLE hDisk = CreateFileA(
        drivePath.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hDisk == INVALID_HANDLE_VALUE) {
        std::cerr << "[-] Error: Access denied. Failed to open target block device.\n";
        return 1;
    }

    std::cout << "[+] Connected to raw storage volume: " << drivePath << "\n";
    std::cout << "[+] Initializing structural data carving engine...\n\n";

    const std::vector<FileSignature> targetSignatures = {
        { "jpg", {0xFF, 0xD8, 0xFF}, {0xFF, 0xD9}, 0 },
        { "png", {0x89, 0x50, 0x4E, 0x47}, {0x49, 0x45, 0x4E, 0x44}, 4 }
    };

    const DWORD BLOCK_SIZE = 4096;
    std::vector<std::uint8_t> buffer(BLOCK_SIZE);
    DWORD bytesRead = 0;

    bool isCarving = false;
    FileSignature activeSig;
    std::ofstream outFile;
    std::uint32_t recoveredCount = 0;
    std::size_t extraBytesCounter = 0;

    while (ReadFile(hDisk, buffer.data(), BLOCK_SIZE, &bytesRead, nullptr) && bytesRead > 0) {

        for (size_t i = 0; i < bytesRead; ++i) {

            if (!isCarving) {
                for (const auto& sig : targetSignatures) {
                    if (i + sig.header.size() <= bytesRead) {
                        bool match = true;
                        for (size_t j = 0; j < sig.header.size(); ++j) {
                            if (buffer[i + j] != sig.header[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            isCarving = true;
                            activeSig = sig;
                            extraBytesCounter = 0;

                            std::string fileName = "recovered_" + std::to_string(recoveredCount++) + "." + activeSig.extension;
                            outFile.open(fileName, std::ios::binary);

                            std::cout << "[+] Hit pattern [" << activeSig.extension << "] -> Extracting to payload: " << fileName << "\n";
                            break;
                        }
                    }
                }
            }

            if (isCarving) {
                outFile.put(buffer[i]);

                if (extraBytesCounter == 0) {
                    if (i + activeSig.footer.size() <= bytesRead) {
                        bool footerMatch = true;
                        for (size_t j = 0; j < activeSig.footer.size(); ++j) {
                            if (buffer[i + j] != activeSig.footer[j]) {
                                footerMatch = false;
                                break;
                            }
                        }
                        if (footerMatch) {
                            extraBytesCounter = activeSig.footer.size() + activeSig.extraBytesAfterFooter - 1;

                            if (extraBytesCounter == 0) {
                                isCarving = false;
                                outFile.close();
                                std::cout << "[*] Stream finalized. Object persistent.\n";
                            }
                        }
                    }
                } else {
                    extraBytesCounter--;
                    if (extraBytesCounter == 0) {
                        isCarving = false;
                        outFile.close();
                        std::cout << "[*] Stream finalized (CRC appended). Object persistent.\n";
                    }
                }
            }
        }
    }

    CloseHandle(hDisk);
    std::cout << "\n[+] Forensic pipeline finished scanning.\n";
    std::cout << "[+] Total recovered objects: " << recoveredCount << "\n";

    return 0;
}
