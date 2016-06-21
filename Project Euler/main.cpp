#include <iostream>
#include <vector>

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

int main()
{
	//MultiplesOf3_And_5(1000);
	EvenValueFibonacci(4'000'000);

	int k;
	std::cin >> k;
	return 0;
}