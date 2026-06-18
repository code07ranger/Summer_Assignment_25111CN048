//Write a program to Second largest element.
#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   int max=INT_MIN;
   int smax=INT_MIN;
   for(int i=0;i<n;i++){
         if(arr[i]>max){
            max=arr[i];
         }
         if(arr[i]!=max && smax<arr[i]){
            smax=arr[i];
         }
   }
   printf("The Second largest element is %d",smax);
    return 0;
}