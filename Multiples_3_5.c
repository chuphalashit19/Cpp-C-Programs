#include<stdio.h>

int main(){
    int i;
    for(i=1; i<=100; i++)
    {
        if (i%3 == 0 && i%5 == 0){
            printf("\n ZipZap");
        }
        else if (i%3 == 0){
            printf("\n Zip");
        }
        else if (i%5 == 0){
            printf("\n Zap");
        }
        else{
            printf("\n %d", i);
        }
    }
}
