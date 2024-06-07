#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <filesystem>
#include <direct.h>

#define LOG_MESSAGE(message) Logger::log(message, __FUNCTION__)

void Logger::log(string inputStr, const char* function) {
	readyLogFile(LOG_FULL_PATH_NAME);
	writeLog(inputStr, function);
}

void Logger::writeLog(string inputStr, const char* function) {

	cout << "s:" << inputStr << endl;
	cout << "function:" << function << endl;

	if (filesystem::exists(LOG_DIR) == false)
	{
		if (_mkdir(LOG_DIR.c_str()) != 0) {
			cout << "Result Dir Make Fail" << endl;
			return;
		}
	}

	ofstream logfile(LOG_FULL_PATH_NAME, ios_base::app);
	if (!logfile.is_open())
	{
		cout << "log.txt file open fail" << endl;
		return;
	}

	time_t now = time(nullptr);
	tm tmNow;
	localtime_s(&tmNow, &now);
	char logstr[100];
	strftime(logstr, sizeof(logstr), "[%y.%m.%d %Hh:%Mm]", &tmNow);
	logfile << format("{0} {1:50s} : {2}", (string)logstr, function, inputStr);
	logfile.close();
}

void Logger::readyLogFile(string fileName) {

	return;
}
