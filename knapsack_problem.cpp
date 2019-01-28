

#include<iostream>

using namespace std;

int maX(int n1,int n2)
{
    if(n1>=n2) return n1;
    else return n2;
}

int main()
{
    int itemNum;
    cout << "Number of item" <<endl;
    cin >> itemNum;

    int capasity;
    cout << "Capasity" << endl;
    cin >> capasity;

    int val[itemNum];
    cout << "enter the values" << endl;
    for (int i=0;i<itemNum;i++) cin >> val[i];

    int weight[itemNum];
    cout << "enter the weight" << endl;
    for (int i=0;i<itemNum;i++) cin >> weight[i];


    int temp[itemNum][capasity+1];


    for(int i=0;i<itemNum;i++)
    {
        temp[i][0]=0;
    }

    for(int i=1;i<=capasity;i++)
    {
        if(weight[0]<=1) temp[0][i]=val[0];
        else temp[0][i]=0;
    }

    for(int i=1;i<itemNum;i++)
    {
        for(int j=1;j<=capasity;j++)
        {
        	if(j>=weight[i])
        	{
				int if_take=val[i]+temp[i-1][j-weight[i]];
	            temp[i][j]=maX(if_take,temp[i-1][j]);
	        }
	        else temp[i][j]=temp[i-1][j];
        }
    }

    for(int i=0;i<itemNum;i++)
    {
        for(int j=0;j<=capasity;j++)
        {
            cout << temp[i][j] << ' ';
        }
        cout << endl;
    }

    int item[itemNum],counter=0;

    int tracker=temp[itemNum-1][capasity];

    for(int i=itemNum-2,j=capasity;tracker!=0;)
    {
    	if(tracker!=temp[i][j])
    	{
    		tracker=tracker-val[i+1];
    		item[counter]=i+2; //i+2 is the item, starting from 1,,2,3,... ...
    		counter++;

    		j=j-weight[i+1];
    		
    		i--;
    	}
    	else
    	{
    		i--;
    	}
    }

    for(int i=0;i<counter;i++)
    {
    	cout<<item[i]<<" ";
    }
    cout << endl;

}
