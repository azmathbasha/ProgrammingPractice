// Bridge.cpp
// Real-world example: Remote control (abstraction) and Device implementations (TV, Radio)

#include <iostream>
#include <memory>
#include <string>

class Device {
public:
    virtual ~Device() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int) = 0;
};

class TV : public Device {
public:
    void turnOn() override { std::cout << "TV: power on\n"; }
    void turnOff() override { std::cout << "TV: power off\n"; }
    void setChannel(int c) override { std::cout << "TV: set channel " << c << "\n"; }
};

class Radio : public Device {
public:
    void turnOn() override { std::cout << "Radio: power on\n"; }
    void turnOff() override { std::cout << "Radio: power off\n"; }
    void setChannel(int c) override { std::cout << "Radio: set frequency " << c << "\n"; }
};

class RemoteControl {
protected:
    std::unique_ptr<Device> device;
public:
    RemoteControl(std::unique_ptr<Device> d): device(std::move(d)) {}
    virtual ~RemoteControl() = default;
    virtual void powerOn() { device->turnOn(); }
    virtual void powerOff() { device->turnOff(); }
    virtual void tune(int v) { device->setChannel(v); }
};

class AdvancedRemote : public RemoteControl {
public:
    AdvancedRemote(std::unique_ptr<Device> d): RemoteControl(std::move(d)) {}
    void mute() { std::cout << "AdvancedRemote: mute\n"; }
};

int main(){
    RemoteControl basic(std::make_unique<TV>());
    basic.powerOn();
    basic.tune(5);
    basic.powerOff();

    AdvancedRemote adv(std::make_unique<Radio>());
    adv.powerOn();
    adv.tune(101);
    adv.mute();
    adv.powerOff();
    return 0;
}
