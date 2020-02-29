#ifndef QUADTREE_H
#define QUADTREE_H

#include "Boundary.h"
#include "../Entity.h"

#include <array>
#include <functional>
#include <memory>
#include <string>

class QuadTree
{
private:
	int MAX_OBJECTS = 10;
	int MAX_LEVELS = 5;
	int level{};

	std::vector<QuadTree> nodes;

	const double x_, y_, whalf_, hhalf_;
	unsigned n_;
	
	std::unique_ptr<QuadTree> nw_, ne_, se_, sw_;

public:
	//QuadTree();
	//QuadTree(int pLevel, Boundary boundary);
	/*int GetIndex(Entity entity);
	void Insert(Entity&& entity);
	void Subdivide();
	std::vector<Entity> Retrieve(std::vector<Entity> returnEntities, Entity entity);
	void Clear();
	Boundary boundary;
	std::vector<Entity> entities;*/

	static const unsigned int MAX_N = 4;
	QuadTree(double x, double y, double width, double height) : x_(x), y_(y), whalf_(width / 2), hhalf_(height / 2), n_(0) {}
	void Insert(Entity&&);
	void Traverse(std::function<void(const QuadTree&, unsigned)> fn, unsigned depth);
	double x() const {
		return x_;
	}
	double y() const {
		return y_;
	}
	std::array<Entity, MAX_N> entities_;

};



#endif // !QUADTREE_H