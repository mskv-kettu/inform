#pragma once
// Can`t have instances
class Event
{
protected:
	unsigned int id = 0;
public:
	virtual ~Event() {};
};