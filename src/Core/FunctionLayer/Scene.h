/**
 * @file Scene.h
 * @author orbitchen
 * @brief Scene representation. Handle ray intersection.
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "Entity.h"
#include "Accelerator.h"
#include "Ray.h"
#include "Intersection.h"
#include "Light.h"

#include <optional>

class Scene
{
	std::unique_ptr<Accelerator> accelerator;
	std::shared_ptr<std::vector<std::shared_ptr<Light>>> lights;
	std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities;

public:
	Scene();
	void addEntity(std::shared_ptr<Entity> object);
	void addLight(std::shared_ptr<Light> light);

	std::optional<Intersection> intersect(const Ray &r) const;

	// @return true if r hits object first (closest), false otherwise.
	bool intersectionTest(const Ray &r, std::shared_ptr<Entity> object) const;

	std::shared_ptr<std::vector<std::shared_ptr<Light>>> getLights() const;
};