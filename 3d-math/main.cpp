#include <iostream>
#include <vector>

using Vec = std::vector<double>;
using Scalar = double;
enum {X = 0, Y = 1, Z = 2};

void print(const Vec & vec)
{
	for (auto x : vec)
	{
		std::cout << x << ", ";
	}

	std::cout << '\n';
}

void print(Scalar num)
{
	std::cout << num << '\n';
}

Vec add(const Vec & vec1, const Vec & vec2)
{
	auto vec = Vec{ vec1[X] + vec2[X], vec1[Y] + vec2[Y], vec1[Z] + vec2[Z] };
	return vec;
}

Scalar dot_product(const Vec & vec1, const Vec & vec2)
{
	return vec1[X] * vec2[X] + vec1[Y] * vec2[Y] + vec1[Z] * vec2[Z];
}

int main() 
{
	Vec vec1{ 1, 2, 3 };
	Vec vec2{ 3, 4, 5 };

	print(add(vec1, vec2));
	print(dot_product(vec1, vec2));

	std::cin.get();
}