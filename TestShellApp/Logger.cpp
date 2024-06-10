#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <filesystem>
#include <direct.h>
#include <regex>

#define LOG_PRINT(message) Logger::print(message, __FUNCTION__)

const int TIME_FORMAT_MAX_SIZE = 100;
const int SIZE_10K = (10 * 1024);
const int FUNCTION_LOG_SIZE = 50;
const string UNTIL_LOG_FILE_FORMAT = "^until_[0-9]{6}_[0-9]{2}h_[0-9]{2}m_[0-9]{2}s.log$";

void Logger::print(string inputStr, const char* function) {
	backupLogFileIfNeeded(LOG_FULL_PATH_NAME);
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

	string timeHeaderLog = getCurrentTimeFormat("[%y.%m.%d %Hh:%Mm]");
	logfile << timeHeaderLog << " " << setw(FUNCTION_LOG_SIZE) << std::left << function << " : " << inputStr << endl;
	logfile.close();

	std::cout << std::right; //back to default option
}

void Logger::backupLogFileIfNeeded(string fileName) {

	int fileSize = filesystem::file_size(fileName);

	if (fileSize < SIZE_10K)
		return;

	vector<string> filelist = getLogFileList();
	for (string filename : filelist) {
		if (regex_match(filename, regex(UNTIL_LOG_FILE_FORMAT)))
		{
			//rename to zip
			string newfile = filename.substr(0, filename.length() - 4) + ".zip";
			filesystem::rename(LOG_DIR + "/" + filename, LOG_DIR + "/" + newfile);
		}
	}

	string untilLogFileName = getCurrentTimeFormat("until_%y%m%d_%Hh_%Mm_%Ss.log");
	filesystem::rename(fileName, LOG_DIR + "/" + untilLogFileName);
	return;
}

vector<string> Logger::getLogFileList() {
	vector<string> fileList;
	if (filesystem::exists(LOG_DIR)) {
		for (const auto& entry : filesystem::directory_iterator(LOG_DIR)) {
			if (entry.is_regular_file()) {
				fileList.push_back(entry.path().filename().string());
			}
		}
	}
	return fileList;
}

string Logger::getCurrentTimeFormat(string strFormat) {
	char strTemp[TIME_FORMAT_MAX_SIZE];
	
	if (strFormat.size() > TIME_FORMAT_MAX_SIZE / 2) {
		cout << "getCurrentTimeFormat Size > " << (TIME_FORMAT_MAX_SIZE / 2) << endl;
		return "";
	}

	time_t now = time(nullptr);
	tm tmNow;
	localtime_s(&tmNow, &now);
	strftime(strTemp, sizeof(strTemp), strFormat.c_str(), &tmNow);
	return (string)strTemp;
}
