#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>

template<typename T>
T getline_as(std::istream& s)
{
	std::stringstream convert(getline_as<std::string>(s));

	T value;
	convert >> value;
	return value;
}

template<>
std::string getline_as<std::string>(std::istream& s)
{
	std::string str;
	std::getline(s, str);
	return str;
}


template<typename input>
input readline(input &type)
{
	input user_input;


	if (typeid(type) == typeid(std::string))
	{
		return getline_as<input>(std::cin);
	}

	std::cin >> user_input;
	int size = sizeof(user_input);

	while (std::cin.fail() != false)
	{
		std::cin.clear();
		std::cout << "Invalid input\n";
		std::cin.ignore(size, ' ');
		std::cin >> user_input;
		size = sizeof(user_input);
	}


	type = user_input;
	return type;
}