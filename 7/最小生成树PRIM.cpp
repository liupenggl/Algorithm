#include <iostream.h>
const int n = 6;
const int max = 100;
typedef struct 
{
	int lowcost;
	int adjvex;
} Element;

void Prim(int arc[n][n], int w);

int main( )
{
	int arc[n][n] = {{max, 34, 46, max,max,19},
	{34, max, max,max,12, max},{46, max, max, 17, max, 25},
	{max, max, 17, max, 38, 25},{max, 12, 38, max, 26},{19, max, 25, 25, 26, max}};
	Prim(arc, 0);
	return 0;
}

void Prim(int arc[n][n], int w)
{   
	int i, j, k;
	int min;
	Element shortEdge[10];
	for (i = 0; i < n; i++)        //��ʼ����������shortEdge
	{
		shortEdge[i].lowcost = arc[w][i];
		shortEdge[i].adjvex = w;
	}
	shortEdge[w].lowcost = 0;             //������0���뼯��U
	for (i = 0; i < n - 1; i++)       
	{
		for (min = 100, j = 0; j < n; j++)           //Ѱ����̱ߵ��ڽӵ�k
		{
			if((shortEdge[j].lowcost != 0) && (shortEdge[j].lowcost < min))
			{
				min = shortEdge[j].lowcost; 
				k = j;
			}
		}
        cout<<shortEdge[k].adjvex<<"--"<<k<<endl; 
		shortEdge[k].lowcost = 0;             //������k���뼯��U��
		for (j = 0; j < n; j++)                //��������shortEdge[n]
		{
			if (arc[k][j] < shortEdge[j].lowcost) {
				shortEdge[j].lowcost = arc[k][j];
				shortEdge[j].adjvex = k;
            }
		}
    }
}

