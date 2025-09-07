#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


void Q1_NameBackWords()
{
    char Fname[50];
    char Lname[50];
    printf("Enter your First Name: ");
    scanf("%s", &Fname);
    printf("Enter your Last Name: ");
    scanf("%s", &Lname);
    char Fullname[150];
    int j = strlen(Fullname);
    strcpy(Fullname, Fname);
    strcat(Fullname, " ");
    strcat(Fullname, Lname);
    for (int i = strlen(Fullname); i > -1; i--)
    {
        printf("%c", Fullname[i]);
    }
}

void Q2_MaxFreqChar()
{
    char Name[100], course[1000];
    int MaxFreq = 0, MAxChar;
    int Freq[256] = {0};

    printf("Enter your name: ");
    scanf("%s", &Name);

    printf("Enter courses offered (separated by commas): ");
    scanf("%s", &course);

    for (int i = 0; Name[i] != '\0'; i++)
    {
        Freq[Name[i]]++;
        if (Freq[Name[i]] > MaxFreq)
        {
            MaxFreq = Freq[Name[i]];
            MAxChar = Name[i];
        }
    }

    for (int i = 0; course[i] != '\0'; i++)
    {
        if (course[i] != ',')
        {
            Freq[course[i]]++;
            if (Freq[course[i]] > MaxFreq)
            {
                MaxFreq = Freq[course[i]];
                MAxChar = course[i];
            }
        }
    }
    printf("most frequent character is %c,  frequency =  %d\n", MAxChar, MaxFreq);
}


void Q3_StringComparison(){
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (strcmp(str1, str2) == 0) {
        printf("Both strings are equal.\n");
    } else if (strcmp(str1, str2) < 0) {
        printf("%s is smaller than %s.\n", str1, str2);
    } else {
        printf("%s is greater than %s.\n", str1, str2);
    }

}
int main()
{
    //Q1_NameBackWords();
    //Q2_MaxFreqChar();
    Q3_StringComparison();

    return 0;
}