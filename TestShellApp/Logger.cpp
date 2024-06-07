#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <filesystem>
#include <direct.h>


void Logger::log(string s) {
	readyLogFile(LOG_FILE);
	writeLog(s);
}

void Logger::writeLog(string s) {

	if (std::filesystem::exists(LOG_DIR) == false)
	{
		if (_mkdir(LOG_DIR.c_str()) != 0) {
			cout << "Result Dir Make Fail" << endl;
			return;
		}
	}

	ofstream file(LOG_FILE, ios_base::app);
	if (!file.is_open())
	{
		cout << "log.txt file open fail" << endl;
		return;
	}
	file << s << endl;

	file.close();
}

void Logger::readyLogFile(string fileName) {
	return;
}
