#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestScriptRunner.cpp"
#include "../TestShellApp/VirtualSsdProcessInterface.h"
#include "../TestShellApp/VirtualSsdProcessMock.h"

using namespace testing;

//TODO: check mock redundancy of MocReadIO class (duplicated to TestReadIOTest.cpp)
class MockReadIO : public ReadIOInterface {
public:
	MOCK_METHOD(string, GetReadResult, (), (override));
};

class TestRunnerFixture : public ::testing::Test {
public:
	TestRunnerFixture() {
	}

	TestScriptRunner m_testRunner{ new VirtualSsdProcessMock, new MockReadIO };
};

TEST_F(TestRunnerFixture, InputCmd) {
	Command testCmd = { "read", 23, "0x77777777" };
	EXPECT_EQ(m_testRunner.inputCmd(testCmd), Result_e::SUCCESS);
}

TEST(VirtualSsdProcMock, RunTest) {
	VirtualSsdProcessMock mockVirtualSSDproc;
	MockReadIO mockReadIO;

	EXPECT_CALL(mockVirtualSSDproc, sendReadIpc)
		.Times(1)
		.WillOnce(Return(Result_e::SUCCESS));

	EXPECT_CALL(mockReadIO, GetReadResult)
		.Times(1)
		.WillOnce(Return("0x77777777"));

	Command testCmd = { "read", 23, "0x77777777" };
	TestScriptRunner testRunner(&mockVirtualSSDproc, &mockReadIO);
	testRunner.inputCmd(testCmd);
	EXPECT_EQ(testRunner.run(), Result_e::SUCCESS);
}