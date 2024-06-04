#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestRunner.cpp"

TEST(TestRunnerSuite, InputCmd) {
	TestRunner testRunner;
	Command	cmd;
	EXPECT_EQ(testRunner.inputCmd(cmd), SUCCESS);
}

TEST(TestRunnerSuite, RunTest) {
	TestRunner testRunner;
	Command	cmd;
	EXPECT_EQ(testRunner.run(), SUCCESS);
}