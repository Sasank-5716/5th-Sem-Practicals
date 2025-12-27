#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
// Function to encrypt using Rail Fence Cipher (Row Transformation)
void railFenceEncrypt(char text[], int key) {
int len = strlen(text);
char rail[key][len];
// Fill the rail matrix with empty spaces
for (int i = 0; i < key; i++)
for (int j = 0; j < len; j++)
rail[i][j] = '\n';
int row = 0, col = 0, dir = 1;
for (int i = 0; i < len; i++) {
rail[row][col++] = text[i];
if (row == 0)
dir = 1;
else if (row == key - 1)
dir = -1;
row += dir;
} printf("Rail Fence Encrypted Text: ");
for (int i = 0; i < key; i++)
for (int j = 0; j < len; j++)
if (rail[i][j] != '\n')
printf("%c", rail[i][j]);
printf("\n");
}
void columnEncrypt(char text[], int key) {
int len = strlen(text);
int row = (len + key - 1) / key; // Number of rows
int col = key; // Number of columns
char matrix[row][col];
int index = 0;
for (int i = 0; i < row; i++)
for (int j = 0; j < col; j++)
matrix[i][j] = (index < len) ? text[index++] : 'X';
printf("Columnar Transposition Encrypted Text: ");
for (int j = 0; j < col; j++)
for (int i = 0; i < row; i++)
printf("%c", matrix[i][j]);
printf("\n");
}
int main() {
printf("Sasank Lama(79010254)");
char text[MAX];
int key;
printf("Enter text (uppercase, no spaces): ");
scanf("%s", text);
printf("Enter key (integer value): ");
scanf("%d", &key);
railFenceEncrypt(text, key);
columnEncrypt(text, key);
return 0;
}
