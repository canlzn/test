#include "tree.h"
USING_NS_CC;

Tree* Tree::create(const std::string& filename) {
    Tree* tree = new (std::nothrow) Tree();
    if (tree && tree->initWithFile(filename)) {
        tree->autorelease();
        return tree;
    }
    CC_SAFE_DELETE(tree);
    return nullptr;
}


SceneObject::InteractResult Tree::interact() {
    CCLOG("Tree was interacted with!"); 
    this->setTexture("tree_chopped.png"); // 改变树的纹理
    //this->setTexture("land_empty.png");
    return InteractResult(ObjectType::Tree, 5, true); // 玩家获得 5 单位木材
}
