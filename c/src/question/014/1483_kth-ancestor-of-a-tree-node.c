/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1483. 树节点的第 K 个祖先
 * link: https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/16.
 */
#include "public.h"

#define MAX_NUM 50000

/*typedef struct {
    int numbers;
    int parentSize;
    int **parent;
} TreeAncestor;*/

/*
 * 1、硬搞，没算法，就是递归获取值，历史的parent[i][k]表示i的第K个结点，这里历史计算过之后会记录下来。
 */
TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize)
{
    TreeAncestor *tree = (TreeAncestor *)malloc(sizeof(TreeAncestor));
    if (tree == NULL) {
        return NULL;
    }
    tree->numbers = n;
    tree->parentSize = parentSize;
    tree->parent = (int**)malloc(sizeof(int*) * parentSize);
    for (int i = 0; i < parentSize; i++) {
        tree->parent[i] = (int*)malloc(sizeof(int) * (parentSize + 1));
        memset(tree->parent[i], -1, sizeof(int) * (parentSize + 1));
        // node 的第一代祖先就是parent[node];
        tree->parent[i][1] = parent[i];
    }

    for (int i = 1; i < parentSize; i++) {
        for (int j = 2; j < parentSize; j++) {
            if ((j > i) || (tree->parent[i][j - 1] == -1)) { // i最多只有j代祖先
                tree->parent[i][j] = -1;
                break;
            }

            // i上一代的第j-1代祖先 或者 i的第j-1代祖先的上一代
            int font = parent[i];
            tree->parent[i][j] = tree->parent[font][j - 1];
            /*
             * int font = tree->parent[i][j - 1];
             * tree->parent[i][j] = tree->parent[font][1];
             */
        }
    }

    return tree;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    if (node < 0) {
        return -1;
    }

    obj->parent[node][k] = treeAncestorGetKthAncestor(obj, obj->parent[node][k - 1], 1);

    return obj->parent[node][k];
}

/*
 * 2、大佬的倍增法
 */
/*
TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize)
{
    TreeAncestor *tree = (TreeAncestor *)malloc(sizeof(TreeAncestor));
    if (tree == NULL) {
        return NULL;
    }
    tree->numbers = n;
    tree->parentSize = parentSize;
    tree->parent = (int**)malloc(sizeof(int*) * (parentSize + 1));
    for (int i = 0; i <= parentSize; i++) {
        tree->parent[i] = (int*)malloc(sizeof(int) * (parentSize + 1));
        memset(tree->parent[i], 0, sizeof(int) * (parentSize + 1));
    }

    for (int i = 0; i < parentSize; i++) {
        tree->parent[i + 1][0] = parent[i] + 1;
    }

    for (int i = 1; (1 << i) <= tree->numbers; i++) {
        for (int u = 1; u <= tree->numbers; u++) {
            tree->parent[u][i] = tree->parent[tree->parent[u][i - 1]][i - 1];
        }
    }

    return tree;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    int u = node + 1;
    for (int i = 0; (1 << i) <= k; i++) {
        if ((1 << i) & k) {
            u = obj->parent[u][i];
        }
    }

    return u - 1;
}
*/

/*
 * 3、在方法1的基础上做个优化，先查询一次treeAncestorGetKthAncestor(obj, n, n - 1)
 */
/*
TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize)
{
    TreeAncestor *tree = (TreeAncestor *)malloc(sizeof(TreeAncestor));
    if (tree == NULL) {
        return NULL;
    }
    tree->numbers = n;
    tree->parentSize = parentSize;
    tree->parent = (int**)malloc(sizeof(int*) * parentSize);
    for (int i = 0; i < parentSize; i++) {
        tree->parent[i] = (int*)malloc(sizeof(int) * (parentSize + 1));
        memset(tree->parent[i], -1, sizeof(int) * (parentSize + 1));
        tree->parent[i][1] = parent[i];
    }

    treeAncestorGetKthAncestor(tree, n - 1, n - 1);

    return tree;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    if (node < 0) {
        return -1;
    }

    if (k == 1) {
        return obj->parent[node][1];
    }

    if (obj->parent[node][k] != -1) {
        return obj->parent[node][k];
    }

    obj->parent[node][k] = treeAncestorGetKthAncestor(obj, obj->parent[node][1], k - 1);

    return obj->parent[node][k];
}
*/

void treeAncestorFree(TreeAncestor* obj) {
    free(obj->parent);
    free(obj);
    obj = NULL;
}


/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);

 * treeAncestorFree(obj);
*/

/*
void main()
{
    int parent[12] = {-1,0,0,1,2,0,1,3,6,1};

    TreeAncestor* obj = treeAncestorCreate(10, parent, 10);
    int param_1 = treeAncestorGetKthAncestor(obj, 7, 3);

    printf("%d", param_1);
}*/
