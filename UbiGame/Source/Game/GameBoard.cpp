#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "Game/Components/playerCameraCompenent.h"
#include "Game/Components/LinkedEntitycomponent.h"
#include "Game/Components/PawnPhysicsComponent.h"

using namespace Game;

GameBoard::GameBoard()
	:m_player(nullptr)
{
	CreatePlayer();
	CreateObstacle();
	CreateBackground();
}


GameBoard::~GameBoard()
{
	
}

void GameBoard::CreatePlayer() {
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.f, 50.f));
	m_player->SetSize(sf::Vector2f(50.f, 50.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(m_player->AddComponent <GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Player);

	//Movement
	m_player->AddComponent<PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::AnimationComponent>();

	m_player->AddComponent<PawnPhysicsComponent>();

	m_player->AddComponent<playerCameraComponent>();

	
}

void GameBoard::CreateObstacle() {
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(350.f, 50.f));
	obstacle->SetSize(sf::Vector2f(150.f, 150.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateBackground() {
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(250.f, 250.f));
	background->SetSize(sf::Vector2f(800.f, 600.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(background->AddComponent<GameEngine::SpriteRenderComponent>());

	render->SetTexture(GameEngine::eTexture::Background);
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);

	LinkedEntityComponent* linkedCmp = static_cast<LinkedEntityComponent*>(background->AddComponent<LinkedEntityComponent>());

	linkedCmp->SetFollowedEntity(m_player);
	linkedCmp->SetFollowOffset(sf::Vector2f(0.f, 0.f));
}

void GameBoard::Update()
{	
	
}