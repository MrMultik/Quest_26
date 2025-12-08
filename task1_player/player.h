#pragma once
#include "track.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

class Player {
private:
    std::vector<Track> tracks;
    bool isPlaying;
    bool isPaused;
    int currentTrackIndex;

    void initializeTracks();

public:
    Player();

    void play(const std::string& trackName);
    void pause();
    void next();
    void stop();
    void listTracks() const;
};