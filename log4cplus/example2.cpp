#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/loggingmacros.h>

#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
    using namespace log4cplus;

    Logger logger = Logger::getInstance("main");
    SharedAppenderPtr appender(new ConsoleAppender());
    std::string pattern = "%D{%m/%d/%y %H:%M:%S} %p - %m%n";
    std::auto_ptr<Layout> layout(new PatternLayout(pattern));
    appender->setLayout(layout);
    logger.addAppender(appender);

    LOG4CPLUS_ERROR(logger, "Hello, error!");
    LOG4CPLUS_WARN(logger, "Hello, warn!");
    LOG4CPLUS_INFO(logger, "Hello, info!");
    LOG4CPLUS_DEBUG(logger, "Hello, debug!");

    return 0;
}
