#pragma once
#include <map>
#include <vector>
#include <memory>
#include "Gear.h"

class GearInventory
{
public:
	GearInventory();
	virtual ~GearInventory() = default;
	void add(std::unique_ptr<Gear> gearToAdd);
	void remove(std::unique_ptr<Gear> gearToRemove);
	std::vector<std::string> getSummary();
private:
	struct m_comparator
	{
		bool operator()(const std::unique_ptr<Gear>& a, const std::unique_ptr<Gear>& b) const
		{
			bool returnValue;
			auto aDescription = a->getDescription();
			auto bDescription = b->getDescription();

			if (aDescription == bDescription)
			{
				returnValue = false;
			}
			else
			{
				returnValue = aDescription > bDescription;
			}
			return returnValue;
		}
	};
	std::map <std::unique_ptr<Gear>, int, m_comparator> m_inventory;
};

