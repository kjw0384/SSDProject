#include "CommandBuffer.h"

map<int, string> CommandBuffer::getBufferMemory()
{
    return BufferMemory;
}

vector<CommandFormat> CommandBuffer::getCommandBuffer()
{
    return commandBuffer;
}

int CommandBuffer::getBufferSize()
{
    return commandBuffer.size();
}

bool CommandBuffer::getData(int addr, string &data)
{
    if (BufferMemory.find(addr) == BufferMemory.end())
        return false;

    data = BufferMemory[addr];
    return true;
}

void CommandBuffer::setData(int addr, string data)
{
    BufferMemory[addr] = data;
}

void CommandBuffer::insertCommand(CommandFormat newCmd)
{
    vector<CommandFormat> tempPGM;
    vector<CommandFormat> tempERS;

    // check overlap
    for (auto cmd : commandBuffer)
    {
        if (!((newCmd.startAddr <= cmd.startAddr) && (cmd.endAddr <= newCmd.endAddr)))
        {
            if (cmd.command == "PGM")
                tempPGM.push_back(cmd);
            else
                tempERS.push_back(cmd);
        }
    }

    // update BufferMemory Data
    for (int addr = newCmd.startAddr; addr < newCmd.endAddr; addr++)
    {
        BufferMemory[addr] = newCmd.data;
    }

    // commandBuffer update
    if (newCmd.command == "ERS")
        memrgeCommandBuffer(newCmd, tempERS);
    tempERS.push_back(newCmd);
    tempERS.insert(tempERS.end(), tempPGM.begin(), tempPGM.end());
    commandBuffer = tempERS;
}

void CommandBuffer::memrgeCommandBuffer(CommandFormat &newCmd, vector<CommandFormat> &ersBuf)
{
    vector<CommandFormat> temp;
    for (auto cmd : ersBuf)
    {
        // out of range
        if ((cmd.endAddr < newCmd.startAddr) || (cmd.startAddr > newCmd.endAddr))
        {
            temp.push_back(cmd);
            continue;
        }

        // range revisit
        int start = min(newCmd.startAddr, cmd.startAddr);
        int end = max(newCmd.endAddr, cmd.endAddr);

        if (end - start > 10)
        {
            temp.push_back(cmd);

            // check overlap
            if (cmd.endAddr > newCmd.endAddr)
                newCmd.endAddr = cmd.startAddr;
            if (cmd.startAddr < newCmd.startAddr)
                newCmd.startAddr = cmd.endAddr;
            continue;
        }

        newCmd.startAddr = start;
        newCmd.endAddr = end;
    }

    ersBuf = temp;
}

void CommandBuffer::pushCommandBuffer(CommandFormat cmd)
{
    commandBuffer.push_back(cmd);
}
