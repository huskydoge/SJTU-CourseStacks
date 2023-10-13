#信息论

# 知识
>[!important] Notation
><mark style="background: #FF5582A6;">红色</mark> ｜指明要求掌握
>
> <mark style="background: #BBFABBA6;">绿色</mark> ｜了解即可
> 
> <mark style="background: #ADCCFFA6;">蓝色</mark>  ｜需要知道结论
## 记号优先级
互信息之间的是分号，表示两个关系是相对应的；熵是逗号，表示两个变量平等
> 优先级：逗号 > 分号 > 条件


逗号的优先级比分号高，$I(X,Y;Z)= I((X,Y);Z)$
分号优先级高于条件”｜“，$I(Y ; Z|X) = I((Y ; Z) | X)$

## Convexity of Functions
* $\log\mid K\mid$ : Concave

*  $\log\frac{|K_{n}|}{|K_{n-p}|}$ : Concave in $K_{n}$

*  $\log\frac{|K_{n}|}{|K_{n-1}|}$ : Concave in $K_{n}$ ^104e1c

## 2. Entropy
[[1. Entropy]]
[[Joint Entropy]]
[[Conditional Entropy]]
[[Mutual Information]]


### Fano's Inequality

^3c06b2

>$X\longrightarrow Y \longrightarrow \hat{X}$
$$H(P_{e})+P_{e}\log \mid\mathcal{X} \mid\ge H(X|\hat{X})\ge H(X|Y)$$

如果$\hat{X}\in \mathcal{X}$, 可以强化为：
$$H(P_{e})+P_{e}\log (\mid\mathcal{X} \mid-1)\ge H(X|\hat{X})\ge H(X|Y)$$

## 4. Entropy Rate
对于一个stationary stochastic过程，entropy rate有两种表达形式
## 7. Differential Entropy
### Differential and Discrete Entropy
### AEP For Continuous Random Variable
### Conditional Differential Entropy
### Covariance Matrix
#### Covariance
#### Correlation
### Mulivariate Normal Distribution
<mark style="background: #ADCCFFA6;">掌握结论</mark>

一般情况下，多元分布的分量无关不意味着独立，但是如果是正态多元分布，那么就是独立的。
>In general, random variables may be uncorrelated but statistically dependent. But if a random vector has a multivariate normal distribution then any two or more of its components that are uncorrelated are independent. This implies that any two or more of its components **that are pairwise independent are independent**.
> But, it is not true that two random variables that are (separately, marginally) normally distributed and uncorrelated are independent
* a **pairwise independent** collection of random variables is a set of random variables any two of which are independent.
* **mutual independence (or collective independence)** of events means, informally speaking, that each event is independent of any combination of other events in the collection. 


https://en.wikipedia.org/wiki/Multivariate_normal_distribution
>[!Warning!] 注意
>[两个变量是正态分布而且无关，不意味着他们独立](https://en.wikipedia.org/wiki/Normally_distributed_and_uncorrelated_does_not_imply_independent)
#### Entropy of Mulivariate Normal Distribution

### Relative Entropy

### Correlated Gaussian

### Maximum Entropy With Constraints
<mark style="background: #FF5582A6;">要求掌握
</mark>

### Maximum Entropy
<mark style="background: #ADCCFFA6;">掌握结论</mark>

### Hadmard‘s Inequality
<mark style="background: #ADCCFFA6;">知道是用高斯分布处理的就行</mark>

### Balanced Information Inequality
<mark style="background: #ADCCFFA6;">结论可以直接用</mark>


### Han's Inequality
<mark style="background: #ADCCFFA6;">知道有这个不等式</mark>｜<mark style="background: #FF5582A6;">掌握低维证明</mark>
Let $\left(X_1, X_2, \ldots, X_n\right)$ have a density, and for every $S \subseteq\{1,2, \ldots, n\}$, denoted by $X(S)$ the subset $\left\{X_i: i \in S\right\}$. Let
$$
\begin{gathered}
h_k^{(n)}=\frac{1}{\left(\begin{array}{l}
n \\
k
\end{array}\right)} \sum_{S:|S|=k} \frac{h(X(S))}{k} \\
g_k^{(n)}=\frac{1}{\left(\begin{array}{l}
n \\
k
\end{array}\right)} \sum_{S:|S|=k} \frac{h\left(X(S) \mid X\left(S^c\right)\right)}{k}
\end{gathered}
$$
When $n=3$,
$$
\begin{gathered}
h_1^{(3)}=\frac{H\left(X_1\right)+H\left(X_2\right)+H\left(X_3\right)}{3} \geq h_2^{(3)}=\frac{H\left(X_1, X_2\right)+H\left(X_2, X_3\right)+H\left(X_3, X_1\right)}{6} \\
\geq h_3^{(3)}=H\left(X_1, X_2, X_3\right) / 3 \\
g_1^{(3)}=\frac{H\left(X_1 \mid X_2, X_3\right)+H\left(X_2 \mid X_1, X_3\right)+H\left(X_3 \mid X_1, X_2\right)}{3} \\
\leq g_2^{(3)}=\frac{H\left(X_1, X_2 \mid X_3\right)+H\left(X_2, X_3 \mid X_1\right)+H\left(X_3, X_1 \mid X_2\right)}{6} \\
\leq g_3^{(3)}=H\left(X_1, X_2, X_3\right) / 3
\end{gathered}
$$
Han's inequality:
$$
h_1^{(n)} \geq h_2^{(n)} \ldots \geq h_n^{(n)}=H\left(X_1, X_2, \ldots, X_n\right) / n=g_n^{(n)} \geq \cdots \geq g_2^{(n)} \geq g_1^{(n)}
$$
****
## 8. Gaussian Channel

### Energy Constraint

### Code Construction

### Probability of Error

### Converse

### Worse Additive Noise


