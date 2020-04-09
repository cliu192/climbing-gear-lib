#include "Shoes.h"

Shoes::Shoes(std::string manufacturerName, std::string productName, double size) :
	Gear(manufacturerName, productName),
	m_size(size)
{
}

std::string Shoes::getDescriptionImpl()
{
	std::string description = ":: size : " + std::to_string(m_size);
	return description;
}
