#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Структура персонажа
typedef struct {
    char name[50]; //Имя персонажа
    int health; //Значение здоровья персонажа
    int level; //Уровень персонажа
    int attack_power; //Значение силы персонажа
} Player;

//Структура существа
typedef struct {
    char name[50];//Имя сущности
    int health;//Значение здоровья сущности
    int attack_power;//Значение силы сущности
} Enemy;

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

//Фунция вывода содержимого инвентаря
void printInventory(const Inventory* inv) {
    printf("Инвентарь:\n");
    for (int i = 0; i < inv->itemCount; i++) {
        printf(" - %s (Количество: %d)\n", inv->items[i].name, inv->items[i].value);
    }
}



int main()
{
	setlocale(LC_ALL, "RU");

    
    return 0;
}
