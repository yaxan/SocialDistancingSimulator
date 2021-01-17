#include "GameBoard.h"

#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine\GameEngineMain.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "Game/Components/playerCameraCompenent.h"
#include "Game/Components/LinkedEntitycomponent.h"
#include "Game/Components/PawnPhysicsComponent.h"
#include "Game/Components/ItemEntity.h"
#include <Game/Components/npcMovementController.h>

using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr)
	, m_gameover(false)
	, m_health(12)
	, m_healthbar(nullptr)
	, m_weight(0)
	, m_points(0)
	, m_id(1)
	, m_backgroundid(1)

{
	CreatePlayer();
	CreatePoints();
	CreateBackground(m_backgroundid);
	HealthBar();
	SpawnRoomItems(1);
	//OBSTACLES AND NPCS FOR INDOOR SUPERMARKET
	

	//OBSTACLES AND NPCS FOR INDOOR SUPERMARKET
}


GameBoard::~GameBoard()
{
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(700.f, 900.f));
	m_player->SetSize(sf::Vector2f(112, 128.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Player);


	m_player->AddComponent<PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::AnimationComponent>();
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
}



void GameBoard::HealthBar() {
	GameEngine::Entity* healthbar = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(healthbar);

	healthbar->SetPos(sf::Vector2f(130.f, 30.f));
	healthbar->SetSize(sf::Vector2f(250.f, 50.f));


	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(healthbar->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::HealthBar);
	spriteRender->SetZLevel(1);
	spriteRender->SetTileIndex(11, 0);
	m_healthbar = healthbar;

}



void GameBoard::CreateNewItem(const sf::Vector2f& position, const sf::Vector2f& size, int itemtexture, int _setzlevel, int _itemid, int _weight, int _points, int _damage) {
	ItemEntity* item = new ItemEntity(2, _setzlevel, _itemid, _weight, _points, _damage);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(item);
	item->SetPos(position);
	item->SetSize(size);
	
	m_obstacles.push_back(item);
}



void GameBoard::SpawnRoomItems(int id) {
	if (id == 1) {
		CreateNewItem(sf::Vector2f(530.f, 410.f), sf::Vector2f(460.f, 40.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(0.f, 0.f), sf::Vector2f(200.f, 2160.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(200.f, 750.f), sf::Vector2f(450.f, 50.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(470.f, 750.f), sf::Vector2f(85.f, 200.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(600.f, 0.f), sf::Vector2f(1000.f, 150.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1150.f, 0.f), sf::Vector2f(30.f, 400.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1450.f, 0.f), sf::Vector2f(30.f, 700.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1670.f, 620.f), sf::Vector2f(480.f, 50.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1570.f, 1000.f), sf::Vector2f(480.f, 200.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1900.f, 850.f), sf::Vector2f(100.f, 500.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(0.f, 2160.f), sf::Vector2f(3840.f, 2160.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1700.f, -20.f), sf::Vector2f(500.f, 50.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(3840.f, 0.f), sf::Vector2f(3840.f, 2160.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1300.f, 0.f), sf::Vector2f(200.f, 200.f), -1, -2, 2, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1450.f, 275.f), sf::Vector2f(100.f, 100.f), 100, 0, 3, 10, 20, 100);
		CreateNewItem(sf::Vector2f(450.f, 400.f), sf::Vector2f(100.f, 100.f), 100, 0, 3, 10, 20, 101);
		CreateNewItem(sf::Vector2f(1550.f, 620.f), sf::Vector2f(100.f, 100.f), 100, 0, 3, 10, 20, 102);
		CreateNewItem(sf::Vector2f(200.f, 750.f), sf::Vector2f(100.f, 100.f), 100, 0, 3, 10, 20, 104);
		CreateNewItem(sf::Vector2f(530.f, 60.f), sf::Vector2f(100.f, 100.f), 100, 0, 3, 10, 20, 103);
		CreateNPC(0);
		CreateNPC(1);
		CreateNPC(2);
		CreateNPC(3);
		CreateNPC(4);
	}
	if (id == 2) {
		CreateNewItem(sf::Vector2f(780.f, 560.f), sf::Vector2f(290.f, 400.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1080.f, 270.f), sf::Vector2f(40.f, 360.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1630.f, 840.f), sf::Vector2f(530.f, 30.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1630.f, 860.f), sf::Vector2f(530.f, 40.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1770.f, 980.f), sf::Vector2f(100.f, 200.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(620.f, 0.f), sf::Vector2f(440.f, 100.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(100.f, 240.f), sf::Vector2f(820.f, 10.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1850.f, 0.f), sf::Vector2f(220.f, 750.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1700.f, 150.f), sf::Vector2f(480.f, 200.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1370.f, 830.f), sf::Vector2f(70.f, 110.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1930.f, 980.f), sf::Vector2f(10.f, 2080.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(0.f, 0.f), sf::Vector2f(4000.f, 10.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(0.f, 1080.f), sf::Vector2f(4000.f, 10.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(0.f, 980.f), sf::Vector2f(10.f, 2080.f), -1, -2, 0, 10, 20, 0);
		CreateNewItem(sf::Vector2f(1100.f, 1000.f), sf::Vector2f(400.f, 70.f), -1, -2, 2, 10, 20, 0);
		CreateNewItem(sf::Vector2f(200.f, 280.f), sf::Vector2f(100.f, 100.f), -1, 0, 3, 10, 20, 105);
		CreateNewItem(sf::Vector2f(850.f, 400.f), sf::Vector2f(100.f, 100.f), -1, 0, 3, 10, 20, 106);
		CreateNewItem(sf::Vector2f(1400.f, 800.f), sf::Vector2f(100.f, 100.f), -1, 0, 3, 10, 20, 107);
		CreateNewItem(sf::Vector2f(680.f, 650.f), sf::Vector2f(100.f, 100.f), -1, 0, 3, 10, 20, 108);
		CreateNPC(5);
		CreateNPC(6);
		CreateNPC(7);
		CreateNPC(8);
	}
}

void GameBoard::PickUpItem(int _id) {
	GameEngine::Entity* dialogue = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(dialogue->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::PickUp);
	render->SetZLevel(2);
	dialogue->SetSize(sf::Vector2f(500.f, 200.f));
	render->SetFillColor(sf::Color::Transparent);
	dialogue->SetPos(sf::Vector2f(1000.f, 900.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(dialogue);
	m_dialogues.push_back(dialogue);
	m_id = 2;
}

void GameBoard::PickUpBadItem() {
	GameEngine::Entity* dialogue = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(dialogue->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::PickUp);
	render->SetZLevel(-4);
	render->SetFillColor(sf::Color::Transparent);
	dialogue->SetSize(sf::Vector2f(250.f, 100.f));
	dialogue->SetPos(sf::Vector2f(1000.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(dialogue);
	m_dialogues.push_back(dialogue);
	m_id = 4;
}

void GameBoard::HideDiagloue() {
	for (std::vector<GameEngine::Entity*>::iterator random = m_dialogues.begin(); random != m_dialogues.end();) {
		GameEngine::Entity* dialogue = (*random);
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(dialogue);
		random = m_dialogues.erase(random);
		m_id = 1;
	}
}

void GameBoard::ChangeHealthLevel(int amount) {
	m_health -= amount;
	int tileindex = m_health - 1;
	m_healthbar->GetComponent<GameEngine::SpriteRenderComponent>()->SetTileIndex(tileindex, 0);
}

void GameBoard::ChangeWeight(int amount) {
	m_weights = amount;
	int weight = m_weights;
	//PlayerMovementComponent* playerMov = m_player->GetComponent<PlayerMovementComponent>();
	PlayerMovementComponent* playerMov = m_player->GetComponent<PlayerMovementComponent>();
	playerMov->SlowPlayer(weight);
}

void GameBoard::ClearObstacles(int id) {
	if (id == 1) {
		for (std::vector<GameEngine::Entity*>::iterator it = m_obstacles.begin(); it != m_obstacles.end();) {
			GameEngine::Entity* obstacle = (*it);
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(obstacle);
			it = m_obstacles.erase(it);
		}
		CreateBackground(id);
		SpawnRoomItems(id);
	}
	if (id == 2) {
		for (std::vector<GameEngine::Entity*>::iterator it = m_obstacles.begin(); it != m_obstacles.end();) {
			GameEngine::Entity* obstacle = (*it);
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(obstacle);
			it = m_obstacles.erase(it);
		}
		CreateBackground(id);
		SpawnRoomItems(id);
	}
	if (id == 3) {
		for (std::vector<GameEngine::Entity*>::iterator it = m_obstacles.begin(); it != m_obstacles.end();) {
			GameEngine::Entity* obstacle = (*it);
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(obstacle);
			it = m_obstacles.erase(it);
		}
	}
}

void GameBoard::CreatePoints() {
	int i = m_points;
	std::string str = std::to_string(i);
}

void GameBoard::Addpoint(int amount) {
	m_points += amount;
}

void GameBoard::CreateNPC(int npcNum)
{
	GameEngine::Entity* m_npc = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_npc);

	m_npc->itemid = 4;
	m_npc->SetSize(sf::Vector2f(112, 128.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(m_npc->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::npc);

	m_npc->AddComponent<GameEngine::CollidableComponent>();

	m_npc->AddComponent<npcMovementController>();
	m_npc->AddComponent<GameEngine::AnimationComponent>();

	npcMovementController* movementC = m_npc->GetComponent<npcMovementController>();
	if (movementC != nullptr)
	{
		movementC->SetNpcNum(npcNum);
	}



	switch (npcNum)
	{
	case 0:
		m_npc->SetPos(sf::Vector2f(200.f, 175.f));
		m_obstacles.push_back(m_npc);
		break;
	case 1:
		m_npc->SetPos(sf::Vector2f(1850.f, 100.f));
		m_obstacles.push_back(m_npc);
		break;
	case 2:
		m_npc->SetPos(sf::Vector2f(375.f, 250.f));
		m_obstacles.push_back(m_npc);
		break;
	case 3:
		m_npc->SetPos(sf::Vector2f(1300.f, 250.f));
		m_obstacles.push_back(m_npc);
		break;
	case 4:
		m_npc->SetPos(sf::Vector2f(1000.f, 150.f));
		m_obstacles.push_back(m_npc);
		break;
	case 5:
		m_npc->SetPos(sf::Vector2f(950.f, 250.f));
		m_obstacles.push_back(m_npc);
		break;
	case 6:
		m_npc->SetPos(sf::Vector2f(570.f, 410.f));
		m_obstacles.push_back(m_npc);
		break;
	case 7:
		m_npc->SetPos(sf::Vector2f(1250.f, 300.f));
		m_obstacles.push_back(m_npc);
		break;
	case 8:
		m_npc->SetPos(sf::Vector2f(1500.f, 750.f));
		m_obstacles.push_back(m_npc);
		break;

	}

}

void GameBoard::CreateObstacle(float posX, float posY, float sizeX, float sizeY)
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(posX, posY));
	obstacle->SetSize(sf::Vector2f(sizeX, sizeY));

	GameEngine::RenderComponent* spriteRender = static_cast<GameEngine::RenderComponent*>
		(obstacle->AddComponent<GameEngine::RenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);

	obstacle->AddComponent<GameEngine::CollidableComponent>();


}

void GameBoard::CreateBackground(int id)
{
	if (id == 1) {

		GameEngine::Entity* bg = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

		bg->SetPos(sf::Vector2f(960.f, 540.f));
		bg->SetSize(sf::Vector2f(1920.f, 1080.f));

		GameEngine::SpriteRenderComponent* sRender = static_cast<GameEngine::SpriteRenderComponent*>
			(bg->AddComponent<GameEngine::SpriteRenderComponent>());
		sRender->SetFillColor(sf::Color::Transparent);
		sRender->SetTexture(GameEngine::eTexture::bg);
		sRender->SetZLevel(-1);
		m_obstacles.push_back(bg);
		m_backgroundid = 2;
		
	}
	if (id == 2) {

		GameEngine::Entity* bg = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

		bg->SetPos(sf::Vector2f(960.f, 540.f));
		bg->SetSize(sf::Vector2f(1920.f, 1080.f));

		GameEngine::SpriteRenderComponent* sRender = static_cast<GameEngine::SpriteRenderComponent*>
			(bg->AddComponent<GameEngine::SpriteRenderComponent>());
		sRender->SetFillColor(sf::Color::Transparent);
		sRender->SetTexture(GameEngine::eTexture::Grassbg);
		sRender->SetZLevel(-1);
		m_obstacles.push_back(bg);
		m_backgroundid = 1;
		
	}
	
}
void GameBoard::Gameoverscreen() {
	GameEngine::Entity* bg = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

	bg->SetPos(sf::Vector2f(960.f, 540.f));
	bg->SetSize(sf::Vector2f(1920.f, 1080.f));

	GameEngine::SpriteRenderComponent* sRender = static_cast<GameEngine::SpriteRenderComponent*>
		(bg->AddComponent<GameEngine::SpriteRenderComponent>());
	sRender->SetFillColor(sf::Color::Transparent);
	sRender->SetTexture(GameEngine::eTexture::GameOver);
	sRender->SetZLevel(-1);
}

void GameBoard::Update()
{	
	if (m_health <= 0) {
		m_gameover = true;
		Gameoverscreen();
		m_backgroundid = 3;
		ClearObstacles(m_backgroundid);
	}
}

