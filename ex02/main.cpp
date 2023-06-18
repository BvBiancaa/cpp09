#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	P p(ac);

	if (ac < 2)
	{
		try
		{
			throw std::invalid_argument("Error: Not enough arguments.");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		p.vec.push_back(atoi(av[i]));
		if (p.vec[i - 1] < 0)
		{
			try
			{
				throw std::invalid_argument("Error: Numbers must be positive.");
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			return (1);
		}
	}
	if (Pmerge(p) == 1)
	{
		try
		{
			throw std::invalid_argument("Error");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (1);
	}
}