//Write a program to Recursive sum of digits.
#include<stdio.h>
int sum(int a){
    if (a==0) return 0;
    int r=a%10;
    a=a/10;
    int x=sum(a)+r;
    return x;
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int m=sum(n);
    printf("Sum of digits of %d is %d",n,m);
    return 0;
}