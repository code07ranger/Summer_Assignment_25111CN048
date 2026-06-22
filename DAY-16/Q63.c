//Write a program to Find pair with given sum.
#include<stdio.h>
int main(){
     int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter sum to be found: ");
    scanf("%d",&x);
    printf("the pairs are: ");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x){
                printf("(%d,%d) , ",arr[i],arr[j]);
            }
        }
    }
    return 0;
}