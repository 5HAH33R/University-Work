#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

Assignment
Q1 Write a C program to find the factorial of a given number using a loop. The factorial of n is calculated as n * (n-1) * (n-2) * ... * 1.
----------------
Q2 Write a program that takes three numbers as input and prints the largest among them using if-else conditions.
---------------
Q3 Write a C program that calculates the sum of the first N natural numbers using a loop. For example, if N = 5, the output should be 1 + 2 + 3 + 4 + 5 = 15.
-----------------
Q4 An admission charge for Theater varies according to
    the age of the person. DEVELOP a
    program to print the ticket charge given the age of the person.

The charges are as follows:

Over 55:
$10.00

21-54:
$15.00

13-20:
$10:00

2-12: $5:00

Under 3:
Free
------------
Q5 Write a program to reverse a given integer. For example, if the input is 1234, the output should be 4321.
--------------
Q6 Write a program to check if a given year is a leap year or not. A leap year is divisible by 4 but not by 100, unless it is also divisible by 400.

*/

// Q1

void Factorial(int Num)
{
    for (int i = Num - 1; i > 1; i--)
    {
        Num = Num * i;
    }
    printf("%d", Num);
}

//

// Q2

void LargestOfThree(int num1, int num2, int num3)
{
    if (num1 > num2 && num1 > num3)
    {
        printf("%d is the largest", num1);
    }
    if (num2 > num1 && num2 > num3)
    {
        printf("%d is the largest", num2);
    }
    if (num3 > num2 && num3 > num1)
    {
        printf("%d is the largest", num3);
    }
}

//

// Q3

void SumOfFirst_N_NaturalNumbers(int Num)
{
    int Ans = 0;
    int i = Num;
    while (i > 0)
    {
        Ans = Ans + i;
        i = i - 1;
    }
    printf("%d", Ans);
}

//

// Q4

void TicketChargeByAge(int Age)
{
    if (Age >= 55)
    {
        printf("$10 Ticket");
    }
    else if (Age >= 21)
    {
        printf("$15 Ticket");
    }
    else if (Age >= 13)
    {
        printf("$10 Ticket");
    }
    else if (Age >= 3)
    {
        printf("$5 Ticket");
    }
    else
    {
        printf("Free");
    }
}

//

// Q5

void ReverseNum(int num)
{
    int reversedNum = 0, remainder;
    while (num != 0)
    {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num /= 10;
    }
    printf("%d is your Reversed Answer", reversedNum);
}

//

// Q6
void LeapYearCheck(int yr)
{
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
    {
        printf("%d is a leap year.", yr);
    }
    else
    {
        printf("not Leap Year Oops");
    }
}
//


int main()
{
    // Factorial(5);
    // LargestOfThree(3,5,6);
    // TicketChargeByAge(12);
    // SumOfFirst_N_NaturalNumbers(10);
    // ReverseNum(1234);
    // LeapYearCheck(2023);
}