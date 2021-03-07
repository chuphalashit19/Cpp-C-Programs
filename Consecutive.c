#include<stdio.h>
int main(){
    int A [] = {10, 7, 21, 18, 45, 22};
    int B[] = {24, 15, 18, 18, 42, 22};
    int count = 0;

    for(int i=0; i<6; i++){
        for(int j=i+1; j<5; j++){
            if(A[i] == A[j]){
                count += 1;
            }
        }
    }
    if (count > 0)
        printf("\ntrue\n");
    else
        printf("\nfalse\n");

    count = 0;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<5; j++){
            if(B[i] == B[j]){
                count += 1;
            }
        }
    }
    if (count > 0)
        printf("\ntrue\n");
    else
        printf("\nfalse\n");
}
