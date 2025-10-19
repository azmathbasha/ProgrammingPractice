// Iterator.cpp
// Real-world example: Custom iterator over a collection (playlist)

#include <iostream>
#include <vector>
#include <string>

class Playlist {
    std::vector<std::string> songs;
public:
    void add(const std::string& s){ songs.push_back(s); }
    auto begin() const { return songs.begin(); }
    auto end() const { return songs.end(); }
};

int main(){
    Playlist p; p.add("Song A"); p.add("Song B"); p.add("Song C");
    for (const auto& s : p) std::cout<<s<<"\n";
    return 0;
}
