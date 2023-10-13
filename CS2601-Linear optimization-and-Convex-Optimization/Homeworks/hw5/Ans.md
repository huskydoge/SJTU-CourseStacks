# Homework 5

## Question 1

According to the first-order optimality condition, the solution to the following problem:
$$
\min _{\boldsymbol{x} \in \bar{B}} f(\boldsymbol{x})=\frac{1}{2}\left\|\boldsymbol{x}-\boldsymbol{x}_0\right\|^2
$$
Should satisfy:
$$
2(\boldsymbol{x^*}-\boldsymbol{x}_0)^T\cdot (\boldsymbol{x}-\boldsymbol{x^*}) \ge 0, \forall \boldsymbol{x} \in \bar{B}
$$
Where $\boldsymbol{x^*}$ is the projection of $\boldsymbol{x_0}$ onto $\bar{B}$.

First, we show that $\boldsymbol{x^*} \in \partial B$.  Otherwise, $\exist \epsilon > 0,\exist \boldsymbol{x} \in O(\boldsymbol{x^*},\epsilon),s.t.$ $(\boldsymbol{x}-\boldsymbol{x^*})$ and $(\boldsymbol{x^*}-\boldsymbol{x_0})$ are collinear but reversed, thus contradicting condition (2).

Second, we show that $\boldsymbol{x^*}$ and $\boldsymbol{x_0}$ are collinear. Otherwise, we could make $\boldsymbol{x}$ close enough to $\boldsymbol{x^*}$ to make $(\boldsymbol{x}-\boldsymbol{x^*})$ lie in the direction of the tangent line of $\bar{B}$ at $\boldsymbol{x^*}$, which lead to $2(\boldsymbol{x^*}-\boldsymbol{x}_0)^T\cdot (\boldsymbol{x}-\boldsymbol{x^*}) \le 0$.

Combining the two conclusions above, we derive that $\hat{x_0}=\frac{x_0}{||x_0||}$

## Question 2

### (a).

![PNG图像-754C4DDD21E5-1](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jswg9fj311x0u0afb.jpg)

![截屏2022-11-02 20.43.29](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jqag6xj30r003s0sx.jpg)

Optimal solution: $x_1=0.2,x_2=0.4$

Optimal value: $0.6$

### (b).

![PNG图像-2B2EB37F1463-1](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2k0z1nvj311x0u0aed.jpg)

![截屏2022-11-02 20.44.07](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2k1nz6tj30po044aa2.jpg)No No optimal solution. Or the Optimal is $+\infty$, it's infeasible.

### (c).

![PNG图像-7926FB980729-1](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jyh98vj311x0u00wb.jpg)

![截屏2022-11-02 20.52.49](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2rj4ic5j30u203s74j.jpg)

Optimal solution: $\{(x_1,x_2)|x_1=0,x_2 \ge 1\}$

Optimal value: $0$

### (d).![截屏2022-11-02 13.17.35](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jrzo9mj30tc04gmxf.jpg)

### (e).![截屏2022-11-02 13.16.56](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jvpubbj30vw04iq36.jpg)

## Problem 3

### (a).

$$
\min _{\boldsymbol{x}} & \|\boldsymbol{A} \boldsymbol{x}-\boldsymbol{b}\|_{\infty} \\ 
\text { s.t. } & \|\boldsymbol{x}\|_{\infty} \leq 1
$$

We introduce a new variable $s$:
$$
\min _{x_1,x_2,\cdots ,x_n,s} & s \\
\text { s.t. } & -1 \le x_i \leq 1,i=1,2,3,\cdots n \\
& -s \le \boldsymbol{a_i}^Tx_i - b_i \le s, i = 1,2,3, \cdots,m \\
$$
Here $\boldsymbol{a_i}$ is the $i$-row vector of $\boldsymbol{A}$, $b_i$ is the $i$-component of $\boldsymbol{b}$.

For conciseness, it can be further interpreted as:
$$
\min _{\boldsymbol{x},s} & s \\
\text { s.t. } & -\boldsymbol{1} \le\boldsymbol{x} \leq \boldsymbol{1} \\
& -\boldsymbol{s} \le \boldsymbol{A}\boldsymbol{x}-\boldsymbol{b}\le \boldsymbol{s}\\
$$
Here $\boldsymbol{s}$ means the vector whose components are all $s$.

### (b).

![截屏2022-11-02 20.58.24](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2xcwjplj30om03qglr.jpg)

### (c).

![截屏2022-11-02 20.56.59](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2vwg30tj30ts03eq36.jpg)

## Problem 4

### (a.)

The normal equation is:
$$
\boldsymbol{X}^T \boldsymbol{X} \boldsymbol{w}=\boldsymbol{X}^T \boldsymbol{y}
$$
We use PYTHON Numpy to solve the equation.

We first notice that $\boldsymbol{X}$ is invertible, so we get:
$$
\boldsymbol{w}=(\boldsymbol{X}^T \boldsymbol{X} )^{-1}\boldsymbol{X}^T \boldsymbol{y}
$$
<img src="https://tva1.sinaimg.cn/large/008vxvgGly1h7r2juqlc7j30yc01it8q.jpg" alt="截屏2022-11-02 14.50.10" style="zoom:50%;" />

### (b).

t = 1

![截屏2022-11-02 14.36.53](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jturjjj30zm05cmxm.jpg)

Compared to the result in (a). **<u>the solution isn't the same.</u>**

Here 3 out of 6 components are equal to zero. **<u>Thus it is a sparse solution.</u>**

t = 10![截屏2022-11-02 14.38.49](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jr0vodj313s04a3yt.jpg)

Compared to the result in (a). <u>**the solution is almost the same.**</u>

Here only the last component could be considered zero.

**<u>Thus it isn't a sparse solution.</u>**

### (c).

t = 1

![截屏2022-11-02 14.55.56](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jzbr93j310e03st91.jpg)

Compared to the result in (a). <u>**the solution isn't the same.**</u>

**<u>It has no zero component.</u>**

t = 100

![截屏2022-11-02 14.53.36](https://tva1.sinaimg.cn/large/008vxvgGly1h7r2jzwv9tj313i03sdg5.jpg)

Compared to the result in (a). <u>**the solution is almost the same.**</u>

**<u>It has no zero component.</u>**

### Summary for Problem 4

From the results above, we verify that `Lasso` tends to produce a sparse solution with zero components in the Linear least squares regression problem, compared to `Ridge regression`.
