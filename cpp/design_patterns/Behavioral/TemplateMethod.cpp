// TemplateMethod.cpp
// Real-world example: Data processing template with steps

#include <iostream>
#include <string>

class DataProcessor {
public:
    virtual ~DataProcessor()=default;
    void process() {
        read();
        transform();
        write();
    }
    virtual void read() = 0;
    virtual void transform() = 0;
    virtual void write() = 0;
};

class CSVProcessor : public DataProcessor {
    std::string data;
public:
    void read() override { data = "1,2,3"; std::cout<<"Read CSV\n"; }
    void transform() override { data += ",4"; std::cout<<"Transformed CSV\n"; }
    void write() override { std::cout<<"Write CSV: "<<data<<"\n"; }
};

int main(){
    CSVProcessor p; p.process();
    return 0;
}
