#pragma once
#include <string>
#include <vector>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>

using namespace std;

class DataBuffer {
public:
	static DataBuffer& getInstance()
	{
		static DataBuffer instance{};
		return instance;
	}

	bool readCacheData(int addr, const int& data);
	void writeCacheData(int addr, unsigned int data);

private:
	DataBuffer() {}
	vector<int> cacheMemory;
};