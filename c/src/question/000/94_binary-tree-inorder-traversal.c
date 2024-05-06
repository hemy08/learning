/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 94. 二叉树的中序遍历
 * link: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/9.
 */

#include "public.h"

#define MAX_NODE_LEN 101

void inorder(struct TreeNode* root, int* res, int* resSize) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    inorder(root->right, res, resSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * MAX_NODE_LEN);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}

/*void inorderStack(struct TreeNode* root, struct TreeNode** stack, int* top) {
    if (root == NULL) {
        return;
    }
    inorderStack(root->left, stack, top);
    stack[(*top)++] = root;
    inorderStack(root->right, stack, top);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode* stk[MAX_NODE_LEN] = {{NULL}};
    *returnSize = 0;
    inorderStack(root, stk, returnSize);

    int* res = malloc(sizeof(int) * (*returnSize));
    (void)memset(res, 0, sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        res[i] = stk[i]->val;
    }
    return res;
}*/


/*
int main()
{

    return 0;
}*/

#define MAX_NODE_NUM 101

int* inorderTraversalIteration(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * MAX_NODE_NUM);
    (void)memset(result, 0, sizeof(int) * MAX_NODE_NUM);


}