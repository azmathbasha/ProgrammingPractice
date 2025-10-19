#include <iostream>

/*
Adapter Pattern (Structural)

Intent: Convert the interface of a class into another interface clients expect.
This example adapts a third-party `LegacyAudioPlayer` to the modern `IAudioPlayer`
interface used by the app. Use when integrating legacy or incompatible classes.

Compile: g++ -std=c++17 Adapter.cpp -o Adapter && ./Adapter
*/

// Target interface used by the application
class IAudioPlayer {
public:
    virtual ~IAudioPlayer() = default;
    virtual void play(const std::string &file) = 0;
};

// Adaptee: third-party legacy class with an incompatible interface
class LegacyAudioPlayer {
public:
    void startPlayback(const char *filePath) {
        std::cout << "Legacy player starting playback: " << filePath << std::endl;
    }
};

// Adapter: wraps LegacyAudioPlayer and exposes IAudioPlayer interface
class LegacyAudioAdapter : public IAudioPlayer {
    LegacyAudioPlayer legacy;
public:
    void play(const std::string &file) override {
        // adapt std::string to const char*
        legacy.startPlayback(file.c_str());
    }
};

int main() {
    // Client code uses the IAudioPlayer interface
    IAudioPlayer *player = new LegacyAudioAdapter();
    player->play("song.mp3");
    delete player;
    return 0;
}
