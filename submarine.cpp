#include "submarine.h"
#include <iostream>
#include <string>

using namespace std;

Submarine::Submarine() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора по умолчанию (Подводная лодка)" << endl << endl;
    lenght = 0;
    weight = 0;
    crew = 0;
    time_underwater = 0;
    speed_underwater = 0;
    armament = "";
}

Submarine::Submarine(const Submarine& other) {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора копирования (Подводная лодка)" << endl << endl;
    *this = other;
}

Submarine::~Submarine() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов деструктора (Подводная лодка)" << endl << endl;
}

void Submarine::setVal() {
    cin >> *this;
}

Submarine& Submarine::operator=(const Submarine& other) {
    this->lenght = other.lenght;
    this->weight = other.weight;
    this->crew = other.crew;
    this->time_underwater = other.time_underwater;
    this->speed_underwater = other.speed_underwater;
    this->armament = other.armament;
    return *this;
}

ofstream& operator<<(ofstream& fout, Submarine& obj) { // Функция записи в файл объекта
    fout << obj.lenght << " " << endl;
    fout << obj.weight << " " << endl;
    fout << obj.crew << " " << endl;
    fout << obj.time_underwater << " " << endl;
    fout << obj.speed_underwater << " " << endl;
    fout << obj.armament << " " << endl;
    fout << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, Submarine& obj) { // Функция чтения файла объекта
    fin >> obj.lenght 
        >> obj.weight
        >> obj.crew
        >> obj.time_underwater
        >> obj.speed_underwater
        >> obj.armament;
    return fin;
}

ostream& operator<<(ostream& out, Submarine& obj) { // Функция вывода на экран данных объекта
    setlocale(LC_ALL, "Russian");
    out << "Длина: " << obj.lenght << endl;
    out << "Ширина: " << obj.weight << endl;
    out << "Экипаж: " << obj.crew << endl;
    out << "Время непрерывного пребывания под водой: " << obj.time_underwater << endl;
    out << "Максимальная подводная скорость: " << obj.speed_underwater << endl; 
    out << "Вооружение: " << obj.armament << endl;
    return out;
}

istream& operator>>(istream& in, Submarine& obj) { // Функция ввода данных объекта
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные:" << endl << endl;
    while (1) {
        cout << "Длина: ";
        cin >> obj.lenght;
        if (cin.fail() || obj.lenght < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while (1) {
        cout << "Ширина: ";
        cin >> obj.weight;
        if (cin.fail() || obj.weight < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while (1) {
        cout << "Экипаж: ";
        cin >> obj.crew;
        if (cin.fail() || obj.crew < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while (1) {
        cout << "Время непрерывного пребывания под водой: ";
        cin >> obj.time_underwater;
        if (cin.fail() || obj.time_underwater < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while (1) {
        cout << "Максимальная подводная скорость: ";
        cin >> obj.speed_underwater;
        if (cin.fail() || obj.speed_underwater < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    cout << "Вооружение: ";
    getchar();
    getline(cin, obj.armament);
    return in;
}
