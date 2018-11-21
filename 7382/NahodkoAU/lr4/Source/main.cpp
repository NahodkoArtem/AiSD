#include <iostream>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include "BinTree.h"
#include <string>
#include <stdio.h>
#define RED "\033[0;31m"
#define COL "\033[0;34m"
#define COL2 "\033[0;32m"
#define NONE "\033[0m"
using namespace std;
using namespace binTree_modul;

void displayBT(binTree b, int n) //функция вывода дерева
{	// n  － уровень узла
	if (b != NULL) {
		cout << ' ' << RootBT(b);
		if (!isNull(Right(b))) {displayBT (Right(b),n+1);}
		else cout << endl; // вниз
		if(!isNull(Left(b))) {
			for (int i=1;i<=n;i++) cout << "  "; // вправо
			displayBT(Left(b), n + 1);
		}
	}
	else {};
}

void printKLP (binTree b)  //функция вывода узлов дерева в порядке КЛП
{       if (!isNull(b))
        {
           cout << RootBT(b);
           printKLP (Left(b));
           printKLP (Right(b));
        }
}

binTree recovery(string &lkp, string &lpk, int x) { //Рекурсивная функция, которая принимает записи узлов в порядке ЛКП и ЛПК, позицию корня и возвращает построенное по ним дерево
 if(lkp == "")
   return NULL;
 if (x < 0)	//Если номер текущего элемента отрицательный
   return NULL;
 if(lkp.length()==1)	//Условие, когда длинна ЛКП записи равна 1
 {
   binTree p = new node;
   p->info = lkp[0];
   return p;	//Тогда дерево состоит из одного узла
 }
 int flag = lkp.find(lpk[x]);	//Заводим переменную flag, которая хранит номер текущего элемента x из записи ЛПК в ЛКП записи
 if(flag < 0)	//Если номер окажется отрицательным
   return NULL;
 binTree r = new node;	//дерево, которое будем возвращать, если соблюдены все условия выше
 r->info = lpk[x];
  string lkp_r=lkp.substr(0, flag);	//функция substr возвращает flag символов из ЛКП записи узлов начиная с 0
  string lpk_r=lpk.substr(0, flag);	//функция substr возвращает flag символов из ЛПК записи узлов начиная с 0
  int x_r=flag-1;
  r->lt=recovery(lkp_r, lpk_r, x_r);	//прямой рекурсией вызываем функцию recovery с полученными параметрами
  lkp_r=lkp.substr(flag + 1);
  lpk_r=lpk.substr(flag, x-1);
  x_r=x-1-flag;
  r->rt = recovery(lkp_r, lpk_r, x_r);	//прямой рекурсией вызываем функию recovery с вновь полученными параметрами
 return r;	//Возвращаем полученное дерево
}

int main() {
 string str_lkp, str_lpk, s_count;	//Строки для ЛКП и ЛПК записи узлов
 ifstream fin("input.txt");		//Файл потока
 if(!fin)
 {
   cout << "Невозможно открыть файл!\n";
   return 0;
 }
int count=0;				//Счётчик символов "/n"
getline(fin, s_count, '\0');		//Считываем всё содержимое потока в строку s_count
for(int i=0; s_count[i]!='\0'; i++){	//Подсчитаем количество символов переноса строки
   if (s_count[i]=='\n'){
	count++;
   }
}
 if(count%2==0)				//Если число чётное - выполнено соответствие, продолжаем выполнение программы
   printf("%sВведённые данные верны! Каждой ЛКП записи соответствует ЛПК запись!%s\n", COL, NONE);
 else{					//Иначе выход из программы
   printf("%sНеверно введены данные. Несоответствие ЛКП и ЛПК строк.%s\n", RED, NONE);
   return 0;
 }
fin.seekg(0);				//Передвигаем каретку на начало потока
for(int i=0; i<count/2; i++){		//Цикл, пока не будут просмотрены все записи
  printf("%sДерево №%d имеет:%s\n", COL2, i+1, NONE);
  getline(fin, str_lkp);		//Отделяем функцией getline из файла input.txt - строчную ЛКП запись узлов
  getline(fin, str_lpk);		//Отделяем функцией getline из файла input.txt - строчную ЛПК запись узлов
  if(str_lkp.length()!=str_lpk.length())
  {
    printf("%sНевозможно построить дерево №%d, несоответствие ЛКП и ЛПК записей!%s\n", RED, i+1, NONE);
    continue;
  }
  else
  {
  cout << "ЛКП запись дерева: ";
  cout << str_lkp << endl;
  cout << "ЛПК запись дерева: ";
  cout << str_lpk << endl;
  binTree Tree = recovery(str_lkp, str_lpk, str_lpk.length()-1);	//Передаём полученные параметры в функцию построения дерева
  displayBT(Tree, 1);	//Выведем дерево на консоль под углом 90 градусов
  cout << "КЛП запись дерева: ";
  printKLP(Tree);	//Выведем КЛП запись файла на консоль
  cout << endl;
  }
}
printf("%sОбратите внимание, изображение дерева повёрнуто на 90 градусов влево!!!%s\n", COL2, NONE);
 return 0;
}
