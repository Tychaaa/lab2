#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECORDS 100
#define MAX_EMPLOYEE 20
#define MAX_ORDER 10

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

int numRecords;
int numEmployees;

// Структура для виниловой пластинки
typedef struct {
    string albumName;   // Название альбома
    string artist;      // Исполнитель
    int year;           // Год выпуска
    string genre;       // Жанр
    float price;        // Цена
    int quantity;       // Количество в наличии
} VinylRecord;

// Структура для человека
typedef struct {
    string firstName;   // Имя
    string lastName;    // Фамилия
} Human;

// Структура для клиента
typedef struct {
    Human person;       // Используем структуру Human для представления клиента
    float money;        // Кол/во денег
    string address;     // Адрес доставки
} Customer;

// Структура для сотрудника магазина
typedef struct {
    Human person;       // Используем структуру Human для представления сотрудника
    string position;    // Должность
    float salary;       // Зарплата
} Employee;

// Структура для заказа
typedef struct {
    int orderNumber;    // Номер заказа
    string orderDate;   // Дата заказа
    Employee employee;  // Сотрудник магазина
    Customer customer;  // Клиент
    VinylRecord orderedRecords[MAX_ORDER]; // Список заказанных виниловых пластинок
    int quantityOrdered[MAX_ORDER];
    float totalCost;    // Общая стоимость заказа
} Order;

// Структура для магазина
typedef struct {
    string storeName;    // Название магазина
    string storeAddress; // Адрес магазина
    VinylRecord vinylRecordsInStore[MAX_RECORDS]; // Список имеющихся в магазине виниловых пластинок
    Employee employeesInStore[MAX_EMPLOYEE];      // Список сотрудников магазина
} Store;

// Функция для инициализации и ввода информации о виниловой пластинке
void inputVinylRecord(VinylRecord& record) {
    cin.ignore();
    cout << endl << "Введите название альбома: ";
    getline(cin, record.albumName);

    cout << "Введите исполнителя: ";
    getline(cin, record.artist);

    cout << "Введите год выпуска: ";
    cin >> record.year;

    cout << "Введите жанр: ";
    cin.ignore(); // Очистка буфера перед считыванием строки
    getline(cin, record.genre);

    cout << "Введите цену: ";
    cin >> record.price;

    cout << "Введите количество в наличии: ";
    cin >> record.quantity;

    cout << endl;
}

// Функция для вывода информации о виниловой пластинке
void outputVinylRecord(const VinylRecord& record) {
    //cout << "Информация о виниловой пластинке:" << endl;
    cout << "Название альбома: " << record.albumName << endl;
    cout << "Исполнитель: " << record.artist << endl;
    cout << "Год выпуска: " << record.year << endl;
    cout << "Жанр: " << record.genre << endl;
    cout << "Цена: " << record.price << endl;
    cout << "Количество в наличии: " << record.quantity << endl;
    cout << endl;
}

// Функция для инициализации и ввода информации о клиенте
void inputCustomer(Customer& customer) {
    cout << "Введите информацию о клиенте:" << endl;

    cout << "Введите имя клиента: ";
    cin >> customer.person.firstName;

    cout << "Введите фамилию клиента: ";
    cin >> customer.person.lastName;

    cout << "Введите количества денег клиента: ";
    cin >> customer.money;
    
    cout << "Введите адрес доставки клиента: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, customer.address);

    cout << endl;
}

// Функция для вывода информации о клиенте
void outputCustomer(const Customer& customer) {
    cout << "Информация о клиенте:" << endl;
    cout << "Имя клиента: " << customer.person.firstName << " " << customer.person.lastName << endl;
    cout << "Количество денег клиента: " << customer.money << endl;
    cout << "Адрес доставки: " << customer.address << endl;
    cout << endl;
}

// Функция для инициализации и ввода информации о сотруднике магазина
void inputEmployee(Employee& employee) {
    cin.ignore();
    cout << "Введите имя сотрудника: ";
    cin >> employee.person.firstName;

    cout << "Введите фамилию сотрудника: ";
    cin >> employee.person.lastName;

    cout << "Введите должность сотрудника: ";
    cin.ignore();
    getline(cin, employee.position);

    cout << "Введите зарплату сотрудника: ";
    cin >> employee.salary;

    cout << endl;
}

// Функция для вывода информации о сотруднике магазина
void outputEmployee(const Employee& employee) {
    //cout << "Информация о сотруднике:" << endl;
    cout << "Имя сотрудника: " << employee.person.firstName << " " << employee.person.lastName << endl;
    cout << "Должность: " << employee.position << endl;
    cout << "Зарплата: " << employee.salary << endl;
    cout << endl;
}

// Функция для инициализации и ввода информации о магазине
void inputStore(Store& store) {
    cout << "Введите информацию о магазине:" << endl;

    cout << "Введите название магазина: ";
    cin >> store.storeName;

    cout << "Введите адрес магазина: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, store.storeAddress);

    // Ввод информации о виниловых пластинках в магазине
    cout << "Введите количество имеющихся виниловых пластинок: ";
    //int numRecords;
    cin >> numRecords;
    cout << endl;
    for (int i = 0; i < numRecords; i++) {
        cout << "Виниловая пластинка #" << i + 1 << endl;
        inputVinylRecord(store.vinylRecordsInStore[i]);
    }

    // Ввод информации о сотрудниках магазина
    cout << "Введите количество сотрудников магазина: ";
    //int numEmployees;
    cin >> numEmployees;
    cout << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        inputEmployee(store.employeesInStore[i]);
    }

    cout << endl;
}

// Функция для вывода информации о магазине
void outputStore(const Store& store) {
    //system("cls");
    cout << "Информация о магазине:" << endl;
    cout << "Название магазина: " << store.storeName << endl;
    cout << "Адрес магазина: " << store.storeAddress << endl;

    cout << endl;

    // Вывод информации о виниловых пластинках в магазине
    cout << "Информация о виниловых пластинках в магазине:" << endl;
    for (int i = 0; i < MAX_RECORDS && !store.vinylRecordsInStore[i].albumName.empty(); i++) {
        cout << "Виниловая пластинка #" << i + 1 << ":" << endl;
        outputVinylRecord(store.vinylRecordsInStore[i]);
    }

    // Вывод информации о сотрудниках магазина
    cout << "Информация о сотрудниках магазина:" << endl;
    for (int i = 0; i < MAX_EMPLOYEE && !store.employeesInStore[i].person.firstName.empty(); i++) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        outputEmployee(store.employeesInStore[i]);
    }
}

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //VinylRecord vinyl1;
    //Customer customer1;
    //Employee employee1;
    Store store1;

    inputStore(store1);
    outputStore(store1);

    /*
    Order order1;
    initializeOrder(order1, 1, "2023-09-19", employee1, customer1);

    // Добавление виниловой пластинки в заказ
    addRecordToOrder(order1, vinyl1, 3);

    // Вывод информации о заказе
    printOrder(order1);
    */
    return 0;
}

