#include <iostream>

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

int main()
{
	MultiplesOf3_And_5(1000);


	int k;
	std::cin >> k;
	return 0;
}