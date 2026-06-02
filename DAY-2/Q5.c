// write a program to print sum of digits of a given number
#include<stdio.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    int s=0;
    int ld=0;
    //s=sum ,ld = lastdigit
    while (n!=0)
    {
        ld= n%10;
        s=s+ld;
        n=n/10;
    }
        printf("the sum of digits is: %d",s);
    return 0;
}