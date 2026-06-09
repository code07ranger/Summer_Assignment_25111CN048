// Write a program to Print character triangle.
// A
// AB
// ABC
// ABCD
// ABCDE
#include<stdio.h>
int main(){
    int n=1;
    for(int i=1;i<=5;i++){
        int a=65;
        for(int i=1;i<=n;i++){
        printf("%c",(char)a);
        a++;
        }
    printf("\n");
    n++;
   }
return 0;
}