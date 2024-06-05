#pragma once
#include <vector>
#include <string>

using namespace std;

const string DATA_DIR = "./Result";
const string NAND_FILE = "./Result/nand.txt";
const string RESULT_FILE = "./Result/result.txt";
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


private:
	FileManager() {}
	//string NAND_Path;
	//string RESULT_Path;

	void getNandData(ifstream& file, vector<string>& ret);
	void initNandData(vector<string>& ret);
	void createOutputFiles();
};