#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../TestShellApp/ResultFileReader.cpp"
#include "../TestShellApp/TestScriptRunner.cpp"
#include "../TestShellApp/VirtualSsdProcessInterface.h"
#include "../TestShellApp/VirtualSsdProcessMock.h"

using namespace testing;

class MockReadIO : public ReadIOInterface
{
  public:
    MOCK_METHOD(string, GetReadResult, (), (override));
};

class TestRunnerFixture : public ::testing::Test
{
  public:
    TestRunnerFixture()
    {
    }

    TestScriptRunner m_testRunner{new VirtualSsdProcessMock, new MockReadIO};
};

TEST_F(TestRunnerFixture, InputCmd)
{
    ShellCommand testCmd = {"read", 23, "0x77777777"};
    EXPECT_EQ(m_testRunner.inputShellCmd(testCmd), Result_e::SUCCESS);
}

TEST(VirtualSsdProcMock, RunTest)
{
    VirtualSsdProcessMock mockVirtualSSDproc;
    MockReadIO mockReadIO;

    EXPECT_CALL(mockVirtualSSDproc, sendReadIpc).Times(1).WillOnce(Return(Result_e::SUCCESS));

    EXPECT_CALL(mockReadIO, GetReadResult).Times(1).WillOnce(Return("0x77777777"));

    ShellCommand testCmd = {"read", 23, "0x77777777"};
    TestScriptRunner testRunner(&mockVirtualSSDproc, &mockReadIO);
    testRunner.inputShellCmd(testCmd);
    EXPECT_EQ(testRunner.run(), Result_e::SUCCESS);
}
