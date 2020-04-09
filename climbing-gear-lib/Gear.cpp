#include "Gear.h"

Gear::Gear(std::string manufacturerName, std::string productName, std::string additionalDescription) :
	m_manufacturerName(manufacturerName),
	m_productName(productName),
	m_additionalDescription(additionalDescription)
{
}

std::string Gear::getDescription()
{
	std::string description = 
		m_manufacturerName + " " + 
		m_productName + " " +
		m_additionalDescription + " " +
		getDescriptionImpl();
	return description;
}

std::string Gear::getDescriptionImpl()
{
	return std::string(); // this will return an empty string unless it's overridden
}
