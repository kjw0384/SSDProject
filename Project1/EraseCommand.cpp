#include "EraseCommand.h"
#include "NANDDevice.h"

void EraseCommand::execute()
{
    device->erase(address, size);
}

ShellStringParserError EraseCommand::parse(vector<string> inputCmdVec)
{
    ShellStringParser parser;
    if (inputCmdVec.size() != 3)
        return ShellStringParserError::CMD_ARGC_ERROR;

    if (parser.isNotLBA(inputCmdVec[1]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    if (parser.isNotSize(inputCmdVec[2]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    if (parser.isNotInRangeSize(inputCmdVec[1], inputCmdVec[2]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    address = stoi(inputCmdVec[1]);
    size = stoi(inputCmdVec[2]);

    return ShellStringParserError::NO_ERROR;
}
