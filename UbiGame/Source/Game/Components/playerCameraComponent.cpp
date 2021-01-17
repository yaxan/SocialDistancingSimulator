#include "playerCameraCompenent.h"
#include "GameEngine/Util/CameraManager.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

playerCameraComponent::playerCameraComponent() {

}

playerCameraComponent::~playerCameraComponent() {

}

void playerCameraComponent::Update() {
	__super::Update();

	GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(GetEntity()->GetPos());
}