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
    std::string name;   // Имя персонажа
    int health;         // Очки здоровья персонажа
    int level;          // Уровень персонажа
    int attackPower;    // Сила атаки персонажа

public:
    // Конструктор класса Player
    Player(const std::string& name, int health, int level, int attackPower)
        : name(name), health(health), level(level), attackPower(attackPower) {}

    // Метод для вывода информации о персонаже
    void printInfo() const {
        std::cout << "Персонаж: " << name << "\nЗдоровье: " << health << "\nУровень: " << level
            << "\nСила атаки: " << attackPower << "\n";
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



/*


//Структура предмета
typedef struct {
    char name[50];//Название предмета
    int value;//Цена предмета
    int type; // 0 - Оружие, 1 - Снаряжение
} Item;

//Структура локации
typedef struct {
    char description[255];//Описание локации
    Item items[10];//Массив предметов в локации
    int itemCount;//Количество предметов
} Location;

//Структура квеста
typedef struct {
    char title[50];//Название квеста
    char description[255];//Описание квеста
    int isCompleted;//Статус завершения
} Quest;

//Структура инвентаря
typedef struct {
    Item items[20];//Массив предметов в инвентаре
    int itemCount;//Количество предметов в инвентаре
} Inventory;

//Структура события
typedef struct {
    char description[100];//Описание события
    int isTriggered;//Статус срабатывания
} Event;

//Структура способности
typedef struct {
    char name[50];//Название способности
    int power;//Сила способности
    int cooldown;//Перезарядка способности
} Ability;

//Функция создания персонажа
void initCharacter(Player* character, const char* name, int health, int level, int attack_power) {
    strcpy(character->name, name); //Копируем имя персонажа в структуру
    character->health = health;//Устанавливаем здоровье
    character->level = level;//Устанавливаем уровень
    character->attack_power = attack_power;//Устанавливаем силу персонажа
}

//Функция для добавления предметов в локацию
void addItemToLocation(Location* loc, Item item) {
    if (loc->itemCount < 10) { // Проверяем, есть ли место для нового предмета
        loc->items[loc->itemCount++] = item; // Добавляем предмет и увеличиваем счётчик
    }
}

//Фунция вывода информации о локации
void printLocation(const Location* loc) {
    printf("Локация: %s\n", loc->description);
    printf("Предметы в локации:\n");
    for (int i = 0; i < loc->itemCount; i++) {
        printf("-%s (Стоимость: %d)\n", loc->items[i].name, loc->items[i].value);
    }
}
//Функция вывода информации о персонаже
void printPlayerInfo(const Player* player) {
    printf("Персонаж: %s\n", player->name);
    printf("Здоровье: %d\n", player->health);
    printf("Уровень: %d\n", player->level);
    printf("Сила атаки: %d\n", player->attack_power);
}
*/

int main()
{
	setlocale(LC_ALL, "RU");

    
    return 0;
}
