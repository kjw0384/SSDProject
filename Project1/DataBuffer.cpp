#include "./DataBuffer.h"


bool DataBuffer::readCacheData(int addr, unsigned int * data)
{
	if (cacheMemory.find(addr) == cacheMemory.end()) return false;

	*data = cacheMemory.find(addr)->second;
	return true;
}
void DataBuffer::writeCacheData(int addr, unsigned int data)
{
	cacheMemory[addr] = data;
}
