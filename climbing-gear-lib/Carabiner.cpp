#include "Carabiner.h"

Carabiner::Carabiner(std::string manufacturerName, std::string productName, bool isLocking) :
	Gear(manufacturerName, productName),
	m_isLocking(isLocking)
{
}

std::string Carabiner::getDescriptionImpl()
{
	std::string description = ":: locking : ";
	description += (m_isLocking ? "true" : "false");
	return description;
}
