#信息论 

>Goal: no two $X$ sequences produce the same $Y$ output sequence.

The channel has a subset of inputs that produce essentially disjoint sequences at the output.
- For each (typical) input $n$-sequence, there are approximately $2^{n H(Y \mid X)}$ possible $Y$ sequences, all of them equally likely

- The total number of possible (typical) $Y$ sequences is $\approx 2^{n H(Y)}$. This set has to be divided into sets of size $2^{n H(Y \mid X)}$ corresponding to the different input $X$ sequences.

>[!Note]
The total number of disjoint sets is less than or equal to $2^{n(H(Y)-H(Y \mid X))}=2^{n I(X ; Y)}$.

Hence, we can send at most $\approx 2^{n I(X ; Y)}$ distinguishable sequences of length $n . \rightarrow I(X ; Y)$


We could use at most $2^{n I(X ; Y)}$ sequences in $X^n$ to denote $W$. Thus the information rate $$R=\frac{1}{n} \log 2^{n l(X ; Y)}=I(X ; Y)$$
The capacity $=\sup R=\max _{p(x)} I(X ; Y)$