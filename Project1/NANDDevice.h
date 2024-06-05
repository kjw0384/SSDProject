#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "FileManager.h"

using namespace std;

class NANDDevice {
public:
    virtual void read(const int address);
    virtual void write(const int address, const string& data);
};
