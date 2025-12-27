#include <stdio.h>

// 1. Euclidean Algorithm (Iterative)
int gcd(int a, int b) {
    while (b != 0) {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}


int main() {
    printf("Sasank Lama \n");
    int x, y;  // Example numbers

    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);
    printf("GCD of %d and %d is %d \n",x,y,gcd(x,y));

    return 0;
}
