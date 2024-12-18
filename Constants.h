/****************************************************************
 * Project Name: xinglugu-project
 * File Name:constants.h
 * File Function: const define
 * Author:all
 * Update Date:12.4
 * License:
 ****************************************************************/
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "GlobalVariables.h"

namespace Constants {// 使用时要加命名空间
    // 地图相关常量
    constexpr int MAP_BACKGROUND_LAYER_Z_ORDER = 0; // 地图背景层 z-order
    constexpr int MAP_BACKGROUND_LAYER_Z_BASIC = 1;// 地图最底层
    constexpr int MAP_BACKGROUND_LAYER_Z_MIDDLE = 2;//地图中间层
    constexpr int MAP_BACKGROUND_LAYER_Z_SURFACE = 3;//地图显示层
    constexpr int kAnimalLayerZOrder = 1;
    constexpr int kMapWidth = 1280; // 地图宽度
    constexpr int kMapLength = 896; // 地图长度
    constexpr float kScale = 1.0; // 地图缩放比例

    // 动物相关默认值
    constexpr int kDefaultAnimalHunger = 100;    // 默认饥饿度
    constexpr int kDefaultAnimalMood = 100;      // 默认心情
    constexpr int kDefaultAnimalHealth = 100;    // 默认健康值
    constexpr float kAnimalMoveSpeed = 50.0f; // 动物每秒移动的像素距离  
   
    constexpr int OriginHealth = 100;
    constexpr  float INTERACT_DISTANCE = 50.0f;

    //物品类定义时，格式转换使用
    constexpr int primeZ = 0x100000001B3ull;
    constexpr int basisZ = 0xCBF29CE484222325ull;

    //背包栏切换控制量
    const bool BackOpen1 = 0;
    const bool BackOpen2 = 1;
    const bool BackPro1 = 0;
    const bool BackPro2 = 1;
    const int invventoryTag = 100;

    //物品数量的加减使用
    constexpr bool wayOfAdd = 0;
    constexpr bool wayOfDecrease = 1;

    //背包中的限定量
    constexpr int backpackCapacity = 36;
    constexpr int moneyInitialize = 500;
    constexpr int grade1 = 0;
    constexpr int grade2 = 1;
    constexpr int grade3 = 2;

    //合成台限定量
    constexpr int amountOfWoodForWoodenSign = 25;
    constexpr int amountOfWoodForWoodFence = 2;
    constexpr int amountOfWoodForGate = 10;
    constexpr int amountOfFibreForGrassStarter = 10;
    constexpr int amountOfWoodForWoodPath = 1;
    constexpr int amountOfStoneForCobblestonePath = 1;
    constexpr int amountOfWoodForTorch = 1;
    constexpr int amountOfSapForTorch = 2;
    constexpr int amountOfSapForBasicFertilizer = 2;
    constexpr int amountOfWoodForChest = 50;
    constexpr int amountOfStoneForFurnace = 25;
    constexpr int amountOfCopperOreForFurnace = 20;
    constexpr int amountOfStoneForStoneSign = 25;
    constexpr int amountOfIronBarForSprinkle = 1;
    constexpr int amountOfCopperBarForSprinkle = 1;
    constexpr int amountOfStoneForBasicRetainingSoil = 2;
    constexpr int amountOfWoodForScareCrow = 50;
    constexpr int amountOfCoalForScareCrow = 1;
    constexpr int amountOfFibreForScareCrow = 20;
    constexpr int amountOfBugmeatForBait = 1;

    //出售栈相关变量
    constexpr int maxnum = 200;
    constexpr int listInit = -1;

    //物品价值
    constexpr int blowfish1 = 200;
    constexpr int blowfish2 = 250;
    constexpr int blowfish3 = 300;
    constexpr int tuna1 = 100;
    constexpr int tuna2 = 125;
    constexpr int tuna3 = 150;
    constexpr int sardine1 = 40;
    constexpr int sardine2 = 50;
    constexpr int sardine3 = 60;
    constexpr int largemouthbass1 = 100;
    constexpr int largemouthbass2 = 125;
    constexpr int largemouthbass3 = 150;
    constexpr int smallmouthbass1 = 50;
    constexpr int smallmouthbass2 = 62;
    constexpr int smallmouthbass3 = 75;
    constexpr int sunfish1 = 30;
    constexpr int sunfish2 = 37;
    constexpr int sunfish3 = 45;
    constexpr int salmon1 = 75;
    constexpr int salmon2 = 93;
    constexpr int salmon3 = 110;
    constexpr int catfish1 = 200;
    constexpr int catfish2 = 250;
    constexpr int catfish3 = 300;
    constexpr int carp1 = 30;
    constexpr int carp2 = 37;
    constexpr int carp3 = 45;

    constexpr int parsnipseed1 = 10;
    constexpr int greenbeanseed1 = 30;
    constexpr int cauliflowerseed1 = 40;
    constexpr int potatoseed1 = 20;
    constexpr int tulipbulbsseed1 = 10;
    constexpr int cabbageseed1 = 50;
    constexpr int bluejazzseed1 = 25;
    constexpr int garlicseed1 = 30;
    constexpr int  riceseedlingseed1 = 40;
    constexpr int   melonseed1 = 80;
    constexpr int   tomatoseed1 = 50;
    constexpr int   blueburryseed1 = 80;
    constexpr int  chilipepperseed1 = 40;
    constexpr int   wheatseed1 = 10;
    constexpr int   turnipseed1 = 40;
    constexpr int   poppiesseed1 = 100;
    constexpr int   summersequinsseed1 = 50;
    constexpr int   hopseed1 = 60;
    constexpr int        cornseed1 = 150;
    constexpr int    sunflowerseed1 = 200;
    constexpr int  redleafcabbageseed1 = 50;
    constexpr int   eggplantseed1 = 25;
    constexpr int pumpkinseed1 = 55;
    constexpr int    chinesecabbageseed1 = 15;
    constexpr int    yamseed1 = 30;
    constexpr int cranberriesseed1 = 15;
    constexpr int       rosefairyseed1 = 35;
    constexpr int      amaranthseed1 = 10;
    constexpr int     grapeseed1 = 40;
    constexpr int    artichokeseed1 = 10;
    constexpr int   cherrysaplings1 = 10;
    constexpr int     apricotsaplings1 = 15;
    constexpr int   orangesaplings1 = 25;
    constexpr int      peachsaplings1 = 35;
    constexpr int   pomegranatesaplings1 = 55;
    constexpr int   applesaplings1 = 55;
    constexpr int   springseed1 = 65;
    constexpr int    grassseed1 = 5;

    constexpr int  parsnip1 = 200;
    constexpr int  parsnip2 = 250;
    constexpr int  parsnip3 = 300;
    constexpr int  greenbean1 = 100;
    constexpr int  greenbean2 = 125;
    constexpr int  greenbean3 = 150;
    constexpr int  cauliflower1 = 300;
    constexpr int  cauliflower2 = 350;
    constexpr int  cauliflower3 = 400;
    constexpr int  potato1 = 150;
    constexpr int  potato2 = 200;
    constexpr int  potato3 = 250;
    constexpr int  tulipbulbs1 = 50;
    constexpr int  tulipbulbs2 = 100;
    constexpr int  tulipbulbs3 = 150;
    constexpr int  cabbage1 = 75;
    constexpr int  cabbage2 = 93;
    constexpr int  cabbage3 = 110;
    constexpr int   bluejazz1 = 200;
    constexpr int   bluejazz2 = 250;
    constexpr int   bluejazz3 = 300;
    constexpr int  garlic1 = 100;
    constexpr int  garlic2 = 125;
    constexpr int  garlic3 = 150;
    constexpr int  riceseedling1 = 50;
    constexpr int  riceseedling2 = 75;
    constexpr int  riceseedling3 = 100;
    constexpr int  melon1 = 250;
    constexpr int  melon2 = 300;
    constexpr int  melon3 = 350;
    constexpr int  tomato1 = 150;
    constexpr int  tomato2 = 175;
    constexpr int  tomato3 = 200;
    constexpr int  blueburry1 = 125;
    constexpr int  blueburry2 = 150;
    constexpr int  blueburry3 = 175;
    constexpr int  chilipepper1 = 100;
    constexpr int  chilipepper2 = 125;
    constexpr int  chilipepper3 = 150;
    constexpr int  wheat1 = 50;
    constexpr int  wheat2 = 75;
    constexpr int  wheat3 = 100;
    constexpr int  turnip1 = 150;
    constexpr int  turnip2 = 200;
    constexpr int  turnip3 = 250;
    constexpr int  poppies1 = 300;
    constexpr int  poppies2 = 350;
    constexpr int  poppies3 = 400;
    constexpr int  summersequins1 = 200;
    constexpr int  summersequins2 = 250;
    constexpr int  summersequins3 = 300;
    constexpr int  hop1 = 75;
    constexpr int  hop2 = 100;
    constexpr int  hop3 = 125;
    constexpr int  corn1 = 100;
    constexpr int  corn2 = 100;
    constexpr int  corn3 = 100;
    constexpr int  sunflower1 = 150;
    constexpr int  sunflower2 = 175;
    constexpr int  sunflower3 = 200;
    constexpr int  redleafcabbage1 = 200;
    constexpr int  redleafcabbage2 = 250;
    constexpr int  redleafcabbage3 = 300;
    constexpr int  eggplant1 = 150;
    constexpr int  eggplant2 = 200;
    constexpr int  eggplant3 = 250;
    constexpr int  pumpkin1 = 300;
    constexpr int  pumpkin2 = 350;
    constexpr int  pumpkin3 = 400;
    constexpr int   chinesecabbage1 = 100;
    constexpr int   chinesecabbage2 = 125;
    constexpr int   chinesecabbage3 = 150;
    constexpr int yam1 = 150;
    constexpr int yam2 = 200;
    constexpr int yam3 = 250;
    constexpr int  cranberries1 = 100;
    constexpr int  cranberries2 = 125;
    constexpr int  cranberries3 = 150;
    constexpr int  rosefairy1 = 150;
    constexpr int  rosefairy2 = 200;
    constexpr int  rosefairy3 = 250;
    constexpr int amaranth1 = 100;
    constexpr int amaranth2 = 125;
    constexpr int amaranth3 = 150;
    constexpr int  grape1 = 50;
    constexpr int  grape2 = 75;
    constexpr int  grape3 = 100;
    constexpr int  artichoke1 = 150;
    constexpr int  artichoke2 = 200;
    constexpr int  artichoke3 = 250;
    constexpr int rice1 = 50;
    constexpr int rice2 = 75;
    constexpr int rice3 = 100;
    constexpr int  cherry1 = 200;
    constexpr int  cherry2 = 250;
    constexpr int  cherry3 = 300;
    constexpr int  apricot1 = 200;
    constexpr int  apricot2 = 250;
    constexpr int  apricot3 = 300;
    constexpr int  orange1 = 150;
    constexpr int  orange2 = 200;
    constexpr int  orange3 = 250;
    constexpr int  peach1 = 200;
    constexpr int  peach2 = 250;
    constexpr int  peach3 = 300;
    constexpr int pomegranate1 = 150;
    constexpr int pomegranate2 = 200;
    constexpr int pomegranate3 = 250;
    constexpr int  apple1 = 100;
    constexpr int  apple2 = 150;
    constexpr int  apple3 = 200;
    constexpr int wildhorseradish1 = 150;
    constexpr int wildhorseradish2 = 200;
    constexpr int wildhorseradish3 = 250;
    constexpr int  daffodil1 = 100;
    constexpr int  daffodil2 = 125;
    constexpr int  daffodil3 = 150;
    constexpr int  leek1 = 150;
    constexpr int  leek2 = 200;
    constexpr int  leek3 = 250;
    constexpr int Dandelion1 = 100;
    constexpr int Dandelion2 = 125;
    constexpr int Dandelion3 = 150;

    constexpr int egg1 = 10;
    constexpr int bigegg1 = 20;
    constexpr int brownegg1 = 15;
    constexpr int brownbigegg1 = 30;
    constexpr int goldegg1 = 100;
    constexpr int duckegg1 = 20;
    constexpr int duckfeather1 = 10;
    constexpr int animalfeather1 = 15;
    constexpr int  rabbitleg1 = 40;

    constexpr int wood1 = 5;
    constexpr int stone1 = 5;
    constexpr int sap1 = 10;
    constexpr int coal1 = 20;
    constexpr int fibre1 = 15;
    constexpr int copperore1 = 20;
    constexpr int goldore1 = 50;
    constexpr int copperbar1 = 80;
    constexpr int ironbar1 = 120;
    constexpr int goldbar1 = 140;
    constexpr int ironore1 = 30; 


    constexpr float HARVEYx = 300.0f;
    constexpr float HARVEYy = 440.0f;
    constexpr float HALEYx = 940.0f;
    constexpr float HALEYy = 668.0f;
    constexpr float Character_width = 20.0f;
    constexpr float Character_height = 30.0f;
    constexpr float Harveyinmap_X = 312.0f;
    constexpr float Harveyinmap_Y = 408.0f;
    constexpr float Haleyinmap_X = 952.0f;
    constexpr float Haleyinmap_Y = 200.0f;
    constexpr int InteractionDistance = 32;
}
#endif // CONSTANTS_H
