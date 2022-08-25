#include <iostream>
#include<vector>
#include<string>

using namespace std;
vector<int> backtrack(vector<int>numbers,int index)
{
    if(index==numbers.size()/2 && numbers.size()%2 == 1)
        return numbers ;
    else if(index==numbers.size()/2 && numbers.size()%2 == 0)
        {
            int temp1 = numbers[index-1];
            numbers[index-1] = numbers[index];
            numbers[index] = temp1;
            return numbers;
        }
    
    numbers = backtrack(numbers,index-1);
    int temp2 = numbers[numbers.size()-index-1];
    numbers[numbers.size()-index-1] = numbers[index];
    numbers[index] = temp2;
    return numbers;
}

int main()
{
 vector<int>numbers;
 int input;
 while(cin>>input)
 {
    numbers.push_back(input);
 }

 numbers = backtrack(numbers,numbers.size()-1);
 for(int i=0;i<numbers.size();i++)
    cout<<numbers[i]<<" ";
 cout<<endl;
    return 0;
}
