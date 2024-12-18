/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "MainScene.h"
#include "startScene.h"
#include "Constants.h"

 // #define USE_AUDIO_ENGINE 1
 // #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

//static cocos2d::Size designResolutionSize = cocos2d::Size(1920, 1080);
static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 896);
//static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
static cocos2d::Size myResolutionSize = cocos2d::Size(Constants::kMapWidth, Constants::kMapLength);
//static cocos2d::Size myResolutionSize = cocos2d::Size(1280,1080);

cocos2d::TMXTiledMap* g_sharedTMXtwo = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXthree = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXcurrent = nullptr;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("StardewVallage", cocos2d::Rect(0, 0, myResolutionSize.width, myResolutionSize.height));
#else
        glview = GLViewImpl::create("MyGame");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {
        director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
    }

    glview->setDesignResolutionSize(Constants::kMapWidth, Constants::kMapLength, ResolutionPolicy::SHOW_ALL);
    Director::getInstance()->setContentScaleFactor(1.0f);

    g_sharedTMXone = TMXTiledMap::create("nf.tmx");
    g_sharedTMXtwo = TMXTiledMap::create("mine.tmx");
    g_sharedTMXthree = TMXTiledMap::create("forest01.tmx");

    auto map = g_sharedTMXone;
    CCLOG("g_sharedTMXone Anchor Point: %f, %f", map->getAnchorPoint().x, map->getAnchorPoint().y);
    CCLOG("g_sharedTMXone Position: %f, %f", map->getPosition().x, map->getPosition().y);
    CCLOG("g_sharedTMXone Scale: %f", map->getScale());
    CCLOG("g_sharedTMXone Content Size: %f x %f", map->getContentSize().width, map->getContentSize().height);


    g_sharedTMXcurrent = g_sharedTMXone;
    if (g_sharedTMXone) g_sharedTMXone->retain();
    if (g_sharedTMXtwo) g_sharedTMXtwo->retain();
    if (g_sharedTMXthree) g_sharedTMXthree->retain();

    CCLOG("Initialized g_sharedTMXone: %p", g_sharedTMXone);
    CCLOG("Initialized g_sharedTMXtwo: %p", g_sharedTMXtwo);
    CCLOG("Initialized g_sharedTMXthree: %p", g_sharedTMXthree);

    register_all_packages();

    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();

    auto scene = startScene::createScene();
    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationWillTerminate() {
    // 释放全局变量
    if (g_sharedTMXone) {
        g_sharedTMXone->release();
        g_sharedTMXone = nullptr;
    }
    if (g_sharedTMXtwo) {
        g_sharedTMXtwo->release();
        g_sharedTMXtwo = nullptr;
    }
    if (g_sharedTMXthree) {
        g_sharedTMXthree->release();
        g_sharedTMXthree = nullptr;
    }
    CCLOG("Released global TMXTiledMap objects.");
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
