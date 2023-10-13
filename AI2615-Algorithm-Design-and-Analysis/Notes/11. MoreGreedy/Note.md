#算法 

>[!Atttention] 贪心算法的正确性基于：局部的贪心不会破坏整体最优的前提。

## Huffman Coding

>证明还是证明partial-OPT。假设不合并两个最小的，就可以进行交换，减少cost

### Refine
Huffman 的过程是从点中选两个权值和最小的点合并，然后把这两个点放入树中
1. Sorting
2. Tree Building

>每一次sorting都需要$n\log n$.如果用堆的话，那建堆之后的 popmin 都是$\log n$, 但是每次tree-building 也要 $\log n$

>[!Note] Surperise! 
>排序的过程我们没法优化了，但是tree-building我们可以用两个Priority-queue来优化建树的过程。
>
>* Q1是原来的节点，然后每次合并掉的点放在Q2里。对于一次合并，我们最多只需要check 4 个点。
>
>* 另外，新的节点在Q2中只会插入在尾部（这个性质很重要，分情况验证下就知道是对的）

## Makespan Minimization

### LPT Algorithm
* 最长处理时间的任务优先处理
* 把任务加入到最早进入空闲时间的机器上
>[!Warning] 但这个算法并不是最优的！
![ct.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/ct.png)


事实上，这个问题是一个NP-Hard 问题，我们的目标应该转化为分析它“有多差”
![a.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/a.png)
我们可以举出例子，说明这个bound=2是紧的！这是证明的重要方法！
>[!tips] 
>事实上，因为在pn之前执行的任务所需的时间都大于等于pn，所以$OPT\ge 2p_{n}$, 上面的bound可以变成$\frac{3}{2}$

> 我们实际上可以做的更好！。考虑不等式的两个方向，发现两个方向都对我们证明结论有利！
![conclusion.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/conclusion.png)
