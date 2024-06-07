#pragma once
#include <vector>
#include <string>
#include <map>
#include "DataBuffer.h"

using namespace std;

const string DATA_DIR = "./Result";
const string NAND_FILE = DATA_DIR + "/nand.txt";
const string RESULT_FILE = DATA_DIR + "/result.txt";
const string BUFFER_FILE = DATA_DIR + "/buffer.txt";
const string DEFAULT_DATA = "0x00000000";
const int START_LBA = 0;
const int END_LBA = 100;

class FileManager{
public:
	static FileManager& getInstance()
	{
		static FileManager instance{};
		return instance;
	}
	void setFilePath();
	vector<string> readFromNand();
	void writeToNand(vector<string> dataBuf);
	void writeToResult(string data);

	bool readBufferData(int addr, string& data);
	bool writeBufferData(int addr, string data);
	map<int, string> getBufferMemory();
	void initBufferFile();

private:
	FileManager() : dataBuffer(DataBuffer::getInstance()) {};

	vector<string> Files = { NAND_FILE , RESULT_FILE, BUFFER_FILE };
	DataBuffer& dataBuffer;

	void readFromBuffer();
	void writeToBuffer(map<int, string>);
	void getNandData(ifstream& file, vector<string>& ret);
	void getBufferData(ifstream& file, map<int, string>& ret);
	void createOutputFiles();
};