#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../TestShellApp/TestScriptValidChecker.cpp"

class CommandValidationVectorStringTest : public ::testing::TestWithParam<std::vector<std::string>>
{
};

INSTANTIATE_TEST_SUITE_P(CommandVectorStrings, CommandValidationVectorStringTest,
                         ::testing::Values(vector<string>{"write", "3", "0xAAAABBBB"}, vector<string>{"read", "3"},
                                           vector<string>{"exit"}, vector<string>{"help"},
                                           vector<string>{"fullwrite", "0x11112222"}, vector<string>{"fullread"}));

class CommandInvalidationVectorStringTest : public ::testing::TestWithParam<std::vector<std::string>>
{
};

INSTANTIATE_TEST_SUITE_P(InvalidCommandVectorStrings, CommandInvalidationVectorStringTest,
                         ::testing::Values(vector<string>{"write", "3"}, vector<string>{"read", "3", "0xAAAABBBB"},
                                           vector<string>{"exit", "3"}, vector<string>{"helpp"},
                                           vector<string>{"helpp", "3"}, vector<string>{"fullread", "0xAAAABBBB"}));

string vectorStringToString(const vector<string> &testScriptTokens)
{

    std::ostringstream oss{};
    for (size_t i = 0; i < testScriptTokens.size(); ++i)
    {
        if (i != 0)
        {
            oss << " ";
        }
        oss << testScriptTokens[i];
    }
    return oss.str();
}

TEST_P(CommandValidationVectorStringTest, IsValidCommand)
{

    TestScriptValidChecker checker;

    const vector<string> &command = GetParam();
    string commandString = vectorStringToString(command);
    EXPECT_TRUE(checker.isValidCommand(commandString, command));
}

TEST_P(CommandInvalidationVectorStringTest, IsNotValidCommand)
{

    TestScriptValidChecker checker;

    const vector<string> &command = GetParam();
    string commandString = vectorStringToString(command);
    EXPECT_FALSE(checker.isValidCommand(commandString, command));
}
