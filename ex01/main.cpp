#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		try
		{
			throw std::invalid_argument("Error: One input required.");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (1);
	}
	if (RPN(av[1]) == 1)
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
	};
}