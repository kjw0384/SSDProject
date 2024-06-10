#pragma once
#include <string>
#include <vector>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>
#include <vector>
#include <map>

using namespace std;


typedef struct stCommand
{
	string command;
	int startAddr;
	int endAddr;
	string data;
}CommandFormat;

class CommandBuffer {
public:
	static CommandBuffer& getInstance()
	{
		static CommandBuffer instance{};
		return instance;
	}

	int getBufferSize();
	map<int, string> getBufferMemory();
	vector<CommandFormat> getCommandBuffer();
	bool getData(int addr, string& data);
	void setData(int addr, string data);
	void insertCommand(CommandFormat newCmd);
	void pushCommandBuffer(CommandFormat cmd);
	void initialize()
	{
		commandBuffer.clear();
		BufferMemory.clear();
	}
private:
	CommandBuffer() {

	}
	vector<CommandFormat>  commandBuffer;
	map<int, string>   BufferMemory;
	void memrgeCommandBuffer(CommandFormat& newCmd, vector< CommandFormat>& ersBuf);
};