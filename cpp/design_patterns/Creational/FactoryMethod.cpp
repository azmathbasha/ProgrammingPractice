// FactoryMethod.cpp
// Real-world example: Document creator that creates different types of Documents (Resume, Report)
// Build and run: g++ -std=c++17 FactoryMethod.cpp -o FactoryMethod && ./FactoryMethod

#include <iostream>
#include <memory>
#include <string>

// Product
class Document {
public:
    virtual ~Document() = default;
    virtual std::string getType() const = 0;
    virtual void open() const = 0;
};

class Resume : public Document {
public:
    std::string getType() const override { return "Resume"; }
    void open() const override { std::cout << "Opening resume layout..." << std::endl; }
};

class Report : public Document {
public:
    std::string getType() const override { return "Report"; }
    void open() const override { std::cout << "Opening report template..." << std::endl; }
};

// Creator
class DocumentCreator {
public:
    virtual ~DocumentCreator() = default;
    // Factory method
    virtual std::unique_ptr<Document> createDocument(const std::string& purpose) const = 0;
    void newDocument(const std::string& purpose) const {
        auto doc = createDocument(purpose);
        std::cout << "Created document type: " << doc->getType() << std::endl;
        doc->open();
    }
};

class HRDocumentCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> createDocument(const std::string& purpose) const override {
        if (purpose == "hire") return std::make_unique<Resume>();
        return std::make_unique<Report>();
    }
};

class EngineeringDocumentCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> createDocument(const std::string& purpose) const override {
        if (purpose == "design") return std::make_unique<Report>();
        return std::make_unique<Resume>();
    }
};

int main() {
    HRDocumentCreator hr;
    EngineeringDocumentCreator eng;

    std::cout << "HR creates for hire:" << std::endl;
    hr.newDocument("hire");

    std::cout << "\nEngineering creates for design:" << std::endl;
    eng.newDocument("design");

    return 0;
}
