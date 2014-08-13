/*
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
    int COUNT=1;
    int CURRENT_VALUE = 0;
    int MAX=0;
    int v1 ,v2 ;
    while(cin>>v1>>v2)
    {
        int temp1 = v1;
        int temp2 = v2;
        if(v1 > v2)
        {
          swap(v1,v2);
        }


       for(int i = v1; i <= v2 ; i++)
       {
        CURRENT_VALUE = i;
        while(CURRENT_VALUE!=1)
        {

            if( CURRENT_VALUE%2 == 1)
                CURRENT_VALUE = CURRENT_VALUE*3+1;
            else
                CURRENT_VALUE = CURRENT_VALUE/2;
            COUNT++;
        }
        if(COUNT > MAX)
            MAX=COUNT;
          COUNT = 1;
       }
       cout << temp1 <<" "<< temp2 <<" "<<MAX<<"\n";
       MAX = 0;


    }
}
*/
#include <cstdio>
#include <iostream>

int cycleLength(long long int);

int cycleLengthResult[1000001];

int main(int argc, char *argv[])
{
    int i = 0, j = 0, cur = 0, max = 0, k = 0, s = 0;

    for (i = 1 ; i < 1000000 ; ++ i )
        cycleLength(i);

    while ( scanf("%d%d", &i, &j) != EOF )
    {
        printf("%d %d ", i, j);
        if ( i > j )
        {
            s = i;
            i = j;
            j = s;
        }
        max = 0;
        for ( k = i ; k <= j ; ++ k )
        {
            cur = cycleLengthResult[k];
            if (cur > max) max = cur;
        }
        printf("%d\n", max);
    }

    return 0;
}

int cycleLength(long long int arg)
{
    if ( arg > 1000000 )
    {
        if (!(arg & 1))
            return 1 + cycleLength(arg/2);
        else
            return 1 + cycleLength(arg*3+1);
    }
    if (cycleLengthResult[arg] == 0)
    {
        int valueForArg = 0;
        if (arg == 1)
            valueForArg = 1;
        else if (!(arg & 1))
            valueForArg = 1 + cycleLength(arg/2);
        else
            valueForArg = 1 + cycleLength(arg*3+1);

        cycleLengthResult[arg] = valueForArg;
    }
    return cycleLengthResult[arg];
}
