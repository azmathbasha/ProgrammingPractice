// Strategy.cpp
// Real-world example: Payment strategies

#include <iostream>
#include <memory>

class PaymentStrategy { public: virtual ~PaymentStrategy()=default; virtual void pay(int amount)=0; };
class CreditCard : public PaymentStrategy { public: void pay(int amount) override { std::cout<<"Paid "<<amount<<" with credit card\n"; } };
class PayPal : public PaymentStrategy { public: void pay(int amount) override { std::cout<<"Paid "<<amount<<" with PayPal\n"; } };

class ShoppingCart {
    std::unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<PaymentStrategy> s){ strategy = std::move(s); }
    void checkout(int amount){ strategy->pay(amount); }
};

int main(){
    ShoppingCart cart;
    cart.setStrategy(std::make_unique<CreditCard>());
    cart.checkout(50);
    cart.setStrategy(std::make_unique<PayPal>());
    cart.checkout(75);
    return 0;
}
