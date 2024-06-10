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
		throw std::runtime_error("Nand.txt file open fail");
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

void FileManager::getBufferData(ifstream& file)
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
	
		CommandFormat cmd;
		cmd.command = splitLine[0];
		cmd.startAddr = std::stoi(splitLine[1]);
		cmd.endAddr = std::stoi(splitLine[2]);
		cmd.data = splitLine[3];

		commandBuffer.pushCommandBuffer(cmd);
		
		for (int add = cmd.startAddr; add < cmd.endAddr; add++)
		{
			commandBuffer.setData(add, cmd.data);
		}
	}
}

void FileManager::writeToResult(string data)
{
	ofstream file(RESULT_FILE);
	if (!file.is_open())
	{
		throw std::runtime_error("Nand.txt file open fail");
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
				throw std::runtime_error("File Open Error");
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
			throw std::runtime_error("Nand.txt file open fail");
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

	return commandBuffer.getData(addr, data);
}

bool FileManager::writeBufferData(int addr, string data)
{
	readFromBuffer();

	CommandFormat Newcmd = { "PGM", addr, addr + 1, data };
	commandBuffer.insertCommand(Newcmd);
	writeToBuffer();

	return (commandBuffer.getBufferSize() >= 10);
}

bool FileManager::eraseBufferData(int addr, int size)
{
	readFromBuffer();
	CommandFormat Newcmd = { "ERS", addr, addr + size, DEFAULT_DATA };
	commandBuffer.insertCommand(Newcmd);
	writeToBuffer();

	return (commandBuffer.getBufferSize() >= 10);
}

void FileManager::readFromBuffer()
{
	ifstream file(BUFFER_FILE);

	if (file.is_open())
	{
		getBufferData(file);
		file.close();
	}
	return;
}

void FileManager::writeToBuffer()
{
	ofstream file(BUFFER_FILE);
	if (!file.is_open())
	{
		throw std::runtime_error("Buffer.txt file open fail");
	}

	vector<CommandFormat> cmdBuf = commandBuffer.getCommandBuffer();
	for (auto cmd : cmdBuf)
	{
		file << cmd.command << " " << cmd.startAddr << " " << cmd.endAddr << " " << cmd.data <<endl;
	}
	file.close();
}

map<int, string> FileManager::getBufferMemory()
{
	return commandBuffer.getBufferMemory();
}

void FileManager::initBufferFile()
{
	ofstream file(BUFFER_FILE);
	if (!file.is_open())
	{
		throw std::runtime_error("Buffer.txt file open fail");
	}
	file.close();
}