// Flyweight.cpp
// Real-world example: Character glyph sharing in a text editor

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class Glyph {
    char c;
public:
    Glyph(char ch): c(ch) {}
    void draw(int x, int y) const { std::cout << "Glyph '"<<c<<"' at ("<<x<<","<<y<<")\n"; }
};

class GlyphFactory {
    std::unordered_map<char, std::shared_ptr<Glyph>> pool;
public:
    std::shared_ptr<Glyph> get(char c) {
        auto it = pool.find(c);
        if (it != pool.end()) return it->second;
        auto g = std::make_shared<Glyph>(c);
        pool[c] = g;
        return g;
    }
};

int main(){
    GlyphFactory f;
    auto a1 = f.get('A');
    auto a2 = f.get('A');
    a1->draw(1,1);
    a2->draw(2,1);
    std::cout << "Shared: " << (a1==a2) << "\n";
    return 0;
}
