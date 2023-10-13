#信息论 
>[!note] Nonsigular
A code is said to be nonsingular if every element of the range of $X$ maps into a different string in $D^*$; that is,
$$x \neq x^{\prime} \Rightarrow C(x) \neq C\left(x^{\prime}\right)(单射)$$ 

>[!note] Extension
The extension $C^*$ of a code $C$ is the mapping from finite length strings of $X$ to finite-length strings of $D$, defined by
>$$
>C\left(x_1 x_2 \ldots x_n\right)=C\left(x_1\right) C\left(x_2\right) \ldots C\left(x_n\right)
>$$
>where $C\left(x_1\right) C\left(x_2\right) \ldots C\left(x_n\right)$ indicates concatenation of the corresponding codewords.

>If $C\left(x_1\right)=00$ and $C\left(x_2\right)=11$, then $C\left(x_1 x_2\right)=0011$.

>[!Note ]  Uniquely decodable
A code is called uniquely decodable if <mark style="background: #FFB86CA6;">its extension is nonsingular.</mark>
>* In other words, any encoded string in a uniquely decodable code has only one possible source string producing it. (单射)


>[!note] Prefix code
A code is called a prefix code(前缀码) or an instantaneous code(即时码) if no codeword is a prefix of any other codeword.
>* An instantaneous code can be decoded without reference to future codewords since the end of a codeword is immediately recognizable

>[!note] Suffix code
Suffix code: no codeword is a suffix of any other codeword