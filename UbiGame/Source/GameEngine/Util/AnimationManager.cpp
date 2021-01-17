#include "AnimationManager.h"


using namespace GameEngine;

AnimationManager* AnimationManager::sm_instance = nullptr;

AnimationManager::AnimationManager()
{

}


AnimationManager::~AnimationManager()
{

}


void AnimationManager::InitStaticGameAnimations()
{
	/*
	//Template definition -> every new animation needs to have an ID and a definition that controls how animation is played
	m_animDefinitions.push_back
	(
	SAnimationDefinition(
	EAnimationId::BirdIdle,
	eTexture::Player,
	sf::Vector2i(0, 0),
	10,
	3)
	);
	*/
    m_animDefinitions.push_back
    (
        SAnimationDefinition(
            EAnimationId::idle,
            eTexture::Player,
            sf::Vector2i(0, 0),
            4,
            10)
    );

    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkLeft,
            eTexture::Player,
            sf::Vector2i(0, 3),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkUp,
            eTexture::Player,
            sf::Vector2i(0, 2),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkRight,
            eTexture::Player,
            sf::Vector2i(0, 4),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkDown,
            eTexture::Player,
            sf::Vector2i(0, 1),
            4,
            10)
    );
    m_animDefinitions.push_back
    (
        SAnimationDefinition(
            EAnimationId::idleNPC,
            eTexture::npc,
            sf::Vector2i(0, 0),
            4,
            10)
    );

    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkLeftNPC,
            eTexture::npc,
            sf::Vector2i(0, 3),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkUpNPC,
            eTexture::npc,
            sf::Vector2i(0, 2),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkRightNPC,
            eTexture::npc,
            sf::Vector2i(0, 4),
            4,
            10)
    );
    m_animDefinitions.push_back(
        SAnimationDefinition(
            EAnimationId::walkDownNPC,
            eTexture::npc,
            sf::Vector2i(0, 1),
            4,
            10)
    );

}


void AnimationManager::ReleaseStaticGameAnimations()
{
	m_animDefinitions.clear();
}


const SAnimationDefinition* AnimationManager::GetAnimDefinition(EAnimationId::type animId) const
{
	for (int a = 0; a < m_animDefinitions.size(); ++a)
	{
		if (m_animDefinitions[a].m_animId == animId)
			return &m_animDefinitions[a];
	}

	return nullptr;
}
