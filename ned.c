#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
   
   /*
      Below are the editor commands and their variable counterparts.
   */
   int max_line_size = 200;
   int file_name_size = 255;
   char quit[2];
   strcpy(quit, "q");
   char read[2];
   strcpy(read, "r");

   char cmd[10]; //var to hold user command
   strcpy(cmd, "t");

    FILE *f_r; //create file pointer for reading
    FILE *f_wa; //file pointer for write/append
    
    char file_name[255];
    if(argc == 2){
        strcpy(file_name, argv[1]);
    }

   while(strcmp(cmd, quit) != 0){
      
      scanf("%s", cmd);
      
      if(strcmp(cmd, quit) == 0){ //if user wants to quit, break
         break;
      }
      else if(strcmp(cmd, read) == 0){ //read file contents
          
          f_r = fopen(file_name, "r"); //open file in read mode
          
          if(!f_r){ //if there was no file to read, alert user
              printf("!\n");
          }
          else{ //otherwise it exits. read it line by line
              int line = 1;
              char curr_line[max_line_size];
              while(fgets(curr_line, max_line_size, f_r)){
                  printf("%d | %s", line, curr_line);
                  line++;
              }
              
              fclose(f_r);
          }
      }
      else{
         printf("?\n");
      }
   }

   return 0;
}