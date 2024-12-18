#ifndef __FISHING_H__
#define __FISHING_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class FishingLayer : public Layer
{
public:
    // 构造和析构函数
    FishingLayer();
    virtual ~FishingLayer();

    // 创建 FishingLayer 实例
    static FishingLayer* createLayer();

    // 初始化 FishingLayer
    virtual bool init();

    // 启动钓鱼过程
    void startFishing();

    // 更新进度条
    void updateProgressBar(float dt);

    // 按钮点击事件：开始钓鱼
    void onFishingButtonClicked(Ref* sender);

    // 钓鱼成功后的处理
    void onFishCaught();

    // 钓鱼失败后的处理
    void onFishMissed();

private:
    ProgressTimer* m_progressBar;   // 进度条
    Label* m_infoLabel;             // 信息标签
    MenuItemImage* m_startButton;   // 开始钓鱼按钮
    bool m_isFishingInProgress;     // 是否正在钓鱼
    float m_fishingProgress;        // 钓鱼进度
};

#endif // __FISHING_H__