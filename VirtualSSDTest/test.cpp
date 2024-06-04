#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ReadCommand.cpp"
#include "../Project1/WriteCommand.cpp"

using namespace testing;

class MockSSDDevice : public SSDDevice {
public:
	MOCK_METHOD(void, read, (const int address), (override));
	MOCK_METHOD(void, write, (const int address, const string& data), (override));
};

class CommandTestFixture : public testing::Test {
public:
	MockSSDDevice mockDevice;
	const int address = 7;
	const string data = "0x12345678";
};

TEST_F(CommandTestFixture, Read) {
	EXPECT_CALL(mockDevice, read)
		.Times(1);

	ReadCommand readCmd(&mockDevice, address);
	readCmd.execute();
}

TEST_F(CommandTestFixture, Write) {
	EXPECT_CALL(mockDevice, write)
		.Times(1);

	WriteCommand writeCmd(&mockDevice, address, data);
	writeCmd.execute();
}