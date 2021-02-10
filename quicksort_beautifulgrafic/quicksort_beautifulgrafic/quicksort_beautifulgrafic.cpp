// quicksort_beautifulgrafic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include <windows.h>

using namespace std;

void foo_sort(int aray[5], int numbers);
void foo_swap(int &left, int &right);
void foo_unique(int aray[],int numbers);
void foo_grafic(int aray[],int numbers);
void foo_out(int aray[], int numbers);
void foo_orgn_sort(int aray[], int numbers);
void grafic_output(int* aray, int n);
void grafic_output_v2(int* aray, int n, int left = 0, int right = 0);

enum color
{
	orange = FOREGROUND_RED | FOREGROUND_INTENSITY,
	red = FOREGROUND_RED | FOREGROUND_INTENSITY,
	green = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	//yellow = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
};



inline std::ostream& operator << (std::ostream& s, const color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c);
	return s;
}

void main()
{
	srand(time(NULL));
	//const int n = 10;
	//int aray[10];
	int n;
	cout << "input count of elements: "; cin >> n;
	int *aray = new int[n];
	foo_unique(aray,n);
	foo_grafic(aray,n);
	foo_sort(aray, n);
	//foo_orgn_sort(aray, n);
	foo_grafic(aray,n);
	//foo_out(aray, n)
	delete[]aray;
	system("pause");
}

void foo_grafic(int aray[], int numbers)
{
	cout << endl;
	for (int i = 0; i < numbers; i++)
	{
		for (int iter = 0; iter < aray[i]; iter++)
		{
			cout << aray[i] << " ";
		}
		cout << endl;
	} cout << endl;
}



void grafic_output(int* aray, int n)
{
	cout << endl;
	for (int iter1{ 1 }; iter1 <= n; iter1++)
	{
		for (int iter2{}; iter2 < n; iter2++)
		{
			if (aray[iter2] >= iter1)
				cout << char(254);//cout << aray[iter2];
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void grafic_output_v2(int* aray, int n, int left, int right)
{
	cout << endl;
	for (int iter1{ 1 }; iter1 <= n + 3; iter1++)
	{
		for (int iter2{}; iter2 < n; iter2++)
		{
			if (iter1 == n + 2 && iter2 == left&&left != -1)
			{
				if ((aray[left]>aray[right]))
				{
					cout << green << 'L' << white;
				}
				else
					cout << "l";
			}
			else if (iter1 == n + 2 && iter2 == right&&left != -1)
			{
				if ((aray[left]<aray[right]))
				{
					cout << red << 'R' << white;
				}
				else
					cout << "r";
			}
			else if (iter1 == n + 3 && iter2 >= left && iter2 <= right&&left != -1)
			{
				if (aray[left]>aray[right])
				{
					if (iter2 == left)
						cout << green << char(251) << white;
					else
						cout << green << '>' << white;
				}
				else
				{
					if (iter2 == right)
						cout << red << char(251) << white;
					else
						cout << red << '<' << white;
				}

			}
			//else if () cout << char(219);
			else if (iter2 == right && aray[iter2] >= iter1 || iter2 == left && aray[iter2] >= iter1&&left != -1)
			{
				//system("COLOR 0C");
				if (aray[left]>aray[right])
					cout << green << char(254) << white;
				//cout<<char(7);
				else
					cout << red << char(254) << white;
				//system("COLOR 07");
			}
			else if (aray[iter2] >= iter1)
				cout << char(254);//char(254);//cout << aray[iter2];
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void foo_swap(int &left, int &right)
{
	int swap = 0;
	swap = left;
	left = right;
	right = swap;
}
void foo_sort(int aray[], int numbers)
{
	//const int n = 20;
	
	while (true)
	{
		int iter = 0,
			swap = 0,
			swapiter = 0;
		bool logic = false,
			exz = false,
			swp{};
		for (int iter = 0; iter < numbers; iter++)
		{
			grafic_output_v2(aray, numbers, iter, (iter != numbers - 1) ? (iter + 1) : iter);
			this_thread::sleep_for(chrono::milliseconds(500));
			system("cls");
			if (aray[iter]>aray[iter + 1] && iter + 1<numbers)
			{
				foo_swap(aray[iter], aray[iter + 1]);
				//swp = 1;
			}
			for (int iter1 = iter; iter1 >= 0; iter1--)
			{
				if (!exz)
				{
					grafic_output_v2(aray, numbers, iter1, iter);
					this_thread::sleep_for(chrono::milliseconds(500));
					system("cls");
				}
				else
				{
					grafic_output_v2(aray, numbers, iter1, swapiter/*(swapiter != numbers - 1) ? (swapiter + 1) : swapiter*/);
					this_thread::sleep_for(chrono::milliseconds(500));
					system("cls");
				}
				if (aray[iter1] > aray[iter] && !exz)
				{
					foo_swap(aray[iter1], aray[iter]);
					swapiter = iter1;
					logic = true;
					exz = true;
					//swp = 1;
				}
				/*grafic_output_v2(aray, numbers, iter1, iter);
				this_thread::sleep_for(chrono::milliseconds(500));
				system("cls");*/
				
				else if (logic&&aray[iter1] > aray[swapiter])
				{
					foo_swap(aray[iter1], aray[swapiter]);
					swapiter = iter1;
					logic = true;
					//swp = 1;
				}
				//if (swp)
				//{
				if (!exz)
				{
					grafic_output_v2(aray, numbers, iter1, iter);
					this_thread::sleep_for(chrono::milliseconds(500));
					system("cls");
				}
				else
				{
					grafic_output_v2(aray, numbers, iter1, /*(swapiter != numbers - 1) ? (swapiter + 1) : swapiter*/swapiter);
					this_thread::sleep_for(chrono::milliseconds(500));
					system("cls");
				}
				
				//}
				//swp = 0;
			}
			//if (swp)
			//{
			grafic_output_v2(aray, numbers, iter, (iter != numbers - 1) ? (iter + 1) : iter);
				this_thread::sleep_for(chrono::milliseconds(500));
				system("cls");
			//}
			//swp = 0;
			logic = false;
			exz = false;
			swapiter = -1;
		}
		foo_unique(aray, numbers);
	}
	
}

void foo_unique(int aray[], int numbers)
{
	int iter = 0,
	i = 0;
	while (i < numbers)
	{
		aray[i] = 1 + rand() % numbers;
		if (i == 0)
		{
			i++;
			continue;
		}
		for (int iter{}; iter < i;iter++)
		//while (iter < i)
		{
			if (aray[i] == aray[iter])
			{
				aray[i] = 1 + rand() % numbers;
				iter = -1;
			}
			//iter++;
		}
		//iter = 0;
		i++;
	}
}

void foo_out(int aray[], int numbers)
{
	for (int i{}; i < numbers; i++)
	{
		cout << "aray[" << i + 1 << "]= " << aray[i] << "\t" << &aray[i] << endl;
	}
}

void foo_native_sort(int aray[], int numbers)
{
	for (int r = numbers - 1; r >= 0; r--)
		for (int l = 0; l < numbers; l++)
			if (aray[l]>aray[l + 1] && l + 1 < numbers)
			{
				foo_swap(aray[l], aray[l + 1]);
				//grafic_output(aray, numbers);
				//this_thread::sleep_for(chrono::milliseconds(150));
				//system("cls");
			}
				
}