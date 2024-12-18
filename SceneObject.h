#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "cocos2d.h"

class Tree;

class SceneObject : public cocos2d::Sprite {
public:
    enum class ObjectType {
        Tree,
        Rock,
        Grass,
        // 其他物体类型
    };
    struct Point {
        int x;
        int y;

        Point(int xVal, int yVal) : x(xVal), y(yVal) {}
    };

    struct InteractResult {
        SceneObject::ObjectType type; // 物品类型
        int quantity;                // 玩家获得的资源数量
        bool success;                // 是否成功交互

        InteractResult(SceneObject::ObjectType t, int q, bool s)
            : type(t), quantity(q), success(s) {}
    };

    // 初始化场景物体
    static void initSceneObject(cocos2d::Node* parentNode, float tileWidth, float tileHeight, std::vector<SceneObject*>& objectGrid);

    // 添加物体坐标
    static void addObjectPosition(ObjectType type, const Point& position);

    virtual InteractResult interact() = 0;

private:
    // 存储不同类型物体的坐标
    static std::vector<Point> treePositions;
    static std::vector<Point> rockPositions;
    static std::vector<Point> grassPositions;
   
    // 创建具体物体
    static SceneObject* createObject(ObjectType type, float tileWidth, float tileHeight, const Point& position);
    static void setpoint();
};

#endif // SCENEOBJECT_H