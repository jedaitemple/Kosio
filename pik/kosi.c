#include <stdio.h>

#include "files.c"

int main(){
	
	char *inputttt;
	
	int a;	
	int b;	
	

int option;//option 1-5


    int choice;
 
    do
    {
        printf("Menu\n\n");
        printf("1. Chetene na programata ot fail i zapis na rezultata vav fail \n");
        printf("2. chetene na programta ot fail i izvezdane na rezultata na ekrana\n");
        printf("3. chetene na programata ot klaviaturata i izvezdane na rezultata na ekrana\n");
	printf("4. chete na programata ot klaviaturata i izvezdane na rezulata v fail\n");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
		option=1;
		 read_file(option);
                break;
            case 2:   	
		option=2;
		read_file(option);
		
                break;
	  case 3:   	
		option=3;
		inputttt=getstring();
		printf("obsht broi simvoli v komentarite\n");
	a=count_symbols(inputttt);
	printf("%d\n",a);	
	printf("broi na simvolite v identifikatorite\n");

	b=count_identifiers(inputttt);
	printf("%d\n",b);
		
                break;
            case 4: inputttt=getstring();
			
			a=count_symbols(inputttt);
			
			b=count_identifiers(inputttt);
			
	  	        write_file(a,b);
	     
                break;
		   case 5: printf("Quitting program!\n");
               
                break;
            default: printf("Invalid choice!\n");
                break;
        }
 
    } while (choice != 5);
 	free(inputttt);
	

	
return 0;
}
