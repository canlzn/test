/****************************************************************
 * Project Name: xinglugu-project
 * File Name:Walking.cpp
 * File Function: walk
 * Author:Sun Yining
 * Update Date:2024.12.11
 * License:
 ****************************************************************/

#include "Walking.h"
#include "cocos2d.h"

USING_NS_CC;


Animate* Walking::createAnimation(const std::string& name, const std::string& direction)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	std::string strPlistName = "resources/SYN/" + name + "/" + name + ".plist";
	std::string strPhotoName = "resources/SYN/" + name + "/" + name + ".png";

	cache->addSpriteFramesWithFile(strPlistName, strPhotoName);
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = nullptr;

	for (int ix = 1; ix <= 4; ix++)
	{
		frame = cache->getSpriteFrameByName(name + direction + Value(ix).asString() + ".png");
		if (frame == nullptr)
		{
			break;
		}
		frameVec.pushBack(frame);

	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec, 1.0f / 5, 1);//帧的更换速度为0.2秒
	Animate* animate = Animate::create(animation);

	return animate;
}

Action* Walking::walkingContently(Sprite* targetSprite, const std::string& name, const std::string& direction) {
	if (targetSprite) {
		// 先调用createAnimation函数获取动画动作
		Animate* animate = Walking::createAnimation(name, direction);
		if (animate) {
			// 使用RepeatForever将动画动作包装成可无限循环的动作
			auto repeatForever = RepeatForever::create(animate);
			// 返回这个可无限循环的动作，类型为Action*，符合函数定义要求
			return repeatForever;
		}
	}
	return nullptr;
}