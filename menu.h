#pragma once
#include "keeper.h"
#include "ship.h"
#include "submarine.h"
#include "boats.h"
#include "sailboat.h"
#include <iostream>

using namespace std;

template <typename T> // T - тип, указанный в параметре шаблона
void menu(T& obj, string line) {
    int c;
    int i;
    bool flag = true;
    setlocale(LC_ALL, "Russian");

    while (flag) {
        system("cls");
        cout << "Выберите действие: " << endl << endl;
        cout << "1 - Добавить объект" << endl;
        cout << "2 - Удалить объект" << endl;
        cout << "3 - Вывод на экран" << endl;
        cout << "4 - Изменить данные" << endl;
        cout << "5 - Сохранить в файл" << endl;
        cout << "6 - Взять из файла" << endl;
        cout << "7 - Выход" << endl << endl;
        cout << "Выберите действие: ";
        cin >> c;

        if (cin.fail() || c < 0 || c > 7) { // Проверка на правильный ввод
            c = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        system("cls");
        switch (c) {
        case 1:
            obj.push(); // Добавление объекта
            system("pause");
            break;
        case 2: 
            obj.display();
            cout << "Выберите для удаления: ";
            cin >> i;
            obj.pop(i); // Удаление объекта
            system("pause");
            break;
        case 3:
            obj.display(); // Вывод объекта на экран
            system("pause");
            break;
        case 4:
            obj.display();
            cout << "Выберите для изменения: ";
            cin >> i;
            obj.edit(i); // Редактирование объекта
            system("pause");
            break;
        case 5:
            obj.write(line); // Запись объекта в файл
            system("pause");
            break;
        case 6:
            obj.read(line); // Считывание объекта из файла
            system("pause");
            break;
        case 7:
            flag = false; // Выход
            break;
        default:
            cout << "Введите от 1 до 7:" << endl << endl;
            system("pause");
            break;
        }
    }
}
