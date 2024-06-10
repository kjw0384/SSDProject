#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <filesystem>
#include <direct.h>
#include <regex>

#define LOG_MESSAGE(message) Logger::log(message, __FUNCTION__)

void Logger::log(string inputStr, const char* function) {
	readyLogFile(LOG_FULL_PATH_NAME);
	writeLog(inputStr, function);
}

void Logger::writeLog(string inputStr, const char* function) {

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
	logfile << format("{0} {1:50s} : {2}\n", (string)logstr, function, inputStr);
	logfile.close();
}

void Logger::readyLogFile(string fileName) {

	int fileSize = filesystem::file_size(fileName);
	vector<string> filelist;

	if (fileSize < 10 * 1024)
		return;

	//rename before
	if (filesystem::exists(LOG_DIR)) {
		for (const auto& entry : filesystem::directory_iterator(LOG_DIR)) {
			if (entry.is_regular_file()) {
				filelist.push_back(entry.path().filename().string());
			}
		}
	}

	for (int i = 0; i < filelist.size(); i++) {
		regex txt_regex("^until_[0-9]{6}_[0-9]{2}h_[0-9]{2}m_[0-9]{2}s.log$");

		if (filelist[i] == LOG_FILE_NAME)
			continue;
		else if (regex_match(filelist[i], txt_regex))
		{
			//rename to zip
			string newfile = filelist[i].substr(0, filelist[i].length() - 4) + ".zip";
			filesystem::rename(LOG_DIR + "/" + filelist[i], LOG_DIR + "/" + newfile);
		}
	}

	//filesystem::rename
	//rename current
	time_t now = time(nullptr);
	tm tmNow;
	localtime_s(&tmNow, &now);
	char untilLogFileName[100];
	strftime(untilLogFileName, sizeof(untilLogFileName), "until_%y%m%d_%Hh_%Mm_%Ss.log", &tmNow);
	filesystem::rename(fileName, LOG_DIR + "/" + (string)untilLogFileName);
	return;
}