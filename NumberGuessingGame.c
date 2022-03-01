/** NumberGuessingGame.c
 * 
 * Program which allows the user to guess a number between 1 and 10 (or a different user-specified maximum)
 * 
 * TODO:
 * Implement function to printMenu() to print menu, prompt user input, and act based on input:
 *  - Press 1 to play a game
 *  - Press 2 to change the max number
 *  - Press 3 to quit
 * 
 * Implement function guessNumber(int answer) that loops, asking user to guess the number:
 *  - prints higher or lower based on number
 *  - if user wins, return to menu
 *  - if q is pressed, game ends (counts as loss) and returns to menu
 * 
 * On program end, display all games and how many guesses it took (or if they quit)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Changes the max number by asking user input. Returns the new maximum
int changeMax() {
    printf("Enter a new max (between 2 and %d)\n",INT_MAX);
    int input;
    scanf("%d",&input);
    fflush(stdin);

    if(input < 2 || input >= INT_MAX) {
        printf("Enter a valid number.\n",INT_MAX);
        changeMax();
    }
    else {
        return input;
    }
}

// Prints the menu, loops or calls function based on user input
void printMenu() {
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    int input;
    scanf("%d",&input);
    fflush(stdin);
    
    int maxNumber = 10;

    switch(input) {
        case 1:
            //startGame()
        case 2:
            maxNumber = changeMax();
            printf("%d", maxNumber);
        case 3:
            return;
        default:
            printf("Invalid input, please enter a valid input.\n");
            printMenu();
    }
}

int main() {
    // TODO
    printMenu();
}

