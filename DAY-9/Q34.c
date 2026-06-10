// Write a program to Print reverse number triangle.
// 12345
// 1234
// 123
// 12
// 1
#include<stdio.h>
int main(){
    int n=5;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            printf("%d",j);
        }
        printf("\n");
        n--;
    }
    return 0;
}