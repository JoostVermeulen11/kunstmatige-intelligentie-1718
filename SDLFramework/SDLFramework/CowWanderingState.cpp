#include "CowWanderingState.h"

CowWanderingState::CowWanderingState()
{
}

CowWanderingState::~CowWanderingState()
{
}

CowWanderingState * CowWanderingState::Instance()
{
	static CowWanderingState instance;
	return &instance;
}

void CowWanderingState::Enter(Cow * cow)
{
	// if we want to do something when enters te state
	std::cout << "Cow is entering the CowWanderingState, assuming he has no pill: " << cow->HasPill() << std::endl;
}

void CowWanderingState::Execute(Cow * cow)
{
	//execute wandering state
	std::cout << "Cow is executing the CowWanderingState" << std::endl;
	cow->Wander();
}

void CowWanderingState::Exit(Cow * cow)
{
	//leave wandering state
	std::cout << "Cow is leaving the CowWanderingState, assuming he has a pill: " << cow->HasPill() << std::endl;
}
