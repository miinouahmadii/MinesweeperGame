#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void count_bombs(vector<string> &map, int x, int y,int row,int coloumn)
{
    char counter='0';
    if( y>1)
    {
        if(map[y-2][x-1]=='M')
            counter++;
    }

    if( x>1)
    {
        if(map[y-1][x-2]=='M')
            counter++;
    }

    if( y<row )
    {
        if(map[y][x-1]=='M')
            counter++;
    }

    if( x<coloumn)
    {
        if(map[y-1][x]=='M')
            counter++;
    }

     if( x>1 && y>1 )
    {
        if(map[y-2][x-2]=='M')
            counter++;
    }

     if( y<row && x<coloumn)
    {
        if(map[y][x]=='M')
            counter++;
    }

     if( x<coloumn && y>1 )
    {
        if(map[y-2][x]=='M')
            counter++;
    }

     if( x>1 && y<row)
    {
        if(map[y][x-2]=='M')
            counter++;
    }
map[y-1][x-1]=counter;

//cout<<map[y-1][x-1]<<" "<<x<<y<<endl;
if(map[y-1][x-1] == '0' && x<coloumn)
    count_bombs(map,x+1,y,row,coloumn);
if(map[y-1][x-1] == '0' && y<row)
    count_bombs(map,x,y+1,row,coloumn);
// if(map[y-1][x-1] == '0' && x>0)
//     count_bombs(map,x-1,y,row,coloumn);
// if(map[y-1][x-1] == '0' && y>1)
//     count_bombs(map,x,y-1,row,coloumn);
}

void show_map(vector<string> map)
{
    for(int i=0;i<map.size();i++)
    {
        for(int j=0;j<map[i].size();j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }
}
vector<string>set_map( vector<string> map, int row, int coloumn)
{
 for( int i=0; i<row; i++)
 {
     string temp_row;
     cin>>temp_row;
     if(temp_row.size()!=coloumn)
        continue;
     map.push_back(temp_row);
 }
 return map;
}

int main()
{
 int row, coloumn,x,y;
 cin>>row>>coloumn>>x>>y;
 vector<string>map;
 map = set_map(map,row,coloumn);
 count_bombs(map,x,y,row,coloumn);
 cout<<endl;
 show_map(map);
 return 0;
}