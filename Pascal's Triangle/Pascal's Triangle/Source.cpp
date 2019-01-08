#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;
void menu();
void fibonacci_sequence();
void pascal_triangle();
int reduce(int);

int main()
{
	fibonacci_sequence();
	pascal_triangle();
}

int reduce(int n)
{
	while (n > 1)
	{
		n = n - 2;
	}

	return n;
}


void menu()
{
	int choice;

	std::cout << "1. Fibonacci Sequance\n";

	std::cout << "Enter the number of the choice you want.\n";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		fibonacci_sequence();
		break;
	default:
		break;
	}
}
void fibonacci_sequence()
{
	std::vector <int> sequance = { 0,1 };

	int next_num;
	int start = 0;
	std::cout << "1\n";



	while (true)
	{
		next_num = sequance[start] + sequance[start + 1];
		std::cout << next_num << std::endl;
		sequance.push_back(next_num);
		Sleep(500);
		start++;

	}
}


void pascal_triangle()
{
	vector <int> tri;
	vector <int> tri2 = { 1,1 };

	cout << "1\n";
	int next_size = 2;
	int n;

	for (int i = 0; i < 11; i++)
	{
		n = reduce(i);

		int size_1 = tri.size();
		int size_2 = tri2.size();
		if (n == 0)
		{
			for (int index = 0; index < size_2; index++)
			{
				cout << tri2[index] << " ";
			}
			cout << endl;
			int sum = 0;
			tri.clear();
			tri.push_back(1);
			for (int index = 0; index < next_size - 2; index++)
			{
				sum = tri2[index] + tri2[index + 1];
				tri.push_back(sum);

			}
			tri.push_back(1);
		}

		if (n == 1)
		{
			for (int index = 0; index < size_1; index++)
			{
				cout << tri[index] << " ";
			}
			cout << endl;
			int sum = 0;
			tri2.clear();
			tri2.push_back(1);
			for (int index = 0; index < next_size - 2; index++)
			{
				sum = tri[index] + tri[index + 1];
				tri2.push_back(sum);

			}
			tri2.push_back(1);
		}
		next_size++;
	}

	cin.get();
}



