#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/ResultFileReader.cpp"

TEST(ResultFileReaderTestSuite, getReultDataTest) {
	ResultFileReader resultReader; 
	EXPECT_EQ(resultReader.GetReadResult(), "0x12345678");
}