#include <filesystem>
#include <string>


using namespace std;


class ReadIOInterface {
public:
	virtual string GetReadResult() = 0;
};

class FileReadIO : public ReadIOInterface {
public:
	virtual string GetReadResult() {

	}
};
