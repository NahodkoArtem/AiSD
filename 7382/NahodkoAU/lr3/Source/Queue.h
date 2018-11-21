#include <iostream>
#include <string.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>

class Queue {                                   //Класс очередь
 public:
        Queue();                                //Инициализация очереди
        void enqueue(const char&);              //Добавление элемента в очередь
        char dequeue();                         //Удаление первого элемента из очереди
        int isEmpty();                          //Проверка очереди на пустоту
        int isFull();                           //Проверка очереди на переполненность
 private:
        static const int maxSize=300;           //Максимальный размер очереди
        char arr[maxSize];                      //Массив для хранения найденных чисел
        int start, size;                        //Начало и конец очереди
};
