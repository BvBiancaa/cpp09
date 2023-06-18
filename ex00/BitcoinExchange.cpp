#include "BitcoinExchange.hpp"

int	check_existence(std::string s)
{
	if (strstr(s.c_str(), " | ") == NULL)
		return (1);
	int x = atoi(s.c_str() + 5);
	int d = atoi(s.c_str() + 8);
	if (x < 1 || x > 12 || d < 1 || d > 32)
		return (1);
	return (0);
}
std::string get_first_db_arg(std::string s)
{
	std::string ret;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] != ',')
			ret += s[i];
		if (s[i] == ',')
			break ;
	}
	return (ret);
}

std::string get_second_db_arg(std::string s)
{
	std::string ret;
	unsigned long int pos = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == ',')
		{
			pos = i + 1;
			break ;
		}
	}
	while (pos < s.length())
	{
		ret += s[pos];
		pos++;
	}
	return (ret);
}

std::string get_first_arg(std::string s)
{
	std::string ret;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] != ' ')
			ret += s[i];
		if (s[i] == ' ' && s[i + 1]  == '|')
			break ;
	}
	return (ret);
}

std::string get_second_arg(std::string s)
{
	std::string ret;
	unsigned long int pos = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == ' ' && s[i + 1]  == '|')
		{
			pos = i + 2;
			break ;
		}
	}
	while (pos < s.length())
	{
		ret += s[pos];
		pos++;
	}
	return (ret);
}

float	ft_get_real_arg(std::string date)
{
	std::fstream db;
	db.open("data.csv");
	std::string read;
	std::string save;
	std::getline(db, read);
	while (std::getline(db, read))
	{
		if (get_first_db_arg(read) == date)
		{
			save = read;
			break ;
		}
		else if (get_first_db_arg(read) >= date)
			break ;
		save = read;
	}
	db.close();
	return(atof(get_second_db_arg(save).c_str()));
}

void	ft_print(std::string date, float n, std::string read)
{
	if (check_existence(read))
	{
		std::cout << " Error: bad input => " << date << std::endl;
		return ;
	}
	float i = ft_get_real_arg(date);
	long int x = n;
	if (i == -1)
		std::cout << date << " => " << n << " = " << "No data" << std::endl;
	else if (n > 0 && x < MAX_NBR)
		std::cout << date << " => " << n << " = " << i * n << std::endl;
	else if (x > MAX_NBR)
		std::cout << "Error: too large a number." << std::endl;
	else if (n < 0)
		std::cout << "Error: negative number." << std::endl;
}

void	exchange(std::string file)
{
	std::map<std::string, float> Map;
	std::fstream fi;
	fi.open(file.c_str());
	if (!fi.is_open())
	{
		try
		{
			throw std::invalid_argument("Error: could not open file.");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::string read;
	std::string date;
	float n;
	while (std::getline(fi, read))
	{
		date = get_first_arg(read);
		n = atof(get_second_arg(read).c_str());
		Map[date]= n;
		ft_print(date, Map[date], read);
	}
	fi.close();
}