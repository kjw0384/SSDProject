#pragma once

#include "TestCommand.h"
#include "TestScriptParser.h"
#include "TestScriptValidChecker.h"

class CommandHandler {
public:
	static CommandHandler& getCommandHandler() {
		static CommandHandler commandHandler;
		return commandHandler;
	}

	Result_e runCommand(const string& testScript);
	Command getCommand();
	void handleHelp();

	void handleScenario(const string& testScenario);

private:
	CommandHandler() {}
	CommandHandler& operator = (const CommandHandler& other) = delete;
	CommandHandler(const CommandHandler& other) = delete;

	Command cmd;
	TestScriptValidChecker checker;
	TestScriptParser parser;
};