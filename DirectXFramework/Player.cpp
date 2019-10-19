#include "Player.h"
#include "PlayerInput.h"
#include <stdlib.h>

Player::Player(std::shared_ptr<Graphics> graphics, std::shared_ptr<Input> input, const std::wstring & spritename, std::shared_ptr<SpriteResources>& sr,
	const int& x, const int& y)
	:
	Entity(graphics, spritename, sr),
	animation_(std::make_shared<AnimationComponent>(this)),
	input_(std::make_shared<PlayerInput>(input, this)),
	x_(x),
	y_(y)
{
	animation_->BindSprite(L"Images/adventuregirlrun.png", AnimationComponent::AnimationState::Runright);
	animation_->InitializeAnimation(4, 2, 0, 7, 0.1f, true, AnimationComponent::AnimationState::Runright);
	animation_->BindSprite(L"Images/adventuregirlidle.png", AnimationComponent::AnimationState::Idle);
	animation_->InitializeAnimation(5, 2, 0, 9, 0.1f, true, AnimationComponent::AnimationState::Idle);
	animation_->BindSprite(L"Images/adventuregirljump.png", AnimationComponent::AnimationState::Jump);
	animation_->InitializeAnimation(5, 2, 0, 9, 0.05f, true, AnimationComponent::AnimationState::Jump);
	animation_->SetAllSpritePositions(float(x_), float(y_));
	animation_->ChangeState(AnimationComponent::AnimationState::Idle);
	components_.push_back(animation_);
	components_.push_back(input_);
}

void Player::CDraw()
{
	animation_->Draw();
}

void Player::CUpdate(const float & frametime)
{
	animation_->Update(frametime);
	input_->Update(frametime);
}
