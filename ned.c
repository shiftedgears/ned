#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME 255

char file_name[MAX_FILE_NAME]; //holds global file_name for opening/closing

/*
    Sets the global file name to "!" for quick detection of whether a file is loaded or not
*/
void unload_file(){
    strcpy(file_name, "!");
}

/*
    Called from the "load file" case, 'l', where the user gives a file name
    to load into the file_name var
*/
void load_file(char *f_name){
   
   strcpy(file_name, f_name);
   //checks to see if file exists
   FILE *f_r = fopen(file_name, "r"); //open file in read mode

   if(!f_r){ //if there was no file to read, alert user. Create it
    printf("%s: No such file name or directory\n", file_name);
    f_r = fopen(f_name, "w+");
   }
   fclose(f_r); //close file pointer
}

/*
    Called from the "read file" case, 'r', where we will dump the file into the terminal
*/
void read_file(){
    FILE* f_r = fopen(file_name, "r"); //open file in read mode
    char curr_line[MAX_LINE_SIZE];
    
    if(!f_r) printf("!\n"); //if there was no file to read, alert user
    else{ //otherwise it exists. read it line by line
        printf("F=|=%s\n", file_name); //output name of file
        int line = 1;
        while(fgets(curr_line, MAX_LINE_SIZE, f_r)){
            printf("%d | %s", line, curr_line);
            line++;
        }
        
        printf("\n");
   
        fclose(f_r); //close file
   }
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
   //char curr_line[MAX_LINE_SIZE];
   char f_name[MAX_FILE_NAME];
   
   unload_file();
   
   if(argc == 2) load_file(argv[1]);

   //FILE *f_r; //create file pointer for reading
   FILE *f_w; //file pointer for write/append
    
   if(argc == 2){ //if they loaded with a filename, load it into the file_name var
     strcpy(file_name, argv[1]);
   }

   while(cmd != quit){
    
     scanf("%c", &cmd);
     
     switch (cmd){
             
     case 'q': //if user wants to quit, break
       break;
     case 'l' ://loading a file to read/write to. Writes over the previous file in the file_name
       scanf("%s", f_name); //wait for user to type the file to "load" (just changes active file_name)
            
       load_file(f_name);
       
       break;
     case 'r': //if user wants to read file

       read_file();
       
       break;
     
     case 'a':  //if user wants to append to a file

       f_w = fopen(file_name, "a"); //open file in append only mode

       if(!f_w){ //if no file opened, alert user
	       printf("!\n");
       }
       else{//otherwise it exists, let user type

           flockfile (f_w); //lock the file
	       //fflush(stdin);
	       fgets(text_app, MAX_LINE_SIZE, stdin);
	       
	       //printf("you typed %s", text_app);

	       fputs(text_app, f_w);

           funlockfile (f_w); //unlock the file
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
