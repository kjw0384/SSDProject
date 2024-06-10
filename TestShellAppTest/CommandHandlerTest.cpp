#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TestShellApp/CommandHandler.cpp"

class CommandHandlerParamFixture : public ::testing::TestWithParam<std::string> {
public:
    CommandHandler& handler = CommandHandler::getCommandHandler();
};

INSTANTIATE_TEST_CASE_P(InvalidCommandStrings,
    CommandHandlerParamFixture,
    ::testing::Values(
        "write 3", "read 3 0xAAAABBBB", "exit 3",
        "helpp", "fullwrite 3", "fullread 0xAAAABBBB"
    ));

TEST_P(CommandHandlerParamFixture, InvalidCommand) {

    const std::string& command = GetParam();
    EXPECT_EQ(Result_e::FAIL,  handler.runParse(command));
}

TEST_P(CommandHandlerParamFixture, exitCommand) {
    const std::string& command = "exit";
    EXPECT_EQ(Result_e::EXIT, handler.runParse(command));
}