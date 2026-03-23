#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hProcess = GetCurrentProcess();

    if (SetPriorityClass(hProcess, REALTIME_PRIORITY_CLASS)) {
        printf("Priority set to REALTIME!\n");
    } else {
        printf("Failed to set priority\n");
    }


    while(1) {}

    return 0;
}
