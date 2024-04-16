#include<iostream>
#include"1.1.h"
#include"2.2.h"
#include<string>
//1101

int main()
{
	std::string s;
	getline(std::cin, s);
	int l = s.length();
	std::string s1 = Logical_Expression(s, l);
	std::string s2 = infixToPostfix(s1);
	for (char c : s2)
	{
		std::cout << s2.c_str();
	}
	return 0;
}