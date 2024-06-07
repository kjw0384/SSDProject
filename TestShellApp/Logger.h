#pragma once
#include <iostream>
#include <string>

using namespace std;


static class Logger {
public:
	static void log(string s);
	static void writeLog(string s);
private:
	static void readyLogFile(string fileName);
};
