void resize(){
	T* old_buffer=buffer;
	capacity_+=chunk_size;
	buffer=new T[capacity_];
for(int i=0;i<size_;i++){
		old_buffer[i]=buffer[i];
	}
	delete [] old_buffer;
}
 T& operator[](int index) {
    return buffer[index];
  }
