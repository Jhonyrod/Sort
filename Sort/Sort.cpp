// Sort.cpp : Defines the entry point for the console application.
//

#include "Algos.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<long long>	arr;
	long long				tmp;
	bool					cnt=false;

	std::cout	<< "Enter the numbers in your array or enter any non number to stop...\n";

	do
	{
		if (cnt)
		{
			std::cout << "Array can't be of zero length, please try again...\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		std::cin >> tmp;
		cnt = std::cin.fail();
	} while (cnt);

	do
	{
		arr.push_back(tmp);
		std::cin >> tmp;
	} while (!std::cin.fail());

	std::cin.clear();
	std::cin.ignore(32767, '\n');

	std::cout << "Select algorithm:\n0.STL.\n1.Single Threaded.\n2.MultiThreaded.\n";

	do
	{
		if (cnt && tmp > 2)
		{
			std::cout << "Select a valid option...\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		std::cin >> tmp;
		cnt = std::cin.fail();
	} while (cnt && tmp > 2);

	auto start = clock();

	switch (tmp)
	{
	case 0:
		std::sort(arr.rbegin(), arr.rend());
		break;
	case 1:
//		nSTQSort(arr);
		break;
	case 2:
		nMTQSort(arr);
		break;
	}

	auto stop = clock();

	std::cout << "\nThe sorted elements are:\n";
	for (const auto& i : arr)
		std::cout << i << '\n';

	std::cout << "And it took " << stop - start << " somethingseconds to complete.\n";

	if (!std::is_sorted(arr.rbegin(), arr.rend()))
		std::cout << "But sadly the array isn't sorted..." << std::endl;
	return 0;
	}