>思路 : 递归合并即可，很容易想到
```
newRoot->left = merge(rRoot->left, lRoot->left);
newRoot->right = merge(rRoot->right, lRoot->right);
```
[原题 617.Merge_Two_Binary_Trees](https://leetcode-cn.com/problems/merge-two-binary-trees/)
