单调队列，即单调递减或单调递增的队列。常用来解决RMQ（Range Maximum/Minimum Query），即用于求某个区间内的最大值或最小值。
对于这类问题，线段树或者稀疏表也搞得定，但是O(log(n))级的，没有单调队列快。

单调队列详细原理见 [KSKUN'S BLOG|单调队列原理及其应用](https://ksmeow.moe/monotonic_queue/)
