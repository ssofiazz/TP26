#include "boats.h"
#include <iostream>
#include <string>

using namespace std;

boats::boats() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора по умолчанию (Катер)" << endl << endl;
    purpose = "";
    housing_material = "";
    driving_qualities = "";
    speed = 0;
    capacity = 0;
}

boats::boats(const boats& other) {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов конструктора копирования (Катер)" << endl << endl;
    *this = other;
}

boats::~boats() {
    setlocale(LC_ALL, "Russian");
    cout << "Вызов деструктора (Катер)" << endl << endl;
}

void boats::setVal() {
    cin >> *this;
}

boats& boats::operator=(const boats& other) {
    this->purpose = other.purpose;
    this->housing_material = other.housing_material;
    this->driving_qualities = other.driving_qualities;
    this->speed = other.speed;
    this->capacity = other.capacity;
    return *this;
}

ofstream& operator<<(ofstream& fout, boats& obj) { // Функция записи в файл объекта
    fout << obj.purpose << " " << endl;
    fout << obj.housing_material << " " << endl;
    fout << obj.driving_qualities << " " << endl;
    fout << obj.speed << " " << endl;
    fout << obj.capacity << " " << endl;
    fout << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, boats& obj) { // Функция чтения файла объекта
    fin >> obj.purpose
        >> obj.housing_material 
        >> obj.driving_qualities
        >> obj.speed
        >> obj.capacity;
    return fin;
}

ostream& operator<<(ostream& out, boats& obj) { // Функция вывода на экран данных объекта
    setlocale(LC_ALL, "Russian");
    out << "Назначение: " << obj.purpose << endl;
    out << "Материал корпуса: " << obj.housing_material << endl;
    out << "Ходовые качества: " << obj.driving_qualities << endl;
    out << "Максимальная скорость: " << obj.speed << endl;
    out << "Максимальное количество людей, которые могут находиться на борту: " << obj.capacity << endl;
    return out;
}

istream& operator>>(istream& in, boats& obj) { // Функция ввода данных объекта
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные:" << endl << endl;
    cout << "Назначение:";
    getchar();
    getline(cin, obj.purpose);
    cout << "Материал корпуса: ";
    cin >> obj.housing_material;
    cout << "Ходовые качества: ";
    getchar();
    getline(cin, obj.driving_qualities);
    while (1) {
        cout << "Максимальная скорость: ";
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
        cout << "Максимальное количество людей, которые могут находиться на борту: ";
        cin >> obj.capacity;
        if (cin.fail() || obj.capacity < 0) {
            cout << "Некорректные данные, введите заново!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    return in;
}
