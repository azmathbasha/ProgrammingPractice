// ChainOfResponsibility.cpp
// Real-world example: Support ticket handlers

#include <iostream>
#include <memory>
#include <string>

class Handler {
protected:
    std::shared_ptr<Handler> next;
public:
    void setNext(std::shared_ptr<Handler> h) { next = h; }
    virtual void handle(const std::string& req) {
        if (next) next->handle(req);
    }
    virtual ~Handler() = default;
};

class FrontDesk : public Handler {
public:
    void handle(const std::string& req) override {
        if (req == "password") std::cout << "FrontDesk: handled password reset\n";
        else Handler::handle(req);
    }
};

class TechSupport : public Handler {
public:
    void handle(const std::string& req) override {
        if (req == "bug") std::cout << "TechSupport: handled bug report\n";
        else Handler::handle(req);
    }
};

class Engineering : public Handler {
public:    
    void handle(const std::string& req) override {
        std::cout << "Engineering: handling complex request: " << req << "\n";
    }
};

int main(){
    auto front = std::make_shared<FrontDesk>();
    auto tech = std::make_shared<TechSupport>();
    auto eng = std::make_shared<Engineering>();
    front->setNext(tech); tech->setNext(eng);
    front->handle("password");
    front->handle("bug");
    front->handle("optimization");
    return 0;
}
