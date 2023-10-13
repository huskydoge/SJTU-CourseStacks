#信息论  #马尔可夫链

>[!Note] Markov Chain



Random variables $X, Y, Z$ are said to form a Markov chain in that order (denoted by $X \rightarrow Y \rightarrow Z$ ) if the conditional distribution of $Z$<mark style="background: #FF5582A6;"> depends only on $Y$ and is conditionally independent of $X$.</mark> Specifically, $X, Y$, and $Z$ form a Markov chain $X \rightarrow Y \rightarrow Z$ if the joint probability mass function can be written as
$$
p(x, y, z)=p(x) p(y \mid x) p(z \mid y)
$$
$M C$ is a simple but very import structure for real world


1. $X \rightarrow Y \rightarrow Z$ if and only if $X$ and $Z$ are conditionally independent given $Y$.
2. <mark style="background: #FFB86CA6;">$X \rightarrow Y \rightarrow Z$ implies that $Z \rightarrow Y \rightarrow X$. Thus, the condition is sometimes written $X \leftrightarrow Y \leftrightarrow Z$</mark>
3. If $Z=f(Y)$, then $X \rightarrow Y \rightarrow Z$ 
4. If $X \rightarrow Y \rightarrow Z$, then $I(X ; Z \mid Y)=0(X$ and $Z$ are conditionally independent given $Y)$

$$I(X ; Y \mid Z)=E_{p(x, y, z)} \log \frac{p(X, Y \mid Z)}{p(X \mid Z) p(Y \mid Z)}$$