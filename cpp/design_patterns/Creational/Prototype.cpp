// Prototype.cpp
// Real-world example: Cloning configurable widgets

#include <iostream>
#include <memory>
#include <string>

class Widget {
public:
    virtual ~Widget() = default;
    virtual std::unique_ptr<Widget> clone() const = 0;
    virtual void info() const = 0;
};

class ButtonWidget : public Widget {
    std::string label;
public:
    ButtonWidget(std::string l): label(std::move(l)) {}
    std::unique_ptr<Widget> clone() const override { return std::make_unique<ButtonWidget>(*this); }
    void info() const override { std::cout << "ButtonWidget: " << label << "\n"; }
};

class SliderWidget : public Widget {
    int minv, maxv;
public:
    SliderWidget(int lo, int hi): minv(lo), maxv(hi) {}
    std::unique_ptr<Widget> clone() const override { return std::make_unique<SliderWidget>(*this); }
    void info() const override { std::cout << "SliderWidget range: " << minv << "-" << maxv << "\n"; }
};

int main() {
    auto btnProto = std::make_unique<ButtonWidget>("OK");
    auto sldProto = std::make_unique<SliderWidget>(0, 100);

    auto btn1 = btnProto->clone();
    auto btn2 = btnProto->clone();
    auto s1 = sldProto->clone();

    btn1->info();
    btn2->info();
    s1->info();

    return 0;
}
