#include "BelayDevice.h"

BelayDevice::BelayDevice(std::string manufacturerName, std::string productName, bool isAutolocking) :
	Gear(manufacturerName, productName),
	m_isAutolocking(isAutolocking)
{
}

std::string BelayDevice::getDescriptionImpl()
{
	std::string description = " :: auto-locking : ";
	description += (m_isAutolocking ? "true" : "false");
	return description;
}
