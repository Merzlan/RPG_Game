#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <string>
#include <vector>

//Класс персонажа
class Player {
private:
    std::string name;
    int health;
    int level;
    static int playerCount; // Статическое поле

public:
    // Конструктор
    Player(const std::string& name, int health, int level)
        : name(name), health(health), level(level) {
        ++playerCount; // Увеличиваем счетчик при создании объекта
    }

    // Конструктор копии
    Player(const Player& other)
        : name(other.name), health(other.health), level(other.level) {
        ++playerCount;
    }

    // Оператор присваивания
    Player& operator=(const Player& other) {
        if (this != &other) { // Использование this для проверки самоприсваивания
            name = other.name;
            health = other.health;
            level = other.level;
        }
        return *this;
    }

    // Дружественная функция
    friend void printPlayer(const Player& player);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Игрок: " << player.name << ", Уровень: " << player.level << ", Здоровье: " << player.health;
        return os;
    }

    // Метод для возврата значения через указатель
    void getHealthPointer(int* healthPtr) const {
        if (healthPtr) {
            *healthPtr = health;
        }
    }

    // Метод для возврата значения через ссылку
    void getHealthReference(int& healthRef) const {
        healthRef = health;
    }

    // Статический метод
    static int getPlayerCount() {
        return playerCount;
    }

    // Деструктор
    ~Player() {
        --playerCount;
    }
};

int Player::playerCount = 0; // Инициализация статического поля

// Дружественная функция
void printPlayer(const Player& player) {
    std::cout << "Дружественная функция: " << player.name << " (Уровень: " << player.level << ")\n";
}

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

int main()
{
	setlocale(LC_ALL, "RU");
    try {
        Player hero("Артур", 100, 1);
        Player knight("Ланселот", 120, 2);

        // Демонстрация работы с указателем и ссылкой
        int healthValue;
        hero.getHealthPointer(&healthValue);
        std::cout << "Здоровье через указатель: " << healthValue << "\n";

        hero.getHealthReference(healthValue);
        std::cout << "Здоровье через ссылку: " << healthValue << "\n";

        // Дружественная функция
        printPlayer(knight);

        // Перегрузка оператора вывода
        std::cout << knight << "\n";

        // Работа со статическим полем и методом
        std::cout << "Количество игроков: " << Player::getPlayerCount() << "\n";

        // Исключение
        throw std::runtime_error("Демонстрация исключения");

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << "\n";
    }

    return 0;
}
