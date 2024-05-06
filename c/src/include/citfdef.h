/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/3.
 */

#include "pub_typedef.h"

#ifndef ____HEMY_CODE_REPO__SRC__LEETCODE_C__INTERFACE__H____
#define ____HEMY_CODE_REPO__SRC__LEETCODE_C__INTERFACE__H____

// 1. 两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

// 2. 两数相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

// 3. 无重复字符的最长子串
int lengthOfLongestSubstring(char *s);

// 5. 最长回文子串
char * longestPalindrome(char * s);

// 6. Z 字形变换
char *convert(char *s, int numRows);

// 7. 整数反转
int reverse(int x);

// 8. 字符串转换整数 (atoi)
int myAtoi(char * s);

// 9. 回文数
bool isPalindrome(int x);

// 10. 正则表达式匹配
bool isMatchRegular(char *s, char *p);

// 剑指 Offer 11. 旋转数组的最小数字
int minArray(int* numbers, int numbersSize);

// 13. 罗马数字转整数
int romanToInt(char * s);

//  14. 最长公共前缀
char * longestCommonPrefix(char ** strs, int strsSize);

// 16. 最接近的三数之和
int threeSumClosest(int nums[], int numsSize, int target);

// 19. 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

// 20. 有效的括号
//bool isValid(char * s);

// 21. 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

// 23. 合并K个排序链表
struct ListNode* mergeTwoListsForK(struct ListNode* l1, struct ListNode* l2);
struct ListNode* mergeKLists1(struct ListNode** lists, int listsSize);
struct ListNode* mergeKLists2(struct ListNode** lists, int listsSize);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);

// 24. 两两交换链表中的节点
struct ListNode* mergeTwoListsForSwapPairs(struct ListNode* list1, struct ListNode* list2);
struct ListNode* swapPairs(struct ListNode* head);  // 拆分再合并
struct ListNode* swapPairsRecursive(struct ListNode* head);  // 递归
struct ListNode* swapPairsIteration(struct ListNode* head);  // 迭代

// 26. 删除排序数组中的重复项
int removeDuplicates(int* nums, int numsSize);

// 27. 移除元素
int removeElement(int* nums, int numsSize, int val);

// 28. 实现 strStr()
int strStr(char * haystack, char * needle);

// 31. 下一个排列;
void nextPermutation(int* nums, int numsSize);

// 33. 搜索旋转排序数组
int searchFuncOne(int* nums, int numsSize, int target);
int dichotomySearch(int *a, int key, int low, int high);
int searchRotated(int* nums, int numsSize, int target);

// 34. 在排序数组中查找元素的第一个和最后一个位置
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

// 35. 搜索插入位置
int searchInsert(int* nums, int numsSize, int target);
int searchInsert2(int* nums, int numsSize, int target);
int binarySearchInsert(int *nums, int key, int low, int high);
int searchInsert3(int* nums, int numsSize, int target);

// 36. 有效的数独
bool isValidSudoku(char** board, int boardSize, int* boardColSize);

// 38. 外观数列
char* GetCount(int n);
char* countAndSay(int n);
char* countAndSayRecursion(int n);

// 41. 缺失的第一个正数
int compIntegerNumber(const void *a, const void *b);
int firstMissingPositive(int* nums, int numsSize);
int firstMissingPositiveBSearch(int* nums, int numsSize);
int firstMissingPositiveSolution2(int* nums, int numsSize);

// 43. 字符串相乘
char * multiply(char * num1, char * num2);

// 44. 通配符匹配
bool isMatchWildCardSolution1(char * s, char * p);
bool isMatchWildCardSolution2(char* s, char* p);

// 45. 跳跃游戏 II
int jump(int* nums, int numsSize);

// 48. 旋转矩阵
void rotateMatrix(int** matrix, int matrixSize, int* matrixColSize);

// 53. 最大子序和
int maxSubArray(int* nums, int numsSize);

// 55. 跳跃游戏
bool canJump(int* nums, int numsSize);

// 56. 合并区间
int** mergeIntervals(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);

// 58. 最后一个单词的长度
int lengthOfLastWord(char * s);

// 59. 螺旋矩阵 II
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);

// 60. 第k个排列
char * getPermutation(int n, int k);

// 61. 旋转链表
struct ListNode* rotateRight(struct ListNode* head, int k);
struct ListNode* rotateRight2(struct ListNode* head, int k);

// 62. 不同路径
int uniquePaths(int m, int n);

// 63. 不同路径 II
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);

// 64. 最小路径和
int minPathSumSolution1(int** grid, int gridSize, int* gridColSize);
int minPathSumSolution2(int** grid, int gridSize, int* gridColSize);

// 66. 加一
int* plusOne(int* digits, int digitsSize, int* returnSize);

// 67. 二进制求和
unsigned int binaryStringToUint(const char *str);
char *uintToBinaryString(unsigned int num);
char *addBinary(const char *a, const char *b);

// 70. 爬楼梯
int funcFibonacciDp(int n, int dp[], int max);
int climbStairs(int n);

// 71. 简化路径
char * simplifyPath(char *path);

// 76. 最小覆盖子串
void getSlidingWindows(const char *left, const char *right, char *result, int *resultSize, int *maxLen);
void deleteSlidingWindowLeftInvalidChar(char **left, int *count_s, const int *count_t);
void moveSlidingWindowRightFrame(char **right, int *count_s, const int *count_t, int *sum_s);
char *minWindow(const char *s, const char *t);

// 81. 搜索旋转排序数组 II
int recurBinary(int *a, int key, int low, int high);
bool searchRotatedII(int* nums, int numsSize, int target);

// 84. 柱状图中最大的矩形
int getMaxArea(int* heights, int heightsSize, int pos);
int largestRectangleArea(int* heights, int heightsSize);

// 88. 合并两个有序数组
void mergeTwoSortArrays(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

// 92. 反转链表 II
struct ListNode* reverseBetween(struct ListNode* head, int m, int n);

// 94. 二叉树的中序遍历
void inorder(struct TreeNode* root, int* res, int* resSize);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
int* inorderTraversalIteration(struct TreeNode* root, int* returnSize);

// 97. 交错字符串
bool isInterleave1(char * s1, char * s2, char * s3);
bool isInterleave2(char* s1, char* s2, char* s3);
bool isInterleave3(char* s1, char* s2, char* s3);

// 99. 恢复二叉搜索树
void recoverTreeSub(struct TreeNode* root, struct TreeNode* node);
void findTreeRootLeft(struct TreeNode* root, struct TreeNode* node);
void findTreeRootRight(struct TreeNode* root, struct TreeNode* node);
void recoverTree(struct TreeNode* root);

// 100. 相同的树
// bool isSameTree(struct TreeNode* p, struct TreeNode* q);

// 162. 寻找峰值
int findPeakElement(int* nums, int numsSize);

// 202. 快乐数
bool isHappy(int n);

// 205. 同构字符串
bool isIsomorphic1(char * s, char * t);
bool isIsomorphic2(char * s, char * t);
bool isIsomorphic3(char * s, char * t);

// 206. 反转链表
struct ListNode* reverseList(struct ListNode* head);

// 215. 数组中的第K个最大元素
int findKthLargest(int* nums, int numsSize, int k);

// 225. 用队列实现栈
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(const MyStack* obj);
bool myStackEmpty(const MyStack* obj);
void myStackFree(MyStack* obj);

// 228. 汇总区间
char ** summaryRanges(int* nums, int numsSize, int* returnSize);

// 229. 求众数 II
int compForMajorityElement(const void*a, const void*b);
int* majorityElement(int* nums, int numsSize, int* returnSize);

// 231. 2的幂
bool isPowerOfTwo(int n);

// 234. 回文链表
bool isPalindromeForLinked(struct ListNode* head);
bool isPalindromePoints(struct ListNode* head);

// 237. 删除链表中的节点
void deleteNode(struct ListNode* node);

// 238. 除自身以外数组的乘积
int *getMultiUp(int* nums, int numsSize);
int *getMultiDown(int* nums, int numsSize);
int* productExceptSelf(int* nums, int numsSize, int* returnSize);

// 239. 滑动窗口最大值
int* maxSlidingWindow1(int* nums, int numsSize, int k, int* returnSize);
int compForSlidingWindow(const void *a, const void *b);
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);

// 242. 有效的字母异位词
bool isAnagram(char * s, char * t);
bool isAnagramQsort(char * s, char * t);

// 252. 会议室
bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize);

// 253. 会议室 II
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize);

// 256. 粉刷房子
int minCost(int** costs, int costsSize, int* costsColSize);
int minCost2(int** costs, int costsSize, int* costsColSize);
int minCost3(int** costs, int costsSize, int* costsColSize);

// 265. 粉刷房子 II
int getMinConstPosition(int *nums, int numsSize, int *pos);
int minCostII(int** costs, int costsSize, int* costsColSize);

// 270. 最接近的二叉搜索树值
int closestValue(struct TreeNode* root, double target);
int closestValue2(struct TreeNode* root, double target);

// 276. 栅栏涂色
int numWays(int n, int k);

// 278. 第一个错误的版本
int firstBadVersion(int n);

// 280. 摆动排序
void swapWiggleSort(int *nums, int a, int b);
void wiggleSort(int* nums, int numsSize);

// 287. 寻找重复数
int findDuplicate(int* nums, int numsSize);

// 295. 数据流的中位数
MedianFinder* medianFinderCreate();
void printfMedianFinder(MedianFinder* obj);
int medianFindInsertPosition(MedianFinder* obj, int num);
void medianFinderAddNum(MedianFinder* obj, int num);
double medianFinderFindMedian(MedianFinder* obj);
void medianFinderFree(MedianFinder* obj);

// 303. 区域和检索 - 数组不可变
NumArray* numArrayCreate(int* nums, int numsSize);
int numArraySumRange(NumArray* obj, int i, int j);
void numArrayFree(NumArray* obj);

// 316. 去除重复字母
int getCharNumbers(int *arr, int arrLen, const char *s);
char *removeDuplicateLetters(char *s);
void countDuplicateLetters(char *s, int *nums, int numsSize);
char* RemoveDuplicateLetters(char* s);

// 321. 拼接最大数
int compareTwoSeq(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2);
int* mergeTwoSeq(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size);
int* MaxSubsequence(int* nums, int numsSize, int k);
void swapForMaxNumber(int** a, int** b);
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize);
int* maxNumber2(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize);

// 329. 矩阵中的最长递增路径
int longestIncreasingPathDfs(int** matrix, int matrixSize, int* matrixColSize);
int longestIncreasingPathTps(int** matrix, int matrixSize, int* matrixColSize);

// 333. 最大 BST 子树
bool largestBSTSubtreeCalc(struct TreeNode* root, int* maxNum, int* leftVal, int* rightVal);
int largestBSTSubtree(struct TreeNode* root);

// 338. 比特位计数
int cover(int num);
int* countBits(int num, int* returnSize);

// 343. 整数拆分
int integerBreak(int n);
int integerBreak2(int n);
int integerBreak3(int n);

// 344. 反转字符串
void reverseString(char* s, int sSize);

// 346. 数据流中的移动平均值
MovingAverage* movingAverageCreate(int size);
double movingAverageNext(MovingAverage* obj, int val);
void movingAverageFree(MovingAverage* obj);
MovingAverageArray* movingAverageCreateWithArray(int size);
double movingAverageNextWithArray(MovingAverageArray* obj, int val);
void movingAverageFreeArray(MovingAverage* obj);

// 349. 两个数组的交集
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

// 350. 两个数组的交集 II
int *intersectWithMinVal(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int* intersectDoublePoint(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int* intersectHashMap(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

// 358. K 距离间隔重排字符串
int calcHashValue(char * s, int i);
void makeHash(char * s);
int compHashTimes(const void* a, const void* b);
void sortHashByTimes();
char getNextWord(int curPos, int k);
char * fillRetVal(char * s, int k);
char * rearrangeString(char * s, int k);

// 362. 敲击计数器
void ReleaseHashNode(HitCounter* obj);
HitCounter* hitCounterCreate();
void hitCounterHit(HitCounter* obj, int timestamp);
int hitCounterGetHits(HitCounter* obj, int timestamp);
void hitCounterFree(HitCounter* obj);

// 369. 给单链表加一
struct ListNode* plusOneLinkedList(struct ListNode* head);

// 383. 赎金信
bool canConstruct(char * ransomNote, char * magazine);

// 392. 判断子序列
bool isSubsequence(char * s, char * t);
bool isSubsequence2(char * s, char * t);
bool isSubsequence3(char * s, char * t);

// 404. 左叶子之和
int isLeafNode(struct TreeNode* node);
int sumOfLeftLeaves(struct TreeNode* root);

// 406. 根据身高重建队列
int compTwoDimensionalArray(const void *a, const void *b);
void resultMove(int** people, int peopleSize, int k);
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes);

// 415. 字符串相加
void ChangeSourceString(char *A, int lenA, char *B, int lenB);
void SumAndPrint(const char *A, const char *B, int len);
char * addStrings(char * num1, char * num2);
int getCharToInt(const char *nums, int *index);
char getNumberAddResult(int num1, int num2, int *flag);
char *addStringsGetResult(char *result, int count, char * num1, char * num2);
char * addStrings2(char * num1, char * num2);

// 442. 数组中重复的数据
int* findDuplicates(int* nums, int numsSize, int* returnSize);

// 448. 找到所有数组中消失的数字
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize);

// 415. 字符串相加
int findContentChildren(int* g, int gSize, int* s, int sSize);

// 480. 滑动窗口中位数
int compMedianSlidingWindow(const void *a, const void *b);
double getMedianNum(const int* nums, int k);
int findKeyOutPos(const int* nums, int key, int low, int high);
int findKeyInPos(int* nums, int numsSize, int key, int low, int high);
void slidingWindowOut(int* nums, int numsSize, int num);
void slidingWindowIn(int* nums, int numsSize, int num);
double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize);

// 503. 下一个更大元素 II
int* nextGreaterElements(int* nums, int numsSize, int* returnSize);

// 504. 七进制数
char * convertToBase7(int num);

// 514. 自由之路
int findRotateSteps(char * ring, char * key);

// 530. 二叉搜索树的最小绝对差
int getMinimumDifference(struct TreeNode* root);

// 562. 矩阵中最长的连续1线段
void longestLineRow(int** M, int i, int j, RecordMatrix** g_record);
void longestLineLine(int** M, int i, int j, RecordMatrix** g_record);
void longestLineX(int** M, int i, int j, RecordMatrix** g_record);
void longestLineY(int** M, int i, int j, int maxJ, RecordMatrix** g_record);
int longestLine(int** M, int MSize, int* MColSize);

// 572. 另一个树的子树
bool checkTreeSame(struct TreeNode* s, struct TreeNode* t);
bool isSubtree(struct TreeNode* s, struct TreeNode* t);

// 582. 杀死进程
int PidCmp(const void* a, const void* b);
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize);

// 635. 设计日志存储系统
LogSystem* logSystemCreate();
void logSystemPut(LogSystem* obj, int id, char * timestamp);
int sysRetrieveLevel(const char *gra);
int* logSystemRetrieve(LogSystem* obj, char * s, char * e, char * gra, int* retSize);
void logSystemFree(LogSystem* obj);

// 657. 机器人能否返回原点
bool judgeCircle(char * moves);

// 680. 验证回文字符串 Ⅱ
bool checkSubStrPalindromeII(const char *start, const char *end, int flag);
bool validPalindrome(char * s);

// 697. 数组的度
int findShortestSubArray(int* nums, int numsSize);

// 739. 每日温度
int* dailyTemperatures(int* T, int TSize, int* returnSize);

// 743. 网络延迟时间
void DijkstraInit();
void DijkstraCreateNoDirection(int** times, int timesSize);
void DijkstraCreateDirection(int** times, int timesSize);
int DijkstraGet(int num, int key);
int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K);

// 746. 使用最小花费爬楼梯
int minCostClimbingStairs(int* cost, int costSize);
int minCostClimbingStairs2(int* cost, int costSize);

// 758. 字符串中的加粗单词
bool IsContain(char* a, int al, char* b, int bl);
void OutputBoldWord(char *str, int *idx, char *S, int b, int e);
char * boldWords(char ** words, int wordsSize, char * S);

// 767. 重构字符串
char * reorganizeString(char * S);

// 771. 宝石与石头
int numJewelsInStones(char * J, char * S);

// 783. 二叉搜索树节点最小距离
int minDiffInBST(struct TreeNode* root);

// 799. 香槟塔
double champagneTower(int poured, int query_row, int query_glass);
double champagneTower2(int poured, int query_row, int query_glass);

// 820. 单词的压缩编码
int minimumLengthEncoding(char ** words, int wordsSize);

// 843. 猜猜这个单词
void findSecretWord(char** wordlist, int wordlistSize, Master* master);
int compareFindSecretWord(char *s1, char* s2);

// 844. 比较含退格的字符串
void delBackSpace(char * input, char * output);
bool backspaceCompare(char * S, char * T);

// 860. 柠檬水找零
bool lemonadeChange(int* bills, int billsSize);

// 862. 和至少为 K 的最短子数组
int shortestSubarray(int* A, int ASize, int K);

// 866. 回文素数
int isPrime(int x);
int covertStringToInteger(const char *acBuf, int maxLen);
void makePalindrome(const int N, char *str, const int len, int l, int r);
int primePalindrome(int N);

// 874. 模拟行走机器人
int compRobotSim(const void *a, const void *b);
bool binarySearchWalking(int x, int y, int** obstacles, int obstaclesSize, int begin, int end);
bool judegIsObstructions(int x, int y, int** obstacles, int obstaclesSize) ;
void robotMonves(int *x, int*y, int drct, int cmds, int** obstacles, int obstaclesSize);
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize);

// 904. 水果成篮
int totalFruit(int* tree, int treeSize);

// 922. 按奇偶排序数组 II
int* sortArrayByParityII(int* A, int ASize, int* returnSize);

// 925. 长按键入
bool isLongPressedName(char * name, char * typed);
bool isLongPressedName2(char * name, char * typed);

// 944. 删列造序
int minDeletionSize( char ** A , int ASize );

// 973. 最接近原点的 K 个点
int compareClosest(void *a, void *b);
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes);

// 1008. 先序遍历构造二叉树
void InsertNode(struct TreeNode *root, int value);
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize);

// 1011. 在 D 天内送达包裹的能力
int averageWeight(int *weights, int weightsSize);
int cmpShipWeight(const void *a, const void *b);
int countShipWeight(int *weights, int weightsSize, int D, int Days);
int shipWithinDays(int *weights, int weightsSize, int D);

// 1025. 除数博弈
bool divisorGame(int N);

// 1028. 从先序遍历还原二叉树
int getCount(char *c);
int getNumbers(char *c, int *len);
void fillNodeLeft(struct TreeNode* node, char **S, int count);
void fillNodeRight(struct TreeNode* node, char **S, int count);
int RecoverTreeNode(struct TreeNode* node, int level, char **S);
struct TreeNode* recoverFromPreorder(char *S);

// 1055. 形成字符串的最短路径
int shortestWay(char * source, char * target);

// 1081. 不同字符的最小子序列
int countCharNumbers(int *arr, int arrLen, const char *s);
char *smallestSubsequence(char *s);

// 1095. 山脉数组中查找目标值
int binarySearchMountain(MountainArray* mountainArr, int low, int high, int key, int type);
int findMountainPeak(MountainArray* mountainArr, int low, int high);
int findInMountainArray(int target, MountainArray* mountainArr);

// 1109. 航班预订统计
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize);
int* corpFlightBookings2(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize);

// 1139. 最大的以 1 为边界的正方形
int getLagestNum(int **grid, int row, int col);
int largest1BorderedSquare(int grid[3][3], int gridSize, int *gridColSize);
int largest1BorderedSquare2(int** grid, int gridSize, int* gridColSize);

// 1151. 最少交换次数来组合所有的 1
int minSwaps(int* data, int dataSize);

// 1165. 单行键盘
int calculateTime(char * keyboard, char * word);

// 1216. 验证回文字符串 III
bool checkSubStrPalindromeIII(const char *start, const char *end, int flag);
bool isValidPalindrome(char * s, int k);

// 1269. 停在原地的方案数
bool judgeParamIsInvalid(int steps, int arrLen, int loc);
bool judgeLastStep(int steps, int arrLen, int loc);
long numWaysCalc(int steps, int arrLen, int loc);
int numWays1269(int steps, int arrLen);

// 1367. 二叉树中的列表
bool findPath(struct ListNode *head, struct TreeNode *root);
bool isSubPath(struct ListNode *head, struct TreeNode *root);

// 1470. 重新排列数组
int* shuffle(int* nums, int numsSize, int n, int* returnSize);

// 1471. 数组中的 k 个最强值
int compForStrongEstVal1(const void *a, const void* b);
int compForStrongEstVal2(const void *a, const void* b);
int* getStrongest(int* arr, int arrSize, int k, int* returnSize);

// 1472. 设计浏览器历史记录
BrowserHistory* browserHistoryCreate(char * homepage);
void browserHistoryVisit(BrowserHistory* obj, char * url);
char * browserHistoryBack(BrowserHistory* obj, int steps);
char * browserHistoryForward(BrowserHistory* obj, int steps);
void browserHistoryFree(BrowserHistory* obj);

// 1480. 一维数组的动态和
int* runningSum(int* nums, int numsSize, int* returnSize);

// 1481. 不同整数的最少数目
int compForRegularMatch(const void *a, const void *b);
int findLeastNumOfUniqueInts(int* arr, int arrSize, int k);

// 1483. 树节点的第 K 个祖先
TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize);
int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k);
void treeAncestorFree(TreeAncestor* obj);

// 1486. 数组异或操作
int xorOperation(int n, int start);

// 1487. 保证文件名唯一
bool CheckIsRepeat(char **names, int namesSize, const char *src, int *pos);
char ** getFolderNames(char **names, int namesSize, int *returnSize);

// 1512. 好数对的数目
int numIdenticalPairs(int* nums, int numsSize);

// 1564. 把箱子放进仓库里 I
int maxBoxesInWarehouse(int* boxes, int boxesSize, int* warehouse, int warehouseSize);

// 503. 下一个更大元素 II
int* nextGreaterElements(int* nums, int numsSize, int* returnSize);

#endif //____HEMY_CODE_REPO__SRC__LEETCODE_C__INTERFACE__H____
