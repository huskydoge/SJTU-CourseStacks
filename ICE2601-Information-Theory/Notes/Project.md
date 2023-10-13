#信息论 
## Word2Vec
Word2vec使用单个隐藏层，完全连接的神经网络如下所示。隐藏层中的神经元都是线性神经元。输入层设置为具有与用于训练的词汇中的单词一样多的神经元。隐藏图层大小设置为生成的单词向量的维度。输出图层的大小与输入图层相同。

因此，假设用于学习单词向量的词汇表由V个单词组成并且N为单词向量的维度(每个单词拥有N个特征)，则对隐藏层连接的输入可以由大小为VxN的矩阵WI表示，其中每行表示词汇单词。以相同的方式，可以通过矩阵WO来描述从隐藏层到输出层的连接大小为NxV。

![image.png](https://obsidian-1317758465.cos.ap-shanghai.myqcloud.com/images/20230513230400.png)

>[!cite] 参考
>1. [Word2Vec之CBOW](https://zhuanlan.zhihu.com/p/55983009)
>2. [一文看懂 Word2vec（基本概念+2种训练模型+5个优缺点）](https://zhuanlan.zhihu.com/p/84301849 )
>3. [word2vec模型训练保存加载及简单使用](https://blog.csdn.net/HUSTHY/article/details/103164934)
>4. [深度学习 - 38.Gensim Word2Vec 实践](https://bitddd.blog.csdn.net/article/details/129837715?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-2-129837715-blog-51472203.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-2-129837715-blog-51472203.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&utm_relevant_index=5)
>5. [word2vec中的数学原理详解](https://www.cnblogs.com/peghoty/p/3857839.html)


### SoftMax
https://zhuanlan.zhihu.com/p/55912929

### CBOW（连续词袋模型）

```pseudo
	\begin{algorithm}
	\caption{Gradient Update}
	\begin{algorithmic}
	\STATE e = 0
	\STATE $\mathbf{x}_w=\sum_{u \in \operatorname{Context}(w)} \mathbf{v}(u)$.
	\FOR{$j=2: l^w $}
	\STATE $q=\sigma\left(\mathbf{x}_w^{\top} \theta_{j-1}^w\right)$
	\STATE  $g=\eta\left(1-d_j^w-q\right)$
	\STATE $\mathrm{e}:=\mathrm{e}+g \theta_{j-1}^w$
	\STATE $\theta_{j-1}^w:=\theta_{j-1}^w+g \mathbf{x}_w $
	\ENDFOR
	
	\FOR{$u \in \operatorname{Context}(w)$}
		\STATE $\mathbf{v}(u):=\mathbf{v}(u)+\mathbf{e}$
	\ENDFOR
	\end{algorithmic}
	\end{algorithm} 
```



### NLLLOSS
[torch.nn.NLLLOSS](https://zhuanlan.zhihu.com/p/383044774)

## Incremental Huffman Tree Merging

* 可以计算一下和自适应编码进行性能对比
* 可以和Huffman编码比较下Greedy是多少倍的

>[!cite] 代码
>* https://github.com/retire2053/PoorWord2Vec
>* https://github.com/chikalabouka/INF8225-TP4/blob/master/word2vec.py
>* https://github.com/zirui-HIT/NLP_Model


## Some Models
[NLP index](https://index.quantumstat.com/#dataset)

[NLP dataset](https://github.com/niderhoff/nlp-datasets/blob/master/README.md)

http://mattmahoney.net/dc/text8.zip




## Pytorch Trick
[pytorch 自定义损失函数、优化器（Optimizer）和学习率策略（Scheduler）](https://blog.csdn.net/zhaohongfei_358/article/details/125759911)

[非叶张量和叶张量](https://blog.csdn.net/qq_42193790/article/details/127899520?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-127899520-blog-120164619.235^v35^pc_relevant_increate_t0_download_v2_base&spm=1001.2101.3001.4242.1&utm_relevant_index=1)

[求非叶节点的梯度](https://zhuanlan.zhihu.com/p/259167106)

[RuntimeError: a view of a leaf Variable that requires grad is being used in an in-place operation.](https://blog.csdn.net/hjxu2016/article/details/121303818?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-121303818-blog-126792752.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-121303818-blog-126792752.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&utm_relevant_index=2)

[a leaf Variable that requires grad has been used in an in-place operation](https://blog.csdn.net/jacke121/article/details/82733407?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPayColumn-1-82733407-blog-121303818.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPayColumn-1-82733407-blog-121303818.235%5Ev35%5Epc_relevant_increate_t0_download_v2_base&utm_relevant_index=1)
*****

对于word2vec的更新是NLP领域的一个问题，huffman树在其中有所应用。huffman树的编码最优性是我们已经熟知的结论，然而，当编码的字符存在更新的情况时，我们就不得不考虑最终码字长度与编码时间两个指标之间的trade-off。我们的论文研究了两种变化的huffman coding，adaptive huffman coding和incremental huffman coding
* 对adaptive huffman code与 huffman code的码字长度分析
* 对incremental huffman code与huffman code的码字长度分析（有论文提出这种算法，但是缺少相关的分析，并且没有提供相应的代码，我们对此进行了补充，并结合adaptive code 进行了分析）
* adaptive huffman code的性能分析
* 就连续词袋模型，adaptive 和 incremental还有朴素huffman三种方法的性能对比。（可能可以得到结论，当数据规模超过一定bound的时候，我们就切换优化方法，这样就可以设计一种算法，当然这是理想情况）

****
1. 更新Thetas和embedding的维度（要扩充）
2. 对于ada而言，要记录交换节点的训练样本重新训练。（最多能交换几次呢？）


Matplotlib整数x轴
https://blog.csdn.net/qq_36170511/article/details/115525728


Latex Theorm不编号：
方案如下：使用\usepackage{amsthm}宏包，然后\newtheorem*{theorem}{定理} 这样定义的定理是没有编号的。



还有一个点就是对于在其中的单词，它不考虑权重的更新，这明显不对。