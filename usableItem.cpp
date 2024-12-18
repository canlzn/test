/****************************************************************
 * Project Name: xinglugu-project
 * File Name:usableItem.cpp
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
 * License:
 ****************************************************************/
#include"usableItem.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;
//----基类Item

//数量更改函数
void Item::quantityChange(bool way, int amount) {
	if (way == wayOfAdd)
		quantity += amount;
	else
		quantity -= amount;
}

//文件名返回
char const* Item::filenameReturn() {
	return pictureName;
}

//物品是否可卖
bool Item::isSoldAble() {
	if (itemtype == ItemType::null || itemtype == ItemType::tool)
		return 0;
	else
		return 1;
}

//物品价值
int Item::moneyToSell() {
	return 0;
}

//左键的作用
void Item::leftKeyFunction() {
	;
}

//右键的作用
void Item::rightKeyFunction() {
	;
}

//----子类Fish

//右键 （吃）
void Fish::rightKeyFunction() {
	;
}

//卖钱
int Fish::moneyToSell() {
	switch (currentSeed) {
	case SeedKind::blowfish:
	{
		switch (quality) {
		case 1:
			return blowfish1;
			break;
		case 2:
			return blowfish2;
			break;
		case 3:
			return blowfish3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::tuna:
	{
		switch (quality) {
		case 1:
			return tuna1;
			break;
		case 2:
			return tuna2;
			break;
		case 3:
			return tuna3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::sardine: {
		switch (quality) {
		case 1:
			return sardine1;
			break;
		case 2:
			return sardine2;
			break;
		case 3:
			return sardine3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::largemouthbass: {
		switch (quality) {
		case 1:
			return largemouthbass1;
			break;
		case 2:
			return largemouthbass2;
			break;
		case 3:
			return largemouthbass3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::smallmouthbass: {
		switch (quality) {
		case 1:
			return smallmouthbass1;
			break;
		case 2:
			return smallmouthbass2;
			break;
		case 3:
			return smallmouthbass3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::sunfish: {
		switch (quality) {
		case 1:
			return sunfish1;
			break;
		case 2:
			return sunfish2;
			break;
		case 3:
			return sunfish3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::salmon: {
		switch (quality) {
		case 1:
			return salmon1;
			break;
		case 2:
			return salmon2;
			break;
		case 3:
			return salmon3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::catfish: {
		switch (quality) {
		case 1:
			return catfish1;
			break;
		case 2:
			return catfish2;
			break;
		case 3:
			return catfish3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case SeedKind::carp: {
		switch (quality) {
		case 1:
			return carp1;
			break;
		case 2:
			return carp2;
			break;
		case 3:
			return carp3;
			break;
		default:
			return 0;
			break;
		}
	}
	default:
		return 0;
		break;
	}
	return 0;
}

//----子类Seed

 //卖钱
int Seed::moneyToSell() {
	switch (currentSeed) {
	case SeedKind::parsnipseed:
	{
		return parsnipseed1;
		break;
	}
	case SeedKind::greenbeanseed:
	{
		return greenbeanseed1;
		break;
	}
	case SeedKind::cauliflowerseed: {
		return cauliflowerseed1;
		break;
	}
	case SeedKind::potatoseed: {
		return potatoseed1;
		break;
	}
	case SeedKind::tulipbulbsseed: {
		return tulipbulbsseed1;
		break;
	}
	case SeedKind::cabbageseed: {
		return cabbageseed1;
		break;
	}
	case SeedKind::bluejazzseed: {
		return bluejazzseed1;
		break;
	}
	case SeedKind::garlicseed: {
		return garlicseed1;
		break;
	}
	case SeedKind::riceseedlingseed: {
		return riceseedlingseed1;
		break;
	}
	case SeedKind::melonseed: {
		return melonseed1;
		break;
	}
	case SeedKind::tomatoseed: {
		return tomatoseed1;
		break;
	}
	case SeedKind::blueburryseed: {
		return blueburryseed1;
		break;
	}
	case SeedKind::chilipepperseed: {
		return chilipepperseed1;
		break;
	}
	case SeedKind::wheatseed: {
		return wheatseed1;
		break;
	}
	case SeedKind::turnipseed: {
		return turnipseed1;
		break;
	}
	case SeedKind::poppiesseed: {
		return poppiesseed1;
		break;
	}
	case SeedKind::summersequinsseed: {
		return summersequinsseed1;
		break;
	}
	case SeedKind::hopseed: {
		return hopseed1;
		break;
	}
	case SeedKind::cornseed: {
		return cornseed1;
		break;
	}
	case SeedKind::sunflowerseed: {
		return sunflowerseed1;
		break;
	}
	case SeedKind::redleafcabbageseed: {
		return redleafcabbageseed1;
		break;
	}
	case SeedKind::eggplantseed: {
		return eggplantseed1;
		break;
	}
	case SeedKind::pumpkinseed: {
		return pumpkinseed1;
		break;
	}
	case SeedKind::chinesecabbageseed: {
		return chinesecabbageseed1;
		break;
	}
	case SeedKind::yamseed: {
		return yamseed1;
		break;
	}
	case SeedKind::cranberriesseed: {
		return cranberriesseed1;
		break;
	}
	case SeedKind::rosefairyseed: {
		return rosefairyseed1;
		break;

	case SeedKind::amaranthseed: {
		return amaranthseed1;
		break;
	}
	case SeedKind::grapeseed: {
		return grapeseed1;
		break;
	}
	case SeedKind::artichokeseed: {
		return artichokeseed1;
		break;
	}
	case SeedKind::cherrysaplings: {
		return cherrysaplings1;
		break;
	}
	case SeedKind::apricotsaplings: {
		return apricotsaplings1;
		break;
	}
	case SeedKind::orangesaplings: {
		return orangesaplings1;
		break;
	}
	case SeedKind::peachsaplings: {
		return peachsaplings1;
		break;
	}
	case SeedKind::pomegranatesaplings: {
		return pomegranatesaplings1;
		break;
	}
	case SeedKind::applesaplings: {
		return applesaplings1;
		break;
	}
	case SeedKind::springseed: {
		return springseed1;
		break;
	}
	case SeedKind::grassseed: {
		return grassseed1;
		break;
	}
	}
								return 0;
	}
}
//----子类Tool

 //左键功能
void Tool::leftKeyFunction() {
	;
}

//右键功能
void Tool::rightKeyFunction() {

}

//----子类Fruit

//右键（吃）
void Fruit::rightKeyFunction() {
	;
}

//卖钱
int Fruit::moneyToSell() {
	switch (currentSeed) {
	case fruitKind::parsnip:
	{
		switch (quality) {
		case 1:
			return parsnip1;
			break;
		case 2:
			return parsnip2;
			break;
		case 3:
			return parsnip3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::greenbean:
	{
		switch (quality) {
		case 1:
			return greenbean1;
			break;
		case 2:
			return greenbean2;
			break;
		case 3:
			return greenbean3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::cauliflower: {
		switch (quality) {
		case 1:
			return cauliflower1;
			break;
		case 2:
			return cauliflower2;
			break;
		case 3:
			return cauliflower3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::potato: {
		switch (quality) {
		case 1:
			return potato1;
			break;
		case 2:
			return potato2;
			break;
		case 3:
			return potato3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::tulipbulbs: {
		switch (quality) {
		case 1:
			return tulipbulbs1;
			break;
		case 2:
			return tulipbulbs2;
			break;
		case 3:
			return tulipbulbs3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::cabbage: {
		switch (quality) {
		case 1:
			return cabbage1;
			break;
		case 2:
			return cabbage2;
			break;
		case 3:
			return cabbage3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::bluejazz: {
		switch (quality) {
		case 1:
			return bluejazz1;
			break;
		case 2:
			return bluejazz2;
			break;
		case 3:
			return bluejazz3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::garlic: {
		switch (quality) {
		case 1:
			return garlic1;
			break;
		case 2:
			return garlic2;
			break;
		case 3:
			return garlic3;
			break;
		default:
			return 0;
			break;
		}
		break;
	}
	case fruitKind::riceseedling: {
		switch (quality) {
		case 1:
			return riceseedling1;
			break;
		case 2:
			return riceseedling2;
			break;
		case 3:
			return riceseedling3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::tomato: {
		switch (quality) {
		case 1:
			return tomato1;
			break;
		case 2:
			return tomato2;
			break;
		case 3:
			return tomato3;
			break;
		default:
			return 0;
			break;
		}

	case fruitKind::melon: {
		switch (quality) {
		case 1:
			return 30;
			break;
		case 2:
			return 37;
			break;
		case 3:
			return 45;
			break;
		default:
			return 0;
			break;
		}
	}
	default:
		return 0;
		break;
	}
	case fruitKind::blueburry: {
		switch (quality) {
		case 1:
			return blueburry1;
			break;
		case 2:
			return blueburry2;
			break;
		case 3:
			return blueburry3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::chilipepper: {
		switch (quality) {
		case 1:
			return chilipepper1;
			break;
		case 2:
			return chilipepper2;
			break;
		case 3:
			return chilipepper3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::wheat: {
		switch (quality) {
		case 1:
			return wheat1;
			break;
		case 2:
			return wheat2;
			break;
		case 3:
			return wheat3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::turnip: {
		switch (quality) {
		case 1:
			return turnip1;
			break;
		case 2:
			return turnip2;
			break;
		case 3:
			return turnip3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::poppies: {
		switch (quality) {
		case 1:
			return poppies1;
			break;
		case 2:
			return poppies2;
			break;
		case 3:
			return poppies3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::summersequins: {
		switch (quality) {
		case 1:
			return summersequins1;
			break;
		case 2:
			return summersequins2;
			break;
		case 3:
			return summersequins3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::hop: {
		switch (quality) {
		case 1:
			return hop1;
			break;
		case 2:
			return hop2;
			break;
		case 3:
			return hop3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::corn: {
		switch (quality) {
		case 1:
			return corn1;
			break;
		case 2:
			return corn2;
			break;
		case 3:
			return corn3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::sunflower: {
		switch (quality) {
		case 1:
			return sunflower1;
			break;
		case 2:
			return sunflower2;
			break;
		case 3:
			return sunflower3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::redleafcabbage: {
		switch (quality) {
		case 1:
			return redleafcabbage1;
			break;
		case 2:
			return redleafcabbage2;
			break;
		case 3:
			return redleafcabbage3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::eggplant: {
		switch (quality) {
		case 1:
			return eggplant1;
			break;
		case 2:
			return eggplant2;
			break;
		case 3:
			return eggplant3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::pumpkin: {
		switch (quality) {
		case 1:
			return pumpkin1;
			break;
		case 2:
			return pumpkin2;
			break;
		case 3:
			return pumpkin3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::chinesecabbage: {
		switch (quality) {
		case 1:
			return chinesecabbage1;
			break;
		case 2:
			return chinesecabbage2;
			break;
		case 3:
			return chinesecabbage3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::yam: {
		switch (quality) {
		case 1:
			return yam1;
			break;
		case 2:
			return yam2;
			break;
		case 3:
			return yam3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::cranberries: {

		switch (quality) {
		case 1:
			return cranberries1;
			break;
		case 2:
			return cranberries2;
			break;
		case 3:
			return cranberries3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::rosefairy: {

		switch (quality) {
		case 1:
			return rosefairy1;
			break;
		case 2:
			return rosefairy2;
			break;
		case 3:
			return rosefairy3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::amaranth: {

		switch (quality) {
		case 1:
			return amaranth1;
			break;
		case 2:
			return amaranth2;
			break;
		case 3:
			return amaranth3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::grape: {

		switch (quality) {
		case 1:
			return grape1;
			break;
		case 2:
			return grape2;
			break;
		case 3:
			return grape3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::artichoke: {

		switch (quality) {
		case 1:
			return artichoke1;
			break;
		case 2:
			return artichoke2;
			break;
		case 3:
			return artichoke3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::rice: {

		switch (quality) {
		case 1:
			return rice1;
			break;
		case 2:
			return rice2;
			break;
		case 3:
			return rice3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::cherry: {

		switch (quality) {
		case 1:
			return cherry1;
			break;
		case 2:
			return cherry2;
			break;
		case 3:
			return cherry3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::apricot: {

		switch (quality) {
		case 1:
			return apricot1;
			break;
		case 2:
			return apricot2;
			break;
		case 3:
			return apricot3;
			break;
		default:
			return 0;
			break;
		}


	}
	case fruitKind::orange: {

		switch (quality) {
		case 1:
			return orange1;
			break;
		case 2:
			return orange2;
			break;
		case 3:
			return orange3;
			break;
		default:
			return 0;
			break;
		}

	}
	case fruitKind::peach: {

		switch (quality) {
		case 1:
			return peach1;
			break;
		case 2:
			return peach2;
			break;
		case 3:
			return peach3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::pomegranate: {
		switch (quality) {
		case 1:
			return pomegranate1;
			break;
		case 2:
			return pomegranate2;
			break;
		case 3:
			return pomegranate3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::apple: {
		switch (quality) {
		case 1:
			return apple1;
			break;
		case 2:
			return apple2;
			break;
		case 3:
			return apple3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::wildhorseradish: {
		switch (quality) {
		case 1:
			return wildhorseradish1;
			break;
		case 2:
			return wildhorseradish2;
			break;
		case 3:
			return wildhorseradish3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::daffodil: {
		switch (quality) {
		case 1:
			return daffodil1;
			break;
		case 2:
			return daffodil2;
			break;
		case 3:
			return daffodil3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::leek: {
		switch (quality) {
		case 1:
			return leek1;
			break;
		case 2:
			return leek2;
			break;
		case 3:
			return leek3;
			break;
		default:
			return 0;
			break;
		}
	}
	case fruitKind::Dandelion: {
		switch (quality) {
		case 1:
			return Dandelion1;
			break;
		case 2:
			return Dandelion2;
			break;
		case 3:
			return Dandelion3;
			break;
		default:
			return 0;
			break;
		}
	}
	}
	return 0;
}

//----子类AnimalProduct

//右键 （吃）
void AnimalProduct::rightKeyFunction() {
	;
}

//卖钱
int AnimalProduct::moneyToSell() {
	switch (currentProduct) {
	case AnimalProductKind::egg:
		return egg1;
	case AnimalProductKind::bigegg:
		return bigegg1;
	case AnimalProductKind::brownegg:
		return brownegg1;
	case AnimalProductKind::brownbigegg:
		return brownbigegg1;
	case AnimalProductKind::goldegg:
		return goldegg1;
	case AnimalProductKind::duckegg:
		return duckegg1;
	case  AnimalProductKind::duckfeather:
		return duckfeather1;
	case AnimalProductKind::animalfeather:
		return animalfeather1;
	case AnimalProductKind::rabbitleg:
		return rabbitleg1;
	default:
		return 0;
	}
	return 0;
}

//----子类terial

//卖钱
int terial::moneyToSell() {
	switch (currentProduct) {
	case terialKind::wood:
		return wood1;
		break;
	case terialKind::stone:
		return stone1;
		break;
	case terialKind::sap:
		return sap1;
		break;
	case terialKind::coal:
		return coal1;
		break;
	case terialKind::fibre:
		return fibre1;
		break;
	case terialKind::copperore:
		return copperore1;
		break;
	case terialKind::goldore:
		return goldore1;
		break;
	case terialKind::copperbar:
		return copperbar1;
		break;
	case terialKind::ironbar:
		return ironbar1;
		break;
	case terialKind::goldbar:
		return goldbar1;
		break;
	case terialKind::ironore:
		return ironore1;
		break;
	}
	return 0;
}