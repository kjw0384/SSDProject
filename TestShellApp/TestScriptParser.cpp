#include "TestScriptParser.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include "Logger.h"

vector<string> TestScriptParser::splitTestScript(const string& testScript) {
    vector<string> scriptTokens;
    std::istringstream ss(testScript);
    string token;
    LOG_PRINT(testScript);

    while (ss >> token) {
        scriptTokens.push_back(token);
    }
    return scriptTokens;
}

Command TestScriptParser::parseTestScript(vector<string> scriptTokens) {
    Command cmd;

    cmd.type = scriptTokens[0];
    if (scriptTokens.size() > 1) 
        cmd.LBAIndexNum = stoi(scriptTokens[1]);

    if (cmd.type == "write") {
        cmd.value = scriptTokens[2];
    }
    if (cmd.type == "fullwrite") {
        cmd.value = scriptTokens[1];
    }
    if (cmd.type == "erase") {
        cmd.size = stoi(scriptTokens[2]);
    }
    if (cmd.type == "erase_range") {
        cmd.type = "erase";
        cmd.size = stoi(scriptTokens[2]) - stoi(scriptTokens[1]);
    }
    LOG_PRINT(cmd.type);
    return cmd;
}

CommandType_e TestScriptParser::getCommandType(cmdType_t type) {
    LOG_PRINT(type);
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
    if (type == "erase") {
        return CommandType_e::ERASE;
    }
    if (type == "erase_range") {
        return CommandType_e::ERASE_RANGE;
    }
    if (type == "flush") {
        return CommandType_e::FLUSH;
    }
    return CommandType_e::EXIT;
}

CommandType_e TestScriptParser::executeParse(vector<string> scriptTokens) {
    LOG_PRINT("");
    command = parseTestScript(scriptTokens);
    return getCommandType(command.type);
}

Command TestScriptParser::getCommand() {
    if (command.type.empty()) {
        LOG_PRINT("Command Type Error");
        throw std::exception();
    }
    LOG_PRINT("return Command");
    return command;
}
