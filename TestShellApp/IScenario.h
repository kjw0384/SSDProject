#pragma once
#include <iostream>

#define interface struct

using std::cout;

interface IScenario {
public:
	virtual ~IScenario() {}
	virtual void run() = 0;
};
