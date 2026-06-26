//Write a program to Count vowels and consonants.
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    printf("enter string:");
    fgets(s,sizeof(s),stdin);
    int n=strlen(s);
    int vow=0,con=0,sp=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
            vow++;
        }
        else if(s[i]=='\n'){
            sp++;
        }
        else{
            con++;
        }
    }
    printf("Vowels:%d\n",vow);
    printf("Consonant:%d",con-sp);
    return 0;
}