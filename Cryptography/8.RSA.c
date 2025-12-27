#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long int gcd(long long int a, long long int b) {
if (b == 0)
return a;
return gcd(b, a % b);
}
long long int mod_exp(long long int base, long long int exp, long long int mod) {
long long int result = 1;
base = base % mod;
while (exp > 0) {
if (exp % 2 == 1)
result = (result * base) % mod;
exp = exp >> 1;
base = (base * base) % mod;
}
return result;
}
int main() {
printf("Sasank Lama (79010254)\nLab8");
long long int p = 61, q = 53;
long long int n = p * q;
long long int phi = (p - 1) * (q - 1);
long long int e = 2;
while (gcd(e, phi) != 1)
e++;
long long int d = 1;
while ((d * e) % phi != 1)
d++;
char message[] = "HELLO";
printf("\n Original Message: %s\n", message);
long long int encrypted[10];
for (int i = 0; i < strlen(message); i++) {
encrypted[i] = mod_exp(message[i], e, n);
}
printf("Encrypted Message: ");
for (int i = 0; i < strlen(message); i++) {
printf("%lld ", encrypted[i]);
}
printf("\n");
printf("Decrypted Message: ");
for (int i = 0; i < strlen(message); i++) {
printf("%c", (char)mod_exp(encrypted[i], d, n));
}
printf("\n");
return 0;
}
