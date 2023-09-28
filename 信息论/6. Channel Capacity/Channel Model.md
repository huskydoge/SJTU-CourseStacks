#信息论 


- A code consists of the message set $\mathcal{M}$, an encoder and a decoder
- Encoder: The channel is used $n$ times to send a symbol $\mathrm{w} \in \mathcal{M}$
An encoder is a function $f$ such that $f(w): \mathcal{M} \rightarrow X^n$ (one-to-one)
- $f$ yields a distribution on $X^n \stackrel{\text { DMC }}{\Longrightarrow}$ a distribution on $\mathcal{X}$



The encoding rule $f(w)=x^n \in X^n$ generates a codebook (码本)
The codebook is shared between the sender and the receiver
When $f$ is given, a random variable $X^n$ was also defined
Decoder received $y^n \sim p\left(y^n \mid x^n\right)=\prod p\left(y_n \mid x_n\right)$


The decoder need to guess the possible $x^n$ by $y^n$ in some genius manner
By the codebook $f^{-1}\left(x^n\right)=w . \widehat{w}$ could be recovered by decoder. Error if $\widehat{w} \neq w$

>[!Note]
An $(M, n)$ code for the channel $(\mathcal{X}, p(y \mid x), \mathcal{Y})$ consists of the following:
1. An index set $\{1,2, \ldots, M\}$.
 2. An encoding function $X^m:\{1,2, \ldots, M\} \rightarrow X^n$, yielding codewords $x^n(1), x^n(2), \ldots, x^n(M)$. The set of codewords is called the codebook
 3. A decoding function
$$
g: y^n \rightarrow\{1,2, \ldots, M\}
$$
which is a deterministic rule that assigns a guess to each possible received vector.


$$
\begin{gathered}
f: \mathcal{M} \rightarrow X^n \text { and } g: \mathcal{Y}^n \rightarrow \mathcal{M} \\
W \rightarrow X^n \rightarrow Y^m \rightarrow \widehat{W}
\end{gathered}
$$