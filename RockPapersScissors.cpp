// RockPapersScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <queue>
#include<string>

using namespace std;
ifstream f("level3_4.in");
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

void verifySol(string sol){
    string newSol = "";
    for(int i=0;i<sol.size();i+=2){
        char w = winner(sol.substr(i,2));
        newSol += w;
    }
    string newnewSol = "";
    for(int i=0;i<newSol.size();i+=2){
        char w = winner(newSol.substr(i,2));
        newnewSol += w;
    }
    cout<<newnewSol<<endl;
}


int main() {
    f >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int r = 0, s = 0, p = 0;
        string sir1,sir2,sir3;

        int nou1,nou2,nou3;
        f >> sir1>>sir2>>sir3;
        
        nou1 = stoi(sir1.substr(0, sir1.size() - 1));
        nou2 = stoi(sir2.substr(0, sir2.size() - 1));
        nou3 = stoi(sir3.substr(0, sir3.size() - 1));

        if (sir1.back() == 'R') r += nou1;
        if (sir1.back() == 'P') p += nou1;
        if (sir1.back() == 'S') s += nou1;

        if (sir2.back() == 'R') r += nou2;
        if (sir2.back() == 'P') p += nou2;
        if (sir2.back() == 'S') s += nou2;

        if (sir3.back() == 'R') r += nou3;
        if (sir3.back() == 'P') p += nou3;
        if (sir3.back() == 'S') s += nou3;
        cout << r << " " << p << " " << s<<endl;

        string sol = "";
        while (r >= 3 && p>0)
        {
            g << "RRRP";
            sol+="RRRP";
            r -= 3;
            p--;
        }
        if (r == 1 && p>=1)
        {
            g << "RP"; p--;r--;
            sol += "RP";
        }
        else if (r == 2 && p>=2)
        {
            g << "RPRP"; p -= 2;r-=2;
            sol += "RPRP";
        }
        else if (r == 2 && p ==1 && s>0)
        {
            g << "RPRS";
            sol += "RRPS";
            p--;
            s--;
            r-=2;
        }
        while (p>0)
        {
            g << "P";
            sol += "P";
            p--;
        }
        while (s>0)
        {
            g << "S";
            sol += "S";
            s--;
        }
        cout<<i;
        verifySol(sol);
        g << endl;
    }

}


