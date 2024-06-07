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
	EXPECT_THAT(data, MatchesRegex("\\[.*\\] .* : abcd$"));
	// TODO : regex change
	//EXPECT_THAT(data, MatchesRegex("\\[[0-9]{2}\\.[0-9]{2}\\.[0-9]{2} [0-9]{2}h:[0-9]{2}m\\] .{50} : abcd$"));
	//EXPECT_THAT(data, MatchesRegex("\[[0-9]{2}\.[0-9]{2}\.[0-9]{2} [0-9]{2}h:[0-9]{2}m\] .{50} : abcd$"));
}

