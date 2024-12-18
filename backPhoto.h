#ifndef __BACKPHOTO_H_
#define __BACKPHOTO_H_

#include "MainScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "Constants.h"

void listenSet();

void listenSet2();

void listenSet3();

void backPhoto(Scene* scene, backPack* pack1, EventDispatcher* _eventDispatcher);

void ventorySet();

void inventory(Scene* scene, backPack* pack1, Vec2 origin);

void backItemAddDisplay(int no);


void storePhoto(Scene* scene);

void numlabel(int posi);

void numlabel2(int posi);

void labelDelete(int posi);

void storeSeasonEx(int season);
#endif // !__BACKPHOTO_H_

