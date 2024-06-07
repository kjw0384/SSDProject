#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ShellStringParser.cpp"

class ShellExecuteFixture : public testing::Test {
public:
	ShellStringParser parser;
	void checkErrorCode(vector<string> inputCmdVec, ShellStringParserError errorCode) {
		ShellStringParserError errorResult = parser.validCheck(inputCmdVec);
		EXPECT_EQ(errorResult, errorCode) << "Error Return Fail " << endl;
	}
};

TEST_F(ShellExecuteFixture, NoCommandExecute) {
	checkErrorCode({}, ShellStringParserError::CMD_EMPTY);
}

TEST_F(ShellExecuteFixture, CommandNotFound) {
	checkErrorCode({ "ADF", "1", "0x59261655" }, ShellStringParserError::CMD_NOT_FOUND);
}

TEST_F(ShellExecuteFixture, WriteArgumentCountError) {
	checkErrorCode({ "W", "1", "0x59261655", "E" }, ShellStringParserError::CMD_ARGC_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsFormatError) {
	checkErrorCode({ "W", "qfe5", "0x59261655" }, ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode({ "W", "1", "0" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsLBAError) {
	checkErrorCode({ "W", "-1", "0x59261655" }, ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode({ "W", "999", "0x59261655" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, WriteNormal) {
	checkErrorCode({ "W", "99", "0x00000000" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "W", "0", "0x0FBD6F80" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "W", "35", "0x1234ABCD" }, ShellStringParserError::NO_ERROR);
}

TEST_F(ShellExecuteFixture, WriteNormalWhenCharUpperOrLowerCase) {
	checkErrorCode({ "W", "1", "0X59261655" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "W", "19", "0Xf9eBa6C5" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "w", "19", "0Xf9eBa6C5" }, ShellStringParserError::NO_ERROR);
}

TEST_F(ShellExecuteFixture, ReadArgumentCountError) {
	checkErrorCode({ "R", "1", "0x59261655" }, ShellStringParserError::CMD_ARGC_ERROR);
	checkErrorCode({ "R" }, ShellStringParserError::CMD_ARGC_ERROR);
}

TEST_F(ShellExecuteFixture, ReadArgumentsFormatError) {
	checkErrorCode({ "R", "qfe5" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, ReadArgumentsLBAError) {
	checkErrorCode({ "R", "-1" }, ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode({ "R", "999" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, ReadNormal) {
	checkErrorCode({ "R", "0" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "R", "12" }, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "r", "12" }, ShellStringParserError::NO_ERROR);
}

TEST_F(ShellExecuteFixture, EraseArgumentCountError) {
	checkErrorCode({ "E", "1" }, ShellStringParserError::CMD_ARGC_ERROR);
	checkErrorCode({ "E" }, ShellStringParserError::CMD_ARGC_ERROR);
}

TEST_F(ShellExecuteFixture, EraseArgumentsFormatError) {
	checkErrorCode({ "E", "qfe5" , "wef" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, EraseArgumentsSizeError) {
	checkErrorCode({ "E", "1", "-11" }, ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode({ "E", "11", "90" }, ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, EraseNormal) {
	checkErrorCode({ "E", "1", "10"}, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "E", "12", "9"}, ShellStringParserError::NO_ERROR);
	checkErrorCode({ "e", "90", "1"}, ShellStringParserError::NO_ERROR);
}