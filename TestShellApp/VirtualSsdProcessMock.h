#pragma once

#include "VirtualSsdProcessInterface.h"

class VirtualSsdProcessMock : public VirtualSsdProcessInterface {
public:
	virtual Result_e sendReadIpc() {

	}

	virtual Result_e sendWriteIpc() {
	}

private:
};
