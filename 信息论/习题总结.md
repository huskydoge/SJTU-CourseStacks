#信息论 #习题

## Chapter 2： Entropy，Relative Entropy and Mutual Infomation

2.2 X的函数的熵小于等于X的熵

2.5 条件熵等于0当且仅当y是x的函数

2.6 条件互信息和互信息的大小一般是不好比较的。结合马尔可夫链进行举例。

2.7 Hamming Code 一道很妙的构造题，但是太难了

2.8 取球问题：放回还是不放回，某一次取道球的概率是一样的（抽签原理）

2.9 条件熵的链式法则应用，证明不等式
$$H(X|Y)+H(Y|Z)\ge H(X|Y,Z)+H(Y|Z)=H(X,Y|Z)=H(X|Z)+H(Y|X,Z)\ge H(X|Z)$$

2.10 知道$H(\alpha)$是什么就够了

2.14 
1. 相互独立的变量相加会增加熵
2. 用"2.2:X的函数的熵小于等于X的熵", $H(Z)=H(X+Y)\le H(X,Y)$

2.15 马尔可夫链情况下:
$$I(X_{1};X_{2},X_{3},\cdots,X_{n})=I(X_{1};X_{2})$$

2.18 World Series

2.20 Run length coding | 要点是抓住关键的信息，哪些东西就足以表示所有我们想要的信息了呢？

2.21 Markov Inequality for probabilities
$$Pr\{p(X)\le d\}\log \frac{1}{d}\le H(X)$$

2.27 基本运算

2.29 不等式。主要还是掌握链式法则。

2.32 Fano不等式的强化 [[知识点大纲#^3c06b2|Fano]]

2.40 Discrete Entropy
$$H(X+Y,X-Y)=H(X,Y)$$

## Chapter 3：The Asymptotic Equipartition Property

3.1 Markov Inequality && Chebyshev's inequality

3.3 Piece of Cake
$$\frac{1}{n}\log T_{n}=\frac{1}{n} \prod_{1}^n\log C_{i}=E(C_{1})$$
>$\frac{1}{n}\log T_{n}$ 就是所谓指数的一阶，取对数然后除以一阶变量n

3.13 典型集的定义


## Chapter 4：Entropy Rates of a Stochastic Process

4.1 Doubly stochastic matrices
Markov 过渡矩阵的行加起来是1.

4.3 Shuffles increase entropy
Shuffle是可逆的！

4.6 
$$H(X_{n}|X_{n-1},\cdots,X_{1})\le \frac{H(X_{1},X_{2},\cdots,X_{n})}{n}\le \frac{H(X_{1},X_{2},\cdots,X_{n-1})}{n-1}$$
由Stationary的条件，
$$H(X_{n}|X_{n-1},\cdots,X_{1})\le H(X_{i}|X_{i-1},\cdots,X_{1})$$

4.10  Pairwise Independence 
n个变量相互独立，无法推出完全独立！$H(X_{i},X_{j})=H(X_{i})+H(X_{j})$不意味着$H(X_{1},X_{2},\cdots,X_{n})$可以拆分成n项！

4.12 狗狗游走问题

4.20 Random Walk on Chessboard

4.33/4.34 不等式
data processing inequality要记住了！


## Chapter 5：Data Compression

5.9 Optimal code lengths that require one bit above entropy
binary random variable，X=1的概率接近1，H（X）=0，但是需要1位

5.13  利用code length和熵的大小关系

5.16  2、3、4进制的Huffman Code

5.28  Shannon Code
Shannon Code 的构造方法要掌握

5.32 Bad Wine

主要是要画出Huffman Tree

## Chapter 7：Channel Capacity

7.5 using two channels at once. 同时使用两个信道，要与后面两个信道变为1个信道作区分！

7.8 The Z channel

7.10 Zero-error capacity

7.13 Erasures and errors in a binary channel

7.14 Channels with dependence between the letters

7.32 Random "20" questions

7.34/7.35 Capacity
* BSC
* TSC
* Parallel

## Chapter 8：Differential Entropy
8.1 常见的Differential Entropy

## Chapter 9：Gaussian

9.4 Exponential Noise Channel
![exponentional.jpeg](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/exponentional.jpeg)
