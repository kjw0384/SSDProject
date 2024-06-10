#include "VirtualSsdProcess.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "Logger.h"


using std::stringstream;

 string VirtaulSsdProcess::getDataDirectory() {
	std::filesystem::path currentPath = std::filesystem::current_path();

	if (currentPath.string().find("Debug") != string::npos ||
		currentPath.string().find("Release") != string::npos) {
		return "ssd";
	}
	else {
		return "..\\x64\\Debug\\ssd";
	}
}

Result_e VirtaulSsdProcess::sendReadIpc(int address) {
	stringstream strstream;
	strstream << getDataDirectory() << " R " << address;

	if (system(strstream.str().c_str())) {
		cout << "ssd read error!\n";
		LOG_PRINT(strstream.str() + " - ssd read error!\n");
		return Result_e::FAIL;
	}
	LOG_PRINT(strstream.str() + " - Success\n");
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendWriteIpc(const int address, const string data) {
	stringstream strstream;
	strstream << getDataDirectory() << " W " << address;
	strstream << " " << data;

	if (system(strstream.str().c_str())) {
		cout << "ssd write error!\n";
		LOG_PRINT(strstream.str() + " - ssd write error!\n");
		return Result_e::FAIL;
	}
	LOG_PRINT(strstream.str() + " - Success\n");
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendEraseIpc(const int address, const int size) {
	stringstream strstream;
	strstream << getDataDirectory() << " E " << address;
	strstream << " " << size;

	if (system(strstream.str().c_str())) {
		cout << "ssd erase error!\n";
		LOG_PRINT(strstream.str() + " - ssd erase error!\n");
		return Result_e::FAIL;
	}
	LOG_PRINT(strstream.str() + " - Success\n");
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendFlushIpc() {
	stringstream strstream;
	strstream << getDataDirectory() << " F ";

	if (system(strstream.str().c_str())) {
		cout << "ssd flush error!\n";
		LOG_PRINT(strstream.str() + " - ssd flush error!\n");
		return Result_e::FAIL;
	}
	LOG_PRINT(strstream.str() + " - Success\n");
	return Result_e::SUCCESS;
}