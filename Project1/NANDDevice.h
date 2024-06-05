#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "FileManager.h"

using namespace std;

class NANDDevice {
public:
    virtual void read(const int address) {
        FileManager& fileManager = FileManager::getInstance();
        fileManager.setFilePath();

        vector<string> getData = fileManager.readFromNand();
        fileManager.writeToResult(getData[address]);
        cout << "Read from LBA: " << address << ", value: " << getData[address]<<endl;
    }

    virtual void write(const int address, const string& data) {
        FileManager& fileManager = FileManager::getInstance();
        fileManager.setFilePath();

        vector<string> setData = fileManager.readFromNand();
        setData[address] = data;
        fileManager.writeToNand(setData);
        cout << "Write to LBA: " << address << ", value: " << setData[address] << endl;
    }
};