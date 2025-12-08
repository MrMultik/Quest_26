#include "player.h"
#include <iostream>
#include <chrono>

Player::Player() : isPlaying(false), isPaused(false), currentTrackIndex(-1) {
    initializeTracks();
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Player::initializeTracks() {
    std::time_t now = std::time(nullptr);

    // Создаем несколько тестовых треков
    std::tm date1 = *std::localtime(&now);
    date1.tm_hour = 10;
    date1.tm_min = 30;
    tracks.push_back(Track("Bohemian Rhapsody", date1, 354));

    std::tm date2 = *std::localtime(&now);
    date2.tm_mday -= 5;
    tracks.push_back(Track("Stairway to Heaven", date2, 482));

    std::tm date3 = *std::localtime(&now);
    date3.tm_mday -= 10;
    tracks.push_back(Track("Hotel California", date3, 391));

    std::tm date4 = *std::localtime(&now);
    date4.tm_mday -= 15;
    tracks.push_back(Track("Imagine", date4, 183));

    std::tm date5 = *std::localtime(&now);
    date5.tm_mday -= 20;
    tracks.push_back(Track("Smells Like Teen Spirit", date5, 301));
}

void Player::play(const std::string& trackName) {
    if (isPlaying && !isPaused) {
        std::cout << "Уже воспроизводится трек: " << tracks[currentTrackIndex].getName() << std::endl;
        return;
    }

    if (isPaused) {
        std::cout << "Продолжаем воспроизведение: " << tracks[currentTrackIndex].getName() << std::endl;
        isPaused = false;
        tracks[currentTrackIndex].displayInfo();
        return;
    }

    // Ищем трек по имени
    for (size_t i = 0; i < tracks.size(); ++i) {
        if (tracks[i].getName() == trackName) {
            currentTrackIndex = static_cast<int>(i);
            isPlaying = true;
            isPaused = false;
            std::cout << "Воспроизведение начато:" << std::endl;
            tracks[i].displayInfo();
            return;
        }
    }

    std::cout << "Трек \"" << trackName << "\" не найден!" << std::endl;
    std::cout << "Доступные треки:" << std::endl;
    listTracks();
}

void Player::pause() {
    if (!isPlaying) {
        std::cout << "Нет активного воспроизведения для паузы." << std::endl;
        return;
    }

    if (isPaused) {
        std::cout << "Уже на паузе: " << tracks[currentTrackIndex].getName() << std::endl;
        return;
    }

    isPaused = true;
    std::cout << "Пауза: " << tracks[currentTrackIndex].getName() << std::endl;
}

void Player::next() {
    if (tracks.empty()) {
        std::cout << "Нет доступных треков." << std::endl;
        return;
    }

    // Случайный выбор следующего трека
    int newIndex;
    do {
        newIndex = std::rand() % tracks.size();
    } while (tracks.size() > 1 && newIndex == currentTrackIndex);

    currentTrackIndex = newIndex;
    isPlaying = true;
    isPaused = false;

    std::cout << "Следующий трек:" << std::endl;
    tracks[currentTrackIndex].displayInfo();
}

void Player::stop() {
    if (!isPlaying) {
        std::cout << "Нет активного воспроизведения для остановки." << std::endl;
        return;
    }

    std::cout << "Остановлено: " << tracks[currentTrackIndex].getName() << std::endl;
    isPlaying = false;
    isPaused = false;
    currentTrackIndex = -1;
}

void Player::listTracks() const {
    std::cout << std::endl << "=== Доступные треки ===" << std::endl;
    for (size_t i = 0; i < tracks.size(); ++i) {
        std::cout << i + 1 << ". " << tracks[i].getName()
            << " (" << tracks[i].getDuration() << " сек)" << std::endl;
    }
    std::cout << "=======================" << std::endl << std::endl;
}