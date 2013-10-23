// Jesal Vyas
// A simple shell for Unix

/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//void error(char* command);
//bool commandIsExit(char* command);
//int commandIsType(char* command);
//int commandIsCopy(char* command);
//int commandIsDelete(char* command);
void type(char* filename);
void copy(char* source, char* dest);
void delete(char* filename);
void execute(char* filename);



// Displays an error message on stdout
void error(char* command) {
  printf("Command not found: %s\n", command);
}




void type(char* filename) {
	
    FILE *fp = fopen(filename, "r");
    char ch;
    printf("ELF");
   
    if(fp == NULL)
    {
        printf("error: file %s not found!\n", filename);
        return;
    }
    
    // read and print content of the file byte by byte
    while( (ch = fgetc(fp)) != EOF)
    {
        putc(ch,stdout);
    }
    
    // close the file
    fclose(fp);
}


void copy(char* source, char* dest) // Copies the bytes from `source` to `dest`
{
   
    FILE *fOut;  
    FILE *fIn;  
    
    char ch;     
    
    
    fOut = fopen(dest, "w"); //opens dest for writing
    
     
    fIn = fopen(source, "r"); // opens source for reading
    
    
    if(fIn == NULL)
    {
        printf("error: file %s could not be opened for reading!\n", source);
        return;
    }
    if(fOut == NULL)
    {
        printf("error: file %s could not be created for writing!\n", dest);
        return;
    }
    
    
    while( (ch = fgetc(fIn)) != EOF)  // write content from source to dest
    {
        putc(ch,fOut);
    }
    
    fclose(fIn);  // closes the input file
    fclose(fOut); // closes the output file
}



// Deletes a file named `filename`
void delete(char* filename) {
   if(remove(filename) != 0)
    {
        printf("Error:file %s cannot be deleted\n", filename);
    }    

}


/* Executes a program named `filename`
void execute(char* filename) {
  // TODO
}
*/

/*int main(int argc, char** argv) {
  printf("\n");
  char command[100] = {0};
  while (true) {
    printf("\n> ");
    scanf("%s", command);    //fgets(command,100,stdin);


    // difff token by spaces


    // argv0... command fire... parameter .. argv1,argv2...
// depends on command

    // copy -2 parameter
    //type .. 1 parameter
    //exit..no paramater
    //delete 1 parameter
    // file open karvani... joi tgay to okoay otherwise file not found.


   
    if (strcmp(command,"exit")==0) {
      break;
    } 

    else if (strcmp(command,"type")==0) {
      
      printf("command is type",command);
      
      
    } 
    else if (strcmp(command, "copy")==0) {
      
    }
    else if (strcmp(command, "delete")==0) {
    	

    }
  
}
return 0;
}
*/

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

# include <sys/types.h>

void parse_input (char* input, char *cmd [], int* n);

void print_file (char* filename);

int main(int argc, char *argv[])

{

char input [INPUT_SIZE];

int args_len;

// loop to read and process all user commands

while(1)

{

//display shell prompt

printf("shell>");

// read user input from keyboard

fgets(input, sizeof(input), stdin);

// remove the trailing newline from input

input[strlen(input) -1] = '\0';

// terminate the shell if user entered 'exit'

if(strcmp(input, "exit") ==0)

{

break; }

// parse input to extract command and arguments

parse_input(input,cmd,&args_len);

// process the command

if (strcmp(cmd[0], "type") == 0)

{

// type <filename>

print_file( cmd [1]);

}

else { 
	return 0;}
}

}


