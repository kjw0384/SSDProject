#include "NANDDevice.h"
#include <map>

NANDDevice::NANDDevice() : fileManager(FileManager::getInstance())
{
    fileManager.setFilePath();
}

void NANDDevice::read(const int address)
{
    string data = "";

    if (fileManager.readBufferData(address, data) == false)
    {
        vector<string> getData = fileManager.readFromNand();
        data = getData[address];
    }

    fileManager.writeToResult(data);
}

void NANDDevice::write(const int address, const string &data)
{

    if (fileManager.writeBufferData(address, data) == true)
    {
        _flush();
    }
}

void NANDDevice::erase(const int address, const int size)
{

    if (fileManager.eraseBufferData(address, size))
    {
        _flush();
    }
}
void NANDDevice::flush()
{
    fileManager.readFromBuffer();
    _flush();
}

void NANDDevice::_flush()
{

    vector<string> setData = fileManager.readFromNand();
    map<int, string> buf = fileManager.getBufferMemory();

    for (auto target : buf)
    {
        setData[target.first] = target.second;
    }

    fileManager.writeToNand(setData);
    fileManager.initBufferFile();
}
