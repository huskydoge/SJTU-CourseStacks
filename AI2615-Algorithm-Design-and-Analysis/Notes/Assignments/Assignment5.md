## Problem 1
### a)
We could transform this problem into a maximum flow problem by following definition. We assign $\{ 1,2,3,\cdots,n \}$ to the left side, and $A_{1},A_{2},\cdots,A_{k}$ to the right side. If $i$ is in $A_{j}$, then there exists an edge from $i$ to $A_{j}$ with capacity $\infty$. Besides, we add the source $s$ and the end $t$ into the graph, and for each $i$, there exists an edge from $s$ to $i$ with capacity $1$, while for each $A_{j}$, there exists an edge from $A_{j}$ to $t$ with capacity $1$. 

Then the problem is equivalent to find the maximum flow of the graph and compare it with $k$: if equal, then $\mathcal{A}$ has a system of distinct representatives, otherwise not.


<img src="https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/IMG_143904227FDC-1.jpeg" alt="IMG_143904227FDC-1.jpeg" style="zoom:50%;" />

#### Correctness

Apparently, to find a system of distinct representatives, we are to find a maximum match between $\{ i \}$ and $\{ A_{j} \}$.

By the Integer property of maximum flow problem, since each $c(e)$ (exclude those $\infty$, which won't influence result) is an integer, we have the that the maximum flow $f_{max}$ is an integer, which means for any edge ending with $t$, its flow should be $1$ or $0$.

It's obvious that each flow represents a match strategy between $(i,A_{j})$: 
* given a match, for each $(i,A_{j})$ in it, we flow $1$ to the edge $(i,A_{j})$, and finally get a flow, whose value is equal to the size of the match.
* given a flow, for any edge $(i,A_{j})$ with a flow, we call it a match.

From the analysis above, we know the size of a match is equal to its corresponding flow, thus once we found the maximum flow, we get the maximum size of match. Then we check whether it's the size of $\mathcal{A}$, which is $k$. If equal, then $\mathcal{A}$ has a system of distinct representatives, otherwise not.

#### Time Complexity

We could use Dinic Algorithm to solve this problem. Actually, here the capacity of edges across two parts could also be deemed as $1$, because the flow source send to its joint vertex is at most zero. And in the worse case, every $i$ could belong to a certain $A_{j}$, then this problem is exactly the same with the special case we have analyzed in `Slides17-NetworkFlowRunningTime`, which has a time complexity of $O(|E| \cdot \sqrt{|V|})$.

To generate the graph, since we have $k$ sets and $n$ number, it costs $O(kn+k+n)$. The number of vertices is $k+n+2$, the number of edges is at most $kn+n+k$, thus we have the total time complexity is $O(kn+k+n)+O((kn+n+k)\sqrt{ k+n+2 })=O(kn\sqrt{ k+n })$, which is polynomial.


### b)

Similar to the construction of graph in (a), we still deem numbers $1,2,\cdots,n$ and $\{ A_{k} \},\{ B_{k} \}$ as vertices. For each $i$, if $i\in A_{j}$, then there is an edge $(i,A_{j})$, if $i\in B_{l}$, then there is an edge $(i,B_{l})$. All the edges's capacity is 1. By solving the maximum flow problem in this graph, we could check whether there exists a common system of distinct representatives of $\mathcal{A},\mathcal{B}$.



<img src="https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/IMG_A7F085A59AD6-1.jpeg" alt="IMG_A7F085A59AD6-1.jpeg" style="zoom:50%;" />


#### Correctness
A path from $s$ to $t$ represents a match $(A_{j},i,B_{l})$, which means $i$ can both represents $A_{j}$ and $B_{l}$. Since every edge has only 1 capacity, which means a vertex could be only matched once. The main goal is to check whether the maximum flow of the graph equals to $k$. If so, then it means there exists $k$ disjoint matches $(A_{j},i,B_{l})$, which implies that there exists a common system of distinct representatives of $\mathcal{A},\mathcal{B}$.

#### Time Complexity
We also use Dinic Algorithm to solve this problem. In this graph, there are $2k+n+2$ vertices and at most $2k+2kn$ edges. Construction of the graph costs $O(2k+2kn)=O(kn)$, thus the total time complexity is $O(kn)+O(|V|^2|E|)=O((2k+2kn)(2k+n+2)^2)=O(k^3n+k^2n^2+kn^3)$.

## Problem 2

### a)
This problem is similar to the conclusion we have already proved in `Slides17-NetworkFlowRunningTime`. However, here the graph is not bipartite, thus the 
vertex joint property no longer holds. 

However, to find the blocking flow still has the cost $O(E)$, since the capacity of each edge is one, that means in each iteration of Dinic each edge will only be visited once.

Let's see how many iterations we need to run. We try to prove that the number of iterations is at most $2\sqrt{ E }$.

#### Case 1
If the number of iterations is less or equal to $\sqrt{ E }$, then the proposition already holds.

#### Case 2
If the number of iterations we need is more than $\sqrt{ E }$.

We assume we have already run $\sqrt{ E }$ iterations and on the graph $G^f$. By the property of Dinic algorithm we have proved, we know $dist^{G_{f}}(s,t)\ge \sqrt{ E }$. 

Since there are at most $E$ edges, while each path from $s$ to $t$ has length larger than $\sqrt{ E }$, since every feasible path is disjoint(otherwise an edge should have a flow larger than 1), this implies that the maximum flow is at most $\frac{E}{\sqrt{ E }}=\sqrt{ E }$.

Since every iteration we will increase the flow at least by one, then we have at most $\sqrt{ E }$ iterations left.

Put those all together, we have the total time complexity $O(E\cdot2\sqrt{ E })=O(E^{3/2})$

### b)
Similarly, the time costs of finding blocking flow is still $O(E)$.

If $f$ reaches maximum flow within $2|V|^{2 / 3}$ iterations, then the total time complexity is $O\left(|V|^{2 / 3} \cdot|E|\right)$, obviously.

Let $f$ be the flow after $2|V|^{2 / 3}$ iterations of the algorithm. Let $D_i$ be the set of vertices at distance $i$ from $s$ in the residual network $G^f$. 

> We first try to prove that there exists $i$ such that $\left.\left|D_i \cup D_{i+1}\right| \leq|V|^{1 / 3}\right)$

We build the level graph on $G$. Since we have run $2|V|^{2 / 3}$ iterations, by the property of Dinic Algorithm, each $s$ to $t$ path has length at least $2|V|^{2 / 3}$, which means there are at least $2|V|^{2 / 3}$ levels, from level one to level $dist^{G^f}(s,t)$. We focus on the level $1,2,\cdots,dist^{G^f}(s,t)-1$. Then we have the inequality below:
$$\sum_{i=1}^{dist^{G^f}(s,t)-1}\mid D_{i} \cup D_{i+1} \mid=2\cdot(V-1)-D_{1}-1\ge (2V^{2/3}-1)x$$

Here the x is the average size of $\mid D_{i} \cup D_{i+1} \mid$. 1 and $D_{1}$ in $2\cdot(V-1)-D_{1}-1$ means the number of vertices in D1  and t itself have been counted only once. Then we have:
$$x=\frac{2V-D_{1}-3}{2V^{2/3}-1}\le V^{1/3} \iff V^{1/3} \le D_{1}+3 $$
**Here $D_{1}$ is the size of the first level set, which is also those vertices with distance 1 from s.**
#### Case 1
If $V_{1} < V^{1/3}$, then the flow out from $s$ is less than $V^{1/3}$ in $G^f$, which means the maximum flow is at most $V^{1/3}$, thus we just need to run at most $V^{1/3}$ iterations to get the maximum flow, which contradicts to the fact that we have run $2|V|^{2 / 3}$ iterations.

#### Case 2
If $D_{1} \ge V^{1/3}$, then $x\le V^{1/3}$. Since the average size of $\mid D_{i} \cup D_{i+1} \mid$ is less than $V^{1/3}$, then there should exist a $\mid D_{i} \cup D_{i+1} \mid \le V^{1/3}$ .

Then, we notice that every path from $s$ to $p$ should first reach at a point $d_{i}$ in $D_{i}$, and then reach at a point $d_{i+1}$ in $D_{i+1}$. Since the size of $\mid D_{i} \cup D_{i+1} \mid$ is less than $V^{1/3}$, we have at most $V^{1/3}\cdot V^{1/3}=V^{2/3}$ edges $(d_{i},d_{i+1})$ exists in $G^f$, which means there are at most $V^{2/3}$ $s$ to $t$ paths. (We should consider that for different $(d_{i},d_{i+1}),(d'_{i},d'_{i+1})$, the path go through them could possibly reunion after $D_{i+1}$, thus decreasing the number of $s$ to $t$ paths.)  This implies the maximum flow in $G^f$ is at most $V^{2/3}$. Thus we need only run at most $V^{2/3}$ iterations to reach the maximum flow. 

In this case, the time complexity is $O(3\cdot|V|^{2 / 3} \cdot|E|)=O(|V|^{2 / 3} \cdot|E|)$

**Combine all the cases above, we have proved that the total time complexity is $O\left(|V|^{2 / 3} \cdot|E|\right)$**




## Problem 3

### a)
In maximum matching problem, the degree of each vertex should no larger than 1, and should be an integer. 
We could describe maximum matching problem as:
$$\begin{array}{lll}\text { maximize } & \sum_{e \in(u, v)} y_e \\ \text { subject to } & \sum_{v \in N(u)} y_{(u, v)} \leq 1 \quad \forall u \in V \\ & 0 \leq y_{(u, v)},y_{(u, v)}\in \mathbb{N} & \forall(u, v) \in E\end{array}\tag{1}$$
 While in (a) , we relax this integer programming problem to LP-problem. Thus, its an LP-relaxation for the maximum matching problem.
### b)

The dual parameters are $x_{u},\forall u\in V$. Since an edge is shared by two vertices,  by comparing the coefficients in (1) , we have  $x_u+x_v \geq 1 , \forall(u, v) \in E$, and our goal is to minimize $\sum_{v \in V} x_v$. Thus the dual problem is:
$$
\begin{array}{lll}
\operatorname{minimize} & \sum_{v \in V} x_v & \\
\text { subject to } & x_u+x_v \geq 1 & \forall(u, v) \in E \\
& 0 \leq x_v \leq 1 \quad \forall v \in V
\end{array}
$$

Minimum vertex cover problem  is to choose minimum number of vertices to cover all the edges, thus for each edge, at least one of its two vertices should be included, thus we have $x_u+x_v \geq 1,\forall(u, v) \in E$. Here $x_{u}=1$ means we choose it, otherwise it should equal to zero. This is an integer program, while the dual problem above turn it into LP,  which means it's an LP-relaxation to the minimum vertex cover problem.

### c)
>[!definition] Unimodular
>If a matrix A is totally unimodular, then every square submatrix of A has determinant +1, -1 or 0. 

For a $1\times 1$ sub matrix of the incident matrix, its determinant is 1 or 0. Assume for any $k\times k$ sub matrix, its determinant is +1, -1 or 0, then we consider a $(k+1) \ \times (k+1)$ matrix $M$.

Since an edge corresponds to two vertices, in the incident matrix, a column has two 1. Therefore, the column of its submatrix has at most two 1. Thus we have cases as follows:

* Case 1: a column in $M$ which is all zero, then the determinant of $M$ is 0.
* Case 2: a column in $M$ has exactly one 1, with all other elements 0. Then by induction and Laplace Theorem, the determinant of $M$ is +1 or -1.
* Case 3: all the columns in $M$ have two 1. By the separability property of the bipartite graph, we could always divide $M$ into upper and lower two parts, where there is no column with two 1s in each part. Note that if there is a 1 in the upper part, then there should also be a 1 in the corresponding column of the lower part, meaning an edge exists across two vertex sets. Thus, we multiply all rows in the lower part with -1 and add all the rows (except the first row)  in $M$ to its first row, then we get a row with all zeros, which means we get a matrix with 0 determinant. Since elementary transformations do not change the reversibility of the matrix, we could conclude that the determinant of $M$ is 0.

Combining all cases above, we could conclude that induction holds, thus the proposition holds.


### d) 
By observation, we find the coefficients of the constraints in the LP of the maximum matching problem are exactly in the form of the incident matrix, as for any vertex $v\in V$, we sum the $v$ row of the incident matrix to check the bounds. And the coefficients of the constraints in the LP of the minimum vertex cover are exactly in the form of the transpose of the incident matrix. 

Since we have proved that the incident matrix is unimodular, obviously its transpose is also unimodular, which means both LP have integral optimal solution, according to the proved conclusion in `Slides19-ApplicationsOfLPDuality`.

Moreover, we can easily check that any if there exists a $y_{e}\ge 2$ in the solution of the LP-relaxation for the maximum matching problem, then it's not feasible, while if there exists a $x_{v}\ge 2$ in the solution of the LP-relaxation for the minimum vertex cover problem, then it's not optimal. Therefore, the optimal solution of them must satisfy $y_{e}\in \{ 0,1 \},x_{v}\in\{ 0,1 \}$.

Combine those analysis with (a) and (b), we could conclude that we have found the optimal solution to both maximum matching problem and minimum vertex cover problem. Since strong duality holds for LP problem, we have the optimal value of dual problem is equal to the optimal value of primal problem, thus we have proved the König-Egerváry Theorem.

### e)
The counterexample could be a triangle with vertices A, B and C. For vertex cover, we should choose at least two edges, while the maximum match is only one. We see that König-Egerváry Theorem doesn't hold here.


## Problem 4

### a)

>[!note]
>If there is pair of anti-parallel edges, we could always find an equal form of graph in the context of Maximum flow by adding some additional vertices, which is mentioned in `Slides15-NetworkFlow`. Thus we only consider the case when there is no pair of anti-parallel edges.

We could transform the original problem into a new NetFlow problem by assigning each edges in the original graph $G$ with capacity $c'_{e}=c_{e}-d_{e}$. Then we solve the maximum flow problem on this new graph $G'$. If there exists a feasible flow on the new graph, then we add each flow $f_{e}'$ with corresponding $d_{e}$ to make $f_{e}$. 

Since $0\le f'_{e}\le c'_{e}$, we have $d_{e}\le f'_{e}+d_{e}=f_{e}\le c_{e}'+d_{e}=c_{e}$, for each $e\in G,G'$.
>[!warning]
>However, this method will make some vertices lose **balance property**!  We should try to solve this problem.

We have noticed that each edge has a demand $d_{e}$, which implies a "necessary flow", thus for any edge $e\in G$, we could divide edge $u,v$ into two parts: 
>[!note] Definition
>1. **necessary edge**: with capacity $d_{e}$, which has to be filled.
>2. **free edge**: with capacity $c_{e}-d_{e}$.

Furthermore, we could add additional source vertex $x$ and additional end vertex $y$, where edge $(x,y)$ has **unlimited capacity**. Then we make every necessary edge $(u,v)$ transformed into $(u,x),(x,y),(y,v)$,where $(u,x)$ has capacity $d_{e}$ and $(y,v)$ also has capacity $d_{e}$. Then we remove the edge $(x,y)$ and add en edge $(t,s)$ with capacity $\infty$,  and take $y$ as new source vertex and $x$ as new end vertex. We run the max flow algorithm on the new graph, and judge whether each edge ending with $x$ is filled.

```pseudo
	\begin{algorithm}
	\caption{Determine the Existence of a Feasible Flow on Variant NetworkFlow}
	\begin{algorithmic}
	\INPUT original graph $G$,source $s$, end $t$
	\STATE add $(t,s)$ with $\infty$ capacity,add new source and end $x,y$
	\FOR{edge $e$ in $G/\{(t,s)\}$}
	\STATE set the capacity of $e$ to be $c_e-d_e$
	\STATE add $(u,x),(y,v)$ with capacity $d_e$
	\ENDFOR
	\STATE Run Dinic algorithm on new graph $G'$, where source is $y$ and end is $x$, to get the max flow
	\IF{every in-edge of $x$ is filled}
	\STATE there exists a feasible flow on variant NetworkFlow
	\ELSE
	\STATE there doesn't exist a feasible flow on variant NetworkFlow
	\ENDIF
	\end{algorithmic}
	\end{algorithm} 
```

<img src="https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/IMG_C2A18556833D-1.jpeg" alt="IMG_C2A18556833D-1.jpeg" style="zoom:80%;" />

>[!attention] 
>Here edge $(x,y)$ should be excluded when running max flow algorithm on new graph, or we could consider that $(x,y)$ is used only to illustrate the equality of solving the problem between the new graph and original graph.
#### Correctness
Actually, we have divided the original graph into two parts: a naive NetworkFlow graph, and a graph where each edge (except $(x,y)$) should be filled. If there exists a feasible flow in this variant problem, then it's enough to check whether those necessary edges are filled. If so, we could then recombine the necessary edges with corresponding free edges, then we get an edge with flow $f_{e}$ satisfying $d_{e}\le f_{e}\le c_{e},\forall e\in G$.

The reason we could add an edge $(t,s)$ with capacity $\infty$ is because that the source has no limit on output while the end has no limit on input. By doing this, we make the transform to a new NetworkFlow problem more formally.

And to check whether those necessary edges are filled, we could simply check whether all the in-edges of $x$ are filled, since the maximum flow into $x$ is equal to the maximum flow out $y$, which is guaranteed since we have set the capacity of $(u,x)$ and $(y,v)$ equal. If all the in-edges of $x$ are filled, then all the $out-edges$ of $y$ are also filled.

To check whether all the in-edges of $x$ are filled, we could run a max flow algorithm on the new graph setting source as $y$ and end as $x$, and compare the max flow we get with the sum of capacities of those in-edges of $x$ to judge whether there exists a 
feasible flow on variant NetworkFlow.

#### Time Complexity

To get new graph $G'$ costs $O(E)$, and the time complexity of Dinic algorithm is $O(V^{2}E)$, thus we have total time complexity $O(V^{2}E)$.







### b)
For clarity, we first give our algorithm.

```pseudo
	\begin{algorithm}
	\caption{Find a maximum feasible flow}
	\begin{algorithmic}
	\INPUT graph $G$
	\STATE first we run the algorithm in (a), to get all the "necessary" flow on the free edge $f'_{e}$ to fill necessary edge
	\STATE Delete added source and end $x,y$, and remove all related edges.
	\STATE Initialize a new graph $G'$ with all vertices in $G$
	\FOR{edge $e=(u,v)$ in original graph $G$}
	\STATE $f_e \leftarrow f'_e+d_e$ 
	\STATE add an edge $(u,v)$ with capacity $c_e-f_e$ and flow 0
	\STATE add an edge $(v,u)$ with capacity $f_e-d_e$ and flow 0
	\ENDFOR
	\STATE Run Dinic Algorithm on graph $G'$
	\FOR{edge $e=(u,v)$ in original graph $G$}
	\STATE $f_{(u,v)} \leftarrow f_{(u,v)}+f'_{(u,v)} - f'_{(v,u)}$
	\ENDFOR
	\RETURN The in-flow of $t$, which is the feasible max flow
	\end{algorithmic}
	\end{algorithm} 
```

<img src="https://p.ipic.vip/n3pe4k.jpg" alt="IMG_1D4BDFAC0CA5-1" style="zoom:80%;" />

#### Correctness

We call the flow on the free edge of graph $G'$ as $f_{e}$, and the flow on the original graph $G$ as $f_{e}$. 

After running the algorithm we designed in (a), we not only know whether there exists a feasible flow, we also have those flows on free edges changed to a state where all $f'_{e}$ satisfies $d_{e}\le f'_{e}+d_{e}\le c_{e}$, we let $f_{e}=f'_{e}+d_{e}$, then we get a feasible flow of original graph. 

However, this flow is not bound to be the feasible maximum flow, we need to leave the room for modification, which is why we add new edge $(u,v)$ and $(v,u)$. One for increasing $f_{e}$, while bounded by $c_{e}=c_{e}-f_{e}+f_{e}$. Another one for decreasing $f_{e}$, while at most decreasing $f_{e}-d_{e}$, to ensure the flow $f_{e}$ after modification is still larger than $d_{e}$.

Although the graph we get after running the algorithm in (a) may have multiple versions, they all satisfies that $d_{e}\le f'_{e}+d_{e}\le c_{e}$. Intuitively, we could get all the feasible flows of $G$ by designing some flows on $G'$ and then update $G$, which implies if we run the maximum flow algorithm on $G'$, if there exists edge ended with $t$ being updated, this implies that the flow on the free edge we choose is feasible, but not optimal, which could be modified to get a greater flow. (**Check the flow on the edges ended with $t$ is enough to get the value of the current flow!**). 

This further implies once the maximum flow on $G'$ is reached, then the corresponding flow on free edges $\{ f'_{e} \}$ ended with $t$ also represents the maximum flow on $G$. This is because that the vertices joint with the end vertex $t$ is fixed, and corresponding demand $d_{e}$ is also fixed. 
$$\max \sum_{e:\text{take $t$ as endpoint} }f_{e}=\max \sum_{e:\text{take $t$ as endpoint} }f'_{e}+d_{e}$$
Once we maximize the sum of those $f'_{e}$, then we get the feasible maximum flow on original graph $G$.
#### Time Complexity
* Run the algorithm in (a) costs $O(V^{2}E)$
* Get $G'$ costs $O(E)$
* Run Dinic Algorithm on graph $G'$ costs $O(V^{2}E)$
* Update $G$ costs $O(E)$

Thus, the total time complexity is $O(V^{2}E)$


*****
>[!bug] Feelings
>Score: 4
>Hours: 8hr


>[!important] Collaborators
>* 李佳鑫
>* 朱鹏翔
>* 周晟洋
>* 黄伊新

>[!Quote] Reference
>I have referred to https://blog.csdn.net/Regina8023/article/details/45815023 for Problem 4(a).