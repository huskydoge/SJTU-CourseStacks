#信息论 

>[!note] (Kraft Inequality 1949) 
>For any instantaneous code (prefix code) over an alphabet of size $D$, the codeword lengths $l_1, l_2, \ldots, l_m$ must satisfy the inequality:
>$$
>\sum_{i=1}^m D^{-l_i} \leq 1
>$$
>Conversely, given a set of codeword lengths that satisfy this inequality, <mark style="background: #FF5582A6;">there exists an instantaneous code with these word lengths.</mark>

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230424150320.png)
*****

>[!Note] (Extended Kraft Inequality)
> For any countably infinite set of codewords that form a prefix code, the codeword lengths satisfy the extended Kraft inequality,
>$$
>\sum_{i=1}^{\infty} D^{-l_i} \leq 1
>$$
>Conversely, given any $l_1, l_2, \ldots$ satisfying the extended Kraft inequality, we can construct a prefix code with these codeword lengths.

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230424151214.png)


## Exercise

1. (Slackness in the Kraft inequality.) An instantaneous code has word lengths $l_1, l_2, \ldots, l_m$, which satisfy the strict inequality
$$
\sum_{i=1}^m D^{-l_i}<1
$$
The code alphabet is $\mathcal{D}=\{0,1,2, \ldots, D-1\}$. Show that there exist arbitrarily long sequences of code symbols in $D^*$ which cannot be decoded into sequences of codewords. 
3. (Fix-free codes) A code is a fix-free code if it is both a prefix code and a suffix code. Let $l_1, l_2, \ldots, l_m$ be $m$ positive integers. Prove that if
$$
\sum_{k=1}^m 2^{-l_k} \leq \frac{1}{2}
$$
then there exists a binary fix-free code with codeword length $l_1, l_2, \ldots, l_m$.
3. $\left(\frac{3}{4}\right.$ fix-free codes) Prove that when
$$
\sum_{k=1}^m 2^{-l_k} \leq \frac{3}{4}
$$
the conclusion above holds.
[[3:4.pdf]]