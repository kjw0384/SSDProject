#pragma once
#include <vector>
#include <string>

#include "Command.h"
#include "NANDDevice.h"

class CommandFactory {
public:
	static CommandFactory& getInstance() {
		static CommandFactory instance{};
		return instance;
	}
	Command* getCommand(NANDDevice* device, vector<string> inputCommandVec);

private:
	CommandFactory() {}
	string toUpper(string inputStr);
};
