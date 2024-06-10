#pragma once
#include <vector>
#include <string>
#include <map>
#include "CommandBuffer.h"

using namespace std;

const string DATA_DIR = "./Result";
const string NAND_FILE = DATA_DIR + "/nand.txt";
const string RESULT_FILE = DATA_DIR + "/result.txt";
const string BUFFER_FILE = DATA_DIR + "/buffer.txt";
const string DEFAULT_DATA = "0x00000000";
const int START_LBA = 0;
const int END_LBA = 100;

class FileManager {
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
	bool eraseBufferData(int addr, int size);
	void readFromBuffer();
	map<int, string> getBufferMemory();
	void initBufferFile();
	void initialize()
	{
		commandBuffer.initialize();
	}
private:
	FileManager() : commandBuffer(CommandBuffer::getInstance()) {};

	vector<string> Files = { NAND_FILE , RESULT_FILE, BUFFER_FILE };
	CommandBuffer& commandBuffer;


	void writeToBuffer();
	void getNandData(ifstream& file, vector<string>& ret);
	void getBufferData(ifstream& file);
	void createOutputFiles();
};