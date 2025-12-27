#include <stdio.h>
#include <string.h>
void caesarCipher(char text[], int shift) {
for (int i = 0; text[i] != '\0'; i++) {
char ch = text[i];
if (ch >= 'a' && ch <= 'z')
text[i] = (ch - 'a' + shift) % 26 + 'a';
else if (ch >= 'A' && ch <= 'Z')
text[i] = (ch - 'A' + shift) % 26 + 'A';
}}
int main() {
printf("Sasank Lama (79010254)\nLab1\n");
char text[100];
int shift;
printf("Enter text: ");
fgets(text, sizeof(text), stdin);
text[strcspn(text, "\n")] = 0;
printf("Enter shift: ");
scanf("%d", &shift);
caesarCipher(text, shift);
printf("Ciphered text: %s\n", text);
return 0;
}
