#include <iostream>
#include <string>

// Linear search
int find_letter(char arr[], int size, char value)
{
	int position = -1;
	int index = 0;
	bool found = false;

	while (index < size && !found)
	{
		if (arr[index] == value)
		{
			position = index;
			found = true;
		}

		index++;
	}


	return position;
}

std::string encode(char arr[], std::string test)
{
	const int size = 94;
	int size_test = test.size();
	int arr_num[size];

	//puts all the characters of the string into an array
	// subtracts 32 to change the character
	int hold_char;
	for (int r = 0; r < size_test; r++)
	{
		hold_char = static_cast<int>(test[r]);
		arr_num[r] = hold_char - 32;
	}

	int hold;
	std::string message = "";

	//concats all the characters in the array into a string value
	for (int r = 0; r < size_test; r++)
	{
		hold = arr_num[r];
		message += arr[hold];
	}

	return message;
}

std::string decode(char arr[], int size, std::string message)
{
	int index;
	char position_index;

	int size_test = message.size();

	std::string new_message = "";

	//searchs for each letter of string in the ascii array
	//returns its position, and adds 32 to convert to right character
	for (int r = 0; r < size_test; r++)
	{
		index = message[r];
		position_index = find_letter(arr, size, index);
		new_message += position_index + 32;
	}

	return new_message;
}

int main()
{
	const int size = 94;
	char ascii[size];

	//puts all ascii character from 126 to 32 into an char array
	for (int i = 126; i > 32; i--)
	{
		ascii[126 - i] = static_cast<char>(i);
	}

	std::string test;

	std::cout << "Enter a message\n";
	std::getline(std::cin, test);

	std::cout << std::endl;

	std::string secret = encode(ascii, test);

	std::cout << "This is your message encoded\n";
	std::cout << secret << std::endl;

	std::cout << std::endl;

	std::cout << "This is your message decoded\n";
	std::string new_message = decode(ascii, size, secret);

	std::cout << new_message << std::endl;

	

	system("pause");
}