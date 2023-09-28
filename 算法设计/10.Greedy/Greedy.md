#算法 

>[!info] 问题引入：写作业问题
>每个大学生都有好多好多作业，自然也有好多好多ddl。面对这些ddl，我们该如何规划作业计划呢？

>###  Formalize问题
>如果我们有 n 个作业，每个作业 $j$ 的规模是$s_{j}$ (需要花费$s_{j}$天完成)，对应的ddl是$d_{j}$

<mark style="background: #FFB86CA6;">贪心算法</mark>   我们每次都完成ddl最近的作业

**最优性：** 我们只需证明，如果这种方法无法完成作业，那么其他任何方法都无法完成作业。
>[!note] Proof:
>![hw.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/hw.png)
>
>如果贪心算法下，对于某个$h_{j}$无法在ddl前完成任务，那么我们将没有办法通过调整顺序的方法成功完成 $h_{k},k=1,2,\cdots,j$
>* 首先，$h_{k},k=1,2,\cdots,j$都需要排在$d_{j}$的右边，所以我们不能通过将$h_{k},k=1,2,\cdots,j$与之后的作业调换的方法达成目标。
>* 那 $h_{k},k=1,2,\cdots,j$的和就一定超过$d_{i}$

接下来我们进入正题～



## Minimum Spanning Tree (MST)
>Input：一个连通无向图
>
Output：生成树，边集的子集，让权值最小

![con.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/con.png)
>[!Note]
>证明Prim算法正确性的关键是证明当前的T是Partial-MST，即它是complete MST的一部分。

![Prim.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/Prim.png) ^357bc9

* V-round popmin
* E-round update
$$O(V\log V+E)$$
使用[[Shortest Path#^464b90|Fibonacci Heap]]
### Kruskal
![K.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/K.png)
#### Correctness
>[! Notes] 
>#todo

#### Refine
>在算法过程中，如果我们把已经连在一起的点视作一个Group，那何时会出现circle？
>
>答：有一条边连接<mark style="background: #ABF7F7A6;">已经在</mark>同一个group里的两个点！

![kr.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/kr.png)

### Union-find Set
> 为了优化Kruskal算法。Kurskal算法过程中，组不断扩大，我们要能够尽可能快的合并组，同时也要控制查找时间，也就是树的高度

![rank.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/rank.png)

>[!Warning] 注意
>这种合并方法下，要得到一个rank=k的树，至少需要$2^k$个nodes！这种合并方式是不允许出现一条长为k的链的情况的！
>![2k.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/2k.png)

### Path-Compression
>思想：We put every red vertex to the first level. 这样下次find就会轻松很多

#### Rank
1. Parent Rank is strictly larger than its child
2. The tree of v has at least $2^{rank[v]}$ nodes

#### How we group
![group.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/group.png)


#### Same Group Charging （SGC）
> Focus on how many vertices in a same group

#### Across Group Charging （AGC）
> Focus on how many different Groups there


> $\log_{*}(n)$