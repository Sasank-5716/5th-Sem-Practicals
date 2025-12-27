#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MOD 26
int modInverse(int det, int mod) {
det = det % mod;
for (int x = 1; x < mod; x++) {
if ((det * x) % mod == 1)
return x;
}
return -1;
}
int invertKey(int key[2][2], int inverseKey[2][2]) {
int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
det = (det % MOD + MOD) % MOD;
int detInv = modInverse(det, MOD);
if (detInv == -1) return 0;
inverseKey[0][0] = (key[1][1] * detInv) % MOD;
inverseKey[0][1] = (-key[0][1] * detInv + MOD) % MOD;
inverseKey[1][0] = (-key[1][0] * detInv + MOD) % MOD;
inverseKey[1][1] = (key[0][0] * detInv) % MOD;
return 1;
}
void textToNumbers(char text[], int numbers[], int size) {
for (int i = 0; i < size; i++)
numbers[i] = toupper(text[i]) - 'A';
}
void numbersToText(int numbers[], char text[], int size) {
for (int i = 0; i < size; i++)
text[i] = (numbers[i] % MOD) + 'A';
text[size] = '\0';
}
void encrypt(int key[2][2], char text[]) {
int length = strlen(text);
int textNums[length], cipherNums[length];
textToNumbers(text, textNums, length);
for (int i = 0; i < length; i += 2) {
cipherNums[i] = (key[0][0] * textNums[i] + key[0][1] * textNums[i + 1]) % MOD;
cipherNums[i+1] = (key[1][0] * textNums[i] + key[1][1] * textNums[i + 1]) % MOD;
}
numbersToText(cipherNums, text, length);
printf("Encrypted Text: %s\n", text);
}
void decrypt(int key[2][2], char text[]) {
int length = strlen(text);
int inverseKey[2][2];
if (!invertKey(key, inverseKey)) {
printf("Decryption not possible (Key matrix is not invertible).\n");
return;
}
int textNums[length], decryptedNums[length];
textToNumbers(text, textNums, length);
for (int i = 0; i < length; i += 2) {
decryptedNums[i] = (inverseKey[0][0] * textNums[i] + inverseKey[0][1] * textNums[i + 1]) %
MOD;
decryptedNums[i+1] = (inverseKey[1][0] * textNums[i] + inverseKey[1][1] * textNums[i + 1]) %
MOD;
}
numbersToText(decryptedNums, text, length);
printf("Decrypted Text: %s\n", text);
}
int main() {
printf("Sasank Lama(79010254)\n");
int key[2][2];
char text[100];
int choice;
printf("Enter 2x2 key matrix (only numbers 0-25):\n");
for (int i = 0; i < 2; i++)
for (int j = 0; j < 2; j++)
scanf("%d", &key[i][j]);
printf("Enter text (must be even length, letters only): ");
scanf("%s", text);
if (strlen(text) % 2 != 0) {
printf("Error: Text length must be even for Hill Cipher.\n");
return 1;
}
printf("Choose operation:\n1. Encrypt\n2. Decrypt\nChoice: ");
scanf("%d", &choice);
if (choice == 1)
encrypt(key, text);
else if (choice == 2)
decrypt(key, text);
else
printf("Invalid choice!\n");
return 0;
}
