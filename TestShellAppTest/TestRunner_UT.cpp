#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestRunner.cpp"

class TetRunnerFixture : public ::testing::Test {
public:
	TetRunnerFixture() {
		m_command = {"READ", 23, 0x7777};
	}

	TestRunner m_testRunner;
	Command m_command; 
};

TEST_F(TetRunnerFixture, InputCmd) {
	EXPECT_EQ(m_testRunner.inputCmd(m_command), SUCCESS);
}

TEST_F(TetRunnerFixture, RunTest) {
	EXPECT_EQ(m_testRunner.run(), SUCCESS);
}