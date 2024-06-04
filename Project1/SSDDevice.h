#pragma once

#include <iostream>
#include <string>
using namespace std;

class SSDDevice {
public:
    void read(const int address) {
        cout << "Reading from LBA: " << address << endl;
        // 실제 읽기 작업 구현
    }

    void write(const int address, const string& data) {
        cout << "Writing data to LBA: " << address << endl;
        // 실제 쓰기 작업 구현
    }
};