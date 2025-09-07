#include <stdio.h>

int main()
{
    FILE *file;
    float col1, col2, col3;
    float sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;

    file = fopen("budge.txt", "w");
    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }
    fprintf(file, "-462.13 486.47 973.79\n");
    fprintf(file, "755.42 843.04 -963.67\n");
    fprintf(file, "442.58 -843.02 -462.86\n");

    fprintf(file, "-233.93 -821.67 399.59\n");
    fprintf(file, "-379.65 -556.37 837.46\n");
    fprintf(file, "55.18 -144.93 -93.15\n");
    fprintf(file, "533.73 804.64 -66.25\n");
    fprintf(file, "-922.12 914.68 -264.67\n");
    fprintf(file, "-600.27 -838.59 747.02\n");
    fprintf(file, "-962.97 49.96 -677.79\n");

    fclose(file);

    file = fopen("budge.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(file, "%f %f %f", &col1, &col2, &col3) == 3)
    {
        sum1 += col1;
        sum2 += col2;
        sum3 += col3;
    }

    fclose(file);
    printf("Sum of each column is: %.2f %.2f %.2f\n", sum1, sum2, sum3);

    return 0;
}