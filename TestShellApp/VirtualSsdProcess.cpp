#include "VirtualSsdProcess.h"
#include <sstream>
#include <iostream>


using std::stringstream;

Result_e VirtaulSsdProcess::sendReadIpc(int address) {
	stringstream strstream;
	strstream << DATA_DIR << " R " << address;
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendWriteIpc(const int address, const string data) {
	stringstream strstream;
	strstream << DATA_DIR << " W " << address;
	strstream << " " << data;
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendEraseIpc(const int address, const int size) {
	stringstream strstream;
	strstream << DATA_DIR << " E " << address;
	strstream << " " << size;
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendFlushIpc() {
	stringstream strstream;
	strstream << DATA_DIR << " F ";
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}