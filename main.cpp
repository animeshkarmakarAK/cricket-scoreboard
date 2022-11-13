#include<bits/stdc++.h>

using namespace std;
//T10 MATCH SUPPOSE
#define total_over 2
#define o wide
class scoreboard{

    int run ;
    int over_no;
    int wicket;
    string teamName;
    vector<string>player;
public:
    scoreboard();
    void set_teamName(string team);
    string get_teamName();
    void over();
    void set_wicket();
    int get_wicket();
    void set_run(int r);
    int get_run();
    void set_over();
    int get_over();
    void set_player(string p);
    string get_player(int i);


};

void scoreboard::set_player(string p)
{
    player.push_back(p);
}

string scoreboard::get_player(int i)
{
    return player[i];
}

void scoreboard::set_teamName(string team)
{
    teamName = team;
}
string scoreboard::get_teamName()
{
    return teamName;
}

void scoreboard::set_over()
{
    over_no += 1;
}

int scoreboard::get_over()
{
    return over_no;
}

int scoreboard::get_run()
{
    return run;
}

void scoreboard::set_run(int r)
{
    run += r;
}


scoreboard::scoreboard(){
    run = 0;
    over_no = 0;
    wicket = 0;
}


int scoreboard::get_wicket()
{
    return wicket;
}


void scoreboard::set_wicket()
{
    wicket += 1;
    if(wicket == 10)
        cout<<"INNINGS OVER"<<endl;
}


void scoreboard::over()
{
  int ball = 1;
  while(ball <= 6)
  {
      char r;
      cout<<"NO "<<ball<<" BALL : ";
      cin>>r;

      if(r =='w'){
        set_wicket();
        cout<<"WICKET BY RUN  = ";
        int by_run;
        cin>>by_run;
        set_run(by_run);
        ++ball;
      }
      else if(r == 'o')
      {
        set_run(1);
        cout<<"WICKET BY RUN  = ";
        int by_run;
        cin>>by_run;
        set_run(by_run);

      }

      else if( r == 'n')
      {
          set_run(1);
          cout<<"BY RUN = ";
          int by_run;
          cin>>by_run;
          set_run(by_run);
      }

      else {
        r = int(r) - 48;
        if(r >= 0 && r<=9)
        set_run(r);
        ++ball;
      }

  }

  set_over();
}

void fordelay(int delay)
{
    int k ;
    for(int i = 0 ; i<= delay; i++)
        k = i;
}


int main()
{
scoreboard first_inn , second_inn;

cout << "ENTER TEAM NAMES:" << endl;
string teamName;
cin>>teamName;
first_inn.set_teamName(teamName);
/*int pos = teamName.find("IND");
cout<<pos;
if(pos>=0)
    cout<<"working ... "<<endl;
return 0;
*/

cout << "  VS  ";

cin >> teamName;
second_inn.set_teamName(teamName);

//#### player setting ########//
fstream player("player.txt");
string p;
int idx = 1;
while(!player.eof()){
    getline(player,p);
    if(idx<=11) {
     first_inn.set_player(p);
    }else {
        second_inn.set_player(p);
    }
    idx++;
}
player.close();

/************************************/

while(total_over > first_inn.get_over())
{
    system("cls");
    system("color 09");
    cout<<first_inn.get_teamName()<< " BATING :"<<endl;
    cout<<"...............................................................\n\n\n"<<endl;
    first_inn.over();
}

cout<<"FIRST INNINGS STATUS"<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"TOTAL RUN = "<<first_inn.get_run()<<" WICKET = "<<first_inn.get_wicket()<<endl;

fordelay(100000000000);

while(total_over > second_inn.get_over())
{
    system("cls");
    system("color 09");
    cout<<second_inn.get_teamName()<< " BATING :"<<endl;
    cout<<"...............................................................\n\n\n"<<endl;
    second_inn.over();
}

cout<<"SECOND INNINGS STATUS"<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"TOTAL RUN = "<<second_inn.get_run()<<" WICKET = "<<second_inn.get_wicket()<<endl;

if(first_inn.get_run() > second_inn.get_run())
    cout<<first_inn.get_teamName()<<" WINS "<<endl;


else if(first_inn.get_run() < second_inn.get_run())
    cout<<second_inn.get_teamName()<<" WINS "<<endl;

else
    cout<<"MATCH DRAW "<<endl;


return 0;
}
