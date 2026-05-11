#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Transition node */
typedef struct Transition {
    char input;
    int toState;
    struct Transition* next;
} Transition;

/* State node */
typedef struct State {
    int id;
    int isFinal;
    Transition* transitions;
    struct State* next;
} State;

/* NFA structure */
typedef struct NFA {
    State* startState;
    State* states;
} NFA;

/* Create a new state */
State* createState(int id, int isFinal) {
    State* s = (State*)malloc(sizeof(State));
    s->id = id;
    s->isFinal = isFinal;
    s->transitions = NULL;
    s->next = NULL;
    return s;
}

/* Add state to NFA */
void addState(NFA* nfa, State* state) {
    if (nfa->states == NULL)
        nfa->states = state;
    else {
        State* t = nfa->states;
        while (t->next != NULL)
            t = t->next;
        t->next = state;
    }
}

/* Add transition between states */
void addTransition(State* from, char input, int toState) {
    Transition* t = (Transition*)malloc(sizeof(Transition));
    t->input = input;
    t->toState = toState;
    t->next = from->transitions;
    from->transitions = t;
}

/* NFA simulation */
int simulate(NFA* nfa, char* str) {
    int current[100] = {0}, next[100] = {0};

    current[0] = 1;  // start state

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];

        // reset next states
        for (int j = 0; j < 100; j++)
            next[j] = 0;

        State* s = nfa->states;

        // check all active states
        while (s != NULL) {
            if (current[s->id]) {
                Transition* t = s->transitions;

                // follow transitions
                while (t != NULL) {
                    if (t->input == c)
                        next[t->toState] = 1;
                    t = t->next;
                }
            }
            s = s->next;
        }

        // move to next state set
        for (int j = 0; j < 100; j++)
            current[j] = next[j];
    }

    // check if any final state is active
    State* s = nfa->states;
    while (s != NULL) {
        if (current[s->id] && s->isFinal)
            return 1;
        s = s->next;
    }

    return 0;
}

int main() {
    NFA nfa;
    nfa.states = NULL;

    // create states
    State* q0 = createState(0, 0);
    State* q1 = createState(1, 0);
    State* q2 = createState(2, 1);

    // add states to NFA
    addState(&nfa, q0);
    addState(&nfa, q1);
    addState(&nfa, q2);

    // transitions for NFA
    addTransition(q0, 'a', 0);
    addTransition(q0, 'a', 1);
    addTransition(q0, 'b', 0);
    addTransition(q1, 'b', 2);
    addTransition(q2, 'a', 0);
    addTransition(q2, 'a', 1);
    addTransition(q2, 'b', 0);

    char str[100];
    scanf("%s", str);

    // check result
    if (simulate(&nfa, str))
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");

    return 0;
}