#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>

#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
    using namespace log4cplus;
    BasicConfigurator config;
    config.configure();

    Logger logger = Logger::getInstance("main");

    LOG4CPLUS_ERROR(logger, "Hello, error!");
    LOG4CPLUS_WARN(logger, "Hello, warn!");
    LOG4CPLUS_INFO(logger, "Hello, info!");
    LOG4CPLUS_DEBUG(logger, "Hello, debug!");

    return 0;
}
