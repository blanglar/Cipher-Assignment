#include <stdio.h>

int main(){
/* Reading hello from input1 file*/
     FILE *input;
     input = fopen("input1", "r");
     if(input == NULL) {
         perror("fopen()");       
     }
     char word[5];
     fscanf(input,"%s",word);
     printf("You entered the word: %s\n",word);
     printf("The word %s with a rotation cipher of 2 is ",word);
/* Rotation of 2 Cipher*/
    int i;
    for(i = 0;i<5;i++){
        word[i]=word[i] - 2;
        if(word[i]<65){
            word[i]=word[i]+26;
        }
        printf("%c",word[i]);
    }
/* Decryption of roatation cipher*/
return 0;
}
