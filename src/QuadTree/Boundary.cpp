#include "Boundary.h"

Boundary::Boundary()
{
}

Boundary::Boundary(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Boundary::Contains(Entity& entity)
{
	TransformComponent* transform = entity.GetComponent<TransformComponent>();

	return (transform->position.x > this->x - this->w &&
		transform->position.x < this->x + this->w &&
		transform->position.y > this->x - this->h &&
		transform->position.y < this->y + this->h);
}