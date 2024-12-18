/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#include "Character.h"

USING_NS_CC;

void Character::stopMoving(Sprite* sprite)
{
	sprite->stopAllActions();
}


void Character::Moving(Sprite* sprite, int direction,float t)
{
	CCLOG("½øÈëCharacter::Movingº¯Êý£¬ sprite: %p, direction: %d", sprite, direction);
	switch (direction) {
	case 0: {
		sprite->runAction(Walking::createAnimation("Abigail", "f"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(0, -16)));
		break;
	}
	case 1: {
		sprite->runAction(Walking::createAnimation("Abigail", "b"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(0, 16)));
		break;
	}
	case 2: {
		sprite->runAction(Walking::createAnimation("Abigail", "l"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(-16, 0)));
		break;
	}
	case 3: {
		sprite->runAction(Walking::createAnimation("Abigail", "r"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(16, 0)));
		break;
	}
	}

}

void Character::MovingContenly(Sprite* sprite, int direction, float t)
{
	switch (direction) {
	case 0: {
		Action* action;
		sprite->runAction(Walking::walkingContently(sprite, "Abigail", "f"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(0, -16)));
		break;
	}
	case 1: {
		Action* action;
		sprite->runAction(Walking::walkingContently(sprite, "Abigail", "b"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(0, 16)));
		break;
	}
	case 2: {
		Action* action;
		sprite->runAction(Walking::walkingContently(sprite, "Abigail", "l"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(-16, 0)));
		break;
	}
	case 3: {
		Action* action;
		sprite->runAction(Walking::walkingContently(sprite, "Abigail", "r"));
		runAction(MoveTo::create(t, this->getPosition() + Vec2(16, 0)));
		break;
	}
	}

}