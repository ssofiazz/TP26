#include <iostream>
#include "keeper.h"
#include "ship.h"
#include "submarine.h"
#include "boats.h"
#include "menu.h"
#include "sailboat.h"

/*Класс Корабль хранит данные о подводных лодках, парусниках и катерах.
Для подводной лодки определено: длина, ширина, экипаж, время непрерывного
пребывания под водой, максимальная подводная скорость, максимальная
подводная скорость, вооружение.
Для парусника определено: тип парусника, название, мирный или военный,
длина корпуса, скорость перемещения, экипаж.
Для катера определено: назначение, материал корпуса, ходовые качества,
скорость и количество людей, которые могут находится на борту.
*/

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper <Submarine> submarine;
    Keeper <boats> boats;
    Keeper <Sailboat> sailboat;
    int button;
    bool flag = true; // Для проверки логических условий (флаг состояний), как выключатель - ВКЛ и ВЫКЛ

    while (flag) {
        system("cls"); // Ждет ввода, чтобы окно консоли не закрылось
        cout << "Меню: " << endl << endl;
        cout << "1 - Подводная лодка" << endl;
        cout << "2 - Парусник" << endl;
        cout << "3 - Катер" << endl;
        cout << "4 - Выход из программы" << endl << endl;
        cout << "Выберите пункт: ";
        cin >> button;

        if (cin.fail()) { // Проверка на правильный ввод
            button = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (button) {
        case 1:
            menu(submarine, "submarine.txt"); // Вызов меню (Мебель)
            break;
        case 2:
            menu(sailboat, "sailboat.txt"); // Вызов меню (Работник)
            break;
        case 3:
            menu(boats, "boats.txt"); // Вызов меню (Машина)
            break;
        case 4:
            flag = false; // Выход из программы
            cout << "\nКонец" << endl;
            break;
        default:
            cout << endl << "Некорректные данные, введите заново!" << endl << endl; // Проверка на правильный ввод
            system("pause");
            break;
        }
    }
    return 0;
}
