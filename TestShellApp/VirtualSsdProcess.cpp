#include "VirtualSsdProcess.h"
#include <sstream>
#include <iostream>
#include "Logger.h"


using std::stringstream;

Result_e VirtaulSsdProcess::sendReadIpc(int address) {
	stringstream strstream;
	strstream << DATA_DIR << " R " << address;

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
	strstream << DATA_DIR << " W " << address;
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
	strstream << DATA_DIR << " E " << address;
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
	strstream << DATA_DIR << " F ";

	if (system(strstream.str().c_str())) {
		cout << "ssd flush error!\n";
		LOG_PRINT(strstream.str() + " - ssd flush error!\n");
		return Result_e::FAIL;
	}
	LOG_PRINT(strstream.str() + " - Success\n");
	return Result_e::SUCCESS;
}