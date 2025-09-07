#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Book
{
    char Title[100];
    char Author[50];
    int YOP;
};

struct Library
{
    char LibraryName[100];
    struct Book BookArr[5];
};

void printLib()
{
    struct Library lib1 = {};
    strcpy(lib1.LibraryName, "City Library");
    // book 1
    strcpy(lib1.BookArr[0].Title, "Sample Name for book 1");
    strcpy(lib1.BookArr[0].Author, "Sample Author for book 1");
    lib1.BookArr[0].YOP = 123;
    // book 2
    strcpy(lib1.BookArr[1].Title, "Sample Name for book 2");
    strcpy(lib1.BookArr[1].Author, "Sample Author for book 2");
    lib1.BookArr[1].YOP = 456;

    printf("%s \n \n", lib1.LibraryName);
    for (int i = 0; i < 2; i++)
    {
        printf("%s \n", lib1.BookArr[i].Title);
        printf("%s \n", lib1.BookArr[i].Author);
        printf("%d \n", lib1.BookArr[i].YOP);
    }
}

struct Student
{
    char name[50];
    int score;
};

void printStuArr()
{
    struct Student StdArr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter name of Student %d \n", i + 1);
        scanf("%s", &StdArr[i].name);
        printf("Enter score of Student %d \n", i + 1);
        scanf("%d", &StdArr[i].score);
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", StdArr[i].name);
        printf("%d\n", StdArr[i].score);
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; StdArr[i].name[j] != '\0'; j++)
        {
            StdArr[i].name[j] = toupper(StdArr[i].name[j]);
        }
        printf("%s\n", StdArr[i].name);
    }
    int highest;
    for (int i = 0; i < 5; i++)
    {
        if (StdArr[i].score > StdArr[i + 1].score)
        {
            highest = StdArr[i].score;
        }
    }
    printf("Highes num is %d", highest);
}

struct Product
{
    int ProdID;
    char ProdName[100];
    float ProdPrice;
    int ProdQuantityInStock;
};

int main()
{
    struct Product ProdArr[3];
    char UserChoice;
    int j = 1;
    printf("would you like to add data? (y,n): ");
    scanf("%c", &UserChoice);
    if (UserChoice == 'y' || UserChoice == 'Y')
    {
        int total;
        int MostExpensive;
        for (int i = 0; i < 3; i++)
        {

            printf("Enter ID of Product %d \n", i + 1);
            scanf("%d", &ProdArr[i].ProdID);
            printf("Enter Name of Product %d \n", i + 1);
            scanf("%s", &ProdArr[i].ProdName);
            printf("Enter Price of Product %d \n", i + 1);
            scanf("%f", &ProdArr[i].ProdPrice);
            printf("Enter Quantity of Product %d \n", i + 1);
            scanf("%d", &ProdArr[i].ProdQuantityInStock);
            printf("\n");

            total = total + (ProdArr[i].ProdPrice * 
            ProdArr[i].ProdQuantityInStock);

            if (ProdArr[i].ProdPrice > ProdArr[i + 1].ProdPrice)
            {
                MostExpensive = ProdArr[i].ProdPrice;
            }
        }
        printf("Total value is %d\n", total);
        for (int i = 0; i < 3; i++)
        {
            if (MostExpensive == ProdArr[i].ProdPrice)
            {
                printf("Most Expensive Product is %s", ProdArr[i].ProdName);
            }
        }
    }
    else if (UserChoice == 'n' || UserChoice == 'N')
    {
        int total;
        int MostExpensive;
        ProdArr[0].ProdID = 1;
        ProdArr[1].ProdID = 2;
        ProdArr[2].ProdID = 3;
        strcpy(ProdArr[0].ProdName, "Product 1");
        strcpy(ProdArr[1].ProdName, "Product 2");
        strcpy(ProdArr[2].ProdName, "Product 3");

        ProdArr[0].ProdPrice = 10.0;
        ProdArr[1].ProdPrice = 20.0;
        ProdArr[2].ProdPrice = 30.0;
        ProdArr[0].ProdQuantityInStock = 100;
        ProdArr[1].ProdQuantityInStock = 200;
        ProdArr[2].ProdQuantityInStock = 300;

        for(int i = 0; i < 3; i++)
        {

            total = total + (ProdArr[i].ProdPrice * ProdArr[i].ProdQuantityInStock);

            if (ProdArr[i].ProdPrice > ProdArr[i + 1].ProdPrice)
            {
                MostExpensive = ProdArr[i].ProdPrice;
            }
        }
        printf("Total value is %d\n", total);
        for (int i = 0; i < 3; i++)
        {
            if (MostExpensive == ProdArr[i].ProdPrice)
            {
                printf("Most Expensive Product is %s", ProdArr[i].ProdName);
            }
        }
    }
    else
    {
        printf("Wrong Choice, Try again");
    }
}
