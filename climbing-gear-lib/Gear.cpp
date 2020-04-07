#include "Gear.h"

Gear::Gear(std::string manufacturerName, std::string productName) :
	m_manufacturerName(manufacturerName),
	m_productName(productName)
{
}

std::string Gear::getDescription()
{
	std::string description = 
		m_manufacturerName + " " + 
		m_productName + " " +
		getDescriptionImpl();
	return description;
}
