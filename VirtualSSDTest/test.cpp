#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ShellStringParser.cpp"

using namespace std;

class ShellExecuteFixture : public testing::Test {
public:
	ShellStringParser parser;
	void checkErrorCode(string inputStr, ShellStringParserError errorCode) {
		ShellStringParserError errorResult = parser.validCheck(inputStr);
		EXPECT_EQ(errorResult, errorCode) << "Error Return Fail " << endl;
	}
};

TEST_F(ShellExecuteFixture, NoCommandExecute) {
	checkErrorCode("", ShellStringParserError::CMD_EMPTY);
}

TEST_F(ShellExecuteFixture, CommandNotFound) {
	checkErrorCode("ADF 1 0x59261655", ShellStringParserError::CMD_NOT_FOUND);
}

TEST_F(ShellExecuteFixture, WriteArgumentCountError) {
	checkErrorCode("W 1 0x59261655 E", ShellStringParserError::CMD_ARGC_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsFormatError) {
	checkErrorCode("W qfe5 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 1 0X59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 1 0", ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsLBAError) {
	checkErrorCode("W -1 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 999 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
}
