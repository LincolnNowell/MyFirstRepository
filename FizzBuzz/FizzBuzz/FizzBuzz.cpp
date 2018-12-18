#include <iostream>

using std::cout; using std::cin; using std::endl;

int main()
{
	int x, y;

	cout << "What number is fizz?\n";
	cin >> x;
	cout << "What number is buzz?\n";
	cin >> y;

	for (int i = 1; i < 100; i++)
	{
		if (i % (x * y) == 0)
		{
			cout << "FizzBuzz\n";
		}
		else if (i % x == 0)
		{
			cout << "Fizz\n";
		}
		else if (i % y == 0)
		{
			cout << "Buzz\n";
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");
}