#抽象代数 

>引理 设G为 [[8.4 Sylow Theorm#^6c1dbc|p 群]]，X为G-集，如果｜X｜= m，且（m，p）= 1，则X中有G-不动点。

^788e7b

>[!Note] 证明
>由[[10.2 轨道公式]], $m=|X|=\sum_{i=1}^t [G:G_{x_{i}}]$, 其中$x_{i}$为每条轨道的代表元。因为G为p群，所以每一个指数$[G:G_{x_{i}}]=p^{r},r\ge 0$.
>
>又因为 (m,p)=1, 所以 $p\not\mid m$, 所以必然存在某个 $x_{i}$ 满足$$[G:G_{x_{i}}]=1$$
>所以$G_{x_{i}}=G$. 所以$\forall g\in G,gx_{i}=x_{i}$. 所以$x_{i}$为G-不动点。



1. 有限群$G$ 的 [[8.4 Sylow Theorm#^ca5032|Sylow-p子群]] 共轭

>[!Note] 证明 
>设$|G|=p^{r}m,(m,p)=1$, $H_{1},H_{2}$为G的任意两个sylow-p子群，令$$X=\{aH_{2}|a\in G \} \text{ ，$H_{2}$ 的所有左陪集}$$
>规定$H_{1}$作用在$X$上：
>$$H_{1}\times X\longrightarrow X$$$$(h_{1},aH_{2})\longmapsto h_{1}aH_{2} \text{ ，仍是$H_{2}$左陪集，在X内}$$
>由[[3. Lagrange定理]]知，$\mid X \mid = m.$ $| H_{1}|=p^{r}$, 又(m,p)=1，由[[补证Sylow Thm的推论#^788e7b|引理]]知$X$中 存在$H_{1}$-不动点, i.e. 存在$aH_{2} \in X$, $\forall h_{1} \in H_{1}$,
>有$$h_{1}(aH_{2})=h_{1}aH_{2}=aH_{2}$$
>即$$a^{-1}h_{1}aH_{2}=H_{2}\Rightarrow a^{-1}h_{1}a\in H_{2}\Rightarrow H_{1}a \subseteq aH_{2}$$
>$\because | H_{1}a | = |a H_{2} |, \therefore H_{1}a=aH_{2}\Rightarrow H_{1}=aH_{2}a^{-1}$


2. Sylow-p子群的个数 $n_p \equiv 1 \text{(mod p)}$, 且$n_p \mid |G|$

> [!Note] 证明
> 设$X=\{H\leqslant G | G的sylow-p子群\}$. 定义G在X上的作用:
> $$G\times X \longrightarrow X$$ $$(g,H)\longmapsto gHg^{-1},共轭作用$$
> 则G[[10.2 轨道公式#^bf9861|可迁地]]作用在X上。（作用出来还是sylow-p子群）。同时，根据 [[10.2 轨道公式#^bf9861|可迁的定义]]，若为可迁作用，那么只有一条轨道。
> 
> 由[[10.2 轨道公式#^5a12aa|轨道公式]]及[[3. Lagrange定理]]，和[[10.2 轨道公式#^4064c5|轨道大小与稳定子群指数的关系]]，$n_{p}=|X|=\mid GH\mid=[G:G_{H}]\mid | G|$. **整除性证明完毕**
> ****
> 
> 取 $L\in X$, L作用到X上 （共轭作用）。<mark style="background: #FF5582A6;">但由于L是G的子集，这个作用不再可迁了。</mark> 
> 记$$F_{L}=\{K\in X \mid l(K)=K,\forall l \in L \}$$
> $lKl^{-1}=K$, 长为1的共轭类。
> 
> 由轨道公式，$n_{p}=|X|=|F_{L} |+\sum_{i=1}^t [L:L_{H_{i}}]$ ($[L:L_{H_{i}}]>1$, 理解为不同轨道大小的相加，$H_{i}$为不同轨道的代表元)
> 
> 由[[3. Lagrange定理]]，p整除每一个指数$[L:L_{H_{i}}]$. <mark style="background: #FFB86CA6;">那么我们要证明结论，只需要研究$F_{L}$的大小。</mark>
> 
> **首先，显然$L\in F_{L}$**
> 
> $\forall H \in F_{L},\forall l \in L$
> $$l(H)=lHl^{-1}=H$$
> $l\in N_{G}(H)\leqslant G\Rightarrow L \subseteq N_{G}(H),H \subseteq N_{G}(H)$. 显然$H$和$L$均为$N_{G}(H)$的Sylow-p子群。由Sylow-p子群共轭知，存在$x\in N_{G}(H)$, 
> $$L=xHx^{-1}=H$$
> 从而$|F_{L}|=1$, 从而命题得证。