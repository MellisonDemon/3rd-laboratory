#include <iostream>
using namespace std;

int main()
{

	int pom;
	int arr[10][10], n = 10, numb = 11;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	int * ptr = &arr[0][0];

	//----ЗАПОЛНЕНИЕ УЛИТКОЙ----//
	for (int i = 0; i < n / 2; i++)
		{

			//----1 ВИД СТРОК-----//

			for (int j = 0 + i; j < (n - 1 - i); j++)
			{
				*(ptr + j + i * n) = numb;
				numb += 1;
			}

			for (int a = 1; a < n*n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;

			//----2 ВИД СТРОК-----//

			pom = -1;

			for (int k = i; k < n - i - 1; k++)
			{
				pom += 1;
				*(ptr + (n - 1)*(i + 1) + n * pom) = numb;
				numb += 1;
			}

			for (int a = 1; a < n*n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;

			//----3 ВИД СТРОК-----//

			for (int l = 0 + i; l < n - 1 - i; l++)
			{
				*(ptr + (n*n - 1) - l - n * i) = numb;
				numb += 1;
			}
			for (int a = 1; a < n*n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;

			//----4 ВИД СТРОК-----//

			for (int m = n - i - 1; m > i; m--)
			{
				*(ptr + i + m * n) = numb;
				numb += 1;
			}
			for (int a = 1; a < n*n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;
		}

	
	/*//----ЗАПОЛНЕНИЕ ЗМЕЙКОЙ----//
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				*(ptr + i + j * n) = numb;
				numb += 1;
			}

			for (int a = 1; a < n * n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;
		}

		else
		{
			for (int m = n - 1; m > -1; m--)
			{
				*(ptr + i + m * n) = numb;
				numb += 1;
			}

			for (int a = 1; a < n * n + 1; a++)
			{
				cout << *(ptr + a - 1) << " ";
				if (a % n == 0) { cout << endl; }
			}
			cout << endl;
		}
	}

	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}*/

	//----ПЕРЕСТАНОВКА A----//
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			swap(*(ptr + j + i * n), *(ptr + j + i * n + (n/2)));
			swap(*(ptr + j + i * n), *(ptr + j + i * n + (n/2) + (n/2)*n));
			swap(*(ptr + j + i * n), *(ptr + j + i * n + (n/2)*n));
		}
	}

	cout << "AAA" << endl;

	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}

	//----ПЕРЕСТАНОВКА B----//
	{
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) + (n / 2) * n));
				swap(*(ptr + j + i * n + (n / 2) * n), *(ptr + j + i * n + (n/2)));
			}
		}
	}

	cout << "BBB" << endl;

	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}

	//----ПЕРЕСТАНОВКА С----//
	{
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				swap(*(ptr + j + i * n), *(ptr + j + i * n + n * (n / 2)));
				swap(*(ptr + j + i * n + n / 2), *(ptr + j + i * n +n * (n / 2) + n / 2)));
			}
		}
	}

	cout << "CCC" << endl;

	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}

	//----ПЕРЕСТАНОВКА D----//
	{
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				swap(*(ptr + i * n + j), *(ptr + i * n + j + n / 2));
				swap(*(ptr + i * n + j + n * (n / 2)), *(ptr + i * 10 + j + n / 2 + n * (n / 2)));
			}
		}
	}

	cout << "DDD" << endl;

	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}

	/*//----СОРТИРОВКА БАБЛ----//

	for (int i = 0; i < n * n; i++) {
		for (int j = 1; j < (n * n - i); j++)
		{
			if (*(ptr + i) > *(ptr + i + j)) { swap((ptr + i), (ptr + i + j)); }
		}
	}
	cout << endl;
	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}
	cout << endl;*/

	return 0;
}
