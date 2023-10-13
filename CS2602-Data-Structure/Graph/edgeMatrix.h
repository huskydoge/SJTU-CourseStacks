//
// Created by 黄奔皓 on 2022/12/29.
// 邻接矩阵！
//

#ifndef 图_GRAPH_H
#define 图_GRAPH_H

#define DefaultNumVertex 20
class outOfBound{};
template <class verType, class edgeType>
class Graph
{
private:
    int verts, edges;   //图的实际顶点数和实际边数
    int maxVertex;      //图顶点的最大可能数量
    verType *verList;   // 保存顶点数据的一维数组
    edgeType **edgeMatrix; //保存邻接矩阵内容的二维数组
    edgeType noEdge;       //无边的标志，一般图为0， 网为无穷大MAXNUM
    bool directed;          //有向图为1，无向图为0
public:
    //初始化图结构g，direct为是否有向图标志，e为无边数据
    Graph(bool direct, edgeType e);
    ~Graph();
    int numberOfVertex()const{ return verts; }; // 返回图当前顶点数
    int numberOfEdge()const{ return edges; }; // 返回图当前边数
    //返回顶点为vertex值的元素在顶点表中的下标
    int getVertex(verType vertex)const;
    //判断某两个顶点间是否有边
    bool existEdge(verType vertex1,verType vertex2)const;
    void insertVertex(verType vertex ); //插入顶点
    void insertEdge(verType vertex1, verType vertex2, edgeType edge); //插入边
    void removeVertex(verType vertex);  //删除顶点
    void removeEdge(verType vertex1, verType vertex2); //删除边

    //返回顶点vertex的第一个邻接点,如果无邻接点返回-1
    int getFirstNeighbor(verType vertex ) const;
    //返回顶点vertex1相对vertex2的下一个邻接点，如果无下一个邻接点返回-1
    int getNextNeighbor(verType vertex1, verType vertex2)const;
    void disp()const; //显示邻接矩阵的值
};

//初始化图结构g，direct为是否有向图标志，e为noEdge时候填入的数据
template <class verType, class edgeType>
Graph<verType, edgeType>::Graph(bool direct, edgeType e)
{
    int i, j;
   //初始化属性
    directed = direct;
    noEdge = e;
    verts = 0;
    edges = 0;
    maxVertex = DefaultNumVertex;
   //为存顶点的一维数组和存边的二维数组创建空间
    verList = new verType[maxVertex];
    edgeMatrix = new edgeType*[maxVertex]; // *** 怎么申请矩阵要关注好！

    //初始化图结构g，direct为是否有向图标志，e为无边数据
    for (i=0; i<maxVertex; i++)
        edgeMatrix[i] = new edgeType[maxVertex];

   //初始化二维数组，边的个数为0
    for (i=0; i<maxVertex; i++)
        for (j=0; j<maxVertex; j++)
            if (i==j)   edgeMatrix[i][j] = 0;//对角线元素
            else   edgeMatrix[i][j] = noEdge; //无边
}
template <class verType, class edgeType>
Graph<verType, edgeType>::~Graph()
{
    int i;
    delete []verList;
   //*** 矩阵的删除
    for (i=0; i<maxVertex; i++)
        delete []edgeMatrix[i];
    delete []edgeMatrix;
}
//返回顶点为vertex值的元素在顶点表中的下标
template <class verType, class edgeType>
int Graph<verType, edgeType>::getVertex(verType vertex) const
{
    int i;
    for (i=0; i<verts; i++)
        if (verList[i]==vertex)
            return i;
    return -1;
}
//判断某两个顶点是否有边
template <class verType, class edgeType>
bool Graph<verType, edgeType>::existEdge(verType vertex1,verType vertex2) const
{
    int i, j;
   //找到vertex1和vertex2的下标
    for (i=0; i<verts; i++)
        if (verList[i]==vertex1)
            break;
    for (j=0; j<verts; j++)
        if (verList[j]==vertex2)
            break;

    if (i==verts && j==verts)   return false;
 if (edgeMatrix[i][j] == noEdge) return false;
    return true;
}

template <class verType, class edgeType>
void Graph<verType, edgeType>::removeVertex(verType vertex)
//删除顶点
{  int i, j, k;
   //找到该顶点在顶点表中的下标
    for (i=0; i<verts; i++)
        if (verList[i]==vertex)  break;
    if (i==verts) return
    //在顶点表中删除顶点
    for (j=i; j<verts-1; j++)
        verList[j] = verList[j+1];

    //计数删除顶点射出的边,边数减少
    for (j=0; j<verts; j++)
        if ( (j!=i) && (edgeMatrix[i][j]!= noEdge))
            edges--;

    //***如果是有向图，还要计数删除顶点射入的边,边数减少
    if (directed)
    {    for (k=0; k<verts; k++)
            if (( (k!=i) && edgeMatrix[k][i]!= noEdge))
                edges--;
    }
   //第i行之后所有行上移
    for (j=i; j<verts-1; j++)
    {   for (k=0; k<verts; k++)
        {   edgeMatrix[j][k] = edgeMatrix[j+1][k];   }
    }
    //第i列之后所有列前移
    for (j=i; j<verts-1; j++)
    {
        for (k=0; k<verts; k++)
            edgeMatrix[k][j] = edgeMatrix[k][j+1];
    }

    verts--;
}




#endif //图_GRAPH_H
