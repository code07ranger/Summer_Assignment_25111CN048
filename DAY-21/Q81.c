//Write a program to Find string length without strlen().
#include<stdio.h>
#include<string.h>
int main(){
 char s[100];
 printf("enter string:");
 fgets(s,sizeof(s),stdin);
 int c=0;
    while(s[c]!='\0'){
        c++;
    }
  if(c>0 && s[c-1]=='\n'){
    c--;
}
 printf("length of string:%d",c);
    return 0;
}