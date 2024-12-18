/****************************************************************
 * Project Name: xinglugu-project
 * File back.cpp
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.10
 * License:
 ****************************************************************/
#include"back.h"
#include"cocos2d.h"
#include"Constants.h"
#include"backPhoto.h"
USING_NS_CC;
using namespace Constants;


//背包初始化
void backPack::init() {//初始化
	for (int i = 0; i < backpackCapacity/3; i++) {
		positionIsAccessible[i] = 1;
	}
	for (int i = backpackCapacity / 3; i < backpackCapacity ; i++) {
		positionIsAccessible[i] = 0;
	}

}

//物品转移的开始，选择物品
void backPack::itemPositionChangeOn(bool isLeftKey,int position) {
	if (position < 0 || position >= 36)
		return;
	else {
		if (isLeftKey == 1) {
			numToTransmit = boxNum[position];
			boxNum[position] = 0;
			itemToTransmit = box[position];
			Item* nullitem = new Item( );
			box[position] = nullitem;
		}
		else {
			numToTransmit++;
			boxNum[position]--;
			if (rightKeyCount == 0) {
				itemToTransmit = box[position];
				rightKeyCount++;
			}
			if (boxNum[position] == 0)
			{
				auto nullitem = new Item();
				box[position] = nullitem;
			}
		}
	}
}

//转移的结束，放置
void backPack::itemPositionChangeOff(int position) {
	if (position < 0 || position >= 36)
		return;
	else {
		rightKeyCount = 0;
		Item* sub1 = box[position];
		int sub2 = boxNum[position];
		box[position] = itemToTransmit;
		boxNum[position] = numToTransmit;
		itemToTransmit = sub1;
		numToTransmit = sub2;
	}
}

//售出物品功能
Item* backPack::itemOutSet() {
	Item* item0;
	item0 = itemToTransmit;
	item0->quantity = numToTransmit;
	Item* newitem = new Item();
	itemToTransmit = newitem;
	numToTransmit = 0;
	return item0;
}

//物品情况重置
void backPack::itemChangeReset() {
	Item* item0 = new Item();
	itemToTransmit = item0;
	numToTransmit = 0;
}

//返回特定位置的物品
Item* backPack::bottomSelect(int NoX) {
	if (NoX < 0 || NoX >= backpackCapacity)
	{
		Item* itemnull = new Item();
		return itemnull;
	}
	else {
		return box[NoX];
	}
}

//特定位置的数量
int backPack::posiNumBack(int NoX) {
	if (NoX < 0 || NoX >= backpackCapacity)
	{
		CCLOG("Number is over field!");
		return 0;
	}
	else
		return boxNum[NoX];
}

//背包升级
bool backPack::upgrade() {
	if (grade == 0)
	{
		grade++;
		for (int i = backpackCapacity / 3; i < backpackCapacity*2 / 3; i++) {
			positionIsAccessible[i] = 1;
		}
		listenSet2();
		return 1;
	}
	else {
		if (grade == 1)
		{
			grade++;
			for (int i = backpackCapacity * 2 / 3; i < backpackCapacity ; i++) {
				positionIsAccessible[i] = 1;
			}
			listenSet3();
			return 1;
		}
		else {
			CCLOG("is Already top");
			return 0;
		}
	}
}

//物品的添加
bool backPack::itemAdd(Item* itemIn,int num) {
	int ring = 0,posi=0;
	bool isAlreadyInside = 0, isAlreadyFull = 0;
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (box[i]->name == itemIn->name) {
			isAlreadyInside = 1;
			posi = i;
			break;
		}
	}
	if (isAlreadyInside == 1) {
		boxNum[posi]+=itemIn->quantity*num;
		backItemAddDisplay(posi);
		numlabel2(posi);
	}
	else {
		while (boxNum[ring] != 0) {
			ring++;
		}
		if (ring < grade * (backpackCapacity / 3) + backpackCapacity / 3) {
			box[ring] = itemIn;
			boxNum[ring] += itemIn->quantity*num;
			backItemAddDisplay(ring);
			numlabel(posi);
		}
		else
			isAlreadyFull = 1;
	}
	if (isAlreadyFull == 0)
		return 0;
	else
		return 1;
}

//判断是否有指定数量的指定物品
bool backPack::matchJudge(Item* itemToMatch, int numToMatch) {
	bool isMatchAble = 0;
	int ring = 0;
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (boxNum[i] == 0)
			continue;
		else {
			if (box[i]->name == itemToMatch->name)
			{
				if(boxNum[i]>=numToMatch)
					isMatchAble = 1;
			}
		}
	}
	if (isMatchAble == 0)
		return 0;
	else
		return 1;
}

//物品减少
void backPack::itemReduce(Item* itemToMatch, int numToMatch) {
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (box[i]->name == itemToMatch->name)
		{
			if (numToMatch < boxNum[i]) {
				boxNum[i] -= numToMatch;			
			}
			else {
					Item* nullitem = new Item();
				if (boxNum[i] == numToMatch) {
					box[i] = nullitem;
					boxNum[i] = 0;
				}
				else {
					CCLOG("The num is too large!");
					return;
				}
			}
		}
	}
}

//钱的增减
//ways：1--减 0--增
void backPack::moneyChange(int addAmount,bool ways) {
	if (ways == wayOfAdd)
		money += addAmount;
	else
		money -= addAmount;
}

//返回钱的值
int backPack::moneyOut() {
	return money;
}

//钱的string输出
std::string backPack::moneyStringOut() {
	int money0 = money;
	std::string moneyout="";
	int index = 1;
	while ((money / index) >= 10) {
		index *= 10;
	}
	while (index > 0) {
		switch (money / index) {
		case 0:
			moneyout += "0";
			break;
		case 1:
			moneyout += "1";
			break;
		case 2:
			moneyout += "2";
			break;
		case 3:
			moneyout += "3";
			break;
		case 4:
			moneyout += "4";
			break;
		case 5:
			moneyout += "5";
			break;
		case 6:
			moneyout += "6";
			break;
		case 7:
			moneyout += "7";
			break;
		case 8:
			moneyout += "8";
			break;
		case 9:
			moneyout += "9";
			break;
		default:
			break;
		}
		money -= (money / index) * index;
		index /= 10;
	}
	money = money0;
	return moneyout;
}

std::string backPack::numStringOut(int posi) {
	int money0 = boxNum[posi];
	std::string moneyout = "";
	int index = 1;
	while ((boxNum[posi] / index) >= 10) {
		index *= 10;
	}
	while (index > 0) {
		switch (boxNum[posi] / index) {
		case 0:
			moneyout += "0";
			break;
		case 1:
			moneyout += "1";
			break;
		case 2:
			moneyout += "2";
			break;
		case 3:
			moneyout += "3";
			break;
		case 4:
			moneyout += "4";
			break;
		case 5:
			moneyout += "5";
			break;
		case 6:
			moneyout += "6";
			break;
		case 7:
			moneyout += "7";
			break;
		case 8:
			moneyout += "8";
			break;
		case 9:
			moneyout += "9";
			break;
		default:
			break;
		}
		boxNum[posi] -= (boxNum[posi] / index) * index;
		index /= 10;
	}
	boxNum[posi] = money0;
	return moneyout;
}

//返回手持物品的名称
std::string backPack::handInItemOut() {
	return handInItem->name;
}

//设置手持物品
void backPack::sethandInItemOut(int no) {
	if (no < 0 || no >= grade * (backpackCapacity / 3) + backpackCapacity / 3)
		return;
	else {
		handInItem = box[no];
	}
}