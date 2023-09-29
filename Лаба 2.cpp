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
    cout << "Имя сотрудника: " << employee.person.firstName << " " << employee.person.lastName << endl;
    cout << "Должность: " << employee.position << endl;
    cout << "Зарплата: " << employee.salary << endl;
    cout << endl;
}

// Функция для инициализации и ввода информации о магазине
void inputStore(Store& store) {
    cout << "Введите информацию о магазине:" << endl;

    cout << "Введите название магазина: ";
    getline(cin, store.storeName);

    cout << "Введите адрес магазина: ";
    getline(cin, store.storeAddress);

    // Ввод информации о виниловых пластинках в магазине
    cout << "Введите количество имеющихся виниловых пластинок: ";
    cin >> numRecords;
    cout << endl;
    for (int i = 0; i < numRecords; i++) {
        cout << "Виниловая пластинка #" << i + 1 << endl;
        inputVinylRecord(store.vinylRecordsInStore[i]);
    }

    // Ввод информации о сотрудниках магазина
    cout << "Введите количество сотрудников магазина: ";
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
    cout << "Информация о магазине:" << endl;
    cout << "Название магазина: " << store.storeName << endl;
    cout << "Адрес магазина: " << store.storeAddress << endl;

    cout << endl;

    // Вывод информации о виниловых пластинках в магазине
    cout << "Информация о виниловых пластинках в магазине:" << endl;
    for (int i = 0; i < MAX_RECORDS && !store.vinylRecordsInStore[i].albumName.empty(); i++) {
        cout << endl << "Виниловая пластинка #" << i + 1 << ":" << endl;
        outputVinylRecord(store.vinylRecordsInStore[i]);
    }

    cout << endl;

    // Вывод информации о сотрудниках магазина
    cout << "Информация о сотрудниках магазина:" << endl;
    for (int i = 0; i < MAX_EMPLOYEE && !store.employeesInStore[i].person.firstName.empty(); i++) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        outputEmployee(store.employeesInStore[i]);
    }
}

// Функция для выбора существующего сотрудника
void chooseEmployee(Employee employees[], int numEmployees, Employee& selectedEmployee) {
    bool isValidChoice = false;

    for (int i = 0; i < numEmployees; i++) {
        cout << i + 1 << ". " << employees[i].person.firstName << " " << employees[i].person.lastName << endl;
    }

    do {
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= numEmployees) {
            selectedEmployee = employees[choice - 1];
            isValidChoice = true; // Устанавливаем флаг, если выбор сотрудника корректен
        }
        else {
            cout << "Некорректный выбор. Пожалуйста, выберите сотрудника из списка." << endl;
        }
    } while (!isValidChoice); // Повторяем цикл, пока выбор не станет корректным
}

// Функция для выбора существующей виниловой пластинки
void chooseVinylRecord(VinylRecord records[], int numRecords, VinylRecord& selectedRecord) {
    bool isValidChoice = false;

    for (int i = 0; i < numRecords; i++) {
        cout << i + 1 << ". " << records[i].albumName << " - " << records[i].artist << " (" << records[i].quantity << "шт." << ")" << endl;
    }

    do {
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= numRecords) {
            selectedRecord = records[choice - 1];
            isValidChoice = true;
        }
        else {
            cout << "Некорректный выбор." << endl;
        }
    } while (!isValidChoice);
}

// Функция для ввода информации о заказе
void inputOrder(Order& order, Store& store) {
    cout << "Введите номер заказа: ";
    cin >> order.orderNumber;

    cout << "Введите дату заказа: ";
    cin >> order.orderDate;

    cout << "Выберите сотрудника, обслуживающего заказ:" << endl;
    chooseEmployee(store.employeesInStore, numEmployees, order.employee);

    cout << "Введите информацию о клиенте, оформляющем заказ:" << endl;
    inputCustomer(order.customer);

    cout << "Введите количество заказанных виниловых пластинок: ";
    int numOrderedRecords;
    cin >> numOrderedRecords;
    cout << "Выберите виниловые пластинки для заказа:" << endl;
    for (int i = 0; i < numOrderedRecords; i++) {
        cout << "Виниловая пластинка #" << i + 1 << ":" << endl;
        chooseVinylRecord(store.vinylRecordsInStore, numRecords, order.orderedRecords[i]);
        cout << "Введите количество заказанных экземпляров: ";
        cin >> order.quantityOrdered[i];
    }

    // Вычисляем общую стоимость заказа
    order.totalCost = 0;
    for (int i = 0; i < numOrderedRecords; i++) {
        order.totalCost += order.orderedRecords[i].price * order.quantityOrdered[i];
    }

    cout << endl;
}

// Функция для вывода информации о заказе
void outputOrder(const Order& order) {
    cout << "Информация о заказе:" << endl;

    cout << "Номер заказа: " << order.orderNumber << endl;

    cout << "Дата заказа: " << order.orderDate << endl;

    cout << "Сотрудник магазина: " << order.employee.person.firstName << " " << order.employee.person.lastName << " (" << order.employee.position << ")" << endl;

    cout << "Клиент: " << order.customer.person.firstName << " " << order.customer.person.lastName << endl;

    cout << "Список заказанных виниловых пластинок:" << endl;
    for (int i = 0; i < 10; i++) {
        if (!order.orderedRecords[i].albumName.empty()) {
            cout << order.orderedRecords[i].albumName << " - " << order.quantityOrdered[i] << " шт." << endl;
        }
    }

    cout << "Общая стоимость заказа: " << order.totalCost << endl;

    cout << endl;
}

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t~~Программа по реализации АТД на языке C и C++~~\n";
    cout << endl;

    Store store1;
    Order order1;

    inputStore(store1);
    outputStore(store1);

    inputOrder(order1, store1);
    outputOrder(order1);

    return 0;
}

