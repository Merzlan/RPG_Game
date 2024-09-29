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


int main()
{
	setlocale(LC_ALL, "RU");

    
    return 0;
}
