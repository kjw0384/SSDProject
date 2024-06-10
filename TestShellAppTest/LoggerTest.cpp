#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/Logger.cpp"
#include <filesystem>
#include <regex>
using namespace testing;


TEST(LoggerTest, writeLog) {
	if (filesystem::exists(LOG_DIR))
		filesystem::remove_all(LOG_DIR);
	Logger::writeLog("abcd", __FUNCTION__);
	
	ifstream file(LOG_FULL_PATH_NAME);
	string data;
	getline(file, data);
	
	regex txt_regex("\\[[0-9]{2}\\.[0-9]{2}\\.[0-9]{2} [0-9]{2}h:[0-9]{2}m\\] .{50} : abcd$");
	EXPECT_EQ(regex_match(data, txt_regex), true);
}
