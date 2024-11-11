#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct SumArgs{
	int *arr;
	int start;
	int end;
	int id;
};


void* sum(void* args) {
	struct SumArgs* sum_args = (struct SumArgs*)args;
	int* arr = sum_args->arr;
	int start = sum_args->start;
	int end = sum_args->end;
	int id = sum_args->id;

	int total = 0;

	for(int i = start; i < end; i++) {
		total += arr[i];
	}
	printf("Sum of thread %d: %d\n",id,total);
	pthread_exit(NULL);
}


int main() {
	int arr[6] = {20,40,2,4,129,258};
	
	pthread_t t1;
	pthread_t t2;

	struct SumArgs args1 = {arr,0,3,1};
	struct SumArgs args2 = {arr,3,6,2};

	pthread_create(&t1,NULL,sum,(void*)&args1);
	pthread_create(&t2,NULL,sum,(void*)&args2);


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}
