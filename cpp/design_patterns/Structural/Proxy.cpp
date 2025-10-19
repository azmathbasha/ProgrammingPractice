// Proxy.cpp
// Real-world example: Virtual proxy for loading large images lazily

#include <iostream>
#include <memory>
#include <string>

class Image {
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};

class RealImage : public Image {
    std::string file;
public:
    RealImage(std::string f): file(std::move(f)) { loadFromDisk(); }
    void loadFromDisk() { std::cout << "Loading " << file << " from disk...\n"; }
    void display() override { std::cout << "Displaying " << file << "\n"; }
};

class ImageProxy : public Image {
    std::string file;
    std::unique_ptr<RealImage> real;
public:
    ImageProxy(std::string f): file(std::move(f)) {}
    void display() override {
        if (!real) real = std::make_unique<RealImage>(file);
        real->display();
    }
};

int main(){
    ImageProxy img("big-photo.png");
    std::cout << "First call:\n"; img.display();
    std::cout << "Second call:\n"; img.display();
    return 0;
}
