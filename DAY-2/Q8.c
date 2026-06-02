//Write a program to Check whether a number is palindrome
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int og=n;
    //og=original number
    int r=0,s=0;
    while(n!=0){
        r=n%10;
        s=s*10+r;
        n/=10;
     }
     if(og==s){
        printf("palindrome");
     }
     else{
        printf("not palindrome");
     }
    return 0;
}