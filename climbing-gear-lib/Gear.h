#pragma once

#include <string>

class Gear
{
public:
	Gear(std::string manufacturerName, std::string productName, std::string additionalDescription = "");
	virtual ~Gear() = default;
	std::string getDescription();

private:
	std::string m_manufacturerName;
	std::string m_productName;
	std::string m_additionalDescription;
	virtual std::string getDescriptionImpl();
};

