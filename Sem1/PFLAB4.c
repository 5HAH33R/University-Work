#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
Q1 Write a C program to input a character from user and check whether given character is small
alphabet, capital alphabet, digit or special character, using if else.

*/

void Q1CharChekcer()
{
    char Char;
    printf("input a character\n");
    scanf("%c", &Char);
    if (isupper(Char))
    {
        printf("the letter is UpperCase");
    }
    if (islower(Char))
    {
        printf("the letter is LowerCase");
    }
    if (isdigit(Char))
    {
        printf("Digit");
    }
    if (ispunct(Char))
    {
        printf("special character");
    }
}

/*
Q2 : An online shopping store is providing discounts on the items due to the Eid. If the cost of items
    is more than 1999 it will give a discount up to 50%. If the cost of shopping is 2000 to 4000, a 20%
    discount will be applied. If the cost of shopping is 4001 to 6000, a 30% discount will be applied.
    If it's more than 6000 then 50% discount will be applied to the cost of shopping. Print the actual
    amount, saved amount and the amount after discount.

*/

void Q2EidDiscount()
{
    int price, saved, final;
    printf("Enter price of Product\n");
    scanf("%d", &price);
    if (price < 1999)
    {
        printf("You are not eligible for a discount");
    }
    else if (price > 1999 && price < 4001)
    {
        printf("the price was %d\n", price);
        printf("You saved %d\n", saved = (0.2 * price));
        printf("the final price is %d\n", final = price - saved);
    }
    else if (price > 4000 && price < 6001)
    {
        printf("the price was %d\n", price);
        printf("You saved %d\n", saved = (0.3 * price));
        printf("the final price is %d\n", final = price - saved);
    }
    else if (price > 6000)
    {
        printf("the price was %d\n", price);
        printf("You saved %d\n", saved = (0.5 * price));
        printf("the final price is %d\n", final = price - saved);
    }
}

void Q3QuadraticRoots()
{
    int a, b, c;
    printf("enter a \n");
    scanf("%d", &a);

    printf("enter b \n");
    scanf("%d", &b);

    printf("enter c \n");
    scanf("%d", &c);

    float root1, root2;
    root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    root2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    printf("root 1 is : %f \n", root1);
    printf("root 2 is : %f \n", root2);
}

void Q4DivisibleBy7()
{
    int input, Mod, Divided;
    printf("input the Number");
    scanf("%d", &input);
    while (input != 7 && input != -7 && input != 0)
    {
        Mod = input % 10;
        Divided = input / 10;
        input = Divided - (2 * Mod);
    }
    printf("%d", input);
}

void Q5Fat_Calories()
{
    float Percentage, FatInFood, CaloriesInFood;
    printf("input Fat in the food\n");
    scanf("%f", &FatInFood);
    printf("input Calories in the food\n");
    scanf("%f", &CaloriesInFood);
    if (CaloriesInFood < FatInFood)
    {
        printf("Wrong input\n");
    }
    if (CaloriesInFood < 0 || FatInFood < 0)
    {
        printf("One Value is Less than 0\n");
    }

    Percentage = ((FatInFood * 9) / CaloriesInFood) * 100;

    if (Percentage > 0 && Percentage < 30)
    {
        printf("The percentage is %f And the food is low in fat", Percentage);
    }
    else if (Percentage > 0)
    {
        printf("The percentage is %f", Percentage);
    }
}

int main()
{
    //Q1CharChekcer();
    // Q2EidDiscount();
    // Q3QuadraticRoots();
    //Q4DivisibleBy7();
    Q5Fat_Calories();
    return 0;
}