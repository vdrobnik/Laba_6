#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "header_func.h"

using namespace std;

int mas[100][100];


bool itsProst(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return FALSE;
    return TRUE;
}


int InPut()
{
    int a;
    cin >> a;
    return a;
}

void OutPut(int s1, int n1)
{
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < n1; j++)
            cout << mas[i][j] << " ";
        cout << "\n";;
    }
}



void CopyMas(int a, int i, int j)
{
    mas[i][j] = a;
}

void Checking_and_CopyMas(int s1, int n1, int s2, int n2, bool numeral, int min, int max)
{
    for (int i = 0; i < s1; i++)
    {
        for (int p = 1; p < s1; p++)
            for (int j = 0; j < n1; j++)
            {
                if (mas[i][j] == mas[i + p][j])
                {
                    if (j == (n1 - 1))
                        numeral = TRUE;
                }
                else
                    break;
            }
    }

    if (numeral == TRUE)
    {
        for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (mas[j][i] < min)
                {
                    min = mas[j][i];
                    s2 = i;
                    n2 = j;
                }
            }

            for (int j = 0; j < n1; j++)
            {
                if (mas[j][i] == min)
                {
                    mas[j][i] = max;
                }
            }

            mas[n2][s2] = max;
            min = INT_MAX;
        }
    }
    else
    {
        cout << "Одинаковых строк нет\n";
    }
}

