// Visitor.cpp
// Real-world example: Tax calculation visitor for different item types

#include <iostream>
#include <vector>
#include <memory>

class TaxVisitor;

class Item {
public:
    virtual ~Item()=default;
    virtual void accept(TaxVisitor& v)=0;
};

class Book : public Item { public: void accept(TaxVisitor& v) override; double price=12.99; };
class Food : public Item { public: void accept(TaxVisitor& v) override; double price=2.5; };

class TaxVisitor {
public:
    double total=0;
    void visit(Book& b){ total += b.price * 0.1; }
    void visit(Food& f){ total += f.price * 0.05; }
};

void Book::accept(TaxVisitor& v){ v.visit(*this); }
void Food::accept(TaxVisitor& v){ v.visit(*this); }

int main(){
    std::vector<std::unique_ptr<Item>> items;
    items.push_back(std::make_unique<Book>());
    items.push_back(std::make_unique<Food>());
    TaxVisitor tax;
    for (auto& it: items) it->accept(tax);
    std::cout<<"Total tax: "<<tax.total<<"\n";
    return 0;
}
