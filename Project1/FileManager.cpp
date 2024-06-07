#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <direct.h>
#include "FileManager.h"

using namespace std;

vector<string> FileManager::readFromNand()
{
	ifstream file(NAND_FILE);
	vector ret(END_LBA, DEFAULT_DATA);

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
	}

	file.close();
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

void FileManager::getBufferData(ifstream& file, map<int, string>& ret)
{
	string line = "";
	while (getline(file, line))
	{
		vector<string> splitLine;
		std::istringstream ss(line);
		string token;

		while (ss >> token) {
			splitLine.push_back(token);
		}
	
		int add = std::stoi(splitLine[0]);
		ret[add] = splitLine[1];
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
	for (string target : Files)
	{
		if (std::filesystem::exists(target) == false)
		{
			ofstream file(target);
			if (file)
			{
				file.close();
			}
			else
			{
				cout << "File Open Error" << endl;
			}
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
		else
		{
			cout << "Result Dir Make Fail" << endl;
		}
	}
	else
	{
		createOutputFiles();
	}
}

bool FileManager::readBufferData(int addr, string& data)
{
	readFromBuffer();

	return dataBuffer.getData(addr, data);
}

bool FileManager::writeBufferData(int addr, string data)
{
	readFromBuffer();
	dataBuffer.setData(addr, data);

	writeToBuffer(dataBuffer.getBufferMemory());

	return (dataBuffer.getBufferSize() >= 10);
}

void FileManager::readFromBuffer()
{
	ifstream file(BUFFER_FILE);
	map<int, string> ret;

	if (file.is_open())
	{
		getBufferData(file, ret);
		file.close();
	}
	dataBuffer.setBufferMemory(ret);
	
	return;
}

void FileManager::writeToBuffer(map<int, string> dataBuf)
{
	ofstream file(BUFFER_FILE);
	if (!file.is_open())
	{
		cout << "Buffer.txt file open fail" << endl;  //todo : exception?
		return;
	}

	for (auto data : dataBuf)
	{
		file << data.first << " " <<data.second << endl;
	}
	file.close();
}

map<int, string> FileManager::getBufferMemory()
{
	return dataBuffer.getBufferMemory();
}

void FileManager::initBufferFile()
{
	ofstream file(BUFFER_FILE);
	if (!file.is_open())
	{
		cout << "Buffer.txt file open fail" << endl;  //todo : exception?
		return;
	}
	file.close();
}