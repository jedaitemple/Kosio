/*
#include<iostream>
using namespace std;

char* reallocate(char* str, size_t& size) {
    const size_t newSize = size << 1;
    char* tmp = new char[newSize];
    for(size_t i =0; i < size; ++i) {
        tmp[i] = str[i];
    }
    delete[] str;
    size = newSize;

    return tmp;
}

int strlen(const char* array){
	int i=0;
	while(array[i] !=0){
		i++;
		
	}
	return i;

}
char* resize(char* str, size_t& size) {
    
    char* tmp = new char[size];
    for(size_t i =0; i < size; ++i) {
        tmp[i] = str[i];
    }
    delete[] str;
   

    return tmp;
}


char* stripduplicates(const char* str){
	int size1=0;
	int flag=1;
	int lent1;
	size_t size=0;
	char* str2 = new char[size];
	int lent=strlen(str);
	for(int i=0;i<=lent;i++){
		lent1=strlen(str2);
		for(int g=0;g<=lent1;g++){
			if(str2[g] == str[i]){
				flag=0;
			}
					
		}
			if(flag==1){

				size++;
				str2=resize(str2,size);
				str2[size1]=str[i];
				size1++;	
			}
		

				flag=1;

		}
	
	return str2;
}
int main() {
    size_t capacity = 10;
    size_t size = 0;
    char* str = new char[size];
    while(true) {
        if(size == capacity) {
            str = reallocate(str, capacity);
        }
        str[size] = std::cin.get();
        if(str[size] == '\n') {
            str[size] = '\0';
            break;
        }
        size++;
    }
char* str1 = new char[10];
str1=stripduplicates(str);
cout<<str1<<endl;

    return 0;
}
*/
/*

#include<iostream>
using namespace std;

char* reallocate(char* str, size_t& size) {
    const size_t newSize = size << 1;
    char* tmp = new char[newSize];
    for(size_t i =0; i < size; ++i) {
        tmp[i] = str[i];
    }
    delete[] str;
    size = newSize;

    return tmp;
}

int strlen(const char* array){
	int i=0;
	while(array[i] !=0){
		i++;
		
	}
	return i;

}


int main() {
    size_t capacity = 10;
    size_t size = 0;
    char* str = new char[size];
    while(true) {
        if(size == capacity) {
            str = reallocate(str, capacity);
        }
        str[size] = std::cin.get();
        if(str[size] == '\n') {
            str[size] = '\0';
            break;
        }
        size++;
    }
cout<<str<<endl;
    return 0;
}
*/

