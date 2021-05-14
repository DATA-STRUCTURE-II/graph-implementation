#ifndef PART1_H_INCLUDED
#define PART1_H_INCLUDED

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    int *items;
    int front;
    int rear;
};

struct graph
{
    int vertices;
    struct node **arr;
    int *visited;
};



struct node* Newnode(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

struct graph *Newgraph(int vertices)
{
    struct graph *newgraph =(struct graph*)malloc(sizeof(struct graph));
    newgraph->vertices=vertices;
    newgraph->arr=(struct node**)malloc(sizeof(struct node*)*vertices);
    newgraph->visited=(int*)malloc(sizeof(int)*vertices);
    while(vertices!=0)
    {
        newgraph->arr[vertices]=NULL;
        newgraph->visited[vertices]=0;
        vertices--;
    }

    return newgraph;
};

struct queue* createQueue(int N)
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    q->items=(int*)malloc(N*sizeof(int));
    return q;
}


int isEmpty(struct queue* q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}


void enqueue(struct queue* q, int value)
{


    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;

}


int dequeue(struct queue* q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}


void creategraph(struct graph *graph,int u,int v)
{
    struct node *node=Newnode(u);
    node->next=graph->arr[v];
    graph->arr[v]=node;

    node=Newnode(v);
    node->next=graph->arr[u];
    graph->arr[u]=node;
}

int *bfs(struct graph* graph, int startVertex,int n)
{
    struct queue* q = createQueue(n);
    int *dis=(int*)malloc(n*sizeof(int));
    for (int i=1; i<=n; i++)
    {
        dis[i]=0;
    }
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        struct node* temp = graph->arr[currentVertex];
        while (temp)
        {
            int adjVertex = temp->data;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                dis[adjVertex] = dis[currentVertex] + 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    return dis;
}

int count (int k,int *dis,int NV)
{
    int c=0;
    if(k==0)
    {
        return -1;
    }
    else
    {
        for(int i=1; i<=NV; i++)
        {
            if(dis[i]==k)
            {
                c++;
            }
        }
    }
    return c;
}


#endif // PART1_H_INCLUDED
