#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		try
		{
			throw std::invalid_argument("Error: could not open file.");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (1);
	}
	exchange(av[1]);
}
