#include "VirtualSsdProcess.h"
#include <sstream>
#include <iostream>


using std::stringstream;

Result_e VirtaulSsdProcess::sendReadIpc(int address) {
	stringstream strstream;
	strstream << DATA_DIR << " R " << address;
	if (system(strstream.str().c_str()))
		throw std::exception("ssd read error!");
	
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendWriteIpc(const int address, const string data) {
	stringstream strstream;
	strstream << DATA_DIR << " W " << address;
	strstream << " " << data;
	if (system(strstream.str().c_str()))
		throw std::exception("ssd write error!");
	
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendEraseIpc(const int address, const int size) {
	stringstream strstream;
	strstream << DATA_DIR << " E " << address;
	strstream << " " << size;
	if (system(strstream.str().c_str()))
		throw std::exception("ssd erase error!");

	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendFlushIpc() {
	stringstream strstream;
	strstream << DATA_DIR << " F ";
	if (system(strstream.str().c_str()))
		throw std::exception("ssd flush error!");

	return Result_e::SUCCESS;
}