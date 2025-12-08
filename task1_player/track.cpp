#include "track.h"

Track::Track() : name("Unknown"), duration(0) {
    std::time_t t = std::time(nullptr);
    creationDate = *std::localtime(&t);
}

Track::Track(const std::string& name, const std::tm& date, int duration)
    : name(name), creationDate(date), duration(duration) {
}

std::string Track::getName() const {
    return name;
}

std::tm Track::getCreationDate() const {
    return creationDate;
}

int Track::getDuration() const {
    return duration;
}

void Track::displayInfo() const {
    std::cout << "=================================\n";
    std::cout << "Трек: " << name << "\n";
    std::cout << "Дата создания: "
        << std::put_time(&creationDate, "%d.%m.%Y %H:%M:%S") << "\n";
    std::cout << "Продолжительность: " << duration << " секунд\n";
    std::cout << "=================================\n";
}