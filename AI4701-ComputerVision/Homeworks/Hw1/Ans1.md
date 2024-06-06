## Problem 1

1.  $f_{x}\frac{X}{Z}+c_x = x$, $f_{y}\frac{Y}{Z}+c_y = y$

2.  $$
    \begin{equation}
    Z\left[\begin{array}{l}
    x \\
    y \\
    1
    \end{array}\right] =
    \left[\begin{array}{l}
    x' \\
    y' \\
    Z
    \end{array}\right]=\left[\begin{array}{llll}
    f_x & & c_x & 0 \\
    & f_y & c_y & 0 \\
    & & 1 & 0
    \end{array}\right]\left[\begin{array}{l}
    X \\
    Y \\
    Z \\
    1
    \end{array}\right]
    \end{equation}
    $$

## Problem 2

根据系数进行匹配可得

$$
H_{p}=\left[\begin{array}{ccc}1 & 0 & 0 \\ 0 & 1 & 0 \\ 4 & 2 & 3\end{array}\right]
$$

$$
\left[\begin{array}{cc}
0.375 & -4.5 \\
0.375 & 7.5
\end{array}\right] = sRK
$$

结合相似、仿射矩阵的形式可知，我们可以设：

$$
sR = \left[\begin{array}{cc}
a & b \\
-b & a
\end{array}\right]
$$

$$
K = \left[\begin{array}{cc}
k_1 & k_2 \\
0 & \frac{1}{k_1}
\end{array}\right]
$$

$$
\left[\begin{array}{cc}
a & b \\
-b & a
\end{array}\right] \left[\begin{array}{cc}
k_1 & k_2 \\
0 & \frac{1}{k_1}
\end{array}\right] = \left[\begin{array}{cc}
0.375 & -4.5 \\
0.375 & 7.5
\end{array}\right]
$$

解上述线性方程，可知：

$$
H_A=\left[\begin{array}{ccc}
\frac{1}{4} & 1 & 0 \\
0 & 4 & 0 \\
0 & 0&1
\end{array}\right]
$$

$$
H_S=\left[\begin{array}{ccc}
\frac{3}{2} & \frac{3}{2} & 2 \\
-\frac{3}{2} & \frac{3}{2} & 4 \\
0 & 0&1
\end{array}\right]=\left[\begin{array}{ccc}
\frac{3\sqrt{2}}{2}cos\frac{\pi}{4} & -\frac{3\sqrt{2}}{2}sin\frac{\pi}{4} & 2 \\
\frac{3\sqrt{2}}{2}sin\frac{\pi}{4} & \frac{3\sqrt{2}}{2}cos\frac{\pi}{4} & 4 \\
0 & 0&1
\end{array}\right]
$$

## Problem 3

1. **仿射变换的表达式或矩阵形式**：

   $$
   \begin{pmatrix}
   x' \\
   y' \\
   1
   \end{pmatrix}
   =
   \begin{pmatrix}
   a & b & t_x \\
   c & d & t_y \\
   0 & 0 & 1
   \end{pmatrix}
   \begin{pmatrix}
   x \\
   y \\
   1
   \end{pmatrix}
   $$

   其中 $(x, y)$ 是原始坐标，$(x', y')$ 是变换后的坐标，$a, b, c, d$ 是线性变换的系数，$t_x, t_y$ 是平移分量。

2. **平行线段长度比的代数形式**：
   假设有两个平行线段 $AB$ 和 $CD$，它们在同一直线上，长度分别为 $L_{AB}$ 和 $L_{CD}$。

   我们假设 $A(x_1, y_1), B(x_2, y_2), C(x_3, y_3), D(x_4, y_4)$，则长度分别为：

   $$
   L_{AB} = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
   $$

   $$
   L_{CD} = \sqrt{(x_4 - x_3)^2 + (y_4 - y_3)^2}
   $$

3. **证明长度比在仿射变换下不变**：
   考虑上述仿射变换，应用于点 $A, B, C, D$，得到变换后的点 $A', B', C', D'$ 的坐标。根据仿射变换的定义，有：

   $$
   \begin{pmatrix}
   x'_i \\
   y'_i \\
   1
   \end{pmatrix}
   =
   \begin{pmatrix}
   a & b & t_x \\
   c & d & t_y \\
   0 & 0 & 1
   \end{pmatrix}
   \begin{pmatrix}
   x_i \\
   y_i \\
   1
   \end{pmatrix}
   $$

   其中 $i$ 代表点 $A, B, C, D$。

   变换后的线段 $A'B'$ 和 $C'D'$ 的长度分别为：

   $$
   L_{A'B'} = \sqrt{(x'_2 - x'_1)^2 + (y'_2 - y'_1)^2}
   $$

   $$
   L_{C'D'} = \sqrt{(x'_4 - x'_3)^2 + (y'_4 - y'_3)^2}
   $$

   将仿射变换的表达式代入上述长度公式中，我们得到：

   $$
   L_{A'B'} = \sqrt{(a(x_2 - x_1) + b(y_2 - y_1))^2 + (c(x_2 - x_1) + d(y_2 - y_1))^2}
   $$

   $$
   L_{C'D'} = \sqrt{(a(x_4 - x_3) + b(y_4 - y_3))^2 + (c(x_4 - x_3) + d(y_4 - y_3))^2}
   $$

注意到 $AB$ 和 $CD$ 是平行的，因此:

Case1: $x_3 = x_4, x_1 = x_2$, 则

$$
\frac{L_{A'B'}}{L_{C'D'}} = \frac{|y_2-y_1|}{|y_4-y_3|} = \frac{L_{AB}}{L_{CD}}
$$

Case2: $\frac{y_3-y_4}{x_3 - x_4} = \frac{y_2 - y_1}{x_2 - x_1} = k$, 则

$$
\frac{L_{A'B'}}{L_{C'D'}} = \frac{\sqrt{(a(x_2 - x_1) + b(y_2 - y_1))^2 + (c(x_2 - x_1) + d(y_2 - y_1))^2}}{\sqrt{(a(x_2 - x_1) + b(y_2 - y_1))^2 + (c(x_2 - x_1) + d(y_2 - y_1))^2}} = \frac{\sqrt{(x_2 - x_1)^2((a+bk)^2+(c+dk)^2)}}{\sqrt{(x_3 - x_4)^2((a+bk)^2+(c+dk)^2)}} = \frac{|x_2-x_1|}{|x_3-x_4|}
$$

$$
\frac{L_{AB}}{L_{CD}} = \frac{\sqrt{(x_2-x_1)^2(1+k^2)}}{\sqrt{(x_3-x_4)^2(1+k^2)}} = \frac{|x_2-x_1|}{|x_3-x_4|} = \frac{L_{A'B'}}{L_{C'D'}}
$$

证毕.
