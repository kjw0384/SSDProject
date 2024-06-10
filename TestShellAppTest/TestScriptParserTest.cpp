#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include "../TestShellApp/TestScriptParser.cpp"

using std::string;
using std::vector;

class TestScriptParserFixture : public testing::Test {
public:
    TestScriptParserFixture() {
        parser = new TestScriptParser();
    }

    const int TYPE_ONLY_SIZE = 1;
    const int TYPE_AND_INDEX_SIZE = 2;
    const int TYPE_INDEX_AND_VALUE_SIZE = 3;

    TestScriptParser* parser;
};

TEST_F(TestScriptParserFixture, splitCommandTypeOnly) {
    vector<string> scriptTokens = parser->splitTestScript("help");
    EXPECT_EQ(TYPE_ONLY_SIZE, scriptTokens.size());
    EXPECT_EQ("help", scriptTokens[0]);
}

TEST_F(TestScriptParserFixture, splitCommandTypeAndIndex) {
    vector<string> scriptTokens = parser->splitTestScript("read 3");
    EXPECT_EQ(TYPE_AND_INDEX_SIZE, scriptTokens.size());
    EXPECT_EQ("read", scriptTokens[0]);
    EXPECT_EQ("3", scriptTokens[1]);
}

TEST_F(TestScriptParserFixture, splitCommandTypeIndexAndValue) {
    vector<string> scriptTokens = parser->splitTestScript("write 3 0xAAAABBBB");
    EXPECT_EQ(TYPE_INDEX_AND_VALUE_SIZE, scriptTokens.size());
    EXPECT_EQ("write", scriptTokens[0]);
    EXPECT_EQ("3", scriptTokens[1]);
    EXPECT_EQ("0xAAAABBBB", scriptTokens[2]);
}

TEST_F(TestScriptParserFixture, parseTestScript) {
    vector<string> scriptTokens = { "write", "3", "0xAAAABBBB" };
    ShellCommand cmd = parser->parseTestScript(scriptTokens);

    EXPECT_EQ(cmd.type, "write");
    EXPECT_EQ(cmd.LBAIndexNum, 3);
    EXPECT_EQ(cmd.value, "0xAAAABBBB");
}

TEST_F(TestScriptParserFixture, getTestCmdSuccess) {
    parser = new TestScriptParser();

    vector<string> scriptTokens = { "write", "3", "0xAAAABBBB" };

    parser->executeParse(scriptTokens);
    ShellCommand cmd = parser->getCommand();

    EXPECT_EQ(cmd.type, "write");
    EXPECT_EQ(cmd.LBAIndexNum, 3);
    EXPECT_EQ(cmd.value, "0xAAAABBBB");
}

TEST_F(TestScriptParserFixture, getTestCmdFailed) {
    EXPECT_THROW(parser->getCommand(), std::exception);
}