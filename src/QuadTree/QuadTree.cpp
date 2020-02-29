#include "./QuadTree.h"

//QuadTree::QuadTree()
//{
//}
//
//QuadTree::QuadTree(int pLevel, Boundary boundary)
//{
//	this->boundary = boundary;
//	this->level = pLevel;
//}

/*
 * Splits the node into 4 subnodes
 */
//void QuadTree::Subdivide()
//{
//	int x = (int)this->boundary.x;
//	int y = (int)this->boundary.y;
//	int subWidth = (int)(this->boundary.w / 2);
//	int subHeight = (int)(this->boundary.h / 2);
//
//	nodes.push_back(QuadTree(level + 1, Boundary(x + subWidth, y, subWidth, subHeight)));
//	nodes.push_back(QuadTree(level + 1, Boundary(x, y, subWidth, subHeight)));
//	nodes.push_back(QuadTree(level + 1, Boundary(x, y + subHeight, subWidth, subHeight)));
//	nodes.push_back(QuadTree(level + 1, Boundary(x + subWidth, y + subHeight, subWidth, subHeight)));
//}

/*
 * Determine which node the object belongs to. -1 means
 * object cannot completely fit within a child node and is part
 * of the parent node
 */
//int QuadTree::GetIndex(Entity entity)
//{
//	double xPosition{ static_cast<double>(entity.GetComponent<TransformComponent>()->position.x) };
//	double yPosition{ static_cast<double>(entity.GetComponent<TransformComponent>()->position.y) };
//	double width{ static_cast<double>(entity.GetComponent<TransformComponent>()->width) };
//	double height{ static_cast<double>(entity.GetComponent<TransformComponent>()->height) };
//
//	int index{ -1 };
//	double verticalMidpoint = xPosition + (width / 2);
//	double horizontalMidpoint = yPosition + (height / 2);
//
//	// Object can completely fit within the top quadrants
//	bool topQuadrant = (yPosition < horizontalMidpoint && yPosition + height < horizontalMidpoint);
//	// Object can completely fit within the bottom quadrants
//	bool bottomQuadrant = (yPosition > horizontalMidpoint);
//
//	// Object can completely fit within the left quadrants
//	if (xPosition < verticalMidpoint && xPosition + width < verticalMidpoint) {
//		if (topQuadrant) {
//			index = 1;
//		}
//		else if (bottomQuadrant) {
//			index = 2;
//		}
//	}
//	// Object can completely fit within the right quadrants
//	else if (xPosition > verticalMidpoint) {
//		if (topQuadrant) {
//			index = 0;
//		}
//		else if (bottomQuadrant) {
//			index = 3;
//		}
//	}
//
//	return index;
//}

/*
 * Insert the object into the quadtree. If the node
 * exceeds the capacity, it will split and add all
 * objects to their corresponding nodes.
 */
void QuadTree::Insert(Entity&& entity)
{
	if (n_ == MAX_N) {
		double w4 = whalf_ / 2,
			h4 = hhalf_ / 2;
		nw_ = std::unique_ptr<QuadTree>(new QuadTree(x_ - w4, y_ - h4, whalf_, hhalf_));
		ne_ = std::unique_ptr<QuadTree>(new QuadTree(x_ + w4, y_ - h4, whalf_, hhalf_));
		se_ = std::unique_ptr<QuadTree>(new QuadTree(x_ + w4, y_ + h4, whalf_, hhalf_));
		sw_ = std::unique_ptr<QuadTree>(new QuadTree(x_ - w4, y_ + h4, whalf_, hhalf_));
	}

	if (n_ >= MAX_N) {
		auto ent = std::move(entity);
		if (ent.GetComponent<TransformComponent>()->position.x < y_) {
			if (ent.GetComponent<TransformComponent>()->position.x < x_) {
				nw_->Insert(std::move(ent));
			}
			else {
				ne_->Insert(std::move(ent));
			}
		}
		else {
			if (ent.GetComponent<TransformComponent>()->position.x < x_) {
				sw_->Insert(std::move(ent));
			}
			else {
				se_->Insert(std::move(ent));
			}
		}
	}
	else {
		entities_[n_] = std::move(entity);
	}

	n_++;
}

void QuadTree::Traverse(std::function<void(const QuadTree&, unsigned)> fn, unsigned depth)
{
	fn(*this, depth);
	if (n_ > MAX_N) {
		nw_->Traverse(fn, depth + 1);
		ne_->Traverse(fn, depth + 1);
		se_->Traverse(fn, depth + 1);
		sw_->Traverse(fn, depth + 1);
	}
}

/*
 * Return all objects that could collide with the given object
 */
//std::vector<Entity> QuadTree::Retrieve(std::vector<Entity> returnEntities, Entity entity)
//{
//	int index{ GetIndex(entity) };
//	if (index != -1 && nodes.size() != 0)
//	{
//		nodes[index].Retrieve(returnEntities, entity);
//	}
//
//	returnEntities.insert(std::end(returnEntities), std::begin(entities), std::end(entities));
//
//	return returnEntities;
//}

/*
 * Clears the quadtree
 */
//void QuadTree::Clear()
//{
//	entities.clear();
//	nodes.clear();
//}