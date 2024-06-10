
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/CommandBuffer.cpp"
#include "../Project1/ReadCommand.cpp"
#include "../Project1/WriteCommand.cpp"
#include "../Project1/EraseCommand.cpp"
#include "../Project1/FileManager.cpp"
#include "../Project1/NANDDevice.cpp"
#include "../Project1/CommandInvoker.h"

using namespace std;
using namespace testing;

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
	
	void initData()
	{
		fileManager.setFilePath();
	}
};
class CommandFixture : public testing::Test {
public:
	NANDDevice device;
	CommandInvoker invoker;
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


TEST_F(FileManagerFixture, WriteNandAndResult) {
	initData();

	int addr = 1;
	vector<string> ret =  fileManager.readFromNand();
	ret[addr] = "0x22222222";
	fileManager.writeToNand(ret);

	vector<string> ret2 = fileManager.readFromNand();
	fileManager.writeToResult(ret2[addr]);

	EXPECT_EQ(ret2, ret);
}

TEST_F(FileManagerFixture, WriteBufferData) {
	initData();

	int addr = 4;
	string data = "0x44422222";
	
	//vector<string> nandRet = fileManager.readFromNand();
	string ret = "";

	fileManager.writeBufferData(addr, data);
	bool result = fileManager.readBufferData(addr, ret);

	EXPECT_EQ(data, ret);
}

TEST_F(CommandFixture, BufferTest1) {
	int adress = 10;
	string data = "";

	for (int i = 0; i < 6; i++)
	{
		invoker.setCommand(new WriteCommand(&device, adress, "0x00000001"));
		invoker.executeCommand();
	}

	invoker.setCommand(new WriteCommand(&device, adress, "0x00000002"));
	invoker.executeCommand();

	invoker.setCommand(new ReadCommand(&device, adress));
	invoker.executeCommand();
}

TEST_F(CommandFixture, FlushTest) {
	int adress = 10;
	string data = "";

	for (int i = 0; i < 9; i++)
	{
		string data = "0x0000000A";
		invoker.setCommand(new WriteCommand(&device, i, data));
		invoker.executeCommand();
	}

	invoker.setCommand(new WriteCommand(&device, adress, "0x00000002"));
	invoker.executeCommand();

	invoker.setCommand(new ReadCommand(&device, adress));
	invoker.executeCommand();
}

TEST_F(CommandFixture, eraseMergeTest1) {
	int adress = 2;
	string data = "";

	FileManager& fileManager = FileManager::getInstance();
	fileManager.initialize();

	invoker.setCommand(new EraseCommand(&device, adress, 5));
	invoker.executeCommand();

	fileManager.initialize();
	invoker.setCommand(new EraseCommand(&device, 7, 3));
	invoker.executeCommand();
}


TEST_F(CommandFixture, eraseMergeTest2) {
	int adress = 2;
	string data = "";

	FileManager& fileManager = FileManager::getInstance();
	fileManager.initialize();

	for (int i = 4; i < 8; i++)
	{
		fileManager.initialize();
		string data = "0x0000000B";
		invoker.setCommand(new WriteCommand(&device, i, data));
		invoker.executeCommand();
	}

	fileManager.initialize();
	invoker.setCommand(new EraseCommand(&device, adress, 5));
	invoker.executeCommand();

	fileManager.initialize();
	invoker.setCommand(new EraseCommand(&device, 7, 7));
	invoker.executeCommand();
}


TEST_F(CommandFixture, eraseMergeTest3) {
	int adress = 0;
	string data = "";

	FileManager& fileManager = FileManager::getInstance();
	fileManager.initialize();


	fileManager.initialize();
	invoker.setCommand(new EraseCommand(&device, adress, 5));
	invoker.executeCommand();

	fileManager.initialize();
	invoker.setCommand(new EraseCommand(&device, 5, 5));
	invoker.executeCommand();
}

