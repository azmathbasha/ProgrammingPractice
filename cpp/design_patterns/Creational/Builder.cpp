// Builder.cpp
// Real-world example: Building a complex `House` object step-by-step using a Builder.
// This example demonstrates separating construction from representation so the same
// construction process can create different representations.

#include <iostream>
#include <memory>
#include <string>

// Product: complex object under construction
class House {
public:
	void setWalls(const std::string& w) { walls = w; }
	void setRoof(const std::string& r) { roof = r; }
	void setPool(bool p) { pool = p; }
	void show() const {
		std::cout << "House with: walls=" << walls << ", roof=" << roof << ", pool=" << (pool?"yes":"no") << "\n";
	}
private:
	std::string walls;
	std::string roof;
	bool pool = false;
};

// Builder interface defines steps to build a House
class HouseBuilder {
public:
	virtual ~HouseBuilder() = default;
	virtual void buildWalls() = 0;
	virtual void buildRoof() = 0;
	virtual void buildPool() = 0;
	virtual std::unique_ptr<House> getResult() = 0;
};

// Concrete builder - builds a simple house
class SimpleHouseBuilder : public HouseBuilder {
	std::unique_ptr<House> house = std::make_unique<House>();
public:
	void buildWalls() override { house->setWalls("brick"); }
	void buildRoof() override { house->setRoof("shingle"); }
	void buildPool() override { house->setPool(false); }
	std::unique_ptr<House> getResult() override { return std::move(house); }
};

// Another concrete builder - builds a luxury house
class LuxuryHouseBuilder : public HouseBuilder {
	std::unique_ptr<House> house = std::make_unique<House>();
public:
	void buildWalls() override { house->setWalls("reinforced concrete"); }
	void buildRoof() override { house->setRoof("tiled roof"); }
	void buildPool() override { house->setPool(true); }
	std::unique_ptr<House> getResult() override { return std::move(house); }
};

// Director orchestrates the building steps. It doesn't know concrete builders'
// internals, only the sequence of steps required to build the product.
class Director {
public:
	void constructMinimalHouse(HouseBuilder& builder) {
		builder.buildWalls();
		builder.buildRoof();
	}
	void constructLuxuryHouse(HouseBuilder& builder) {
		builder.buildWalls();
		builder.buildRoof();
		builder.buildPool();
	}
};

int main() {
	Director director;
	SimpleHouseBuilder simpleBuilder;
	director.constructMinimalHouse(simpleBuilder);
	auto simpleHouse = simpleBuilder.getResult();
	std::cout << "Simple house: "; simpleHouse->show();

	LuxuryHouseBuilder luxuryBuilder;
	director.constructLuxuryHouse(luxuryBuilder);
	auto luxuryHouse = luxuryBuilder.getResult();
	std::cout << "Luxury house: "; luxuryHouse->show();

	return 0;
}

