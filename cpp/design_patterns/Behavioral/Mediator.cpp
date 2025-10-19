// Mediator.cpp
// Real-world example: Chatroom mediator for users

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class User;

class Chatroom {
    std::vector<User*> users;
public:
    void join(User* u) { users.push_back(u); }
    void broadcast(const std::string& from, const std::string& msg);
};

class User {
    std::string name;
    Chatroom& room;
public:
    User(std::string n, Chatroom& r): name(std::move(n)), room(r){ room.join(this); }
    void send(const std::string& msg){ room.broadcast(name, msg); }
    void receive(const std::string& from, const std::string& msg){ std::cout<<from<<" to "<<name<<": "<<msg<<"\n"; }
    const std::string& getName() const { return name; }
};

void Chatroom::broadcast(const std::string& from, const std::string& msg){
    for (auto u : users) if (u->getName() != from) u->receive(from, msg);
}

int main(){
    Chatroom room;
    User alice("Alice", room);
    User bob("Bob", room);
    alice.send("Hello everyone");
    bob.send("Hi Alice");
    return 0;
}
