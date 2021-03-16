#include<stdio.h>
#include <limits.h>

int SecondLargest(int arr[], int n){
    int i;
    int m1 = INT_MIN;
    int m2 = INT_MIN;
    for(i=0; i<n; i++)
    {
        if(arr[i] > m1)
        {
            m2 = m1;
            m1 = arr[i];
        }
        else if(arr[i] > m2 && arr[i] < m1)
        {
            m2 = arr[i];
        }
    }
    return m2;
}

int main(){
    int arr[6] =  {10, 20 , 2, 50, 50, 0};
    int len = 6;
    printf("\n Second Largest: %d\n\n", SecondLargest(arr, len));
}
