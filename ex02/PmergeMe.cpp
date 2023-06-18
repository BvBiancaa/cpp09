#include "PmergeMe.hpp"

P::P()
{
	return ;
}

P::P(long int i)
{
	this->vec.reserve(i - 1);
	this->second.reserve(i / 2);
	ac = i;
	return ;
}

P::P(const P &cpy)
{
	this->vec = cpy.vec;
	this->second = cpy.second;
	this->first_h = cpy.first_h;
	this->second_h = cpy.second_h;
	this->ac = cpy.ac;
	return ;
}

P &P::operator=(const P &cpy)
{
	this->vec = cpy.vec;
	this->second = cpy.second;
	this->first_h = cpy.first_h;
	this->second_h = cpy.second_h;
	this->ac = cpy.ac;
	return (*this);
}

P::~P()
{
	return ;
}

time_t	ft_sort_list(P &p)
{
	struct timeval time_now;
   	gettimeofday(&time_now, NULL);
    	time_t msecs_time = time_now.tv_usec;
	for (unsigned int i = 0; i < p.vec.size() / 2; i++)
		p.first_h.push_back(p.vec[i]);
	for (unsigned int i = p.vec.size() / 2; i < p.vec.size(); i++)
		p.second_h.push_back(p.vec[i]);
	p.first_h.sort();
	p.second_h.sort();
	p.first_h.insert(p.first_h.end(), p.second_h.begin(), p.second_h.end() );
	p.first_h.sort();
	gettimeofday(&time_now, NULL);
	time_t now = time_now.tv_usec;
	return (now - msecs_time);
}

time_t ft_sort_vec(P &p)
{
	struct timeval time_now;
   	gettimeofday(&time_now, NULL);
    	time_t msecs_time = time_now.tv_usec;
	unsigned int x = p.vec.size();
	for (unsigned int i = x - 1; i > x / 2; i--)
	{
		p.second.push_back(p.vec[i]);
		p.vec.pop_back();
	}
	std::sort(p.second.begin(), p.second.end());
	std::sort(p.vec.begin() + p.vec.size(), p.vec.end());
	p.vec.insert(p.vec.end(), p.second.begin(), p.second.end());
	std::sort(p.vec.begin(), p.vec.end());
	gettimeofday(&time_now, NULL);
	time_t now = time_now.tv_usec;
	return (now - msecs_time);
}

double	to_sec(double t)
{
	return (t / 10000);
}

int	Pmerge(P &p)
{
	double timeVec;
	double timeList;
	std::cout << "Before:  ";
	for (unsigned long int i = 0; i < p.vec.size(); i++)
		std::cout << p.vec[i] << " ";
	std::cout << std::endl;
	timeList = to_sec(ft_sort_list(p));
	timeVec = to_sec(ft_sort_vec(p));
	std::cout << "After:  ";
	/* for (std::list<int>::iterator it=p.first_h.begin(); it!=p.first_h.end(); ++it)
    		std::cout << ' ' << *it; */
	for (unsigned long int i = 0; i < p.vec.size(); i++)
		std::cout << p.vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << p.ac << " elements with std::list : " << timeList << " us" << std::endl;
	std::cout << "Time to process a range of " << p.ac << " elements with std::vector : " << timeVec << " us" << std::endl;
	return (0);
}