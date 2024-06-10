#pragma once

#include "VirtualSsdProcessInterface.h"

class VirtualSsdProcessMock : public VirtualSsdProcessInterface {
public:
	MOCK_METHOD(Result_e, sendReadIpc, (const int address), (override));
	MOCK_METHOD(Result_e, sendWriteIpc, (const int address, const string data), (override));
	MOCK_METHOD(Result_e, sendEraseIpc, (const int address, const int size), (override));
	MOCK_METHOD(Result_e, sendFlushIpc, (), (override));
private:
};
