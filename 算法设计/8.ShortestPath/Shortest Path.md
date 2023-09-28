#算法 

## 单源最短路 Single Source Shortest Path

>Shortest Path Tree(SPT): 最短路的并集
### 边权为1
* Input: A directed graph 𝐺 (𝑉,𝐸), represented by an Adjacent List, and a source vertex 𝑠 .
* Output: Distance 𝑑 ( 𝑠 , 𝑣 ) , for all 𝑣 ∈ 𝑉 .

用BFS即可

### 边权不为1
* Input：Weight/Distance: 𝑤(𝑢 , 𝑣) ≥ 0 for each edge 

<mark style="background: #FFB86CA6;">Dijkstra Algorithm</mark> ^89655f

![di.png|800](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/di.png)

Time Complexity: $O(V^{2}+E)$
> 我们可以用堆进行优化！

#### Heap Reiview

![fib.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/fib.png)



#### Fibonacci Heap*

^464b90

1. update，进入一个新的节点，如果它比根小，那就要进行更新
2. pop min，从藤上取下当前最小的点，然后更新heap

为了减少更新代价：
* 控制所有根中的max degree
	* 我们想要每一个兄弟节点之间，一个degree只有一个“根”
	 >claim：一个度数为k的根至少有$2^{k}-1$个后代（图中数字代表度数）
	 >![good.png|600](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/good.png)

* 控制藤上原来有的根的数量

>[!Warning] 更新的时候如何保证不破坏原来的good性质呢？
>规定：每次更新，对于非根节点，只允许失去最多一个孩子<mark style="background: #FF5582A6;">（注意这里说的是孩子而不是后代！）</mark>
>![update.png|600](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/update.png)

具体到更新方法就是 Cascading Cut，但是这会让藤上的根的数量太多，导致t变大，进而导致pop min的代价变大。
>[!note] 好消息
>但我们可以do something good for the future，在这次pop的时候，顺便也把藤上的根整理一下，merge一下。
>![merge.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/merge.png)
>![gd.png|](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/gd.png)


Time Complexity
* Cascading Cut
* pop min

Still $O(t+D)$, t可能是n

## 均摊分析 Amortized Analysis 
>[!Important] 重要思想
>一个当前情况下似乎很简单的行为（时间复杂度小），可能使将来的某个行为代价增加！不公平！


real cost：$\sum c(p_{i})$，这里的 $p_{i}$ 的操作是可以重复的。

amortized: $\sum c(p_{i}) \le k_{1}\hat{C}(P_{1})+k_{2}\hat{C}(P_{2})$, 如果操作只有两种类型。

Potential Function: $\Phi,\Phi_{0}$代表状态0.

$$\sum \hat{C}\ge \sum C + \Phi\delta$$


<img class="custom" src="https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/sk.png" > </img>


![ar.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/ar.png)
> 每一层（这里是藤）一个degree的根只有一个，我们max degree是D，而D等于$\log_{n}$