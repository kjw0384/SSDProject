#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/ShellStringParser.cpp"
#include "../Project1/DataBuffer.cpp"
#include "../Project1/ReadCommand.cpp"
#include "../Project1/WriteCommand.cpp"
#include "../Project1/FileManager.cpp"

using namespace std;
using namespace testing;

class ShellExecuteFixture : public testing::Test {
public:
	ShellStringParser parser;
	void checkErrorCode(string inputStr, ShellStringParserError errorCode) {
		ShellStringParserError errorResult = parser.validCheck(inputStr);
		EXPECT_EQ(errorResult, errorCode) << "Error Return Fail " << endl;
	}
};

TEST_F(ShellExecuteFixture, NoCommandExecute) {
	checkErrorCode("", ShellStringParserError::CMD_EMPTY);
}

TEST_F(ShellExecuteFixture, CommandNotFound) {
	checkErrorCode("ADF 1 0x59261655", ShellStringParserError::CMD_NOT_FOUND);
}

TEST_F(ShellExecuteFixture, WriteArgumentCountError) {
	checkErrorCode("W 1 0x59261655 E", ShellStringParserError::CMD_ARGC_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsFormatError) {
	checkErrorCode("W qfe5 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 1 0X59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 1 0", ShellStringParserError::CMD_ARGV_ERROR);
}

TEST_F(ShellExecuteFixture, WriteArgumentsLBAError) {
	checkErrorCode("W -1 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
	checkErrorCode("W 999 0x59261655", ShellStringParserError::CMD_ARGV_ERROR);
}


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
		const int START_LBA = 0;
		const int END_LBA = 100;

		for (int addr = START_LBA; addr < END_LBA; addr++)
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
	string exp = "0x22222222";

	vector<string> ret = fileManager.readFromNand();
	ret[0] = exp;
	fileManager.writeToNand(ret);

	vector<string> ret2 = fileManager.readFromNand();
	fileManager.writeToResult(ret2[0]);
	EXPECT_EQ(ret2[0], exp);
}

