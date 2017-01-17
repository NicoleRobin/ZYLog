/*
 * g++ -o test ./test.cpp ../src/ZYLog.cpp -I ../include -lpthread
 */
#include "ZYLog.h"
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void *ThreadFunc(void *arg)
{
	pthread_t tid = pthread_self();
	for (int i = 0; i < 10; ++i)
	{
		LOG_DEBUG("Thread %u, Debug %d", tid, i);
		LOG_ERROR("Thread %u, Error %d", tid, i);
		sleep(1);
	}

	return (void*)0;
}

int main(int argc, char **argv)
{
	pthread_t tid[10];
	for (int i = 0; i < 10; ++i)
	{
		pthread_create(&tid[i], NULL, ThreadFunc, NULL);
	}

	for (int i = 0; i < 10; ++i)
	{
		pthread_join(tid[i], 0);
	}

	return 0;
}
