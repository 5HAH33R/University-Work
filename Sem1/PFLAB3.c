#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void Q1SwapNumbers()
{
    int num1, num2, Temp;
    printf("Enter Number 1\n");
    scanf("%d", &num1);
    printf("Enter Number 2\n");
    scanf("%d", &num2);

    printf("this is num1 before swap :  %d \n this is num2 before swap :  %d \n", num1, num2);
    Temp = num1;
    num1 = num2;
    num2 = Temp;
    printf("this is num1 after swap :  %d \n this is num2 after swap :  %d \n", num1, num2);
}

void Q2TaxCalculator()
{
    float salary, salaryAfterTax, PercentageTax;
    printf("input your salary\n");
    scanf("%f", &salary);
    printf("input tax percentage\n");
    scanf("%f", &PercentageTax);
    salaryAfterTax = salary - ((PercentageTax / 100) * salary);
    printf("Your salary after tax is %f", salaryAfterTax);
}

void Q3CarAverage()
{
    int Hours;
    printf("Enter a num between 1-5 (hours travelled by the car): ");
    scanf("%d", &Hours);
    if (Hours > 0 && Hours <= 5)
    {
        float DistPerHr, TotalDist, AvgSpeed;
        for (int i = 0; i < Hours; i++)
        {
            printf("enter Distance Travelled in Hour %d\n", i + 1);
            scanf("%f", &DistPerHr);
            TotalDist = TotalDist + DistPerHr;
        }
        AvgSpeed = TotalDist / Hours;
        printf("Avg speed is %f", AvgSpeed);
    }
    else
    {
        printf("Wrong input");
    }
}

void Q4InterestAndProfit()
{
    float Principle, RateOfInterest, Time, PrincipleWithInterest,Profit = 0,Rate ;
    printf("input principle value between 1 - 1,000,000\n");
    scanf("%f", &Principle);
    printf("input Rate of interest (5-10 percent)\n");
    scanf("%f", &RateOfInterest);
    printf("input time (1-10 yrs)\n");
    scanf("%f", &Time);

    PrincipleWithInterest = Principle;

    if (Principle < 1 && Principle > 100000 && RateOfInterest > 10 && RateOfInterest < 5 && Time > 10 && Time < 0)
    {
        printf("wrong input");
    }
    else
    {

        for (int i = 0; i < Time; i++)
        {
            PrincipleWithInterest = PrincipleWithInterest + (PrincipleWithInterest*(RateOfInterest/100));
        }
        Profit = PrincipleWithInterest - Principle;

        printf("Your amount was %f , with an interest rate of %f , you will recieve %f amount , with a profit of %f\n",Principle,RateOfInterest,PrincipleWithInterest,Profit);
    }
}




void Pi() {
    double pi_approx = 0.0, sign = 1.0, denominator = 1.0 , i;

    //printf("Enter the number of terms: ");
    //scanf("%d", &i);

    for (i = 1; i <= 10000; i++) {
        pi_approx = pi_approx + (sign * 4.0 / denominator);
        sign = sign * -1.0;
        denominator = denominator + 2.0;


        if (pi_approx >= 3.14) {
            printf("Reached 3.14 after %d terms.\n", i);
        }

        if (pi_approx >= 3.141) {
            printf("Reached 3.141 after %d terms.\n", i);
        }

        if (pi_approx >= 3.1415) {
            printf("Reached 3.1415 after %d terms.\n", i);
        }

        if (pi_approx >= 3.14159) {
            printf("Reached 3.14159 after %d terms.\n", i);
            break;
        }
    }
}

void Pi2(){
    int i;
    double pi = 0.0;
    double term;

    //printf("Terms\tApproximation of π\n");

    for (i = 1; ; i++) {
        term = pow(-1, i + 1)/(2 * i - 1);
        pi += term;

        if (fabs(4 * pi - 3.14) < 0.0001) {
            printf("Reached 3.14 at term %d\n", i);
            break;
        }
    }
    
    for (i = 1; ; i++) {
        term = pow(-1, i + 1)/(2 * i - 1);
        pi += term;

        if (fabs(4 * pi - 3.141) < 0.0001) {
            printf("Reached 3.141 at term %d\n", i);
            break;
        }
    }

    for (i = 1; ; i++) {
        term = pow(-1, i + 1)/(2 * i - 1);
        pi += term;
    
        if (fabs(4 * pi - 3.1415) < 0.0001) {
            printf("Reached 3.1415 at term %d\n", i);
            break;
        }
    }

    for (i = 1; ; i++) {
        term = pow(-1, i + 1)/(2 * i - 1);
        pi += term;
    
        if (fabs(4 * pi - 3.14159) < 0.00001) {
            printf("Reached 3.14159 at term %d\n", i);
            break;
        }
    }

}


int main()
{
    Pi2();
    return 0;
}