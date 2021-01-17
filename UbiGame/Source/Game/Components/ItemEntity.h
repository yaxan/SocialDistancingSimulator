#pragma once
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game {
	class ItemEntity : public GameEngine::Entity {
	public:
		ItemEntity(int itemtexture, int _setzlevel, int _itemid, int _weight, int _points, int _damage);
		~ItemEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
	protected:
		GameEngine::SpriteRenderComponent* m_render;
	};
}