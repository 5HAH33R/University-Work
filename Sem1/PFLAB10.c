#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


//Q1 and Q2
struct Employee {
    int id;
    char name[50];
    float salary;
    char department[50];
};

int main() {
    struct Employee Employee1;

    printf("Enter employee ID: ");
    scanf("%d", &Employee1.id);

    printf("Enter employee name: ");
    scanf("%s", Employee1.name);

    printf("Enter employee salary: ");
    scanf("%f", &Employee1.salary);

    printf("Enter employee department: ");
    scanf("%s", Employee1.department);

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", Employee1.id);
    printf("Name: %s\n", Employee1.name);
    printf("Salary: %.2f\n", Employee1.salary);
    printf("Department: %s\n", Employee1.department);

    return 0;
}

// Q3


struct PhoneNumber {
    int areaCode;
    int exchange;
    int number;
};

int main() {
    struct PhoneNumber phone1, phone2;

    phone1.areaCode = 212;
    phone1.exchange = 767;
    phone1.number = 8900;

    printf("Enter area code: ");
    scanf("%d", &phone2.areaCode);

    printf("Enter exchange: ");
    scanf("%d", &phone2.exchange);

    printf("Enter number: ");
    scanf("%d", &phone2.number);

    printf("My number is (%d) %d-%d\n", phone1.areaCode, phone1.exchange, phone1.number);
    printf("Your number is (%d) %d-%d\n", phone2.areaCode, phone2.exchange, phone2.number);

    return 0;
}

//

//Q4


struct Course {
    char name[50];
    float GPA;
};

struct Address {
    char street[50];
    char city[50];
    char state[50];
    int zip;
};

struct Student {
    float CGPA;
    struct Course courses[5];
    struct Address address;
};

int main() {
    struct Student student1, student2;

    printf("Enter details for Student 1:\n");
    printf("Enter CGPA: ");
    scanf("%f", &student1.CGPA);

    for (int i = 0; i < 2; i++) {
        printf("Enter course name for course %d: ", i + 1);
        scanf("%s", student1.courses[i].name);
        printf("Enter GPA for course %d: ", i + 1);
        scanf("%f", &student1.courses[i].GPA);
    }

    printf("Enter address for Student 1:\n");
    printf("Street: ");
    scanf("%s", student1.address.street);
    printf("City: ");
    scanf("%s", student1.address.city);
    printf("State: ");
    scanf("%s", student1.address.state);
    printf("ZIP: ");
    scanf("%d", &student1.address.zip);

    printf("\nEnter details for Student 2:\n");
    printf("Enter CGPA: ");
    scanf("%f", &student2.CGPA);

    for (int i = 0; i < 2; i++) {
        printf("Enter course name for course %d: ", i + 1);
        scanf("%s", student2.courses[i].name);
        printf("Enter GPA for course %d: ", i + 1);
        scanf("%f", &student2.courses[i].GPA);
    }

    printf("Enter address for Student 2:\n");
    printf("Street: ");
    scanf("%s", student2.address.street);
    printf("City: ");
    scanf("%s", student2.address.city);
    printf("State: ");
    scanf("%s", student2.address.state);
    printf("ZIP: ");
    scanf("%d", &student2.address.zip);

    if (student1.CGPA > student2.CGPA) {
        printf("\nStudent 1 has a higher CGPA.\n");
    } else if (student2.CGPA > student1.CGPA) {
        printf("\nStudent 2 has a higher CGPA.\n");
    } else {
        printf("\nBoth students have the same CGPA.\n");
    }

    for (int i = 0; i < 2; i++) {
        if (student1.courses[i].GPA > student2.courses[i].GPA) {
            printf("Student 1 has a higher GPA in %s\n", student1.courses[i].name);
        } else if (student2.courses[i].GPA > student1.courses[i].GPA) {
            printf("Student 2 has a higher GPA in %s\n", student2.courses[i].name);
        } else {
            printf("Both students have the same GPA in %s\n", student1.courses[i].name);
        }
    }

    return 0;
}

// 


// Q5

struct Complex {
    float real;
    float imag;
};

void readComplex(struct Complex *c) {
    printf("Enter real part: ");
    scanf("%f", &c->real);
    printf("Enter imaginary part: ");
    scanf("%f", &c->imag);
}

void printComplex(struct Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("Enter the second complex number:\n");
    readComplex(&num2);

    printf("\nFirst Complex Number: ");
    printComplex(num1);

    printf("Second Complex Number: ");
    printComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers: ");
    printComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers: ");
    printComplex(product);

    return 0;
}



