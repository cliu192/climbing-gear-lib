#include "Quickdraw.h"

Quickdraw::Quickdraw(std::string manufacturerName, std::string productName, QuickdrawType quickdrawType) :
	Gear(manufacturerName, productName),
	m_quickdrawType(quickdrawType)
{
}

std::string Quickdraw::getDescriptionImpl()
{
	std::string description = ":: type : ";
	switch (m_quickdrawType)
	{
	case QuickdrawType::sport:
		description += "sport";
		break;
	case QuickdrawType::alpine:
		description += "alpine";
		break;
	}
	return description;
}
