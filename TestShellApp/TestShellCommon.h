#pragma once

enum class Result_e
{
    SUCCESS,
    FAIL,
    EXIT,
};

enum class CommandType_e
{
    EXIT,
    HELP,
    READ,
    WRITE,
    FULLREAD,
    FULLWRITE,
    ERASE,
    ERASE_RANGE,
    FLUSH,
};
