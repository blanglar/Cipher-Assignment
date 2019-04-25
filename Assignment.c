#include <stdio.h>

int main(){
/* Reading hello from input1 file*/
     FILE *input1;
     input1 = fopen("input1", "r");
     if(input1 == NULL) {
         perror("fopen()");       
     }
/* Reading Ciphered text from input 2 file*/
    FILE * input2;
    input2 = fopen("input2","r");
    if(input2 == NULL){
        perror("fopen()");
    }
     /* Selection of cipher task */
    printf("Baxter Langlar's Cipher Assignment\n\n");
    printf("Please select a task to view;\n");
    printf("(a) Encryption of a message with a rotation cipher given the message text and rotation amount\n");
    printf("(b) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("(c) Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
/* Variables for case 'a'*/
    char word[5];
    int i;
/*Variables for case 'b'*/
    char mess[511];
    int i2;
    
    char select;
    scanf("%c",&select);
    switch(select){
        case 'a':
            fscanf(input1,"%s",word);
            printf("You entered the word: %s\n",word);
            printf("The word %s with a rotation cipher of 2 is ",word);
/* Rotation of 2 Cipher*/
            for(i = 0;i<5;i++){
                word[i]=word[i] - 2;
                if(word[i]<65){
                    word[i]=word[i]+26;
                }
            }
            printf("%s\n",word);
            printf("\n");
            break;
        case 'b':
            fscanf(input2,"%511[^\t]s",mess);
            printf("This text uses a cipher rotation of -7\n%s\n",mess);
 /*This prints every cipher rotation*/           
            
            for(i2=0;i2<511;i2++){
                mess[i2]=mess[i2] - 7;
                if((mess[i2]<65)&&(mess[i2]>38)){ //if ASCII value lower than A then make it Z
                    mess[i2]=mess[i2] + 26;
                } 
                printf("%c",mess[i2]);
            }
            
            printf("\n");
            
            break;
        
        case 'c':
            break;
            
        default:
            printf("That's not an option. Run the program and try again.\n\n");
            break;
            
    }
     
/* Decryption of roatation cipher testing without terminal*/

    fscanf(input2,"%511[^\t]s",mess);
            printf("This text uses a cipher rotation of -7\n%s\n",mess);
 /*This prints every cipher rotation*/           
            
            for(i2=0;i2<511;i2++){
                mess[i2]=mess[i2] - 7;
                if((mess[i2]<65)&&(mess[i2]>57)){ //if ASCII value lower than A then make it Z
                    mess[i2]=mess[i2] + 26;
                } 
                
            }
            printf("%s",mess);
            printf("\n");
            
    
    
    
    
    printf("\n");
return 0;
}
