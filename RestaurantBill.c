/** RestaurantBill.c
 * 
 * Calculates the total cost of a randomly-selected meal based on tax and tip.
 * Tip is on the pre-tax amount of the meal.
 * Tax and tip are specified as command-line arguments, with or without a percent symbol.
 * Tax and tip are assumed to be integer amounts (10% or 15%, not 17.5%).
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // Make sure number of command line arguments is correct
        printf("Incorrect number of command line arguments specified.\n");
        printf("Enter the arguments as percentages in this order: tax, tip");
        return -1;
    }
    
    // Get tax and tip amounts from arguments and convert from percentages to decimal
    float tax = atof(argv[1]) / 100;
    float tip = atof(argv[2]) / 100;

    // Generate random meal cost
    srand(time(NULL)); // use time for a random seed
    int randIndex = rand() % 4;
    const char meals[4][10] = {"Salad", "Soup", "Sandwich", "Pizza"};
    float mealCosts[4] = {9.95, 4.55, 13.25, 22.35};
    float mealCost = mealCosts[randIndex];

    // Calculate final (tip is on the pre-tax amount)
    float taxCost = mealCost * tax;
    float tipCost = mealCost * tip;
    float finalCost = mealCost + taxCost + tipCost;

    // Print formatted results
    printf("Cost of %s: $%.2f\n", meals[randIndex], mealCost);
    printf("Tax amount: $%.2f\n", taxCost);
    printf("Tip amount: $%.2f\n", tipCost);
    printf("Total: $%.2f\n", finalCost);
}