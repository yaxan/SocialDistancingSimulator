#include "npcMovementController.h"
#include "GameEngine\GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\Util\AnimationManager.h"
using namespace Game;


npcMovementController::npcMovementController()
	: m_animComponent(nullptr)
	, npcNum(0)
	, t(0.f)
	, playerVel(100.f)
	, index(0)

{

}

npcMovementController::~npcMovementController()
{

}

void npcMovementController::OnAddToWorld()
{
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
	switch (npcNum)
	{
	case 0:
		t = 5.f;
		break;
	case 1:
		t = 3.f;
		times.push_back(3.f);
		times.push_back(4.f);
		times.push_back(4.f);
		times.push_back(3.f);
		directions.push_back(0.f);
		directions.push_back(1.f);
		directions.push_back(2.f);
		directions.push_back(3.f);

		break;
	case 2:
		t = 3.f;
		times.push_back(3.f);
		times.push_back(4.f);
		times.push_back(2.f);
		times.push_back(2.f);
		times.push_back(4.f);
		times.push_back(3.f);
		directions.push_back(3.f);
		directions.push_back(1.f);
		directions.push_back(0.f);
		directions.push_back(3.f);
		directions.push_back(2.f);
		directions.push_back(0.f);

		break;
	case 3:
		t = (float)3.5;
		times.push_back((float)3.5);
		times.push_back((float)3.5);
		times.push_back((float)3.5);
		times.push_back(3.f);
		times.push_back(3.f);
		times.push_back((float)3.5);
		directions.push_back(1.f);
		directions.push_back(2.f);
		directions.push_back(1.f);
		directions.push_back(3.f);
		directions.push_back(0.f);
		directions.push_back(2.f);

		break;
	case 4:
		t = 5.f;
		break;
	case 5:
		t = 3.f;
		break;
	case 6:
		t = 3.f;
		times.push_back(3.f);
		times.push_back(3.f);
		times.push_back(3.f);
		times.push_back(3.f);
		directions.push_back(0.f);
		directions.push_back(1.f);
		directions.push_back(3.f);
		directions.push_back(2.f);
	case 7:
		t = 3.f;
		break;
	case 8:
		t = 2.f;
		times.push_back(2.f);
		times.push_back(2.f);
		times.push_back(2.f);
		times.push_back(2.f);
		directions.push_back(3.f);
		directions.push_back(2.f);
		directions.push_back(0.f);
		directions.push_back(1.f);
	}

}

void npcMovementController::Update()
{
	__super::Update();
	//how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	//player vel is applied when we have some input (10pixels/sec)

	if (npcNum == 0)
	{
		t -= dt;
		if (t <= 0)
		{
			t = 5.f;
			playerVel *= -1.f;
		}
		wantedVel.y += playerVel * dt;
		upOrDown(m_animComponent, playerVel);
	}
	if (npcNum == 1)
	{
		t -= dt;
		dir(directions[index], m_animComponent, playerVel, dt, wantedVel);
		if (t <= 0)
		{
			if (index > 2) index = 0;
			else index++;
			t = times[index];
		}

	}
	if (npcNum == 2)
	{
		t -= dt;
		dir(directions[index], m_animComponent, 150.f, dt, wantedVel);
		if (t <= 0)
		{
			if (index > 4) index = 0;
			else index++;
			t = times[index];
		}

	}
	if (npcNum == 3)
	{
		t -= dt;
		dir(directions[index], m_animComponent, 150.f, dt, wantedVel);
		if (t <= 0)
		{
			if (index > 4) index = 0;
			else index++;
			t = times[index];
		}

	}
	if (npcNum == 4)
	{
		t -= dt;
		if (t <= 0)
		{
			t = 5.f;
			playerVel *= -1.f;
		}
		wantedVel.y += playerVel * 1.25 * dt;
		upOrDown(m_animComponent, playerVel);
	}
	if (npcNum == 5)
	{
		t -= dt;
		if (t <= 0)
		{
			t = 3.f;
			playerVel *= -1.f;
		}
		wantedVel.x -= playerVel * 1.25 * dt;
		rightOrLeft(m_animComponent, playerVel);
	}
	if (npcNum == 6)
	{
		t -= dt;
		dir(directions[index], m_animComponent, 170.f, dt, wantedVel);
		if (t <= 0)
		{
			if (index > 2) index = 0;
			else index++;
			t = times[index];
		}

	}
	if (npcNum == 7)
	{
		t -= dt;
		if (t <= 0)
		{
			t = 3.f;
			playerVel *= -1.f;
		}
		wantedVel.y += playerVel * 2 * dt;
		upOrDown(m_animComponent, playerVel);
	}
	if (npcNum == 8)
	{
		t -= dt;
		dir(directions[index], m_animComponent, 170.f, dt, wantedVel);
		if (t <= 0)
		{
			if (index > 2) index = 0;
			else index++;
			t = times[index];
		}
	}


	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}

void npcMovementController::upOrDown(GameEngine::AnimationComponent* m_animComponent, float playerVel) {
	if (m_animComponent) {
		if (playerVel < 0)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkUpNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkUpNPC);
			}
		}
		else
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkDownNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkDownNPC);
			}
		}
	}
}

void npcMovementController::dir(int dir, GameEngine::AnimationComponent* m_animComponent, float playerVel, float dt, sf::Vector2f& wantedVel) {
	if (dir == 0)
	{
		wantedVel.x -= playerVel * dt;
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkLeftNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkLeftNPC);
			}
		}
	}
	if (dir == 1)
	{
		wantedVel.y += playerVel * dt;
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkDownNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkDownNPC);
			}
		}
	}
	if (dir == 2)
	{
		wantedVel.y -= playerVel * dt;
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkUpNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkUpNPC);
			}
		}
	}
	if (dir == 3)
	{
		wantedVel.x += playerVel * dt;
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkRightNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkRightNPC);
			}
		}
	}
}

void npcMovementController::rightOrLeft(GameEngine::AnimationComponent* m_animComponent, float playerVel) {
	if (m_animComponent) {
		if (playerVel < 0)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkRightNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkRightNPC);
			}
		}
		else
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkLeftNPC)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkLeftNPC);
			}
		}
	}
}