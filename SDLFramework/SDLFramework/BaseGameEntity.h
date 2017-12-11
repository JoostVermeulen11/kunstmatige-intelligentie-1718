#pragma once
class BaseGameEntity
{
private:
	//every entity has a unique identifying number
	int _ID;

	//this is the next valid ID. each time a basegameEntity is instantiated this value is updated
	static int m_iNextValidID;

	//this is called within the constructor to make sure the ID is set correctly. It verifies that the value passed to the method is greater or equal
	//to the next valid ID, before setting the ID and incrementing the next valid ID
	void SetID(int val);
public:
	BaseGameEntity(int id) {
		SetID(id);
	};

	virtual ~BaseGameEntity();
	
	int ID() const { return _ID; }
};

