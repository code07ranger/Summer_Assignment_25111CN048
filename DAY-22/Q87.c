//Write a program to Character frequency.
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string:");
    gets(str);
    printf("Enter character: ");
    char r;
    scanf("%c",&r);
    int l=strlen(str);
    int freq=0;
    for(int i=0;i<l;i++){
        if(str[i]==r){
            freq++;
        }
    }
    printf("%d",freq);
    return 0;
}