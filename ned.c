#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char **argv){
   
   /*
      Below are the editor commands and their variable counterparts.
   */
   int file_name_size = 255;
   char quit = 'q';
   char read = 'r';
   char load = 'l';
   char append = 'a';
   
   char cmd = 't'; //var to hold user command
   char text_app[MAX_LINE_SIZE]; //create c-string for whatever users wants to write
   char curr_line[MAX_LINE_SIZE];

   FILE *f_r; //create file pointer for reading
   FILE *f_w; //file pointer for write/append
    
   char file_name[file_name_size];
   if(argc == 2){ //if they loaded with a filename, load it into the file_name var
     strcpy(file_name, argv[1]);
   }

   while(cmd != quit){
    
     scanf("%c", &cmd);

     if(cmd == quit){ //if user wants to quit, break
       break;
     }
     else if(cmd == load){//loading a new file to read/write
       scanf("%s", file_name); //wait for user to type the file to "load" (just changes active file_name)
            
       //checks to see if file exists
       f_r = fopen(file_name, "r"); //open file in read mode

       if(!f_r){ //if there was no file to read, alert user
	 printf("!\n");
       }
       else{
	 fclose(f_r); //otherwise close it
       }
     }
     else if(cmd == read){ //if user wants to read file

       f_r = fopen(file_name, "r"); //open file in read mode

       if(!f_r){ //if there was no file to read, alert user
	 printf("!\n");
       }
       else{ //otherwise it exists. read it line by line
	 int line = 1;
	 while(fgets(curr_line, MAX_LINE_SIZE, f_r)){
	   printf("%d | %s", line, curr_line);
	   line++;
	 }
                
	 printf("\n");

	 //fclose(f_r); //close file
       }
     }
     else if(cmd == append){ //if user wants to append to a file

       f_w = fopen(file_name, "a"); //open file in write mode

       if(!f_w){ //if no file opened
	       printf("!\n");
       }
       else{//otherwise it exists, let user type

	       fflush(stdin);
	       fgets(text_app, MAX_LINE_SIZE, stdin);

	       fputs(text_app, f_w);

	       fclose(f_w); //close pointer
	    
       }

     }
     else{
       printf("?\n");
     }
        
     while ((cmd = getchar()) != '\n' && cmd != EOF) { }
   }

   return 0;
}
