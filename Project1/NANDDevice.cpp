#include <map>
#include "NANDDevice.h"

NANDDevice::NANDDevice() : fileManager(FileManager::getInstance()) {
    fileManager.setFilePath();
}

void NANDDevice::read(const int address) {
    string data = "";
    
    if (fileManager.readBufferData(address, data) == false)
    {
        vector<string> getData = fileManager.readFromNand();
        data = getData[address];
    }

    fileManager.writeToResult(data);
}

void NANDDevice::write(const int address, const string& data) {

    if (fileManager.writeBufferData(address, data) == true)
    {
       flush();
    }
}

void NANDDevice::flush() {

    vector<string> setData = fileManager.readFromNand();
    map<int, string>buf =  fileManager.getBufferMemory();

    for (auto target : buf)
    {
        setData[target.first] = target.second;
    }
   
    fileManager.writeToNand(setData);
    fileManager.initBufferFile();

}

void NANDDevice::erase(const int address, const int size) {
    for (int addr = address; addr < address + size; ++addr) {
        write(addr, "0x00000000");
    }

}