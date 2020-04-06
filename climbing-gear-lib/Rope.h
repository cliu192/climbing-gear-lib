#pragma once
#include "Gear.h"
class Rope :
	public Gear
{
public:
	Rope(std::string manufacturerName, std::string productName, int lengthInMeters);
	virtual ~Rope() = default;
private:
	int m_lengthInMeters;
	virtual std::string getDescriptionImpl() override;
};

