//Write a program to Reverse a string.
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    printf("enter string:");
    fgets(s,sizeof(s),stdin);
    int n=strlen(s);
    int i=0,j=n-1;
    while(i<j){
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    puts(s);
    return 0;
}