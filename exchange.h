/****************************************************************
 * Project Name: xinglugu-project
 * File exchange.h
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.4
 * License:
 ****************************************************************/
#ifndef __EXCHANGE_H_
#define __EXCHANGE_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include"back.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;

//合成台的实现类
class craftTable {
public:
	int grade;
	craftTable(int yourGrade) {
		grade = yourGrade;
	}
	void gradeExchange(int newGrade) {
		grade = newGrade;
	}
	bool changeForCraft(backPack* Back, int itemToMake);
	Item* getItem(backPack* Back, int itemToMake);
};

//Pierre商店的实现类
class Pierre {
private:
	int season;
public:
	Pierre() {
		season = 1;
	}
	bool isAffordable(backPack* Back, int itemToMake, int season);

	std::string itemMoneyOut(int posi, int season);

	int itemMoneyBack(int posi, int season);

	Item* getItem(backPack* Back, int itemToMake, int season);

	std::string itemNameOut(int no, int season, bool choise);

	void seasonEx(int season);

	int seasonOut();
};
//铁匠铺的实现类
class BlackSmith {
public:
	BlackSmith() {
		;
	}
	bool isAffordable(backPack* Back, int itemToMaken);
	Item* getItem(backPack* Back, int itemToMake);
};

#endif  
