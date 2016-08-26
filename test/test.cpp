/*
 * g++ -o test ./test.cpp ../src/ZYLog.cpp -I ../include
 */
#include "ZYLog.h"

int main(int argc, char **argv)
{
	for (int i = 0; i < 10; ++i)
	{
		LOG_DEBUG("Debug %d", i);
		LOG_ERROR("Error %d", i);
	}

	return 0;
}
