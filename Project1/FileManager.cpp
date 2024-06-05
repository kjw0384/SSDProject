#include <string>
#include <vector>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "FileManager.h"

using namespace std;

vector<string> FileManager::readFromNand()
{
	ifstream file(NAND_FILE);
	vector<string> ret;

	if (!file.is_open())  //nand.txt 없는 경우
	{
		initNandData(ret);
		return ret;
	}

	getNandData(file, ret);
	file.close();

	return ret;
}

void FileManager::writeToNand(vector<string> dataBuf)
{
	//ofstream file(NAND_FILE);

}

void FileManager::initNandData(vector<string>& ret)
{
	for (int addr = START_LBA; addr < END_LBA; addr++)
	{
		ret[addr] = DEFAULT_DATA;
	}
}

void FileManager::getNandData(ifstream& file, vector<string>& ret)
{

}

void FileManager::writeToResult(string data)
{
	//ofstream file(RESULT_FILE);

}