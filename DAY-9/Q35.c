// Write a program to Print repeated character pattern.
// A
// BB
// CCC
// DDDD
// EEEEE
#include<stdio.h>
int main(){
    int n=1;
    int a=65;
    for(int i=1;i<=5;i++){
        for(int i=1;i<=n;i++){
        printf("%c",(char)a);
        }
    printf("\n");
    n++;
    a++;
   }
return 0;
}