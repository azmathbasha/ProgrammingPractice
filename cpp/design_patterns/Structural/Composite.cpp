// Composite.cpp
// Real-world example: File system directory and files

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class FileSystemNode {
public:
    virtual ~FileSystemNode() = default;
    virtual void ls(int indent=0) const = 0;
};

class File : public FileSystemNode {
    std::string name;
public:
    File(std::string n): name(std::move(n)) {}
    void ls(int indent=0) const override { std::cout << std::string(indent, ' ') << name << "\n"; }
};

class Directory : public FileSystemNode {
    std::string name;
    std::vector<std::unique_ptr<FileSystemNode>> children;
public:
    Directory(std::string n): name(std::move(n)) {}
    void add(std::unique_ptr<FileSystemNode> node) { children.push_back(std::move(node)); }
    void ls(int indent=0) const override {
        std::cout << std::string(indent, ' ') << name << "/\n";
        for (const auto& c : children) c->ls(indent+2);
    }
};

int main(){
    auto root = std::make_unique<Directory>("root");
    root->add(std::make_unique<File>("README.md"));
    auto src = std::make_unique<Directory>("src");
    src->add(std::make_unique<File>("main.cpp"));
    src->add(std::make_unique<File>("util.cpp"));
    root->add(std::move(src));
    root->ls();
    return 0;
}
