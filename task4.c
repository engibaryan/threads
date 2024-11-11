#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct SquareArgs{
	int number;
	int id;

};

void* square(void* args) {
	struct SquareArgs* square_args = (struct SquareArgs*)args;
	int number = square_args->number;
	int id = square_args->id;

	int result = number * number;

	printf("Thread: %d, square is:%d\n", id , result);
	pthread_exit(NULL);

}


int main() {
	int arr[5] = {1,2,3,4,5};

	pthread_t threads[5];
	struct SquareArgs args[5];

	for(int i = 0; i < 5; i++) {
		args[i].number = arr[i];
		args[i].id = i +1;;		               
		pthread_create(&threads[i],NULL,square,(void*)&args[i]);

	}


	for(int i = 0; i < 5; i++){ 
		pthread_join(threads[i],NULL);
	}

	return 0;


}
