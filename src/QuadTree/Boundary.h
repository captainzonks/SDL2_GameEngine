#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "../Entity.h"
#include "../Component.h"
#include "../Components/TransformComponent.h"

class Boundary
{
private:

public:
	Boundary();
	Boundary(int x, int y, int w, int h);
	int x{};
	int y{};
	int w{};
	int h{};

	bool Contains(Entity& entity);
};

#endif // !BOUNDARY_H