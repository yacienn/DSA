#include <stdio.h>
#include <string.h>

#define MAX_STATES 10

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    // state set: 0 = q0, 1 = q1, 2 = q2
    int current[MAX_STATES] = {0};
    int next[MAX_STATES];

    current[0] = 1; // start in q0

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];

        // reset next states
        for (int j = 0; j < MAX_STATES; j++)
            next[j] = 0;

        for (int state = 0; state < 3; state++) {
            if (current[state]) {

                if (state == 0) {
                    if (c == 'a') {
                        next[0] = 1;
                        next[1] = 1;
                    }
                    if (c == 'b') {
                        next[0] = 1;
                    }
                }

                else if (state == 1) {
                    if (c == 'b') {
                        next[2] = 1;
                    }
                }

                else if (state == 2) {
                    if (c == 'a') {
                        next[0] = 1;
                        next[1] = 1;
                    }
                    if (c == 'b') {
                        next[0] = 1;
                    }
                }
            }
        }

        // copy next → current
        for (int j = 0; j < 3; j++) {
            current[j] = next[j];
        }
    }

    // check accept state q2
    if (current[2])
        printf("acc (ends with ab)\n");
    else
        printf("rej\n");

    return 0;
}