// Write a program to Print repeated-number pattern.
// 1
// 22
// 333
// 4444
// 55555
#include<stdio.h>
int main(){
    int n=1;
    int a=1;
    for(int i=1;i<=5;i++){
        for(int i=1;i<=n;i++){
        printf("%d",a);
        }
    printf("\n");
    n++;
    a++;
   }
return 0;
}