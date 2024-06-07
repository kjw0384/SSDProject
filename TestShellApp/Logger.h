#pragma once
#include <iostream>
#include <string>

using namespace std;

const string LOG_DIR = "./Log";
const string LOG_FILE = LOG_DIR + "/latest.log";

static class Logger {
public:
	static void log(string s);
	static void writeLog(string s);
private:
	static void readyLogFile(string fileName);
};
