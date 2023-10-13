#实变函数 
Cantor集$\mathcal{C}$为集族$\{C_k\}$的可数交。其中$\{C_k\}$满足：
1. $\{C_k\}$为下降的闭集序列
2. $C_k$是$2^k$个不交闭区间的并集，每个区间长度为$\frac{1}{3^k}$

>[!Note] 注意
>Cantor集是闭集，所以是Borel集！

*****
*命题19* Cantor集$C$是闭的测度为零的不可数集
>[!important] 证明
>反证法。假如可数，令$\{c_k\}_{k=1}^{\infty}为\mathcal{C}的一个列举$。定义$F_1$为$C_1$中不包含$c_1$的区间，然后$F_2$是$C_2$中两个区间中不包含$c_2$的那一个，如此得到一个下降的闭集可数族$\{ F_k\}_{k=1}^{\infty}$, 它还具有如下性质：
>1. $F_k \in C_k$
>2. $c_k \notin F_k$
>
>由闭区间套定理知：$\bigcap_{k=1}^{\infty}F_k \neq \emptyset$, 设$x\in \bigcap_{k=1}^{\infty}F_k$, 则$x$必然在$\{c_k\}_{k=1}^{\infty}$这个列举里，显然会与上述性质的第二条矛盾！

>[!Warning] 总结
>Cantor集的存在让我们知道了：
> <mark style="background: #FFF3A3A6;">一个集合的测度为0，它不一定可数</mark>；一个集合可数，那它的测度为零。


习题部分 #todo 