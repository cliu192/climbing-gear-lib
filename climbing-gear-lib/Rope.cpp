#include "Rope.h"

Rope::Rope(std::string manufacturerName, std::string productName, int lengthInMeters) :
	Gear(manufacturerName, productName),
	m_lengthInMeters(lengthInMeters)
{
}

std::string Rope::getDescriptionImpl()
{
	std::string description = ":: length : " + std::to_string(m_lengthInMeters) + " meters";
	return description;
}

