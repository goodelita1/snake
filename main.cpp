#include <iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
  bool gameover;
    int score;
    int x,y;
    int fx,fy;
    int tailx[100], taily[100];
    int ntail;
    const int width = 60,height = 40;
    enum dir {STOP=0 , UP , DOWN , LEFT , RIGHT};
    dir direct;
void start()
{
    gameover = false;
    direct = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;

}
void print()
{
    system("cls");
    for(int i=0 ; i<width+1 ; i++)
        cout<<"#";
        cout<<endl;
    for(int i=0 ; i<height ; i++)
    {
        for(int j=0 ; j<width ; j++)
        {
            if(j==0 || j==width -1)
                cout<<"#";
            if(i == y && j == x)
                cout<<"O";
            else if(i == fy && j == fx)
                cout<<"*";
            else{
                    bool pr = false;
                    for(int k = 0; k < ntail ; k++ ) {
                        if(tailx[k] ==j && taily[k] == i){
                            pr = true;
                            cout << "o";
                        }
                    }
                 if(!pr)
                 cout<<" ";
            }
        }
        cout<<endl;
    }

     for(int i=0 ; i<width+1 ; i++)
        cout<<"#";
        cout<<endl;
        cout<<"Score"<<" "<<score<<endl;
}
void input()
{
    if(_kbhit()) {
        switch(_getch())
        {
    case 'a':
        direct = LEFT;
        break;
    case 's':
        direct = DOWN;
        break;
    case 'd':
        direct = RIGHT;
        break;
    case 'w':
        direct = UP;
        break;
    case 'x':
        gameover = true;
        break;
        }
    }
}
void logic(){
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x , prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1 ; i < ntail ; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch(direct)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    //if(x >width || x < 0 || y > height ||y < 0)
     //   gameover = true;
     if(x >= width-1)
        x = 0;
     else if(x < 0)
        x = width - 1;
     if(y >= height-1)
        y = 0;
     else if(y < 0)
        y = height - 1;
        for(int  i = 0 ; i < ntail ; i++){
            if(tailx[i] == x && taily[i] == y)
                gameover =true;
        }
    if(x == fx && y == fy)
    {
        score += 10;
        fx = rand() % width;
        fy = rand() % height;
        ntail++;
    }

}
int main()
{
    srand(time(NULL));
    start ();
    while(!gameover)
    {
        print();
         input();
         logic();
    }
    system("PAUSE");
    return 0;
}
