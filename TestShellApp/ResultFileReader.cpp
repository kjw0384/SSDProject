#include "ResultFileReader.h"


string ResultFileReader::GetReadResult() {
	ifstream resultFileStream(RESULT_FILE);

	if (resultFileStream.is_open() != true) {
		cout << "Nand.txt file open fail" << endl;  //todo : exception?
		return "";
	}

	string Result = getResultData(resultFileStream);
	resultFileStream.close();

	return Result;
}

string ResultFileReader::getResultData(ifstream& rInputStream) {
	string data = "";
	while (getline(rInputStream, data));
	cout << "Read result.txt 's data value is" << data << endl;
	return data;
}