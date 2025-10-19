// AbstractFactory.cpp
// Real-world example: GUI toolkit factories for creating buttons and checkboxes for different OS themes

#include <iostream>
#include <memory>
#include <string>

// Abstract products
class Button {
public:
    virtual ~Button() = default;
    virtual void paint() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void paint() const = 0;
};

// Concrete products for Windows
class WindowsButton : public Button { public: void paint() const override { std::cout << "Rendering Windows-style button\n"; } };
class WindowsCheckbox : public Checkbox { public: void paint() const override { std::cout << "Rendering Windows-style checkbox\n"; } };

// Concrete products for macOS
class MacButton : public Button { public: void paint() const override { std::cout << "Rendering macOS-style button\n"; } };
class MacCheckbox : public Checkbox { public: void paint() const override { std::cout << "Rendering macOS-style checkbox\n"; } };

// Abstract factory
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<WindowsButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<WindowsCheckbox>(); }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<MacButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<MacCheckbox>(); }
};

// Application code
class Application {
    std::unique_ptr<GUIFactory> factory;
public:
    Application(std::unique_ptr<GUIFactory> f): factory(std::move(f)) {}
    void render() const {
        auto btn = factory->createButton();
        auto cb  = factory->createCheckbox();
        btn->paint();
        cb->paint();
    }
};

int main() {
    std::cout << "Windows UI:\n";
    Application appWin(std::make_unique<WindowsFactory>());
    appWin.render();

    std::cout << "\nmacOS UI:\n";
    Application appMac(std::make_unique<MacFactory>());
    appMac.render();

    return 0;
}
