#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// Problem Solving Functions
unsigned problem1();
unsigned problem2();
unsigned problem3();

// Utility Functions
bool isPrime(unsigned long long);

int main(int argc, char** argv)
{
	if (!strcmp(argv[1], "1"))
		cout << problem1();
	if (!strcmp(argv[1], "2"))
		cout << problem2();
	if (!strcmp(argv[1], "3"))
		cout << problem3();

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