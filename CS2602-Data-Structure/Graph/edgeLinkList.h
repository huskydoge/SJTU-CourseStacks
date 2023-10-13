//
// Created by 黄奔皓 on 2022/12/29.
//

#ifndef 图_EDGELINKLIST_H
#define 图_EDGELINKLIST_H

#define DefaultNumVertex 20
class outOfBound{};
template <class edgeType>
struct edgeNode
{
    int dest; // 该边指向的顶点在verList中的下标
    edgeType weight;
    edgeNode *link; // 邻接表中的下一个
};
template <class verType, class edgeType>
struct verNode
{
    verType data;
    edgeNode<edgeType> *adj;
};

// ** Prim算法
// 程序中，外循环体每执行一次找到一个选择点，共执行n-1次。
// 外循环体内有两个串行操作：
// 沿着当前选择点遍历其边表一遍，当整个外循环执行完毕时共访问边e次，总时间消耗为n+e。
// 在U中选择dist最小的顶点，时间消耗为n，当整个外循环执行完毕时共访问边𝑛^2次，总时间消耗为𝑛^2。
// 故Prim算法的时间复杂度为O(𝑛^2 )。
template <class edgeType>
struct primNode
{
    int from; //边的一个邻接点
    int to;   //边的另外一个邻接点
    edgeType weight; //边的权值
};
template <class verType, class edgeType>
void Graph<verType, edgeType>::Prim()const
{
    int *source;  //记录源顶点
    edgeType *dist; //记录顶点到U集合中的距离
    bool *selected; //记录顶点是否已经到U中
    primNode<edgeType> *treeEdges; //最小生成树中的边
    edgeType sum; //最小生成树的权值和
    int cnt; //记录集合U中顶点的个数
    int min; //选出当前W中离集合U最短的顶点下标
    int i, j, selVert;
    edgeNode<edgeType> *p;
    //创建动态空间
    source = new int[verts];
    dist   = new edgeType[verts];
    selected = new bool[verts];
    treeEdges = new primNode<edgeType>[verts-1]; // 最小生成树中的边最多n-1条
    //初始化
    for (i=0; i<verts; i++)
    {
        source[i]=-1;
        dist[i]=9999; //用一个很大的值表示无穷大
        selected[i] = false;
    }
    //选中一个顶点
    selVert = 0;
    source[0]=0;
    dist[0] = 0;
    selected[0]=true;
    cnt=1;
    while (cnt<verts)
    {
        //检查selVert的所有仍在W中的邻接点，如有需要更新它的信息
        p = verList[selVert].adj;
        while (p)
        {
            if (!selected[p->dest]&&(dist[p->dest] > p->weight))
            {
                source[p->dest] = selVert;
                dist[p->dest] = p->weight;
            }
            p = p->link;
        }
        //选择W中离U最近的顶点，即dist最小的值
        for (i=0; i<verts; i++)
            if (!selected[i]) break;
        min = i;
        for (j=i+1; j<verts; j++)
            if (!selected[j] && dist[j]<dist[min]) min = j;
        //将最近的顶点并入U,并将对应的边并于最小生成树
        selVert = min;
        selected[min] = true;
        treeEdges[cnt-1].from = source[min];
        treeEdges[cnt-1].to = min;
        treeEdges[cnt-1].weight = dist[min];
        cnt++;
    }
}
// ******************************************************************************************

// ** Dijkstra算法
template <class edgeType>
struct DijkstraNode
{
    int source; //当前最短路径上前一顶点
    int dist;   //当前最短路径距离
    bool selected;
    //顶点是否已经在S中的标志
};
template <class verType, class edgeType>
void Graph<verType, edgeType>::Dijkstra (verType start) const
{
    DijkstraNode<edgeType> *DList;
    int i, j, startInt;
    int cnt; //记录集合U中顶点的个数
    int min; //选出的当前离集合最短的顶点
    int dist;
    //查找起始点下标
    for (i=0; i<verts; i++)
        if (verList[i] == start)   break;
    if (i==verts) return;
    //创建空间并初始化DList[i]数组
    startInt = i;
    DList = new DijkstraNode<edgeType> [verts];
    for (i=0; i<verts; i++)
    {
        DList[i].source = -1;
        DList[i].dist = noEdge;
        DList[i].selected = false;    }//从下标为startInt的点开始
    min = startInt;
    cnt = 1;
    DList[startInt].source = startInt ;
    DList[startInt].dist = 0;
    DList[startInt].selected = true;
    while (cnt<verts)
    {
        //根据min顶点发出的边，判断是否修正相邻顶点的最短距离
        for (j=0; j<verts; j++)
        {
            if (edgeMatrix[min][j]==0) continue;       //对角线元素
            if (DList[j].selected) continue;                 //已经加入集合S
            if (edgeMatrix[min][j]==noEdge) continue;      //无边
            if (DList[min].dist+edgeMatrix[min][j]<DList[j].dist)
            {
                DList[j].dist = DList[min].dist+edgeMatrix[min][j];
                DList[j].source = min;
            }
        }
        //搜索当前距离标签最小的顶点
        min = -1;     dist = noEdge;
        for (i=0; i<verts; i++)
        {
            if (DList[i].selected) continue; // 已经在集合S中了，我们要选的是 V-S
            if (DList[i].dist < dist) {
                min = i; dist = DList[i].dist;
            }
        }
        //此时min一定为某个顶点的下标，如果仍然为-1表示该无向图不连通
        //将顶点min加入集合S
        cnt++;
        DList[min].selected = true;
    }   //如果图用邻接矩阵来存储，可以看出时间复杂度为O(𝑛^2 )。
}
// ******************************************************************************************

// ** Floyd算法
template <class verType, class edgeType>
void Graph<verType, edgeType>::Floyd()const
{
    int i,j,k;
    edgeType **A;  // 数组A[i][j]记录顶点i到j间的最短距离
    int **pre;     // 数组pre[i][j]记录顶点对i到j的最短路径中的中介顶点，
    //创建动态数组floyd和path
    A = new edgeType *[verts];
    pre = new int*[verts];
    for (i=0; i<verts; i++)
    {
        A[i]= new edgeType [verts];
        pre[i] = new int[verts];
    }
    //初始化数组floyd和path
    for (i=0; i<verts; i++)
        for (j=0; j<verts; j++)
        {
            A[i][j]= edgeMatrix[i][j];
            pre[i][j] = -1;
        }
    //迭代计算A数组
    for (k=0; k<verts; k++)
    {
        for (i=0; i<verts; i++)
        {
            if (i==k) continue; //避开加A[i][i]
            for (j=0; j<verts; j++)
            {
                if ((j==k)||(j==i)) continue;//避开加A[j][j]和A[i][i]
                if (A[i][j]>(A[i][k]+A[k][j]))
                {
                    A[i][j]=A[i][k]+A[k][j];
                    pre[i][j]=k;
                }
            }
        }
    }
// ******************************************************************************************

template <class verType, class edgeType>
class Graph
{
private:
    bool directed;      //有向图为1，无向图为0
    int verts, edges;     //图的实际顶点数和实际边数
    int maxVertex;      //图顶点的最大可能数量
    verNode<verType,edgeType> *verList;   // 保存顶点数据的一维数组
public:
    //初始化图结构g，direct为是否有向图标志，e为无边数据
    Graph(bool direct);
    ~Graph();
           int numberOfVertex()const{ return verts; }; // 返回图当前顶点数
    int numberOfEdge()const{ return edges; }; // 返回图当前边数
    int getVertex(verType vertex)const; //返回顶点为vertex值的元素在顶点表中的下标
    bool existEdge(verType vertex1,verType vertex2)const; //判断某两个顶点间是否有边
    int getFirstNeighbor(verType vertex ) const;
//返回顶点vertex1的相对vertex2的下一个邻接点，如无下一个邻接点返回-1
    int getNextNeighbor(verType vertex1, verType vertex2)const;
    void disp() const; //显示邻接矩阵的值

    void insertVertex(verType vertex ); //插入顶点
    void insertEdge(verType vertex1, verType vertex2, edgeType edge); //插入边
    void removeVertex(verType vertex);  //删除顶点
    void removeEdge(verType vertex1, verType vertex2); //删除边
    //返回顶点vertex的第一个邻接点,如果无邻接点返回-1
};
//初始化图结构g，direct为是否有向图标志
template <class verType, class edgeType>
Graph<verType, edgeType>::Graph(bool direct)
{
    int i;
    //初始化属性
    directed = direct;
    verts = 0;
    edges = 0;
    maxVertex = DefaultNumVertex;
    //为存顶点的一维数组创建空间
    verList = new verNode<verType,edgeType> [maxVertex];
}
template <class verType, class edgeType>
Graph<verType, edgeType>::~Graph()
{
    int i;    edgeNode<edgeType> *p;
    for (i=0; i<verts; i++) //释放所有边表中的结点
    {   while (verList[i].adj)
        {  p = verList[i].adj;    verList[i].adj = p->link;    delete p;      }
    }
      delete []verList;
}
template <class verType, class edgeType>
void Graph<verType, edgeType>::insertEdge(verType vertex1, verType vertex2, edgeType edge) //插入边
{  int i, j;
    edgeNode<edgeType> *tmp;
       //找到vertex1和vertex2的下标
    for (i=0; i<verts; i++)     if (verList[i].data==vertex1)    break;
    for (j=0; j<verts; j++)     if (verList[j].data==vertex2)    break;
       //无此顶点
    if ((i==verts)||(j==verts))   return;
    //在i下标引导的单链表中插入一个边结点
    tmp = new edgeNode<edgeType>;      tmp->dest = j;      tmp->weight = edge;
    tmp->link = verList[i].adj;     verList[i].adj = tmp;
       edges++;
       if (!directed) //如果是无向图，矩阵中关于主对角线的对称点也要设置
    {  tmp = new edgeNode<edgeType>;           tmp->dest = i;
        tmp->weight = edge;           tmp->link = verList[j].adj;
        verList[j].adj = tmp;
    }
}
template <class verType, class edgeType>
void Graph<verType, edgeType>::removeVertex(verType vertex)  //删除顶点
{  int i, j;     int count=0;     edgeNode<edgeType> *p, *q;
       //找到该顶点在顶点表中的下标
    for (i=0; i<verts; i++)     if (verList[i].data==vertex)   break;
       if (i==verts) return; //该顶点不在顶点表中
       //删除下标为i的顶点引导的单链表中所有结点并计数删除的边
    p = verList[i].adj;
    while (p)  {    count++;   verList[i].adj = p->link;   delete p;   p = verList[i].adj;  }

    //检查所有单链表，凡是dest是i的都删除
    for (j=0; j<verts; j++)
    {  p = verList[j].adj; q = NULL;
        while (p)    {  if (p->dest == i) break;    q = p;   p = p->link;   }
        if (!p) continue;
        if (!q)   verList[j].adj = p->link;
        else   q->link = p->link;
        delete p;
        count++;
    }
    //检查所有单链表，凡是dest>i的都删减一
    for (j=0; j<verts; j++)
    {  p = verList[j].adj;
        while (p)   {
            if (p->dest > i)   p->dest--;
            p = p->link;
        }
    }
    if (directed)    edges-=count;
    else   edges-=count/2;
    //无向图，减少count的一半

    //在顶点表中删除顶点
    for (j=i; j<verts-1; j++)
        verList[j] = verList[j+1];
    verts--;
}



//**深度优先搜索 O(n+e)
// DFS()中第一个for循环初始化visited数组，时间为O(n)；
// 第二个for循环中的每一次循环体的执行都有一个顶点被访检查，
// 一共有n个顶点，每个顶点又通过DFS(int start, bool visited[])遍历了它的边表，因此总的时间复杂度为O(n+e)。
template <class verType, class edgeType>
void Graph<verType, edgeType>::DFS()const
{
    bool *visited;
    int i;
    visited = new bool[verts]; // * 用于传入是否访问过的状态
    if (!visited) throw illegalSize();
    for (i=0; i<verts; i++) visited[i]=false;
    // *** 外循环
    for (i=0; i<verts; i++)
    {
        if (!visited[i]) DFS(i, visited);
        cout<<endl;
    }
}
template <class verType, class edgeType>
void Graph<verType, edgeType>::DFS(int start, bool visited[])const
{
    edgeNode<edgeType> *p;
    cout<<verList[start].data<<'\t';
    visited[start] = true;
    p = verList[start].adj;
    while (p)
    {
        if (!visited[p->dest])
            DFS(p->dest, visited);
        p = p->link;
    }
}
// *深度优先搜索的非递归实现
// 外层for循环，循环体执行了n次，但前面for循环体执行中访问过的结点将不再进入内部while循环，
// 因此打开for循环成为串行结构，总的时间复杂度仍为O(n+e)。
template <class verType, class edgeType>
void Graph<verType, edgeType>::DFS()const
{
    seqStack<int> s;
    edgeNode<edgeType> *p;
    bool *visited;
    int i, start;
    //为visited创建动态数组空间，并置初始访问标志为false。
    visited = new bool[verts];
    if (!visited) throw illegalSize();
    for (i=0; i<verts; i++)   visited[i]=false;
    //逐一找到未被访问过顶点，做深度优先遍历
    for (i=0; i<verts; i++)
    {
        if (visited[i]) continue;
        s.push(i); // **推入的是下标！
        while (!s.isEmpty())
        {
            start = s.top();
            s.pop();
            if (visited[start]) continue;
            cout<<verList[start].data<<'\t';
            visited[start] = true;

            p = verList[start].adj;
            while (p)
            {
                if (!visited[p->dest])
                    s.push(p->dest);
                p = p->link;
            }
        }
        cout<<'\n';
    }
}


// ** 广度优先搜索
// 初始化visited数组，时间为O(n)；第二个循环为for、while、while三层循环嵌套，三层循环相互并不独立。
// 打开外循环，检查每个顶点，当某个顶点未被访问时，通过内循环访问它，并通过遍历边表访问所有和它在一个连通分量中的顶点，因此总的时间为n+e，
// 故算法的时间复杂度为O(n+e)。
template <class verType, class edgeType>
void Graph<verType, edgeType>::BFS()const//广度优先遍历
{
    seqQueue<int> q;      edgeNode<edgeType> *p;
    bool *visited;   int i, start;
    //为visited创建动态数组空间，并置初始访问标志为false。
    visited = new bool[verts];
    if (!visited) throw illegalSize();
    for (i=0; i<verts; i++) visited[i]=false;
    //逐一找到未被访问过顶点，
    //做广度优先遍历
    for (i=0; i<verts; i++)
    {
        if (visited[i]) continue;
        q.enQueue(i);
        while (!q.isEmpty())
        {
            start = q.front(); q.deQueue();
            if (visited[start]) continue;
            cout<<verList[start].data<<'\t';
            visited[start] = true;
            p = verList[start].adj;
            while (p)
            {
                if (!visited[p->dest])
                    q.enQueue(p->dest);
                p = p->link;
            }
        }
        cout<<'\n';
    }
}

// ** 判断有向图的连通性
template <class verType, class edgeType>
bool Graph<verType, edgeType>::connected()const//广度优先遍历
{
    seqQueue<int> q;
    edgeNode<edgeType> *p;
    bool *visited;
    int i, start, count=0; //count为计数器
    //为visited创建动态数组空间，并置初始访问标志为false。
    visited = new bool[verts];
    if (!visited) throw illegalSize();
    for (i=0; i<verts; i++) visited[i]=false;
    //逐一找到未被访问过顶点，
    //做广度优先遍历
    for (i=0; i<verts; i++)
    {
        if (visited[i]) continue;
        q.enQueue(i);
        count++;
        while (!q.isEmpty())
        {
            start = q.front();
            q.deQueue();
            if (visited[start]) continue;
            cout<<verList[start].data<<'\t';
            visited[start] = true;
            p = verList[start].adj;
            while (p)
            {
                if (!visited[p->dest])
                    q.enQueue(p->dest);
                p = p->link;
            }
        }
        cout<<'\n';
    }
    if (count==1) return true;
    return false;
}
// ******************************************************************************************

// ** 拓扑排序
template <class verType, class edgeType>
void Graph<verType, edgeType>::topoSort()const
    {
        int *inDegree;
        seqStack<int> s;
        int i, j;
        //创建空间并初始化计算每个顶点的入度,
        //邻接矩阵每一列元素相加,加完入度为零的压栈
        inDegree = new int[verts];
        for (j=0; j<verts; j++)
        {
            inDegree[j] = 0;
            for (i=0; i<verts; i++)
            {
                if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
                    inDegree[j]++;
            }
            if (inDegree[j]==0) s.push(j);
        }
        //逐一处理栈中的元素
        while (!s.isEmpty())
        {   i = s.top(); s.pop();
            cout<<i<<"  ";
            //将i射出的边指示的邻接点入度减一，减为零时压栈
            for (j=0; j<verts; j++)
                if ((j!=i)&&(edgeMatrix[i][j]!=noEdge))
                {
                    inDegree[j]--;
                    if (inDegree[j]==0) s.push(j);
                }
        }
        cout<<endl;
    }
// ******************************************************************************************

// ** 求关键路径
//保存边信息
template <class edgeType>
struct keyEdge
{
    int u, v;
    edgeType weight;
    edgeType early, last;
};
template <class verType, class edgeType>
void Graph<verType, edgeType>::keyActivity (verType start, verType end)const
{
    int *inDegree;
    edgeType *verEarly, *verLast; //事件-顶点的最早发生时间、最迟发生时间
    keyEdge<edgeType> *edgeEL; //记录每个活动-边的最早发生时间、最迟发生时间
    seqStack<int> s1; //s1保存入度为0的顶点
    seqStack<int> s2; //s2保存确定顶点最早发生时间的顶点顺序
    int i, j, k;
    int u, v;
    int intStart, intEnd;
    //创建动态数组空间
    inDegree = new int[verts];
    verEarly = new edgeType[verts];
    verLast = new edgeType[verts];
    edgeEL = new keyEdge<edgeType>[edges];
    //找到起点和终点的下标
    intStart = intEnd = -1;
    for (i=0; i<verts; i++)
    {
        if (verList[i]==start)
            intStart = i;
        if (verList[i]==end)
            intEnd = i;
    }
    if ((intStart==-1)||(intEnd==-1)) throw outOfBound();
    //计算每个顶点的最早发生时间
    //初始化起点的最早发生时间
    verEarly[intStart] = 0;
    s1.push(intStart);
    s2.push(intStart);
    i = intStart;
    //计算其他顶点的最早发生时间
    while (i!=intEnd) //当终点因为入度为零压栈、出栈时，计算结束
    {
        for (j=0; j<verts; j++)
        {   if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {   inDegree[j]--;
                if (inDegree[j]==0) s1.push(j); //入度为0，进栈
                if (verEarly[j]<verEarly[i]+edgeMatrix[i][j])
                    verEarly[j] = verEarly[i]+edgeMatrix[i][j];
            }
        }
        i = s1.top();
        s1.pop();
        s2.push(i); //当前确定了最早发生时间的顶点入栈
    }
    //初始化顶点最迟发生时间
    for (i=0; i<verts; i++)
        verLast[i] = verEarly[intEnd];
    //按照计算顶点最早发生时间逆序依次计算顶点最迟发生时间
    while (!s2.isEmpty())
    {
        j = s2.top(); s2.pop();
        //修改所有射入顶点j的边的箭尾顶点的最迟发生时间
        for (i=0; i<verts; i++)
            if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
                if (verLast[i] > verLast[j] - edgeMatrix[i][j])
                    verLast[i] = verLast[j] - edgeMatrix[i][j];
    }
    //建立边信息数组
    k=0;
    for (i=0; i<verts; i++)
        for (j=0; j<verts; j++)
            if ((i!=j)&&(edgeMatrix[i][j]!=noEdge))
            {
                edgeEL[k].u = i;
                edgeEL[k].v = j;
                edgeEL[k].weight = edgeMatrix[i][j];
                k++;
            }
    //将边的最早发生时间<u,v>设置为箭尾顶点u的最早发生时间
    //将边的最迟发生时间<u,v>设置为箭头顶点v的最迟发生时间-<u,v>边的权重
    for (k=0; k<edges; k++)
    {
        u = edgeEL[k].u;
        v = edgeEL[k].v;
        edgeEL[k].early = verEarly[u];
        edgeEL[k].last  = verLast[v] - edgeEL[k].weight;
    }
    //输出关键活动
    cout<<"关键活动："<<endl;
    for (k=0; k<edges; k++)
        if (edgeEL[k].early == edgeEL[k].last)
        {
            u = edgeEL[k].u;
            v = edgeEL[k].v;
            cout<<verList[u]<<"->"<<verList[v]<<endl;
            cout<<"early: "<<edgeEL[k].early<<"  "
                <<"last: "<<edgeEL[k].last;
            cout<<endl<<endl;
        }
}
// ******************************************************************************************


#endif //图_EDGELINKLIST_H
