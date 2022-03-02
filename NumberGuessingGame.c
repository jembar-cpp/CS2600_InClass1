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
#include <string.h>

// Result of a game. If number of guesses is -1, the game was a loss. Otherwise, it was a win.
typedef struct GameResult {
    int numGuesses;
    int answer;
} GameResult;

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

// Starts the game, writes win statistics to character array and accepts max number as parameter.
// Requires game number as parameter.
void startGame(GameResult results[8192], int maxNumber, int gameNumber) {
    srand(time(NULL)); // use time for a random seed
    int answer = (rand() % maxNumber) + 1; // generate random number between 1 and max
    int numGuesses = 0;
    int guess;
    char input[20];

    // Game loop
    while(1) { // Breaks out of loop when win condition is met or user quits
        numGuesses++;
        printf("Enter a guess from 1 to %d: ",maxNumber);
        fgets(input, 20, stdin); // get input from user
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }

        if(strcmp(input,"q") == 0) { // check if user quit
            // end game
        }

        if(guess == answer) { // User won
            printf("Congratulations, you guessed the number in %d guesses.\n",numGuesses);
            GameResult r = {numGuesses, answer};
            results[gameNumber-1] = r;
        }
        return;
    }
}

// Prints the formatted menu
void printMenu() {
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
}

// Initializes the game, keeps track of number of games, wins, and maximum number
void initGame() {
    printMenu();
    int input;
    scanf("%d",&input);
    fflush(stdin);
    
    int maxNumber = 10;
    int numGames = 0;
    GameResult results[8192]; // maximum number of games

    switch(input) {
        case 1:
            numGames++;
            if(numGames >= 8192) {
                printf("Maximum number of games reached.\n");
                return;
            }
            startGame(results, maxNumber, numGames);
            break;
        case 2:
            maxNumber = changeMax();
            break;
        case 3:
            return;
        default:
            printf("Invalid input, please enter a valid input.\n");
            initGame();
    }
}

int main() {
    // TODO
    initGame();
}

