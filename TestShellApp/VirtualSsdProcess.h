#pragma once

#include "VirtualSsdProcessInterface.h"
#include <iostream>

using namespace std;

class VirtaulSsdProcess : public VirtualSsdProcessInterface {
public:
	virtual Result_e sendReadIpc() {
		cout << "sendReadIpc is not implemented" << endl;
	}

	virtual Result_e sendWriteIpc() {
		cout << "sendWriteIpc is not implemented" << endl;
	}

private:

};