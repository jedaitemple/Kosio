#include <stdio.h>
#include <stdlib.h>
#include <string.h>





	int count_symbols(const char* input){
		
		int i=0;
		int flag=0;
		int flag2=0;
		int counter=0;
			while(input[i]!=0){
				if((input[i]=='/') && (input[i+1] == '*')){
					flag=1;	
					i++;
					i++;				
				}
				
				if((input[i]=='*') && (input[i+1] == '/')){
					flag=0;	
					i++;
					i++;				
				}
				if((input[i]=='/') && (input[i+1] == '/')){
					flag2=1;	
					i++;
					i++;				
				}
				if(input[i]=='\n'){
					flag2=0;	
							
				}
				if((flag==1)|| (flag2==1)){
					if((input[i] !=' ') && (input[i] !='	') && (input[i] !='\n') && (input[i] !='\0') && (input[i] !='\t') &&(input[i] != '\r')){

						
						counter++;
					}
				}
				i++;
			
			}
	
		return counter;
	}//39


	char* getstring( char arr[10000], FILE *fp){
		int i = 0;
		int t=0;
        	char c;
		int a=0;
		char line[10000];
		
		
	while (1) {
    	    if (fgets(line,255, fp) == NULL) break;
    		    a=strlen(line);
			for(int g=0;g<a;g++){
				
				arr[t]=line[g];
				t++;
			}
   		     
	}
		
		
	
  

		return arr;
	}//20
	
	
 
		
		




	int count_identifiers( char* input){
		
		int sum=0;
		int count=0;
		char * pch;
		int flag3=0;
		int i=0;
		int flag=0;
		int flag2=0;
		int counter=0;
		char array[10000];
		int g=0;
int var=0;
	while(input[i]!=0){
				if((input[i]=='/') && (input[i+1] == '*')){
					flag=1;	
					i++;
					i++;				
				}
				
				if((input[i]=='*') && (input[i+1] == '/')){
					flag=0;	
					i++;
					i++;				
				}
				if((input[i]=='/') && (input[i+1] == '/')){
					flag2=1;	
					i++;
					i++;				
				}
				if((input[i]=='(') && (input[i+1] == '"')){
					flag3=1;	
					i++;
					i++;				
				}
				if((input[i]=='"') && (input[i+1] == ')')){
					flag3=0;	
					i++;
					i++;				
				}
	
				if(input[i]=='\n'){
					flag2=0;	
							
				}
				if((flag==0)&& (flag2==0) && (flag3==0)){
					array[g]=input[i];
					g++;
				}
				i++;
			
			}



	
		
		
  pch = strtok (array," 	;(),\n");
  while (pch != NULL)
  {
	
	i=0;
	count=0;
	if((pch[0]=='_')  || (pch[0] >='a'&& pch[0]<='z' ) || (pch[0] >='A' && pch[0] <='Z')){
	while(pch[i]!= 0){
		if((pch[i] >='a'&& pch[i]<='z' ) || (pch[i] >='A' && pch[i] <='Z') || (pch[i] >='0' && pch[i] <='9') ){
			count++;
		}
		if((pch[i] =='~') || (pch[i] =='!' ) ||   (pch[i] =='@')  || (pch[i] =='#') ||  (pch[i] =='%')  || (pch[i] =='^') || (pch[i] =='&') || (pch[i] =='*') ||  (pch[i] =='"') || (pch[i] == ':') 
|| (pch[i] == '"') || (pch[i] == '<') || (pch[i] == '>') || (pch[i] == '?')){

			count=0;
			break;
		}
	
		i++;	
	}
	
	sum=sum+count;
	}	
    pch = strtok (NULL, "	 (),;\n");
  
}
//printf("%d\n",sum);
	
//printf("%d\n",counter);
//printf("%d\n",count_id);
	return sum;
	}//45
	
	


	void write_file( int count_symbols, int count_ident){//v tozi sluchai programata ne raboti
		char file[100];		 
		FILE *fptr;
		printf("Vavedete ime na faila v koito iskate da zapishete\n");
		scanf("%s",file);
   		fptr = fopen(file, "w");
   		if(fptr == NULL)
   		{
      			printf("Error!");
      			
   		}

   		fprintf(fptr,"obsht broi simvoli v komentarite\n");
   		fprintf(fptr,"%d\n",count_symbols);
   		fprintf(fptr,"broi na simvolite v identifikatorite\n");
 		fprintf(fptr,"%d\n",count_ident);
   		fclose(fptr);

	}//rezultat 34 no izkarva 38



		void read_file( int option){
		FILE * fp;
		char str[10000];
		char file[1000];
	
	    
		printf("Vavedete ime na faila ot koito iskate da chetete\n");

	     scanf("%s",file);
	    fp = fopen(file, "r");

int i = 0;
		int t=0;
        	char c;
		int a=0;
		char line[10000];
		
		
	while (1) {
    	    if (fgets(line,255, fp) == NULL) break;
    		    a=strlen(line);
			for(int g=0;g<a;g++){
				
				str[t]=line[g];
				t++;
			}
   		     
	}

	
		

	if(option == 2){
		printf("obsht broi simvoli v komentarite\n");
		int b;
	
		b=count_symbols(str);
		printf("%d\n",b);	
		printf("broi na simvolite v identifikatorite\n");
		int k;
	
		k=count_identifiers(str);
		printf("%d\n",k);
	}
	if(option==1){

		
		int b;
	
		b=count_symbols(str);	
		
		int k;

		k=count_identifiers(str);
		write_file(b,k);

	}
	
	


    fclose(fp);
 



}//pravilno


int main(){
	
	char* input;
	
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
		input=getstring(input,stdin);
		printf("obsht broi simvoli v komentarite\n");
	a=count_symbols(input);
	printf("%d\n",a);	
	printf("broi na simvolite v identifikatorite\n");

	b=count_identifiers(input);
	
	printf("%d\n",b);
		
                break;
            case 4: input=getstring(input,stdin);
			
			a=count_symbols(input);
			
			b=count_identifiers(input);
			
	  	        write_file(a,b);
	     
                break;
		   case 5: printf("Quitting program!\n");
               
                break;
            default: printf("Invalid choice!\n");
                break;
        }
 
    } while (choice != 5);
 
	

	
return 0;
}


