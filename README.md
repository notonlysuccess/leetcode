3Sum Closest		O(n^2log(n))  
3Sum			O(n^2log(n))  
4Sum			O(n^3log(n))  
Add Binary		模拟二进制加法  
Add Two Numbers		模拟链表加法，同上  
Anagrams		筛选出由相同字母组成的字符串  
Balanced Binary Tree	检查是否是二叉平衡树  
Best Time to Buy and Sell Stock III	知道股票每日价格，只能交易两笔，卖了之后才能买，要求O(n) ， 两边dp	***  
Best Time to Buy and Sell Stock II	知道股票每日价格，可以交易任意笔，要求O(n)，只需要查找一遍  
Best Time to Buy and Sell Stock		知道股票每日价格，只能交易一笔，要求O(n)简单DP  
Binary Tree Inorder Traversal		简单遍历二叉树  
Binary Tree Level Order Traversal II	简单遍历二叉树  
Binary Tree Level Order Traversal	简单遍历二叉树  
Binary Tree Maximum Path Sum		简单树形DP，权值只和最大的一段路径	特别要注意负数	***  
Binary Tree Zigzag Level Order Traversal	简单遍历二叉树	  
Climbing Stairs		Fibonacci  
Combination Sum II	递归  
Combination Sum		同上  
Combinations		同上  
Construct Binary Tree from Inorder and Postorder Traversal	知道中序和后序，构建树，要注意内存	***  
Construct Binary Tree from Preorder and Inorder Traversal	知道前序和中序，构件树，同上  
Container With Most Water	很赞的一题，从n^2,到nlogn到n		***  
Convert Sorted Array to Binary Search Tree	简单递归  
Convert Sorted List to Binary Search Tree	简单递归，比上题略难	***  
Count and Say			简单模拟  
Decode Ways			简单DP	  
Distinct Subsequences		简单DP  
Divide Two Integers		模拟除法，不用*/% 要注意符号，溢出等边界，转为负数	***  
Edit Distance			最短编辑距离，注意边界  
First Missing Positive		O(n)且常数时间，注意数组的多次利用  
Flatten Binary Tree to Linked List	树的结构重建，dfs，好题	***  
Generate Parentheses		简单递归  
Gray Code			格雷码 规律 定义  
Implement strStr()		KMP				***   
Insert Interval			区间合并，要严重注意细节	***  
Integer to Roman		数字翻译成罗马数字  
Interleaving String		看s1和s2能不能合并成s3，不是子串，审清细节题  
Jump Game			简单遍历，注意细节  
Jump Game2			DP				***  
Largest Rectangle in Histogram	经典DP	可以用栈巧妙解决	***   
Length of Last Word		基础题  
Letter Combinations of a Phone Number	简单递归  
Longest Common Prefix		简单题  
Longest Consecutive Sequence	unordered_map			***  
Longest Palindromic Substring	最长回文  
Longest Substring Without Repeating Characters	最长不重复  
Longest Valid Parentheses	最长合法括号数，注意边界	***  
Maximal Rectangle		同Largest Rectangle in Histogram ***  
Maximum Depth of Binary Tree	树的最长深度  
Maximum Subarray		最大子序列  
Merge Intervals			合并区间  
Merge Sorted Array		合并两个有序数组，不用第三个数组  
Merge Two Sorted Lists		合并两个有序链表，不用申请内存  
Minimum Depth of Binary Tree	树的最小深度，注意定义  
Minimum Path Sum		简单二维DP  
Minimum Window Substring	二分+统计  
Multiply Strings		大数乘法  
Next Permutation		下一个组合数，要求O(n)并如二分一般不	用思考就可以闭着眼睛写出来 ***  
N-Queens II			N皇后问题，用位运算快速解决  
N-Queens			N皇后问题，输出方案  
Palindrome Number		回文数字  
Palindrome Partitioning		回文串+递归  
Palindrome Partitioning II	回文串+递归  
Partition List			指针操作，一定要注意细节  
Path Sum			树的路径和  
Path Sum II			树的路径和 输出  
Permutation Sequence		第K个组合数  
Permutations II			组合数，用重复数字  
Permutations			组合数  
Plus One			模拟加法  
Populating Next Right Pointers in Each Node II	二叉树的邻居指针 很nice的题目			***  
Populating Next Right Pointers in Each Node	完全二叉树的邻居指针  
Recover Binary Search Tree		树中两个元素错位，要求修复并用O(1)的空间，前序遍历记录上一个节点 ***  
Remove Duplicates from Sorted Array	对有序数组去重  
Unique Binary Search Trees II		把所有的二叉搜索树构造出并保存起来	 ***  
Valid Number				有限自动机				 ***  
Word Ladder II				记录所有路径				 ***  