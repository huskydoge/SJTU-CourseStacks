#信息论 

$$
X^n=\left(X_1, \ldots, X_n\right) \longrightarrow \text { Encoder } m \text { bits } \longrightarrow \widehat{X}^n
$$
(Data compression/Source coding) For a source sequence, we seek to find a shorter encoding for them:
$$\text{"苟利国家生死以"} \rightarrow\{00,01,1,110,111,010,1010\}$$

>[!Note] Problem definition
>Source: $X_1, X_2, \ldots$, are i.i.d. $\sim p(X)$.
>Source sequences: $X^n=\left(X_1, \ldots, X_n\right)$ denotes the $n$-tuple that represents a sequence of $n$ source symbols
- Alphabet: $\mathcal{X}=\{1,2, \ldots,|\mathcal{X}|\}$ - the possible values that each $X_i$ can take on
- Encoder and decoder are a pair of functions $f, g$ such that
$f: \mathcal{X} \rightarrow\{0,1\}^*$ and $g:\{0,1\}^* \rightarrow \mathcal{X}$
* Probability of error: $\quad P_e=P\left(X^n \neq \widehat{X}^n\right)$
If $P_e=0$, "lossless", otherwise "lossy"
- The rate of a scheme: $R=\frac{m}{n}(R=\log |\mathcal{X}|$ is trivial!)

>ToDo: Find an encoder and decoder pair such that $P_e \rightarrow 0$, as $n \rightarrow \infty$

****

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230424131238.png)


>[!Note] Analysis

$$
\begin{aligned}
& E\left(l\left(X^n\right)\right)=\sum_{x^n} p\left(x^n\right) l\left(x^n\right) \\
& =\sum_{x^n \in A_\epsilon^{(n)}} p\left(x^n\right) l\left(x^n\right)+\sum_{x^n \notin A_\epsilon^{(n)}} p\left(x^n\right) l\left(x^n\right) \\
& \leq \sum_{x^n \in A_\epsilon^{(n)}} p\left(x^n\right)(n(H+\epsilon)+2)+\sum_{x^n \notin A_\epsilon^{(n)}} p\left(x^n\right)(n \log |\mathcal{X}|+2) \\
& =\operatorname{Pr}\left\{A_\epsilon^{(n)}\right\}(n(H+\epsilon)+2)+\operatorname{Pr}\left\{\left(A_\epsilon^{(n)}\right)^c\right\}(n \log |\mathcal{X}|+2) \\
& \leq n(H+\epsilon)+\epsilon n(\log |\mathcal{X}|)+2 \\
& =n\left(H+\epsilon^{\prime}\right) \\
& E\left[\frac{1}{n} l\left(X^n\right)\right] \leq H(X)+\epsilon \quad \begin{array}{l}
\text { Thus, we can represent sequences } \boldsymbol{X}^{\boldsymbol{n}} \text { using } \\
\boldsymbol{n H}(\boldsymbol{X}) \text { bits on the average. }
\end{array} \\
&
\end{aligned}
$$
>(Converse). For any scheme with rate $r<H(X), P_e \rightarrow 1$


Let $r=H(X)-\epsilon$. For any scheme with rate $r$, it can encode at most $2^{n r}$ different symbols in $X^n$. The correct decoding probability is $\approx 2^{n r} 2^{-n H}=2^{-n(H-r)} \rightarrow 0$
$$
P_e \rightarrow 1
$$

>[!Warning] Rate 有一个下界，否则就一定会出错！