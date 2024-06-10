#include "ResultFileReader.h"
#include "Logger.h"


string ResultFileReader::GetReadResult() {
	ifstream resultFileStream(RESULT_FILE);

	if (resultFileStream.is_open() != true) {
		cout << "result.txt file open fail" << endl;  //todo : exception?
		LOG_PRINT("Read Result Fail");
		return "";
	}

	LOG_PRINT("Read Result");
	string Result = getResultData(resultFileStream);
	resultFileStream.close();

	return Result;
}

string ResultFileReader::getResultData(ifstream& rInputStream) {
	string data{};
	rInputStream >> data;
	return data;
}