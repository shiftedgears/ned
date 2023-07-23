#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
   
   /*
      Below are the editor commands and their variable counterparts.
   */
   int max_line_size = 200;
   int file_name_size = 255;
   char quit = 'q';
   char read = 'r';
   char load = 'l';

   char cmd = 't'; //var to hold user command

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
                char curr_line[max_line_size];
                while(fgets(curr_line, max_line_size, f_r)){
                    printf("%d | %s", line, curr_line);
                    line++;
                }
                
                printf("\n");

                //fclose(f_r); //close file
            }
        }
        else{
            printf("?\n");
        }
        
        while ((cmd = getchar()) != '\n' && cmd != EOF) { }
    }

   if(f_r){ //cleanup pointers
     fclose(f_r);
   }
   if(f_w){
     fclose(f_w);
   }

   return 0;
}
