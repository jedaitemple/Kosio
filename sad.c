#include<stdio.h>
int main(){
FILE *fp;
fp=fopen("test.bin", "wb");

//size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
char* kosio="Kosio e velik";

 fwrite(kosio, sizeof(char*), 25, fp);
fclose(fp);
 char ptr[100];
 fp=fopen("test.bin", "rb");

fread(ptr, sizeof(char*), 25, fp);
printf("%s\n",ptr);
return 0;

}
