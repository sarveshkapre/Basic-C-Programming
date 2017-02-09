#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex.h>
int main()
{

regex_t match_reg;
char fileName[256];
char filext[4];
printf("Enter the name of a file:\n");
scanf("%s",fileName);

printf("You entered %s\n",fileName);

// We need to check whether the filename entered is valid or invalid
// We will use regex to check whether the input is legitimate

int x = strlen(fileName);
printf("The length of fileName is:%d\n",x);

if(x>256)                                            //this function will check for the maximum characters in filename
{
 printf("The filename is too long\n\n");
}

if(fileName[x-1] == '.')                  //filename can never end in '.'
 {                                        // The if clause checks whether the file ends in '.' and immediately displays an error and quits
  printf("Invalid Filename\n");
  printf("Filename should not end in '.'\n\n\n");
  return 0;
 }




int i;
 for(i=0;i<x;i++)
  {
              
     
      switch( fileName[i] )
                 {
                        
                        // The special characters displayed below ccannot be used as a part of filenames
                        // This is just to secure our code from canonicalization vulnerabilties
                        
                        case '<':
                        case '>':
                        case '/':
                        case '\\':
                        case '\"':
                        case '?':   
                        case '*':
                        case '|':
                        case '~':
                        case '!':
                        case '@':
                        case '#':
                        case '$':
                        case '%':
                        case '^':   
                        case '&':
                        case '+':
                          printf("The filename contains disallowed character\n");
                          printf("Please re-check your input and enter a valid filename\n\n\n");
                          return 0;      //If any of the above character is spotted in the filename; we quit the program
                      
                 }

  }

//Extract file extension from file name.

  char *fext;
   fext = strrchr(fileName, '.');
if (!fext) {
    { printf("No extension"); }
} else {
    printf("File extension is :  %s\n", fext + 1);
}
 char extfile[10];
  strcpy(extfile,fext+1);

// To check for file extensions

if( (strcmp(extfile, "pdf") == 0) || (strcmp(extfile, "c") == 0) ||(strcmp(extfile, "java") == 0) ||(strcmp(extfile, "docx") == 0) ||(strcmp(extfile, "doc") == 0) ||(strcmp(extfile, "txt") == 0) ||(strcmp(extfile, "xls") == 0) ||(strcmp(extfile, "com") == 0) ||(strcmp(extfile, "jpg") == 0) ||(strcmp(extfile, "jpeg") == 0) ||(strcmp(extfile, "rtf") == 0) ||(strcmp(extfile, "png") == 0) ||(strcmp(extfile, "gif") == 0) ||(strcmp(extfile, "bmp") == 0) ||(strcmp(extfile, "ext") == 0) ||(strcmp(extfile, "zip") == 0) ||(strcmp(extfile, "log") == 0) ||(strcmp(extfile, "ppt") == 0) ||(strcmp(extfile, "xml") == 0) ||(strcmp(extfile, "bat") == 0) ||(strcmp(extfile, "html") == 0) ||(strcmp(extfile, "pl") == 0)||(strcmp(extfile, "py") == 0))


{ printf("File extension is valid.\n");  }
else
 { printf("File extension is invalid.\n"); }

printf("The path for the file is:\n");


//realpath will give us the path of the file
char *path = realpath(fileName, NULL);
if(path == NULL){
	printf("Unable to find path for the file[%s]\n\n\n", fileName);
} else{
	printf("[%s]\n", path);
	free(path);
}

struct stat sb;


int stat(const char *path, struct stat *buf);         //To check whether the file is regular file or device file

stat(path, &sb);
           if ((sb.st_mode & S_IFMT) == S_IFREG) {
               printf("Its not a device file\n");
           }

switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("Its a regular file\n\n\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }


return 0;
}
