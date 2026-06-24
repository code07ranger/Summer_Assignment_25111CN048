//Write a program to Bubble sort.
#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){// for no of pass=i
        bool flag=true;// array is sorted
       for (int j=0;j<n-1-i;j++){// for swapping  in acending order
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=false;
        }
    }
    if(flag==true){
        break;
    }
}
for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
}
    return 0;
}