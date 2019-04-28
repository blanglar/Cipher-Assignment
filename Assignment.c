#include <stdio.h>

int main(){
    printf("Baxter Langlar's Cipher Assignment\n\n");
/* Reading HELLO from input1 file for task 1 */
     FILE *input1;
     input1 = fopen("input1", "r");
     if(input1 == NULL) {
         perror("fopen()");       
     }
/* Reading Ciphered text from input2 file for task 2 */
    FILE * input2;
    input2 = fopen("input2","r");
    if(input2 == NULL){
        perror("fopen()");
    }
/* Reading Substitution Cipher Key for task 3 */
    FILE * SubCipher;
    SubCipher = fopen("SubCipher","r");
    if(SubCipher == NULL){
        perror("fopen()");
    }
/* Reading Text for task 3 */
    FILE * Task3text;
    Task3text = fopen("Task3text","r");
    if(Task3text == NULL){
        perror("fopen()");
    }
/* Reading Text for task 4 */
    FILE * Task4text;
    Task4text = fopen("Task4text","r");
    if(Task4text == NULL){
        perror("fopen()");
    }

/* Variables for Task 1 */
    char word[5];
    int i;
/* Variables for Task 2 */
    char mess[86];
    int i2;
/* Variables for Task 3 */
    char key[25];
    char text[23];
    int i3;
/* Variables for Task 4 (NOTE: Task 4 uses the same cipher key as Task 3) */
    int i4;
    char text2[120];
/* Loop to keep being able to select tasks */
int x = 1; //if this value changes loop exits
char select; //Variable for task selection 
while(x == 1){ 
/* Printing Selection menu */
    printf("Please select a task to view;\n");
    printf("(a) Encryption of a message with a rotation cipher given the message text and rotation amount\n");
    printf("(b) Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("(c) Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
    printf("(d) Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("(e) Exit\n");
    printf("Your input: ");
/* User input for task selection */
    scanf(" %c",&select);
    switch(select){
/*Task 1 - Encrypting with Rotation Cipher given text and key*/
        case 'a':
            fscanf(input1,"%s",word); //reading text from input1
            printf("The word '%s' was read from input1.\n",word);
            printf("The word '%s' with a rotation cipher of 2 is ",word);
            for(i = 0;i<5;i++){ //This rotates each letter by 2
                word[i]=word[i] - 2;
                if(word[i]<65){ //if ASCII value is less than A make it Z
                    word[i]=word[i]+26;
                }
            }
            printf("'%s'\n",word);
            printf("\n");
            for(i = 0;i<5;i++){ //This resets the word for second use in loop
                word[i]=word[i] + 2;
                if(word[i]>90){ //if ASCII value greater than Z make it A
                    word[i]=word[i]-26;
                }
            }
            break;
/* Task 2 - Rotation Cipher Decryption with key and text */
        case 'b':
            fscanf(input2,"%[^\n]%*c",mess); //reading text from input2
            printf("The text below is read from the file input2 and uses a rotation of 7;\n%s\n\n",mess);           
            for(i2=0;i2<86;i2++){
                if((mess[i2]>=65)&&(mess[i2]<=90)){ //This condition rules out punctuation and only rotates for letters
                    mess[i2]=mess[i2] + 7;
                    if(mess[i2]>90){ //if ASCII value lower than A then make it Z
                    mess[i2]=mess[i2] - 26;
                    }
                }   
            }
            printf("The text from input2 decrypted reads;\n%s\n\n",mess);
            /* resets phrase for second use in loop */
            for(i2=0;i2<86;i2++){
                if((mess[i2]>=65)&&(mess[i2]<=90)){
                    mess[i2]=mess[i2] - 7;
                    if(mess[i2]<65){ //if ASCII value greater than Z then make it A
                    mess[i2]=mess[i2] + 26;
                    }
                }   
            }
            break;
/* Task 3 - Substitution Cipher with Key and Text */       
        case 'c':
            fscanf(SubCipher,"%s",key); //reading cipher key
            fscanf(Task3text,"%[^\t]s",text); //reading text
            printf("The phrase '%s' is read from the file Task3text.\n",text);
            printf("The phrase '%s' using the substitution key '%s' is;\n\n",text,key);
            for(i3=0;i3<23;i3++){
                /* This selects a letter and performs a substitution */
                switch(text[i3]){
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
                    default:    break;
                }
                printf("%c",text[i3]); //This prints each letter as it is ciphered
            }
            printf("\n");
            /* This resets phrase for second use in loop */
            for(i3=0;i3<23;i3++){
                switch(text[i3]){
                    case 'D': text[i3] = 'A';    break;
                    case 'W': text[i3] = 'B';    break;
                    case 'A': text[i3] = 'C';    break;
                    case 'R': text[i3] = 'D';    break;
                    case 'F': text[i3] = 'E';    break;
                    case 'M': text[i3] = 'F';    break;
                    case '0': text[i3] = 'G';    break;
                    case 'B': text[i3] = 'H';    break;
                    case 'S': text[i3] = 'I';    break;
                    case 'Q': text[i3] = 'J';    break;
                    case 'U': text[i3] = 'K';    break;
                    case 'I': text[i3] = 'L';    break;
                    case 'Z': text[i3] = 'M';    break;
                    case 'L': text[i3] = 'N';    break;
                    case 'Y': text[i3] = 'O';    break;
                    case 'N': text[i3] = 'P';    break;
                    case 'X': text[i3] = 'Q';    break;
                    case 'J': text[i3] = 'R';    break;
                    case 'P': text[i3] = 'S';    break;
                    case 'G': text[i3] = 'T';    break;
                    case 'K': text[i3] = 'U';    break;
                    case 'V': text[i3] = 'V';    break;
                    case 'E': text[i3] = 'W';    break;
                    case 'T': text[i3] = 'X';    break;
                    case 'C': text[i3] = 'Y';    break;
                    case 'H': text[i3] = 'Z';    break;
                    default:    break;
                }
            }
            printf("\n");
            break;
/* Task 4 - Decryption of substitution cipher given key and text */
        case 'd':
            fscanf(Task4text,"%[^\t]s",text2); //reading text
            printf("The text below is read from the file 'Task4text'\n%s\n",text2);
            printf("This text uses the substitution 'DWARFMOBSQUIZLYNXJPGKVETCH' it reads;\n");
            /* This finds the letter the index is up to and reverses its substitution */
            for(i4=0;i4<120;i4++){
                switch(text2[i4]){
                    case 'D': text2[i4] = 'A';    break;
                    case 'W': text2[i4] = 'B';    break;
                    case 'A': text2[i4] = 'C';    break;
                    case 'R': text2[i4] = 'D';    break;
                    case 'F': text2[i4] = 'E';    break;
                    case 'M': text2[i4] = 'F';    break;
                    case 'O': text2[i4] = 'G';    break;
                    case 'B': text2[i4] = 'H';    break;
                    case 'S': text2[i4] = 'I';    break;
                    case 'Q': text2[i4] = 'J';    break;
                    case 'U': text2[i4] = 'K';    break;
                    case 'I': text2[i4] = 'L';    break;
                    case 'Z': text2[i4] = 'M';    break;
                    case 'L': text2[i4] = 'N';    break;
                    case 'Y': text2[i4] = 'O';    break;
                    case 'N': text2[i4] = 'P';    break;
                    case 'X': text2[i4] = 'Q';    break;
                    case 'J': text2[i4] = 'R';    break;
                    case 'P': text2[i4] = 'S';    break;
                    case 'G': text2[i4] = 'T';    break;
                    case 'K': text2[i4] = 'U';    break;
                    case 'V': text2[i4] = 'V';    break;
                    case 'E': text2[i4] = 'W';    break;
                    case 'T': text2[i4] = 'X';    break;
                    case 'C': text2[i4] = 'Y';    break;
                    case 'H': text2[i4] = 'Z';    break;
                    default:    break;
                }
                printf("%c",text2[i4]);//This prints each letter when it has been reversed
            }
            /* This resets the phrase for second use in loop */
            for(i4=0;i4<120;i4++){
                switch(text2[i4]){
                    case 'A': text2[i4] = 'D';    break;
                    case 'B': text2[i4] = 'W';    break;
                    case 'C': text2[i4] = 'A';    break;
                    case 'D': text2[i4] = 'R';    break;
                    case 'E': text2[i4] = 'F';    break;
                    case 'F': text2[i4] = 'M';    break;
                    case 'G': text2[i4] = 'O';    break;
                    case 'H': text2[i4] = 'B';    break;
                    case 'I': text2[i4] = 'S';    break;
                    case 'J': text2[i4] = 'Q';    break;
                    case 'K': text2[i4] = 'U';    break;
                    case 'L': text2[i4] = 'I';    break;
                    case 'M': text2[i4] = 'Z';    break;
                    case 'N': text2[i4] = 'L';    break;
                    case 'O': text2[i4] = 'Y';    break;
                    case 'P': text2[i4] = 'N';    break;
                    case 'Q': text2[i4] = 'X';    break;
                    case 'R': text2[i4] = 'J';    break;
                    case 'S': text2[i4] = 'P';    break;
                    case 'T': text2[i4] = 'G';    break;
                    case 'U': text2[i4] = 'K';    break;
                    case 'V': text2[i4] = 'V';    break;
                    case 'W': text2[i4] = 'E';    break;
                    case 'X': text2[i4] = 'T';    break;
                    case 'Y': text2[i4] = 'C';    break;
                    case 'Z': text2[i4] = 'H';    break;
                    default:    break;
                }
            }
            printf("\n\n");
            break;
/* This is when the user selects to exit the program */
        case 'e':
            printf("You exited the program.\n");
            x--; //This makes x = 0 which will exit the while loop
            break;
/* This is when the user inputs something random that doesn't correspond with a task */
        default:
            printf("\nThat's not an option. Please select a letter corresponding with the task you wish to select. Please run the program and try again.\n\n");
            x--; //This makes x = 0 which will exit the while loop
            break;
    }
/* This breaks the while loop if x equals 0. This is caused by quitting or inputting incorrectly */
    if(x == 0){
        break;
    } else {
        continue;
    }
}
    printf("\n");
return 0;
}
