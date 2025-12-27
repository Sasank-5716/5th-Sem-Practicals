#include <stdio.h>
#include <string.h>
void shiftCipher(char text[], int shift) {
for (int i = 0; text[i] != '\0'; i++) {
char ch = text[i];
if (ch >= 'a' && ch <= 'z') {
text[i] = ((ch - 'a' + shift) % 26) + 'a';
}
else if (ch >= 'A' && ch <= 'Z') {
text[i] = ((ch - 'A' + shift) % 26) + 'A';
}
}
}
int main() {
printf("Sasank Lama(79010254)\nLab 2\n");
char text[100];
int shift;
printf("Enter the plaintext: ");
fgets(text, sizeof(text), stdin); // safer than gets()
text[strcspn(text, "\n")] = '\0'; // remove newline if present
printf("Enter the shift value (1-25): ");
scanf("%d", &shift);
// Ensure shift value is within 1 to 25
shift = shift % 26;
shiftCipher(text, shift);
printf("Encrypted text using Shift Cipher: %s\n", text);
return 0;
}
