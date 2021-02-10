// bublesort_grafic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;
int main();
class MyClass
{
private:
	int a1;
public:
	void setel(int a1){ this->a1 = a1; }
};

class F
{
public:
	struct u
	{
		struct v{
			int j;
		};
		v v1;
	};
	u u1;
};
struct x
{
	int a;
	class D
	{
	public:
		int c2;
		
	};
	D d;
};
x foo()
{
	class D
	{
	public:
		x c2;
	};
	D d ;
	F f1;
	f1.u1.v1.j = 1;
	main();
	d.c2.d.c2=2;
	return d.c2;
}

int main()
{

	MyClass mcl; int a=1, b=3;
	mcl.setel(b-a);
	struct c
	{
		x d;
		int c1;
	};
	c c1;
	c1.d.a = 2;
	class D
	{
	public:
		c c2;
	};
	D d;
	d.c2.d.a = 3;
	srand(time(NULL));
	int		 *arr,
		temp,
		iter,
		iter1,
		size,
		left,
		right,
		count_compr = 0,
		count_swap = 0;
	bool	 logic = true;
	size = 1 + rand() % rand() % 21;
	if ((sizeof(arr) / sizeof(arr[0])) != 1)
		size = sizeof(arr) / sizeof(arr[0]);
	arr = new int[size];
	cout << endl << endl;
	for (int k = 0, iter = 0; iter < size; iter++)
	{
		k =  rand() % rand() % size;
		while (logic)
		{
			temp = 0;
			while (temp <= iter){
				if (k == arr[temp]) { logic = true; break; }
				else logic = false;
				temp++;
			}
			if (logic)k =  rand() % rand() % size;
		}logic = true;
		arr[iter] = k;
	}
	cout << endl << endl;
	for (iter = 0; iter < size; iter++)
	{
		if (arr[iter] < 10)	cout << " "; cout << arr[iter] << " ";
		for (iter1 = 0; iter1 <= arr[iter]; iter1++)
		{
			if (iter1 <= 1) continue;
			if (arr[iter] < 10)	cout << " "; cout << arr[iter] << " ";
		}
		cout << endl;
	}cout << endl << endl;

	for (right = size - 1, left = 0; right > left; left++)
	{
		for (; right >= left; right--)
		{
			if (arr[right] < arr[right - 1])
			{
				temp = arr[right];
				arr[right] = arr[right - 1];
				arr[right - 1] = temp;
				count_compr += 1;
			}
			count_swap += 1;
		}right = size - 1;
	}
	for (iter = 0; iter < size; iter++)
	{
		if (arr[iter] < 10) cout << " "; cout << arr[iter] << " "; 
		for (iter1 = arr[0]; iter1 <= arr[iter]; iter1++)  //arr[0]=1, numeration starts from 1, array are sorted
		{
			if (iter1 <= arr[0]) continue;
			if (arr[iter] < 10)	cout << " "; cout << arr[iter] << " ";
		}
		cout << endl;
	}cout << endl << endl;
	system("pause");
	return 0;
}

