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

TEST_F(TestScriptParserFixture, parseTestScript) {
    vector<string> scriptTokens = { "write", "3", "0xAAAABBBB" };
    Command cmd = parser->parseTestScript(scriptTokens);

    EXPECT_EQ(cmd.type, "write");
    EXPECT_EQ(cmd.LBAIndexNum, 3);
    EXPECT_EQ(cmd.value, "0xAAAABBBB");
}

TEST_F(TestScriptParserFixture, getTestCmdSuccess) {
    parser = new TestScriptParser();

    vector<string> testScript;
    testScript.push_back("write");
    testScript.push_back("3");
    testScript.push_back("0xAAAAAAAA");

    parser->executeParse(testScript);
    Command cmd = parser->getTestCmd();

    EXPECT_EQ(cmd.type, "write");
    EXPECT_EQ(cmd.LBAIndexNum, 3);
    EXPECT_EQ(cmd.value, "0xAAAAAAAA");
}

TEST_F(TestScriptParserFixture, getTestCmdFailed) {
    EXPECT_THROW(parser->getTestCmd(), std::exception);
}