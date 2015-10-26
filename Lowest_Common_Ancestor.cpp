BTreeNode_t *GetLastCommonParent( BTreeNode_t *pRoot, BTreeNode_t *pNode1, BTreeNode_t *pNode2){
    if( pRoot == NULL )
        return  NULL;

    if( pRoot == pNode1 || pRoot == pNode2 )
        return pRoot;

    BTreeNode_t   *pLeft = GetLastCommonParent( pRoot->m_pLeft, pNode1, pNode2);
    BTreeNode_t   *pRight = GetLastCommonParent( pRoot->m_pRight, pNode1, pNode2);

    if( pLeft == NULL )
        return pRight;
    if ( pRight == NULL )
        return pLeft;
    
    return pRoot;
}
