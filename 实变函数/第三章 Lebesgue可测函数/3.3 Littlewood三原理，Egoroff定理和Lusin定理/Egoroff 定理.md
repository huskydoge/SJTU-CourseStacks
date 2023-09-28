#实变函数

p 53
## Egoroff定理
假设$E$具有有限测度，可测函数序列逐点 {$f_n$} $\rightarrow f$，f实值。则对于任意的$\epsilon$，存在包含于E的闭集F，满足$m(E\sim F) < \epsilon$， 且在F上一致 {$f_n$} $\rightarrow f$。
* 假若E不有界的话不能用下面的引理，所以之后每个用到Egoroff定理证明的定理都要求E有界！

>[!Note]
>1. Egoroff定理告诉我们，逐点收敛其实<mark style="background: #FFF3A3A6;">“接近”于一致收敛</mark>


****

*Lemma*
在Egoroff定理的条件下，对任意的 $\delta >0, \eta > 0$, 存在 E 的可测子集 A 和 指标 N，满足对任意的 n 大于等于 N，有：
$$
m(E\sim A) < \delta, \,|f_n-f|<\eta \,\text{ on A }
$$
>证明用到了 [[Lebesgue测度的连续性|L 测度连续性]]。
>定义$E_n=\{\forall k \ge n,x \in E \mid |f(x)-f_k(x)| < \eta \}$。 可以证明，$E_n$是可测集，且$\{E_n\}$为上升的可测集族，由[Lebesgue测度的连续性](Lebesgue测度的连续性.md)， 我们知道:
>$$\lim_{n\rightarrow \infty}m(E_n)=m(\bigcup_{n=1}^\infty E_n)$$
>而已知$\{f_n\}$逐点收敛于$f$,所以必然有 $\bigcup_{n=1}^\infty E_n=E$, 所以$$m(\bigcup_{n=1}^\infty E_n)=m(E)$$
>
>***下面是关键的一步:***
>我们回归目标：我们要找到一个E的可测子集，使得E扣掉A的测度小于$\delta$, 由测度的分割性质知只需$m(E)-m(A)<\delta$。 那我们根据极限的性质，我们总能找到一个指标N，使得n大于等于N时，$m(E_N)>m(E)-\delta$。那取A为这个子集$E_N$就结束了证明。

