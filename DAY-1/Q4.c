// write a program to count digits of a given number
#include<stdio.h>
int main(){
  int n;
  printf("enter a number: ");
  scanf("%d",&n);
  int count=0;
  while (n!=0)
  {
    n=n/10;
    count++;
  }
  printf("no of digits are: %d ",count);
  return 0;
}