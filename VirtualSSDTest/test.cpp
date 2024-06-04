#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ShellStringParser.cpp"

using namespace std;

class ShellExecuteFixture : public testing::Test {
public:
	ShellStringParser parser;
	void checkErrorCode(string inputStr, int errorCode) {
		int errorResult = parser.validCheck(inputStr);
		EXPECT_EQ(errorResult, errorCode) << "Error Return not " << errorCode << endl;
	}
};

TEST_F(ShellExecuteFixture, NoCommandExecute) {
	checkErrorCode("", 1);
}

TEST_F(ShellExecuteFixture, CommandNotValid) {
	checkErrorCode("ADF 1 0x59261655", 2);
}

TEST_F(ShellExecuteFixture, WriteArgumentCountError) {
	checkErrorCode("W 1 0x59261655 E", 3);
}
	