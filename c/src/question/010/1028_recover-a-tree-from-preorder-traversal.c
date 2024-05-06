/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1028. 从先序遍历还原二叉树
 * link: https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/18.
 */

#include "public.h"

#define NUM_LEN 11
#define NODE_INIT(node) \
    (node)->val = 0x00;\
    (node)->left = NULL;\
    (node)->right = NULL;

int getCount(char *c)
{
    int count = 0;
    while (*c == '-') {
        count++;
        *c++;
    }
    return count;
}

int getNumbers(char *c, int *len)
{
    int count = 0;
    char num[NUM_LEN] = {0};

    while ((*c != '-') && (*c != '\0')) {
        num[count] = *c;
        count++;
        c++;
    }

    *len = count;
    return atoi(num);
}

void fillNodeLeft(struct TreeNode* node, char **S, int count)
{
    int len = 0;
    node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node->left == NULL) {
        return;
    }
    NODE_INIT(node->left);
    (*S) += count;
    node->left->val = getNumbers((*S), &len);
    (*S) += len;
}

void fillNodeRight(struct TreeNode* node, char **S, int count)
{
    int len = 0;
    node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node->right == NULL) {
        return;
    }
    NODE_INIT(node->right);
    (*S) += count;
    node->right->val = getNumbers((*S), &len);
    (*S) += len;
}

int RecoverTreeNode(struct TreeNode* node, int level, char **S)
{
    int count = 0;
    int result;

    count = getCount(*S);

    // 父节点或者兄弟节点，返回其父节点
    if (count < level) {
        return count;
    }

    // count不可能比level大，下面处理相等情况
    fillNodeLeft(node, S, count);
    // 填写左节点的子节点
    result = RecoverTreeNode(node->left, level + 1, S);
    // 没有子节点了
    if (result == level) {
        // result 和level相同，说明是当前节点的右节点
        fillNodeRight(node, S, result);
        // 右节点填写子节点
        result = RecoverTreeNode(node->right, level + 1, S);
        // 没有子节点了
        if (result >= level) {
            return 0;
        }
    }

    return result;
}

struct TreeNode* recoverFromPreorder(char *S)
{
    struct TreeNode *root = NULL;
    int len = 0;

    if ((S == NULL) || (strlen(S) == 0)){
        return NULL;
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    NODE_INIT(root);

    root->val = getNumbers(S, &len);
    S += len;
    RecoverTreeNode(root, 1, &S);

    return root;
}

/*
void main()
{
    char s[100] = "1-2--3--4-5--6--7";
    struct TreeNode *root;

    root = recoverFromPreorder(s);

    printf("end.");
}*/
