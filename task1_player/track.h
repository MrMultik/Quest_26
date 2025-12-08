#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

class Track {
private:
    std::string name;
    std::tm creationDate;
    int duration; // в секундах

public:
    Track();
    Track(const std::string& name, const std::tm& date, int duration);

    std::string getName() const;
    std::tm getCreationDate() const;
    int getDuration() const;

    void displayInfo() const;
};