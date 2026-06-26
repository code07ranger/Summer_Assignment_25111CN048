//Write a program to Check palindrome string.
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int ispalin(char s[100]){
    int l=strlen(s);
     int i=0,j=l-1;
    while(i<j){
        if(s[i]!=s[j]){
          return false;
        }
        i++,j--;
    }
    return true;
}
int main(){
    char s[100];
    printf("Enter a string: ");
    scanf("%s",s);
    if(ispalin(s)){
        printf("String is palindrome");
    }
    else{
        printf("string not palindrome");
    }
    return 0;
}