#pragma once
// Can`t have instances
class Event
{
protected:
	unsigned int id;
public:
	virtual ~Event() = 0;
};