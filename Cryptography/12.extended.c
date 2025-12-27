#include <stdio.h>
// Function to implement the Extended Euclidean Algorithm
// It returns GCD of a and b, and the coefficients x and y such that ax + by = gcd(a, b)
int extended_euclidean_algorithm(int a, int b, int *x, int *y) {
if (b == 0) {
*x = 1;
*y = 0;
return a; // Base case: gcd(a, 0) = a
}
int x1, y1;
int gcd = extended_euclidean_algorithm(b, a % b, &x1, &y1);
// Update x and y using the results of the recursive call
*x = y1;
*y = x1 - (a / b) * y1;
return gcd; // Return the GCD
}
int
main() {
printf("Sasank Lama (79010254)\nLab12\n");
int a, b, x, y;
// Taking input from the user
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
// Calling the Extended Euclidean Algorithm function
int gcd = extended_euclidean_algorithm(a, b, &x, &y);
// Displaying the result
printf("The GCD of %d and %d is: %d\n", a, b, gcd);
printf("Coefficients x and y are: %d and %d\n", x, y);
printf("The equation is: %d * %d + %d * %d = %d\n", a, x, b, y, gcd);
return 0;
}
