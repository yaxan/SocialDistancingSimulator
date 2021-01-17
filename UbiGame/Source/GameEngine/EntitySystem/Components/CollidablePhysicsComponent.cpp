#include "CollidablePhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameBoard.h"


#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
{

}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	__super::OnAddToWorld();
}


void CollidablePhysicsComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			int itemid = colComponent->GetEntity()->itemid;
			int someotherid = colComponent->GetEntity()->someotherId;

			if (itemid == -1) {
				continue;
			}

			printf("%d\n", itemid);

			if (itemid == 1) {

			}
			if (itemid == 2) {
				GameEngineMain::GetInstance()->m_gameBoard->ClearObstacles(GameEngineMain::GetInstance()->m_gameBoard->m_somegodid());
			}
			if (itemid == 3) {
				GameEngineMain::GetInstance()->m_gameBoard->PickUpItem(colComponent->GetEntity());
			}
			if (itemid == 4) {
				GameEngineMain::GetInstance()->m_gameBoard->PickUpBadItem();
			}
			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;
			}

			GetEntity()->SetPos(pos);
		}
	}
}