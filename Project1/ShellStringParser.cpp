#include "ShellStringParser.h"

bool ShellStringParser::isNotLBA(string strLBA)
{
    regex txt_regex("^[0-9]+$");
    if (regex_match(strLBA, txt_regex) == false)
        return true;

    int nLBA = atoi(strLBA.c_str());
    if (nLBA < 0 || nLBA > 99)
        return true;

    return false;
}

bool ShellStringParser::isNotSize(string strSize)
{
    regex txt_regex("^[0-9]{1,2}$");
    if (regex_match(strSize, txt_regex) == false)
        return true;

    int nSize = atoi(strSize.c_str());
    if (nSize < 0 || nSize > 10)
        return true;

    return false;
}

bool ShellStringParser::isNotInRangeSize(string strLBA, string strSize)
{
    int nLBA = atoi(strLBA.c_str());
    int nSize = atoi(strSize.c_str());

    if (nLBA + nSize <= 100)
        return false;
    return true;
}

bool ShellStringParser::isNotValue(string strValue)
{
    regex txt_regex("^0[xX][0-9A-Fa-f]{8}$");
    if (regex_match(strValue, txt_regex) == false)
        return true;

    return false;
}
