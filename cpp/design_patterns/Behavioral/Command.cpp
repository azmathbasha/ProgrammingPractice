// Command.cpp
// Real-world example: Remote control with commands

#include <iostream>
#include <memory>
#include <vector>

class Command { public: virtual ~Command()=default; virtual void execute()=0; };

class Light {
public:
    void on(){ std::cout<<"Light on\n"; }
    void off(){ std::cout<<"Light off\n"; }
};

class LightOnCommand : public Command {
    Light& light;
public:
    LightOnCommand(Light& l): light(l) {}
    void execute() override { light.on(); }
};

class Remote {
    std::vector<std::unique_ptr<Command>> slots;
public:
    void setCommand(std::unique_ptr<Command> cmd){ slots.push_back(std::move(cmd)); }
    void press(int idx){ if (idx < (int)slots.size()) slots[idx]->execute(); }
};

int main(){
    Light light;
    Remote remote;
    remote.setCommand(std::make_unique<LightOnCommand>(light));
    remote.press(0);
    return 0;
}
