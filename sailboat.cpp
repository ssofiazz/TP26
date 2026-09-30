#include "sailboat.h"
#include <iostream>
#include <string>

using namespace std;

Sailboat::Sailboat() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора по умолчанию (Парусник)" << endl << endl;
    type = "";
    name = "";
    peaceful_military = "";
    body_length = 0;
    speed = 0;
    crew = 0;
}

Sailboat::Sailboat(const Sailboat& other) {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора копирования (Парусник)" << endl << endl;
    *this = other;
}

Sailboat::~Sailboat() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов деструктора (Парусник)" << endl << endl;
}

void Sailboat::setVal() {
    cin >> *this;
}

Sailboat& Sailboat::operator=(const Sailboat& other) {
    this->type = other.type;
    this->name = other.name;
    this->peaceful_military = other.peaceful_military;
    this->body_length = other.body_length;
    this->speed = other.speed;
    this->crew = other.crew;
    return *this;
}

ofstream& operator<<(ofstream& fout, Sailboat& obj) { // Функция записи в файл объекта
    fout << obj.type << " " << endl;
    fout << obj.name << " " << endl;
    fout << obj.peaceful_military << " " << endl;
    fout << obj.body_length << " " << endl;
    fout << obj.speed << " " << endl;
    fout << obj.crew << " " << endl;
    fout << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, Sailboat& obj) { // Функция чтения файла объекта
    fin >> obj.type
        >> obj.name
        >> obj.peaceful_military
        >> obj.body_length
        >> obj.speed
        >> obj.crew;
    return fin;
}

ostream& operator<<(ostream& out, Sailboat& obj) { // Функция вывода на экран данных объекта
    setlocale(LC_ALL, "Russian");
    out << "Тип парусника: " << obj.type << endl;
    out << "Название: " << obj.name << endl;
    out << "Мирный или военный: " << obj.peaceful_military << endl;
    out << "Длина корпуса: " << obj.body_length << endl << endl;
    out << "Скорость перемещения: " << obj.speed << endl << endl;
    out << "Экипаж: " << obj.crew << endl << endl;
    return out;
}

istream& operator>>(istream& in, Sailboat& obj) { // Функция ввода данных объекта
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные:" << endl << endl;
    cout << "Тип парусника: ";
    cin >> obj.type;
    cout << "Название: ";
    cin >> obj.name;
    cout << "Мирный или военный: ";
    cin >> obj.peaceful_military;
    while (1) {
        cout << "Длина корпуса: ";
        cin >> obj.body_length;
        if (cin.fail() || obj.body_length < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    while (1) {
        cout << "Скорость перемещения: ";
        cin >> obj.speed;
        if (cin.fail() || obj.speed < 0) {
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
    return in;
}
