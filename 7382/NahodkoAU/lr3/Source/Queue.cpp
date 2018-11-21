#include <iostream>
#include <string.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "Queue.h"

Queue::Queue() : size(0), start(0)
{}

void Queue::enqueue(const char &a)
{
        if (isFull()!=0)                        //Если очередь не полна, занчит можем вставить элемент
        {
                arr[(start+size)]=a;            //Ставим на ближайшее свободное место, после этого увеличиваем размер очереди на одну единицу
                ++size;
        } else
        {
                printf("Очередь переполнена!\n");
                exit(1);
        }
}

char Queue::dequeue()
{
        if (isEmpty()!=0)                       //Если очередь не пуста, значит можем достать из неё элемент
        {
                char b = arr[start];            //Присвоим b первый элемент очереди, который будем извлекать
                start=(++start);                //Теперь первым элементом станет второй элемент очереди
                --size;                         //Уменьшаем размер очереди и возвращаем элемент b
                return b;
        } else {
                printf("Стек пуст! Невозможно вернуть элемент!\n");
                exit(1);
        }
}

int Queue::isEmpty()
{
        if (size==0) return 0;                  //Если размер равен 0
        return 1;
}

int Queue::isFull()
{
        if(size==maxSize) return 0;             //Если размер равен максиммально возможному
        return 1;
}
