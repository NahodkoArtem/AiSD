#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[0;31m"
#define NONE "\033[0m"

int Correct_Place_Bracket(int len_of_text, char *text) //Функция проверки равенства закрывающихся и открывающихся скобок
{
 int bracket_count=0; //Счётчик кол-ва скобок
 char *element=text; //Указатель на второй эл-нт текста
 while(*element!=0)
 {
   if(*element=='(')
   bracket_count++; //Увеличиваем счётчик, если скобка открыта
   if(*element==')')
   bracket_count--; //Уменьшаем счётчик, если скобка закрыта
   element++;
 }
 if(bracket_count==0) //Если счётчик равен 0, то наблюдается равенство открытых и закрытых скобок
   return 1;
 else
   return 0;
}

int Find_Close_Bracket(int len_of_text,char *text) //Функция нахождения закрывающихся скобок для открытых
{
 if(len_of_text==1) return 0;
 int bracket_count=1;
 char *element=text+1;
 while(bracket_count!=0) //Цикл, пока для первой откытой скобки не найдём закрытую
 {
   if(*element=='(')
     bracket_count++;
   if(*element==')')
     bracket_count--;
   if(*element==0)
     return 0;
   if(element==text+len_of_text)
     break;
 element++;
 }
 return element-text; //Возвращаем кол-во элементов в найденных закрытых скобках
}

int rec_analis(int len_of_text,char *text) //Рекурсивная функция проверки текста на понятие "скобки"
{
 printf("%s\n", text);
 if(len_of_text<1)
   return 0;
 if(*text=='A' && len_of_text==1)
   return 1;
 if(*text=='(' && *(text+1)=='B') //Если первый эл-нт ( и последующий B
 {
   if(Find_Close_Bracket(len_of_text,text)==0) return 0;
   int corr_section=rec_analis(Find_Close_Bracket(len_of_text,text)-3,text+2); //Находим "правильный" участок для запуска анализа
   int trans_section=rec_analis(len_of_text-Find_Close_Bracket(len_of_text,text),text+Find_Close_Bracket(len_of_text,text)); //Используем как переход на новый участок
   return corr_section * trans_section; //В случае верной постановки скобок, функция вернёт значение 1
 }
 else
 {
   return 0;
 }
}

int main()
{
 char *text=(char*)malloc(500);
 printf("Введите текст: ");
 scanf("%s",text);
 int len_of_text=strlen(text); //Длина текста
 if(len_of_text==0)
 {
   printf("%sПрограмма выполняет анализ...%s\nТекст пуст!\n", RED, NONE);
   return 0;
 }
 if(Correct_Place_Bracket(len_of_text, text)==0) //Если функция не прошла проверку на равенство закрытых и раскрытых скобок
 {
   printf("%sПрограмма выполняет анализ...%s\nНекорректный ввод данных!\n", RED, NONE);
   return 0;
 }
 if(*text!='A' && (*text!='(' || Find_Close_Bracket(len_of_text, text)==0))
 {
   printf("%sПрограмма выполняет анализ...%s\nВведённый текст не является скобками!\n", RED, NONE);
   return 0;
 }
 if(rec_analis(len_of_text,text)==1) //Производим анализ введённого текста
 {
   printf("%sПрограмма выполняет анализ...%s\nВведённый текст скобки!\n", RED, NONE);
 }
 else
 {
   printf("%sПрограмма выполняет анализ...%s\nВведённый текст не является скобками!\n", RED, NONE);
 }
 free(text);
 return 0;
}


