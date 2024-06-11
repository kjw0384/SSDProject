#pragma once
#include "FileManager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NANDDevice
{
  public:
    NANDDevice();
    virtual void read(const int address);
    virtual void write(const int address, const string &data);
    virtual void flush();
    virtual void erase(const int address, const int size);

  private:
    FileManager &fileManager;
    void _flush();
};
