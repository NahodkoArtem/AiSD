#include <iostream>
#include <string.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "Queue.h"
#define COL "\033[0;33m"
#define COL2 "\033[0;34m"
#define COL3 "\033[0;35m"
#define NONE "\033[0m"

using namespace std;

//Функия, которая выполняет вывод цифр из очереди на консоль в конец строки и запись их в текстовый файл выхода
void print_num(Queue &q_num, ofstream &fout, int action, string s_for_out)
{
	char c;
	while (q_num.isEmpty()!=0)		//Если очередь текущая очередь цифр не пуста
	{
		c = q_num.dequeue();		//Достанем из неё первый элемент и выведем его в конец строки в консоли и текстового файла
		fout << c;			//Вывод элемента в файл
		if(action!=1) cout << c;	//Вывод цифры на консоль, если флаг действия не равен 1
		if(action==1)			//Если флаг действия равен 1, то будем производить промежуточные выводы результатов
                {
                  s_for_out.append(1, c);	//С помощьюфункции append дозаписываем символ c в конец строки s_for_out
                  cout << s_for_out << endl;
                }
       }
       fout << endl;
       cout << endl;
}

int main()
{
	Queue q_num;				//Очередь цифр, извлечённых из первоначальной строки
	string s;				//Строка которую будем преобразовывать
	int action=0;				//Флаг действия
	string s_for_out;			//Строка для записи промежуточных результатов
	ifstream fin("input.txt");		//Файл содержимое которого изменяем
	ofstream fout("output.txt");		//Файл в который записываем результат работы программы
        cout << "Хотите ли вы видеть промежуточные выводы программы? 1 - да; другой символ - нет" << endl;
        cin >> action;
	for (int i = 0; (getline(fin, s)); i++)			//С помощью функции getline разбиваем содержимое файла input.txt на строки для обработки
	{
		printf("%sСтрока №%d:%s\n", COL, i+1, NONE);
		printf("%sСтрока до измененеия:%s\n", COL2, NONE);
		cout << s << endl;
		printf("%sСтрока после изменения:%s\n", COL3, NONE);
		s_for_out="";
		for (int j = 0; j < s.length(); j++)		//Цикл прохода строки для её поэлементной проверки
		{
			if (((int)s[j]>47) && ((int)s[j]<58))	//Если номеру текущего символа соотвествует цифра согласно таблице ASCII
			{
			 q_num.enqueue(s[j]);			//Добавляем эту цифру в очередь
                        }
			else
			{
				if(action!=1) cout << s[j];	//Если флаг действия не 1, то выводим на консоль элемент
				fout << s[j];			//Запись элемента в файл
				if(action==1)			//Если флаг действия равен 1, то будем делать промежуточные выводы
				{
 				  s_for_out.append(1, s[j]);	//С помощью функции append присоединяем элемент s[j] в конец строки s_for_out
				  cout << s_for_out << endl;
				}
			}
		}
		print_num(q_num, fout, action, s_for_out);		//Передаём очереди цифр в функцию print_num для их вывода
	}
}
