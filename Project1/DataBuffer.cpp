#include "./DataBuffer.h"

void DataBuffer::setBufferMemory(map<int, string> mapBuf)
{
	BufferMemory = mapBuf;
}

map<int, string> DataBuffer::getBufferMemory()
{
	return BufferMemory;
}

int DataBuffer::getBufferSize()
{
	return BufferMemory.size();
}

bool DataBuffer::getData(int addr, string& data)
{
	if (BufferMemory.find(addr) == BufferMemory.end()) return false;

	data = BufferMemory[addr];
	return true;
}

void DataBuffer::setData(int addr, string data)
{
	BufferMemory[addr] = data;
}
