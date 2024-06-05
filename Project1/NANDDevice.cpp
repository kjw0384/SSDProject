#include "NANDDevice.h"

NANDDevice::NANDDevice() : fileManager(FileManager::getInstance()) {
    fileManager.setFilePath();
}

void NANDDevice::read(const int address) {
    vector<string> getData = fileManager.readFromNand();
    fileManager.writeToResult(getData[address]);
}

void NANDDevice::write(const int address, const string& data) {
    vector<string> setData = fileManager.readFromNand();
    setData[address] = data;
    fileManager.writeToNand(setData);
}