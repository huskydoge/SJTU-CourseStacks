#信息论 

> Not required


$A_\epsilon^{(n)}$ is a very tiny set that contains most of the probability; i.e., high probability set

>Definition. For each $n=1,2, \ldots$, let $B_\delta^{(n)} \subseteq \mathcal{X}^n$ be the smallest set with
>$$
>\operatorname{Pr}\left\{B_\delta^{(n)}\right\} \geq 1-\delta
>$$

>[!Note] Theorem
>Let $X_1, X_2, \ldots, X_n$ be i.i.d $\sim p(x)$. For $\delta<\frac{1}{2}$ and any $\delta^{\prime}>0$, if $\operatorname{Pr}\left\{B_\delta>^{(n)}\right\} \geq 1-\delta$, then $\frac{1}{n} \log \left|B_\delta^{(n)}\right|>H-\delta^{\prime}$ for $n$ sufficiently large.


Intuition: As $A_\epsilon^{(n)}$ has $2^{n(H \pm \epsilon)}$ elements, $\left|B_\delta^{(n)}\right|$ and $\left|A_\epsilon^{(n)}\right|$ are equal to the first order in the exponent
Proof: (exercise 3.11)
- For any two sets $A, B$, if $\operatorname{Pr}(A) \geq 1-\epsilon_1 \operatorname{Pr}(B) \geq 1-\epsilon_2$, then
$$
\begin{gathered}
\operatorname{Pr}(A \cap B)>1-\epsilon_1-\epsilon_2 \\
1-\epsilon-\delta \leq \operatorname{Pr}\left(A_\epsilon^{(n)} \cap B_\delta^{(n)}\right)=\sum_{A_\epsilon^{(n)} \cap B_\delta^{(n)}} p\left(x^n\right) \leq \sum_{A_\epsilon^{(n)} \cap B_\delta^{(n)}} 2^{-n(H-\epsilon)} \\
=\left|A_\epsilon^{(n)} \cap B_\delta^{(n)}\right| 2^{-n(H-\epsilon)} \leq\left|B_\delta^{(n)}\right| 2^{-n(H-\epsilon)} \\
\left|B_\delta^{(n)}\right| \geq\left|A_\epsilon^{(n)} \cap B_\delta^{(n)}\right| \geq 2^{n(H-\epsilon)}(1-\epsilon-\delta)
\end{gathered}
$$