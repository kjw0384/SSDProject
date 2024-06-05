#pragma once
#include <string>

using namespace std;

#define interface struct

interface ReadIOInterface {
public:
    virtual string GetReadResult() = 0;

};

class FileReadIO : public ReadIOInterface {
public:
    virtual string GetReadResult() {

    }
};
