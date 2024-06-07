#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/Logger.cpp"
#include <filesystem>
using namespace testing;


TEST(LoggerTest, writeLog) {
	if (filesystem::exists(LOG_FILE))
		filesystem::remove(LOG_FILE);
	Logger::writeLog("abcd");
	ifstream file(LOG_FILE);
	string data;
	getline(file, data);
	EXPECT_EQ(data, "abcd");
}
