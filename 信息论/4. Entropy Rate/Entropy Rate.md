#信息论 




>[!Note] Definition
The entropy rate of a stochastic process $\left\{X_i\right\}$ is defined by
>$$
H(\mathcal{X})=\lim _{n \rightarrow \infty} \frac{1}{n} H\left(X_1, X_2, \ldots, X_n\right)
>$$
when the limits exists


* Average entropy

* How to evaluate:
$$
H\left(X_n, \ldots, X_1\right)=\sum_{i=1}^n H\left(X_i \mid X_{i-1}, \ldots, X_1\right)
$$


>For $H\left(X_i \mid X_{i-1}, \ldots, X_1\right)$, <mark style="background: #FFF3A3A6;">we now need to make clear of </mark>
* The existence of
$$
\lim _{n \rightarrow \infty} H\left(X_n \mid X_{n-1}, \ldots, X_1\right)
$$
* In a series $\left\{a_n\right\}$, if $a_n \rightarrow a$, the existence of
$$
\lim _{n \rightarrow \infty} \frac{1}{n} \sum_{i=1}^n a_i
$$

>[!Note] Proof of existence

For a <mark style="background: #FF5582A6;">stationary stochastic process</mark>, $H\left(X_n \mid X_{n-1}, \ldots, X_1\right)$ is nonincreasing in $n$ and has a limit
$$
\begin{aligned}
& H\left(X_{n+1} \mid X_n, \ldots, X_1\right) \\
& \leq H\left(X_{n+1} \mid X_n, \ldots, X_2\right) \\
&= \boldsymbol{H}\left(\boldsymbol{X}_n \mid \boldsymbol{X}_{n-1}, \ldots, \boldsymbol{X}_1\right) \\ \\
& H\left(X_n \mid X_{n-1}, \ldots, X_1\right) \geq 0
\end{aligned}
$$
Since $\left\{H\left(X_n \mid X_{n-1}, \ldots, X_1\right)\right\}$ is nonincreasing and $H\left(X_n \mid X_{n-1}, \ldots, X_1\right) \geq 0$, the limit exists.
>[!warning] 注意
>这里要求过程是stationary的！这样才会有可利用的单调性！


>Define
>$$
>H^{\prime}(\mathcal{X})=\lim _{n \rightarrow \infty} H\left(X_n \mid X_{n-1}, X_{n-2}, \ldots, X_1\right)
>$$

>[!Note]  Theorem: The limits $H^{\prime}(\mathcal{X})$ exists

If $a_n \rightarrow a$ and $b_n=\frac{1}{n} \sum_{i=1}^n a_i$, then $b_n \rightarrow a$
Let $\epsilon>0$. Since $a_n \rightarrow a$, there exists a number $N(\epsilon)$ such that $\left|a_n-a\right| \leq \epsilon$ for all $n \geq N(\epsilon)$. Hence,
$$
\begin{aligned}
\left|b_n-a\right| & =\left|\frac{1}{n} \sum_{i=1}^n\left(a_i-a\right)\right| \\
& \leq \frac{1}{n} \sum_{i=1}^n\left|\left(a_i-a\right)\right| \\
& \leq \frac{1}{n} \sum_{i=1}^{N(\epsilon)}\left|a_i-a\right|+\frac{n-N(\epsilon)}{n} \epsilon \\
& \leq \frac{1}{n} \sum_{i=1}^{N(\epsilon)}\left|a_i-a\right|+\epsilon
\end{aligned}
$$
Thus, $\left|b_n-a\right| \leq \epsilon^{\prime}$, for all $n \geq N(\epsilon)$

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230424141727.png)
