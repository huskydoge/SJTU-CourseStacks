#信息论 


>[!Note] Data processing inequality
If $X \rightarrow Y \rightarrow Z$, then $$I(X ; Y) \geq I(X ; Z)$$


Proof sketch: Expand $I(X ; Y, Z)$ by chain rule
$$
\begin{array}{r}
I(X ; Y, Z)=I(X ; Z)+I(X ; Y \mid Z) \\
I(X ; Y, Z)=I(X ; Y)+I(X ; Z \mid Y)
\end{array}
$$
where $I(X ; Z \mid Y)=0$


1.  if $Z=g(Y)$, we have $I(X ; Y) \geq I(X ; g(Y))$.
2. If $X \rightarrow Y \rightarrow Z$, then $I(X ; Y \mid Z) \leq I(X ; Y)$.



Assume $X, Y$ are two independent random variables uniformly distributed on $\{0,1\}$.
$$
Z=X+Y(\bmod 2)
$$
这种情况下 $(I(X ; Y \mid Z)>I(X ; Y))$. [[Conditional Mutual Information]]

>Some facts:
1. $X, Y, Z$ are all uniformly distributed $H(X)=H(Y)=H(Z)$
2. Any two of $X, Y, Z$ can determine the other $H(X, Y, Z)=H(X, Y)$
3. Any two of $X, Y, Z$ are independent $H(X, Y)=H(X)+H(Y)$
$$
\begin{aligned}
& I(X ; Y \mid Z)=H(X \mid Z)-H(X \mid Y, Z) \\
&=H(X \mid Z) \\
&=H(X) \\
&=1 \\
& I(X ; Y \mid Z)>I(X ; Y)
\end{aligned}
$$


>[!info] Define: 
>$$I(X ; Y ; Z)=I(X ; Y)-I(X ; Y \mid Z)$$


>Conditioning may not reduce mutual information. <mark style="background: #FF5582A6;">Mutual information is not uncertainty.</mark>