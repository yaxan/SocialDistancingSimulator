#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player,
			Obstacle = 2,
			bg,
			npc,
			HealthBar,
			GameOver,
			PickUp,
			Grassbg,
			Peanut = 100,
			Can = 101,
			Spam = 102,
			Soda = 103,
			Wipes = 104,
			Eggplant = 105,
			Apple = 106,
			Corn = 107,
			Carrot = 108,
			Count,

		};
	}

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player: return "Player.png";
		case eTexture::Obstacle: return "Obstacle.png";
		case eTexture::bg: return "bg.png";
		case eTexture::npc: return "npc.png";
		case eTexture::HealthBar: return "healthbar.png";
		case eTexture::PickUp: return "pickup.png";
		case eTexture::GameOver: return "gameover.png";
		case eTexture::Grassbg: return "grassbg.png";
		case eTexture::Peanut: return "peanutButter.png";
		case eTexture::Can: return "can.png";
		case eTexture::Spam: return "spam.png";
		case eTexture::Soda: return "soda.png";
		case eTexture::Wipes: return "wipes.png";
		case eTexture::Eggplant: return "eggplant.png";
		case eTexture::Apple: return "apple.png";
		case eTexture::Corn: return "corn.png";
		case eTexture::Carrot: return "carrot.png";
		}

		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		void UpdateTileRect();
		void UpdateSpriteParams();

		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture) {
		case GameEngine::eTexture::HealthBar: return sf::Vector2f(64.f, 15.f);
		case GameEngine::eTexture::Player: return sf::Vector2f(112.f, 128.f);
		case GameEngine::eTexture::npc: return sf::Vector2f(112.f, 128.f);
		}

		return sf::Vector2f(-1.f, -1.f);
	}
}

