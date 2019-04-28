#include <stdio.h>

int main(){
/* Reading HELLO from input1 file for task 1*/
     FILE *input1;
     input1 = fopen("input1", "r");
     if(input1 == NULL) {
         perror("fopen()");       
     }
/* Reading Ciphered text from input 2 file for task 2*/
    FILE * input2;
    input2 = fopen("input2","r");
    if(input2 == NULL){
        perror("fopen()");
    }
/* Reading Substitution Cipher Key for task 3*/
    FILE * SubCipher;
    SubCipher = fopen("SubCipher","r");
    if(SubCipher == NULL){
        perror("fopen()");
    }
/* Reading Text for task 3*/
    FILE * Task3text;
    Task3text = fopen("Task3text","r");
    if(Task3text == NULL){
        perror("fopen()");
    }
/* Printing Selection menu */
    printf("Baxter Langlar's Cipher Assignment\n\n");
    printf("Please select a task to view;\n");
    printf("(a) Encryption of a message with a rotation cipher given the message text and rotation amount\n");
    printf("(b) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("(c) Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
/* Variables for case 'a'*/
    char word[5];
    int i;
/* Variables for case 'b'*/
    char mess[511];
    int i2;
/* Variables for case 'c'*/
    char key[25];
    char text[23];
    int i3;

/* User input for task selection */  
    char select;
    scanf("%c",&select);
    switch(select){
/*Task 1 - Encrypting with Rotation Cipher given text and key*/
        case 'a':
            fscanf(input1,"%s",word);
            printf("The word '%s' was read from input1.\n",word);
            printf("The word %s with a rotation cipher of 2 is ",word);
            for(i = 0;i<5;i++){
                word[i]=word[i] - 2;
                if(word[i]<65){
                    word[i]=word[i]+26;
                }
            }
            printf("%s\n",word);
            printf("\n");
            break;
/* Task 2 - Rotation Cipher Decryption with key and text */
        case 'b':
            fscanf(input2,"%511[^\t]s",mess);
            printf("The text below is read from the file input2 and uses a rotation of 7;\n%s\n\n",mess);           
            for(i2=0;i2<511;i2++){
                mess[i2]=mess[i2] - 7;
                if((mess[i2]<65)&&(mess[i2]>57)){ //if ASCII value lower than A then make it Z
                    mess[i2]=mess[i2] + 26;
                }  
            }
            printf("The text from input2 decrypted reads;\n%s\n",mess);
            break;
/* Task 3 - Substitution Cipher with Key and Text */       
        case 'c':
            fscanf(SubCipher,"%s",key);
            fscanf(Task3text,"%23[^\t]s",text);
            printf("The phrase '%s' using the substitution key   '%s' is;\n\n",text,key);
            for(i3=0;i3<23;i3++){
                switch(text[i3]){
                    case '\0': printf(" ");
                    case 'A': text[i3] = key[0];    break;
                    case 'B': text[i3] = key[1];    break;
                    case 'C': text[i3] = key[2];    break;
                    case 'D': text[i3] = key[3];    break;
                    case 'E': text[i3] = key[4];    break;
                    case 'F': text[i3] = key[5];    break;
                    case 'G': text[i3] = key[6];    break;
                    case 'H': text[i3] = key[7];    break;
                    case 'I': text[i3] = key[8];    break;
                    case 'J': text[i3] = key[9];    break;
                    case 'K': text[i3] = key[10];   break;
                    case 'L': text[i3] = key[11];   break;
                    case 'M': text[i3] = key[12];   break;
                    case 'N': text[i3] = key[13];   break;
                    case 'O': text[i3] = key[14];   break;
                    case 'P': text[i3] = key[15];   break;
                    case 'Q': text[i3] = key[16];   break;
                    case 'R': text[i3] = key[17];   break;
                    case 'S': text[i3] = key[18];   break;
                    case 'T': text[i3] = key[19];   break;
                    case 'U': text[i3] = key[20];   break;
                    case 'V': text[i3] = key[21];   break;
                    case 'W': text[i3] = key[22];   break;
                    case 'X': text[i3] = key[23];   break;
                    case 'Y': text[i3] = key[24];   break;
                    case 'Z': text[i3] = key[25];   break;
                    default: /*printf("Something went wrong!\n");*/    break;
                }
                printf("%c",text[i3]);
            }
            printf("\n");
            break;
            
        default:
            printf("That's not an option. Run the program and try again.\n\n");
            break;
            
    }
     
    printf("\n");
return 0;
}
