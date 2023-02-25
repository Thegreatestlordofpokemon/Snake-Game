#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup(){
   gameOver = false;
   dir = STOP;
   x = width / 2;
   y = height / 2;
   fruitX = rand() % width;
   fruitY = rand() % height;
   score = 0;
   

}
void Draw(){
   system("cls");
   for ( int i = 0; i < width + 2; i++)
   cout << "#";
    cout << endl;
   
   for (int i = 0; i < height; i++)
    {
     for (int j = 0; j < width; j++)
     {
        if (j == 0)
           cout << "#";
        if (i == y && j == x)
           cout << "0";
        else if (i == fruitY && j == fruitX)
        cout << "F";
           else
           {
            bool print1 = false;
            for(int k = 0; k < nTail; k++)
            {
             
            if(tailX[k] == j && tailY[k] == i)
             {
                print1 = true;
                cout << "o";
             }
             
            }
              if (!print1)
                cout << " ";  
           }
           
           

        if (j == width - 1)
           cout << "#";
        
     }
     cout << endl;
     }
    
    for ( int i = 0; i < width + 2; i++)
    cout << "#";
    cout << endl;
    cout << "Score: " << score;
   
   }
void Input(){
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'm' :
            gameOver = true;
            break;   
                        
        }
    }
    
}
void Logic(){

    int prevx = tailX[0];
    int prevy = tailY[0];
    int prev2x, prev2y;
     tailX[0] = x;
     tailY[0] = y;
    for(int i = 1; i < nTail; i++){
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevx;
        tailY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
       
    }

    switch (dir)
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
      default:
        break;
    }
    //if(x > width || x < 0 || y > height || y < 0)
    //gameOver = true;

    if(x >= width) x = 0; else if(x < 0)  x = width - 1;
    if(y >= height) y = 0; else if(y < 0) y = height - 1;

    
    for (int i = 0; i < nTail; i++)
    {
        if(tailX[i] == x && tailY[i] == y){
            gameOver = true;
        }
    }
    
    if(x == fruitX && y == fruitY)
    {
         nTail++;
         score += 10;
         fruitX = rand() % width;
         fruitY = rand() % height;
         
    }
    

}

int main(){
   
    Setup();
    while(!gameOver){
    Draw();    
    Input();
    Logic();
    Sleep(100);
    
    }
   
    


    return 0;
}