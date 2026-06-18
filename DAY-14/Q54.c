//Write a program to Frequency of an element.
#include<stdio.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int a;
    printf("Enter element to find frequency: ");
    scanf("%d",&a);
    int x=0;
    for(int i=0;i<n;i++){
        if (arr[i]==a){
            x++;
        }
    }
    printf("Frequency of %d is %d",a,x);
    return 0;
}