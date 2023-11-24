#include <stdio.h>
#include <stdlib.h>

// Function to print a polynomial
void printPolynomial(int poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i < n - 1 && poly[i + 1] != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(int poly1[], int n1, int poly2[], int n2) {
    int maxSize = (n1 > n2) ? n1 : n2;
    int result[maxSize];

    for (int i = 0; i < maxSize; i++) {
        int term1 = (i < n1) ? poly1[i] : 0;
        int term2 = (i < n2) ? poly2[i] : 0;
        result[i] = term1 + term2;
    }

    printf("Sum: ");
    printPolynomial(result, maxSize);
}

// Function to multiply two polynomials
void multiplyPolynomials(int poly1[], int n1, int poly2[], int n2) {
    int maxSize = n1 + n2 - 1;
    int result[maxSize];

    for (int i = 0; i < maxSize; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    printf("Product: ");
    printPolynomial(result, maxSize);
}

int main() {
    int n1, n2;

    printf("Enter the degree of Polynomial 1: ");
    scanf("%d", &n1);
    
    int poly1[n1 + 1];
    printf("Enter the coefficients of Polynomial 1 from highest degree to constant term:\n");
    for (int i = n1; i >= 0; i--) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of Polynomial 2: ");
    scanf("%d", &n2);
    
    int poly2[n2 + 1];
    printf("Enter the coefficients of Polynomial 2 from highest degree to constant term:\n");
    for (int i = n2; i >= 0; i--) {
        scanf("%d", &poly2[i]);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1, n1 + 1);

    printf("Polynomial 2: ");
    printPolynomial(poly2, n2 + 1);

    addPolynomials(poly1, n1 + 1, poly2, n2 + 1);
    multiplyPolynomials(poly1, n1 + 1, poly2, n2 + 1);

    return 0;
}