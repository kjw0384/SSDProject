#include "WriteCommand.h"
#include "NANDDevice.h"

void WriteCommand::execute()
{
    device->write(address, data);
}

ShellStringParserError WriteCommand::parse(vector<string> inputCmdVec)
{
    ShellStringParser parser;
    if (inputCmdVec.size() != 3)
        return ShellStringParserError::CMD_ARGC_ERROR;

    if (parser.isNotLBA(inputCmdVec[1]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    if (parser.isNotValue(inputCmdVec[2]))
        return ShellStringParserError::CMD_ARGV_ERROR;

    address = stoi(inputCmdVec[1]);
    data = inputCmdVec[2];

    return ShellStringParserError::NO_ERROR;
}
