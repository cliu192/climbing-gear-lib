#pragma once

#include <string>

class Gear
{
public:
	// if populating the additionalDescription in order to create a miscellaneous gear instance, 
	// use the format ":: [attribute1] : [attribute1 value] :: [attribute2] : [attribute2 value]", etc.
	Gear(std::string manufacturerName, std::string productName, std::string additionalDescription = "");
	virtual ~Gear() = default;
	std::string getDescription();

private:
	std::string m_manufacturerName;
	std::string m_productName;
	std::string m_additionalDescription;
	virtual std::string getDescriptionImpl();
};

