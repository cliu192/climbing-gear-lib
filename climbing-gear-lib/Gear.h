#pragma once

#include <string>

class Gear
{
public:
	Gear(std::string manufacturerName, std::string productName);
	~Gear() = default;
	std::string getDescription();

private:
	std::string m_manufacturerName;
	std::string m_productName;
	virtual std::string getDescriptionImpl() = 0;
};

