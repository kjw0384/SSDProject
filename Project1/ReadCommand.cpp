#include "ReadCommand.h"
#include "NANDDevice.h"

void ReadCommand::execute()
{
    device->read(address);
}

ShellStringParserError ReadCommand::parse(vector<string> inputCmdVec)
{
    ShellStringParser parser;
    if (inputCmdVec.size() != 2)
        return ShellStringParserError::CMD_ARGC_ERROR;

    if (parser.isNotLBA(inputCmdVec[1]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    address = stoi(inputCmdVec[1]);

    return ShellStringParserError::NO_ERROR;
}
