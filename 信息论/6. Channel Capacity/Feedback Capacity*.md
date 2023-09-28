#信息论 
> Not required by exam

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230425210305.png)


We assume that all the received symbols are sent back immediately and noiselessly to the transmitter, which can then use them to decide which symbol to send next 

We define a $\left(2^{n R}, n\right)$ feedback code as a sequence of mappings $x_i\left(W, Y^{i-1}\right)$, where each $x_i$ is a function only of the message $W \in 2^{n R}$ and the previous received values, $Y_1, Y_2, \ldots, Y_{i-1}$, and a sequence of decoding functions $g: y^n \rightarrow\left\{1,2, \ldots, 2^{n R}\right\}$. Thus,
$$
P_e^{(n)}=\operatorname{Pr}\left(g\left(Y^n\right) \neq W\right)
$$
when $W$ is uniformly distributed over $\left\{1,2, \ldots, 2^{n R}\right\}$.

>Feedback capacity
$$
C_{F B} = C = \max _{p(x)}(X ; Y)
$$


## Feedback won't increase capacity!

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230425210442.png)
