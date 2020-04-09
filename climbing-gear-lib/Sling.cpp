#include "Sling.h"

Sling::Sling(std::string manufacturerName, std::string productName, int lengthInCentimeters) :
	Gear(manufacturerName, productName),
	m_lengthInCentimeters(lengthInCentimeters)
{
}

std::string Sling::getDescriptionImpl()
{
	std::string description = ":: length : " + std::to_string(m_lengthInCentimeters) + " centimeters";
	return description;
}
