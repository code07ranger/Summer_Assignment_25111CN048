//Write a program to Find largest and smallest element in array.
//input the array from the user.
#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
   int max=INT_MIN;
   int min=INT_MAX;
   for(int i=0;i<n;i++){
      if(arr[i]>max){
        max=arr[i];
      }
      if(arr[i]<min){
        min=arr[i];
      }
   }
   printf("The maximum element of array is %d\n",max);
   printf("The minimum element of array is %d",min);
    return 0;
}