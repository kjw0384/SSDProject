#include <string>
#include <vector>
#include <deque>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <direct.h>
#include "FileManager.h"

using namespace std;

vector<string> FileManager::readFromNand()
{
	ifstream file(NAND_FILE);
	vector<string> ret;

	initNandData(ret);

	if (!file.is_open())  return ret;

	getNandData(file, ret);
	file.close();

	return ret;
}

void FileManager::writeToNand(vector<string> dataBuf)
{
	ofstream file(NAND_FILE);
	if (!file.is_open())
	{
		cout << "Nand.txt file open fail" << endl;  //todo : exception?
		return;
	}

	for (string data : dataBuf)
	{
		file << data << endl;
	};

	file.close();
}

void FileManager::initNandData(vector<string>& ret)
{
	for (int addr = START_LBA; addr < END_LBA; addr++)
	{
		ret.push_back(DEFAULT_DATA);
	}
}

void FileManager::getNandData(ifstream& file, vector<string>& ret)
{
	int targetAddr = 0;
	string data = "";
	while (getline(file, data))
	{
		ret[targetAddr++] = data;
	}
}

void FileManager::writeToResult(string data)
{
	ofstream file(RESULT_FILE);
	if (!file.is_open())
	{
		cout << "Nand.txt file open fail" << endl;  //todo : exception?
		return;
	}

	file << data << endl;
	file.close();
}

void FileManager::createOutputFiles()
{
	//std::filesystem::path filePath(NAND_FILE);
	if (std::filesystem::exists(NAND_FILE) == false)
	{
		ofstream file(NAND_FILE);
		if (file)
		{
			file.close();
		}
		else
		{
			cout << "NAND File Open Error" << endl;
		}
	}

	if (std::filesystem::exists(RESULT_FILE) == false)
	{
		ofstream file(RESULT_FILE);
		if (file)
		{
			file.close();
		}
		else
		{
			cout << "RESULT File Open Error" << endl;
		}
	}
}

void FileManager::setFilePath()
{
	if (std::filesystem::exists(DATA_DIR) == false)
	{
		if (_mkdir(DATA_DIR.c_str()) == 0)
		{
			createOutputFiles();
		}
	}
	else
	{
		createOutputFiles();
	}
}
