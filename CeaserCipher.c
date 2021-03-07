#include<stdio.h>
#include<string.h>

void encryption(char *str){
	char ch;
	int i, key = 3;
	for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
    }

	for(i = 0; str[i] != '\0'; ++i){
		ch = str[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			str[i] = ch;
		}
	}
	printf("\nEncrypted message: %s", str);
}

void decryption(char *str){
    char ch;
    int i, key = 3;
    for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
    }

    for(i = 0; str[i] != '\0'; ++i){
		ch = str[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			str[i] = ch;
		}
	}

	printf("\nDecrypted message: %s", str);
}

int main(){
    char str[30];
    int choice = 0;
    do{
        printf("\n\n1 Encrypt a message");
        printf("\n2 Decrypt a message");
        printf("\n3 Exit\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nWhat is the message to encrypt?\n");
            scanf("%s", str);
            encryption(str);
        }
        else if(choice == 2){
            printf("\nWhat is the encrypted message?\n");
            scanf("%s", str);
            decryption(str);
        }
        else{
            printf("\nExiting!!!");
            return 0;
        }
    }while(choice != 3);
}
