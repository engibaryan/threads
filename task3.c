#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* message(void* arg) {
	int thread_id = *((int*)arg);
	for(int i = 1; i < 6; i++) {
		printf("Thread %d is running: %d\n", thread_id,i);
	}
	pthread_exit(NULL);
}


int main() {
        pthread_t t1;
	pthread_t t2;
	pthread_t t3;

	const int id1 = 1;
	const int id2 = 2;
	const int id3 = 3;

	pthread_create(&t1, NULL, message,(void*)&id1);
	pthread_create(&t2, NULL, message,(void*)&id2);
        pthread_create(&t3, NULL, message,(void*)&id3);	
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	printf("All threads have completed. \n");
       	
	return 0;
}
