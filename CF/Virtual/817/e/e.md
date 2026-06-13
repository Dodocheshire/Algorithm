
# 📌 二维前缀和（2D Prefix Sum）

## 1. 定义

$$prefix[i][j] = \sum_{x=1}^{i}\sum_{y=1}^{j} a[x][y]$$

含义：左上角 (1,1) 到 (i,j) 的矩形和。

---

## 2. 递推公式

$$prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j]$$

二维前缀和一定要从 1 开始建($i>=1 j>=1$)，并规定:
```cpp
prefix[0][j] = 0
prefix[i][0] = 0
prefix[0][0] = 0
```
```text id="a1"
上 + 左 - 左上 + 自己
例如prefix[1][1] = prefix[0][1] + prefix[1][0] - prefix[0][0] + a[1][1] = a[1][1]
```


---

## 3. 子矩阵查询

$$S = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]$$
- 注意左上角顶点坐标(x1, y1) >= (1, 1)

记忆：

```text id="a2"
大 - 上 - 左 + 左上
```

---

## 4. 复杂度

| 操作   | 复杂度   |
| ---- | ----- |
| 预处理  | O(nm) |
| 单次查询 | O(1)  |
| q次查询 | O(q)  |

---

## 5. 一句话

```text id="a3"
二维前缀和 = 用 O(nm) 预处理，把子矩阵和变成 O(1) 查询
```

