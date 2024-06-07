#pragma once
#include <string>
#include <vector>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>
#include <map>

using namespace std;

class DataBuffer {
public:
	static DataBuffer& getInstance()
	{
		static DataBuffer instance{};
		return instance;
	}

	int getBufferSize();
	void setBufferMemory(map<int, string> mapBuf);
	map<int, string> getBufferMemory();
	bool getData(int addr, string& data);
	void setData(int addr, string data);

private:
	DataBuffer() {}
	map<int, string> BufferMemory;
};