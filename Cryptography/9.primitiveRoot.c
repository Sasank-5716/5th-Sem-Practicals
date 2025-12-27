#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Function to check if a number is prime
int isPrime(int num) {
if (num < 2) return 0;
for (int i = 2; i <= sqrt(num); i++) {
if (num % i == 0)
return 0;
}
return 1;
}
// Function to perform modular exponentiation
int power(int base, int exp, int mod) {
int result = 1;
base = base % mod;
while (exp > 0) {
if (exp % 2 == 1)
result = (result * base) % mod;
exp = exp / 2;
base = (base * base) % mod;
}
return result;
}
// Function to find prime factors of n and store in array
int findPrimeFactors(int n, int factors[]) {
int count = 0;
if (n % 2 == 0) {
factors[count++] = 2;
while (n % 2 == 0)
n /= 2;
}
for (int i = 3; i <= sqrt(n); i += 2) {
if (n % i == 0) {
factors[count++] = i;
while (n % i == 0)
n /= i;
}
}
if (n > 2)
factors[count++] = n;
return count;
}
// Check if g is primitive root of p
int isPrimitiveRoot(int g, int p, int factors[], int count) {
for (int i = 0; i < count; i++) {
if (power(g, (p - 1) / factors[i], p) == 1)
return 0; // <-- fixed missing semicolon here
}
return 1;
}
int main() {
printf("Sasank Lama (79010254)\nLab 9\n");
int p;
printf("Enter a prime number: ");
scanf("%d", &p);
if (!isPrime(p)) {
printf("Error: The number must be prime!\n");
return 1;
}
int phi = p - 1;
int factors[100];
int count = findPrimeFactors(phi, factors);
for (int g = 2; g < p; g++) {
if (isPrimitiveRoot(g, p, factors, count)) {
printf("The smallest primitive root of %d is: %d\n", p, g);

return 0;
}
}
printf("No primitive root found.\n");
return 0;
}
