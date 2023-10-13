
# 4. Selection Overview
#算法 

 > [!important] 目标：从一个数组中选出第k小的数字。
 
 *Divider And Conquer*
 > [!Note] 核心思想：
 > 选定一个pivot，然后根据这个pivot把数组分成L，M，R三个部分，对三个部分确定一个子问题。
 > ![截屏2023-04-13 22.58.28.png|inline|600](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2022.58.28.png) ![s|inline|700](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2023.00.41.png)
 
 如果不做任何优化，上面这个算法的代价是$n^2$
 ### 随机算法
 随机选一个Pivot。
 
如果我们幸运的将pivot落在了中间1/2的部分，那么:
$$T(n)=T(\frac{3n}{4})+O(n)$$
根据[[MergeSort&CountInversion#Master Theorm|主定理]]，$T(n)=O(n)$. 
那么我们考虑不够lucky的情况又该如何呢？

![截屏2023-04-13 23.39.45.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/%E6%88%AA%E5%B1%8F2023-04-13%2023.39.45.png)

>[!important] 对于随机算法，运行时间我们应该用期望来衡量！

#### Good Pivot： Median of medians
> 如何寻找一个好的pivot？
1. 把数组按照size=5进行划分: $O(n)$
2. 找到每个组（size=5）里的中位数 $O(n)$
3. 找到n/5个中位数里的中位数 $T(n/5)$

>[!important] 我们的pivot好到什么程度了呢？
>我们有n/5个medians，而我们的pivot是它们的中位数，所以它大于n/10个pivot，每个pivot又大于至少2个数，所以它一共大于3n/10个数。
>同理，它也一定小于3n/10个数。
>
>于是我们的pivot将递归式至少优化为：
>$$T(n)=T(n-3n/10)+O(n)+T(n/5)$$

如何分析上面这个递归式的Running Time呢？
>[!Bug] 不能带着Big-O表示法来进行Induction！我们要考虑常数的代价！
>如果我们这样证明：$$T(n)=O(n)+O(n)+O(n)=O(n)$$我们就忽略了$O(n)$前含有的常数，对于不同的n，$T(n)=O(n)\le C_n n$, 这里的常熟$C_n$随着递推的进行会变得和n有关！所以是错误的！

![induction.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/induction.png)
