#include "Rope.h"

Rope::Rope(std::string manufacturerName, std::string productName, int lengthInMeters, double diameterinMillimeters) :
	Gear(manufacturerName, productName),
	m_lengthInMeters(lengthInMeters),
	m_diameterinMillimeters(diameterinMillimeters)
{
}

std::string Rope::getDescriptionImpl()
{
	std::string description = ":: length : " + std::to_string(m_lengthInMeters) + " meters";
	description += " :: diameter : " + std::to_string(m_diameterinMillimeters) + " millimeters";
	return description;
}

