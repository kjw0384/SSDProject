#pragma once
#include <iostream>

#define interface struct

using std::cout;

interface IScenario {
public:
	virtual ~IScenario() {}
	virtual void run() = 0;
};

class test1app : public IScenario {
public:
	void run() override {
		cout << "runScenario()\n";
	}
};

class test2app : public IScenario {
public:
	void run() override {
		cout << "runScenario()\n";
	}
};
