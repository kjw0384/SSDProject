#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TestShellApp/FileIO.h"

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
}
