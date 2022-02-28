/** RestaurantBill.c
 * 
 * TODO:
 * Add random meal cost, choose from values $9.95, $4.55, $13.25, $22.35
 * Calculate cost with tax and tip
 * Format and display meal cost, tax amount, tip amount, total bill
 * 
 * Output format example:
 * Meal cost: $9.95
 * Tax amount: 10%
 * Tip amount: 15%
 * Total: $12.59
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // Make sure number of command line arguments is correct
        printf("Incorrect number of command line arguments specified.");
        printf("Enter the arguments as percentages in this order: tax, tip");
        return -1;
    }
    
    // Get tax and tip amounts from arguments and convert from percentages to decimal
    float tax = atof(argv[1]) / 100;
    float tip = atof(argv[2]) / 100;

    printf("%f,%f",tax,tip);
}