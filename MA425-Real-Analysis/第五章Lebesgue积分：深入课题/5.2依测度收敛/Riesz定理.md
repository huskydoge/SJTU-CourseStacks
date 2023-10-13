#实变函数 
## Riesz定理
p84
若在E上依测度$\{f_n\}\rightarrow f$, 则存在在E上$a.e.$<mark style="background: #FFB86CA6;">逐点收敛于$f$ </mark>的子序列$\{f_{n_k}\}$.
>[!Important] 证明
> 运用[Borel-Cantelli引理](Borel-Cantelli引理.md)进行证明。


*推论5*
令$\{ f_n\}为E上的非负可积函数序列.$ 则
$$\lim_{k\rightarrow \infty} \int _E f_k = 0$$
当且仅当：
$$在E上\{f_n \}依测度收敛于f\equiv 0且\{f_n\}在E上是一致可积与紧的$$
> [!Important] 证明
> 必要性：$\Leftarrow$
>根据 [一般Vitali收敛定理的推论](一般的Vitali收敛定理.md#^5bc8cb), 我们知道$\{ f_n\}$是一致可积且紧的。而要证明依测度收敛，我们运用[Chebyshev不等式](Chebyshev不等式.md), 对每个指标$n$, 我们有：
>$$m\{x\in E | f_n > \eta \} \le \frac{1}{\eta} \cdot \int_E  f_n$$
>于是有：
>$$0 \le \lim_{n\rightarrow \infty} m\{x\in E|f_n > \eta\} \le \frac{1}{\eta} \cdot \lim_{n \rightarrow \infty} \int_E f_n=0$$.
>即在E上$\{ f_n\}$依测度收敛于 0。
> 充分性：$\Rightarrow$。反证法。若$\lim_{k\rightarrow \infty} \int _E f_k = 0$不成立，则存在某个$\epsilon_0$和子列$\{f_{n_k}\}$满足：
> $$
> 对所有的k, \int_E f_{n_k} \le \epsilon_0。\tag{1}
> $$
> 但根据[Riesz定理](#Riesz定理), 我们知道存在$\{f_{n_k}\}$的一个子序列在E上a.e.逐点收敛到$f\equiv 0$, 且该子列是一致可积且紧的（因为它的母列的性质如此），于是根据[一般的Vitali收敛定理](一般的Vitali收敛定理.md),我们发现这样的子列不满足$(1)$的条件，矛盾！