#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <filesystem>


void Logger::log(string s) {
	readyLogFile("log.txt");
	writeLog(s);
}

void Logger::writeLog(string s) {

	vector<string> dataBuf;
	string fileName = "log.txt";
	ofstream file(fileName, ios_base::app);
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
