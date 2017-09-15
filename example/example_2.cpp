/*
 * @File: example_2.cpp
 * @Function: 输出日志到文件中
 */
#include "ZYLog.h"
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#include <iostream>

using namespace std;

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
	if (argc != 2)
	{
		cout << "Usage:argv[0] logfile" << endl;
		return 0;
	}

	LOG_INIT(argv[1]);
	
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
