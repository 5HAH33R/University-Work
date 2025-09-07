#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Q1

// void CountFrequency(int size) {
//     int array[size], i, j, count;

//     for (i = 0; i < size; i++) {
//         array[i] = rand() % 11;
//     }

//     printf("Array elements: ");
//     for (i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     for (i = 0; i < size; i++) {
//         count = 1;
//         for (j = i + 1; j < size; j++) {
//             if (array[i] == array[j]) {
//                 count++;
//                 array[j] = -1;
//             }
//         }
//         if (array[i] != -1) {
//             printf("%d occurs %d times\n", array[i], count);
//         }
//     }
// }

// int main() {
//     int size;

//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     CountFrequency(size);

//     return 0;
// }

//



// //Q2

// void assignPosition(int marks, int experience) {
//     if (marks >= 70 && experience >= 2) {
//         printf("You are selected as an Associate Developer.\n");
//     } else if (marks >= 60 && experience >= 1) {
//         printf("You are selected as an Assistant Developer.\n");
//     } else if (marks >= 50) {
//         printf("You are selected as a Trainee Engineer.\n");
//     } else {
//         printf("Sorry, you did not meet the requirements.\n");
//     }
// }

// int main() {
//     int marks, experience;

//     printf("Enter your test marks: ");
//     scanf("%d", &marks);

//     if (marks >= 60) {
//         printf("Enter your experience in years: ");
//         scanf("%d", &experience);
//     }

//     assignPosition(marks, experience);

//     return 0;
// }


// //


// Q3


// void volumeCal(int h, int a) {
//     float volume = (a * a * h) / 3.0;
//     printf("The volume of the pyramid is: %f\n", volume);
// }


// void getData(int h, int a) {
//     printf("Enter the height of the pyramid: ");
//     scanf("%d", &h);

//     printf("Enter the base of the pyramid: ");
//     scanf("%d", &a);

//     volumeCal(h, a);
// }
// int main() {
//     int height, base;

//     getData(height, base);
    

//     return 0;
// }

//


// // Q4

// int main() {
//     float num;

//     printf("Enter a positive number: ");
//     scanf("%f", &num);

//     num = roundf(num * 100) / 100;

//     printf("Rounded number: %.2f\n", num);

//     return 0;
// }

// //

// Q5

void displayInstructions() {
    printf("This program calculates the total cost of a house after 5 years.\n");
    printf("Please enter the following information for each set of data:\n");
    printf("1. Initial House Cost\n");
    printf("2. Annual Fuel Cost\n");
    printf("3. Annual Tax Rate (as a decimal)\n\n");
}

float calculateTotalCost(float initialCost, float annualFuelCost, float taxRate) {
    float totalFuelCost = annualFuelCost * 5;
    float totalTaxes = initialCost * taxRate * 5;
    float totalCost = initialCost + totalFuelCost + totalTaxes;
    return totalCost;
}

int main() {
    displayInstructions();

    float initialCost, annualFuelCost, taxRate, totalCost;

    for (int i = 1; i <= 3; i++) {
        printf("\nEnter data for set %d:\n", i);
        printf("Initial House Cost: ");
        scanf("%f", &initialCost);

        printf("Annual Fuel Cost: ");
        scanf("%f", &annualFuelCost);

        printf("Annual Tax Rate: ");
        scanf("%f", &taxRate);

        totalCost = calculateTotalCost(initialCost, annualFuelCost, taxRate);
        printf("Total cost for set %d: %.2f\n", i, totalCost);
    }

    return 0;
}

//