#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void fillWithZeros(char** M, int m, int n){
  //fills the matrix with zeros
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      M[i][j] = '0';
    }
  }
}

void printMatrix(char** M, int n, int m){
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<< M[i][j]<<" ";
    }
    cout<< endl;
  }
}

void colorOnePixel(char** M, int x, int y, char color){
  M[x][y] = color;
}

void colorLineRow(char** M, int y, int x1, int x2, char color){
  for(int i=x1;i<=x2;i++){
    M[y][i] = color;
  }
}

void colorLineColumn(char** M, int x, int y1, int y2, char color){
  for(int i=y1;i<=y2;i++){
    M[i][x] = color;
  }
}

void colorRectangle(char** M, int x1, int x2, int y1, int y2, char color){
  for(int i=x1;i<=x2;i++){
    for(int j=y1;j<=y2;j++){
      M[i][j] = color;
    }
  }
}

void colorRegion(char** M, int n, int m, int x, int y, char color){
  //saving the pixel's original color
  char actualColor = M[x][y];

  //coloring the target pixel in the new color
  colorOnePixel(M, x, y, color);

  //using recursion to test if the adjacent pixels are the same color
  if(M[x+1][y] == actualColor && x+1 < m){
    colorRegion(M, m, n, x+1, y, color);
  }
  if(M[x-1][y] == actualColor && x-1 >= 0){
    colorRegion(M, m, n, x-1, y, color);
  }
  if(M[x][y+1] == actualColor && y+1 < n){
    colorRegion(M, m, n, x, y+1, color);
  }
  if(M[x][y-1] == actualColor && y-1 >= 0){
    colorRegion(M, m, n, x, y-1, color);
  }
}

void saveInFile(char** M, int n, int m, string name){
  ofstream file;
  file.open(name);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      file<<M[i][j]<<" ";
    }
    file<<endl;
  }
}

int main() {
  char op;
  bool ctrl = true;
  int m,n,x1,y1,x2,y2;
  string name;
  char **M, color;
  while(ctrl){
    cin>>op;

    switch(op){
      case 'I':{
        cin>>m>>n;
        //creating matrix
        M = new char*[n];
        for(int i=0;i<n;i++){
          M[i] = new char[m];
        }

        fillWithZeros(M, n, m);
        break;
      }

      case 'L':{
        cin>>x1>>y1>>color;
        colorOnePixel(M, y1-1, x1-1, color);
        break;
      }
      
      case 'X':{
        ctrl = false;

        //deleting the matrix
        for(int i=0;i<n;i++){
          delete [] M[i];
        }
        delete [] M;
        break;
      }
      
      case 'C':{
        fillWithZeros(M, m, n);
        break;
      }
      
      case 'P':{
        //this case is for printing the matrix, for debugging purposes
        //this should not be used in the complete code!
        printMatrix(M, m, n);
        break;
      }

      case 'V':{
        cin>>x1>>y1>>y2>>color;
        colorLineColumn(M, x1-1, y1-1, y2-1, color);
        break;
      }

      case 'H':{
        cin>>x1>>x2>>y1>>color;
        colorLineRow(M, y1-1, x1-1, x2-1, color);
        break;
      }

      case 'K':{
        cin>>x1>>y1>>x2>>y2>>color;
        colorRectangle(M, x1-1, x2-1, y1-1, y2-1, color);
        break;
      }

      case 'S':{
        cin>>name;
        saveInFile(M, m, n, name);
        break;
      }

      case 'F':{
        cin>>x1>>y1>>color;
        colorRegion(M, m, n, x1-1, y1-1, color);
        break;
      }
      
      default:{
        break;
      }
    }
  }
  return 0;
}