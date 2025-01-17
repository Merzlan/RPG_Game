#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <string>
#include <vector>

// Абстрактный класс
class Character {
protected:
    std::string name;
    int health;

public:
    Character(const std::string& name, int health) : name(name), health(health) {}
    virtual void printInfo() const = 0; // Чисто виртуальный метод
    virtual ~Character() = default;    // Виртуальный деструктор
};

// Класс Player
class Player : public Character {
protected:
    int level;
    static int playerCount; // Статическое поле

public:
    Player(const std::string& name, int health, int level)
        : Character(name, health), level(level) {
        ++playerCount;
    }

    Player(const Player& other)
        : Character(other.name, other.health), level(other.level) {
        ++playerCount;
    }

    Player& operator=(const Player& other) {
        if (this != &other) {
            name = other.name;
            health = other.health;
            level = other.level;
        }
        return *this;
    }

    static int getPlayerCount() {
        return playerCount;
    }

    void printInfo() const override {
        std::cout << "Игрок: " << name << ", Уровень: " << level
            << ", Здоровье: " << health << "\n";
    }

    virtual void attack() const {
        std::cout << name << " атакует!\n";
    }

    virtual ~Player() { --playerCount; }
};

int Player::playerCount = 0;

// Производный класс Warrior
class Warrior : public Player {
private:
    int strength;

public:
    Warrior(const std::string& name, int health, int level, int strength)
        : Player(name, health, level), strength(strength) {}

    void attack() const override {
        Player::attack(); // Вызов метода базового класса
        std::cout << name << " наносит мощный удар с силой " << strength << "!\n";
    }

    void printInfo() const override {
        std::cout << "Воин: " << name << ", Уровень: " << level
            << ", Здоровье: " << health << ", Сила: " << strength << "\n";
    }
};

// Производный класс Mage
class Mage : public Player {
private:
    int mana;

public:
    Mage(const std::string& name, int health, int level, int mana)
        : Player(name, health, level), mana(mana) {}

    void attack() const override {
        std::cout << name << " использует магическую атаку с маной " << mana << "!\n";
    }

    void printInfo() const override {
        std::cout << "Маг: " << name << ", Уровень: " << level
            << ", Здоровье: " << health << ", Мана: " << mana << "\n";
    }
};


//Класс существа
class Enemy {
private:
    std::string name;   // Имя врага
    int health;         // Очки здоровья врага
    int attackPower;    // Сила атаки врага

public:
    Enemy(const std::string& name, int health, int attackPower)
        : name(name), health(health), attackPower(attackPower) {}

    //Метод для вывода информации о враге
    void printInfo() const {
        std::cout << "Существо: " << name << "\nЗдоровье: " << health
            << "\nСила атаки: " << attackPower << "\n";
    }
};

//Класс предмета
class Item {
private:
    std::string name; // Имя предмета
    int value;        // Ценность предмета
    int type;         // Тип предмета (например, оружие или снаряжение)

public:
    Item(const std::string& name, int value, int type)
        : name(name), value(value), type(type) {}

    //Метод для получения свойств предмета
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getType() const { return type; }
};

//Класс локации
class Location {
private:
    std::string description; // Описание локации
    std::vector<Item> items; // Массив предметов в локации

public:
    Location(const std::string& description) : description(description) {}

    //Метод для добавления предмета в локацию
    void addItem(const Item& item) {
        if (items.size() < 10) {
            items.push_back(item);
        }
    }
    //Метод для вывода информации о локации и предметах в ней.
    void printInfo() const {
        std::cout << "Локация: " << description << "\nПредметы в локации:\n";
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << " (Стоимость: " << item.getValue() << ")\n";
        }
    }
};

//Класс квеста
class Quest {
private:
    std::string title;        // Название квеста
    std::string description;  // Описание квеста
    bool isCompleted;         // Статус выполнения квеста

public:
    Quest(const std::string& title, const std::string& description, bool isCompleted = false)
        : title(title), description(description), isCompleted(isCompleted) {}

    //Метод для завершения квеста
    void complete() { isCompleted = true; }


    //Метод вывода информации о квесте
    void printInfo() const {
        std::cout << "Квест: " << title << "\nОписание: " << description
            << "\nЗавершен: " << (isCompleted ? "Да" : "Нет") << "\n";
    }
};

//Класс инвентаря
class Inventory {
private:
    std::vector<Item> items; // Массив предметов в инвентаре

public:
    //Метод добавления предмета в инвентарь
    void addItem(const Item& item) {
        if (items.size() < 20) {
            items.push_back(item);
        }
    }
    //Метод вывода списка предметов из инвентаря
    void printInfo() const {
        std::cout << "Инвентарь:\n";
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << " (Стоимость: " << item.getValue() << ")\n";
        }
    }
};

//Класс события
class Event {
private:
    std::string description; // Описание события
    bool isTriggered;        // Флаг, показывающий, произошло ли событие

public:
    Event(const std::string& description, bool isTriggered = false)
        : description(description), isTriggered(isTriggered) {}

    //Метод для завершения события
    void trigger() { isTriggered = true; }

    //Метод вывода информации о событии
    void printInfo() const {
        std::cout << "Событие: " << description << "\nСработано: " << (isTriggered ? "Да" : "Нет") << "\n";
    }
};

//Класс способности
class Ability {
private:
    std::string name; // Название способности
    int power;        // Сила способности
    int cooldown;     // Время перезарядки способности

public:
    Ability(const std::string& name, int power, int cooldown)
        : name(name), power(power), cooldown(cooldown) {}

    //Метод вывода информации о способности
    void printInfo() const {
        std::cout << "Способность: " << name << "\nСила: " << power << "\nПерезарядка: " << cooldown << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Warrior warrior("Рагнар", 150, 5, 30);
    Mage mage("Мерлин", 100, 7, 50);

    // Демонстрация вызова виртуальной функции через указатель
    Character* charPtr = &warrior;
    charPtr->printInfo(); // Печатает информацию о воине

    charPtr = &mage;
    charPtr->printInfo(); // Печатает информацию о маге

    // Демонстрация перегрузки метода
    warrior.attack();
    mage.attack();

    // Демонстрация вызова базового метода
    Player player("Гендальф", 100, 3);
    player.attack();

    // Демонстрация работы статического метода
    std::cout << "Всего игроков: " << Player::getPlayerCount() << "\n";

    return 0;
}
