#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DataBuffer.cpp"
#include "../Project1/ReadCommand.cpp"
#include "../Project1/WriteCommand.cpp"
#include "../Project1/FileManager.cpp"

using namespace testing;

class DataBufferFixture : public testing::Test
{
public:
	DataBuffer& dataBuffer = DataBuffer::getInstance();
};

class MockNANDDevice : public NANDDevice {
public:
	MOCK_METHOD(void, read, (const int address), (override));
	MOCK_METHOD(void, write, (const int address, const string& data), (override));
};

class CommandTestFixture : public testing::Test {
public:
	MockNANDDevice mockDevice;
	const int address = 7;
	const string data = "0x12345678";
};

class FileManagerFixture : public testing::Test {
public:
	FileManager& fileManager = FileManager::getInstance();
	
	void initData(vector<string>& exp)
	{
		for (int addr = 0; addr < 99; addr++)
		{
			exp.push_back("0x00000000");
		}
		fileManager.setFilePath();
	}
};

TEST_F(DataBufferFixture, DataBufferReadEmptyTest) {
	unsigned int data = 0;
	bool ret = dataBuffer.readCacheData(10, &data);
	EXPECT_EQ(ret, false);
}

TEST_F(DataBufferFixture, DataBufferWriteTest) {

	dataBuffer.writeCacheData(10, 0x500);
	unsigned int data = 0;
	bool ret = dataBuffer.readCacheData(10, &data);
	EXPECT_EQ(data, 0x500);
}

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

TEST_F(FileManagerFixture, WriteNandAndResult) {
	vector<string> exp;
	initData(exp);

	exp[0] = "0xAA55AA55";

	fileManager.writeToNand(exp);
	vector<string> ret = fileManager.readFromNand();
	fileManager.writeToResult(ret[0]);
	EXPECT_EQ(ret, exp);
}
