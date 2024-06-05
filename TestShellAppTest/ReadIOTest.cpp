#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/ReadIOInterface.h"
#include "../TestShellApp/VirtualSsdProcess.cpp"

using namespace testing;

class MockReadIO : public ReadIOInterface {
public:
    MOCK_METHOD(string, GetReadResult, (), (override));
};

TEST(TestShellTestSuite, ReadIO) {
    MockReadIO mockReadIO;

    EXPECT_CALL(mockReadIO, GetReadResult)
        .Times(AtLeast(1))
        .WillRepeatedly(Return("0x12345678"));

    EXPECT_EQ(mockReadIO.GetReadResult(), "0x12345678");
}

TEST(VirtaulSsdProcessTestSuite, Write) {
    VirtaulSsdProcess virProc;
    const int addr{ 7 };
    const string data{ "0x99998888" };

    EXPECT_EQ(virProc.sendWriteIpc(addr, data), Result_e::SUCCESS);
}

TEST(VirtaulSsdProcessTestSuite, Read) {
    VirtaulSsdProcess virProc;
    const int addr{ 7 };

    EXPECT_EQ(virProc.sendReadIpc(addr), Result_e::SUCCESS);
}