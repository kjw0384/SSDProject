#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ShellStringParser.cpp"

using namespace std;

TEST(ShellExecute, NoCommandExecute) {
	ShellStringParser s;
	EXPECT_EQ(s.validCheck(""), 1) << "Error Return not 1" << endl;
}

TEST(ShellExecute, CommandNotValid) {
	ShellStringParser s;
	EXPECT_EQ(s.validCheck("ADF 1 0x59261655"), 2) << "Error Return not 2" << endl;
}

TEST(ShellExecute, WriteNormal) {
	ShellStringParser s;
	EXPECT_EQ(s.validCheck("W 1 0x59261655 E"), 3) << "Error Return not 2" << endl;
}
