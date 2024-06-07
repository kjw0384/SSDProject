#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/Logger.cpp"
#include <filesystem>
using namespace testing;


TEST(LoggerTest, writeLog) {
	if (filesystem::exists(LOG_DIR))
		filesystem::remove_all(LOG_DIR);
	Logger::writeLog("abcd", __FUNCTION__);
	ifstream file(LOG_FULL_PATH_NAME);
	string data;
	getline(file, data);
	EXPECT_EQ(data, "abcd");
}

