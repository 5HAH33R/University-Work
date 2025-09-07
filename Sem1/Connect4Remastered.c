#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

void PrintPositions(int Rows)
{
    printf("\n");
    for (int i = 1; i < Rows + 1; i++)
    {
        printf("%d  ", i);
    }
}

int main()
{
    int Rows, Columns, ColumntoInsert;

    printf("how many rows do u want (max 10) = ");
    scanf("%d", &Rows);
    printf("how many columns do u want (max 10) = ");
    scanf("%d", &Columns);
    char BoardArray[Rows][Columns];

    //GenerateTable(Rows, Columns);

    for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Columns; j++)
            {
                BoardArray[i][j] = '|';
            }
        }
        for (int i = 0; i < Rows; i++)
        {
            printf("\n");
            for (int j = 0; j < Columns; j++)
            {
                printf("%c", BoardArray[i][j]);
                printf("  ");
            }
        }

    PrintPositions(Rows);

    printf("choose a num to play : ");
    scanf("%d",&ColumntoInsert);

    for (int i = 0 ; i < ColumntoInsert; i++)
    {
        for (int j = Rows; j>0; j--)
        {
            if (BoardArray[j][ColumntoInsert-1] == '|')
            {
                BoardArray[j][ColumntoInsert-1] = 'X';
                break;
            }
            

        }
        break;
    }

    for (int i = 0; i < Rows; i++)
        {
            printf("\n");
            for (int j = 0; j < Columns; j++)
            {
                printf("%c", BoardArray[i][j]);
                printf("  ");
            }
        }
    
    return 0;

    
}