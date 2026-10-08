#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

template <class T>
class Keeper {
    T* ptr;
    int size;
public:
    Keeper();
    ~Keeper();
    void push(); // Функция добавления нового объекта
    void pop(int); // Функция удаления объекта
    void write(string); // Функция записи объекта в файл
    void read(string); // Функция считывания объекта из файла
    void display(); // Функция вывода объекта на экран
    void edit(int); // Функция редактирования объекта
};

template<class T>
Keeper<T>::Keeper() { // Конструктор
    cout << "Вызов конструктора по умолчанию (Хранитель)" << endl << endl;
    ptr = nullptr;
    size = 0;
}

template<class T>
Keeper<T>::~Keeper() { // Деструктор
    cout << "Вызов деструктора (Хранитель)" << endl << endl;
    delete[] ptr;
}

template<class T>
void Keeper<T>::push() { // Функция добавления нового объекта
    T* tmp = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        tmp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = tmp;
    cin >> ptr[size];
    ++size;
    cout << endl << endl << "Новый объект добавлен" << endl << endl;
}

template <class T>
void Keeper<T>::pop(int num) { // Функция удаления объекта
    try {
        if (size == 0) {
            exception error("Пусто");
            throw error;
        }
        if (num < 0 || num >= size) {
            exception bug("Неверный номер");
            throw bug;
        }
        T* tmp = new T[size - 1];
        ptr[num] = ptr[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            tmp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = tmp;
        --size;
        cout << endl << endl << "Объект удален" << endl << endl;
    }
    catch (exception& error) {
        cout << error.what() << endl << endl;
    }
}

template<class T>
void Keeper<T>::display() { // Функция вывода объекта на экран
    if (size == 0) {
        cout << "Пусто" << endl << endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            cout << ptr[i] << endl;
        }
    }
}

template<class T>
void Keeper<T>::edit(int change) { // Функция редактирования объекта
    try {
        if (size == 0) {
            exception error("Пусто");
            throw error;
        }
        if (change < 0 || change >= size) {
            exception bug("Неверный номер");
            throw bug;
        }
        cin >> ptr[change];
    }
    catch (exception& bug) {
        cout << bug.what() << endl << endl;
    }
}

template<class T>
void Keeper<T>::write(string s) { // Функция записи объекта в файл
    ofstream fout(s, ios::out);
    try {
        if (size == 0) {
            exception error("Пусто");
            throw error;
        }
        fout << size << endl;
        for (int i = 0; i < size; ++i) {
            fout << ptr[i] << endl;
        }
        fout.close();
        cout << "Запись прошла успешно" << endl << endl;
    }
    catch (exception& error) {
        cout << error.what() << endl;
    }
}

template<class T>
void Keeper<T>::read(string s) { // Функция считывания объекта из файла
    delete[] ptr;
    ifstream fin(s, ios::in);
    fin >> size;
    ptr = new T[size];
    for (int i = 0; i < size; ++i) {
        fin >> ptr[i];
    }
    fin.close();
    cout << "Прочитано успешно" << endl << endl;
}
