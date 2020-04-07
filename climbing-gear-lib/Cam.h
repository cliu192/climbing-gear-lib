#pragma once
#include "Gear.h"
class Cam :
	public Gear
{
public:
	Cam(std::string manufacturerName, std::string productName, double size);
	virtual ~Cam() = default;
private:
	double m_size;
	virtual std::string getDescriptionImpl();
};

