#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/Logger.cpp"
#include <filesystem>
using namespace testing;


TEST(LoggerTest, writeLog) {
	if (filesystem::exists("log.txt"))
		filesystem::remove("log.txt");
	Logger::writeLog("abcd");
	ifstream file("log.txt");
	string data;
	getline(file, data);
	EXPECT_EQ(data, "abcd");
}
