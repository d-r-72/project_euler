#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

void MultiplesOf3_And_5(int num)
{
	int result = 0;

	for (int i = 0; i < num; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			result += i;
		}
	}

	std::cout << result << std::endl;
}

void EvenValueFibonacci(uint32_t max)
{
	std::vector<int> vec;

	int counter = 0;
	bool done = false;
	int result = 0;

	int i = 1;
	int j = 2;
	int k = i + j;

	vec.push_back(i);
	vec.push_back(j);
	vec.push_back(k);

	while (!done)
	{
		int temp1 = k;
		k += j;
		int temp2 = j;
		j = temp1;
		i = temp2;

		vec.push_back(k);
		if (k > max)
			done = true;
	}

	vec.pop_back();

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] % 2 == 0)
			result += vec[i];
	}

	std::cout << result << std::endl;
}

void LargestPrimeFactor(uint64_t number)
{
	uint64_t temp = number;

	for (uint64_t i = 2; i < temp; i++)
	{
		if (temp % i == 0)
		{
			std::cout << i << std::endl;
			temp /= i;
		}
	}

	if (temp > 1)
		std::cout << temp;
}

void LargestPalindromeProduct(int digits)
{
	bool done = false;
	int flipped = 0;
	int unFlipped;
	int temp;

	std::vector<int> palindromes, first, second;

	switch (digits)
	{
	case 2:
		for (int i = 10; i <= 99; i++)
		{
			for (int j = 99; j >= 10; j--)
			{
				unFlipped = 0;
				flipped = 0;
				unFlipped = j * i;
				std::cout << i << " " << j << std::endl;
				temp = unFlipped;

				while (temp > 0)
				{
					flipped = flipped * 10 + (temp % 10);
					temp = temp / 10;
				}

				if (flipped == unFlipped)
				{
					first.push_back(i);
					second.push_back(j);
					palindromes.push_back(flipped);
				}
			}
		}
		break;

	case 3:
		for (int i = 100; i <= 999; i++)
		{
			for (int j = 999; j >= 1; j--)
			{
				unFlipped = 0;
				flipped = 0;
				unFlipped = j * i;
				std::cout << i << " " << j << std::endl;
				temp = unFlipped;

				while (temp > 0)
				{
					flipped = flipped * 10 + (temp % 10);
					temp = temp / 10;
				}

				if (flipped == unFlipped)
				{
					first.push_back(i);
					second.push_back(j);
					palindromes.push_back(flipped);
				}
			}
		}
		break;

	default:
		std::cout << digits << " Digits not supported yet!\n";
		_getch();
		exit(1);
		break;
	}

	std::cout << "Biggest Palindrome: " << *std::max_element(palindromes.begin(), palindromes.end());
}

int main()
{
	//MultiplesOf3_And_5(1000);
	//EvenValueFibonacci(4'000'000);
	//LargestPrimeFactor(600851475143);
	LargestPalindromeProduct(3);

	int k;
	std::cin >> k;
	return 0;
}