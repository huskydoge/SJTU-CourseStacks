


## Problem 1
We denote the input string as $s$, its i-th character as $s[i]$ (here index is zero based). And we use $d[i,j]$ to denote the length of longest palindrome between $s[i]$ and $s[j]$. 

Apparently, if $i=j$, then $d[i,j]=1$. If $i>j$, we stipulate $d[i,j]=0$.

Let $s_{i}s_{i+1}s_{i+2}\cdots s_{j}$ ($i<j$) be a string., we have state transition equation as follows:
* if $i>j$, $d[i,j]=0$
* if $i=j$, $d[i,j]=1$
* if $i<j$:
	* if $s[i]=s[j]$, $d[i,j]=2+d[i+1,j-1]$
	* if $s[i]\neq s[j]$, $d[i,j]=\max \{ d[i,j-1],d[i+1,j] \}$


### Correctness
If we want to find the longest palindrome subsequence of it, there are two cases we need to consider:
1. $s[i]=s[j]$. If so, then we could turn the problem into finding the longest palindrome subsequence of , since for  $s_{i+1}s_{i+2}\cdots s_{j-1}$'s  longest palindrome subsequence $s'$,    $s_{i}s's_{j}$ should be the longest palindrome subsequence of $s$, otherwise there should be a palindrome subsequence $s''$ of  $s_{i}s_{i+1}\cdots s_{j-1}$ with longer length than $s'$, which leads to contradiction.
2. $s[i]\neq s[j]$. Then we could divide the problem into two subproblems: find the longest palindrome subsequence among $s_{i}s_{i+1}\cdots s_{j-1}$ and $s_{i+1}s_{i+2}\cdots s_{j}$, then choose the longer one as the longest palindrome subsequence (If two have equal length, then just randomly pick one).

By induction, we could obviously always maintain the correctness of the algorithm.

>[!attention]  
>Here we should traverse it in diagonal order, from top left to bottom right.

If we want to store the longest palindrome subsequence, we need another matrix $c$,where $c[i][j]$ store the longest palindrome subsequence between $s[i]$ and $s[j]$. 

Algorithm is shown as follows:
```pseudo
	\begin{algorithm}
	\caption{find the longest palindrome}
	\begin{algorithmic}
	\INPUT a string $s$ and its length $n$
	\OUTPUT the longest palindrome $s'$ that is a subsequence of $s$
	\STATE $“” \leftarrow s'$
	\STATE $1 \leftarrow max$
	\FOR{$i\leftarrow 1$ to $n$}
		\FOR{$j\leftarrow 1$ to $n$}
		\IF{$i\neq j$}
			\state $d[i,j]=0$
			\STATE $c[i,j]=“”$
		\else 
			\state $d[i,j]=1$
			\STATE $c[i,j]=s[i]$
		\ENDIF
		\ENDFOR
	\ENDFOR
	\STATE
	\FOR{$k \leftarrow 1$ to $n$}
	\FOR{$i\leftarrow 1$ to $n-k$}
	\IF{$s[i]=s[i+k]$}
		\STATE $d[i,i+k]=2+d[i+1,i+k-1]$
		\STATE $c[i,i+k]=s[i]+c[i+1,i+k-1]+s[i+k]$
		\else
		\IF{$d[i,i+k-1]>d[i+1,i+k]$}
		\STATE $d[i,i+k]= d[i,i+k-1]$
		\STATE $c[i,i+k]=c[i,i+k-1]$
		\else
		\STATE $d[i,i+k]= d[i+1,i+k]$
		\STATE $c[i,i+k]=c[i+1,i+k]$
		\ENDIF
	\ENDIF
	\IF{$d[i,i+k]>max$}
		\STATE $max=d[i,i+k]$
		\STATE $s'=c[i,i+k]$
	\ENDIF
	\ENDFOR
	\ENDFOR
	\STATE
\PRINT $s'$



	\end{algorithmic}
	\end{algorithm} 
```

### Correctness
The **correctness** of the algorithm has been demonstrated in the statement before the pseudo-code by splitting the optimal solution into the optimal solution of a smaller problem.

### Time Complexity
By observing the times of loop, we can easily conclude that its time complexity is $O(n^{2})$, where $n$ is the length of the input string $s$.

****
## Problem 2

Let $f(i,j)$ denote whether there are two sets $A$ and $B$ that don't intersect satisfying the sum of $A$ is $i$ and the sum of $B$ is $j$.  We initialize $f(0,0)=true$.

The transition equation is as follows:

>If $f(i,j)==True$,  then $f(i+a_{k},j)$ is True for those $a_{k}$ that haven't been used.

The main problem here is how to design a topological order to guarantee that $a_{k},k=1,2,3,\cdots,n$ won't be used twice in the procedure of getting $f(i,j)$. The topological designed is shown in the below algorithm:

```pseudo
	\begin{algorithm}
	\caption{3-PARTITION problem}
	\begin{algorithmic}
	\INPUT Integers $a_1,a_2,\cdots,a_n$ which are given
	\OUTPUT Whether there exists a 3-PARTITION of them
	\STATE Initialize: $f(0,0)\leftarrow True,sum\leftarrow \sum\limits_{i=1}^n a_i$
	
	\FOR{$i=1$ to $n$}
		\FOR{$k=0$ to sum}
			\FOR{$j=sum-k$ to $sum$}
				\IF{$f(j-sum+k,j)$ is True}
				\STATE $f(j-sum+k+a_i,j)=True,f(j-sum+k,j+a_i)=True$
				\ENDIF
			\ENDFOR
		\ENDFOR
	\ENDFOR 
	\STATE
	\IF{$f(sum/3,sum/3)==True$}
	\PRINT "Yes" 
	\else
	\PRINT "No"
	\ENDIF
	\end{algorithmic}
	\end{algorithm} 
```

### Correctness
In this topological order, every $a_{k}$ will only be used in one outside loop, and inside this loop, we traverse the matrix by such diagonal traversal order, which gurantee that points that are updated in the current loop won't be used in this loop again, eliminating the possibility of a certain $a_{k}$ being used twice. By checking "$f(j-sum+k+a_i,j)=True,f(j-sum+k,j+a_i)=True$", we can see only the point on the top right of the diagonal will be updated.

![dia.png|500](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/dia.png)


Then if we have $f(sum/3,sum/3)==True$, then there exist two non-intersect sets whose sum are $\frac{sum}{3}$. Obviously, the remaining part of $a_{1},a_{2},\cdots,a_{n}$ is also a set whose sum is $\frac{sum}{3}$, meaning that 3-parition exists.
### Time Complexity
From the structure of loops, we know the total time complexity is $O(\sum a_{i}\cdot \sum a_{i} \cdot n)$.


****
## Problem 3

>Firstly, the graph may not be connected. We should first run a DFS starting from $s$ and exclude all the vertices that are not visited from the graph.


Let $f(S,v)$ denote the the shortest path from s to 𝑣 , with inter-vertex exactly $S \subset V$.  **<mark style="background: #FFF3A3A6;">(don't need to exclude s and v, since visiting an edge multiple times is permitted)</mark>**

Then the transition equation is:
$$f[S, v]=\min _{t \in S} \{f[S-\{t\},  t]+d(t, v)\}$$

Which is obvious, since if we want to go from s to v, with inter  inter-vertex exactly $S \subset V$, there must exists an edge (t,v) where $t\in S$, we just minimize the cost by  $\min _{t \in S} \{f[S-\{t\},  t]+d(t, v)\}$ is enough. Here $d(t,v)$ is the edge cost of edge $(t,v)$,(if exists, otherwise $\infty$)

Detailed algorithm is as follows:
```pseudo
	\begin{algorithm}
	\caption{Modified TSP}
	\begin{algorithmic}
	\INPUT a connected graph G=(V,E,c) with n vertices, and c is the cost of each E
	\OUTPUT  the shortest path cost cover all vertices in G(if exists), which starts from $s$ and ends at $s$
	\STATE 
	\FUNCTION{TSP}{G=(V,E,c) }
	\STATE Initialize: $f(S,v)\leftarrow \infty,f(\emptyset, v) \leftarrow 0, \forall v, S\neq \emptyset$
	\FOR{$i=1$ to $n$}
		\FOR{$S\subseteq V$ and $|S|=i$}
		\FOR{$v \in V$}

				\STATE $f[S, v]=\min _{t \in S} \{f[S-\{t\},  t]+d(t, v)\}$

		\ENDFOR
		\ENDFOR
	\ENDFOR
	\STATE 
	\RETURN $f(V,s,s)$
	\ENDFUNCTION
	\end{algorithmic}
	\end{algorithm} 
```

Then for all possible $2^n$ subgraphs $U$ of original graph, we calculate $$\min_{U\subset V} \{ \sum_{v \in U} p(u)- TSP(U)\}$$
to output the answer.

### Correctness

The correctness of Modified TSP is given by the derivation procedure of transition equation, for simplicity, here we won't use induction to show its correctness again.

The topological order we designed here is based on the observation that the $f(S_{1},v)$ with larger set $S_{1}$ will depend on the smaller set $S_{2}$, and all its vertices.

Obviously, the optimal solution could be viewed as a subgraph of original graph, which has a path starting from $s$ and ends at $s$ and cover all the vertices in it, which is similar to a TSP problem, except that its edges and vertices can be visited multiple times.

By checking all the subgraphs of $G$, we compare all the possible cases, which enables us to find the optimal solution.

### Time Complexity

Modified TSP:  we traverse all subsets of $G$, and for every set $S$, we traverse all the vertics in $V$ and then traverse all the vertices in $S$ to get $\min _{t \in S} \{f[S-\{t\},  t]+d(t, v)\}$. Thus we have the time complexity of $O(n^22^n)$

If we checking all the subgraphs, then the total time comlexity is $O(2^{n}(n^22^{n}))\le O(8^n)$, which is exponential and satisfies the requirement. 


****
## Problem 4

### (a)
>[!note] Definition
Let $s[i]$ denotes the maximum (1, 1)-step subsequence ended with $a_{i}$. 


Since $L=R=1$, we have the subsequence is consecutive, then we could have transition equation as follows:
$$s[i]=\max \{ a_{i} , s[i-1]+a_{i}\} $$


>[!attention] 
>For all $i\le 0,s[i]=0$

>[!note] Simplification
>For simplification, we assume here $s[i]$ is the value of such sequence.
>
>**if we want to output the corresponding $a_{i}$ in this sequence, we only need to record the second-to-last integer in each s[i], then we could trace back the corresponding $\{ a_{i} \}$ sequence and output it.**
>
>**Therefore we won't specifically include this part in our algorithm in problem (a),(b) and (c)**

#### Correctness
We prove it using induction.
* when $i=1$, then $s[1]=\max \{ a_{1} , s[0]+a_{1} \}=a_{1}$, the correctness holds.
* assume for all $i<k$, the correctness holds.
* when $i=k$, $s[k]$ is either $a_{k}$ or $s[k-1]+a_{k}$, which means the maximum (1, 1)-step subsequence ended with $a_{k}$ is either $a_{k}$ or the sum of $a_{k}$ and the maximum (1, 1)-step subsequence ended with $a_{k-1}$, which is required by its consecutive property.  Intuitively, the correctness still holds.

Thus, we have proved the correctness always holds throughout the procedure of the algorithm.
#### Time Complexity
Since $s[i]$ only depends on $s[i-1]$ and $a_{i}$, which means there is no loop inside a loop. By traversing $i$ from $1$ to $n$, with each step a constant cost, we could get all those $s[i]$, which is $O(n)$. Then we scan through $s[i]$ again to get the maximum (1, 1)-step subsequence., which is $O(n)$

Altogether, the time complexity is $O(n)$

### (b)
Here $L,R$ is no longer 1, which means the subsequence is no longer consecutive, but we could use the same idea in (a). We will use the same notation in (a) below.

We need to modifiy the transition equation as follows:
$$s[i]=\max \{ a_{i} , a_{i}+\max_{i-R\le t \le i-L}s[t]\} $$

#### Correctness
We prove it using induction.
* when $i=1$, then $s[1]=\max \{ a_{1} , a_{1}+\max_{1-R\le t \le 1-L}s[t]\}=a_{1}$, correctness holds.
* assume for all $i<k$, the correctness holds.
* when $i=k$, $s[k]$ is either $a_{k}$, or the maximum of those maximum (L, R)-step subsequences ended with $a_{t}$ where $L\le k-t\le R$. We should choose the larger one, which is equivalent to: $s[k]=\max \{ a_{k} , a_{k}+\max_{k-R\le t \le k-L}s[t]\}$, the correctness holds.

Thus, we have proved the correctness always holds throughout the procedure of the algorithm.

#### Time Complexity
Different from (a), here we have a $R-L$ steps inner iterations, which means we have a time complexity of $O((R-L)n)$.

Since $R-L\le n-1 <n$, we have $O((R-L)n)=O(n^2)$ in the worst case, that is, the time complexity is $O(n^{2})$

### (c)

As applied in the lecture "More Dynamic Programming", we could use a priority queue to store the potential largest list (PLL), which consists of the potential $s[t]$ to participate in comparison. We give algorithm as follows:
```pseudo
	\begin{algorithm}
	\caption{Find max (L, R)-step subsequence}
	\begin{algorithmic}
	\INPUT a sequence of integers $a_1,a_2,\cdots,a_n$
	\OUTPUT max (L, R)-step subsequence of this sequence
	\STATE
	\STATE Initialize a deque PLL
	\STATE
	\FUNCTION{UPDATE}{i}
	\WHILE{$PLL.front.index<i-R$}
		\STATE PopFront(PLL)
	\ENDWHILE
	\WHILE{$PLL.back.value\le s[i-L]$}
		\STATE PopBack(PLL)
	\ENDWHILE
	\RETURN $PLL.front$
	\ENDFUNCTION
	\STATE 
	\FOR{$i=1$ to $n$}
		\STATE s[i]=$\max \{a_i,UPDATE(i) +a_i\}$
	\ENDFOR 
	\STATE
	\PRINT $\max_{i=1}^n s[i]$
	\end{algorithmic}
	\end{algorithm} 
```

#### Correctness
The main idea is as same as in (b), while the main problem here is how to simplify the computation of $\max_{1-R\le t \le 1-L}s[t]$ to turn $O(n^2)$ into $O(n)$.

By using PLL, we just simplify the procedure of $$s[i]=\max \{ a_{i} , a_{i}+\max_{i-R\le t \le i-L}s[t]\}$$ 
to 
$$s[i]=\max \{ a_{i} , a_{i}+UPDATE(i)\}  ,$$
which is euivalent since $UPDATE(i)=\max_{i-R\le t \le i-L}s[t]$. 

Therefore,  we could use the induction proof exactly the same as in problem (b).
#### Time Complexity
We know from the lecture that the total updating procedure has a time complexity of $O(n)$. And the loop has a time complexity of $O(n)$. The operation $\max_{i=1}^n s[i]$ is also $O(n)$.

Thus, the total time comlexity is $O(n)$

*****
## Problem 5
Time Spent: 10hr

Score: 4

Collaborator: 李佳鑫，朱鹏翔，李禛，黄伊新, 郑普嘉