#include <iostream>
#include <string>
using namespace std;


bool testAccepted(string std[], string ans[], int size_ans, int size_std){
  if(size_ans != size_std)
    return false;
  
  for(int i=0;i<size_ans;i++){
    if(std[i] != ans[i])
      return false;

    for(int j=0;j<std[i].length();j++){
        if(std[i].at(j) != ans[i].at(j))
            return false;
    }
  }
  
  return true;
}

bool testPresentation(string std[], string ans[], int size_ans, int size_std){
  
  
  if(size_ans != size_std)
    return false;
  
  //iterating in the string arrays
  for(int i=0;i<size_ans;i++){
    string stdBuffer="", ansBuffer="";
    
    //looking for the numerical values in the std array
    for(int j=0;j<std[i].length();j++){
      if(isdigit(std[i].at(j))){
        stdBuffer.append(std[i].substr(j,1));
      }
    }

    //looking for the numerical values in the ans array
    for(int j=0;j<ans[i].length();j++){
      if(isdigit(ans[i].at(j))){
        ansBuffer.append(ans[i].substr(j,1));
      }
    }

    if(stdBuffer != ansBuffer)
      return false;
  }
  
  return true;
}

void compareAnswers(string std[], string ans[], int size_ans, int size_std, int run){
  if(testAccepted(std, ans, size_ans, size_std)){
    cout<<"Run #"<<run<<": Accepted"<<endl;
  }else if(testPresentation(std, ans, size_ans, size_std)){
    cout<<"Run #"<<run<<": Presentation Error"<<endl;
  }else{
    cout<<"Run #"<<run<<": Wrong Answer"<<endl;
  }
  
}

int main() {
  int n, m, run = 0;
  bool ctrl = true;
  
  while(ctrl){
    run ++;
    cin>>n;
    
    //Exits the program
    if(n == 0){
      ctrl = false;
      break;
    }
    
    string standard[n];
    for(int i=0;i<n;i++){
      cin.ignore();
      getline(cin, standard[i], '\n');
    }

    cin>>m;

    string team[m];
    for(int i=0;i<m;i++){
      cin.ignore();
      getline(cin, team[i], '\n');
    }

    compareAnswers(standard, team, m, n, run);
  }
  
  return 0;
}