#include <stdio.h>
#include <ctype.h>
#include <string.h>
int check(char table[5][5], char k) {
for (int i = 0; i < 5; ++i)
for (int j = 0; j < 5; ++j)
if (table[i][j] == k)
return 0;
return 1;
}
int main() {
printf("\nSasank Lama (79010254)\n");
int i, j, key_len;
char table[5][5];
// Initialize table with '0'
for (i = 0; i < 5; ++i)
for (j = 0; j < 5; ++j)
table[i][j] = '0';
printf("********** Playfair Cipher ************\n\n");
// Get key
printf("Enter the length of the Key: ");
scanf("%d", &key_len);
getchar(); // clear newline
char key[key_len + 1];
printf("Enter the Key: ");
fgets(key, sizeof(key), stdin);
key[strcspn(key, "\n")] = '\0'; // remove newline
// Replace 'j' with 'i'
for (i = 0; i < key_len; ++i)
if (key[i] == 'j')
key[i] = 'i';
// Fill table with key characters
int count = 0, flag;
for (i = 0; i < 5; ++i) {
for (j = 0; j < 5; ++j) {
while (count < key_len && !check(table, key[count]))
++count;
if (count < key_len) {
table[i][j] = key[count];
++count;
}}}
// Fill remaining letters
char ch = 'a';
for (i = 0; i < 5; ++i) {
for (j = 0; j < 5; ++j) {
if (table[i][j] == '0') {
while (!check(table, ch) || ch == 'j')
++ch;
table[i][j] = ch;
++ch;
}}}
// Display the table
printf("The table is as follows:\n");
for (i = 0; i < 5; ++i) {
for (j = 0; j < 5; ++j)
printf("%c ", table[i][j]);
printf("\n");
}
// Input plaintext
int l;
printf("\nEnter the length of the plaintext (without spaces): ");
scanf("%d", &l);
getchar(); // clear newline
char p[l + 1];
printf("Enter the Plain text: ");
fgets(p, sizeof(p), stdin);
p[strcspn(p, "\n")] = '\0';
// Replace 'j' with 'i'
for (i = 0; i < l; ++i)
if (p[i] == 'j')
p[i] = 'i';
printf("\nThe replaced text (j with i): ");
for (i = 0; i < l; ++i)
printf("%c ", p[i]);
printf("\n");
// Insert bogus characters
char p1[200];
int k = 0;
for (i = 0; i < l; i++) {
p1[k++] = p[i];
if (i + 1 < l && p[i] == p[i + 1]) {
p1[k++] = (p[i] == 'x') ? 'z' : 'x';
}}
if (k % 2 != 0)
p1[k++] = (p1[k - 1] == 'x') ? 'z' : 'x';
int length = k;
printf("Final prepared text: ");
for (i = 0; i < length; ++i)
printf("%c ", p1[i]);
printf("\n");
// Encrypt using Playfair rules
char cipher_text[200];
int r1, r2, c1, c2;
for (i = 0; i < length; i += 2) {
char a = p1[i], b = p1[i + 1];
for (r1 = 0; r1 < 5; r1++)
for (c1 = 0; c1 < 5; c1++)
if (table[r1][c1] == a)
goto found1;
found1:
for (r2 = 0; r2 < 5; r2++)
for (c2 = 0; c2 < 5; c2++)
if (table[r2][c2] == b)
goto found2;
found2:
if (r1 == r2) {
cipher_text[i] = table[r1][(c1 + 1) % 5];
cipher_text[i + 1] = table[r2][(c2 + 1) % 5];
} else if (c1 == c2) {
cipher_text[i] = table[(r1 + 1) % 5][c1];
cipher_text[i + 1] = table[(r2 + 1) % 5][c2];
} else {
cipher_text[i] = table[r1][c2];
cipher_text[i + 1] = table[r2][c1];
}}
printf("\nThe Cipher text is:\n");
for (i = 0; i < length; ++i)
printf("%c ", cipher_text[i]);
return 0;
}
