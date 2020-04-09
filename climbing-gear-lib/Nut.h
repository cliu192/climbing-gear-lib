#pragma once
#include "Gear.h"
class Nut :
	public Gear
{
public:
	Nut(std::string manufacturerName, std::string productName, int size);
	virtual ~Nut() = default;
private:
	int m_size;
	virtual std::string getDescriptionImpl() override;
};

