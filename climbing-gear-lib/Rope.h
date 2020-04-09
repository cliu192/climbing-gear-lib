#pragma once
#include "Gear.h"
class Rope :
	public Gear
{
public:
	Rope(std::string manufacturerName, std::string productName, int lengthInMeters, double diameterInMillimeters);
	virtual ~Rope() = default;
private:
	int m_lengthInMeters;
	double m_diameterinMillimeters;
	virtual std::string getDescriptionImpl() override;
};

