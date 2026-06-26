//Write a program to Count words in a sentence.
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    printf("Enter a string: ");
    gets(s);
    int l=strlen(s);
    int i=0,word=0;
    while(i<l){
        if(s[i]==' ' && s[i+1]!=' '){
            word++;
        }
        i++;
    }
    printf("%d",word+1);
    return 0;
}