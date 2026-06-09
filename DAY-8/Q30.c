//Write a program to Print number triangle.
// 1
// 12
// 123
// 1234
// 12345
#include<stdio.h>
int main(){
    int n=1;
    for(int i=1;i<=5;i++){
        int a=1;
        for(int i=1;i<=n;i++){
        printf("%d",a);
        a++;
        }
    printf("\n");
    n++;
   }
return 0;
}