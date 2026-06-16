//Write a program to Write function for palindrome.
#include<stdio.h>
void palindrome(int a){
    int og=a;
    int r=0,s=0;
    while(a!=0){
    r=a%10;
    s=s*10+r;
    a=a/10;
    }
    if(og==s){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
    return;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    palindrome(n);
    return 0;
}