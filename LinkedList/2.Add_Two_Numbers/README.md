>思路：由于链表本身就是逆序给出的，所以直接遍历相加即可，长度不足的那个链表，后续直接补0相加。唯一要考虑的就是进位的问题，如果相加完成后，carry为1，不要忘记补1.  

[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)