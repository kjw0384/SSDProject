#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DataBuffer.cpp"

//using namespace testing;

class DataBufferFixture : public testing::Test
{
public:
	DataBuffer& dataBuffer = DataBuffer::getInstance();
};

TEST_F(DataBufferFixture, DataBufferReadEmptyTest) {
	unsigned int data = 0;
	bool ret = dataBuffer.readCacheData(10, &data);
	EXPECT_EQ(ret, false);
}

TEST_F(DataBufferFixture, DataBufferWriteTest) {

	dataBuffer.writeCacheData(10, 0x500);
	unsigned int data = 0;
	bool ret = dataBuffer.readCacheData(10, &data);
	EXPECT_EQ(data, 0x500);
}