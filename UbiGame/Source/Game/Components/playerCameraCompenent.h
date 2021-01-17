#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game {
	class playerCameraComponent : public GameEngine::Component {

	public: 
		playerCameraComponent();
		~playerCameraComponent();

		virtual void Update() override;


	};
}
