#include <iostream>
#include <chrono>
using namespace std;

void printing(float * ptr, int n)
{
	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, pom, numb = 11;

	while (true)
	{
		cout << "Введите какого размера создать массив (6, 8, 10): ";
		cin >> n;
		if (n != 6 && n != 8 && n != 10) { cout << "Ошибка. Повторите ввод." << endl; }
		else { break; }
	}

	float ** arr = new float *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new float[n];
	}

	float * ptr = &arr[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int choise;
	cout << "Выберите вид заполнения массива:" << endl << "1. Улитка" << endl << "2. Змейка" << endl;
	while (true)
	{
		cin >> choise;
		switch (choise)
		{
		case (1):
		{
			//----ЗАПОЛНЕНИЕ УЛИТКОЙ----//
			for (int i = 0; i < n / 2; i++)
			{
				//----1 ВИД СТРОК-----//

				for (int j = 0 + i; j < (n - 1 - i); j++)
				{
					*(ptr + j + i * n) = (rand() % 100);
				}
				printing(ptr, n);

				//----2 ВИД СТРОК-----//

				pom = -1;
				for (int k = i; k < n - i - 1; k++)
				{
					pom += 1;
					*(ptr + (n - 1) * (i + 1) + n * pom) = (rand() % 100);
				}
				printing(ptr, n);

				//----3 ВИД СТРОК-----//

				for (int l = 0 + i; l < n - 1 - i; l++)
				{
					*(ptr + (n * n - 1) - l - n * i) = (rand() % 100);
				}
				printing(ptr, n);

				//----4 ВИД СТРОК-----//

				for (int m = n - i - 1; m > i; m--)
				{
					*(ptr + i + m * n) = (rand() % 100);
				}
				printing(ptr, n);
			}
			break;
		}

		case(2):
		{
			//----ЗАПОЛНЕНИЕ ЗМЕЙКОЙ----//
			{
				for (int i = 0; i < n; i++)
				{
					if (i % 2 == 0)
					{
						for (int j = 0; j < n; j++)
						{
							*(ptr + i + j * n) = (rand() % 100);
						}

						printing(ptr, n);
					}

					else
					{
						for (int m = n - 1; m > -1; m--)
						{
							*(ptr + i + m * n) = (rand() % 100);
						}

						printing(ptr, n);
					}
				}
			}
			break;
		}

		default:
		{
			cout << "Ошибка. Повторите ввод.";
			break;
		}

		}
		if (choise == 1 || choise == 2)
		{
			choise = 0;
			break;
		}
	}

	cout << endl << "Выберите вид перестановки элементов:" << endl << "1. По часовой стрелке" << endl << "2. Крест-накрест" << endl << "3. По вертикали" << endl << "4. По горизонтали" << endl;
	while (true)
	{
		cin >> choise;
		switch (choise)
		{
		case(1):
		{
			//----ПЕРЕСТАНОВКА A----//
			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2)));
					swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) + (n / 2) * n));
					swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) * n));
				}
			}
			printing(ptr, n);
			break;
		}


		case(2):
		{
			//----ПЕРЕСТАНОВКА B----//
			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) + (n / 2) * n));
					swap(*(ptr + j + i * n + (n / 2) * n), *(ptr + j + i * n + (n / 2)));
				}
			}
			printing(ptr, n);
			break;
		}

		case(3):
		{
			//----ПЕРЕСТАНОВКА С----//
			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					swap(*(ptr + j + i * n), *(ptr + j + i * n + n * (n / 2)));
					swap(*(ptr + j + i * n + n / 2), *(ptr + j + i * n + n * (n / 2) + n / 2));
				}
			}
			printing(ptr, n);
			break;
		}

		case(4):
		{
			//----ПЕРЕСТАНОВКА D----//
			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					swap(*(ptr + i * n + j), *(ptr + i * n + j + n / 2));
					swap(*(ptr + i * n + j + n * (n / 2)), *(ptr + i * 10 + j + n / 2 + n * (n / 2)));
				}
			}
			printing(ptr, n);
			break;
		}

		default:
		{
			cout << "Ошибка. Повторите ввод.";
			break;
		}
		}
		if (choise == 1 || choise == 2 || choise == 3 || choise == 4)
		{
			choise = 0;
			break;
		}
	}

	cout << endl << "Отсортированный массив (сортировка пузырьком):" << endl;

	//----СОРТИРОВКА БАБЛ----//
	{
		for (int i = 0; i < n * n; i++) {
			for (int j = 1; j < (n * n - i); j++)
			{
				if (*(ptr + i) > *(ptr + i + j)) { swap(*(ptr + i), *(ptr + i + j)); }
			}
		}
		cout << endl;
		printing(ptr, n);
	}

	cout << endl << "Выберите действие над массивом:" << endl << "1. Увеличение(+)" << endl << "2. Уменьшение (-)" << endl << "3. Умножение (*)" << endl << "4. Деление (/)" << endl;
	float helper;
	while (true)
	{
		cin >> choise;
		switch (choise)
		{
		case(1):
		{
			cout << "Введите число, на которое хотите увеличить элементы массива: ";
			cin >> helper;
			for (int a = 0; a < n * n; a++)
			{
				*(ptr + a) = float(*(ptr + a)) + helper;
			}
			printing(ptr, n);
			break;
		}

		case(2):
		{
			cout << "Введите число, на которое хотите уменьшить элементы массива: ";
			cin >> helper;
			for (int a = 0; a < n * n; a++)
			{
				*(ptr + a) = float(*(ptr + a)) - helper;
			}
			printing(ptr, n);
			break;
		}

		case(3):
		{
			cout << "Введите число, во сколько раз вы хотите увеличить элементы массива: ";
			cin >> helper;
			for (int a = 0; a < n * n; a++)
			{
				*(ptr + a) = float(*(ptr + a)) * helper;
			}
			printing(ptr, n);
			break;
		}

		case(4):
		{
			cout << "Введите число, во сколько раз вы хотите уменьшить элементы массива: ";
			cin >> helper;
			for (int a = 0; a < n * n; a++)
			{
				*(ptr + a) = float(*(ptr + a)) / helper;
			}
			printing(ptr, n);
			break;
		}

		default:
		{
			cout << "Ошибка. Повторите ввод.";
			break;
		}
		}
		if (choise == 1 || choise == 2 || choise == 3 || choise == 4)
		{
			choise = 0;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
