#include "ResultFileReader.h"


string ResultFileReader::GetReadResult() {
	ifstream resultFileStream(RESULT_FILE);

	if (resultFileStream.is_open() != true) {
		cout << "result.txt file open fail" << endl;  //todo : exception?
		return "";
	}

	string Result = getResultData(resultFileStream);
	resultFileStream.close();

	return Result;
}

string ResultFileReader::getResultData(ifstream& rInputStream) {
	string data{};
	rInputStream >> data;
	return data;
}