#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define MAX_NBR 2147483647

#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

void	exchange(std::string file);
int	check_csv(std::string file);

#endif