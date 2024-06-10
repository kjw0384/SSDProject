#pragma once

#include "TestCommand.h"
#include "TestScriptParser.h"
#include "TestScriptValidChecker.h"
#include "../TestScenario/TestScenario.h"

class CommandHandler {
public:
	static CommandHandler& getCommandHandler() {
		static CommandHandler commandHandler;
		return commandHandler;
	}
	IScenario* scenario;
	Result_e runCommand(const string& testScript);
	Command getCommand();
	void handleHelp();

	void handleScenario(const string& testScenario, TestScenario& scenarioLib);

private:
	CommandHandler() {}
	CommandHandler& operator = (const CommandHandler& other) = delete;
	CommandHandler(const CommandHandler& other) = delete;

	Command cmd;
	TestScriptValidChecker checker;
	TestScriptParser parser;
};