#include <stdio.h>

int main(){
/* Reading hello from input1 file*/
     FILE *input1;
     input1 = fopen("input1", "r");
     if(input1 == NULL) {
         perror("fopen()");       
     }
     char word[5];
     fscanf(input1,"%s",word);
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
printf("\n");
    FILE * input2;
    input2 = fopen("input2","r");
    if(input2 == NULL){
        perror("fopen()");
    }
    char mess[511];
    fscanf(input2,"%s",mess);
    /*int i2;
    for(i2=0;i2<511;i++){
       if(mess[i] == NULL){
        printf(" "); 
        }
    printf("%c",mess[i]);
    }*/
    printf("%s",mess);
    printf("hisdkasd");
    
    
return 0;
}
