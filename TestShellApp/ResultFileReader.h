#pragma once

#include "ReadIOInterface.h"
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

const string DATA_DIR = "./Result";
const string RESULT_FILE = DATA_DIR + "/result.txt";

class ResultFileReader : public ReadIOInterface {
public:
	virtual string GetReadResult();

private:
	string getResultData(ifstream& rInputStream);
};
