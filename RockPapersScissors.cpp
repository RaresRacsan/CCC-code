// RockPapersScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <queue>
#include<string>

using namespace std;
ifstream f("level3_1.in");
ofstream g("output.txt");
int n,m;

char winner(string battle )
{
    //battle is of form RR, PP, SS, RS, RP, PS, SR, SP, PR
    // the result is the winner of the battle
    if(battle[0] == battle[1])
    {
        return battle[0];
    }
    else if(battle[0] == 'R' && battle[1] == 'S')
    {
        return 'R';
    }
    else if(battle[0] == 'S' && battle[1] == 'R')
    {
        return 'R';
    }
    else if(battle[0] == 'R' && battle[1] == 'P')
    {
        return 'P';
    }
    else if(battle[0] == 'P' && battle[1] == 'R')
    {
        return 'P';
    }
    else if(battle[0] == 'P' && battle[1] == 'S')
    {
        return 'S';
    }
    else if(battle[0] == 'S' && battle[1] == 'P')
    {
        return 'S';
    }
}



void task2(int n, int m) {
    char c1, c2;
    for (int i = 0; i < n; i++)
    {
        queue<char> q;
        cout << i;

        for (int j = 0; j < m / 2; j++)
        {
            f >> c1 >> c2;
            string battle = "";
            battle += c1;
            battle += c2;
            q.push(winner(battle));
        }
        while (q.size() != (m / 4))
        {


            char c1 = q.front();
            q.pop();
            char c2 = q.front();
            q.pop();
            string battle = "";
            battle += c1;
            battle += c2;
            q.push(winner(battle));

        }

        string sol;
        while (!q.empty())
        {
            sol += q.front();
            q.pop();
        }
        g << sol << endl;
    }
}


int main() {
    f >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int r = 0, s = 0, p = 0;
        string sir1,sir2,sir3;

        int nou1,nou2,nou3;
        f >> sir1>>sir2>>sir3;
        
        nou1 = stoi(sir1);
        nou2 = stoi(sir2);
        nou3 = stoi(sir3);

        if (sir1[sir1.size() - 1] == 'R')
            r += nou1;
        if (sir2[sir2.size() - 1] == 'P')
            p += nou2;
        if (sir3[sir3.size() - 1] == 'S')
            s += nou3;
        cout << r << " " << p << " " << s<<endl;

        while (r >= 3)
        {
            g << "RRRP";
           // cout << "RRRP";
            r -= 3;
            p--;
        }
        if (r == 1 && p>=1)
        {
            g << "RP"; p--;
        }
        else if (r == 2 && p>=2)
        {
            g << "RPRP"; p -= 2;
        }
        else if (r == 2 && p <= 2)
        {
            g << "RRPS";
            p--;
            s--;
        }
        while (p)
        {
            g << "P";
            p--;
        }
        while (s)
        {
            g << "S";
            s--;
        }
        g << endl;
    }
}

