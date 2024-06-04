#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestRunner.cpp"

class TestRunnerFixture : public ::testing::Test {
public:
	TestRunnerFixture() {
		m_command = {"READ", 23, 0x7777};
	}

	TestRunner m_testRunner;
	Command m_command; 
};

TEST_F(TestRunnerFixture, InputCmd) {
	EXPECT_EQ(m_testRunner.inputCmd(m_command), SUCCESS);
}

TEST_F(TestRunnerFixture, RunTest) {
	EXPECT_EQ(m_testRunner.run(), SUCCESS);
}