#include "ZYLog.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/time.h>


#define LOG_BUF_SIZE 1024
#define TIME_BUF_SIZE 32

CZYLog* CZYLog::Instance()
{
	static CZYLog s_zylog;
	return &s_zylog;
}

void CZYLog::WriteLog(const char *filename, int line, const char *funcname, const char *logLevel, const char *msg, ...)
{
	char szFile[LOG_BUF_SIZE + 1] = "";
	snprintf(szFile, LOG_BUF_SIZE, "[%-5s][%s:%d][%s]", logLevel, filename, line, funcname);

	char szMsg[LOG_BUF_SIZE + 1] = "";
	va_list argList;
	va_start(argList, msg);
	vsnprintf(szMsg, LOG_BUF_SIZE, msg, argList);
	va_end(argList);

	timeval tv;
	gettimeofday(&tv, NULL);
	struct tm *local = localtime(&tv.tv_sec);

	char szTime[TIME_BUF_SIZE + 1] = "";
	snprintf(szTime, TIME_BUF_SIZE, "[%04d-%02d-%02d %02d:%02d:%02d.%06d]", 
			local->tm_year + 1900, 
			local->tm_mon + 1, 
			local->tm_mday, 
			local->tm_hour, 
			local->tm_min, 
			local->tm_sec, 
			(int)tv.tv_usec);

	char szLog[LOG_BUF_SIZE + 1] = "";
	snprintf(szLog, LOG_BUF_SIZE, "%s%s %s", szTime, szFile, szMsg);

	printf("%s\n", szLog);
}
