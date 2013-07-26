
<table border="1">
<tr>
<td width = "300">3Sum Closest</td>		
<td>O(n^2) 求三个数字之和最接近target的数字,排序后循环一层,接下去两端向中间靠拢</td>
<td>80ms</td>
</tr>
<tr>
<td>3Sum</td>				
<td>O(n^2) 求3个数字之和为0的组合,同上,注意去重</td> 
<td>250ms</td>
</tr>
<tr>
<td rowspan="2"><b>4Sum</b></td>
<td>O(n^3) 求4个数字之和为0的组合,同3Sum,第三层循环两端向中间靠拢</td>
<td>250ms</td>
</tr>
<tr>
<td>O(n^2log(n))+大常数 将原数组两两相加组成一个二元组(num[i]+num[j],i,j),接着对原数组两层for循环并对二元组二分取值,用下标保证不重复</td>
<td>1100ms</td>
</tr>
<tr>
<td>Add Binary</td>
<td>模拟二进制加法,一个for循环</td>
<td>20ms</td>
</tr>
<tr>
<td>Add Two Numbers</td>
<td>链表加法,同上,一个for循环</td>
<td>200ms</td>
</tr>
<tr>
<td>Anagrams</td>
<td>选取strs中由相同字符构成的串,用map<\string,vector<\string> >解决,排序后的str做key,然后把原值塞进vector中</td>
<td>250ms</td>
</tr>
<tr>
<td>Balanced Binary Tree</td>
<td>检查是否是二叉平衡树,任意节点的左右子树高度差不超过1,递归解决</td>
<td>68ms</td>
</tr>
<tr>
<td><b>Best Time to Buy and Sell Stock III</b></td>
<td>O(n) 知道股票每日价格,只能交易两笔,卖了之后才能买,两边DP</td>
<td>60ms</td>
</tr>
<tr>
<td>Best Time to Buy and Sell Stock II</td>
<td>O(n) 知道股票每日价格,可以交易任意笔,差值求和</td>
<td>48ms</td>
</tr>
<tr>
<td>Best Time to Buy and Sell Stock </td>
<td>O(n) 知道股票每日价格,只能交易一笔,记录最小值</td>
<td>56ms</td>
</tr>
<tr>
<td>Binary Tree Inorder Traversal</td>
<td>in-order遍历二叉树</td>
<td>12ms</td>
</tr>
<tr>
<td>Binary Tree Level Order Traversal II</td>
<td>简单遍历二叉树,从叶子到根的顺序装进vector</td>
<td>132ms</td>
</tr>
<tr>
<td>Binary Tree Level Order Traversal</td>
<td>简单遍历二叉树,从根到叶子的顺序装进vector</td>
<td>24ms</td>
</tr>
<tr>
<td><b>Binary Tree Maximum Patd Sum</b></td>
<td>简单树形DP，权值之和最大的一段路径	特别要注意负数</td>
<td>152ms</td>
</tr>
<tr>
<td>Binary Tree Zigzag Level Order Traversal</td>
<td>简单遍历二叉树,从根到叶子,奇数层从左到右,偶数层从右到左</td>
<td>28ms</td>
</tr>
<tr>
<td>Climbing Stairs</td>
<td>Fibonacci</td>
<td>12ms</td>
</tr>
<tr>
<td>Combination Sum II</td>
<td>简单递归,从数组C中找一些数字组使这些数字和为T,一个数字用一次,且答案不能重复</td>
<td>60ms</td>
</tr>
<tr>
<td>Combination Sum</td>
<td>简单递归,从数组C中找一些数字组使这些数字和为T,一个数字用任意次</td>
<td>60ms</td>
</tr>
<tr>
<td>Combinations</td>
<td>简单递归,列出所有k个数字(1-n)的组合</td>
<td>56ms</td>
</tr>
<tr>
<td>Construct Binary Tree from Inorder and Postorder Traversal</td>
<td>知道中序和后序，构建树，要注意内存</td>
<td>168ms</td>
</tr>
<tr>
<td>Construct Binary Tree from Preorder and Inorder Traversal</td>
<td>知道中序和前序，构建树，要注意内存</td>
<td>176ms</td>
</tr>
<tr>
<td><b>Container With Most Water</b></td>
<td>一排直线,找两条线使得能装下的水最多</td>
<td>100ms</td>
</tr>
<tr>
<td>Convert Sorted Array to Binary Search Tree</td>
<td>以排好序的数组生成BST,找到中间节点,用preorder生成</td>
<td>92ms</td>
</tr>
<tr>
<td><b>Convert Sorted List to Binary Search Tree</b></td>
<td>已排好序的链表生成BST,先得到长度,然后用inorder来生成</td>
<td>164ms</td>
</tr>
<tr>
<td><b>Count and Say</b></td>
<td>简单模拟 1->11->21->1211->... </td>
<td>20ms</td>
</tr>
<tr>
<td>Decode Ways</td>
<td>简单DP O(n) 把字符串分段使得每一段都是1-26的方法数</td>
<td>16ms</td>
</tr>
<tr>
<td>Distinct Subsequences</td>
<td>简单DP O(n*m) 有多少个S的子串包含T 注意边界</td>
<td>72ms</td>
</tr>
<tr>
<td><b>Divide Two Integers</b></td>
<td>模拟除法,用位运算,注意边界,int转正数会溢出,转成负数做</td>
<td>64ms</td>
</tr>
<tr>
<td><b>Edit Distance</b></td>
<td>O(n*m) 最短编辑距离 注意边界</td>
<td>140ms</td>
</tr>
<tr>
<td><b>First Missing Positive<b/></td>
<td>找到最小不存在的正整数,O(1)空间</td>
<td>20ms</td>
</tr>
<tr>
<td><b>Flatten Binary Tree to Linked List</b></td>
<td>将二叉树重构,只有右儿子</td>
<td>52ms</td>
</tr>
<tr>
<td>Generate Parentheses</td>
<td>简单递归 生成匹配的括号</td>
<td>12ms</td>
</tr>
<tr>
<td><b>Gray Code</b></td>
<td>格雷码 公式i^(i>>1)</td>
<td>36ms</td>
</tr>
<tr>
<td><b>Implement strStr()</b></td>
<td>KMP</td>
<td>28ms</td>
</tr>
<tr>
<td><b>Insert Interval</b></td>
<td>一个区间和一组有序区间合并</td>
<td>72ms</td>
</tr>
<tr>
<td>Integer to Roman</td>
<td>数字翻译成罗马数字</td>
<td>128ms</td>
</tr>
<tr>
<td>Interleaving String</td>
<td>看s1和s2能不能合并成s3</td>
<td>16ms</td>
</tr>
<tr>
<td><b>Jump Game II</b></td>
<td>每个位子可以跳到val远处,问起点到终点的最小步数</td>
<td>52ms</td>
</tr>
<tr>
<td>Jump Game</td>
<td>每个位子可以跳到val远处,问起点能不能跳到终点</td>
<td>52ms</td>
</tr>
<tr>
<td rowspan="2"><b>Largest Rectangle in Histogram</b></td>
<td>经典问题,最大矩形 left+right</td>
<td>100ms</td>
</tr>
<tr>
<td>用一个递增栈来做</td>
<td>100ms</td>
</tr>
<tr>
<td><b>Length of Last Word</b></td>
<td>最后一个词的长度 优美解法</td>
<td>32ms</td>
</tr>
<tr>
<td>Letter Combinations of a Phone Number</td>
<td>递归 手机号码和字符的组合数</td>
<td>12ms</td>
</tr>
<tr>
<td>Longest Common Prefix</td>
<td>一组字符串的最长相同前缀</td>
<td>24ms</td>
</tr>
<tr>
<td><b>Longest Consecutive Sequence</b></td>
<td>乱序数组中最长的连续数字 用unordered_set O(n)</td>
<td>64ms</td>
</tr>
<tr>
<td><b>Longest Palindromic Substring</b></td>
<td>最长回文 O(n)</td>
<td>40ms</td>
</tr>
<tr>
<td>Longest Substring Without Repeating Characters</td>
<td>字符串中最长不重复的字符 纯O(n) 两种做法,比较优美</td>
<td>50ms</td>
</tr>
<tr>
<td><b>Longest Valid Parentheses</b></td>
<td>最长合法圆括号数</td>
<td>40ms</td>
</tr>
<tr>
<td>Maximal Rectangle</td>
<td>二维的Largest Rectangle in Histogram</td>
<td>72ms</td>
</tr>
<tr>
<td>Maximum Depth of Binary Tree</td>
<td>树的最长深度</td>
<td>44ms</td>
</tr>
<tr>
<td>Maximum Subarray</td>
<td>最大子序列</td>
<td>44ms</td>
</tr>
<tr>
<td><b>Median of Two Sorted Arrays</b></td>
<td>两个排序数组的中位数</td>
<td>192ms</td>
</tr>
<tr>
<td><b>Merge Intervals</b></td>
<td>合并区间 O(nlogn)</td>
<td>88ms</td>
</tr>
<tr>
<td><b>Merge k Sorted Lists</b></td>
<td>合并k个有序链表 O(nlogm) 注意写比较器</td>
<td>84ms</td>
</tr>
<tr>
<td>Merge Sorted Array</td>
<td>将有序数组A,B合并到A中,O(1)内存,倒序</td>
<td>32ms</td>
</tr>
<tr>
<td>Merge Two Sorted Lists</td>
<td>合并两个有序链表,新链表要用原链表拼接</td>
<td>60ms</td>
</tr>
<tr>
<td>Minimum Depth of Binary Tree</td>
<td>根节点到最近的叶子节点的距离</td>
<td>52ms</td>
</tr>
<tr>
<td>Minimum Path Sum</td>
<td>从左上角向下向右走到右下角的最短距离 简单二维DP</td>
<td>76ms</td>
</tr>
<tr>
<td><b>Minimum Window Substring</b></td>
<td>从S中找到包含T所有字符的最小子串 , O(n)</td>
<td>60ms</td>
</tr>
<tr>
<td>Multiply Strings</td>
<td>大数乘法</td>
<td>36ms</td>
</tr>
<tr>
<td></td>
<td></td>
<td></td>
</tr>
</table>
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