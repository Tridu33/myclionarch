// https://blog.csdn.net/dashuniuniu/article/details/52224882 综述

// https://blog.csdn.net/dashuniuniu/article/details/103462147?spm=1001.2014.3001.5501 再谈Domainator tree的计算
// 方舟编译器学习笔记66  Dominance中的支配树和支配边界计算 - 小乖他爹的文章 - 知乎 https://zhuanlan.zhihu.com/p/90305544
class DomTreeNode
{
public:
    enum class color {WHITE, GRAY, BLACK};
private:
    BBPtr TheBB;
    int PostNumber;
    int DFSInNum, DFSOutNum;
    color VisitColor;
    DomTreeNodePtr IDom;

    std::vector<DomTreeNodePtr> Children;
    // Express the predecessor when we depth-first searching of
    // the CFG.
    // e.g.
    //     B1        B2
    //      \        /
    //		 \      /
    //			B3
    // B1 and B2 both the father of B3, but we only can via one
    // node reach B3 when the depth-first searching.
    DomTreeNodePtr Father;
public:
    DomTreeNode(BBPtr BB = nullptr) :
            TheBB(BB), IDom(nullptr), DFSInNum(-1), DFSOutNum(-1),
            PostNumber(-1), Father(nullptr) {}

    BBPtr getBlock() const { return TheBB; }
    DomTreeNodePtr getIDom() const { return IDom; }

    const std::vector<DomTreeNodePtr>& getChildren() const
    {
        return Children;
    }

    DomTreeNodePtr addChild(DomTreeNodePtr Child)
    {
        Children.push_back(Child);
        return Child;
    }

    std::vector<DomTreeNodePtr> Predecessors;
    unsigned getDFSNumIn() const { return DFSInNum; }
    unsigned getDFSNumOut() const { return DFSOutNum; }
    unsigned getPostOrder() const { return PostNumber; }
    bool DominatedBy(DomTreeNodePtr other) const
    {
        return this->DFSInNum >= other->DFSInNum &&
               this->DFSOutNum <= other->DFSOutNum;
    }

    void setDFSInNum(int InNum) { DFSInNum = InNum; }
    void setDFSOutNum(int OutNum) { DFSOutNum = OutNum; }
    void setPostNumber(int PostOrder) { PostNumber = PostOrder; }
    void setVisitColor(color c) { VisitColor = c; }
    void setDFSFather(DomTreeNodePtr DFSFather) { Father = DFSFather; }

    color getVisitColor() const { return VisitColor; }
    size_t getNumChildren() const { return Children.size(); }
    void clearAllChildren() { Children.clear(); }

    void setIDom(DomTreeNodePtr NewIDom)
    {
        IDom = NewIDom;
    }
};

//===------------------------------------------------------------===//
// A dominator tree is a tree where each node's children are those
// nodes it immediately dominates.
// Because the immediate dominator is unique, it is a tree. The start
// node is the root of the tree.

// DominatorTree - This represents the forward Dominance.
class DominatorTree
{
    using DomTreeNodeMapType = std::map<BBPtr, DomTreeNodePtr>;
    DomTreeNodeMapType DomTreeNodes;
    DomTreeNodePtr RootNode;

    std::vector<DomTreeNodePtr> PostOrder;
    std::vector<DomTreeNodePtr> ReversePostOrder;
    std::list<BBPtr> Vertex;

    std::map<DomTreeNodePtr, std::vector<DomTreeNodePtr>> PredecessorrsOfCFG;

    // DominanceFrontier - Represent the forward Dominance Frontier.
    std::map<DomTreeNodePtr, std::set<DomTreeNodePtr>> DominanceFrontier;
    // JoinPoints - Represent the join point(have more than two predecessors)
    // of CFG.
    std::vector<DomTreeNodePtr> JoinNodes;
private:
    void getPostOrder();
    void getReversePostOrder();

    // compute the DomTree.
    void computeDomTree(BBPtr EntryBlock);
    // 获取当前DomNode在CFG中前驱对应的DomTreeNode.
    std::vector<DomTreeNodePtr> getDomNodePredsFromCFG(DomTreeNodePtr Node);
    // Intersect() - This function only be using to get closest parent of A and B.
    DomTreeNodePtr Intersect(DomTreeNodePtr A, DomTreeNodePtr B);

    // Insert the frontier.
    void InsertFrontier(DomTreeNodePtr Node, DomTreeNodePtr FrontierItem);

    // ComputeDomFrontier() - Compute the forward dominance frontier.
    void ComputeDomFrontier();
public:
    // 我们使用 runOnCFG() 和 runOnFunction() 来计算支配树（其实并没有真正构造一棵树出来，只是维护了支配信息）。
    // ComputeDomFrontierOnCFG() 和 ComputeDomFrontierOnFunction() 用来计算支配边界。
    // compute the DomTree of the CFG.
    void runOnCFG(std::vector<BBPtr> &BBs);
    // compute the DomTree of the Function.
    void runOnFunction(FuncPtr F);

    void ComputeDomFrontierOnCFG(std::vector<BBPtr> &BBs);
    void ComputeDomFrontierOnFunction(FuncPtr F);

    DomTreeNodePtr getDomTreeNode(BBPtr BB) const;

    // getRootNode - This returns the entry node for the CFG of the function.
    DomTreeNodePtr getRootNode() { return RootNode; }
    bool properlyDominates(DomTreeNodePtr Node) const;
    bool isReachableFromEntry(BBPtr BB) const;
    bool dominates(DomTreeNodePtr A, DomTreeNodePtr B) const;

    // printIDoms - Convert IDoms to human readable form.
    void printIDoms(std::ostream &out) const;

    // printDF - Convert Dom Frontier to human readable form.
    void printDomFrontier(std::ostream &out) const;

    void DFS(DomTreeNodePtr Node);

    // Calcuate - compute a dominator tree for the given function.
    void Calcuate();

    // dominates - Return true if A dominates B. This perform the special
    // checks necessary if A and B are in the same basic block.
    bool dominates(InstPtr A, InstPtr B) const;
};
/*
 * 上面的代码是 DomTreeNode 以及 DominatorTree 的来定义。

我们使用类 DomTreeNode 来包裹 BasicBlock，
 其中比较重要有 IDom 数据成员用来表示当前结点的直接支配结点，
 另外还有一些辅助深度优先遍历的数据成员。我们通过深度优先遍历确定 CFG 的后序以及逆后序。

我们使用类 DominatorTree 来表示支配树，
 其中 DomTreeNodes 用来表示进行迭代数据流分析时的列表，
 DominanceFrontier 表示每个结点的支配边界集合，
 PredecessorrsOfCFG 表示结点在 CFG 中的前驱结点
 */

void DominatorTree::Calcuate()
{
    if (ReversePostOrder.size() == 0)
        getReversePostOrder();

    // iterate
    bool changed = true;
    RootNode->setIDom(RootNode);

    while (changed)
    {
        changed = false;
        for (auto CurNode : ReversePostOrder)
        {
            if (CurNode == RootNode)
                continue;

            // Get the predecessors of current node.
            auto PredDomNodeFromCFG = getDomNodePredsFromCFG(CurNode);

            // (1) Find the first non-nullptr predecessor.
            auto getAvailiablePred =
                    [this, &PredDomNodeFromCFG]() -> DomTreeNodePtr
                    {
                        // 从Preds中找到一个IDom不为空的predecessor.
                        for (auto pred : PredDomNodeFromCFG)
                        {
                            if (pred->getIDom() != nullptr)
                                return pred;
                        }
                        assert(0 && "Unreachable code.");
                        return nullptr;
                    };

            auto AvailiablePred = getAvailiablePred();
            DomTreeNodePtr NewIDom = AvailiablePred;

            // (2) Traverse other predecessors.
            for (auto pred : PredDomNodeFromCFG)
            {
                if (pred == NewIDom)
                    continue;
                if (pred->getIDom() != nullptr)
                    NewIDom = Intersect(NewIDom, pred);
            }

            // (3) Judge the IDom is changed.
            if (CurNode->getIDom() != NewIDom)
            {
                CurNode->setIDom(NewIDom);
                changed = false;
            }
        }

    }
}

void DominatorTree::ComputeDomFrontier()
{
    DomTreeNodePtr runner = nullptr;
    // Just compute the join points.
    for (auto Node : JoinNodes)
    {
        auto preds = getDomNodePredsFromCFG(Node);
        for (auto pred : preds)
        {
            runner = pred;
            while (runner != Node->getIDom())
            {
                InsertFrontier(runner, Node);
                runner = runner->getIDom();
            }
        }
    }
}





