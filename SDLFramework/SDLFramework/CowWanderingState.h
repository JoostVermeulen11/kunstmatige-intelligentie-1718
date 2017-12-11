#pragma once
#include "IState.h"
#include "Cow.h"
#include <iostream>

class CowWanderingState : public IState
{
private:
	CowWanderingState();
public:	
	~CowWanderingState();
	static CowWanderingState* Instance();
	virtual void Enter(Cow* cow);
	virtual void Execute(Cow* cow);
	virtual void Exit(Cow* cow);
};

