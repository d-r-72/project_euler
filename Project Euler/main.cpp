#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <numeric>

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

void SmallestMultiple()
{
	bool done = false;
	int counter;
	while(!done)
	for (int i = 1; i < INT_MAX; i++)
	{
		done = true;
		counter = 0;
		for (int j = 1; j <= 20; j++)
		{
			if (i % j != 0)
				done = false;
			else
				counter++;

			if (counter == 20)
			{
				std::cout << i << std::endl;
				done = true;
			}
		}
	}
}

void SumSquareDifference(int natNums)
{
	int SumOfSquare = 0;
	int SquareOfSum = 0;

	for (int i = 1; i <= natNums; i++)
	{
		SumOfSquare += pow(i, 2);
		SquareOfSum += i;
	}

	SquareOfSum = pow(SquareOfSum, 2);

	std::cout << (SquareOfSum - SumOfSquare) << std::endl;
}

void TenThousandAndOnePrime()
{
	int counter = 0;
	int iter = 2;
	bool done = false;
	bool addToList;

	while (!done)
	{
		addToList = true;
		
		for (int i = 2; i < (iter - 1); i++)
		{
			if (iter % i == 0)
				addToList = false;
		}

		if (addToList)
		{
			counter++;
			if (counter == 10001)
			{
				std::cout << "10,001: " << iter << std::endl;
				done = true;
			}
		}
		iter++;
	}
}

void LargestProductInSeries(int adjs)
{
	std::string loadedNumber;
	std::vector<unsigned long long> sums;

	std::ifstream in("ThousandDigitNumber.txt");

	if (in.fail())
	{
		std::cerr << "Error opening file\n";
		_getch();
		exit(1);
	}

	std::string line;
	while (getline(in, line))
	{
		loadedNumber.append(line);
	}
	
	bool done = false;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	unsigned long long prevNum = 1;
	unsigned long long nexNum = 1;

	const int MAX_ADJACENTS = adjs;
	const int DIGITS = loadedNumber.size();

	int temp = 0;

	while (temp <= DIGITS - MAX_ADJACENTS)
	{
		for (int i = temp; i < temp + MAX_ADJACENTS; i++)
			nexNum *= (loadedNumber[i] - '0');
		
		if (nexNum > prevNum)
			prevNum = nexNum;
		
		nexNum = 1;
		temp++;
	}

	std::cout << prevNum;
}

void SpecialPythagoreanTriplet()
{
	bool done = false;

	const int TOTAL = 1000;

	while (!done)
	{
		for (int a = 1; a < TOTAL; a++)
		{
			for (int b = a + 1; b < TOTAL; b++)
			{
				for (int c = b + 1; c < TOTAL; c++)
				{
					if ((pow(a, 2) + pow(b, 2)) == pow(c, 2))
					{
						printf("%d^2 + %d^2 = %d^2\n", a, b, c);
						if ((a + b + c) == TOTAL)
						{
							printf("\n\n\n");
							printf("%d^2 + %d^2 = %d^2\n", a, b, c);
							printf("%d * %d * %d = %d", a, b, c, (a * b * c));
							done = true;
						}
					}
					if (done)
						break;
				}
				if (done)
					break;
			}
			if (done)
				break;
		}
	}
}

void SummationOfPrimes(const int max)
{	
	//Sieve of Eratosthenes

	uint64_t sum = 0;

	std::vector<bool> primes(max);

	std::fill(primes.begin(), primes.end(), true);

	for (int i = 2; i < max; i++)
		if (i <= sqrt(max) && primes[i] == true)
			for (int j = pow(i, 2); j < max; j++)
				if (j % i == 0)
					primes[j] = false;

	for (int i = 2; i < max; i++)
		if (primes[i] == true)
			sum += i;

	std::cout << sum << std::endl;
}

int main()
{
	//MultiplesOf3_And_5(1000);				1
	//EvenValueFibonacci(4'000'000);		2
	//LargestPrimeFactor(600851475143);		3
	//LargestPalindromeProduct(3);			4
	//SmallestMultiple();					5
	//SumSquareDifference(100);				6
	//TenThousandAndOnePrime();				7
	//LargestProductInSeries(13);			8
	//SpecialPythagoreanTriplet();			9
	SummationOfPrimes(2000000);

	int k;
	std::cin >> k;
	return 0;
}