#pragma once
#include "Gear.h"

enum class QuickdrawType
{
	sport,
	alpine
};

class Quickdraw :
	public Gear
{
public:
	Quickdraw(std::string manufacturerName, std::string productName, QuickdrawType quickdrawType);
	virtual ~Quickdraw() = default;
private:
	QuickdrawType m_quickdrawType;
	std::string getDescriptionImpl() override;
};

