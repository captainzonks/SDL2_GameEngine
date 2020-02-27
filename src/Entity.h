#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <map>
#include <typeinfo>
#include "./Constants.h"
#include "./EntityManager.h"
#include "./Component.h"

class EntityManager;
class Component;

class Entity
{
private:
	EntityManager& manager;
	bool isActive;
	std::vector<Component*> components;
	std::map<const std::type_info*, Component*> componentTypeMap;
public:
	std::string name;
	LayerType layer;
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name, LayerType layer);
	void Update(float deltaTime);
	void Render();
	void Destroy();
	bool IsActive() const;
	void ListAllComponents() const;

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->owner = this;
		components.emplace_back(newComponent);
		componentTypeMap[&typeid(*newComponent)] = newComponent;
		newComponent->Initialize();
		return *newComponent;
	}

	template <typename T>
	T* GetComponent()
	{
		return static_cast<T*>(componentTypeMap[&typeid(T)]);
	}

	template <typename T>
	bool HasComponent() const
	{
		auto search = componentTypeMap.find(&typeid(T));
		if (search != componentTypeMap.end())
		{
			std::cout << "True" << std::endl; // debug output
			return true;
		}
		else
		{
			std::cout << "False" << std::endl; // debug output
			return false;
		}
	}
};

#endif // !ENTITY_H