#pragma once
#include <vector>
#include "Collider.h"

class PhysicsEntity :public GameEntity {
protected:
	Collider* collider;

public:
	PhysicsEntity();
	virtual ~PhysicsEntity();

	bool CheckCollision(PhysicsEntity* other);
	bool CheckTopCollision(PhysicsEntity* other);
	bool CheckBottomCollision(PhysicsEntity* other);
	bool CheckLeftCollision(PhysicsEntity* other);
	bool CheckRightCollision(PhysicsEntity* other);

	virtual void Render();

protected:

	void AddCollider(Vector2 size, Vector2 localPos = VEC2_ZERO);
};