#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string LOG_DIR = "./Log";
const string LOG_FILE_NAME = "latest.log";
const string LOG_FULL_PATH_NAME = LOG_DIR + "/" + LOG_FILE_NAME;

static class Logger {
public:
	static void print(string s, const char* function);
	static void writeLog(string s, const char* function);
private:
	static void backupLogFileIfNeeded();
	static vector<string> getUntilLogFileList();
	static string getCurrentTimeFormat(string strFormat);
};
