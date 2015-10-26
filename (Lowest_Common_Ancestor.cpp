BTreeNode_t *GetLastCommonParent( BTreeNode_t *pRoot, BTreeNode_t *pNode1, BTreeNode_t *pNode2){
    if( pRoot == NULL ) //说明是空树，不用查找了，也就找不到对应节点，则返回NULL
        return  NULL;

    if( pRoot == pNode1 || pRoot == pNode2 )//说明在当前子树的根节点上找到两个节点之一
        return pRoot;

    BTreeNode_t   *pLeft = GetLastCommonParent( pRoot->m_pLeft, pNode1, pNode2);  //左子树中的查找两个节点并返回查找结果
    BTreeNode_t   *pRight = GetLastCommonParent( pRoot->m_pRight, pNode1, pNode2);//右子树中查找两个节点并返回查找结果

    if( pLeft == NULL )//如果在左子树中没有找到，则断定两个节点都在右子树中，可以返回右子树中查询结果；否则，需要结合左右子树查询结果共同断定
        return pRight;
    if ( pRight == NULL )//如果在右子树中没有找到，则断定两个节点都在左子树中，可以返回左子树中查询结果；否则，需要结合左右子树查询结果共同断定
        return pLeft;
    
    return pRoot;//如果在左右子树中都找两个节点之一，则pRoot就是最低公共祖先节点，返回即可。
}
