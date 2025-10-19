// Memento.cpp
// Real-world example: Text editor snapshot undo

#include <iostream>
#include <string>

class Memento { std::string state; public: Memento(std::string s):state(std::move(s)){} const std::string& get() const { return state; } };

class Editor {
    std::string content;
public:
    void type(const std::string& t){ content += t; }
    Memento save() const { return Memento(content); }
    void restore(const Memento& m){ content = m.get(); }
    void show() const { std::cout<<content<<"\n"; }
};

int main(){
    Editor e; e.type("Hello"); auto m1 = e.save();
    e.type(" World"); e.show();
    e.restore(m1); e.show();
    return 0;
}
