#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>

#include "./Entity.h"
#include "./Component.h"

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	void ClearData();
	void Update(float deltaTime);
	void Render();
	bool HasNoEntities() const;
	unsigned int GetEntityCount();
	void ListAllEntities() const;
	std::vector<Entity*> GetEntities() const;
	std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
	Entity& AddEntity(std::string entityName, LayerType layer);


};

#endif // !ENTITYMANAGER_H
