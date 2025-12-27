#include <stdio.h>
#include <math.h>
// Function to calculate (base^exp) % mod efficiently
long long int power(long long int base, long long int exp, long long int mod) {
long long int result = 1;
while (exp > 0) {
if (exp % 2 == 1)
result = (result * base) % mod;
exp = exp >> 1;
base = (base * base) % mod;
}return result;
}
int main() {
printf("Sasank Lama (79010254)\n");
long long int P = 23; // Prime number
long long int G = 5; // Primitive root
long long int a = 6; // Alice's private key
long long int b = 15; // Bob's private key
long long int A = power(G, a, P); // Alice's public key
long long int B = power(G, b, P); // Bob's public key
long long int key_A = power(B, a, P); // Shared secret for Alice
long long int key_B = power(A, b, P); // Shared secret for Bob
printf("Prime Number (P): %lld\n", P);
printf("Primitive Root (G): %lld\n", G);
printf("Alice's Private Key: %lld\n", a);
printf("Bob's Private Key: %lld\n", b);
printf("Alice's Public Key (A): %lld\n", A);
printf("Bob's Public Key (B): %lld\n", B);
printf("Shared Secret Key (Alice): %lld\n", key_A);
printf("Shared Secret Key (Bob): %lld\n", key_B);
if (key_A == key_B) {
printf("Key Exchange Successful! Both parties share the same key.\n");
} else {
printf("Key Exchange Failed! Shared keys do not match.\n");
}

return 0;
}
