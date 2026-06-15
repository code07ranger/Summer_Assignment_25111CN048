//Write a program to Write function to find maximum.
#include<stdio.h>
int max(int a,int b){
    if(a<b) return b;
    else return a;
}
int main(){
    int a;
    printf("Enter first number: ");
    scanf("%d",&a);
    int b;
    printf("Enter second number: ");
    scanf("%d",&b);
    int m=max(a,b);
    printf("The maximum of %d and %d is %d",a,b,m);
    return 0;
}