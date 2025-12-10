#include <stdio.h>
#include <stdlib.h>

// Frame structure to simulate recursive calls
typedef struct Frame {
    int n;
    char from, to, aux;
    int stage;              // 0 or 1
    struct Frame* next;
} Frame;

// Linked-list stack
Frame* top = NULL;

// push frame onto stack
void push(int n, char from, char to, char aux, int stage) {
    Frame* node = (Frame*)malloc(sizeof(Frame));
    node->n = n;
    node->from = from;
    node->to = to;
    node->aux = aux;
    node->stage = stage;
    node->next = top;
    top = node;
}

// pop frame from stack
Frame pop() {
    Frame temp = *top;
    Frame* del = top;
    top = top->next;
    free(del);
    return temp;
}

// check empty stack
int isEmpty() {
    return top == NULL;
}

int main() {
    int n = 30;

    
    push(n, 'A', 'C', 'B', 0);

    while (!isEmpty()) {
        Frame cur = pop();

        if (cur.n == 1) {
            printf("Move disk 1 from %c to %c\n", cur.from, cur.to);
            continue;
        }

        if (cur.stage == 0) {
            cur.stage = 1;
            push(cur.n, cur.from, cur.to, cur.aux, 1);

            push(cur.n - 1, cur.from, cur.aux, cur.to, 0);

        } else if (cur.stage == 1) {
            printf("Move disk %d from %c to %c\n", cur.n, cur.from, cur.to);

            push(cur.n - 1, cur.aux, cur.to, cur.from, 0);
        }
    }

    return 0;
}
