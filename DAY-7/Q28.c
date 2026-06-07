//Write a program to Recursive reverse number.
#include<stdio.h>
int reverse(int a,int b){
    if(a==0) return b;
    int r=a%10;
    a=a/10;
    b=b*10+r;
    int x=reverse(a,b);
    return x;
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int m=reverse(n,0);
    printf("Reverse of %d is %d",n,m);
    return 0;
}