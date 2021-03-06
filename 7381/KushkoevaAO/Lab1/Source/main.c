/*
10.Построить синтаксический анализатор для определяемого далее понятия константное_выражение.
константное_выражение::=ряд_цифр|
	константное_выражение знак_операции константное_выражение
знак_операции::=+ | - | *
ряд_цифр::=цифра | цифра ряд_цифр
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void error(int i, int deep) {
        for(int i = 0; i <= deep; i++) {
                printf(" ");
	}

	printf("ERROR: ");

	switch (i) {								//вывод причины ошибки
		case 1:
			printf("invalid first character!\n");
			break;
		case 2:
			printf("requires a number of digits!\n ");
			break;
		case 3:
			printf("extra characters in the input line!\n");
			break;
		default:
			break;

	}

}


int check_next(char* str, int deep) {
	if(str[deep] == '\0') {
		error(2, deep);
		return 0;
	}
	else {
		return 1;
	}
}

int analiz(char* str, int deep) {
	int flag = 1;

        if(str[deep] == '\0') {                //завершение рекурсии в случае константного выражения
		return 1;
	}

	for(int i = 0; i < deep; i++) {						//отступ для удобного просмотра результата программы
		printf(" ");
	}

	printf(">The incoming character: %c", str[deep]);

	if(!isdigit(str[0])) { 							//проверка корректности первого элемента выражения
		printf("\n");
		error(1, deep);
		printf("<\n");
		return 0;
	}

	if(isdigit(str[deep])) {
		printf("\n");
		if(!analiz(str, deep+1)) {
			flag = 0;
		}
	}
	else {
		if(str[deep] == '+'|| str[deep] == '-' || str[deep] == '*') {
			printf("   \\\\ Waiting for a series of numbers.\n");

			if(check_next(str, deep+1)) {
				if( !analiz(str, deep+1) ) {
					flag = 0;
				}
			}

			else {
				flag = 0;
				deep--;
			}
		}

		else {
			printf("\n");
			flag = 0;
			error(3, deep);
		}
	}

	for(int i = 0; i < deep; i++) {						//отступ для удобного просмотра результата программы
		printf(" ");
	}

	printf("<\n");

	if(flag) {
		 return 1;
	}
	else {
		return 0;
	}
}

int main() {
        int len_str = 100;
        char* str = (char*)malloc(sizeof(char)*len_str);

	printf("Enter the name of a file, which contains the expression, or just enter the expression right here: ");

	scanf("%s", str);

	if (strstr(str, ".txt")) {
		FILE* file = fopen(str, "r");

		if (!file) {
			printf("A file doesn't exist or it's not a constant expression!\n");
			return 0;
		}

		str[0] = '\0';

		fgets(str, len_str, file);

		if (str[strlen(str)-1] == '\n') {
			str[strlen(str)-1] = '\0';
		}

		fclose(file);
	}

	printf("Constant expression analyzer:\n");

	if(analiz(str, 0)) {
		 printf("It's a constant expression!\n");
	}
	else {
		printf("It's not a constant expression!\n");
	}

	return 0;
}

