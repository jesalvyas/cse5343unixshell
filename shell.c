
// Jesal Vyas
// A simple shell for Unix

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void type(char* filename);
void copy(char* source, char* dest);
void delete(char* filename);
int execute(char* filename);

// Displays an error message on stdout
void error(char* command) {
  printf("Command not found: %s\n", command);
}
void type(char* filename) {
	
    FILE *fp = fopen(filename, "r");
    char ch;
    printf("Hey");
   
    if(fp == NULL)
    {
        printf("error: file %s not found!\n", filename);
        return;
    }
    
    
    while( (ch = fgetc(fp)) != EOF) // reads and prints content of the file
    {
        putc(ch,stdout);
    }
    
     fclose(fp); // closes the file

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
// Executes a program named `filename`
 int execute(char **argv) {
pid_t pid;
int status;

if ((pid = fork()) < 0) {                 //fork a child process
printf("forking child process failed\n");
return 0;
}

else if (pid == 0) {                
if (execvp(*argv, argv) < 0) {    //  executes the command 
printf("exec failed\n");
return 0;
}
} else {
                                      
while (wait(&status) != pid) //waits for completion 

}
return 1;
}

int main(int argc, char** argv) {
  printf("\n");
  char command[100] = {0};
  while (true) {
    printf("\n> ");
    scanf("%s", command);    
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
