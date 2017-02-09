/* 	Create an array of pointers to character strings.   
	Allocate memory from the heap for each string using malloc().   
	Use a loop to go through each entry of the array and print out the name of the type and the size of the type.  
	Use printf() statements to create the output using format strings.
	In a second loop, print out each type name along with the address to its pointer and the address of the memory storing the type names.
	Add the ability for a user to pass a single type name argument to the program.  If that type name is in the list, do the same outputs 		but just with that one type.
	Create an initialized, but unused global integer variable notused and add a notused local variable in a function, initialized to a 		different value than the global variable notused.
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int notused = 7; // Create and initialized but unused global variable "notused"
const int MAX = 7;

struct myVar
{
	char first;
	char *second;
 	int third;  
	int *fourth;
} varStruct;

int main(int argc, char *argv[]) //Add the ability for a user to pass a single type name argument to the program. 
{
	
int notused = 9; // Create and initialized but unused local variable "notused" having different value than global variable

 
char *datatypes[] = { "char", "int", "unsigned int", "float", "long", "long long", "struct"}; /* Array of pointers to character String */

int i=0;
if(argv[1] != NULL)  //Add the ability for a user to pass a single type name argument to the program. 
{
	for (i=0;i<MAX;i++)	
 	{	
	if(argv[2] == NULL)
		{
			if((strcmp(argv[1],"char")) == 0)
			{ printf("Size of char is %d\n",sizeof(char));
			printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
                	printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;}
			else if((strcmp(argv[1],"int")) == 0)
			{ printf("Size of int is %d\n",sizeof(int));
			printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
               		 printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;	}
 			else if((strcmp(argv[1],"float")) == 0)
			{ printf("Size of float is %d\n",sizeof(float));
			printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
                	printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;}	
			else if((strcmp(argv[1],"long")) == 0)
			{ printf("Size of long is %d\n",sizeof(long));
			printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
               		 printf("The address to its pointer is : %p\n", &(*datatypes[i])); break; }
			else if((strcmp(argv[1],"struct")) == 0)
			{ 
				struct myVar mt;
			  	{ printf("Size of struct is %d\n",sizeof(mt)); 
					printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
                			printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;
				}
			}
		}
	else if(argv[2] != NULL && argv[3] == NULL )
		{	
	        	if (((strcmp(argv[1],"long")) == 0) && ((strcmp(argv[2],"long")) == 0))
			{
				printf("Size of int is %d\n",sizeof(long long int));
				printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
                		printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;
			}
			else if (((strcmp(argv[1],"unsigned")) == 0) && ((strcmp(argv[2],"int")) == 0))
			{
				printf("Size of unsigned int is %d\n",sizeof(unsigned int));		
				printf("The address of memory storing the type name is : %p\n", &(datatypes[i]));
               			printf("The address to its pointer is : %p\n", &(*datatypes[i])); break;
			}
		}
	else
	 	{ 
			printf("You have entered a wrong argument.\nEnter valid argument within the given range\n"); 
		}
}
}
else
{
 for (i=0;i<MAX;i++)  //Use a loop to go through each entry of the array and print out the name of the type and the size of the type.
 {
  	printf("Datatype %s ",datatypes[i]);

	  if(datatypes[i]=="char" || argv[1]=="char")
	 {
		char varChar;
		char *varChar_pointer;
		varChar_pointer = (char *)malloc(10 * sizeof(char));   //Allocate memory from the heap for each string using malloc().
		printf("has the value of %d bytes\n", sizeof(varChar));
	
	 }
	else 
	if(datatypes[i]=="int" || argv[1]=="int")
	 {
		int varInt;
	   	int *varInt_pointer;
		varInt_pointer = (int *)malloc(10 * sizeof(int));  //Allocate memory from the heap for each string using malloc().
		printf("has the value of %d bytes\n", sizeof(varInt));
	 }
	else 
	if(datatypes[i]=="unsigned int" || argv[1]=="unsigned int")
	 { 
		unsigned int varUint;
		unsigned *varUint_pointer;
		varUint_pointer = (unsigned int *)malloc(10 * sizeof(unsigned int)); /*Allocate memory from the heap using malloc() */
	 	printf("has the value of %d bytes\n", sizeof(varUint));
	 }
	else 
	if(datatypes[i]=="float" || argv[1]=="float")
	 { 
		float varFloat;
		float *varFloat_pointer;
		varFloat_pointer = (float *)malloc(10 * sizeof(float)); /*Allocate memory from the heap for each string using malloc() */
	  	printf("has the value of  %d bytes\n", sizeof(varFloat));
	 }
	else 
	if(datatypes[i]=="long" || argv[1]=="long") 
	 { 
		long varLong;
		long *varLong_pointer;
		varLong_pointer = (long *)malloc(10 * sizeof(long)); /*Allocate memory from the heap for each string using malloc() */
	   	printf("has the value of %d bytes\n", sizeof(varLong));
	 }
	else 
	if(datatypes[i]=="long long" || argv[1]=="long long")
	 { 
		long long varLlong;
		long long *varLlong_pointer;
		varLlong_pointer = (long long *)malloc(10 * sizeof(long long)); /*Allocate memory from the heap for each string using malloc() */
		printf("has the value of %d bytes\n", sizeof(varLlong));
	 }
	else 
	if(datatypes[i]=="struct" || argv[1]=="struct")
	 { 
		struct myVar mt;
		struct myVar *mt_pointer;
		mt_pointer = (struct myVar *)malloc(10 * sizeof(mt));
		printf("has the value of %d bytes\n", sizeof(mt)); // passing the variable to sizeof()
	 }
	else
	{
 		printf("invalid datatype");
	}
}

for (i=0;i<MAX;i++)  /* In a second loop, print out each type name along with the address to its pointer and the address of the memory storing the type names */
 {
  	printf("Datatype %s ",datatypes[i]);

	  if(datatypes[i]=="char" || argv[1]=="char")
	 {
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="int" || argv[1]=="int")
	 {
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="unsigned int" || argv[1]=="unsigned int")
	 { 
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="float" || argv[1]=="float")
	 { 
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="long" || argv[1]=="long") 
	 { 
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="long long" || argv[1]=="long long")
	 { 
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else 
	if(datatypes[i]=="struct" || argv[1]=="struct")
	 { 
		printf("- The address of memory storing the type name is : %p\n", &(datatypes[i]));
                printf("\t\t The address to its pointer is : %p\n", &(*datatypes[i]));
	 }
	else
	{
 		printf("invalid datatype");
	}
}
}
}


 
    

