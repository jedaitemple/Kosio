#include <stdio.h>
#include <stdlib.h>

	int strcmp(const char *s1, const char *s2) {
  		unsigned char c1, c2;
   		 while ((c1 = *s1++) == (c2 = *s2++)) {
     			   if (c1 == '\0')
         	   return 0;
    	}
 	   return c1 - c2;
	}
	size_t strlen(const char *str){
        	const char *s;

      		  for (s = str; *s; ++s)
      	          ;
      	  return (s - str);
	}
	char *strcpy(  char *d, const  char *s){
   		char *saved = d;
   		while ((*d++ = *s++) != '\0');

   	return saved; //returning starting address of s1
	}
	char* strtok(char* str, const char* tokens){
    //Making a static string to be used again on next function call.
     		char *temp;
    
    	//If string passed to function is not null, copy it to our static variable
    		if(str!=NULL){
        		temp=(char*)malloc(strlen(str));
        		strcpy(temp,str);
    		}

    //If the string passed is NULL and even the copy is NULL, we are done and return NULL.
    		else if(temp==NULL)
   			 return NULL;

    //If only the string passed is NULL and the copy still has data, work with it.
    		else{
        		str=temp;
 		}

 	   int chars=0, len = strlen(tokens), flag=0;
    
    //Run the loop till we find a token or our copy is fully parsed.
 		   while(*temp){
        		for(int i=0;i<len;i++){
            			if(*temp==tokens[i]){
                			if(chars==0){
                    				flag=1;
                    				str++;
                		}
                			else{
                    				temp++;
                    				str[chars]='\0';
                    				return str;
               				 }
          			}
        		}
       			 if(flag==0)
           			 chars++;
       				 temp++;
      				  flag=0;
		    }
    		temp=NULL;
   		 str[chars]='\0';
   	return str;
	}





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


	char* getstring(){
		int i = 0;
		char* temp;
        	char c, *input;
		input = (char *) malloc(sizeof(char));
	
		  if(input == NULL) {
			    printf("Could not allocate memory!");
		   
		  }
	
		 while((c = getchar()) != EOF) {
			    input[i++] = c;
			    temp=realloc(input,(i+2)*sizeof(char)); /* give the pointer some memory */
					if ( temp != NULL ) {
						input=temp;
					} else {
						free(input);
						printf("Error allocating memory!\n");

					}
	

  		}

		 input[i] = '\0';
  

		return input;
	}//20

	char** get_a( char* input){
		int NumStrings=0;
		int b=0;
		while(input[b] != '\0'){
			if((input[b] != ' ')  ||(input[b] !='\n') || (input[b] != '\t')  ){
				NumStrings++;
			}
		b++;
		
		}
	char **strings = (char**) malloc(sizeof(char*) * NumStrings);
	for( int i = 0; i < NumStrings; i++)
		{
   /*Just an example of how every string may have different memory allocated.
      Note that sizeof(char) is normally 1 byte, but it's better to let it there */
   			strings[i] = (char*) malloc(sizeof(char) * i * 10);
		}

 	int i=0;
		strings[i] = strtok(input,"	 \n");
	
		while(strings[i]!=NULL){
     		
			strings[++i] = strtok(NULL," 	\n");
		}

		return strings;
	} //30
 

	int count_identifiers( char* input){

		char **array;
 		array=get_a(input);

		int g=0;
		int v=0;
		int counter=0;
		int count_id=0;
		int i=0;
	while(array[i]!=NULL){
     			i++;
			
		}
	
	
		for(g=0;g<i;g++){
		

			if((strcmp(array[g],"char")==0) || (strcmp(array[g],"int")==0) ||  (strcmp(array[g],"double")==0) || (strcmp(array[g],"char*")==0) ||(strcmp(array[g],"float")==0) || (strcmp(array[g],"short")==0) || (strcmp(array[g],"void")==0)  || (strcmp(array[g],"char**")==0)) {
				v=0;
				counter++;
					while((array[g+1][v] !=';') && (array[g+1][v] != '(') && (array[g+1][v] != ')') && (array[g+1][v] != '=')  ){
					
						
							if((array[g+1][v] !=' ') && (array[g+1][v] !='	') && (array[g+1][v] !='\n') &&  (array[g+1][v] !=',') && (array[g+1][v] !='\0') && (array[g+1][		v] !='\t') &&(array[g+1][v]!= '\r') && (array[g+1][v]!= '*') && (array[g+1][v] != ';') ){
							count_id++;
						}
							v++;
					}	
			}
	}
	free(array);
//printf("%d\n",counter);
//printf("%d\n",count_id);
	return count_id;
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
	
	char* temp;
	char file[100];
	 FILE * fp;
	    char * line = NULL;
	    size_t len = 0;
	    ssize_t read;
		char  *str;
		str = (char *) malloc(sizeof(char));
		  if(str == NULL) {
			    printf("Could not allocate memory!");
		    
		  }
		printf("Vavedete ime na faila ot koito iskate da chetete\n");
	     scanf("%s",file);
	    fp = fopen(file, "r");
	    if (fp == NULL)
	        
	    strcpy (str,"");
		int i=0;
		
		int g=0;;
		    while ((read = getline(&line, &len, fp)) != -1) {
	
			i=0;
		

			while(line[i]!='\0'){
	  			str[g] = line [i];
			    	temp=realloc(str,(g+2)*sizeof(char)); /**/
					if ( temp != NULL ) {
						str=temp;
					} else {
						free(str);
						printf("Error allocating memory!\n");

					}
				 
			i++;
			g++;
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
	
	if(str)
		free(str);


    fclose(fp);
 	   if (line)
 	       free(line);



}//pravilno
