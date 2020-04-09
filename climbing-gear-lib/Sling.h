#pragma once
#include "Gear.h"
class Sling :
	public Gear
{
public:
	Sling(std::string manufacturerName, std::string productName, int lengthInCentimeters);
	virtual ~Sling() = default;
private:
	int m_lengthInCentimeters;
	virtual std::string getDescriptionImpl() override;
};

