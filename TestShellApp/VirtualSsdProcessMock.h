#pragma once

#include "VirtualSsdProcessInterface.h"

class VirtualSsdProcessMock : public VirtualSsdProcessInterface {
public:
	MOCK_METHOD(Result_e, sendReadIpc, (const int address), (override));
	MOCK_METHOD(Result_e, sendWriteIpc, (const int address, const string data), (override));

private:
};
