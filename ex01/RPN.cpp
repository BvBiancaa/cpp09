#include "RPN.hpp"

int	check_last(std::string input, unsigned long int i)
{
	if (i != 0 && i < input.length() - 1 && input[i - 1] == ' ' && input[i + 1] == ' ')
		return (0);
	else if (i == 0 || i == input.length() - 1)
		return (0);
	else
		return (1);
}

int	is_valid(std::string input, unsigned long i)
{
	if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		return (check_last(input, i));
	else if (input[i] >= 48 && input[i] <= 57)
		return (check_last(input, i));
	else if (input[i] == ' ')
		return (0);
	else
		return (1);
}

int RPN(std::string input)
{
	unsigned long int i = 0;
	std::deque<int> arr, sign;
	while (input[i])
	{
		if (is_valid(input, i) == 0)
		{
			if (input[i] != ' ' && input[i] >= 48 && input[i] <= 57)
				arr.push_back(input[i]);
			else if (input[i] != ' ' && (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
				sign.push_back(input[i]);
			i++;
		}
		else
			return (1);
	}
	for (unsigned long int i = 0; i < arr.size(); i++)
		std::cout << static_cast<char>(arr[i]) << std::endl;
	for (unsigned long int i = 0; i < sign.size(); i++)
		std::cout << static_cast<char>(sign[i]) << std::endl;
	int result = arr[0] - 48;
	i = 0;
	while (i < arr.size() - 1 && i < sign.size())
	{
		std::cout << result << "  " << static_cast<char>(sign[i]) << "  " << arr[i + 1] - 48 << "   ";
		if (sign[i] == '+')
			result += (arr[i + 1] - 48);
		else if (sign[i] == '-')
			result -= (arr[i + 1] - 48);
		else if (sign[i] == '*')
			result *= (arr[i + 1] - 48);
		else if (sign[i] == '/')
			result /= (arr[i + 1] - 48);
		i++;
		std::cout << result << std::endl;
	}
	std::cout << result << std::endl;
	return (0);
}