#include <stdio.h>
#include <string.h>
// Function to perform XOR encryption/decryption
void oneTimePad(char input[], char key[], char output[]) {
int i;
for (i = 0; input[i] != '\0'; i++) {
output[i] = input[i] ^ key[i];
}
output[i] = '\0'; // Null-terminate the string
}
int main() {
printf("\nSasank Lama (79010254)\nLab 6\n");
char plaintext[100], key[100], ciphertext[100], decrypted[100];
printf("Enter the plaintext: ");
fgets(plaintext, sizeof(plaintext), stdin);
plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline
printf("Enter the key (same length as plaintext): ");
fgets(key, sizeof(key), stdin);
key[strcspn(key, "\n")] = '\0'; // Remove newline
if (strlen(plaintext) != strlen(key)) {
printf("Error: Key length must match plaintext length!\n");
return 1;
}
// Encryption
oneTimePad(plaintext, key, ciphertext);
printf("\nEncrypted (in ASCII values): ");
for (int i = 0; ciphertext[i] != '\0'; i++) {
printf("%d ", (unsigned char)ciphertext[i]);
}
// Decryption
oneTimePad(ciphertext, key, decrypted);
printf("\nDecrypted text: %s\n", decrypted);

return 0;
}
