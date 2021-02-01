 using namespace std;
 int coord1,coord2;
 pair<int,int> up(int i,int j)
{
    coord1 = i-1;
    coord2 = j;
    return make_pair(coord1,coord2);
}
 pair<int,int> down(int i,int j)
{
    coord1 = i+1;
    coord2 = j;
    return make_pair(coord1,coord2);
}
pair<int,int> left(int i,int j)
{
    coord1 = i;
    coord2 = j-1;
    return make_pair(coord1,coord2);
}
pair<int,int> right(int i,int j)
{
    coord1 = i;
    coord2 = j+1;
    return make_pair(coord1,coord2);
}
pair<int,int> up_left(int i,int j)
{
    coord1 = i-1;
    coord2 = j-1;
    return make_pair(coord1,coord2);
}
pair<int,int> up_right(int i,int j)
{
    coord1 = i-1;
    coord2 = j+1;
    return make_pair(coord1,coord2);
}
pair<int,int> down_left(int i,int j)
{
    coord1 = i+1;
    coord2 = j-1;
    return make_pair(coord1,coord2);
}
pair<int,int> down_right(int i,int j)
{
    coord1 = i+1;
    coord2 = j+1;
    return make_pair(coord1,coord2);
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
int coodValidity(int n,int m)
{
    if((coord1>=0 && coord1<n) && (coord2>=0 && coord2<m))
    {
        return 1;//of okay returns 1
    }
    return 0;//else returns 0
}
void print_pair(pair<int,int> p)
{
    cout<<p.first<<" "<<p.second<<endl;
}
void show_coords()
{
    //cout<<coord1<<" "<<coord2<<endl;
}
