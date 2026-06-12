# multiset 与平衡二叉搜索树（BST）

## 1. 为什么需要 multiset

很多题目需要维护一个动态集合，并支持：

* 插入元素
* 删除元素
* 查找元素
* 查询第一个 ≥ x 的元素
* 查询第一个 > x 的元素
* 查询 ≤ x 的最大元素（前驱）
* 查询 ≥ x 的最小元素（后继）

例如 CSES Concert Tickets：

```text
票价：3 5 5 8
预算：6
```

需要找到：

```text
<=6 的最大票价
```

答案为：

```text
5
```

并将其删除。

---

## 2. 为什么不用数组

若使用有序数组：

```cpp
vector<int>
```

查找：

```cpp
lower_bound(...)
upper_bound(...)
```

复杂度：

$$
O(\log n)
$$

但删除元素需要移动后续元素：

$$
O(n)
$$

因此无法支持大量动态操作。

---

## 3. 二叉搜索树（BST）

BST 满足：

```text
左子树 < 当前节点 < 右子树
```

例如：

```text
        8
      /   \
     4     12
    / \   /  \
   2  6 10 14
```

查找 10：

```text
8 → 12 → 10
```

只沿一条路径向下。

复杂度：

$$
O(h)
$$

其中：

$$
h=\text{树高}
$$

---

## 4. 为什么需要平衡

若依次插入：

```text
1 2 3 4 5
```

BST 退化为：

```text
1
 \
  2
   \
    3
     \
      4
```

此时：

$$
h=n
$$

所有操作退化为：

$$
O(n)
$$

因此需要平衡 BST。

---

## 5. 平衡 BST

典型结构：

```text
        4
      /   \
     2     6
    / \   / \
   1  3 5  7
```

高度满足：

$$
h=O(\log n)
$$

因此：

| 操作     | 复杂度      |
| ------ | -------- |
| insert | O(log n) |
| erase  | O(log n) |
| find   | O(log n) |

STL 中：

```cpp
set
multiset
map
multimap
```

通常由红黑树实现。

---

## 6. 为什么 lower_bound 是 O(log n)

目标：

```cpp
s.lower_bound(x)
```

返回：

```text
第一个 >= x 的元素
```

例如：

```text
        8
      /   \
     4     12
    / \   /  \
   2  6 10 14
```

求：

```text
lower_bound(7)
```

搜索过程：

```text
8 >= 7
候选答案 = 8
向左走

4 < 7
向右走

6 < 7
向右走
```

结束。

答案：

```text
8
```

整个过程中：

* 每层最多访问一个节点
* 只走一条根到叶子的路径

访问节点数：

$$
O(h)
$$

平衡树高度：

$$
h=O(\log n)
$$

因此：

$$
lower_bound = O(\log n)
$$

---

## 7. 为什么 upper_bound 是 O(log n)

目标：

```cpp
s.upper_bound(x)
```

返回：

```text
第一个 > x 的元素
```

搜索逻辑与 lower_bound 完全相同：

* 当前节点 > x，记录答案，向左搜索更小候选
* 当前节点 ≤ x，向右搜索

仍然只沿一条路径向下。

因此：

$$
upper_bound = O(\log n)
$$

---

## 8. set 与 multiset

### set

元素唯一：

```cpp
set<int> s;
```

```text
5 5 5
```

实际只保存：

```text
5
```

---

### multiset

允许重复：

```cpp
multiset<int> s;
```

```text
5 5 5
```

实际保存：

```text
5 5 5
```

Concert Tickets 必须使用：

```cpp
multiset
```

因为票价可能重复。

---

## 9. 常用操作

### 最小值

```cpp
*s.begin()
```

---

### 最大值

```cpp
*prev(s.end())
```

---

### 第一个 ≥ x

```cpp
s.lower_bound(x)
```

---

### 第一个 > x

```cpp
s.upper_bound(x)
```

---

### 删除一个元素

```cpp
s.erase(it)
```

复杂度：

$$
O(\log n)
$$

注意：

```cpp
s.erase(value)
```

会删除所有 value。

---

## 10. 查询 ≤ x 的最大元素（前驱）

竞赛最常见操作。

利用：

```cpp
auto it = s.upper_bound(x);
```

得到：

```text
第一个 > x 的元素
```

前驱就是：

```cpp
--it;
```

因此：

```cpp
auto it = s.upper_bound(x);

if(it == s.begin()){
    // 不存在 <= x 的元素
}
else{
    --it;
    // *it 即最大的 <= x 的元素
}
```

复杂度：

$$
O(\log n)
$$

---

## 11. Concert Tickets 模板

```cpp
auto it = tickets.upper_bound(x);

if(it == tickets.begin()){
    cout << -1 << '\n';
}
else{
    --it;
    cout << *it << '\n';
    tickets.erase(it);
}
```

---

## 一句话总结

`multiset` 本质上是一棵平衡二叉搜索树（通常为红黑树）。由于树高始终保持在

$$
O(\log n)
$$

因此插入、删除、查找、lower_bound、upper_bound、前驱和后继查询都能在

$$
O(\log n)
$$

时间内完成。
