#include "PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Components/PawnPhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/System/Vector2.hpp"

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent() 
	: m_lastFaceIndex(0)
{

}

PlayerMovementComponent::~PlayerMovementComponent() {

}

void PlayerMovementComponent::OnAddToWorld() {
	__super::OnAddToWorld();
}

void PlayerMovementComponent::Update() {
	__super::Update();

	float playerVelocity = 100.f;

	sf::Vector2f wantedVelocity = sf::Vector2f(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		wantedVelocity.x -= playerVelocity;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		wantedVelocity.x += playerVelocity;
	}

	int maxFaces = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		m_wasFaceSwapButtonPressed = true;
	}
	else {
		if (m_wasFaceSwapButtonPressed) {
			GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
			if (animComponent)
			{
				animComponent->SetIsLooping(false);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWink);
			}
		}
	}

	PawnPhysicsComponent* pawnPhys = GetEntity()->GetComponent<PawnPhysicsComponent>();
	if (pawnPhys) {
		pawnPhys->SetVelocity(wantedVelocity);
	}


}