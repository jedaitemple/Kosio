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
