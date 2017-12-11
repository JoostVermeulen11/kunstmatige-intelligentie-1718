#pragma once
#include "Cow.h"

class Cow;

class IState
{
public:
	virtual ~IState() {}
	//this will execute when the state is entered
	virtual void Enter(Cow*) = 0;
	//this is called by the miner’s update function each update step
	virtual void Execute(Cow*) = 0;
	//this will execute when the state is exited
	virtual void Exit(Cow*) = 0;
};