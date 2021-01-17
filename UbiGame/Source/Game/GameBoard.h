#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();
		
		int id() { return m_id; };
		void PickUpBadItem();
		bool IsGameOver() const{ return m_gameover; };
		void HealthBar();
		void Gameoverscreen();
		void Update();
		void CreateNewItem(const sf::Vector2f& position, const sf::Vector2f& size, int itemtexture, int _setzlevel, int _itemid, int _weight, int _points, int _damage);
		void ChangeHealthLevel(int amount);
		void ChangePoints();
		void ChangeWeight(int amount);
		void SpawnRoomItems(int id);
		void HideDiagloue();
		void ClearObstacles(int id);
		int m_somegodid() { return m_backgroundid; };
		void PickUpItem(int _id);
		void Addpoint(int amount);
		void CreatePoints();
		bool IsGameOver() { return false; }
		int m_id;
		void CreateNPC(int npcNum);
		std::vector<GameEngine::Entity*> m_obstacles;

	private:
		void CreatePlayer();
		
		void CreateObstacle(float posX, float posY, float sizeX, float sizeY);
		void CreateBackground(int id);
		GameEngine::Entity* m_player;
		int m_backgroundid;

	protected:
		std::vector<GameEngine::Entity*> m_dialogues;
		

		GameEngine::Entity* m_healths;
		GameEngine::Entity* m_weight;
		GameEngine::Entity* m_healthbar;

		
		int m_health;
		int m_weights;
		int m_points;
		bool m_gameover;
	};
}

