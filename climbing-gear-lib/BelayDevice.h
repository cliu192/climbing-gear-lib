#pragma once
#include "Gear.h"
class BelayDevice :
	public Gear
{
public:
	BelayDevice(std::string manufacturerName, std::string productName, bool isAutolocking);
	virtual ~BelayDevice() = default;
private:
	bool m_isAutolocking;
	virtual std::string getDescriptionImpl() override;
};

