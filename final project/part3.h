#ifndef PART3_H_INCLUDED
#define PART3_H_INCLUDED
#define INFINITY 999

void dijkstra(int **G,int **t,int n,int startnode,int dis,int M)
{
    int **cost,*price,*pred,totalcost,totaltime;
    int *visited,coun,c,mincost,nextnode;
    int sum,temp1,temp2;

    cost = (int **)calloc(n, sizeof(int *));
    for (int i=1; i<=n; i++)
    {
        cost[i] = (int *)calloc(n, sizeof(int));
    }
    price =(int *)calloc(n, sizeof(int));
    pred =(int *)calloc(n, sizeof(int));
    visited =(int *)calloc(n, sizeof(int));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(G[i][j]==0)
            {
                cost[i][j]=INFINITY;
            }
            else
            {
                cost[i][j]=G[i][j];
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        price[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    price[startnode]=0;
    visited[startnode]=1;
    coun=1;

    while(coun<=n)
    {
        mincost=INFINITY;

        for(int i=1; i<=n; i++)
        {
            if(price[i]<mincost&&!visited[i])
            {
                mincost=price[i];
                nextnode=i;
            }
        }

        visited[nextnode]=1;
        for(int i=0; i<=n; i++)
        {
            if(!visited[i])
                if(mincost+cost[nextnode][i]<price[i])
                {
                    price[i]=mincost+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        }
        coun++;
    }

    if(dis!=startnode)
    {
        printf("\nThe route with minimum cost is\n");
        printf("%d",dis);

        int temp=dis;
        c=0;
        do
        {
            temp=pred[temp];
            printf("<-%d",temp);
            c++;
        }
        while(temp!=startnode);
    }
    sum=0;
    temp1=dis;
    temp2=pred[dis];
    for (int i=0; i<c; i++)
    {
        sum =sum+t[temp1][temp2];
        temp1=pred[dis];
        temp2=pred[temp1];
    }
    totaltime=sum+c-1;
    printf("\nTotalTime = %d hours",totaltime);
    totalcost=totaltime*M+price[dis];
    printf("\nTotalCost= %d$\n",totalcost);

}

#endif // PART3_H_INCLUDED
