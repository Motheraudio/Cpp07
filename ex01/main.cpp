#include <iostream>
#include "iter.hpp"
class Hehe
{
public:
Hehe() : x(67) {}
int whatsx() const {return (this->x);}
int x;
};
std::ostream & operator<<(std::ostream &os, Hehe const &member) {
	os << member.whatsx();
	return os;}
template< typename T >
void print(T const &x) {std::cout << x << std::endl; return;}
void addone (Hehe &y) {y.x += 1;}
int main()
{
	int one[] = { 6, 7, 6, 7, 6, 7, 6};
	Hehe two[7];
	iter(one, 7, print);
	iter(two, 7, print);
	iter(two, 7, addone);
	iter(two, 7, print);
}
