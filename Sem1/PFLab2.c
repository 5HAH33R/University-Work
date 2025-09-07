#include <stdio.h>
#include <windows.h>

// Q1. Write a C Program to play beep five times

// Answer

int Beep5Times()
{
    for (int i = 0; i < 5; i++)
    {
        Beep(700, 500);
    }
    return 0;
}

/*
   Q2. What does the following code print?
       printf( "*\n**\n***\n****\n*****\n" );


    Answer :
                *
                **
                ***
                ****
                *****
*/

// Q3 Write a C program to print the following shapes using escape sequences.

int Shape1()
{
    printf(" * \n *\t* \n *\t*\t* \n *\t*\t*\t*");
    return 0;
}

int Shape2()
{
    printf(" * \n *\t* \n *\t*\t* \n *\t* \n *");
    return 0;
}

//
// Q4 Write a program that prints the following shapes with asterisks

int Square()
{
    for (int i = 0; i < 8; i++)
    {
        printf("*");
    }

    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        printf("*      *\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("*");
    }
    return 0;
}

int Circle()
{
    printf("    *** \n");
    printf("   *   *\n");
    printf(" *       *\n");
    printf(" *       *\n");
    printf(" *       *\n");
    printf(" *       *\n");
    printf(" *       *\n");
    printf("   *   * \n");
    printf("    ***\n");
    return 0;
}

int Arrow()
{
    printf("  * \n");
    printf(" ***\n");
    printf("*****\n");
    printf("  *  \n");
    printf("  *  \n");
    printf("  *  \n");
    printf("  *  \n");
    printf("  *  \n");
    return 0;
}

int Diamond()
{
    printf("    *  \n");
    printf("   * * \n");
    printf("  *   * \n");
    printf(" *     * \n");
    printf("*       * \n");
    printf(" *     * \n");
    printf("  *   * \n");
    printf("   * * \n");
    printf("    *  \n");
    return 0;
}

int main()
{
    // Q1

    // Beep5Times();

    // Q3

    // Shape1();
    // Shape2():

    // Q4

    // Square();
    // Circle();
    // Arrow();
    // Diamond();

    return 0;
}