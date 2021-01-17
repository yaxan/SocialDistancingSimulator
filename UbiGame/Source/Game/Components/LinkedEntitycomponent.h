#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "SFML/System/Vector2.hpp"

class GameEngine::Entity;

namespace Game {
	class LinkedEntityComponent : public GameEngine::Component {
	public:
		LinkedEntityComponent();
		~LinkedEntityComponent();

		void SetFollowedEntity(GameEngine::Entity* entity) { m_followedEntity = entity; }

		void SetFollowOffset(sf::Vector2f offset) { m_offset = offset; }

		virtual void Update() override;

	private:
		GameEngine::Entity* m_followedEntity;
		sf::Vector2f m_offset;
	};
}