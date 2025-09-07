#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Q1_FtoK()
{
    float FH;
    printf("insert Farenheit");
    scanf("%f", &FH);
    FH = ((FH - 32) * (0.55)) + 273;
    printf("%f", FH);
    return 0;
}


int Q2_Area()
{
    // insert math.h
    float Rad;
    float pi = 3.14159265358979323846264338327950288419716939937510;
    printf("insert RAD");
    scanf("%f", &Rad);
    float Area;
    Area = pi * pow(Rad, 2);
    printf("%f", Area);
    return 0;
}


int Q3_KmToM()
{
    int Km_hr;
    printf("insert km/hr");
    scanf("%d", &Km_hr);
    printf("M_hr = %d", Km_hr * 1000);
    return 0;
}


int Q4_hrAndMinToSec()
{
    int hrs, min, sec;
    printf("insert hr");
    scanf("%d", &hrs);
    printf("insert min");
    scanf("%d", &min);

    printf("%d", sec = (hrs * 3600) + (min * 60));
    return 0;
}


int Q5_Angle()
{
    int angleA, angleB, UnknownAngle;
    printf("insert angle A");
    scanf("%d", &angleA);
    printf("insert angle B");
    scanf("%d", &angleB);
    UnknownAngle = 360 - angleB - angleA;
    printf("%d", UnknownAngle);
}


int Q6_YrToDay()
{
    int yr, day;
    printf("insert How old u are");
    scanf("%d", &yr);
    printf("%d", day = yr * 365);
}


int Q7_PrintLargerNum()
{
    int num1, num2;
    printf("insert num1 \n");
    scanf("%d", &num1);
    printf("insert num2 \n");
    scanf("%d", &num2);
    if (num1 > num2)
    {
        printf("larger num is = ");
        printf("%d", num1);
    }
    else
    {
        printf("larger num is = ");
        printf("%d", num2);
    }
    return 0;
}


int Q8_Divby7()
{
    int num;
    printf("insert num");
    scanf("%d", &num);
    if (num % 7 == 0)
    {
         printf("Divisible");
    }
    else
    {
        printf("Not Divisible");
    }
}


int main()
{
    FunctionName();  //function name corresponding to the answer
    return 0;
}