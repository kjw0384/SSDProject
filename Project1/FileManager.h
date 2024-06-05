#pragma once
#include <vector>
#include <string>

using namespace std;

const string DATA_DIR = "/Result";
const string NAND_FILE = "nand.txt";
const string RESULT_FILE = "result.txt";
const string DEFAULT_DATA = "0x00000000";
const int START_LBA = 0;
const int END_LBA = 99;


class FileManager{
public:
	static FileManager& getInstance()
	{
		static FileManager instance{};
		return instance;
	}
	vector<string> readFromNand();
	void writeToNand(vector<string> dataBuf);
	void writeToResult(string data);
	
private:
	FileManager() {}
	void getNandData(ifstream& file, vector<string>& ret);
	void initNandData(vector<string>& ret);
};