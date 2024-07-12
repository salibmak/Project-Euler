#include <iostream>
#include <cstring>
using namespace std;

unsigned problem1();
unsigned problem2();

int main(int argc, char** argv)
{
	if (!strcmp(argv[1], "1"))
		cout << problem1();
	if (!strcmp(argv[1], "2"))
		cout << problem2();

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