#include<stdio.h>
double days = 0;
double COVID19(int N);

double COVID19(int N){
    if(N > 0){
        int temp = N-(N*0.3);
        days = days+1;
        return COVID19(temp);
    }
}

int main(){
    char name[10];
    int id;
    int N;
    printf("Enter your name and ID: ");
    scanf("%s %d", name, &id);
    printf("\nName: %s", name);
    printf("\nID:%d", id);
    printf("\nEnter the number of infections N:");
    scanf("%d", &N);
    COVID19(N);
    printf("\n%f\n\n\n", days*2);
}
