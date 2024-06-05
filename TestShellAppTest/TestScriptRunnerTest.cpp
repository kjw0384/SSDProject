#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestScriptRunner.cpp"
#include "../TestShellApp/VirtualSsdProcessInterface.h"

class VirtualSsdProcessMock : public VirtualSsdProcessInterface {
public:
	MOCK_METHOD(Result_e, sendReadIpc, (const int address), (override));
	MOCK_METHOD(Result_e, sendWriteIpc, (const int address, const string data), (override));

private:
};

//TODO: check mock redundancy of MocReadIO class (duplicated to TestReadIOTest.cpp)
class MockReadIO : public ReadIOInterface {
public:
	MOCK_METHOD(string, GetReadResult, (), (override));
};

class TestRunnerFixture : public ::testing::Test {
public:
	TestRunnerFixture() {
	}

	TestScriptRunner m_testRunner {new VirtualSsdProcessMock, new MockReadIO };
};

TEST_F(TestRunnerFixture, InputCmd) {
	Command testCmd = { "READ", 23, "0x77777777" };
	//TODO: check if m_testRunner contins command
	EXPECT_EQ(m_testRunner.inputCmd(testCmd), Result_e::SUCCESS);
}

TEST_F(TestRunnerFixture, RunTest) {
	Command testCmd = { "READ", 23, "0x77777777" };
	m_testRunner.inputCmd(testCmd);
	EXPECT_EQ(m_testRunner.run(), Result_e::SUCCESS);
}