#include <stdio.h>
#include <string.h>
void vernamCipher(char text[], char key[], char result[]) {
int i;
for (i = 0; text[i] != '\0'; i++) {
result[i] = text[i] ^ key[i]; // XOR each character
}
result[i] = '\0'; // Null-terminate the result
}
int main() {
printf("Sasank Lama(79010254) \n");
char plaintext[100], key[100], encrypted[100], decrypted[100];
printf("Enter the plaintext: ");
fgets(plaintext, sizeof(plaintext), stdin);
plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline
printf("Enter the key (same length as plaintext): ");
fgets(key, sizeof(key), stdin);
key[strcspn(key, "\n")] = '\0'; // remove newline
if (strlen(plaintext) != strlen(key)) {
printf("Error: Key length must be equal to plaintext length.\n");
return 1;
}
// Encryption
vernamCipher(plaintext, key, encrypted);
printf("Encrypted text (ASCII values): ");
for (int i = 0; encrypted[i] != '\0'; i++) {
printf("%d ", (unsigned char)encrypted[i]); // show ASCII
}
printf("\n");
// Decryption
vernamCipher(encrypted, key, decrypted);
printf("Decrypted text: %s\n", decrypted);
return 0;
}
