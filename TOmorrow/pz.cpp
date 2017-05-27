void Book::setname(const char* str)
{
	if(!str)
	{
		delete[] this->name;
		this->name = NULL;

		return;
	}

	size_t length = strlen(str) + 1;
	
	char* buffer = new char[length];
	strcpy(buffer,  str);

	delete[] this->name;
	this->name = buffer;
}
  void resize(){
        int* old_buffer=buffer;
        capacity+=1;
        buffer=new int[capacity];
        for(int i=0;i<capacity;i++){
            buffer[i]=old_buffer[i];
        }
        delete [] old_buffer;
    }
 void Add_egg(const EGG& EG1){
	  
     EGG* old_buffer=egg;
	if(egg !=0){
		delete [] egg;
	}
        number_egg+=1;
        egg=new EGG[number_egg];
        for(int i=0;i<number_egg;i++){
            egg[i]=old_buffer[i];
        }
        delete [] old_buffer;

        }
