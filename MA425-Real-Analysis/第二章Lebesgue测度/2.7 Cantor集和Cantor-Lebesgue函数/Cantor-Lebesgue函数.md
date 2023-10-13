#实变函数 
p43
我们首先在构造Cantor集所去掉的集合上定义函数。

然后通过在$\mathcal{C}$(cantor set)上定义我们将$\phi$延拓到整个$[0,1]$区间：
$$\phi(0)=0,\phi(x)=\sup \{\phi(t) \mid t \in \mathcal{O} \cap [0,x) \}，若x\in \mathcal{C} \sim \{0\}$$
*命题20* Cantor-Lebesgue函数$\phi$
1. 是<mark style="background: #FF5582A6;">递增</mark>的<mark style="background: #FFB86CA6;">连续</mark>函数
2. 将$[0,1]$映到$[0,1]$。
3. 它的导数在开集$\mathcal{O}$上存在。
	* 在$\mathcal{O}$上$\phi' = 0$
	*  $m(\mathcal{O})=1$



*命题21* 令$\phi$为Cantor-Lebesgue函数且定义在$[0,1]$上的函数$\psi$ 为：
$$对所有的x\in [0,1] \quad \psi(x)=\phi(x)+x$$
则$\psi$为<mark style="background: #FF5582A6;">严格单调递增</mark>的连续函数，它将$[0,1]$映为$[0,2]$.
1) 将Cantor集 $\mathcal{C}$ 映上正测度的可测集
2) 将一个可测集，即Cantor集的子集映上一个非可测集
>[!important] 证明
>首先由函数连续且$\psi(0)=0,\psi(1)=2$，知它将$[0,1]$映为$[0,2]$。
>然后将$[0,1]$分解为$\mathcal{C} \cup \mathcal{O}$，则$\psi$也有不交分解：$$[0,2]=\psi(\mathcal{C})\cup \psi(\mathcal{O})$$结合$m(\mathcal{O})=1$, 证明$m(\psi(\mathcal{O}))=1$, 从而得到$m(\psi(\mathcal{C}))=1$, 于是（1）得证。
>
>对于(2)，我们运用[Vitali定理](Vitali定理.md)，知$\psi(\mathcal{C})$中有一个不可测子集$W$，则有Cantor集的可测子集 $\psi^{-1}(W)$ 被 $\psi$ 映射到一个不可测集$W$上。得证。


*命题22* Cantor集有一个不是Borel集的可测子集
>[!important] 证明
>严格递增的连续函数将Borel集映射到Borel集上，于是上面的Cantor可测子集$\psi^{-1}(W)$不是Borel集合，否则它将被$\psi$映射到Borel集合上，因此会可测，这与事实不符！

 
 可见：Borel集是可测集，<mark style="background: #FFF3A3A6;">但是可测集不一定是Borel集</mark>

