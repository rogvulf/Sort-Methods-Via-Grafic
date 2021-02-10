// PyramidaSorting_beatifulgrafic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <windows.h>

using namespace std;

void grafic_left_side(int aray[],int n);
void grafic_right_side(int aray[],int n);
void pyramid(int aray[], int n);
void grafic_both_side_pyramid(int aray[], int n);
void pyramid_conversely(int aray[], int n);
void pyramid_ordinary(int aray[], int n);
void pyramid_both_side_ordinary(int aray[], int n);
void output(int aray[], int n);


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

void pyramid_sorting(int aray[], int n);
void grafic_output(int* aray, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int n;
	cout << "input count of elements; "; cin >> n;
	int i = 0,
		l,
		//n = rand()%9+1,
		r,
		c,
		iter = NULL,
		swap = 0,
		s = n,
		*aray = new int[n];
	int max = aray[0];
	while (i < n)
	{
		i++;
		aray[i] = 1 + rand() % n;
		while (iter < i)
		{
			if (aray[i] == aray[iter])
			{
				aray[i] = 1 + rand() % n;
				iter = -1;
			}
			iter++;
		}iter = 0;
		cout << "aray[" << i << "]= " << aray[i] << endl;
	}
	i = 0;
	cout << endl << endl;
	cout << endl << endl;
	//grafic_output(aray, n);
	pyramid_sorting(aray, n);
	iter = 0;
	while (i < n)
	{
		//i++;
		//aray[i] = 1 + rand() % n;
		/*while (iter < i)
		{
			if (aray[i] == aray[iter])
			{
				aray[i] = 1 + rand() % n;
				iter = -1;
			}
			iter++;
		}iter = 0;*/
		cout << "aray[" << i << "]= " << aray[i++] << endl;
	}
	i = 0;
	cout << endl << endl;
	cout << endl << endl;
	/*for (; s >= 1; s--)
	{
	while (aray[1] != max)
	{
		while (i < s)
		{
			i++;
			if (aray[i] < aray[2 * i] && (2 * i) <= s)
			{
				swap = aray[i];
				aray[i] = aray[2 * i];
				aray[2 * i] = swap;
			}
			if (aray[i] < aray[2 * i + 1] && (2 * i + 1) <= s)
			{
				swap = aray[i];
				aray[i] = aray[2 * i + 1];
				aray[2 * i + 1] = swap;
			}
			if (aray[i] > max)max = aray[i];

		}
		i = 0;
	}
	max = aray[0];
		swap = aray[1];
		aray[1] = aray[s];
		aray[s] = swap;
}*/
	i = 0;
	iter = 0;
	//output(aray, n);
	//pyramid_conversely(aray, n);
	//grafic_both_side_pyramid(aray, n);
	//pyramid_both_side_ordinary(aray, n);
	system("pause");
	return 0;
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

void pyramid_sorting(int aray[],int n)
{
	
	//while (1)
	//{
		int max = aray[0], i{}, s{ n }, swap{}; bool swp{};
		for (; s >= 1; s--)
		{
			
			//cout << char(7);
			
			while (aray[1] != max)
			{
				while (i < s)
				{
					i++;
					grafic_output_v2(aray, n, i, (2 * i + 1 <= n - 1) ? (2 * i + 1) : i);
					this_thread::sleep_for(chrono::milliseconds(300));
					system("cls");
					//else if (aray[i] > aray[2 * i])
					grafic_output_v2(aray, n, i, (2 * i <= n - 1) ? (2 * i) : i);
					this_thread::sleep_for(chrono::milliseconds(300));
					system("cls");
					if (aray[i] < aray[2 * i] && (2 * i) <= s)
					{
						swap = aray[i];
						aray[i] = aray[2 * i];
						aray[2 * i] = swap;
						swp=1;
					}
					else if (aray[i] < aray[2 * i + 1] && (2 * i + 1) <= s)
					{
						swap = aray[i];
						aray[i] = aray[2 * i + 1];
						aray[2 * i + 1] = swap;
						swp = 1;
					}
					if (aray[i] > max)
						max = aray[i];
					//if (swp)
					//{
						//grafic_output(aray, n);
						//if (aray[i] > aray[2 * i + 1])
							grafic_output_v2(aray, n, i, (2 * i + 1 <= n - 1) ? (2 * i + 1) : i);
							this_thread::sleep_for(chrono::milliseconds(300));
							system("cls");
						//else if (aray[i] > aray[2 * i])
							grafic_output_v2(aray, n, i, (2 * i <= n - 1) ? (2 * i ) : i);
						this_thread::sleep_for(chrono::milliseconds(300));
						system("cls");
					//}
					//swp = 0;
				}
				i = 0;
				
			}
			max = aray[0];
			swap = aray[1];
			aray[1] = aray[s];
			aray[s] = swap;
		}
	//}	
		grafic_output(aray, n);
		this_thread::sleep_for(chrono::milliseconds(10000));		
}


void pyramid_ordinary(int aray[], int n)
{
	int i = 1,
		iter,
		temp_ar = n + (n - 1),
		*temp_ar1 = new int[temp_ar],
		*temp_ar2 = new int[temp_ar],
		temp = ((n + (n - 1)) % 2 == 1) ? ((n + (n - 1)) / 2 + 1) : ((n + (n - 1)) / 2);
	cout << endl << endl;
	while (i <= n)
	{
		iter = temp;
		while (iter > 0)
		{
			if (aray[i] >= iter)
			{
				temp_ar2[iter] - aray[i];
				cout << aray[i];
			}
			else if ((temp_ar1[iter] == aray[i - 1])&&i-1!=0)
				cout << "_";
			cout << " ";
			iter--;
		}
		for (int it = 0; it < temp; it++)
		{
			temp_ar1[it] = temp_ar2[it];
		}delete[] temp_ar2;
		temp_ar2 = new int[temp];
		i++; cout << endl;
	}
}

void pyramid_both_side_ordinary(int aray[], int n)
{
	int i = 0,
		iter,
		temp_ar = n + (n - 1),
		*temp_ar1 = new int[temp_ar],
		*temp_ar2 = new int[temp_ar],
		temp = ((n + (n - 1)) % 2 == 1) ? ((n + (n - 1)) / 2 + 1) : ((n + (n - 1)) / 2);
	cout << endl << endl;
	while (i < n)
	{
		iter = temp;
		while (iter > 0)
		{
			if (aray[i] >= iter)
			{
				temp_ar2[iter] - aray[i];
				cout << aray[i];
			}
			else if ((temp_ar1[iter] == aray[i - 1])&&i-1!=0)
				cout << "_";
			cout << " ";
			iter--;
		}
		for (int it = 0; it < temp; it++)
		{
			temp_ar1[it] = temp_ar2[it];
		}delete[] temp_ar2;
		temp_ar2 = new int[temp];
		i++; cout << endl;
	}
	i = n - 2;
	while (i >= 0)
	{
		iter = temp;
		while (iter > 0)
		{
			if (aray[i] >= iter)
			{
				temp_ar2[iter] - aray[i];
				cout << aray[i];
			}
			else if ((temp_ar1[iter] == aray[i - 1])&& i-1!=0)
				cout << "_";
			cout << " ";
			iter--;
		}
		for (int it = 0; it < temp; it++)
		{
			temp_ar1[it] = temp_ar2[it];
		}delete[] temp_ar2;
		temp_ar2 = new int[temp];
		i--; cout << endl;
	}
}
void pyramid(int aray[], int n)
{
	int i = 0,
		iter;
	cout << endl << endl;
	while (i < n)
	{
		i++;
		iter = n;
		while (iter >0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter--;
		}
		iter = 1;
		while (iter <= aray[i])
		{
			cout << aray[i];
			if (iter == aray[i])
			{
				iter++;
				continue;
			}
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter++;
		}
		cout << endl;
	}
}
void grafic_both_side_pyramid(int aray[], int n)
{
	int i = 0, 
		iter = 0;
	cout << endl << endl;
	while (i < n)
	{
		i++;
		cout << "aray[" << i << "]= " << aray[i] << endl;
	}
	i = 0;
	cout << endl << endl;


	while (i < n)
	{
		i++;
		iter = n;
		while (iter >0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter--;
		}
		iter = 1;
		while (iter <= aray[i])
		{

			cout << aray[i];
			if (iter == aray[i])
			{
				iter++;
				continue;
			}
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter++;
		}
		cout << endl;
	}

	i = n;

	while (i >0)
	{
		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter--;
		}
		iter = 1;
		while (iter <= aray[i])
		{

			cout << aray[i];
			if (iter == aray[i])
			{
				iter++;
				continue;
			}
			if (aray[i] < 10)
				cout << " ";
			cout << " ";
			iter++;
		}
		i--;
		cout << endl;
	}
}

void pyramid_conversely(int aray[], int n)
{
	int iter,
	i = n;
	cout << endl << endl;

	while (i > 0)
	{
		iter = 1;
		while (iter <= n)
		{
			if (iter <= aray[i])
				cout << aray[i];
			else cout << " ";
			cout << " ";
			iter++;
		}

		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			cout << " ";
			iter--;
		}
		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			cout << " ";
			iter--;
		}iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			cout << " ";
			iter--;
		}
		i--;
		cout << endl;
	}

	i = 0;

	while (i <n)
	{
		i++;
		iter = 1;
		while (iter <= n)
		{
			if (iter <= aray[i])
				cout << aray[i];
			else cout << " ";
			cout << " ";
			iter++;
		}
		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			//cout << " ";
			iter--;
		}
		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			//cout << " ";
			iter--;
		}
		iter = n;
		while (iter > 0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else if (iter == 1)
			{
				iter--;
				continue;
			}
			else
				cout << " ";
			if (aray[i] < 10)
				cout << " ";
			//cout << " ";
			iter--;
		}
		cout << endl;
	}
}

void grafic_left_side(int aray[],int n)
{
	int i = 0,
		iter;
	cout << endl << endl;
	while (i < n)
	{
		i++;
		iter = 1;
		while (iter <= aray[i])
		{

			cout << aray[i] << " ";
			iter++;
		}
		cout << endl;
	}
}

void grafic_right_side(int aray[],int n)
{
	int i = 0,
		iter;
	cout << endl << endl;
	while (i < n)
	{
		i++;
		iter = n;
		while (iter >0)
		{

			if (aray[i] >= iter)
				cout << aray[i];
			else
				cout << " ";
			cout << " ";
			iter--;
		}
		cout << endl;
	}
}
void output(int aray[], int n)
{
	int i = 0;
	cout <<endl << endl;
	while (i < n)
	{
		i++;
		cout << "aray[" << i << "]= " << aray[i] << endl;
	}
}
/*
const int n = 10;
int aray[n],
i = 0,
l,
r,
c,
swap = 0;
while (i < n)
{
aray[i] = 1 + rand() % 10;
cout << "aray[" << i + 1 << "]= " << aray[i] << endl;
i++;
}
i = 0;
l = 0;
r = n;
do{
c = (l + r) / 2;
l = (l + c) / 2;
r = (r + c) / 2;
} while (true);





for (int iter = n - 1,iter1=0; iter >= 0; iter--,iter1++)
{
while (i < n)
{
if (aray[2 * i] > aray[i])
{
swap = aray[2 * i];
aray[2 * i] = aray[i];
aray[i] = swap;
}
if (aray[2 * i + 1] > aray[i])
{
swap = aray[2 * i + 1];
aray[2 * i + 1] = aray[i];
aray[i] = swap;
}
i++;
}
i = 0;
swap = aray[iter];
aray[iter] = aray[iter1];
aray[iter1] = swap;
}
cout << endl << endl;
i = 0;
while (i<n)
{
cout << "aray[" << i + 1 << "]= " << aray[i] << endl;
i++;
}//////*/