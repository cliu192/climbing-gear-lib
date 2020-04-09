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
	//std::map<std::unique_ptr<Gear>, int> m_inventory;
};

