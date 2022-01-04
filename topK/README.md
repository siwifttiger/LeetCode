topK问题即是在一堆数据中找出最小/最大的K个数。这种问题一般有以下几种解法：排序、堆、类快排划分、

## 排序

直接对数据排序，返回前k个数据。时间复杂度$O(nlgn)$, 空间复杂度$O(lgn)$。

C++ `sort()` 函数原型如下：

```c++
void sort (RandomAccessIterator first, RandomAccessIterator last);
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

第一种形式默认使用操作符`<`进行比较。`sort()` 默认按从小到大排序。若要自定义排序，可以重定义排序对象的`<`操作符，也可以传入指定的comp函数。

comp函数形参应为`(const classA& a, const classA& b)`形式，返回true，则a会排在前，b在后；返回false，则b在前，a在后。

c++ lambad表达式的一般形式：
```c++
[ capture ] ( params ) opt -> ret { body; };
// eg:
[](int a) -> int { return a + 1; };
```
其中capture部分捕获外部变量，可以有以下形式：
- `[]` 不捕获任何变量。
- `[&]` 按引用捕获外部作用域中所有变量。
- `[=]` 按值捕获外部作用域中所有变量。
- [=，&foo] 按值捕获外部作用域中所有变量，按引用捕获 foo 变量。
- [bar] 按值捕获 bar 变量。
- [this] 捕获当前类中的 this 指针，让 lambda 表达式拥有和当前类成员函数同样的访问权限。如果已经使用了 & 或者 =，就默认添加此选项。

### 堆

对于求最小的k个数，可以使用大根堆；反之，可以使用小根堆。时间复杂度$O(nlgk)$, 空间复杂度$O(lgk)$。

```c++
priority_queue<int> maxQ;
for(int i=0; i<input.size(); ++i){
    if (i<k){
        maxQ.push(input[i]);
    }else{
        if (maxQ.top() > input[i]){
            maxQ.pop();
            maxQ.push(input[i]);
        }
    }
}
```

c++ 可以使用priority_queue实现大顶堆/小顶堆：`priority_queue<Type, Container, Functional>`。
Functional默认是less<int>。

```c++
// 小顶堆(top()获取的是最小元素)
priority_queue <int,vector<int>,greater<int>> q;
// 大顶堆(top()获取的是最大元素)
priority_queue <int,vector<int>,less<int>> q;
```

## 类快排划分

快排每次将数组分成两个部分，小于等于分界值 pivot 的元素在数组的左边，其它的在右边。快速排序会根据分界值的下标递归处理划分的两侧，而这里我们只需要只处理划分的一边。

定义函数`randomized_selected(arr, l, r, k)` 表示划分数组 arr 的 [l,r] 部分，使前 k 小的数在数组的左侧，在函数里我们调用快排的划分函数，假设划分函数返回的下标是 pos（表示分界值 pivot 最终在数组中的位置），即 pivot 是数组中第 pos - l + 1 小的数，那么一共会有三种情况：

如果 pos - l + 1 == k，表示 pivot 就是第 k 小的数，直接返回即可；

如果 pos - l + 1 < k，表示第 k 小的数在 pivot 的右侧，因此递归调用 `randomized_selected(arr, pos + 1, r, k - (pos - l + 1))`；

如果 pos - l + 1 > k，表示第 k 小的数在 pivot 的左侧，递归调用 `randomized_selected(arr, l, pos - 1, k)`。

函数递归入口为 randomized_selected(arr, 0, arr.length - 1, k)。

本方法时间复杂度期望为$O(lgn)$，但最坏情况下为$O(n^2)$；空间复杂度$O(lgn)$。
