#include <iostream>
#include "seqList.h"
using namespace std;

//求两个正整数集合的交集，用线性表处理集合问题。
//TODO 改进输入可能不是集合的情况
int main()
{
    seqList<int> list1(20), list2(20), list3(20); //实例化对象
    int i, j, x;
    int len1,len3;
    //输入第一个整数集合中的元素，输入零结束：
    i=1;
    cout<<"输入第一个正整数集合，以零为结束标志：";
    cin>>x;
    while (x!=0)
    {
        try {
            if(list1.has(x)){
                throw(repeatedElem());
            }
            list1.insert(i, x);
            i++;
            cin >> x;
        }
        catch (repeatedElem){
            cout << "集合中已经存在这个元素了,请勿重复添加!" << endl << "请继续输入:" << endl;
            cin >> x;
        }
    }
    //输入第二个整数集合中的元素，输入零结束：
    i=1;
    cout<<"输入第一个正整数集合，以零为结束标志：";
    cin>>x;
    while (x!=0)
    {
        list2.insert(i,x);
        i++;
        cin>>x;
    }

    //求list1,list2的交集，结果存入list3
    len1 = list1.length();
    j=1;
    for (i=1; i<=len1; i++)
    {
        x=list1.get(i);
        if (list2.find(x)!=0)
        {
            list3.insert(j,x);
            j++;
        }
    }

    //显示list3中的元素
    cout<<"两个集合的交集元素为：";
    len3 = list3.length();
    for (i=1; i<=len3; i++)
    {
        x=list3.get(i);
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}


