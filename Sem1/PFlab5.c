#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void Q1Deletion()
{
    char input;

    printf("Are you sure to delete [Y/y] / [N/n] ? ");
    scanf(" %c", &input);

    switch (input)
    {
    case 'Y':
    case 'y':
        printf("Deleted successfully\n");
        break;
    case 'N':
    case 'n':
        printf("Delete cancelled\n");
        break;
    default:
        printf("Choose the right option\n");
    }

}

void Q3Marks()
{
    float fscMarks;
    float fscPercentage, ntsPercentage;

    printf("Enter your F.Sc marks (out of 1100): ");
    scanf("%f", &fscMarks);
    printf("Enter your NTS marks (out of 100): ");
    scanf("%f", &ntsPercentage);

    fscPercentage = (fscMarks / 1100) * 100;

    if (fscPercentage > 70 && ntsPercentage >= 70)
    {
        printf("Allocated seat in OxfordIT department.\n");
    }
    else if (fscPercentage > 70 && ntsPercentage >= 60)
    {
        printf("Allocated seat in Electronics department.\n");
    }
    else if (fscPercentage > 70 && ntsPercentage >= 50)
    {
        printf("Allocated seat in Telecommunication department.\n");
    }
    else if (fscPercentage >= 60 && fscPercentage <= 70 && ntsPercentage >= 50)
    {
        printf("Allocated seat in MITIT department.\n");
    }
    else if (fscPercentage >= 50 && fscPercentage <= 59 && ntsPercentage >= 50)
    {
        printf("Allocated seat in Chemical department.\n");
    }
    else if (fscPercentage > 40 && fscPercentage < 50 && ntsPercentage >= 50)
    {
        printf("Allocated seat in Computer department.\n");
    }
    else
    {
        printf("No suitable department found for your marks.\n");
    }

}

void Q4Snacks()
{
    int numTypes, quantity, totalCost = 0;
    char choice;

    printf("Menu:\n");
    printf("B = burger (Rs. 200)\n");
    printf("F = french Fries (Rs. 50)\n");
    printf("P = pizza (Rs. 500)\n");
    printf("S = sandwiches (Rs. 150)\n");

    printf("Enter the number of types of snacks you want to order: ");
    scanf("%d", &numTypes);

    for (int i = 0; i < numTypes; i++)
    {
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        switch (choice)
        {
        case 'B':
        case 'b':
            totalCost += 200 * quantity;
            break;
        case 'F':
        case 'f':
            totalCost += 50 * quantity;
            break;
        case 'P':
        case 'p':
            totalCost += 500 * quantity;
            break;
        case 'S':
        case 's':
            totalCost += 150 * quantity;
            break;
        default:
            printf("wrong choice\n");
        }
    }

    printf("Total charges for the order: %d\n",totalCost);
}
int main()
{
    Q4Snacks();
    return 0;
}