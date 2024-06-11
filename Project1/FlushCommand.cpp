#include "FlushCommand.h"
#include "NANDDevice.h"

void FlushCommand::execute()
{
    device->flush();
}

ShellStringParserError FlushCommand::parse(vector<string> inputCmdVec)
{
    if (inputCmdVec.size() != 1)
        return ShellStringParserError::CMD_ARGC_ERROR;

    return ShellStringParserError::NO_ERROR;
}
