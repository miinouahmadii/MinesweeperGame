#include <iostream>
using namespace std;

int recursive_conversion (int index ,string s)
{
    if (index == 0)
        return s[index]-48;
    return (s[index]-48) + recursive_conversion(index-1 , s )*6 ;
}

int convertBase6ToBase10(string s)
{
 return recursive_conversion(s.size()-1,s);
}

int main()
{
string s;
while(cin >> s)
cout << convertBase6ToBase10(s) << endl;
return 0;
}