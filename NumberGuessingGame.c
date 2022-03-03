/** NumberGuessingGame.c
 * 
 * Program which allows the user to guess a number between 1 and 10 (or a different user-specified maximum)
 * 
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

// Prints a properly formatted list of results from a GameResult array paramater
void printResults(GameResult results[8192], int numGames) {
    printf("\nThank you for playing");
    if(numGames == 0) { // user didn't even play a game...
        printf("...\nNext time, please play a game!");
        return;
    }
    printf("!\nResults:\n");
    for(int i = 0; i < numGames; i++) { // loop through array
        GameResult cur = results[i];
        printf("Game %d: ",i+1);
        printf("Correct answer: %d, ",cur.answer);
        if (cur.numGuesses == -1) {
            printf("Number not guessed.");
        }
        else {
            printf("Number of guesses: %d.\n",cur.numGuesses);
        }
    }
}

// Changes the max number by asking user input. Returns the new maximum
int changeMax() {
    printf("Enter a new maximum number (between 2 and %d): ",INT_MAX);
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
    char *ptr;

    // Game loop
    while(1) { // Breaks out of loop when win condition is met or user quits
        printf("Enter a guess from 1 to %d (q to quit): ",maxNumber);
        fgets(input, 20, stdin); // get input from user
        fflush(stdin);
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { // remove newline from input, if exists
            input[strlen(input) - 1] = '\0';
        }

        if(strcmp(input,"q") == 0) { // check if user quit
            GameResult r = {-1, answer}; // count as a loss
            results[gameNumber-1] = r;
            return;
        }
        int guess = strtol(input, &ptr, 10); // convert guess to integer (base 10), store string part in ptr

        if(strcmp(ptr, "") != 0 || guess < 1 || guess > maxNumber) { // guess wasn't numeric or out of bounds - invalid
            printf("Invalid guess - please enter a valid guess between 1 and %d.\n",maxNumber);
            continue;
        }

        numGuesses++; // only increment number of guesses for a valid guess

        if(guess == answer) { // User won
            printf("Congratulations, you guessed the number in %d guesses.\n",numGuesses);
            GameResult r = {numGuesses, answer};
            results[gameNumber-1] = r;
            return;
        }

        if(guess > answer) {
            printf("Guess too high, try again.\n");
        }
        else {
            printf("Guess too low, try again.\n");
        }
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
    int input;
    int maxNumber = 10;
    int numGames = 0;
    GameResult results[8192]; // maximum number of games

    while(1) { // loop until user quits
        printMenu();
        scanf("%d",&input);
        fflush(stdin);
        switch(input) {
            case 1: // start game
                numGames++;
                if(numGames >= 8192) {
                    printf("Maximum number of games reached.\n");
                    return;
                }
                startGame(results, maxNumber, numGames);
                break;
            case 2: // change max guess
                maxNumber = changeMax();
                break;
            case 3: // end program
                printResults(results, numGames);
                return;
            default:
                printf("Invalid input, please enter a valid input.\n");
                continue;
        }
    }
    return;
}

int main() {
    initGame();
    return 0;
}

