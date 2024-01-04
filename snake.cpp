#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;
int x, y, fruitx, fruity, score;
enum direction
{
   STOP = 0,
   LEFT,
   RIGHT,
   BOTTOM,
   TOP
};
direction dir;
vector<int> histX;
vector<int> histY;

void setup()
{
   gameOver = false;
   dir = STOP;
   x = width / 2;
   y = height / 2;
   fruitx = rand() % width;
   fruity = rand() % height;
   score = 0;
}

void draw()
{
   system("cls");
   cout << "#####################";
   cout << endl;
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         bool char_not_printed = true;
         for (int z = 0; z < score; z++)
         {
            if (histX[z] == j && histY[z] == i)
            {
               cout << "O";
               char_not_printed = false;
            }
         }
         if (j == 0 || j == width - 1)
            cout << "#";
         if (i == y && j == x)
            cout << "O";
         else if (i == fruity && j == fruitx)
            cout << "F";
         else if (char_not_printed){
            cout << " ";
         }
      }
      cout << endl;
   }

   cout << "#####################";
   cout << endl
        << "Score:" << score << endl;
}

void input()
{
   if (_kbhit())
   {
      switch (_getch())
      {
      case 'a':
         if (dir != RIGHT)
         dir = LEFT;
         break;
      case 's':
         if (dir != TOP)
         dir = BOTTOM;
         break;
      case 'd':
         if (dir != LEFT)
         dir = RIGHT;
         break;
      case 'w':
         if (dir != BOTTOM)
         dir = TOP;
         break;
      case 'x':
         gameOver = true;
         break;
      case 'r':
         x = width / 2;
         y = height / 2;
      }
   }
}

void logic()
{
   histX.insert(histX.begin(), x);
   histY.insert(histY.begin(), y);
   switch (dir)
   {
   case LEFT:
      --x;
      break;
   case RIGHT:
      x++;
      break;
   case TOP:
      y--;
      break;
   case BOTTOM:
      y++;
      break;
   default:
      break;
   }

   if (x > width || x < 0)
      x = width - x;

   if (y > height || y < 0)
      y = height - y;
   if (x == fruitx && y == fruity)
   {
      score = score + 1;
      fruitx = rand() % width;
      fruity = rand() % height;
   }
   for(int i=0;i<score;i++){
         if(histX[i] == x && histY[i] == y)
         gameOver=true;
      }
   
}

int main()
{
   setup();
   while (!gameOver)
   {
      draw();
      input();
      logic();
      Sleep(20);
      
   }
}
