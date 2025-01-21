#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

// Базовый класс игрока
class Player {
protected:
    std::string name;
    int level;

public:
    Player(const std::string& name, int level) : name(name), level(level) {}

    virtual ~Player() = default;

    virtual void printInfo() const {
        std::cout << "Игрок: " << name << ", Уровень: " << level << "\n";
    }

    const std::string& getName() const {
        return name;
    }

    int getLevel() const {
        return level;
    }
};

// Производный класс - Воин
class Warrior : public Player {
private:
    int strength;

public:
    Warrior(const std::string& name, int level, int strength)
        : Player(name, level), strength(strength) {}

    void printInfo() const override {
        std::cout << "Воин: " << name << ", Уровень: " << level
            << ", Сила: " << strength << "\n";
    }
};

// Производный класс - Маг
class Mage : public Player {
private:
    int mana;

public:
    Mage(const std::string& name, int level, int mana)
        : Player(name, level), mana(mana) {}

    void printInfo() const override {
        std::cout << "Маг: " << name << ", Уровень: " << level
            << ", Мана: " << mana << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    // Используем контейнер vector для хранения объектов базового и производных классов
    std::vector<std::shared_ptr<Player>> players;

    // Добавляем игроков в контейнер
    players.push_back(std::make_shared<Warrior>("Рагнар", 10, 50));
    players.push_back(std::make_shared<Mage>("Мерлин", 12, 100));
    players.push_back(std::make_shared<Warrior>("Конан", 8, 60));
    players.push_back(std::make_shared<Mage>("Гэндальф", 15, 200));

    std::cout << "Игроки до сортировки:\n";
    for (const auto& player : players) {
        player->printInfo();
    }

    // 1. Сортировка игроков по уровню
    std::sort(players.begin(), players.end(), [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
        return a->getLevel() > b->getLevel(); // Сортировка по убыванию уровня
        });

    std::cout << "Игроки после сортировки:\n";
    for (const auto& player : players) {
        player->printInfo();
    }

    // 2. Поиск игрока по имени
    std::string searchName = "Мерн";
    auto it = std::find_if(players.begin(), players.end(), [&searchName](const std::shared_ptr<Player>& player) {
        return player->getName() == searchName;
        });

    if (it != players.end()) {
        std::cout << "\nНайден игрок:\n";
        (*it)->printInfo();
    }
    else {
        std::cout << "\nИгрок с инем " << searchName << " не найден.\n";
    }

    return 0;
}