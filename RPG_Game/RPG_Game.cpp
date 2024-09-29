#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char name[50]; //Имя персонажа
    int health; //Значение здоровья персонажа
    int level; //Уровень персонажа
    int attack_power; //Значение силы персонажа
    struct Location* current_location; //Текущее местоположение персонажа
    struct Item* inventory[20];//Массив, в котором хранятся вещи персонажа
} Player;//Название структуры

typedef struct {
    char name[50];//Имя сущности
    int health;//Значение здоровья сущности
    int level;//Уровень сущности
    int attack_power;//Значение силы сущности
} Enemy;//Название структуры

int main()
{
	setlocale(LC_ALL, "RU");

}
