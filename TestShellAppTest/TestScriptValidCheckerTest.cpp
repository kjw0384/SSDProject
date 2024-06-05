#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/TestScriptValidChecker.cpp"

class CommandValidationTest : public ::testing::TestWithParam<std::string> {};

INSTANTIATE_TEST_CASE_P(CommandStrings,
    CommandValidationTest,
    ::testing::Values(
        "write 3 0xAAAABBBB", "read 3","exit",
        "help","fullwrite", "fullread"
    ));

class InvalidCommandValidationTest : public ::testing::TestWithParam<std::string> {};

INSTANTIATE_TEST_CASE_P(InvalidCommandStrings,
    InvalidCommandValidationTest,
    ::testing::Values(
        "write 3", "read 3 0xAAAABBBB", "read 333", "exit 3",
        "helpp", "fullwrite 3", "fullread 0xAAAABBBB"
    ));

TEST_P(CommandValidationTest, IsValidCommand) {

    TestScriptValidChecker checker;

    const std::string& command = GetParam();
    EXPECT_TRUE(checker.isValidCommand(command));
}

TEST_P(InvalidCommandValidationTest, IsNotValidCommand) {

    TestScriptValidChecker checker;

    const std::string& command = GetParam();
    EXPECT_FALSE(checker.isValidCommand(command));
}