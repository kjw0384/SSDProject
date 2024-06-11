#include "../TestShellApp/Logger.cpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <regex>
using namespace testing;

int getRegexMatchingFileCount(string fileFormat)
{
    int nResult = 0;

    if (!filesystem::exists(LOG_DIR))
        return 0;

    for (const auto &entry : filesystem::directory_iterator(LOG_DIR))
    {
        if (!entry.is_regular_file())
            continue;

        string fileName = entry.path().filename().string();
        if (regex_match(fileName, regex(fileFormat)) == true)
            nResult++;
    }
    return nResult;
}

void write10K(string str, const char *function)
{
    for (int i = 0; i < 150; i++)
        Logger::writeLog("abcd", function);
}

TEST(LoggerTest, writeLog)
{
    if (filesystem::exists(LOG_DIR))
        filesystem::remove_all(LOG_DIR);
    Logger::writeLog("abcd", __FUNCTION__);

    ifstream file(LOG_FULL_PATH_NAME);
    string data;
    getline(file, data);

    regex txt_regex("\\[[0-9]{2}\\.[0-9]{2}\\.[0-9]{2} [0-9]{2}h:[0-9]{2}m\\] .{50} : abcd$");
    EXPECT_EQ(regex_match(data, txt_regex), true);
}

TEST(LoggerTest, checkBackup)
{
    if (filesystem::exists(LOG_DIR))
        filesystem::remove_all(LOG_DIR);

    write10K("abcd", __FUNCTION__);

    LOG_PRINT("efgh");

    write10K("qwer", __FUNCTION__);

    LOG_PRINT("fdsa");
    EXPECT_EQ(getRegexMatchingFileCount("^until_[0-9]{6}_[0-9]{2}h_[0-9]{2}m_[0-9]{2}s.log$"), 1);
    EXPECT_EQ(getRegexMatchingFileCount("^until_[0-9]{6}_[0-9]{2}h_[0-9]{2}m_[0-9]{2}s.zip$"), 1);
    EXPECT_EQ(getRegexMatchingFileCount("^latest.log$"), 1);
}
