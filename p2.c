#include <stdio.h>
#include <string.h>

int main() {

    int states = 4;
    int startState = 1;
    int finalState = 2;

    int transitionTable[4][2] = {
        {2, 3},
        {1, 4},
        {4, 1},
        {3, 2}
    };

    char inputString[] = "abbabab";
    int length = strlen(inputString);

    int currentState = startState;

    for (int i = 0; i < length; i++) {
        char input = inputString[i];

        if (input == 'a') {
            currentState = transitionTable[currentState - 1][0];
        } else if (input == 'b') {
            currentState = transitionTable[currentState - 1][1];
        } else {
            printf("Invalid input '%c' encountered\n", input);
            return 1;
        }
    }

    if (currentState == finalState) {
        printf("The input string '%s' is accepted\n", inputString);
    } else {
        printf("The input string '%s' is rejected\n", inputString);
    }

    return 0;
}
