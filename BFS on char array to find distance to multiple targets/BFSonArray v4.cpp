#include<bits/stdc++.h>
#include "BFSonArray v4 helper.cpp"
using namespace std;
///left,left-up,up,right-up,right,right-down,down,left-down

char arr[100][100];
int visited[100][100];

int enqueue_eligibility(int n,int m);

struct array2dindex
{
    int a;
    int b;
};

struct position
{
    char ch;
    int x;
    int y;
};
bool compare(position first, position second)
{
  if (first.ch < second.ch)
    return true;
  else
    return false;
}

int main()
{
    int n,m;
    int source_i,source_j;
    int dest_i,dest_j;

    cout<<"Input the size of the map\n";
    cin>>n>>m;

    //char arr[n][m];
    //int visited[n][m];
    int distancefromSource[n][m];
    struct array2dindex parenttracker[n][m];
    list <position> pos;
    position temp;

    for(int i=0; i<n; i++)///Taking Input if map
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='Z')// records the destination point
            {
                source_i = i;
                source_j = j;
            }
            if(arr[i][j]>='A' && arr[i][j]<='Y')// a list that keeps track of the number of chars
            {
                temp.ch = arr[i][j];
                temp.x = i;
                temp.y =j;
                pos.push_back(temp);
            }
            visited[i][j] = 0;
            parenttracker[i][j].a =-1;
            parenttracker[i][j].b =-1;
            distancefromSource[i][j] = 1000;
        }
    }

    pos.sort(compare);

    pair<int,int> it;///initializing source getting ready for bfs
    queue< pair<int,int> > q;
    q.push(make_pair(source_i,source_j));
    visited[source_i][source_j] = 1;
    distancefromSource[source_i][source_j] = 0;

    while(q.empty()!=1)//BFS Travarsal_ edit show coords to see progress
    {
        it = q.front();
        q.pop();
        //printf("\n(i,j): %d %d\ndis = %d\n",it.first,it.second,distancefromSource[it.first][it.second]);
        int dis = distancefromSource[it.first][it.second];
        left(it.first,it.second);///left
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        up_left(it.first,it.second);///up-left
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        up(it.first,it.second); ///up
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        up_right(it.first,it.second);///up-right
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        right(it.first,it.second);///right
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        down_right(it.first,it.second);///down-right
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        down(it.first,it.second);///down
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }

        down_left(it.first,it.second);///down-left
        if(enqueue_eligibility(n,m))
        {
            visited[coord1][coord2]= 1;
            q.push(make_pair(coord1,coord2));
            parenttracker[coord1][coord2].a =it.first;
            parenttracker[coord1][coord2].b =it.second;
            show_coords();
            distancefromSource[coord1][coord2] = dis+1;
        }
    }

    struct position v;
    struct position quickest;
    int min_distance=10000;

    for ( v: pos)
    {
        dest_i = v.x;
        dest_j = v.y;
        int x = dest_i;
        cout<<"For "<<v.ch<<": ";
        cout<<distancefromSource[dest_i][dest_j]<<endl;
        if(min_distance>distancefromSource[dest_i][dest_j])
        {
             quickest = v;
             min_distance = distancefromSource[dest_i][dest_j];
        }
        /*while((parenttracker[dest_i][dest_j].a!=-1)&&(parenttracker[dest_i][dest_j].b!=-1)) //tracking path to source
        {
            cout<<dest_i<<" "<<dest_j<<"( ";
            cout<<arr[dest_i][dest_j]<<" ) -> ";
            dest_i = parenttracker[x][dest_j].a;
            dest_j = parenttracker[x][dest_j].b;
            x = dest_i;
        }
        cout<<dest_i<<" "<<dest_j<<endl;*/



    }
    /*for(int i=0; i<n; i++)//viewing the whole array for tracking distance
    {
        for(int j = 0; j<m; j++)
        {
            if(distancefromSource[i][j]>=1000)
            {
                cout<<"X ";
            }
            else
                cout<<distancefromSource[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<"Shortest Distance:\n"<<quickest.ch<<": "<<distancefromSource[quickest.x][quickest.y]<<endl;
}

int enqueue_eligibility(int n,int m)///specific for map
{
    if((coodValidity(n,m)==1) && (visited[coord1][coord2]==0) &&(arr[coord1][coord2]!='.'))
    {
        return 1;
    }
    return 0;
}

/*
10 15
. . . . . . . . . . . . Z . .
. . . . x x x x x x x x x . .
. C . . x . x . . . . . x . .
. x . . x x x . . x . . x . .
. . x . x . x x x x x x x x x
. . x . x . . . x . x . x . .
. B x x x . . . x . . . x . .
. x x . x x x x x x x x x . .
. . . . . . . . x x x . x . .
. . . . . . . . . A . . . . .
*/

/*
10 15
. . . . . . . . . . . . Z . .
. . . . x x x x x x x x x . .
. C . . x . x . . . . . . . .
. x . . x x x . . x . . x . .
. . x . x . x x x x x x x x x
. . x . x . . . x . x . x . .
. B x x x . . . x . x . . . .
. x x . x x x x x x x x x . .
. . . . . . . . x x x . x . .
. . . . . . . . . A . . . . .
*/
/*
10 15
. . . . . . . . . . . . Z . .
. . . . x x x x x x x x x . .
. . . . x . x . . . . . x . .
. x . . x x x . . x . . x . .
. . x . x . x x x x x x x x x
. . x . x . . . x . x . x . .
. . x x x . . . x . . . x . .
. x x . x x x x x x x x x . .
. . . . . . . . x x x . x . .
. . . . . . . . A F C . E . .
*/
