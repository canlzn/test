/****************************************************************
 * Project Name: xinglugu-project
 * File exchange.cpp
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.4
 * License:
 ****************************************************************/
#include"exchange.h"
#include"cocos2d.h"
#include"back.h"
#include"usableItem.h"
#include"Constants.h"
#include"backPhoto.h"
USING_NS_CC;
using namespace Constants;
//ºÏ³ÉÌ¨²¿·Ö

//ÎïÆ·¶ÔÓ¦Êý×Ö
//0--Ä¾ÅÆ
//1--Ä¾Õ¤À¸
//2--´óÃÅ
//3--²Ý×Ñ
//4--Ä¾¾¶
//5--Ê¯¾¶
//6--»ð°Ñ
//7--»ù´¡·ÊÁÏ
//8--±¦Ïä
//9--ÈÛÂ¯
//10--Ê¯ÅÆ
//11--Ë®ÁúÍ· 
//12--»ù´¡ÊªÍÁ
//13--µ¾²ÝÈË
//14--Óã¶ü
//15--Ó£ÌÒÕ¨µ¯
//16--½×ÌÝ
//17--óô»ð
//18--´ºÈÕÒ°ÖÖ
//¶ÔÎïÆ·ÊÇ·ñ¿ÉºÏ³ÉµÄÅÐ¶Ï
bool craftTable::changeForCraft(backPack* Back,int itemToMake) {
	switch (itemToMake) {
	case 0://Ä¾ÅÆ
	{
		Item* WoodenSign = terial::create("wood");
		if (Back->matchJudge(WoodenSign, amountOfWoodForWoodenSign))
			return 1;
		else
			return 0;
		break;
	}
	case 1://Ä¾Õ¤À¸
	{
		Item* WoodFence = terial::create("wood");
		if (Back->matchJudge(WoodFence, amountOfWoodForWoodFence))
			return 1;
		else
			return 0;
		break;
	}
	case 2://´óÃÅ
	{
		Item* Gate = terial::create("wood");
		if (Back->matchJudge(Gate, amountOfWoodForGate))
			return 1;
		else
			return 0;
		break;
	}
	case 3://²Ý×Ñ
	{
		Item* GrassStarter = terial::create("fibre");
		if (Back->matchJudge(GrassStarter, amountOfFibreForGrassStarter))
			return 1;
		else
			return 0;
		break;
	}
	case 4://Ä¾¾¶
	{
		Item* WoodPath = terial::create("wood");
		if (Back->matchJudge(WoodPath, amountOfWoodForWoodPath))
			return 1;
		else
			return 0;
		break;
	}
	case 5://Ê¯¾¶
	{
		Item* CobblestonePath = terial::create("stone");
		if (Back->matchJudge(CobblestonePath, amountOfStoneForCobblestonePath))
			return 1;
		else
			return 0;
		break;
	}
	case 6://»ð°Ñ
	{
		Item* Torch1 = terial::create("wood");
		Item* Torch2 = terial::create("sap");
		if (Back->matchJudge(Torch1, amountOfWoodForTorch) && Back->matchJudge(Torch2, amountOfSapForTorch))
			return 1;
		else
			return 0;
		break;
	}
	case 7://»ù´¡·ÊÁÏ
	{
		Item* BasicFertilizer = terial::create("sap");
		if (Back->matchJudge(BasicFertilizer, amountOfSapForBasicFertilizer))
			return 1;
		else
			return 0;
		break;
	}
	case 8://±¦Ïä
	{
		Item* Chest = terial::create("wood");
		if (Back->matchJudge(Chest, amountOfWoodForChest))
			return 1;
		else
			return 0;
		break;
	}
	case 9://ÈÛÂ¯
	{
		Item* Furnace1 = terial::create("stone");
		Item* Furnace2 = terial::create("copperore");
		if (Back->matchJudge(Furnace1, amountOfStoneForFurnace) && Back->matchJudge(Furnace2, amountOfCopperOreForFurnace))
			return 1;
		else
			return 0;
		break;
	}
	case 10://Ê¯ÅÆ
	{
		Item* StoneSign = terial::create("stone");
		if (Back->matchJudge(StoneSign, 25))
			return 1;
		else
			return 0;
		break;
	}
	case 11://Ë®ÁúÍ· 
	{
		Item* Sprinkle1 = terial::create("ironbar");
		Item* Sprinkle2 = terial::create("copperbar");
		if (Back->matchJudge(Sprinkle1, amountOfIronBarForSprinkle) && Back->matchJudge(Sprinkle2, amountOfCopperBarForSprinkle))
			return 1;
		else
			return 0;
		break;
	}
	case 12://»ù´¡ÊªÍÁ
	{
		Item* BasicRetainingSoil = terial::create("stone");
		if (Back->matchJudge(BasicRetainingSoil, 2))
			return 1;
		else
			return 0;
		break;
	}
	case 13://µ¾²ÝÈË
	{
		Item* ScareCrow1 = terial::create("wood");
		Item* ScareCrow2 = terial::create("coal");
		Item* ScareCrow3 = terial::create("fibre");
		if (Back->matchJudge(ScareCrow1, amountOfWoodForScareCrow) && Back->matchJudge(ScareCrow2, amountOfCoalForScareCrow) && Back->matchJudge(ScareCrow3, amountOfFibreForScareCrow))
			return 1;
		else
			return 0;
		break;
	}
	case 14://Óã¶ü
	{
		Item* Bait = AnimalProduct::create("bugmeat");
		if (Back->matchJudge(Bait, amountOfBugmeatForBait))
			return 1;
		else
			return 0;
		break;
	}
	case 15://Ó£ÌÒÕ¨µ¯
	{
		Item* CherryBomb1 = terial::create("coal");
		Item* CherryBomb2 = terial::create("copperore");
		if (Back->matchJudge(CherryBomb1, 2) && Back->matchJudge(CherryBomb2, 4))
			return 1;
		else
			return 0;
		break;
	}
	case 16://½×ÌÝ
	{
		Item* StairCase = terial::create("stone");
		if (Back->matchJudge(StairCase, 99))
			return 1;
		else
			return 0;
		break;
	}
	case 17://óô»ð
	{
		Item* CampFire1 = terial::create("stone");
		Item* CampFire2 = terial::create("wood");
		Item* CampFire3 = terial::create("fibre");
		if (Back->matchJudge(CampFire1, 10) && Back->matchJudge(CampFire2, 10) && Back->matchJudge(CampFire3, 10))
			return 1;
		else
			return 0;
		break;
	}
	case 18://´ºÈÕÒ°ÖÖ
	{
		Item* SpringSeed1 = Fruit::create("wildhorseradish");
		Item* SpringSeed2 = Fruit::create("daffodil");
		Item* SpringSeed3 = Fruit::create("leek");
		Item* SpringSeed4 = Fruit::create("Dandelion");

		if (Back->matchJudge(SpringSeed1, 1) && Back->matchJudge(SpringSeed2, 1) && Back->matchJudge(SpringSeed3, 1) && Back->matchJudge(SpringSeed4, 1))
			return 1;
		else
			return 0;
		break;
	}
	default:
		break;
	}
}

//ºÏ³ÉÎïÆ·
Item* craftTable::getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0:
	{
		Item* WoodenSign = Tool::create("woodensign");
		return WoodenSign;
		break;
	}
	case 1:
	{
		Item* WoodFence = Tool::create("woodfence");
		return WoodFence;
		break;
	}
	case 2:
	{
		Item* Gate = Tool::create("gate");
		return Gate;
		break;
	}
	case 3:
	{
		Item* GrassStarter = Tool::create("grassstarter");
		return GrassStarter;
		break;
	}
	case 4:
	{
		Item* WoodPath = Tool::create("woodpath");
		return WoodPath;
		break;
	}
	case 5:
	{
		Item* CobblestonePath = Tool::create("cobblestonepath");
		return CobblestonePath;
		break;
	}
	case 6:
	{
		Item* Torch = Tool::create("torch");
		return Torch;
		break;
	}
	case 7:
	{
		Item* BasicFertilizer = Tool::create("basicfertilizer");
		return BasicFertilizer;
		break;
	}
	case 8:
	{
		Item* Chest = Tool::create("chest");
		return Chest;
		break;
	}
	case 9:
	{
		Item* Furnace = Tool::create("furnace");
		return Furnace;
		break;
	}
	case 10:
	{
		Item* StoneSign = Tool::create("stonesign");
		return StoneSign;
		break;
	}
	case 11:
	{
		Item* Sprinkle = Tool::create("sprinkle");
		return Sprinkle;
		break;
	}
	case 12:
	{
		Item* BasicRetainingSoil = Tool::create("basicretainingsoil");
		return BasicRetainingSoil;
		break;
	}
	case 13:
	{
		Item* ScareCrow = Tool::create("scarecrow");
		return ScareCrow;
		break;
	}
	case 14:
	{
		Item* Bait = Tool::create("bait");
		return Bait;
		break;
	}
	case 15:
	{
		Item* CherryBomb = Tool::create("cherrybomb");
		return CherryBomb;
		break;
	}
	case 16:
	{
		Item* StairCase = Tool::create("staircase");
		return StairCase;
		break;
	}
	case 17:
	{
		Item* CampFire = Tool::create("campfire");
		return CampFire;
		break;
	}
	case 18:
	{
		Item* SpringSeed = Tool::create("springseed");
		return SpringSeed;
		break;
	}
	default:
		Item* SpringSeed = Tool::create("init");
		return SpringSeed;
		break;
	}
}

//PierreÉÌµê²¿·Ö

//ÎïÆ·¶ÔÓ¦Êý×Ö
// season 1£º
//   0--·À·ç²Ý
//   1--Çà¶¹
//   2--»¨Ò¬²Ë
//   3--ÍÁ¶¹
//   4--Óô½ðÏãÇò¾¥
//   5--¸ÊÀ¶
//   6--À¶¾ôÊ¿
//   7--´óËâ
//   8--µ¾Ãç  
//   9--²Ý×Ñ
//   10--²Ý×ÑÅä·½
//   11--ÌÇ
//   12--´óÂó·Û
//   13--´óÃ×
//   14--ÓÍ
//   15--´×
//   16--³õ¼¶·ÊÁÏ
//   17--¸ß¼‰·ÊÁÏ
//   18--³õ¼¶±£ÊªÍÁÈÀ
//   19--¸ß¼¶±£ÊªÍÁÈÀ
//   20--Ó£ÌÒÊ÷Ãç
//   21--ÐÓ×ÓÊ÷Ãç
//   22--³È×ÓÊ÷Ãç
//   23--ÌÒ×ÓÊ÷Ãç
//   24--Ê¯ÁñÊ÷Ãç
//   25--Æ»¹ûÊ÷Ãç
//   26--»¨Êø
// season 2£º
//   0--Ìð¹Ï
//   1--Î÷ºìÊÁ
//   2--À¶Ý®
//   3--À±½·
//   4--Ð¡Âó
//   5--ÂÜ²·
//   6--ÓÝÃÀÈË
//   7--ÏÄ¼¾ÁÁÆ¬
//   8--Æ¡¾Æ»¨
//   9--ÓñÃ×
//   10--ÏòÈÕ¿û
//   11--ºìÒ¶¾íÐÄ²Ë
//   12--²Ý×Ñ
//   13--²Ý×ÑÅä·½
//   14--ÌÇ
//   15--´óÂó·Û
//   16--´óÃ×
//   17--ÓÍ
//   18--´×
//   19--³õ¼¶·ÊÁÏ
//   20--¸ß¼‰·ÊÁÏ
//   21--³õ¼¶±£ÊªÍÁÈÀ
//   22--¸ß¼¶±£ÊªÍÁÈÀ
//   23--Ó£ÌÒÊ÷Ãç
//   24--ÐÓ×ÓÊ÷Ãç
//   25--³È×ÓÊ÷Ãç
//   26--ÌÒ×ÓÊ÷Ãç
//   27--Ê¯ÁñÊ÷Ãç
//   28--Æ»¹ûÊ÷Ãç
//   29--»¨Êø
// // season 3£º
//   0--ÇÑ×Ó
//   1--ÓñÃ×
//   2--ÄÏ¹Ï
//   3--Ð¡°×²Ë
//   4--É½Ò©
//   5--ÂûÔ½Ý®
//   6--ÏòÈÕ¿û
//   7--Ãµ¹åÏÉ×Ó
//   8--ÜÈ²Ë
//   9--ÆÏÌÑ
//   10--Ð¡Âó
//   11--Ñó¼»
//   12--²Ý×Ñ
//   13--²Ý×ÑÅä·½
//   14--ÌÇ
//   15--´óÂó·Û
//   16--´óÃ×
//   17--ÓÍ
//   18--´×
//   19--³õ¼¶·ÊÁÏ
//   20--¸ß¼‰·ÊÁÏ
//   21--³õ¼¶±£ÊªÍÁÈÀ
//   22--¸ß¼¶±£ÊªÍÁÈÀ
//   23--Ó£ÌÒÊ÷Ãç
//   24--ÐÓ×ÓÊ÷Ãç
//   25--³È×ÓÊ÷Ãç
//   26--ÌÒ×ÓÊ÷Ãç
//   27--Ê¯ÁñÊ÷Ãç
//   28--Æ»¹ûÊ÷Ãç
//   29--»¨Êø
//¶ÔÊÇ·ñÂòµÃÆðµÄÅÐ¶Ï
bool Pierre::isAffordable(backPack* Back, int itemToMake,int season) {
	switch (season) {
	case 1:
		switch (itemToMake) {
			case 0://Parsnip·À·ç²Ý
				if (Back->moneyOut() >= parsnipseed1)
					return 1;
				else
					return 0;
			case 1://GreenBeanÇà¶¹
				if (Back->moneyOut() >= greenbeanseed1)
					return 1;
				else
					return 0;
			case 2://cauliflower»¨Ò¬²Ë
				if (Back->moneyOut() >= cauliflowerseed1)
					return 1;
				else
					return 0;
			case 3://potatoÍÁ¶¹
				if (Back->moneyOut() >= potatoseed1)
					return 1;
				else
					return 0;
			case 4://Tulip bulbsÓô½ðÏãÇò¾¥
				if (Back->moneyOut() >= tulipbulbsseed1)
					return 1;
				else
					return 0;
			case 5://cabbage¸ÊÀ¶
				if (Back->moneyOut() >= cabbageseed1)
					return 1;
				else
					return 0;
			case 6://Blue Jazz À¶¾ôÊ¿
				if (Back->moneyOut() >= bluejazzseed1)
					return 1;
				else
					return 0;
			case 7://Garlic´óËâ
				if(Back->moneyOut() >= garlicseed1)
					return 1;
				else
					return 0;
			case 8://rice seedlingµ¾Ãç
				if (Back->moneyOut() >= riceseedlingseed1)
					return 1;
				else
					return 0;
			case 9://grass seed²Ý×Ñ
				if (Back->moneyOut() >= grassseed1)
					return 1;
				else
					return 0;
			case 10://grass seed formulation²Ý×ÑÅä·½
				if (Back->moneyOut() >= 5)
					return 1;
				else
					return 0;
			case 11://sugar ÌÇ
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 12://barley flour ´óÂó·Û
				if (Back->moneyOut() >= 25)
					return 1;
				else
					return 0;
			case 13://rice ´óÃ×
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 14://oil ÓÍ
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 15://vinegar ´×
				if (Back->moneyOut() >= 15)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer³õ¼¶·ÊÁÏ
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer¸ß¼‰·ÊÁÏ
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 20://Cherry saplingsÓ£ÌÒÊ÷Ãç
				if (Back->moneyOut() >= cherrysaplings1)
					return 1;
				else
					return 0;
			case 21://Apricot saplingsÐÓ×ÓÊ÷Ãç
				if (Back->moneyOut() >= apricotsaplings1)
					return 1;
				else
					return 0;
			case 22://Orange saplings³È×ÓÊ÷Ãç
				if (Back->moneyOut() >= orangesaplings1)
					return 1;
				else
					return 0;
			case 23://Peach saplingsÌÒ×ÓÊ÷Ãç
				if (Back->moneyOut() >= peachsaplings1)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
				if (Back->moneyOut() >= pomegranatesaplings1)
					return 1;
				else
					return 0;
			case 25://Apple saplingsÆ»¹ûÊ÷Ãç
				if (Back->moneyOut() >= applesaplings1)
					return 1;
				else
					return 0;
			case 26://flowers »¨Êø
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			default:
				return 0;
		}
		break;
	case 2:
		switch (itemToMake) {
		case 0://melonÌð¹Ï
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 1://tomatoÎ÷ºìÊÁ
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 2://blueburryÀ¶Ý®
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 3://chili pepperÀ±½·
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 4://wheatÐ¡Âó
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 5://turnipÂÜ²·
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 6://Poppies ÓÝÃÀÈË
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 7://Summer sequinsÏÄ¼¾ÁÁÆ¬
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 8://hop Æ¡¾Æ»¨
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 9://cornÓñÃ×
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 10://sunflowerÏòÈÕ¿û
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 11://Red leaf cabbageºìÒ¶¾íÐÄ²Ë
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 12://grass seed²Ý×Ñ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation²Ý×ÑÅä·½
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ÌÇ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour ´óÂó·Û
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ´óÃ×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ÓÍ
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ´×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers »¨Êø
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		default:
			return 0;
		}
		break;
	case 3:
		switch (itemToMake) {
		case 0://eggplantÇÑ×Ó
			if (Back->moneyOut() >= 20)
				return 1;
			else
				return 0;
		case 1://cornÓñÃ×
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 2://pumpkinÄÏ¹Ï
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 3://Chinese cabbageÐ¡°×²Ë
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 4://yamÉ½Ò©
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 5://CranberriesÂûÔ½Ý®
			if (Back->moneyOut() >= 240)
				return 1;
			else
				return 0;
		case 6://sunflower ÏòÈÕ¿û
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 7://Rose FairyÃµ¹åÏÉ×Ó
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 8://amaranthÜÈ²Ë
			if (Back->moneyOut() >= 70)
				return 1;
			else
				return 0;
		case 9://grapeÆÏÌÑ
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 10://wheatÐ¡Âó
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 11://artichokeÑó¼»
			if (Back->moneyOut() >= 30)
				return 1;
			else
				return 0;
		case 12://grass seed²Ý×Ñ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation²Ý×ÑÅä·½
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ÌÇ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour ´óÂó·Û
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ´óÃ×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ÓÍ
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ´×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers »¨Êø
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		default:
			return 0;
		}
		break;
	}
	return 0;
}

std::string Pierre::itemMoneyOut(int posi,int season) {
	switch (season) {
	case 1:
	{
		switch (posi) {
		case 0:
			return "10";
			break;
		case 1:
			return "30";
			break;
		case 2:
			return "40";
			break;
		case 3:
			return "20";
			break;
		case 4:
			return "10";
			break;
		case 5:
			return "50";
			break;
		case 6:
			return "25";
			break;
		case 7:
			return "30";
			break;
		case 8:
			return "40";
			break;
		case 9:
			return "5";
			break;
		case 10:
			return "50";
			break;
		case 11:
			return "20";
			break;
		case 12:
			return "25";
			break;
		case 13:
			return "50";
			break;
		case 14:
			return "20";
			break;
		case 15:
			return "15";
			break;
		case 16:
			return "30";
			break;
		case 17:
			return "50";
			break;
		case 18:
			return "50";
			break;
		case 19:
			return "100";
			break;
		case 20:
			return "10";
			break;
		case 21:
			return "15";
			break;
		case 22:
			return "25";
			break;
		case 23:
			return "35";
			break;
		case 24:
			return "55";
			break;
		case 25:
			return "55";
			break;
		case 26:
			return "50";
			break;
		}
	}
	case 2: {
		switch (posi) {
		case 0://melonÌð¹Ï
			return "80";
			break;
		case 1://tomatoÎ÷ºìÊÁ
			return "50";
			break;
		case 2://blueburryÀ¶Ý®
			return "80";
			break;
		case 3://chili pepperÀ±½·
			return "40";
			break;
		case 4://wheatÐ¡Âó
			return "10";
			break;
		case 5://turnipÂÜ²·
			return "40";
			break;
		case 6://Poppies ÓÝÃÀÈË
			return "100";
			break;
		case 7://Summer sequinsÏÄ¼¾ÁÁÆ¬
			return "50";
			break;
		case 8://hop Æ¡¾Æ»¨
			return "60";
			break;
		case 9://cornÓñÃ×
			return "150";
			break;
		case 10://sunflowerÏòÈÕ¿û
			return "200";
			break;
		case 11://Red leaf cabbageºìÒ¶¾íÐÄ²Ë
			return "50";
			break;
		case 12://grass seed²Ý×Ñ
			return "5";
			break;
		case 13://grass seed formulation²Ý×ÑÅä·½
			return "50";
			break;
		case 14://sugar ÌÇ
			return "20";
			break;
		case 15://barley flour ´óÂó·Û
			return "25";
			break;
		case 16://rice ´óÃ×
			return "50";
			break;
		case 17://oil ÓÍ
			return "20";
			break;
		case 18://vinegar ´×
			return "15";
			break;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			return "30";
			break;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			return "50";
			break;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			return "50";
			break;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			return "100";
			break;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			return "10";
			break;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			return "15";
			break;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			return "25";
			break;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			return "35";
			break;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			return "55";
			break;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			return "55";
			break;
		case 29://flowers »¨Êø
			return "50";
			break;
		default:
			return 0;
		}
	}
	case 3: {
		switch (posi) {
		case 0://eggplantÇÑ×Ó
			return "20";
			break;
		case 1://cornÓñÃ×
			return "150";
			break;
		case 2://pumpkinÄÏ¹Ï
			return "100";
			break;
		case 3://Chinese cabbageÐ¡°×²Ë
			return "50";
			break;
		case 4://yamÉ½Ò©
			return "60";
			break;
		case 5://CranberriesÂûÔ½Ý®
			return "240";
			break;
		case 6://sunflower ÏòÈÕ¿û
			return "200";
			break;
		case 7://Rose FairyÃµ¹åÏÉ×Ó
			return "200";
			break;
		case 8://amaranthÜÈ²Ë
			return "70";
			break;
		case 9://grapeÆÏÌÑ
			return "60";
			break;
		case 10://wheatÐ¡Âó
			return "10";
			break;
		case 11://artichokeÑó¼»
			return "30";
			break;
		case 12://grass seed²Ý×Ñ
			return "5";
			break;
		case 13://grass seed formulation²Ý×ÑÅä·½
			return "50";
			break;
		case 14://sugar ÌÇ
			return "20";
			break;
		case 15://barley flour ´óÂó·Û
			return "25";
			break;
		case 16://rice ´óÃ×
			return "50";
			break;
		case 17://oil ÓÍ
			return "20";
			break;
		case 18://vinegar ´×
			return "15";
			break;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			return "30";
			break;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			return "50";
			break;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			return "50";
			break;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			return "100";
			break;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			return "10";
			break;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			return "15";
			break;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			return "25";
			break;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			return "35";
			break;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			return "55";
			break;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			return "55";
			break;
		case 29://flowers »¨Êø
			return "50";
			break;
		default:
			return 0;
		}
	}

	default:
		return 0;
		break;
	}
	return 0;
}

int Pierre::itemMoneyBack(int posi, int season) {
	switch (season) {
	case 1:
	{
		switch (posi) {
		case 0:
			return parsnipseed1;
			break;
		case 1:
			return greenbeanseed1;
			break;
		case 2:
			return cauliflowerseed1;
			break;
		case 3:
			return potatoseed1;
			break;
		case 4:
			return tulipbulbsseed1;
			break;
		case 5:
			return cabbageseed1;
			break;
		case 6:
			return bluejazzseed1;
			break;
		case 7:
			return garlicseed1;
			break;
		case 8:
			return riceseedlingseed1;
			break;
		case 9:
			return grassseed1;
			break;
		case 10:
			return 5;
			break;
		case 11:
			return 20;
			break;
		case 12:
			return 25;
			break;
		case 13:
			return 50;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 15;
			break;
		case 16:
			return 30;
			break;
		case 17:
			return 50;
			break;
		case 18:
			return 50;
			break;
		case 19:
			return 100;
			break;
		case 20:
			return cherrysaplings1;
			break;
		case 21:
			return apricotsaplings1;
			break;
		case 22:
			return orangesaplings1;
			break;
		case 23:
			return peachsaplings1;
			break;
		case 24:
			return pomegranatesaplings1;
			break;
		case 25:
			return applesaplings1;
			break;
		case 26:
			return 50;
			break;
		}
	}
	case 2:
	{
		switch (posi) {
		case 0:
			return melonseed1;
			break;
		case 1:
			return tomatoseed1;
			break;
		case 2:
			return blueburryseed1;
			break;
		case 3:
			return chilipepperseed1;
			break;
		case 4:
			return wheatseed1;
			break;
		case 5:
			return turnipseed1;
			break;
		case 6:
			return poppiesseed1;
			break;
		case 7:
			return summersequinsseed1;
			break;
		case 8:
			return hopseed1;
			break; 
		case 9:
			return cornseed1;
			break;
		case 10:
			return sunflowerseed1;
			break;
		case 11:
			return redleafcabbageseed1;
			break;
		case 12:
			return grassseed1;
			break;
		case 13:
			return 5;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 25;
			break;
		case 16:
			return 50;
			break;
		case 17:
			return 20;
			break;
		case 18:
			return 15;
			break;
		case 19:
			return 30;
			break;
		case 20:
			return 50;
			break;
		case 21:
			return 50;
			break;
		case 22:
			return 100;
			break;
		case 23:
			return cherrysaplings1;
			break;
		case 24:
			return apricotsaplings1;
			break;
		case 25:
			return orangesaplings1;
			break;
		case 26:
			return peachsaplings1;
			break;
		case 27:
			return pomegranatesaplings1;
			break;
		case 28:
			return applesaplings1;
			break;
		case 29:
			return 50;
			break;
		}
	}
	case 3:
	{
		switch (posi) {
		case 0:
			return eggplant1;
			break;
		case 1:
			return corn1;
			break;
		case 2:
			return pumpkin1;
			break;
		case 3:
			return chinesecabbage1;
			break;
		case 4:
			return yam1;
			break;
		case 5:
			return cranberries1;
			break;
		case 6:
			return sunflower1;
			break;
		case 7:
			return rosefairy1;
			break;
		case 8:
			return amaranth1;
			break;
		case 9:
			return grape1;
			break;
		case 10:
			return wheat1;
			break;
		case 11:
			return artichoke1;
			break;
		case 12:
			return grassseed1;
			break;
		case 13:
			return 5;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 25;
			break;
		case 16:
			return 50;
			break;
		case 17:
			return 20;
			break;
		case 18:
			return 15;
			break;
		case 19:
			return 30;
			break;
		case 20:
			return 50;
			break;
		case 21:
			return 50;
			break;
		case 22:
			return 100;
			break;
		case 23:
			return cherrysaplings1;
			break;
		case 24:
			return apricotsaplings1;
			break;
		case 25:
			return orangesaplings1;
			break;
		case 26:
			return peachsaplings1;
			break;
		case 27:
			return pomegranatesaplings1;
			break;
		case 28:
			return applesaplings1;
			break;
		case 29:
			return 50;
			break;
		}
	}
	default:
		return 0;
		break;
	}
	return 0;
}

std::string Pierre::itemNameOut(int no, int season,bool choise) {
	std::string outItem;
	switch (season) {
	case 1: {
		switch (no) {
		case 0:
			outItem="parsnipseed";
			break;
		case 1:
			outItem = "greenbeanseed";
			break;
		case 2:
			outItem = "cauliflowerseed";
			break;
		case 3:
			outItem = "potatoseed";
			break;
		case 4:
			outItem = "tulipbulbsseed";
			break;
		case 5:
			outItem = "cabbageseed";
			break;
		case 6:
			outItem = "bluejazzseed";
			break;
		case 7:
			outItem = "garlicseed";
			break;
		case 8:
			outItem = "riceseedlingseed";
			break;
		case 9:
			outItem = "grassseed";
			break;
		case 10:
			outItem = "grassseedformulation";
			break;
		case 11:
			outItem = "sugar";
			break;
		case 12:
			outItem = "barleyflour";
			break;
		case 13:
			outItem = "rice";
			break;
		case 14:
			outItem = "oil";
			break;
		case 15:
			outItem = "vinegar";
			break;
		case 16:
			outItem = "basicfertilizer";
			break;
		case 17:
			outItem = "seniorfertilizer";
			break;
		case 18:
			outItem = "basicremainingsoil";
			break;
		case 19:
			outItem = "seniorremainingsoil";
			break;
		case 20:
			outItem = "cherrysaplings";
			break;
		case 21:
			outItem = "apricotsaplings";
			break;
		case 22:
			outItem = "orangesaplings";
			break;
		case 23:
			outItem = "peachsaplings";
			break;
		case 24:
			outItem = "pomegranatesaplings";
			break;
		case 25:
			outItem = "applesaplings";
			break;
		case 26:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	case 2: {
		switch (no) {
		case 0:
			outItem = "melonseed";
			break;
		case 1:
			outItem = "tomatoseed";
			break;
		case 2:
			outItem = "blueburryseed";
			break;
		case 3:
			outItem = "chilipepperseed";
			break;
		case 4:
			outItem = "wheatseed";
			break;
		case 5:
			outItem = "turnipseed";
			break;
		case 6:
			outItem = "poppiesseed";
			break;
		case 7:
			outItem = "summersequinsseed";
			break;
		case 8:
			outItem = "hopseed"; 
			break;
		case 9:
			outItem = "cornseed";
			break;
		case 10:
			outItem = "sunflowerseed";
			break;
		case 11:
			outItem = "redleafcabbageseed";
			break;
		case 12:
			outItem = "grassseed";
			break;
		case 13:
			outItem = "grassseedformulation";
			break;
		case 14:
			outItem = "sugar";
			break;
		case 15:
			outItem = "barleyflour";
			break;
		case 16:
			outItem = "rice";
			break;
		case 17:
			outItem = "oil";
			break;
		case 18:
			outItem = "vinegar";
			break;
		case 19:
			outItem = "basicfertilizer";
			break;
		case 20:
			outItem = "seniorfertilizer";
			break;
		case 21:
			outItem = "basicremainingsoil";
			break;
		case 22:
			outItem = "seniorremainingsoil";
			break;
		case 23:
			outItem = "cherrysaplings";
			break;
		case 24:
			outItem = "apricotsaplings";
			break;
		case 25:
			outItem = "orangesaplings";
			break;
		case 26:
			outItem = "peachsaplings";
			break;
		case 27:
			outItem = "pomegranatesaplings";
			break;
		case 28:
			outItem = "applesaplings";
			break;
		case 29:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	case 3: {
		switch (no) {
		case 0:
			outItem = "eggplantseed";
			break;
		case 1:
			outItem = "cornseed";
			break;
		case 2:
			outItem = "pumpkinseed";
			break;
		case 3:
			outItem = "chinesecabbageseed";
			break;
		case 4:
			outItem = "yamseed";
			break;
		case 5:
			outItem = "cranberriesseed";
			break;
		case 6:
			outItem = "sunflowerseed";
			break;
		case 7:
			outItem = "rosefairyseed";
			break;
		case 8:
			outItem = "amaranthseed";
			break;
		case 9:
			outItem = "grapeseed";
			break;
		case 10:
			outItem = "wheatseed";
			break;
		case 11:
			outItem = "artichokeseed";
			break;
		case 12:
			outItem = "grassseed";
			break;
		case 13:
			outItem = "grassseedformulation";
			break;
		case 14:
			outItem = "sugar";
			break;
		case 15:
			outItem = "barleyflour";
			break;
		case 16:
			outItem = "rice";
			break;
		case 17:
			outItem = "oil";
			break;
		case 18:
			outItem = "vinegar";
			break;
		case 19:
			outItem = "basicfertilizer";
			break;
		case 20:
			outItem = "seniorfertilizer";
			break;
		case 21:
			outItem = "basicremainingsoil";
			break;
		case 22:
			outItem = "seniorremainingsoil";
			break;
		case 23:
			outItem = "cherrysaplings";
			break;
		case 24:
			outItem = "apricotsaplings";
			break;
		case 25:
			outItem = "orangesaplings";
			break;
		case 26:
			outItem = "peachsaplings";
			break;
		case 27:
			outItem = "pomegranatesaplings";
			break;
		case 28:
			outItem = "applesaplings";
			break;
		case 29:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	default:
		break;
	}
	if (choise == 0)
		return outItem;
	else
		return outItem + ".png";
}

//ÂòÏÂÎïÆ·
Item* Pierre::getItem(backPack* Back, int itemToMake, int season) {
	switch (season){
	case 1:
		switch (itemToMake) {
		case 0://Parsnip·À·ç²Ý
		{
			Item* Parsnip = Seed::create("parsnipseed");
			return Parsnip;
		}
		case 1://GreenBeanÇà¶¹
		{
			Item* GreenBean = Seed::create("greenbean");
			return GreenBean;
		}
		case 2://cauliflower»¨Ò¬²Ë
		{
			Item* Cauliflower = Seed::create("cauliflower");
			return Cauliflower;
		}
		case 3://potatoÍÁ¶¹
		{
			Item* Potato = Seed::create("potato");
			return Potato;
		}
		case 4://Tulip bulbsÓô½ðÏãÇò¾¥
		{
			Item* TulipBulbs = Seed::create("tulipbulbs");
			return TulipBulbs;
		}
		case 5://cabbage¸ÊÀ¶
		{
			Item* Cabbage = Seed::create("cabbage");
			return Cabbage;
		}
		case 6://Blue Jazz À¶¾ôÊ¿
		{
			Item* BlueJazz = Seed::create("bluejazz");
			return BlueJazz;
		}
		case 7://Garlic´óËâ
		{
			Item* Garlic = Seed::create("garlic");
			return Garlic;
		}
		case 8://rice seedlingµ¾Ãç
		{
			Item* RiceSeedling = Seed::create("riceseedling");
			return RiceSeedling;
		}
		case 9://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 10://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 11://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 12://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 13://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 14://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 15://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 16://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 17://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 18://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 19://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 20://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 21://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 22://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 23://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 24://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 25://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 26://flowers »¨Êø
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	case 2:
		switch (itemToMake) {
		case 0://melonÌð¹Ï
		{
			Item* Melon = Seed::create("melonseed");
			return Melon;
		}
		case 1://tomatoÎ÷ºìÊÁ
		{
			Item* Tomato = Seed::create("tomatoseed");
			return Tomato;
		}
		case 2://blueburryÀ¶Ý®
		{
			Item* Blueburry = Seed::create("blueburryseed");
			return Blueburry;
		}
		case 3://chili pepperÀ±½·
		{
			Item* ChiliPepper = Seed::create("chilipepperseed");
			return ChiliPepper;
		}
		case 4://wheatÐ¡Âó
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 5://turnipÂÜ²·
		{
			Item* Turnip = Seed::create("turnipseed");
			return Turnip;
		}
		case 6://Poppies ÓÝÃÀÈË
		{
			Item* Poppies = Seed::create("poppiesseed");
			return Poppies;
		}
		case 7://Summer sequinsÏÄ¼¾ÁÁÆ¬
		{
			Item* SummerSequins = Seed::create("summersequinsseed");
			return SummerSequins;
		}
		case 8://hop Æ¡¾Æ»¨
		{
			Item* Hop = Seed::create("hopseed");
			return Hop;
		}
		case 9://cornÓñÃ×
		{
			Item* Corn = Seed::create("cornseedseed");
			return Corn;
		}
		case 10://sunflowerÏòÈÕ¿û
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 11://Red leaf cabbageºìÒ¶¾íÐÄ²Ë
		{
			Item* RedLeafCabbage = Seed::create("redleafcabbageseed");
			return RedLeafCabbage;
		}
		case 12://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 13://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers »¨Êø
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	case 3:
		switch (itemToMake) {
		case 0://eggplantÇÑ×Ó
		{
			Item* Eggplant = Seed::create("eggplantseed");
			return Eggplant;
		}
		case 1://cornÓñÃ×
		{
			Item* Corn = Seed::create("cornseed");
			return Corn;
		}
		case 2://pumpkinÄÏ¹Ï
		{
			Item* Pumpkin = Seed::create("pumpkinseed");
			return Pumpkin;
		}
		case 3://Chinese cabbageÐ¡°×²Ë
		{
			Item* ChineseCabbage = Seed::create("chinesecabbageseed");
			return ChineseCabbage;
		}
		case 4://yamÉ½Ò©
		{
			Item* Yam = Seed::create("yamseed");
			return Yam;
		}
		case 5://CranberriesÂûÔ½Ý®
		{
			Item* Cranberries = Seed::create("cranberriesseed");
			return Cranberries;
		}
		case 6://sunflower ÏòÈÕ¿û
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 7://Rose FairyÃµ¹åÏÉ×Ó
		{
			Item* RoseFairy = Seed::create("rosefairyseed");
			return RoseFairy;
		}
		case 8://amaranthÜÈ²Ë
		{
			Item* Amaranth = Seed::create("amaranthseed");
			return Amaranth;
		}
		case 9://grapeÆÏÌÑ
		{
			Item* Grape = Seed::create("grapeseed");
			return Grape;
		}
		case 10://wheatÐ¡Âó
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 11://artichokeÑó¼»
		{
			Item* Artichoke = Seed::create("artichokeseed");
			return Artichoke;
		}
		case 12://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseedseed");
			return GrassSeed;
		}
		case 13://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers »¨Êø
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	}
	Item* null;
	return null;
}

void Pierre::seasonEx(int season0) {
	season = season0;
	storeSeasonEx( season0);
}

int Pierre::seasonOut() {
	return season;
}

//Ìú½³ÆÌ²¿·Ö

//ÎïÆ·¶ÔÓ¦Êý×Ö
//  0--Í­¿óÊ¯
//  1--Ìú¿óÊ¯
//  2--ÃºÌ¿
//  3--»Æ½ð¿óÊ¯
//  4--Í­¸«
//  5--Í­Ë®ºø
//  6--Í­¸ä
//  7--Í­³ú
//  8--Ìú¸«
//  9--ÌúË®ºø
//  10--Ìú¸ä
//  11--Ìú³ú
//  12--½ð¸«
//  13--½ðË®ºø
//  14--½ð¸ä
//  15--½ð³ú
//  16--Ò¿¸«
//  17--Ò¿Ë®ºø
//  18--Ò¿¸ä
//  19--Ò¿³ú
//¶ÔÊÇ·ñÂòµÃÆðµÄÅÐ¶Ï
bool BlackSmith::isAffordable(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore Í­¿óÊ¯
	{
		if (Back->moneyOut() >= 75)
			return 1;
		else
			return 0;
	}
	case 1://iron ore Ìú¿óÊ¯
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 2://coal ÃºÌ¿
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 3://gold ore »Æ½ð¿óÊ¯
	{
		if (Back->moneyOut() >= 400)
			return 1;
		else
			return 0;
	}
	case 4://copper axeÍ­¸«
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 5://copper wateringcan Í­Ë®ºø
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 6://copper pickaxe Í­¸ä
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 7://copper hoe Í­³ú
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 8://iron axe Ìú¸«
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 9://iron wateringcan ÌúË®ºø
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 10://iron pickaxe Ìú¸ä
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 11://iron hoe Ìú³ú
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 12://gold axe ½ð¸«
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 13://gold wateringcan ½ðË®ºø
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 14://gold pickaxe ½ð¸ä
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 15://gold hoe ½ð³ú
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 16://iridium axe Ò¿¸«
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 17://iridium wateringcan Ò¿Ë®ºø
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 18://iridium pickaxe Ò¿¸ä
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 19://iridium hoe Ò¿³ú
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	}
	return 0;
}

//ÂòÏÂÎïÆ·
Item* getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore Í­¿óÊ¯
	{
		Item* CopperOre = terial::create("copperore");
		return CopperOre;
	}
	case 1://iron ore Ìú¿óÊ¯
	{
		Item* IronOre = terial::create("ironore");
		return IronOre;
	}
	case 2://coal ÃºÌ¿
	{
		Item* Coal = terial::create("coal");
		return Coal;
	}
	case 3://gold ore »Æ½ð¿óÊ¯
	{
		Item* GoldOre = terial::create("goldore");
		return GoldOre;
	}
	case 4://copper axeÍ­¸«
	{
		Item* CopperAxe = Tool::create("copperaxe");
		return CopperAxe;
	}
	case 5://copper wateringcan Í­Ë®ºø
	{
		Item* CopperWateringcan = Tool::create("copperwateringcan");
		return CopperWateringcan;
	}
	case 6://copper pickaxe Í­¸ä
	{
		Item* CopperPickaxe = Tool::create("copperpickaxe");
		return CopperPickaxe;
	}
	case 7://copper hoe Í­³ú
	{
		Item* CopperHoe = Tool::create("copperhoe");
		return CopperHoe;
	}
	case 8://iron axe Ìú¸«
	{
		Item* IronAxe = Tool::create("ironaxe");
		return IronAxe;
	}
	case 9://iron wateringcan ÌúË®ºø
	{
		Item* IronWateringcan = Tool::create("ironwateringcan");
		return IronWateringcan;
	}
	case 10://iron pickaxe Ìú¸ä
	{
		Item* IronPickaxe = Tool::create("ironpickaxe");
		return IronPickaxe;
	}
	case 11://iron hoe Ìú³ú
	{
		Item* IronHoe = Tool::create("ironhoe");
		return IronHoe;
	}
	case 12://gold axe ½ð¸«
	{
		Item* GoldAxe = Tool::create("goldaxe");
		return GoldAxe;
	}
	case 13://gold wateringcan ½ðË®ºø
	{
		Item* GoldWateringcan = Tool::create("goldwateringcan");
		return GoldWateringcan;
	}
	case 14://gold pickaxe ½ð¸ä
	{
		Item* GoldPickaxe = Tool::create("goldpickaxe");
		return GoldPickaxe;
	}
	case 15://gold hoe ½ð³ú
	{
		Item* GoldHoe= Tool::create("goldhoe");
		return GoldHoe;
	}
	case 16://iridium axe Ò¿¸«
	{
		Item* IridiumAxe = Tool::create("iridiumaxe");
		return IridiumAxe;
	}
	case 17://iridium wateringcan Ò¿Ë®ºø
	{
		Item* IridiumWateringcan = Tool::create("iridiumwateringcan");
		return IridiumWateringcan;
	}
	case 18://iridium pickaxe Ò¿¸ä
	{
		Item* IridiumPickaxe = Tool::create("iridiumpickaxe");
		return IridiumPickaxe;
	}
	case 19://iridium hoe Ò¿³ú
	{
		Item* IridiumHoe = Tool::create("iridiumhoe");
		return IridiumHoe;
	}
	}
	Item* null=new Item();
	return null;
}
