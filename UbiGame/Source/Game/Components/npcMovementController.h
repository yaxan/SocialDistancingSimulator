#pragma once
#include "GameEngine\GameEngineMain.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"

namespace Game
{
    class npcMovementController : public GameEngine::Component
    {
    public:
        npcMovementController();
        ~npcMovementController();

        virtual void Update() override;

        virtual void OnAddToWorld() override;

        void SetNpcNum(int num) { npcNum = num; }

    private:
        void upOrDown(GameEngine::AnimationComponent* m_animComponent, float playerVel);
        void rightOrLeft(GameEngine::AnimationComponent* m_animComponent, float playerVel);
        void dir(int dir, GameEngine::AnimationComponent* m_animComponent, float playerVel, float dt, sf::Vector2f& wantedVel);
        std::vector<float> times;
        std::vector<float> directions;
        int npcNum;
        int index;
        float t;
        float playerVel;
        GameEngine::AnimationComponent* m_animComponent;
    };
}