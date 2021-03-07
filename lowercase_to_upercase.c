#include <string.h>

int i = 0;

char upperToLower_viceVerse(char *s)
{
    if(s[i] >= 'a' && s[i] <= 'z'){
        if(s[i]>=97 && s[i]<=122){
            s[i] -= 32;
            i++;
            return upperToLower_viceVerse(s);
        }
    }
    if(s[i] >= 'A' && s[i] <= 'Z'){
        if(s[i]>=65 && s[i]<=90){
             s[i] += 32;
             i++;
             return upperToLower_viceVerse(s);
        }
    }
    else{
        return;
    }
}
int main()
{
    char s[100];
    int i;
    printf("Enter  the string: ");
    gets(s);
    printf("String: = '%s'\n",s);
    upperToLower_viceVerse(s);
    printf("String after changing = '%s'\n",s);
}
