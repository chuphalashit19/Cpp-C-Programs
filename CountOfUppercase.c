#include<stdio.h>
#include<string.h>

int main(void)
{
    int i = 0, n, count = 0;

    printf("\n Enter a positive integer: ");
    scanf("%d", &n);

    char ch[n];
    printf("\n Enter %d characters: ", n);
    for(i=0; i<n; i++)
        scanf("%s", &ch[i]);

    for(i=0; i<n; i++){
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            count += 1;
    }

    printf("\n There are %d upper case letters", count);
    printf("\n\n");
}
