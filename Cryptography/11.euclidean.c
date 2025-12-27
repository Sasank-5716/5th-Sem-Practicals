#include <stdio.h>
int euclidean_algorithm(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}

int main() {
printf("Sasank Lama (79010254)\nLab11\n");
int a, b;
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
int gcd = euclidean_algorithm(a, b);
printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", a, b, gcd);

return 0;
}
