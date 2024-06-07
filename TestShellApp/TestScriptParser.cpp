#include "TestScriptParser.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

vector<string> TestScriptParser::splitTestScript(const string& testScript) {
    vector<string> scriptTokens;
    std::istringstream ss(testScript);
    string token;

    while (ss >> token) {
        scriptTokens.push_back(token);
    }
    return scriptTokens;
}

Command TestScriptParser::parseTestScript(vector<string> scriptTokens) {
    Command cmd;
    if (scriptTokens.size() > 0) {
        cmd.type = scriptTokens[0];
    }
    if (scriptTokens.size() > 1) {
        cmd.LBAIndexNum = std::stoi(scriptTokens[1]);
    }
    if (scriptTokens.size() > 2) {
        cmd.value = scriptTokens[2];
    }
    if (cmd.type == "fullwrite") {
        cmd.value = scriptTokens[1];
    }
    return cmd;
}

CommandType_e TestScriptParser::getCommandType(cmdType_t type) {
    if (type == "exit") {
        return CommandType_e::EXIT;
    } 
    if (type == "help") {
        return CommandType_e::HELP;
    }
    if (type == "read") {
        return CommandType_e::READ;
    }
    if (type == "write") {
        return CommandType_e::WRITE;
    }
    if (type == "fullread") {
        return CommandType_e::FULLREAD;
    }
    if (type == "fullwrite") {
        return CommandType_e::FULLWRITE;
    }
    if (type.find("testscript") == 0) {
        return CommandType_e::TESTSCRIPT;
    }
    return CommandType_e::EXIT;
}

CommandType_e TestScriptParser::executeParse(const string& testScript) {

    vector<string> scriptTokens = splitTestScript(testScript);
    testCmd = parseTestScript(scriptTokens);
    return getCommandType(testCmd.type);
}

Command TestScriptParser::getTestCmd() {
    if (testCmd.type.empty()) {
        throw std::exception();
    }
    return testCmd;
}
