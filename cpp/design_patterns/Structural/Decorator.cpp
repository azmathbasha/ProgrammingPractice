// Decorator.cpp
// Real-world example: Coffee with condiments

#include <iostream>
#include <memory>
#include <string>

class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

class HouseBlend : public Beverage {
public:
    std::string getDescription() const override { return "House Blend Coffee"; }
    double cost() const override { return 0.89; }
};

class CondimentDecorator : public Beverage {
protected:
    std::unique_ptr<Beverage> beverage;
public:
    CondimentDecorator(std::unique_ptr<Beverage> b): beverage(std::move(b)) {}
};

class Mocha : public CondimentDecorator {
public:
    Mocha(std::unique_ptr<Beverage> b): CondimentDecorator(std::move(b)) {}
    std::string getDescription() const override { return beverage->getDescription() + ", Mocha"; }
    double cost() const override { return beverage->cost() + 0.20; }
};

class Soy : public CondimentDecorator {
public:
    Soy(std::unique_ptr<Beverage> b): CondimentDecorator(std::move(b)) {}
    std::string getDescription() const override { return beverage->getDescription() + ", Soy"; }
    double cost() const override { return beverage->cost() + 0.15; }
};

int main(){
    std::unique_ptr<Beverage> beverage = std::make_unique<HouseBlend>();
    beverage = std::make_unique<Mocha>(std::move(beverage));
    beverage = std::make_unique<Soy>(std::move(beverage));
    std::cout << beverage->getDescription() << " costs $" << beverage->cost() << "\n";
    return 0;
}
