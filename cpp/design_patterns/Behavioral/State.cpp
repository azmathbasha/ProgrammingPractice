// State.cpp
// Real-world example: Simple connection state transitions

#include <iostream>
#include <memory>
#include <string>

class Connection;

class State {
public:
    virtual ~State()=default;
    virtual void open(Connection*){}
    virtual void close(Connection*){}
    virtual void send(Connection*, const std::string&){ }
};

class Connection {
    State* state = nullptr;
public:
    void setState(State* s){ state = s; }
    void open(){ if (state) state->open(this); }
    void close(){ if (state) state->close(this); }
    void send(const std::string& msg){ if (state) state->send(this,msg); }
};

class ClosedState : public State {
public:
    void open(Connection* c) override { std::cout<<"Opening connection...\n"; c->setState(new State()); }
};

int main(){
    Connection c; ClosedState closed; c.setState(&closed);
    c.open(); c.send("Hello"); c.close();
    return 0;
}
