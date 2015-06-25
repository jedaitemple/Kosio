#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int g = 0;

void* thread(void* arg) {
	printf("1\n");
	int* val = (int*) malloc(sizeof(int));
	val = (int*) arg;
	pthread_mutex_lock(&mutex);
	g += *val;
	pthread_mutex_unlock(&mutex);
	pthread_exit((void*) val);
}

int main() {
	int cmp = 0;
	int  i  = 0;
	int a[10];
	pthread_t id[10];
	pthread_mutex_init(&mutex, NULL);
	for(i = 0; i < 10;++i) {
		a[i] = i;
		pthread_create(&id[i], NULL, thread, (void *) &a[i]);
	}
	for(i = 0; i < 10;++i) {
		int* res;
		pthread_join(id[i], (void*)&res);
		cmp += *res;
	}
	printf("%d\n", (cmp == g));
	printf("%d\n", g);
	printf("%d\n", cmp);
	pthread_mutex_destroy(&mutex);
	return 0;
}
