#pragma once
#include "Gear.h"
class Shoes :
	public Gear
{
public:
	Shoes(std::string manufacturerName, std::string productName, double size);
	virtual ~Shoes() = default;
private:
	double m_size;
	virtual std::string getDescriptionImpl() override;
};

