#pragma once
#include <string>
#include <vector>

#include "../TestShellApp/IScenario.h"

using namespace std;



//class test2app : public IScenario {
//public:
//	void run() override {
//		cout << "runScenario()\n";
//	}
//	test2app();
//	void run() override;
//private:
//};
////test2app::test2app() {
////	vector<string> scenarios{
////		"read 3 0x33333333",
////		"write 5 0x55555555",
////		"read 5"
////	};
////
////	for (const auto& scenario : scenarios) {
////		Command cmd = parseCommand(scenario);
////		m_TestScriptCommandVector.push_back(cmd);
////	}
////}
////void test2app::run() {
////	for (const auto& command : m_TestScriptCommandVector) {
////		cout << "Type: " << command.type << ", LBA Index: " << command.LBAIndexNum << ", Value: " << command.value << endl;
////	}
////}

#define TEST_SCRIPT_DESC_STRAT(NAME)\
class TestScript##NAME : public  IScenario\
{\
public :\
	TestScript##NAME (){\
		vector<string> scenarios{

#define TEST_SCRIPT_DESC_COMMAND(CMD_STRING)\
		CMD_STRING , 
	
#define TEST_SCRIPT_DESC_RUN(RUN_FUNC_IMPLE)\
		};\
		for (const auto& scenario : scenarios) {\
			Command cmd = parseCommand(scenario);\
			m_TestScriptCommandVector.push_back(cmd);\
		}\
	}\
	virtual void run()##RUN_FUNC_IMPLE##;

#define TEST_SCRIPT_DESC_END()\
};
#include "TestScriptDescriptor.h"