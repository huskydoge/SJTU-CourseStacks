#信息论 

>Not required by exam!


![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230425210623.png)

In data compression: $R>H$
In data transmission: $R<C$

Is the condition $H<C$ sufficient and necessary?
****
- We want to send the sequence of symbols $V^n=V_1, V_2, \ldots, V_n$ over the channel so that the receiver can reconstruct the sequence

To do this, we map the sequence onto a codeword $X^n\left(V^n\right)$ and send the codeword over the channel

The receiver looks at his received sequence $Y^n$ and makes an estimate $\widehat{V}^n$ of the sequence $V^n$ that was sent. The receiver makes an error if $V^n \neq \widehat{V}^n$. We define the probability of error as
$$
\operatorname{Pr}\left(V^n \neq \widehat{V}^n\right)=\sum_{y^n} \sum_{v^n} p\left(v^n\right) p\left(y^n \mid x^n\left(v^n\right)\right) I\left(g\left(y^n\right) \neq v^n\right)
$$
Where $I$ is the indicator function and $g\left(y^n\right)$ is the decoding function


$H<C$ is sufficient and necessary

>[!Note] Theorem (Source-channel coding theorem)

If $V_1, V_2, \ldots, V_n$ is a finite alphabet stochastic process that satisfies the AEP and $H(\mathcal{V})<C$, there exists a source-channel code with probability of error $\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) \rightarrow 0$. Conversely, for any stationary stochastic process, if $H(\mathcal{V})>C$, the probability of error is bounded away from zero, and it is not possible to send the process over the channel with arbitrarily low probability of error.

Converse: We wish to show that $\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) \rightarrow 0$ implies that $H(\mathcal{V}) \leq C$ for any sequence of source-channel codes
$$
\begin{aligned}
& X^n\left(V^n\right): \mathcal{V}^n \rightarrow \mathcal{X}^n \\
& g_n\left(Y^n\right): \mathcal{Y}^n \rightarrow \mathcal{V}^n \\
& H\left(V^n \mid \widehat{V}^n\right) \leq 1+\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) \log \left|\mathcal{V}^n\right|=1+\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) n \log |\mathcal{V}| \\
& H(\mathcal{V}) \leq \frac{H\left(V_1, V_2, \ldots, V_n\right)}{n}=\frac{H\left(V^n\right)}{n}=\frac{1}{n} H\left(V^n \mid \hat{V}^n\right)+\frac{1}{n} I\left(V^n ; \hat{V}^n\right) \\
& \leq \frac{1}{n}\left(1+\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) n \log |\mathcal{V}|\right)+\frac{1}{n} I\left(V^n ; \widehat{V}^n\right) \\
& \leq \frac{1}{n}+\operatorname{Pr}\left(\widehat{V}^n \neq V^n\right) \log |\mathcal{V}|+\frac{1}{n} I\left(X^n ; Y^n\right) \rightarrow C \\
&
\end{aligned}
$$