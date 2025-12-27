#include <stdio.h>

void fibonacci(int n){
    int a=0,b=1,e;
    printf("%d %d",a,b);
    for(int i=2; i<n; i++){
        e=a+b;
        printf("%d",e);
        a=b;
        b=e;
    }
    printf("\n");
}

int main(){
    printf("Sasank Lama \n");
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if(n<2){
        printf("Number of terms must be at least 2. \n");
        return 1;
    }
    fibonacci(n);
    return 0;
}
