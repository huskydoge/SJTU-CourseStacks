#抽象代数 
>[!Note] Burnside 引理
有限群G作用在有限集X上，则X在G作用下的不同轨道数 N：
$$N=\frac{1}{|G |}\sum_{g\in G} F(g)$$
其中$F(g)$为g作用到X上的不动点的数目 ^a89f09

>例：$G=Klein=\{ e,a,b,c \}$, $X=G$
>
>共轭作用，4条轨道（因为Klein交换，中心等于自己，每一个元素自成一类）
>$F(e)=F(a)=F(b)=F(c)=4$
>$$N=\frac{1}{4}(4\times 4)=4$$


>例: $H=\{e,a\} \leqslant Klein = G$ 。H作用到G=X上，
>$$H\times G \;\longrightarrow G_{Hx}$$ $$h\times x \;\mapsto hx $$, 右陪集。整个群阶为4，H的阶为2，所以有两个右陪集(两条轨道！)
>
>如果利用公式，N=2，F(e)=4, F(a)=0


>[!Note] 证明
>设$X=\{a_{1},a_{2},\dots,a_{n}\}$, $G=\{g_{1},g_{2},\dots,g_{m}\}$
>令$$b_{ij}= \begin{cases}1 & g_i\left(a_j\right)=a_j \\ 0 & \text { else }\end{cases}$$
>
$$
\begin{pmatrix} \\
 & a_1 & a_{2} & \dots &a_{n} & \\g_{1} & b_{11} & b_{12} & \dots &b_{1n} &行和为F(g_{1})\\ 
 g_{2} & b_{21} & b_{22} & \dots &b_{2n} &行和为F(g_{2})\\ \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
g_{m} & b_{n1} & b_{n2} & \dots &b_{nm} &行和为F(g_{m})\\
\end{pmatrix}$$
>列和为$a_{i}$稳定子群的阶级，行为$g_{i}$不动点的个数。
>有 $$\sum _{a_{i}\in X}|G_{a_{i}} |=\sum_{g\in G}F(g)$$ 
>由[[10.2 轨道公式#^5a12aa|轨道公式]]， $\Omega_{k}$ 是轨道k
>$$\sum_{k=1}^N \sum_{a_{i}\in \Omega_{k}}|G_{a_{i}} |=\sum_{k=1}^n |\Omega_{k} || G_{a_{i}}|=N| G|$$

>例：项链问题, n颗珠子，r种颜色，每颗珠子染一种颜色，问能串成多少种不同的圆形项链？
>
>令 $B=\{ 1,2,3,\dots,n\}$为珠子集，$C=\{c_{1},c_{2},\dots,c_{r}\}$表示 r 种颜色。
>
>令 $\Omega= \{f: B\longrightarrow C\}$ 所有映射
>
>所有的项链数为$|\Omega |=r^n$， 考虑二面体群$D_{n}$作用到$\Omega$上， 不同的项链数就是$\Omega$不同的轨道数N
>
>由[[Burnside引理#^a89f09|Burnside Thm]]：$$N=\frac{1}{2n} \sum_{g\in D_{n}} F(g)$$
>



>[!note] 引理： 
>$\alpha \in D_{n},f \in \Omega, \alpha \times f = f \iff (ij)在\alpha 的同一轮换中，则f(i)=f(j)$
>


>[!note] 命题:
> $N=\frac{1}{2n}\sum c(1^{\lambda_{1}}2^{\lambda_{2}}\dots s^{\lambda_{s}}) \cdot r^{\lambda_{1}+\lambda_{2}+\dots+\lambda_{s}}$
>
>其中$\alpha=(1^{\lambda_{1}}2^\lambda_{2}\dots s^{\lambda_{s}})$为型，$c(1^{\lambda_{1}}2^\lambda_{2}\dots s^{\lambda_{s}})$是型的个数


> [!example] 6颗珠子，3种颜色，能串成多少手链？
> $D_{6}=\{ (1),(123456),(135)(246),(14)(25)(36),(153)(264),(165432),(12)(36)(45),(23)(14)(56),(34)(25)(16),(26)(35),(31)(46),(42)(51) \}$
> $1^{6}:F((1))=3^{6}$
> $6^{1}: 2\times 3^1$
> $3^{2}:2\times 3^{2}$
> $2^{3}:4\times 3^3$
> $1^22^2:3\times 3^{2+2}$
> $$N=\frac{1}{12}(3^{6}+6+18+4\times 27 + 3^{5})=92$$


>[!example]  有红、黄、蓝三种颜色的珠子分别有3，4，5颗，且每个手链由6颗珠子构，则可以串成多少种不同的手链？
>1. 找不动点。（麻烦但是可行）
>2. 在上一个例子中去掉不符合的项。
>
>在上例中去掉不符合题意的。92 - 16 = 76
> ![e.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/e.png)





#作业 练习：红黄两种颜色的珠子各3颗，问能串成多少种不同的手链？长度为6（D6作用），找不动点来写。