#include "PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Components/PawnPhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/System/Vector2.hpp"
#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent() 
	: m_animComponent(nullptr)
	, m_speed(300.f)
{

}

PlayerMovementComponent::~PlayerMovementComponent() {

}

void PlayerMovementComponent::OnAddToWorld() {
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
}

void PlayerMovementComponent::Update() {
	__super::Update();

	//Grabs how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default the wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	//player Velocity is applied when we have some input (for the time being let's make it 10pixels a second)
	float playerVel = m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			wantedVel.x -= playerVel * dt;
		}
		else { wantedVel.x -= playerVel / 2 * dt; }

		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkLeft &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkLeft);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			wantedVel.x += playerVel * dt;
		}
		else { wantedVel.x += playerVel / 2 * dt; }
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkRight &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkRight);
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			wantedVel.y -= playerVel * dt;
		}
		else { wantedVel.y -= playerVel / 2 * dt; }
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkUp)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkUp);
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			wantedVel.y += playerVel * dt;
		}
		else { wantedVel.y += playerVel / 2 * dt; }
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::walkDown)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::walkDown);
			}
		}
	}

	if (wantedVel == sf::Vector2f(0.f, 0.f))
	{
		if (m_animComponent)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::idle)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::idle);
			}
		}
	}
	//Update the entity position with new velocity
	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}



void PlayerMovementComponent::SlowPlayer(int amount) {
	m_speed -= amount;
}
