#include "Nut.h"

Nut::Nut(std::string manufacturerName, std::string productName, int size) :
	Gear(manufacturerName, productName),
	m_size(size)
{
}

std::string Nut::getDescriptionImpl()
{
	std::string description = ":: size : " + std::to_string(m_size);
	return description;
}
