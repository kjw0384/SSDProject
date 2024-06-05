#include "VirtualSsdProcess.h"
#include <sstream>
#include <iostream>


using std::stringstream;

Result_e VirtaulSsdProcess::sendReadIpc(int address) {
	stringstream strstream;
	strstream << "fake_ssd R " << address;
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}

Result_e VirtaulSsdProcess::sendWriteIpc(const int address, const string data) {
	stringstream strstream;
	strstream << "fake_ssd W " << address;
	strstream << " " << data;
	system(strstream.str().c_str());
	return Result_e::SUCCESS;
}
