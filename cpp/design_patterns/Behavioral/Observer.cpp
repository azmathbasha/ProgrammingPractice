// Observer.cpp
// Real-world example: News publisher and subscribers

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Observer { public: virtual ~Observer()=default; virtual void update(const std::string& msg)=0; };

class Publisher {
    std::vector<Observer*> subs;
public:
    void subscribe(Observer* o){ subs.push_back(o); }
    void publish(const std::string& m){ for (auto s: subs) s->update(m); }
};

class Reader : public Observer {
    std::string name;
public:
    Reader(std::string n):name(std::move(n)){}
    void update(const std::string& msg) override { std::cout<<name<<" received: "<<msg<<"\n"; }
};

int main(){
    Publisher pub;
    Reader a("Alice"), b("Bob");
    pub.subscribe(&a); pub.subscribe(&b);
    pub.publish("Breaking news!");
    return 0;
}
