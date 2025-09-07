#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void Q1Factorial()
{
    int number, factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("number is negative");
    }
    else
    {
        for (int i = number; i > 0; i--)
        {
            factorial *= i;
        }

        printf("Factorial of %d is %d\n", number, factorial);
    }
}

void Q2FibWithForLoop()
{
    int a = 1, b = 1, NextNum, sum = 0;

    printf("Fibonacci series up to 1000:\n%d %d ", a, b);
    for (int i = 3; i < 17; i++)
    {
        NextNum = a + b;
        printf("%d ", NextNum);
        if (NextNum % 3 == 0 || NextNum % 5 == 0 || NextNum % 7 == 0)
        {
            sum += NextNum;
        }
        a = b;
        b = NextNum;
    }
    printf("\nSum of numbers divisible by 3, 5,7: %d", sum);
}

void Q2FibWithWhileLoop()
{
    int a = 1, b = 1, NextNum, i = 0, sum = 0;

    printf("Fibonacci series up to 1000:\n%d %d ", a, b);
    while (i < 14)
    {
        NextNum = a + b;
        printf("%d ", NextNum);
        if (NextNum % 3 == 0 || NextNum % 5 == 0 || NextNum % 7 == 0)
        {
            sum += NextNum;
        }
        a = b;
        b = NextNum;
        i = i + 1;
    }
    printf("\nSum of numbers divisible by 3,5,7 : %d\n", sum);
}

#include <stdbool.h>
int Q3input5Nums()
{
    int num, sumOfDigits = 0, temp;
    bool isPrime = true, isPalindrome = false;

    printf("Enter a 5-digit number: ");
    scanf("%d", &num);

    if (num < 10000 || num > 99999)
    {
        printf("The number is not a 5 digit number.\n");
        return 0;
    }

    temp = num;
    while (temp != 0)
    {
        sumOfDigits += temp % 10;
        temp /= 10;
    }

    if (sumOfDigits % 2 == 0)
    {

        if (num <= 1)
        {
            isPrime = false;
        }
        else
        {
            for (int i = 2; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
        {
            printf("The sum of digits is even and the number %d is prime.\n", num);
        }
        else
        {
            printf("The sum of digits is even and the number %d is not prime.\n", num);
        }
    }
    else
    {
        int original = num, reversed = 0, remainder;
        temp = num;
        while (temp != 0)
        {
            remainder = temp % 10;
            reversed = reversed * 10 + remainder;
            temp /= 10;
        }

        if (original == reversed)
        {
            isPalindrome = true;
        }

        if (isPalindrome)
        {
            printf("The sum of digits is odd and the number %d is a palindrome.\n", num);
        }
        else
        {
            printf("The sum of digits is odd and the number %d is not a palindrome.\n", num);
        }
    }

    return 0;
}


int main()
{
    Q3input5Nums();

    return 0;
}