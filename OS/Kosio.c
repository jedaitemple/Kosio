#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main() {
	DIR *d = opendir(".");
	struct dirent *entry;

	struct stat st;
	stat("dir.c", &st);
	printf("%lld  ", (long long) st.st_size);
	

	printf("%d  ", st.st_mode &S_IXUSR); 
	
	while(entry != NULL){
		entry = readdir(d);
		if(entry != NULL){
			printf("%s   ", entry->d_name);
		}
	}
	closedir(d);
	
	return 0;
}
