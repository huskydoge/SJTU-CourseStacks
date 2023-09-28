#信息论 


>[!Note] The typical set (典型集) 
>$A_\epsilon^{(n)}$ with respect to $p(x)$ is the set of sequences $\left(x_1, x_2, \ldots, x_n\right) \in \mathcal{X}^n$ with the property
>$$
>2^{-n(H(X)+\epsilon)} \leq p\left(x_1, x_2, \ldots, x_n\right) \leq 2^{-n(H(X)-\epsilon)}
>$$


1. If $\left(x_1, x_2, \ldots, x_n\right) \in A_\epsilon^{(n)}$, then $H(X)-\epsilon \leq-\frac{1}{n} \log p\left(x_1, x_2, \ldots, x_n\right) \leq H(X)+\epsilon$
2. $\operatorname{Pr}\left\{A_\epsilon^{(n)}\right\} \geq 1-\epsilon$ for $n$ sufficiently large.
3. $\left|A_\epsilon^{(n)}\right| \leq 2^{n(H(X)+\epsilon)}$, where $|A|$ denotes the number of elements in the set $A$.
4. $\left|A_\epsilon^{(n)}\right| \geq(1-\epsilon) 2^{n(H(X)-\epsilon)}$ for $n$ sufficiently large.

>[!Note] Intuition
>1. The typical set has probability nearly 1｜(近1性)
>2. All elements of the typical set are nearly equiprobable ｜(等概率性)
>3. The number of elements in the typical set is nearly $2^{n H}$



*****
1. If $\left(x_1, x_2, \ldots, x_n\right) \in A_\epsilon^{(n)}$, then $H(X)-\epsilon \leq-\frac{1}{n} \log p\left(x_1, x_2, \ldots, x_n\right) \leq H(X)+\epsilon$ Proof. By the definition of typical set.
2. $\operatorname{Pr}\left\{A_\epsilon^{(n)}\right\} \geq 1-\epsilon$ for $n$ sufficiently large.
Proof. By AEP Theorem, the probability of the event $\left(X_1, X_2, \ldots, X_n\right) \in A_\epsilon^{(n)}$ tends to 1 as $n \rightarrow \infty$. Thus, for any $\delta>0$, there exists an $n_0$ such that for all $n \geq n_0$, we have
$$
\operatorname{Pr}\left\{\left|-\frac{1}{n} \log p\left(X_1, X_2, \ldots, X_n\right)-H(X)\right|<\epsilon\right\}>1-\delta
$$
Setting $\delta=\epsilon$.

3. $\left|A_\epsilon^{(n)}\right| \leq 2^{n(H(X)+\epsilon)}$, where $|A|$ denotes the number of elements in the set $A$. Proof.
$$
\begin{aligned}
& 1=\sum_{x \in X^n} p(x) \\
& \geq \sum_{x \in A_\epsilon^{(n)}} p(x) \\
& \geq \sum_{x \in A_\epsilon^{(n)}} 2^{-n(H(X)+\epsilon)} \\
&=2^{-n(H(X)+\epsilon)}\left|A_\epsilon^{(n)}\right| \\
& \text { Thus, }\left|A_\epsilon^{(n)}\right| \leq 2^{n(H(X)+\epsilon)}
\end{aligned}
$$

> $$\begin{gathered}
\frac{\left|A_\epsilon^{(n)}\right|}{\left|X^n\right|} \leq 2^{n(H(X)-\log |X|)} \Rightarrow 0 \\
\operatorname{Pr}\left(\mathcal{X}^n\right) \approx \operatorname{Pr}\left(A_\epsilon^{(n)}\right)
\end{gathered}$$


4. $\left|A_\epsilon^{(n)}\right| \geq(1-\epsilon) 2^{n(H(X)-\epsilon)}$ for $n$ sufficiently large.
Proof. For sufficiently large $n, \operatorname{Pr}\left\{A_\epsilon^{(n)}\right\}>1-\epsilon$, so that
$$
\begin{aligned}
& 1-\epsilon<\operatorname{Pr}\left\{A_\epsilon^{(n)}\right\} \\
\leq & \sum_{x \in A_\epsilon^{(n)}} 2^{-n(H(X)-\epsilon)} \\
= & 2^{-n(H(X)-\epsilon)}\left|A_\epsilon^{(n)}\right|
\end{aligned}
$$
Thus $\left|A_\epsilon^{(n)}\right| \geq(1-\epsilon) 2^{n(H(X)-\epsilon)}$