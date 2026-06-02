// write a code to print reverse of a given number and store it
#include<stdio.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    int r=0;
    while (n!=0)// can be written as n>0
    {   r=r*10;
        r=(n%10)+r;
        n=n/10;
    }
    printf("the reversed number is: %d",r);
    return 0;
}