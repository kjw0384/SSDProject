#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/ShellCommandHandler.cpp"

class ShellCommandHandlerParamFixture : public ::testing::TestWithParam<std::string> {
public:
    ShellCommandHandler& handler = ShellCommandHandler::getCommandHandler();
};

INSTANTIATE_TEST_CASE_P(InvalidCommandStrings,
    ShellCommandHandlerParamFixture,
    ::testing::Values(
        "write 3", "read 3 0xAAAABBBB", "exit 3",
        "helpp", "fullwrite 3", "fullread 0xAAAABBBB"
    ));

TEST_P(ShellCommandHandlerParamFixture, InvalidCommand) {

    const std::string& command = GetParam();
    EXPECT_EQ(Result_e::FAIL,  handler.runParse(command));
}

TEST_P(ShellCommandHandlerParamFixture, exitCommand) {
    const std::string& command = "exit";
    EXPECT_EQ(Result_e::EXIT, handler.runParse(command));
}