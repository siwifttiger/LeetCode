>思路：经典问题了，定义两个指针，其中一个先移动n位，再定义一个dummy伪节点，另一个节点从伪节点开始和前一个同时遍历，前一个到链表尾部时，这一个正好到倒数第n+1个节点，可以直接开始删除了。 
 
[19.删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)