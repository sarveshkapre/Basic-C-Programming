#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{ 
    char transfer[200];
    char userName[50];
    char passWord[50];
    int len1;
    int len2;
    printf("Enter username:\n");
    scanf("%s",userName);
    len1 = strlen(userName);
    
    if(len1 > 25)
     {
        printf("Incorrect username\n");
        return -1;
     }
 
    printf("Enter password:\n");
    scanf("%s",passWord);
    len2 = strlen(passWord);

    if(len2 > 25)
     {
        printf("Incorrect password\n");
        return -1;
     }
 
    sprintf(transfer,"perl 4.pl '%s' '%s'",userName,passWord);
    system(transfer);
    
    return 0;	
}
