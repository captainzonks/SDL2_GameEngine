#include <iostream>
#include <memory>
#include <ctime>

#include "Boundary.h"
#include "Point.h"
#include "QuadTree.h"

int main()
{
	std::srand((unsigned int)std::time(nullptr));

	std::shared_ptr<Boundary> boundary = std::make_unique<Boundary>(200, 200, 200, 200);

	std::shared_ptr<QuadTree> qt = std::make_unique<QuadTree>(boundary, 4);

	for (size_t i{}; i < 500; i++)
	{
		std::shared_ptr<Point> p = std::make_unique<Point>(rand() % 400 + 1, rand() % 400 + 1);
		qt->Insert(*p);
	}

	return 0;
}