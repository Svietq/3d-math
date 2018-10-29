#include <iostream>
#include <vector>
#include <cmath>

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

Scalar coeff(Scalar a1, Scalar a2, Scalar b1, Scalar b2)
{
	return a1 * b2 - a2 * b1;
}

Vec cross_product(const Vec & vec1, const Vec & vec2)
{
	return Vec{ coeff(vec1[Y], vec1[Z], vec2[Y], vec2[Z]),
			   -coeff(vec1[X], vec1[Z], vec2[X], vec2[Z]),
				coeff(vec1[X], vec1[Y], vec2[X], vec2[Y]) };
}

Scalar length(const Vec & vec)
{
	using std::pow;
	return pow(pow(vec[X], 2) + pow(vec[Y], 2) + pow(vec[Z], 2), 0.5);
}

int main() 
{
	Vec vec1{ 1, 2, 3 };
	Vec vec2{ 4, 5, 6 };

	print(add(vec1, vec2));
	print(dot_product(vec1, vec2));
	print(cross_product(vec1, vec2));
	print(length(vec1));

	std::cin.get();
}