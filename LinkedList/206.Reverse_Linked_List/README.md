思路：经典问题，应该能默写了。。。
递归的思想很简单，就不介绍了
迭代的思想就是定义3个指针,pre,cur,next，每一次循环完成的事情时先记录next,然后让cur->next指向pre，然后同时向后移动这3个指针，重复上述过程，遍历完链表，链表也就逆序完成了。


[206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)