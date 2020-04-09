#pragma once
#include "Gear.h"
class Carabiner :
	public Gear
{
public:
	Carabiner(std::string manufacturerName, std::string productName, bool isLocking);
	virtual ~Carabiner() = default;
private:
	bool m_isLocking;
	virtual std::string getDescriptionImpl() override;
};

