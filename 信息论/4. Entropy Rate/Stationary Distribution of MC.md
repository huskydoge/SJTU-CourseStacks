#马尔可夫链 #信息论 

By the definition of stationary,<mark style="background: #FFF3A3A6;"> a Markov chain is stationary iff $p\left(X_{n+1}\right)=p\left(X_n\right)$ </mark>
- If the probability mass function at time $n$ is $p\left(x_n\right)$, then
$$
p\left(x_{n+1}\right)=\sum_{x_n} p\left(x_n\right) P_{x_n x_{n+1}} \text { or } x^T P=x^T
$$
- If the initial state of a Markov chain is drawn according to a stationary distribution, the Markov chain is stationary

Consider a two-state Markov chain with a probability transition matrix
$$
P=\left[\begin{array}{cc}
1-\alpha & \alpha \\
\beta & 1-\beta
\end{array}\right]
$$

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230424135810.png)
