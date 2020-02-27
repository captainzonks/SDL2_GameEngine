#ifndef QUADTREE_H
#define QUADTREE_H

class Quadtree
{
private:
	int MAX_OBJECTS = 10;
	int MAX_LEVELS = 5;

	int level;
	vector<Entity*> entities;
	SDL_Rect rectangleBounds;

};

#endif // !QUADTREE_H
