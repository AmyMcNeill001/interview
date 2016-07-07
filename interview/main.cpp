#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> columns(string &input, int &columnSize)
{
    vector<string>columns;
    int xx = columnSize;
    char space = ' ';
    int endPoint = 0;
    
    while(xx < input.length() + columnSize)
    {
        char dummy = input[xx];
        cout << "Dummy value is: " << dummy << endl;
        
        while(dummy != space)
        {
            xx--;
            dummy = input[xx];
            
            if(xx == endPoint)
            {
                dummy = space;
                xx = endPoint + columnSize;
            }
        }
        
        string forAppend ="";
        for(int zz = endPoint; zz < xx; zz++)
        {
            if(zz == endPoint && input[zz] == space)
                ;
            else
                forAppend += input[zz];
        }
        columns.push_back(forAppend);
        
        endPoint = xx;
        xx += columnSize;
    }
    
    return columns;
}

int main()
{
    string input = "This is a very long string to be made in to columns";
    int size = 10;
    vector<string> forOutput = columns(input, size);
    
    for (int ii = 0; ii < forOutput.size(); ii++)
    {
        cout << forOutput.at(ii) << endl;;
    }
    
    return 0;
}