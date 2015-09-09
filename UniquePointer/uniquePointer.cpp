#include <cstddef>
#include <memory>
#include <iostream>

template<typename T>
class tree
{
public:
    typedef tree<T> subTreeType;

    tree(T level)
    :mLevel(level),mSubTree(std::unique_ptr<subTreeType>(nullptr)),mHasChild(false)
    {

    }

    void addSubTree(std::unique_ptr<subTreeType> && subTree )
    {
        mSubTree = std::move(subTree);
        mHasChild = true;
    }

    void printTree()
    {
        std::cout<<"level = "<<mLevel<<std::endl;
        if(mHasChild)
        {
            mSubTree->printTree();
        }
    }

private:
    T mLevel;
    std::unique_ptr<subTreeType> mSubTree;
    bool mHasChild;
};

int main(void)
{
    typedef tree<double> treeType;
    typedef treeType::subTreeType subTreeType;

    treeType myTree(0);

    myTree.addSubTree(std::unique_ptr<subTreeType>(new treeType(1)));

    myTree.printTree();

    return 0;
}
