/****************************************************************
 * Project Name: xinglugu-project
 * File Name:ItemOut.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
 * License:
 ****************************************************************/
#ifndef __ITEMOUT_H_
#define __ITEMOUT_H_
#include "usableItem.h"
#include "Constants.h"
class SoldBox {
private:
	int singleDayProfit = 0;
	Item* itemInput[maxnum];
	int itemnum[maxnum];
	int itemList;
	int numList;

public:

	//构造函数
	SoldBox() {
		itemList = listInit;
		numList = listInit;
	}

	//把东西放入售卖箱
	bool singleDayInput(Item* itemToSell, int num);

	//取出东西
	Item* itemSingleOut();

	int topNumOut();

	Item* topItemOut();

	//每日总结,清空箱子
	int dayProfitOut();

	//判断是否为空
	bool isBoxEmpty();
};



#endif

