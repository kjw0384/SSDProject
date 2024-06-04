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

	bool readCacheData(int addr, unsigned int * data);
	void writeCacheData(int addr, unsigned int data);

private:
	DataBuffer() {}
	map<int, unsigned int> cacheMemory;
};