#pragma once
#pragma once
#include <string>
#include <vector>

#include "../TestShellApp/IScenario.h"

using namespace std;


#define TEST_SCRIPT_DESC_STRAT(NAME)\
class TestScript##NAME : public  IScenario\
{\
public :
#define TEST_SCRIPT_DESC_COMMAND(CMD)
#define TEST_SCRIPT_DESC_RUN(RUN_FUNC_IMPLE)\
	virtual void run()##RUN_FUNC_IMPLE##;
#define TEST_SCRIPT_DESC_END()\
};
#include "TestScriptDescriptor.h"