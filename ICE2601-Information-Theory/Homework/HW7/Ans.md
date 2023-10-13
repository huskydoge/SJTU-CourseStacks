## 7.32 Random 20 questions

### a)

 $X$ contains $\log_2 m=n$ bits information. Thus we at least need $n$ deterministic questions to determine $X$. To reach the limit, we first ask the question "is $X\in$ {$1,2,\cdots,m/2$}? "

1. If the answer is "Yes", then ask "is $X\in$ {$1,2,\cdots,m/2^2$}? "
2. otherwise, then ask "is $X\in$ {$m/2+1,2,\cdots,m$}? "

Keep repeat the procedure on the new set we get, since $m < \infty$ , after a finite steps this procedure will terminate with the conclusion $X \in$ { $i$ }, which means $X = i,i \in $ {$1,2,3,\cdots, m$}

### b)

We continue perceive the problem in the perspective of a $\log_2m=n$ bits code. If two object share the same answers for k questions, then it simply means two objects share $k$ bits prefix in common. Then we know the probability is:
$$
p=\frac{1}{2^k} 
$$

### c)

$$
E= \sum_{j=2}^{m}2^{-k}=(m-1)2^{-k}=(2^n-1)2^{-k}
$$

### d)

Assume the correct object is object 1. To calculate the number of those having the same answers with object 1, by  appying the conclusion in (c),  we know the answer is :
$$
(2^n-1)2^{-n-\sqrt{n}}
$$

### e)

We denote the number of wrong objects as $N$. By markov inequality, we have:
$$
p(N \ge 1) \le (2^n-1)2^{-n-\sqrt{n}} <(2^n)2^{-n-\sqrt{n}} = \frac{1}{2^{\sqrt{n}}}
$$
As $n\rightarrow \infty$,  $p(N \ge 1)  \rightarrow 0$.

## 7.34 Capacity

### a)

By the conclusion in `7.13`, we know that for a single BSC, its capacity is $C=1-H(p)$

From the conclusion in `7.28`  we know that for such parallel BSC, we have:
$$
2^C=2^{C_1}+2^{C_2}=2^{2-H(p)}
$$
Thus $C=2-H(p)$.

### b)

In this case, $C_1=1-H(p)$ and $C_2=0$, thus
$$
2^C=2^{C_1}+2^{C_2}=2^{1-H(p)}+1
$$
We have $C=\log_2(2^{1-H(p)}+1)$

### c)

For a ternary channel, we have $C_1=\max I(X;Y)=\max( H(Y)-H(Y|X))=\log_23-H(1/2)=\log_23-1$ bits.

The capcity of BSC is $C_2=1-H(1/2)=0$.

Thus $C=\log_2(2^{\log_23-1}+1)=\log_2 \frac{5}{2}$ bits.

### d)

$C=\max I(X;Y)=\max( H(Y)-H(Y|X))=\log_23-H(1/3,2/3)=\frac{2}{3} bits$

## 7.35 Capacity

### a)

This is equal to the case with two parallel channel, with joint capacity $C'$ Satisfying: 
$$
2^{C'}=2^{C_1}+2^{C_2}=2^C+1
$$
 $C'=\log_2 (2^C+1)$

### b)

We could deem this as $k+1$ parallel channel. And when we compute the capacity, we first compute the capacity of first two channel, which is  $C'_1=C'=\log_2 (2^C+1)$ as we have figured out in (a). Then deem $C'_1=C'$ as the capacity of a new channel, and continually adding another parallel channel, to get the new capacity $C'_2$. 

Actually, we have the recursion formula：
$$
C'_{k+1}=\log_2(2^{C'_k}+1)
$$
We have $C_k'=\log_2(k-1+2^{C_1'})=\log_2(k-1+2^{C}+1)=\log_2(k+2^{C})$

## 8.1 Differential entropy

### a)

WLOG, we only consider the case where $\lambda > 0$, 
$$
h(X)=-\int_0^{+\infty}f(x)\ln(f(x))dx=\int_0^{+\infty}\lambda^2 xe^{-\lambda x}dx-\ln(\lambda)\int_0^{+\infty}e^{-x}dx= \ln\frac{e}{\lambda} \text{ bits}
$$

### b)

Since Laplace density function is an even function, we have:
$$
\begin{aligned}
h(X) &= 2(-\frac{1}{2}\int_0^{+\infty} \lambda e^{-\lambda x}\ln\lambda e^{-\lambda x} dx+\frac{\ln2}{2}\int_0^{+\infty} \lambda e^{-\lambda x}dx)\\
&= \ln \frac{e}{\lambda}+\ln 2 \\
&= \ln \frac{2e}{\lambda} \text{ bits}
\end{aligned}
$$

### c)

Given the fact that the sum of two normal random variables is also normal, and the condtion that $X_1,X_2$ are independent, then we have
$$
X_1+X_2 \sim \mathcal{N}\left(\mu_1+\mu_2, \sigma_1^2+\sigma_2^2\right)
$$
Thus,
$$
h(f)=\frac{1}{2} \log 2 \pi e\left(\sigma_1^2+\sigma_2^2\right) \text{ bits}
$$

## 9.1 Channel with two independent looks at Y

### a)

Since $Y_1,Y_2$ are conditionally independent and conditionally identical distributed given $X$, then we have:
$$
\begin{aligned}
I(X;Y_1,Y_2) &=H(Y_1,Y_2)-H(Y_1,Y_2|X) \\
&=H(Y_1)+H(Y_2)-I(Y_1;Y_2)-H(Y_1|X)-H(Y_2|X) \\
&=I(X;Y_1)+I(X;Y_2) - I(Y_1;Y_2) \\
& = 2I(X;Y_1)- I(Y_1;Y_2)
\end{aligned}
$$

### b)

By Applying the conclusion in (a), we have:
$$
C_1=\max I(X;Y_1,Y_2) = \max 2I(X;Y_1)- I(Y_1;Y_2) \le 2\max  I(X;Y_1) = 2C_2
$$


## 9.2 Two-look Gaussian channel

To maximize the capacity, obviously we should reach the limit of power constraint, that is $X\sim \mathcal{N}(0,P)$

The capacity of the channel can be calculated as:
$$
\begin{aligned} C & =\max I\left(X ; Y_1, Y_2\right) \\ & =h\left(Y_1, Y_2\right)-h\left(Y_1, Y_2 | X\right) \\ & =h\left(Y_1, Y_2\right)-h\left(Z_1, Z_2 | X\right) \\ & =h\left(Y_1, Y_2\right)-h\left(Z_1, Z_2\right)\end{aligned}
$$
From the distribution matrxi of $(Z_1,Z_2)$, we have:
$$
h\left(Z_1, Z_2\right)=\frac{1}{2} \log [(2 \pi e)^2\left|K\right|]=\frac{1}{2} \log [(2 \pi e)^2 N^2\left(1-\rho^2\right)]
$$
Since $Y_1=X+Z_1,Y_2=X+Z_2$, we have 
$$
\left(Y_1, Y_2\right) \sim \mathcal{N}\left(\mathbf{0},\left[\begin{array}{cc}P+N & P+\rho N \\ P+\rho N & P+N\end{array}\right]\right)
$$
Which means:
$$
h\left(Y_1, Y_2\right)=\frac{1}{2} \log [(2 \pi e)^2\left|K'\right|]=\frac{1}{2} \log [(2 \pi e)^2\left(N^2\left(1-\rho^2\right)+2 P N(1-\rho)\right)]
$$
Then we get:
$$
\begin{aligned} C & =h\left(Y_1, Y_2\right)-h\left(Z_1, Z_2\right) \\ & =\frac{1}{2} \log \left(1+\frac{2 P}{N(1+\rho)}\right)\end{aligned}
$$
*    $\rho=1,$ $C=\frac{1}{2} \log \left(1+\frac{P}{N}\right)$
*    $\rho=0,$ $C=\frac{1}{2} \log \left(1+\frac{2 P}{N}\right)$
*    $\rho=-1,$ $C=+\infty$

## 9.4 Exponential noise channels

$$
\begin{aligned} C & =\max _{f(X): E X \leq \lambda} I(X ; Y) \\ & =\max _{f(X): E X \leq \lambda} h(Y)-h(Y | X) \\ & =\max _{f(X): E X \leq \lambda} h(Y)-h(Z | X) \\ & =\max _{f(X): E X \leq \lambda} h(Y)-h(Z) \\ & =\max _{f(X): E X \leq \lambda} h(Y)-(1+\ln \mu) \text{ ,   using conclusion in 8.1} \end{aligned}
$$

$Y=X+Z$, $E(Y)=E(X)+E(Y)\le \mu + \lambda$

When the mean value is constrained, according to the maximum entropy in lecture 7, we know that the maximum entropy is reached when the distribution is exponentional distribution, with maximum entropy:
$$
\max _{f(X): E X \leq \lambda} h(Y)=\ln e(\mu+\lambda) = 1+\ln (\mu+\lambda)
$$

$$
\begin{aligned}
C&=\max _{f(X): E X \leq \lambda} h(Y)-(1+\ln \mu) \\
&=\ln (1+\frac{\lambda}{\mu}) \text{ bits}

\end{aligned}
$$

To prove this capacity can be realized, we render a possible example learned from teacher:

<img src="../../../../Library/Containers/com.tencent.xinWeChat/Data/Library/Application%20Support/com.tencent.xinWeChat/2.0b4.0.9/7fca2ed932d7e78df673844b9f659e86/Message/MessageTemp/9e20f478899dc29eb19741386f9343c8/Image/501680608598_.pic.jpg" alt="501680608598_.pic" style="zoom:33%;" />

<img src="../../../../Library/Application%20Support/typora-user-images/%E6%88%AA%E5%B1%8F2023-04-04%2019.45.41.png" alt="截屏2023-04-04 19.45.41" style="zoom:33%;" />
