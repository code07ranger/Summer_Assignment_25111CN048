//Write a program to Remove spaces from string.
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string:");
    gets(str);
    int l=strlen(str);
    int i=0,j=0;
    while(i<l){
        if(str[i]!=' '){
            str[j]=str[i];
            j++;
        }
       i++;
    }
    str[j]='\0';
   puts(str);
    return 0;
}