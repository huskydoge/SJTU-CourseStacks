## Problem (a)

To prove this problem problem is NP-Complete, we first prove that it's NP.  Obviously, there is a polynomial verifier which rejects all inputs if the problem is a no instance, and accept a poly size input if it's a yes instance. For example, a clique with size $\frac{n}{2}$ is a certificate.

Then we prove this problem is NP-hard. As we known, clique problem is NP-Complete, we try to reduce clique problem to this problem.

For a given clique instance $(G=(V,E),y)$, we construct the corresponding instance $G'=(V',E')$ for this problem as follows:
* Case 1: If $y=\frac{|V|}{2}$, then $G'=G$
* Case 2: If $y< \frac{|V|}{2}$, then we add $|V|-2y$ new vertices into $G$, and make those new vertices connected to each other, connect all original vertices in $G$ with those new vertices. Let $G'$ be this new graph.
* Case 3: If $y> \frac{|V|}{2}$, then we add $2y-|V|$ new isolated vertices into $G$.Let $G'$ be this new graph.

### Correctness


>[!note] We prove that:  $G$ has a clique of size $y$  if and only if $G'$ has a clique of size $\frac{|V'|}{2}$.

**Case 1** is obvious.

**Case 2:** 
$\Rightarrow$ If $G'$ has a clique of size $\frac{|V'|}{2}$, which means there is a clique of size $|V|-y$ in $G'$. Since the size of new added vertices is $|V|-2y$, thus there are at least $y$ vertices in $G$ which are subgraph of the this clique in $G'$. Since a subgraph of a clique is also a clique, we have found a clique of size $y$ in $G$.
$\Leftarrow$ If $G$ has a clique of size $y$, we just combine these clique with these new added $|V|-2y$ vertices, then we get a clique with size $\frac{|V'|}{2}$ in $G'$.

**Case 3:** 
$\Rightarrow$ If $G'$ has a clique of size $\frac{|V'|}{2}$, which means there is a clique of size $y$ in $G'$.  Since these new added vertices are isolated, this clique could only exist in the original graph $G$, thus we have found a clique of size $y$ in $G$.
$\Leftarrow$ If $G$ has a clique of size $y$, then this clique is also the clique with size $\frac{|V'|}{2}=y$ in $G'$.

Therefore, we could reduce clique problem to this problem, combining with the fact that we have proved this problem is NP, we conclude that it is NP-Complete.


## Problem (e)

We first prove this problem is NP. Obviously, there is a polynomial verifier which rejects all inputs if the problem is a no instance, and accept a poly size input if it's a yes instance. For example, a $\mathcal{T} \subseteq \mathcal{S}$ such that $\bigcup_{S \in \mathcal{T}} S=U$ and $|\mathcal{T}|=k$ is a ploy size input which could be accepted.

To prove it's NP-Complete, we reduce Vertex Cover problem to this problem.

For a instance $(G=(V,E),k)$ of Vertex Cover, we construct the instance $(U,\mathcal{S},k')$ as follows:
* Let $U$ contain $|E|$ elements corresponding to edges in $G$
* Let $\mathcal{S}$ contain $|V|$ elements. Element $i$ is the set consisting of edges which take $v_{i}$ as endpoint.
* Let $k'=k$

### Correctness

>[!note] We try to prove $G$ has a Vertex Cover of size $k$ if and only if there is a $\mathcal{T} \subseteq \mathcal{S}$ such that $\bigcup_{S \in \mathcal{T}} S=U$ and $|\mathcal{T}|=k'$.



$\Rightarrow$ If we find a $\mathcal{T} \subseteq \mathcal{S}$ such that $\bigcup_{S \in \mathcal{T}} S=U$ and $|\mathcal{T}|=k'$,  then it means all the edges in $G$ can be covered by the corresponding $k'$ vertices of $\mathcal{T}$, which means $G$ has a Vertex Cover of size $k'=k$.

$\Leftarrow$ If $(G=(V,E),k)$ has a Vertex Cover of size $k$, then we make $\mathcal{T}$ consisting of the sets corresponding to the $k=k'$ vertices in the cover, then we have $|\mathcal{T}|=k'$ and $\bigcup_{S \in \mathcal{T}} S=U$.

Therefore, we could reduce Vertex Cover problem to this problem, combining with the fact that we have proved this problem is NP, we conclude that it is NP-Complete.


## Problem (f)


We first prove this problem is NP. Obviously, there is a polynomial verifier which rejects all inputs if the problem is a no instance, and accept a poly size input if it's a yes instance. For example, a subcollection with sum exactly 0 is a ploy size which could be accepted.

To prove this problem is NP-Complete, we try to reduce SubsetSum+ problem to this problem. For a instance $(S=\left\{a_1, \ldots, a_n\right\},k)$ of SubsetSum+ problem, we construct the instance of this problem as $S'=S\cup \{ -k \}$.

### Correctness

>[!note] We try to prove $(S=\left\{a_1, \ldots, a_n\right\},k)$ is a yes instance of SubsetSum+  if and only if $S'=S\cup \{ -k \}$ is a yes instance of this problem.

$\Rightarrow$ If $S'=S\cup \{ -k \}$ is a yes instance of this problem, then there exists a subcollection of $S$ with sum exactly $k$, since $-k$ is the only negative number in $S'$.

$\Leftarrow$ If $(S=\left\{a_1, \ldots, a_n\right\},k)$ is a yes instance of SubsetSum+, then there exists subcollection $s$ of $S'$ with sum exactly $0$, by adding $-k$ to $s$.

Therefore, we could reduce  SubsetSum+ problem to this problem, combining with the fact that we have proved this problem is NP, we conclude that it is NP-Complete.

****

time spent: 2.5hr
score: 4

no collaborator



