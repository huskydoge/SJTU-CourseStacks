#信息论 

>[!Note] Theorem (AEP 渐近均分性) 
>If $X_1, X_2, \ldots$ are i.i.d. $\sim p(x)$, then
>$$
>-\frac{1}{n} \log p\left(X_1, X_2, \ldots, X_n\right) \rightarrow H(X)
>$$
>in probability.


Proof.
$$
\begin{aligned}
-\frac{1}{n} \log p\left(X_1, X_2, \ldots, X_n\right) & =-\frac{1}{n} \sum_i \log p\left(X_i\right) \\
& \rightarrow-E \log p(X) \text { in probability } \\
& =H(X)
\end{aligned}
$$
$-\frac{1}{n} \log p\left(X_1, \ldots, X_n\right) \rightarrow H(X)$

■ 总概率 $\rightarrow 1$

$$
\begin{gathered}
H(X)-\epsilon \leq-\frac{1}{n} \log p\left(X_1, X_2, \ldots, X_n\right) \leq H(X)+\epsilon \text { in prob. } \\
2^{-n(H(X)+\epsilon)} \leq p\left(X_1, X_2, \ldots, X_n\right) \leq 2^{-n(H(X)-\epsilon)} \Rightarrow A_\epsilon^{(n)}
\end{gathered}
$$