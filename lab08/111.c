#include<stdio.h>
//Including stdlib to use exit() function
#include<stdlib.h>
//Including time.h library to seed srand() function
#include<time.h>

//random() function returns a random number in specified range
int random(){
    //srand() sets seed for rand() function to generate random function
    srand(time(NULL));
    //rand()%max generates a random number in range (0,max)
    int number= rand()%5;
    return number;
}

//Program execution starts here
int main(){
    /*For communication between file and program we need to
    create a pointer of type FILE */
    FILE *fptr;
    //Declaring a string array of size 5 with each string size 50
    char text_lines[5][50];

    /*fopen("textfile","r") is a function to open a textfile.
    Second argument denotes mode. "r" is used for reading*/
    //If file is empty then error message is printed
    if((fptr=fopen("C:\\hobbies.txt","r"))==NULL){
        printf("Error reading file");
        exit(1);
    }
    int i=0;
    /*fgets() function gets a line from the opened text file
    and stores the line in first argument*/
    //Storing each new line in already declared char array text_lines
    while(fgets(text_lines[i],sizeof text_lines[i],fptr)!=NULL){
        fscanf(fptr,"%[^\n]",text_lines[i]);
        i++;
    }
    //We are done with the file. So closing file opening fclose()
    fclose(fptr);
    char lines[25];
    int rand_num;
    printf("Entering infinite loop. Press EOF(-1) to exit.\n");
    /*Entering a infinte loop to repeatedly take a input from user
    and randomly print a line from the textfile*/
    //The loop exits when user enter EOF
    //Remember value of EOF in c is -1.
    //So when user enter -1 this loop terminates
    while(i!=-1)
    {
        printf("Enter ctrl+z to exit, else enter input: ");
        scanf("%s",&lines);
        if (atoi(lines)==EOF)
        {
            break;
        }

        /*Calling random() funciton to randomly get a index
        to access text_lines[] array which contain the read file*/
        rand_num = random();
        printf("%s\n",text_lines[rand_num]);
    }
    printf("\nGood bye!!!");
    return 0;
}
