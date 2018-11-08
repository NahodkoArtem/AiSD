#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "l_intrfc.h"
#include <clocale>
#define COL "\033[0;31m"
#define COL1 "\033[0;32m"
#define COL2 "\033[0;33m"
#define COL3 "\033[0;34m"
#define COL4 "\033[0;35m"
#define NONE "\033[0m"

using namespace std;
using namespace h_list;

//Рекурсивная функция замены в исходном списке задаваемый элемент "a" на "b".
//В качестве аргументов принимает: список, задаваемый элемент "a", "b" и копию списка для вывода промежуточный результатов.
void Swap(lisp list, const base &a, const base &b, lisp s)
{
 if (isNull(list))             //Проверяем список на пустоту
   return;
 else if (isAtom(list))
 {
  if(list->node.atom == a)     //Входим в этот блок, если текущий элемент надо заменить
  {
  list->node.atom = b;         //Заменяемый элемент
  write_lisp(s);               //Вывод промежуточных результатов
  cout << endl;
  }
 }
 else                          //Перебор элементов
 {
    Swap(head(list), a, b, s);
    Swap(tail(list), a, b, s);
 }
 return;
}

int act_to_perform()
{
 while (true)
 {
  int x;                      //Показатель действия
  printf("Выберите действие для выполнения:\n%s1 - ввести список;%s\n%s2 - удалить список;%s\n%s3 - осущетвить замену элементов;%s\n%s4 - вывести список на экран%s\n%s5 -выйти из программы.%s\n", COL, NONE, COL1, NONE, COL2, NONE, COL3, NONE, COL4, NONE);
  cin >> x;
   if ((x<1)|| (x>5))         //Проверка показателя на корректность
   {
    printf("Некорректно введённые данные, попробуйте ещё раз!\n");
    continue;
   }
  return x;
 }
}

int main ( )
{
 int x;
 char a, b;                   //Изменяемые элементы
 lisp s;
 int act, flag;
 printf("Выберите действие для выполнения:\n%s1 - автоматическая замена элементов в файле.%s\n%s2 - ручная работа с файлом%s\n%s3 - выход из программы.%s\n", COL, NONE, COL1, NONE, COL2, NONE);
 cin >> act;
 switch (act)
 {
  case 1:
        cin >> a;
        cin >> b;
        cout << "Замена " << a << " на " << b <<".Результат: " << endl;
        while (s!=NULL)
        {
          read_lisp (s);
	  write_lisp(s);
          cout << endl;
          Swap(s, a, b, s);
          cout << endl;
          destroy (s);        //Удаления списка
          s=NULL;
        }
        break;
  case 2:
        while (true)
        {
          x=act_to_perform();
	  switch (x)
	  {
            case 1:
                  cout << "Введите список: ";
                  read_lisp(s);
                  break;
            case 2:
                  destroy(s);
		  s = NULL;
                  cout << "Cписок удален успешно!" << endl;
                  break;
            case 3:
                  cout << "Выберите элемент для замены: ";
                  cin >> a;
                  cout << "Выберите подставляемый элемент: ";
                  cin >> b;
                  Swap(s, a, b, s);
                  break;
            case 4:
		  if (isNull(s))
		    cout << "Список пуст!" << endl;
		  else
                  {
		    cout << "Cписок: ";
                    write_lisp (s);
            	    cout << endl;
		  }
	          break;
            case 5:
                  return 0;
          }
       cout << "Хотите продолжить работу с программой? 1-да; 0-нет.";
       cin >> flag;
       cout << endl;
       if (flag == 0) return 0;
     }
    break;
  }
}
