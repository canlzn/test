/****************************************************************
 * Project Name: xinglugu-project
 * File back.h
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.12
 * License:
 ****************************************************************/
#ifndef __BACKPACK_H__
#define __BACKPACK_H__

#include "cocos2d.h"
#include"usableItem.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;

//背包的类
//包括内部的物品与钱
//作为物品储存与购买、兑换的媒介
class backPack {
private:

	//储存物品
	Item* box[backpackCapacity];

	//物品数量
	int boxNum[backpackCapacity];

	//背包等级（0,1,2）
	int grade;

	//钱财
	int money;

	//位置是否可用
	bool positionIsAccessible[backpackCapacity];

	//背包是否打开
	bool packIsOpen;

	//右键数量计数
	bool rightKeyCount;

	//转移数量
	int numToTransmit;

	//要转移的物品
	Item* itemToTransmit;

	Item* handInItem;
public:
	backPack() {//构造函数
		packIsOpen = 0;
		rightKeyCount = 0;
		grade = grade1;
		money = moneyInitialize;
		numToTransmit = 0;
		for (int i = 0; i < backpackCapacity; i++) {
			if (i > 4) {
				Item* nullItem = new Item();
				box[i] = nullItem;
				boxNum[i] = 0;
			}
			positionIsAccessible[i] = 0;

		}
		box[0] = Tool::create("axe");
		boxNum[0] = 1;
		box[1] = Tool::create("wateringcan");
		boxNum[1] = 1;
		box[2] = Tool::create("pickaxe");
		boxNum[2] = 1;
		box[3] = Tool::create("hoe");
		boxNum[3] = 1;
		box[4] = Tool::create("sickle");
		boxNum[4] = 1;
		handInItem = box[0];
	}
	static backPack* create() {//创建背包
		backPack* bPack = new backPack();
		return bPack;
	}
	void init();
	bool display();
	void itemPositionChangeOn(bool isLeftKey, int position);
	void itemPositionChangeOff(int position);
	Item* itemOutSet();
	void itemChangeReset();
	void packDisplay();
	Item* bottomSelect(int NoX);
	int posiNumBack(int NoX);
	bool upgrade();
	bool itemAdd(Item* itemIn, int num);
	bool matchJudge(Item* itemToMatch, int numToMatch);
	void itemReduce(Item* itemToMatch, int numToMatch);
	void moneyChange(int addAmount, bool ways);
	int moneyOut();
	std::string moneyStringOut();
	std::string numStringOut(int posi);
	std::string handInItemOut();
	void sethandInItemOut(int no);

};


#endif // __BACKPACK_H__
