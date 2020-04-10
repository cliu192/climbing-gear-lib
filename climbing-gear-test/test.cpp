#include "pch.h"
#include "GearInventory.h"

// Test List
// 1) When a novel piece of gear is added, the inventory adds the new piece of gear. 
// 2) When a duplicate piece of gear is added, the inventory only increments the count of the piece of 
//    gear.
// 3) When there is nothing in the inventory, an empty summary is returned.
// 4) When there is gear in the inventory, a summary of the gear and the quantities 
//    in the inventory are returned.
// 5) When removal of an existing piece of gear is requested and only one piece of gear exists,
//    that piece of gear is removed from the inventory entirely.
// 6) When removal of an existing piece of gear is requested and multiple of that piece of gear exists,
//    that piece of gear's count in decremented.
// 7) When removal of a non-existent piece of gear is requested, an exception is thrown. 

class GearInventoryTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_gearInventory = std::make_unique<GearInventory>();
    }

    std::unique_ptr<GearInventory> m_gearInventory;
    std::string m_manufacturerName = "Black Diamond";
    std::string m_productName = "Vector Helmet";
};
TEST_F(GearInventoryTest, WhenAdditionOfNovelGearIsRequestedGearIsAddedToInventory)
{
    // create new piece of gear to add to inventory and save description
    auto newGear = std::make_unique<Gear>(m_manufacturerName, m_productName);
    auto newGearDescription = newGear->getDescription();

    m_gearInventory->add(std::move(newGear));

    // create expected gear description
    auto expectedGearDescription = "(1) " + newGearDescription;
    // get returned gear description
    auto addedGearDescription = m_gearInventory->getSummary()[0];

    EXPECT_EQ(expectedGearDescription, addedGearDescription);
}
TEST_F(GearInventoryTest, WhenAdditionOfDuplicateGearIsRequestedGearCountIsIncremented)
{
    // populate inventory with duplicate pieces of gear and save description
    auto newGear1 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    auto newGearDescription = newGear1->getDescription();
    m_gearInventory->add(std::move(newGear1));
    auto newGear2 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->add(std::move(newGear2));

    // create expected gear description
    auto expectedGearDescription = "(2) " + newGearDescription;
    // get returned gear description
    auto addedGearDescription = m_gearInventory->getSummary()[0];

    EXPECT_EQ(expectedGearDescription, addedGearDescription);
}
TEST_F(GearInventoryTest, WhenInventoryIsEmptySummaryIsAlsoEmpty)
{
    // create empty gear summary
    auto expectedSummary = std::vector<std::string>();
    // get returned gear summary
    auto returnedSummary = m_gearInventory->getSummary();

    EXPECT_EQ(expectedSummary, returnedSummary);
}

TEST_F(GearInventoryTest, WhenInventoryIsNotEmptySummaryIncludesGearAndQuantities)
{
    std::vector<std::string> expectedSummary;

    // populate inventory with different pieces of gear and save descriptions
    auto newGear1 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    auto newGearDescription1 = newGear1->getDescription();
    m_gearInventory->add(std::move(newGear1));
    auto newGear2 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->add(std::move(newGear2));
    auto newGear3 = std::make_unique<Gear>(m_manufacturerName, "Nut Tool");
    auto newGearDescription3 = newGear3->getDescription();
    m_gearInventory->add(std::move(newGear3));

    // create expected gear summary 
    auto expectedGearDescription1 = "(2) " + newGearDescription1;
    auto expectedGearDescription2 = "(1) " + newGearDescription3;
    expectedSummary.push_back(expectedGearDescription1);
    expectedSummary.push_back(expectedGearDescription2);
    //get returned gear summary
    auto returnedSummary = m_gearInventory->getSummary();

    EXPECT_EQ(expectedSummary, returnedSummary);
}

TEST_F(GearInventoryTest, WhenRemovalOfGearWithOnlyOneCopyIsRequestedGearIsRemovedEntirelyFromInventory)
{
    // populate inventory
    auto newGear = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->add(std::move(newGear));

    auto gearToRemove = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->remove(std::move(gearToRemove));

    // create empty gear summary
    auto expectedSummary = std::vector<std::string>();
    // get returned gear summary
    auto returnedSummary = m_gearInventory->getSummary();

    EXPECT_EQ(expectedSummary, returnedSummary);
}

TEST_F(GearInventoryTest, WhenRemovalOfGearWithMultipleCopiesIsRequestedGearCountIsDecremented)
{
    // populate inventory and save description
    auto newGear1 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    auto newGearDescription = newGear1->getDescription();
    m_gearInventory->add(std::move(newGear1));
    auto newGear2 = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->add(std::move(newGear2));

    auto gearToRemove = std::make_unique<Gear>(m_manufacturerName, m_productName);
    m_gearInventory->remove(std::move(gearToRemove));

    // create expected gear summary
    auto expectedDescription = "(1) " + newGearDescription;
    std::vector<std::string> expectedSummary;
    expectedSummary.push_back(expectedDescription);
    // get returned gear summary
    auto returnedSummary = m_gearInventory->getSummary();

    EXPECT_EQ(expectedSummary, returnedSummary);
}

TEST_F(GearInventoryTest, WhenRemovalOfGearNotInInventoryIsRequestedExceptionIsThrown)
{
    auto gearToRemove = std::make_unique<Gear>(m_manufacturerName, m_productName);

    EXPECT_ANY_THROW(m_gearInventory->remove(std::move(gearToRemove)));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}