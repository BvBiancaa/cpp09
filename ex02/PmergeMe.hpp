#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <sys/time.h>
#include <ctime>

class P
{
	public:
	P();
	P(long int i);
	P(const P &cpy);
	P &operator=(const P &cpy);
	~P();
	std::vector<int> vec, second;
	std::list<int> first_h, second_h;
	int	ac;
};

int	Pmerge(P &p);

#endif