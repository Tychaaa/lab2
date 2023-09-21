#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

using namespace std; // Добавлено использование namespace std

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
    Store* store;       // Магазин, в котором работает
} Employee;

// Структура для заказа
typedef struct {
    int orderNumber;    // Номер заказа
    string orderDate;   // Дата заказа
    Employee employee;  // Сотрудник магазина
    Customer customer;  // Клиент
    VinylRecord orderedRecords[10]; // Максимум 10 заказанных пластинок
    //int quantityOrdered[10];
    float totalCost;    // Общая стоимость заказа
} Order;

// Структура для магазина
typedef struct {
    string storeName;
    string storeAddress;
    VinylRecord vinylRecordsInStore[100]; // Максимум 100 пластинок
    Employee employeesInStore[20]; // Максимум 20 сотрудников
} Store;

int main()
{

}

