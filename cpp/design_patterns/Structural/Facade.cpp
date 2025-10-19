// Facade.cpp
// Real-world example: Simple subsystem facade for a home theater

#include <iostream>
#include <string>

class Amplifier { public: void on(){std::cout<<"Amplifier on\n";} void off(){std::cout<<"Amplifier off\n";} };
class Tuner { public: void setFrequency(double f){std::cout<<"Tuner set to "<<f<<"\n";} };
class StreamingPlayer { public: void play(const std::string& m){std::cout<<"Playing "<<m<<"\n";} void stop(){std::cout<<"Stop playing\n";} };
class Projector { public: void on(){std::cout<<"Projector on\n";} void off(){std::cout<<"Projector off\n";} };

class HomeTheaterFacade {
    Amplifier amp; Tuner tuner; StreamingPlayer player; Projector projector;
public:
    void watchMovie(const std::string& movie) {
        std::cout << "Get ready to watch a movie...\n";
        amp.on();
        tuner.setFrequency(101.1);
        projector.on();
        player.play(movie);
    }
    void endMovie() {
        player.stop();
        projector.off();
        amp.off();
        std::cout << "Movie ended\n";
    }
};

int main(){
    HomeTheaterFacade home;
    home.watchMovie("Inception");
    home.endMovie();
    return 0;
}
