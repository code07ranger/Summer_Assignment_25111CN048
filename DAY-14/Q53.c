//Write a program to Linear search.
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
    printf("Enter element to be searched: ");
    scanf("%d",&a);
    int f=0;
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]==a){
           f=1;
           idx=i;
           break;
        }
    }
    if(f==1){
        printf("%d found at %d position",a,idx+1);
    }
    else{
        printf("Element not found");
    }
    return 0;
}