#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME 255

char file_name[MAX_FILE_NAME]; //holds global file_name for opening/closing

void load_file(){
    scanf("%s", file_name); //wait for user to type the file to "load" (just changes active file_name)
            
       //checks to see if file exists
       FILE *f_r = fopen(file_name, "r"); //open file in read mode

       if(!f_r){ //if there was no file to read, alert user
	       printf("!\n");
       }
       else fclose(f_r);
       
}

int main(int argc, char **argv){
   
   /*
      Below are the editor commands and their variable counterparts.
   */
   char quit = 'q';
   //char read = 'r';
   //char load = 'l';
   //char append = 'a';
   
   char cmd = 't'; //var to hold user command
   char text_app[MAX_LINE_SIZE]; //create c-string for whatever users wants to write
   char curr_line[MAX_LINE_SIZE];

   FILE *f_r; //create file pointer for reading
   FILE *f_w; //file pointer for write/append
    
   if(argc == 2){ //if they loaded with a filename, load it into the file_name var
     strcpy(file_name, argv[1]);
   }

   while(cmd != quit){
    
     scanf("%c", &cmd);
     
     switch (cmd){
             
     case 'q': //if user wants to quit, break
       break;
     case 'l' ://loading a new file to read/write
     
       load_file();
       
       break;
     
     case 'r': //if user wants to read file

       f_r = fopen(file_name, "r"); //open file in read mode

       if(!f_r){ //if there was no file to read, alert user
	       printf("!\n");
       }
       else{ //otherwise it exists. read it line by line
           printf("F=|=%s\n", file_name);
           int line = 1;
           while(fgets(curr_line, MAX_LINE_SIZE, f_r)){
            printf("%d | %s", line, curr_line);
            line++;
	       }
                
	       printf("\n");
	       
	       fclose(f_r); //close file
       }
       break;
     
     case 'a':  //if user wants to append to a file

       f_w = fopen(file_name, "a"); //open file in write mode

       if(!f_w){ //if no file opened
	       printf("!\n");
       }
       else{//otherwise it exists, let user type

	       fflush(stdin);
	       fgets(text_app, MAX_LINE_SIZE, stdin);
	       
	       printf("you typed %s", text_app);

	       fputs(text_app, f_w);
	       

	       fclose(f_w); //close pointer
	    
       }
       break;
       
     default:
       if(cmd == quit) printf("?\n");
     }
        
     //while ((cmd = getchar()) != '\n' && cmd != EOF) { }
   }


   return 0;
}
