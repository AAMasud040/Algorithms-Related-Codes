#include<bits/stdc++.h>
using namespace std;
struct array2dindex{
    int a;
    int b;
};
int coord1,coord2;
void up(int i,int j)
{
    coord1 = i-1;
    coord2 = j;
}
void down(int i,int j)
{
    coord1 = i+1;
    coord2 = j;
}
void left(int i,int j)
{
    coord1 = i;
    coord2 = j-1;
}
void right(int i,int j)
{
    coord1 = i;
    coord2 = j+1;
}
void up_left(int i,int j)
{
    coord1 = i-1;
    coord2 = j-1;
}
void up_right(int i,int j)
{
    coord1 = i-1;
    coord2 = j+1;
}
void down_left(int i,int j)
{
    coord1 = i+1;
    coord2 = j-1;
}
void down_right(int i,int j)
{
    coord1 = i+1;
    coord2 = j+1;
}
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
int coodValidity(int n)
{
    if((coord1>=0 && coord1<n) && (coord2>=0 && coord2<n))
    {
        return 1;//of okay returns 1
    }
    return 0;//else returns 0
}
int main()
{
    int n=5;
    int m=5;
    int arr[n][m];
    int visited[n][m];
    int sum = 0;
    struct array2dindex parenttracker[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j] = sum;
            visited[i][j] = 0;
            parenttracker[i][j].a =-1;
            parenttracker[i][j].b =-1;
            sum++;
        }
    }
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //cout<<arr[i][j]<<" ";
            cout<<parenttracker[i][j].a<<","<<parenttracker[i][j].b<<" ";
        }
        cout<<endl;
    }*/

    pair<int,int> it;
    queue< pair<int,int> > q;

    int source_i=4,source_j=3;
    q.push(make_pair(source_i,source_j));
    visited[source_i][source_j] = 1;

    while(q.empty()!=1)//BFS Travarsal
    {
        it = q.front();
        q.pop();
        printf("%d %d\n",it.first,it.second);

        left(it.first,it.second);///left
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        up_left(it.first,it.second);///up-left
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        up(it.first,it.second); ///up
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        up_right(it.first,it.second);///up-right
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        right(it.first,it.second);///right
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        down_right(it.first,it.second);///down-right
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        down(it.first,it.second);///down
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }

        down_left(it.first,it.second);///down-left
        if((coodValidity(n)==1) && (visited[coord1][coord2]==0))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
        }
    }
    for(int i=0; i<n; i++)//Printing parent tracker
    {
        for(int j=0; j<m; j++)
        {
            //cout<<arr[i][j]<<" ";
            cout<<parenttracker[i][j].a<<","<<parenttracker[i][j].b<<" ";
        }
        cout<<"\n\n";
    }
    //destination to source
    int dest_i=0;
    int dest_j=3;
    int x = dest_i;
    while((parenttracker[dest_i][dest_j].a!=-1)&&(parenttracker[dest_i][dest_j].b!=-1))
    {
        cout<<dest_i<<" "<<dest_j<<" -> ";
        dest_i = parenttracker[x][dest_j].a;
        dest_j = parenttracker[x][dest_j].b;
        x = dest_i;
    }
    cout<<dest_i<<" "<<dest_j;
}
/*
up(2,2);//checking coords if they are right
cout<<coord1<<" "<<coord2<<endl;
down(2,2);
cout<<coord1<<" "<<coord2<<endl;
left(2,2);
cout<<coord1<<" "<<coord2<<endl;
right(2,2);
cout<<coord1<<" "<<coord2<<endl;
up_left(2,2);
cout<<coord1<<" "<<coord2<<endl;
up_right(2,2);
cout<<coord1<<" "<<coord2<<endl;
down_left(2,2);
cout<<coord1<<" "<<coord2<<endl;
down_right(2,2);
cout<<coord1<<" "<<coord2<<endl;
*/
/*
    queue< pair<int,int> > q; //
    q.push(make_pair(1,2));
    q.push(make_pair(2,2));
    q.push(make_pair(3,2));
    pair<int,int> it;
    it = q.front();
    cout<<it.first<<" "<<it.second<<endl;
    q.pop();
    it = q.front();
    cout<<it.first<<" "<<it.second<<endl;
*/
/*up(4,0);//checking side coords if they are valid
    coodValidity(n);
    down(4,0);
    coodValidity(n);
    left(4,0);
    coodValidity(n);
    right(4,0);
    coodValidity(n);
    up_left(4,0);
    coodValidity(n);
    up_right(4,0);
    coodValidity(n);
    down_left(4,0);
    coodValidity(n);
    down_right(4,0);
    coodValidity(n);*/
