>思路：求两个链表的相交节点。如果能把两个链表长度补成一致后对齐，同时遍历，那两个链表遍历时，一定同时到达相交节点。正是基于这样的思想，让两个链表同时遍历，短的一端一定先到达结尾，长的一端此时的位置距离短链表，恰好是开头两个链表的差值。此时让短链表遍历指针指向长链表头，当长链表到达结尾时，让长链表遍历指针指向短链表头，这样两个指针就能同时到达交点了


[160.相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)