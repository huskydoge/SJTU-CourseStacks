#算法 

[[Shortest Path|Shortest Path]] 中我们讨论了边权为正的情况，用[[Shortest Path#^89655f|Dijkstra]]算法。

>这一节我们研究边存在负权的问题

>Dijkstra算法很聪明，它利用了在无负边的图中，每个边在update中只会被用一次，而不会因为路径权值为负数被反复使用

![BellmanFord.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/BellmanFord.png)
![correctness.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/correctness.png)
