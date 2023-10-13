#实变函数 

p78
*命题25* 令E为<mark style="background: #FFB86CA6;">有限测度</mark>集，$\{f_n\}$ 一致可积，<mark style="background: #FF5582A6;">且在E上a.e.逐点收敛于$f$,</mark>
则f在E上可积。
>[!证明]
>要求E为有限测度是因为要将E进行不交的有限分割，用到[引理22](积分的连续性表示.md#*引理22*)
>根据[引理22](积分的连续性表示.md#*引理22*)，我们可以把E分为有限集族$\{E_k\}_{k=1}^N$的不交并，且每个$E_k$的测度小于$\delta$, 这里的$\delta$ 应对于$\{f_n\}$ 一致可积中 $\epsilon = 1$ 的挑战。如此一来：
>$$\int_E |f_n|=\sum_k^N\int_{E_k}|f_n|<N$$
>再由[Fatou引理](Fatou引理.md)，$$\int_E|f|\le\lim_{n\rightarrow \infty}\inf \int |f_n|\le N$$
>于是f在E上可积。

E有限测度是必要的。
*反例*
若E=R，取$f_n=\mathcal{X}_{[-n,n]}$, 则$\{f_n\}$一致可积，但是他们的极限$f \equiv 1$ 在E=R上不可积！

>[! Bug]  #错题标记 #考试题目 
>我曾在实分析的期中考试中，忽视了对Vitali收敛定理，<mark style="background: #FF5582A6;">要求点态收敛的条件</mark>，只考虑了一致可积。谨记！*——2023年4月10日 Monday*
******

# *Vitali收敛定理*


 令E为有限测度集，<mark style="background: #FF5582A6;">$\{f_n\}$ [一致可积](一致可积.md)</mark>，且在E上a.e.逐点收敛于$f$, 则f在E上可积且

$$\lim_{n\rightarrow \infty}\int_Ef_n=\int_Ef$$
>[!证明]
>需要用到 [Egoroff 定理](Egoroff%20定理.md) 进行证明，所以命题中要求E有限！还用到了[Fatou引理](Fatou引理.md).
>思路切入是积分的三角不等式：
>$$|\int_E{f_n}-\int_Ef|=|\int_E({f_n-f})|\le \int_E|f_n-f|$$
>而对E的任意子集，我们可以对E进行如下的分割：
>$$\int_E|f_n-f|=\int_{E\sim A}|f_n-f|+\int_A|f_n-f|\le\int_{E\sim A}|f_n-f|+\int_A|f_n|+\int_A|f|$$
>这个分解的目的性就很强了，我们想要证明对任意的$\epsilon$, $RHS < \epsilon$, 那么我们可以做三等分。
>1. 由 $\{f_n\}$ 的一致可积性， 我们可以对任意的$\epsilon$取$\delta>0$, 使得$m(A) < \delta$ 则$\int_A|f_n| < \frac{\epsilon}{3}$.
>2. 因为在E上$\{f_n\}$ a.e.逐点收敛于$f$, 在E上$\{\mid f_n\mid\}$ a.e.逐点收敛于$\mid f \mid$ 所以由[Fatou引理](Fatou引理.md)，$\int_A|f| < \frac{\epsilon}{3}$
>3. 由[Egoroff 定理](Egoroff%20定理.md)，我们可以选取包含于E的可测闭集F，这里也就是选为$E\sim A$，使得$m(E\sim (E\sim A))=m(A) < \delta$, 而在$E\sim A$上$\{f_n\}$一致收敛于$f$。那么我们总可以选取自然数N，使得n大于N时成立：
>	$$|f_n-f|<\frac{\epsilon}{3m(E)}$$
>	
>这样就算证明完成了。
>

*反例*
假如E=R，则Vitali定理不成立。取$f_n=\mathcal{X}_{[n,n+1]}$，则 $\{f_n\}$ 一致可积， $\{f_n\}$ 逐点收敛于$f\equiv 0$, 但是积分显然不同。

***推论***
令E为有限测度集，假定$\{h_n\}$是在E上a.e.逐点收敛于 $h\equiv 0$ 的<mark style="background: #FF5582A6;">非负</mark>可积函数序列，则：
$$\lim_{n\rightarrow \infty}\int_E h_n=0\,\,当且仅当\{h_n\}在E上一致可积$$
>证明

$h_n$非负是必要的！

*反例*
取 $E = [-1,1]$, 取:
$$
h_{n}=\left\{\begin{array}{ll}
n & x \in\left(0, \frac{1}{n}\right) \\
-n & x \in\left(-\frac{1}{n}, 0\right) \\
0 & \text { else }
\end{array}\right.
$$
则 $\lim_{n\rightarrow \infty}\int_E h_n=0$, 但是$\{h_n\}$在E上不一致收敛！