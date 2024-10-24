#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

// Problem Solving Functions
unsigned problem1();
unsigned problem2();
unsigned problem3();
unsigned problem4();
unsigned problem5();

// Utility Functions
bool isPrime(unsigned long long);
bool isPalindromic(string);

int main(int argc, char** argv)
{

	if (!strcmp(argv[1], "1"))
		cout << problem1();
	if (!strcmp(argv[1], "2"))
		cout << problem2();
	if (!strcmp(argv[1], "3"))
		cout << problem3();
	if (!strcmp(argv[1], "4"))
		cout << problem4();
	if (!strcmp(argv[1], "5"))
		cout << problem5();

	return 0;
}

unsigned problem1()
{
	unsigned sum = 0;

	for (unsigned i = 3; i < 1000; i += 3)
		sum += i;

	for (unsigned i = 5; i < 1000; i += 5)
		sum += i % 3 ? i : 0; // Don't double count a number if it is divisible by 3

	return sum;
}

unsigned problem2()
{
	unsigned sum = 0;
	unsigned int num1 = 1;
	unsigned int num2 = 2;
	unsigned int temp = 1;

	while (num2 <= 4000000)
	{
		if (!(num2 % 2))
			sum += num2;

		temp = num1;
		num1 = num2;
		num2 = temp + num2;
	}

	return sum;
}

unsigned problem3()
{
	unsigned long long num = 600851475143;
	unsigned max = 1;

	for (unsigned i = 3; i < sqrt(num) + 1; i += 2)
	{
		if (!(num % i) && isPrime(i))
			max = i;
	}

	return max;
}

unsigned problem4()
{
	unsigned prod = 1;

	for (int i = 999; i > 99; i--)
	{
		for (int j = 999; j > 99 && j * i > prod; j--)
		{
			if (isPalindromic(to_string(j * i)))
				prod = j * i;
		}
	}
	return prod;
}

unsigned problem5()
{
	int factors[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	unsigned prod = 1;
	for (int i = 0; i < 10; i++)
		prod *= factors[i];
	

	for (int i = 20; i < prod; i += 20)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i % factors[j])
				break;
			if (j == 9)
				return i;
		}
	}
	return prod;
}

bool isPrime(unsigned long long num)
{
	if (num == 2)
		return true;

	for (int i = 2; i < sqrt(num) + 1; i++)
	{
		if (!(num % i))
			return false;
	}

	return true;
}

bool isPalindromic(string str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - i - 1])
			return false;
	}

	return true;
}