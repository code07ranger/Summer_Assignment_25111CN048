//Write a program to Count even and odd elements in array.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    int even=0;
    int odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Even element in array is %d\n",even);
    printf("Odd element in array is %d",odd);
    return 0;
}