#信息论 
![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230425203439.png)

## Construction
Fix $p(x)$. Generate a $\left(2^{n R}, n\right)$ code at random according to $p(x)$
$$
p\left(x^n\right)=\prod_{i=1}^n p\left(x_i\right)
$$
>Random coding


The probability the we generate a particular code $C$ is
$$
\operatorname{Pr}(C)=\prod_{w=1}^{2^{n R}} \prod_{i=1}^n p\left(x_i(w)\right)
$$
The code $C$ is revealed to both the sender and the receiver. Both them know $p(y \mid x)$
- A message $W$ is chosen according to a <mark style="background: #FF5582A6;">uniform distribution</mark>
$$
\operatorname{Pr}(W=w)=2^{-n R}, w=1,2, \ldots, 2^{n R}
$$
- The $w$ th codeword $X^n(w)$ is sent over the channel
- The receiver receives a sequence $Y^n$ according to the distribution
$$
P\left(y^n \mid x^n(w)\right)=\prod_{i=1}^N p\left(y_i \mid x_i(w)\right)
$$

## Joint decoding

The receiver guess which message was sent. In jointly typical decoding, the receiver declares that the index $\widehat{W}$ was sent if the following conditions are satisfied:
>1. $\left(X^n(\widehat{W}), Y^n\right)$ is jointly typical
>
>2. There is no other index $W^{\prime} \neq W$, such that $\left(X^n\left(W^{\prime}\right), Y^n\right) \in A_\epsilon^{(n)}$.

If no such $\widehat{W}$ exists or if there is more than one such, an error is declared. (We may assume that the receiver outputs a dummy index such as 0 in this case.)

Let $\mathcal{E}$ be the event $\{\widehat{W} \neq W\}$

>We need to show that:
$$
\operatorname{Pr}(\mathcal{E}) \rightarrow 0
$$

>[!Warning] The following Proof is not required by exam!

>[!Note] Main idea
>If we could prove that for <mark style="background: #FFF3A3A6;">all the codebook (all the possible $C$ )</mark>, the average $\operatorname{Pr}(\mathcal{E}) \leq \epsilon_{\text {; }}$ then the error probability of the best code (one of $\left.C^{\prime} s\right) \leq \epsilon$
- We let $W$ be drawn according to a uniform distribution over $\left\{1,2, \ldots, 2^{n R}\right\}$ and use jointly typical decoding $\widehat{W}\left(y^n\right)$
- Let $\mathcal{E}=\left\{\widehat{W}\left(y^n\right) \neq W\right\}$ denote the error event
- We will calculate the average [[Probability of Error]], averaged over all codewords in the codebook, and <mark style="background: #FFB86CA6;">averaged over all codebooks</mark> (两次平均)
$$
\begin{aligned}
& \operatorname{Pr}(\varepsilon)=\sum_C \operatorname{Pr}(C) P_e^{(n)}(C) \\
& =\sum_C \operatorname{Pr}(C) \frac{1}{2^{n R}} \sum_{w=1}^{2^{n R}} \lambda_w(C) \\
& =\frac{1}{2^{n R}} \sum_{w=1}^{2^{n R}} \sum_C \operatorname{Pr}(C) \lambda_w(C)
\end{aligned}
$$

>$$
E_i=\left\{\left(\left(X^n(i), Y^n\right) \text { is in } A_\epsilon^{(n)}\right), i \in\left\{1,2, \ldots, 2^{n R}\right\}\right\}
>$$

Then an error occurs in the decoding scheme if either $E_1^C$ occurs (when the transmitted codeword and the received sequence are not jointly typical) or $E_2 \cup E_3 \cup \cdots \cup E_{2^{n R}}$ occurs (when a wrong codeword is jointly typical with the received sequence).

>We can assume without loss of generality that the message $W=1$ was sent


$$
\begin{aligned}
& \sum_C \operatorname{Pr}(C) \lambda_1(C)=\operatorname{Pr}(\varepsilon \mid W=1) \\
& \operatorname{Pr}(\mathcal{E})=\frac{1}{2^{n R}} \sum_{w=1}^{2^{n R}} \operatorname{Pr}(\varepsilon \mid W=w)
\end{aligned}
$$
Take $\operatorname{Pr}(\mathcal{E} \mid W=1)$ for example

$$\begin{gathered}E_i=\left\{\left(\left(X^n(i), Y^n\right) \text { is in } A_\epsilon^{(n)}\right), i \in\left\{1,2, \ldots, 2^{n R}\right\}\right\} \\ \operatorname{Pr}(\varepsilon \mid W=1)=P\left(E_1^c \cup E_2 \cup E_3 \cup \cdots \cup E_{2^{n R}} \mid W=1\right) \\ \leq P\left(E_1^c \mid W=1\right)+\sum_{i=2}^{2^{n R}} P\left(E_i \mid W=1\right)\end{gathered}$$


By [[Joint AEP]]$, P\left(E_1^c \mid W=1\right) \rightarrow 0$, and hence $\mathrm{P}\left(\mathrm{E}_1^{\mathrm{c}} \mid \mathrm{W}=1\right) \leq \epsilon$, for $n$ sufficiently large.

For $i \geq 2,\left(E_i \mid W=1\right)$ : Since by the code generation process, $X^n(1)$ and $X^n(i)$ are independent for $i \neq 1$, so are $Y^n$ and $X^n(i)$. Hence, the probability that $X^n(i)$ and $Y^n$ are jointly typical is $\leq 2^{-n(I(X ; Y)-3 \epsilon)}$ by the joint AEP


$$
\begin{aligned}
\operatorname{Pr}(\varepsilon \mid W=1) & \leq \epsilon+\sum_{i=2}^{2^{n R}} 2^{-n(I(X ; Y)-3 \epsilon)} \\
& =\epsilon+\left(2^{n R}-1\right) 2^{-n(I(X ; Y)-3 \epsilon)} \\
& \leq \epsilon+2^{n R} 2^{-n(I(X ; Y)-3 \epsilon)} \\
& =\epsilon+2^{-n(I(X ; Y)-R-3 \epsilon)}
\end{aligned}
$$
If $n$ is sufficiently large and $R<I(X ; Y)-3 \epsilon$,
$$
\begin{gathered}
\operatorname{Pr}(\mathcal{E} \mid W=1) \leq 2 \epsilon \\
\operatorname{Pr}(\mathcal{E}) \leq 2 \epsilon
\end{gathered}
$$


There exists a best codebook $C^*$ such that
$$
\operatorname{Pr}\left(\mathcal{E} \mid C^*\right)=\frac{1}{2^{n R}} \sum_{i=1}^{2^{n R}} \lambda_i\left(C^*\right) \leq 2 \epsilon
$$
By the definition of $\left(n, 2^{n R}\right)$ code, we need to further show that
$$
\lambda^{(n)} \rightarrow 0
$$
Without loss of generality, assume
$$
\lambda_1 \leq \lambda_2 \leq \cdots \leq \lambda_2{ }^{n R}
$$
By $\operatorname{Pr}\left(\varepsilon \mid C^*\right) \leq 2 \epsilon$, we have
$$\lambda_1 \leq \lambda_2 \leq \cdots \leq \lambda_{2^{n R-1}} \leq 4 \epsilon$$
(Or $\lambda_{2^{n R-1}}>4 \epsilon, \frac{1}{2^{n R}} \sum_{i=1+2^{n R-1}}^{2^{n R}} \lambda_i\left(C^*\right)>\frac{1}{2} 4 \epsilon=2 \epsilon$, contradiction!)

>Further refine the codebook $C^*$

* Throw away the worst half of the codewords in the best codebook $C^*$
* The best half of the codewords <mark style="background: #FFB86CA6;">have a maximal probability of error less than $4 \epsilon$</mark>
* If we reindex these codewords, we have $2^{n R-1}$ codewords. Throwing out half the codewords has changed the rate from $R$ to $R-\frac{1}{n}$, <mark style="background: #FF5582A6;">which is negligible for large $n$</mark>