#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header_func.h"

using namespace std;

struct wall
{
    int s1, n1, n2, s2;
};
wall Sides;

int matrix1[100][100], number;

/*bool itsProst(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return FALSE;
	return TRUE;
}*/

//n - столбцов
//s - строк

int main()
{
    setlocale(LC_ALL, "Russian");
    //3 вариант Погрeбной 6 лаба

    cout << "Введите размер матриц\n(Сначала количество столбцов, затем строк)\n";
    cin >> Sides.n1 >> Sides.s1;
    cout << "\nЗаполните матрицу\n";

    for (int i = 0; i < Sides.s1; i++)
        for (int j = 0; j < Sides.n1; j++)
        {
            matrix1[i][j] = InPut();//функция ввода
            CopyMas(matrix1[i][j], i, j);
        }


    int min = INT_MAX, l = 0, mas_string[20], param = 0, max = 1;

    for (int i = 0; i < Sides.s1; i++)
        for (int j = 0; j < Sides.n1; j++)
            if ((matrix1[i][j] >= max) && (itsProst(matrix1[i][j]) == TRUE))
                max = matrix1[i][j];

    bool numeral = FALSE;

    Checking_and_CopyMas(Sides.s1, Sides.n1, Sides.s2, Sides.n2, numeral, min, max);

    cout << "\n";

    OutPut(Sides.s1, Sides.n1);


    _getch();
}

