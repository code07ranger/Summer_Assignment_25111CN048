//Write a program to Find product of digit
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int r=0,s=1;
    while(n!=0){
        r=n%10;
        s=s*r;
        n=n/10;
    }
    printf("the product of digits are: %d",s);
    return 0;
}