## Notations

| Symbol   Used |                           Meaning                            | Problem Number |
| :-----------: | :----------------------------------------------------------: | :------------: |
|   $W_{ALG}$   |         The total reward of homework achieved by ALG         |  Problem 1, 2  |
|   $W_{OPT}$   |         The total reward of homework achieved by OPT         |  Problem 1, 2  |
|   $OPT[k]$    |         The assignment OPT choose at k-th iteration          |   Problem 1    |
|   $ALG[k]$    |         The assignment ALG choose at k-th iteration          |   Problem 1    |
|   $S_{ALG}$   |                The homework set picked by ALG                |  Problem 1, 2  |
|   $S_{OPT}$   |                The homework set picked by OPT                |  Problem 1, 2  |
|    $W_{A}$    | The total reward of homework in subset $A$, where $1\le \mid A \mid\le 2$ |  Problem 2(c)  |
|     MISMW     |   symbol for "maximal independent set with maximum weight"   |   Problem 3    |
|      $c$      |                  real cost of add operation                  |   Problem 4    |
|   $\hat{c}$   |                    Amortized cost off add                    |   Problem 4    |
|   $\delta$    |           A chosen constant in amortized analysis            |   Problem 4    |

****
## Problem 1

The basic idea we want to use here is "Greedy won't ruin the OPT". **As the choosing order doesn't matter in OPT, we sort the assignment in $OPT$ by its weight in descending order.**

We assumed we have run k'th iteration with $OPT=ALG$, and we will consider the case at k+1'th iteration. Let $i$ be the assignment chosen by ALG at k+1 iteration, $i\notin S$, the weight of $S \cup \{ i \}$ does not exceed $T$, and $i$ is assignment with the largest weight in $Γ(S)$. 


Without loss of generality, we assume $i$ is not included in $OPT$. Otherwise we make keep `++k` until we find a certain $i\notin S$ at current iteration and $i\notin OPT$. 

According to the assumption that before k+1 iteration, $ALG[k]=OPT[k]$, but $i=ALG[k+1]\neq OPT[k+1]$

> Case 1: $w_{ALG[k+1]}=w_{OPT[k+1]}$
>
> In this case, just make $w_{OPT[k+1]}=w_{ALG[k+1]}$, we won't ruin optimality.

> Case 2: $w_{ALG[k+1]}> w_{OPT[k+1]}$.
>
> Since we have sorted $OPT$ in descending order of weight, then we have  $w_{ALG[k+1]}> w_{OPT[k+1+t]},t=0,1,\cdots$
>
> 1. If $OPT[k+1+t],t=0,1,\cdots$ are different from each other, then we have:
>    $$
>    \sum_{t\ge 0}w_{OPT[k+1+t]}\le \sum_{j=0}^{w_i-1}2^j=2^{w_i}-1 < 2^{w_i}
>    $$
>    which contradicts to the fact that $W_{OPT}\ge W_{ALG}$
>
> 2. If there exists some assignment with same weight in $\{ OPT[k+1+t]\mid t\ge 0 \}$, we then merge these homework with same weight. Everytime we merge, the exponent of such homework increase by 1, since $2\cdot 2^w=2^{w+1}$. During the merging process,
>
>    * if there appears a merged assignment whose weight reaches $w_{i}=w_{ALG[k+1]}$, then we could replace these assignment in $OPT$ with $ALG[k+1]$, and we won't ruin the optimality. 
>    * If there doesn't exist a merged assignment whose weight reaches $w_{i}=w_{ALG[k+1]}$, which means still all the assignment's weight is less than $w_{i}=w_{ALG[k+1]}$, then by (1), we know we find a contradiction.

Therefore, we have proved in all cases, at (k+1)-th iteration, $ALG$ still corresponds to $OPT$. By induction, we have proved AKG correctly outputs S with the maximum reward.



****
## Problem 2

### a)

Denote the final rewards achieved by ALG as $W_{ALG}$, by OPT as $W_{OPT}$. To Prove for the 0.5-approximation, we need to prove that $2W_{ALG}\ge W_{OPT}$. 

From the procedure of the ALG, we know that when ALG terminates, $W_{ALG}\ge T-w_{1}$, where $w_{1}$ is the assignment with minimum reward. Otherwise, ALG won't terminate as we could add $w_{1}$ into $S$ and continue the procedure. Then we have:
$$
		T-w'=W_{OPT}\ge W_{ALG}\ge T-w_{1}
$$
Here $w_{1}\le w'$. We try to prove $$2W_{ALG}\ge 2T-2w_{1} \ge T-w'=W_{OPT}$$
which is equivalent to: $$T \ge 2w_{1}-w'$$

>Case 1: $T < 2w_{1}$

* Then $S_{OPT}=S_{ALG}=\{w_{1}\}$,  thus $W_{ALG}=W_{OPT}$.

>Case 2: $T \ge 2w_{1}$

* then $T \ge 2w_{1}\ge 2w_{1}-w'$, thus: $2W_{ALG}\ge 2T-2w_{1} \ge T-w'=W_{OPT}$

Therefore, the greedy algorithm in Question 1 is a 0.5-approximation algorithm.



### b)

let homework set = $\left\{ 5+\epsilon,5-\frac{\epsilon}{2},5-\frac{\epsilon}{2}  \right\}$

$W_{ALG}=5+\epsilon, W_{OPT}=10-\epsilon$, then $$\lim_{ \epsilon \to 0 } \frac{W_{OPT}}{W_{ALG}}=\lim_{ \epsilon \to 0 }\frac{10-\epsilon}{5+\epsilon}=2$$



### c)

>[!Note] Lemma: $W_{ALG}>T-w_{i},\forall w_{i} \notin S_{ALG}$
>According to the procedure of the ALG, we could assert that $W_{ALG}>T-w_{i},\forall w_{i} \notin S_{ALG}$. Otherwise, we could add it to $S_{ALG}$ and increase the rewards.

>Case 1:  $|S_{OPT}\cap S_{ALG}^c| = 0$.

In this case, we have $S_{OPT} \subseteq S_{ALG}$, which means $W_{ALG}\ge W_{OPT}$. Since $W_{OPT}\ge W_{ALG}$, we have $W_{OPT}=W_{ALG}$.

>Case 2:  $|S_{OPT}\cap S_{ALG}^c| = 1$.

* For simplicity, we use $A\Delta B$ to denote the symmetric difference of set A and B. 
  * if $|S_{OPT}\Delta S_{ALG}|=2$, then there exists an assignment $i\in S_{OPT}\cap S_{ALG}^c$ and an assignment $j \in S_{OPT}^c\cap S_{ALG}$, and other assignment choose by $ALG$ and $OPT$ are the same, which could be illustrated as follows: ($a_{k}$ stands for assignment $i$)
    $$ALG:[a_{1},a_{2},\cdots ,j, \cdots ,a_{n}]$$
    $$OPT:[a_{1},a_{2},\cdots ,i, \cdots ,a_{n}]$$
    Here $[a_{k}]$ is in the descending order of weight. If $w_{i} > w_{j}$, and $W_{OPT}\le T$, then according to the description of $ALG$, it should choose $i$ rather than $j$, since $j$ is in $\Gamma(S)$ at that moment. Thus $w_{i}\le w_{j}$ , which means $W_{OPT}\le W_{ALG}$.
  * if $|S_{OPT}\Delta S_{ALG}|>2$, which means there exists more than one assignment in $S_{OPT}^c\cap S_{ALG}$, which could be illustrated as:
    $$ALG:[a_{1},a_{2},a_{3}, a_{4}\cdots ,j, \cdots ,a_{n}]$$
    $$OPT:[a_{1},None,a_{3}, None, \cdots ,i, \cdots ,a_{n}]$$
    Here "None" means this assignment doesn't exist in $OPT$. Combined with the analysis for the former case, we know in this case we still have  $W_{OPT}\le W_{ALG}$.

Since $W_{OPT}\ge W_{ALG}$, we have $W_{OPT}=W_{ALG}$. 

>Case 3:  $|S_{OPT}\cap S_{ALG}^c| \ge 2$


We consider the **first iteration** of ALG. We pick subset $A$ of homework set satisfying $1\le | A|\le 2$ and $$T \ge W_{A} \ge w_{i}+w_{j}, \forall w_{i},w_{j}\in S_{OPT}\cap S_{ALG}^c,i\neq j$$
by the requirement that $W_{A}$ is the maximum weight that satisfies $W_{A}\le T$.

<mark style="background: #FFF3A3A6;">The reason we focus on $\forall w_{i},w_{j}\in S_{OPT}$ is that we need to ensure $w_{i},w_{j}$ won't exceed the limit of $T$.</mark>

By symmetry, we might as well assume $w_{i}\le w_{j}$, then $W_{A}\ge 2w_{i}$. Combined with the lemma, we have $$W_{ALG}\ge W_{A}\ge 2w_{i}>2(T-W_{ALG})$$

$$\Rightarrow 3W_{ALG} > 2 T \ge 2W_{OPT}$$

Thus we have proved that this is a $\frac{2}{3}$ - approximation algorithm.

****
## Problem 3

### a)

We assume there exists two maximal independent set  $A$ and $B$ with $|A|<|B|$. Since $M=(U,\mathcal{I})$ is a matroid, thus it should satisfy exchange property, which means there exists a $x\in B \setminus  A$ such that $\{ x \} \cup A \in \mathcal{I}$. However, $A\subsetneq \{ x \} \cup A \in \mathcal{I}$, contradicting to the fact that $A$ is a maximal independent set. Thus, maximal independent sets are of the same size.

### b)

>Since edge set could represent a graph, I will describe edge set as "graph".


#### hereditary property

1. Since for any single edge $e \in E$, we have $\{ e \}\in \mathcal{S}$, thus $\mathcal{S}$ is not empty.
2. For every $F \in \mathcal{S}$ and $F'\subseteq F$, since $F$ does not contain a cycle, as its subgraph, $F'$ also does not contain a cycle, which means $F' \in \mathcal{S}$.

#### exchange property

>[!Note] Lemma: if an acyclic graph $A$ is connected, and another acyclic graph $B$ satisfy $|A|<|B|$, then $A$ and $B$ must have different vertex.
>Proof:
>since $A$ is connected and acyclic, we know $A$ is actually a spanning tree, which have fixed edge numbers given $A$. For a spanning tree, we connected any two of its vertices will form a cycle. 
>If $B$'s vertices are all $A$'s, since we have $|A|<|B|$, then it means there exists a cycle in $B$, contradicted to the fact that $B$ is also acyclic.

For any $A, B\in \mathcal{S}$ with $|A|<|B|$, 

>if $A$ is connected

According to the lemma, we choose a vertex $v$ which is in $B$ and not in $A$. For the edge $x$ which takes $v$ as its endpoint in $B$, since $v\notin A$, we know $x\in B \setminus A$, and there exists no cycle in $A\cup \{ x \}$, then we could have $\{ x \}\cup A \in \mathcal{S}$


>If $A$ is not connected

Suppose there are two connected component $A_{1},A_{2}$ in $A$.


**Case 1:**
if $B$'s vertices are all in $A$'s, then there should exist an edge $x$ between $A_{1}$ and $A_{2}$ in $B$, as shown below:

 ```mermaid
graph LR

a((A1))--edge x x---b((A2))
 ```


   Otherwise as $|B|>|A|=|A_1|+ |A_2|$, combined with lemma, there will exist a cycle inside $B$, which leads to contradiction. Then we could have $\{ x \}\cup A \in \mathcal{S}$



**Case 2:**
If there exists a vertex $v$ in $B$ and not in $A$, then for the edge $x$ which takes $v$ as its endpoint in $B$, since $v\notin A$, we know $x\in B \setminus A$, and there exists no cycle in $A\cup \{ x \}$, then we could have $\{ x \}\cup A \in \mathcal{S}$

**When there are more than two connected components in $A$**, just choose two of them and do the same analysis to them, we can get the same result.

****

We have proved that two property for matroid is satisfied for $M$, which means $M$ is matroid.

>The maximal sets of this matroid is the spaning tree of $E$. We denote it as $T$. ($T$ could have different shape)


Since $T$ is a spanning tree of $E$, if we add any other edge into $T$, we will get a cycle, which means there does not exist a $B\in \mathcal{S}$ that $T \subsetneq B$

### c)

The first element x the algorithm added to S satisfies $A_{0}=\{ x \}\in \mathcal{I}$. Since we have sorted $U$ by weight $w$, and $\mathcal{I}$ is the collection of subset of $U$, then $x$ should be the largest element in $\bigcup \mathcal{I}$. 

>Assume there does not exist a maximal independent set $\mathcal{S}'$ with maximum weight, and $x\in \mathcal{S}'$. 

By the exchange property of matriod, since $|\mathcal{S}'|>|A_{0}|=|\{ x \}|=1$, there should exist an element $x'$ in $\mathcal{S}'\setminus A_{0}$ satisfies $A_{1}=A_{0}\cup \{ x' \}\in \mathcal{I}$. **Unless we have reached the size of maximal independent set of $\mathcal{I}$** (which is $|\mathcal{S}'|)$, we could keep adding elements into $A_{k}$ to get $A_{k+1}$ with larger size. This procedure will finally terminate since $U$ is a finite set. When the procedure terminates, we get a maximal independent set $\mathcal{S''}\in \mathcal{I}$ containing $x$.

According to (a), $\mathcal{S}'$ and $\mathcal{S''}$ are of the same size, while $x \in \mathcal{S''}, x\notin \mathcal{S'}$. Correspondingly, there exists an element $v$ satisfies $v \in \mathcal{S'}, v\notin \mathcal{S''}$.  However, $x$ is the largest element in $\bigcup \mathcal{I}$, which means $x\ge v$. 

* If $x=v$, then we have $w(\mathcal{S}')=w(\mathcal{S''})$, which means that $x$ is in a MISMW $\mathcal{S''}$. **(Here $\mathcal{S'}$ and  $\mathcal{S''}$ could be different! Same weight different element)**
* If $x>v$, then $w(\mathcal{S'})<w(\mathcal{S''})$, which contradicted to the fact that $\mathcal{S'}$ is a MISMW. Thus $x\in \mathcal{S'}$,then we have proved $x$ is in a MISMW $\mathcal{S'}$.

### d)

Denote the size of MISMW as $n$.

>The main direction of my proof here is to apply the conclusion in (c) to find what elements are in a MISMW of    $\,\mathcal{I}$.

Directly from (c), we know the first element x ALG add to $\mathcal{S}$ is in a MISMW, denoted as $\mathcal{S}_{1}$. If we find out this $S_{1}$, then we have found a MISMW.

We let $\, \mathcal{I}' \leftarrow \{ s\mid s\cup \{ x \}\in \mathcal{I}  \}\setminus  \{ x \}, \mathcal{S} \leftarrow \emptyset$. **Here $set \setminus  \{ x \}$ means eliminate all the occurence of $x$ in the element of a set**. 

>We show $M=(U,\mathcal{I}')$ is still a matroid
>
>* **hereditary property**: obviously $\mathcal{I}'$ is nonempty, otherwise we have found the MISMW. 
>  Since for every $A \in \mathcal{I} \text { and } B \subseteq A$ it holds $B \in \mathcal{I}$, combined with hereditary property of $\mathcal{I}$, we have:$$\forall A' \in \mathcal{I}' \text { and } B' \subseteq A'\Rightarrow B' \in \mathcal{I}'$$
>* **exchange property**: use the hereditary property of $\mathcal{I}'$ we have already proved, it's obvious.  

If we want to find $S_{1}$, the euivalent problem is to find a set of size $n-1$ with maximum weight satisfies the constraint that $\{ x \}\cup S_{2}\in \mathcal{S}$.  Here $n-1$ comes from the proof below.

>[!Note] Lemma
>Denote the MISMW contains $x$ as $\mathcal{X}=[x_{1},x_{2},\cdots,x_{n}]$, $x_{i}$ is in descending order, $n$ is the size of maximal independent set of $\mathcal{I}$, and $x_{1}=x$. Denote the set get by ALG as $\mathcal{X}'=[x_{1}',x_{2}',\cdots,x_{m}']$, also $x_{i}'$ is in descending order, which is determined by ALG.
>
>We prove $m=n$
>
>Obviously, if $m\neq n$, then $m$ could only be less than $n$. However, according to the exchange property, we know that unless the size of $\mathcal{X}'$ has reached the size of maximal independent set $n$, we could always add elements into it to get a larger set. **(Otherwise the maximal set's size should be m, contradictory)** This means in the procedure of the ALG, we have some elements $x'$ which satisfies $\mathcal{S} \cup \{ x' \}\in \mathcal{I}$ but we drop it. 
>
>Since the procedure of ALG is a scanning through the elements of $U$ in a decsending order, this case cannot happen! 
>Thus we must have $m=n$.

****

To find a set of size $n-1$ with maximum weight satisfies the constraint that $\{ x \}\cup S_{2}\in \mathcal{S}$,

>This is equivalent to find the MISMW of  $\,\mathcal{I}'$

By applying the same proof of problem (c), we know the next x (or $x_{2}$) found by the ALG is among a MISMW of $\mathcal{I'}$.

Keep repeating this procedure to $x_{3},x_{4},\cdots,x_{n}$, we have proved that greedy algorithm returns a MISMW.

>[!note] Generization of Kruskal’s algorithm
>Since we have proved in (b) that $M=(E,\mathcal{S})$ is a matroid, where $\mathcal{S}=\{F \subseteq E \mid F$ does not contain a cycle $\}$. Here $F$ is exactly the minimum spanning tree. If we set the weight in algorithm 1 to be the negative of edge weight, then we can algorithm 1 turns into Kruaskal Algorithm.


### e)

let $\mathcal{I}=\{ S\subseteq U\mid \text{the vectors in S are independent}\}$. Then we prove $M=(U,\mathcal{I})$ is a matroid.

#### hereditary property

Since any single vector $\{ v \}\in \mathcal{I}$, $\mathcal{I}$ is not empty. According to the fact that the subset of a group of independent vectors are independent,  then hereditary property holds.

#### exchange property

For any $A,B\in \mathcal{I}$, if $|A| < |B|$. Assumed that there doesn't exist an $x\in B \setminus A$ that $A\cup \{ x \}\in \mathcal{I}$, which means all the vectors in $B$ can be represented by vectors in $A$. However, the dimensional of $A$ is less than $B$, thus contradicted! Therefore,  exchange property holds.

Combined with two property above, we have proved $M=(U,\mathcal{I})$ is a matroid.

Then we could apply the alogorithm 1 to solve the problem. The algorithm is as follows:

```pseudo
	\begin{algorithm}
	\caption{2 find a set of vectors S ⊆ U with maximum weight and all vectors in S are linearly independent.}
	\begin{algorithmic}
	\INPUT A matroid $M=(U, \mathcal{I})$ and a weight function $w: U \rightarrow \mathbb{R}_{> 0}$
	\OUTPUT A maximal independent set $S \in \mathcal{I}$ with maximum $w(S)$ and all vectors in S are linearly independent.
	
	\STATE $S \leftarrow \emptyset$
	\STATE Sort $U$ into decreasing order by weight $w$
	\FOR{$x \in U$ in decreasing order of $w$ :}
	\IF{ $S \cup\{x\} \in \mathcal{I}$ }
	\STATE $\quad S \leftarrow S \cup\{x\}$
	\ENDIF

	\ENDFOR
	\RETURN{$S$}
	\end{algorithmic}
	\end{algorithm} 
```

**Time Complexity**
* Sort: $O(m\log m)$
* Judge whether  $S \cup\{x\} \in \mathcal{I}$ : assume there are k n-dimensional vectors in $S \cup\{x\}$, where $k\le \min \{ m,n \}$, since n+1 n-dimensional vector is bound to be linear-dependent. We concate these vectors horizentally to get a $n\times k$ matrix $A$. We check whether the rank of $A$ is equal to k, by using Gaussian Elimination，which has a time complexity at most $O(n^{3})$. If the rank is equal to k, then the vector group is linear-independent, otherwise not. There are m iterations, which has a time complexity of $O(mn^3)$

Thus, the total time complexity is: $\max \{ O(mn^{3}),O(m\log m) \}$
***

## Problem 4

Note that the definition of bit operation is defined as "flip 0 to 1 or flip 1 to 0", in the procedure of adding one to the integer, we could deem it as a combination of some bit operation. Each bit operation's cost is $O(1)$. For the convenience of customizing $\delta$ in amortized analysis below , we assume here $O(1)$ also stands for a constant.

>Define the potential function $\phi$ to be the number of 1-digits in the binary form of the integer.  


>[!Note] Lemma: If we add one to the integer, we would change one and only one 0-digit to 1-digit in its binary form.
>This lemma could be explained as follows: 
>
>* if no carry occurs, then we turn the last digit from 0 to 1.
>* if carry occurs, the carrying procedure will terminate iff it meets an 0-digit.

We assume that, after adding one to the integer, we have $x$ 1-digits turned into 0-digit. According to the lemma above, we know that there is exactly one 0-digit turned into a 1-digit.
$$c=(x+1)O(1)$$
$$\hat{c}=c+\delta \Delta \phi=c+ \delta (1-x)$$
Here we choose $\delta = O(1)$, then we have amortized cost as $\hat{c}=2O(1)=O(1)$



****

## Problem 5
Score: 4
Time spent: 8hr
Collaborator: 朱鹏翔，李佳鑫，李禛