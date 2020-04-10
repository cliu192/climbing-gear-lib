#include "GearInventory.h"

GearInventory::GearInventory()
{
}

void GearInventory::add(std::unique_ptr<Gear> gearToAdd)
{
	auto it = m_inventory.find(gearToAdd);

	if (it == m_inventory.end()) // gear to be added isn't already in inventory
	{
		m_inventory.insert(std::make_pair(std::move(gearToAdd), 1));
	}
	else // gear is already in inventory, just increment count
	{
		++(it->second);
	}
}

void GearInventory::remove(std::unique_ptr<Gear> gearToRemove) // pass in by reference?
{
	auto it = m_inventory.find(gearToRemove);

	if (it->second > 1) // multiple copies of gear exist, just remove one
	{
		--(it->second);
	}
	else // only one copy exists, remove entire inventory entry
	{
		m_inventory.erase(it);
	}
}

std::vector<std::string> GearInventory::getSummary() // TODO make more efficient
{
	std::vector <std::string> totalSummary; 

	for (auto& gear : m_inventory)
	{
		auto gearSummary = "(" + std::to_string(gear.second) + ") ";
		gearSummary += gear.first->getDescription();
		totalSummary.push_back(gearSummary);
	}

	return totalSummary;
}
