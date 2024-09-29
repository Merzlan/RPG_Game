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

int main()
{
	setlocale(LC_ALL, "RU");

    
    return 0;
}
