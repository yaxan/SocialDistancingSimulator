#include "ItemEntity.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Graphics.hpp>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <GameEngine/Util/TextureManager.h>
#include "Game/GameBoard.h"
#include "Game/Components/npcMovementController.h"

using namespace Game;

ItemEntity::ItemEntity( int itemtexture, int _setzlevel, int _itemid, int _weight, int _points, int _damage) {
		itemid = _itemid;
		int weight = _weight;
		int points = _points;


		enum GameEngine::eTexture::type texturename = static_cast<GameEngine::eTexture::type>(_damage);
		m_render = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
		m_render->SetTexture(texturename);
		m_render->SetFillColor(sf::Color::Transparent);
		m_render->SetZLevel(_setzlevel);
		//m_render->SetTileIndex(0, 0);

		AddComponent<GameEngine::CollidableComponent>();
}

ItemEntity::~ItemEntity() {

}

void ItemEntity::OnAddToWorld() {
	__super::OnAddToWorld();
}

void ItemEntity::OnRemoveFromWorld() {
	__super::OnRemoveFromWorld();
}