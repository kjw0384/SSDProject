#pragma once

#include "ReadIOInterface.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string RESULT_FILE_DATA_DIR = "./Result";
const string RESULT_FILE_PATH = RESULT_FILE_DATA_DIR + "/result.txt";

class ResultFileReader : public ReadIOInterface
{
  public:
    virtual string GetReadResult();

  private:
    string getResultData(ifstream &rInputStream);
};
