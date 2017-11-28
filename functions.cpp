#include<iostream>
#include"functions.h"
#include<stdlib.h>
#include<list>
#include<algorithm>

using namespace std;



bool checkList(vector<vector<double> > vec, vector<double> vbl){
  //check is variable is in vector
  //note that input must be as vectors
  if (find(vec.begin(),vec.end(),vbl) != vec.end()){
    return true;
  }
  else{
    return false;
  }
}
//checked and working

//Easier at this stage to randomly calculate your positions without calling a function to do so (can come back to this later if necessary)

double totalEnergy(vector<int> structure, int N,vector<double> J){
  //calculate the total energy of the stucture
  //note that input must be as vectors
  
  int energy = 0;
  for(int i=0;i < (N-1);i++){
    energy = energy + J[structure[i]][structure[i+1]];
  }
  return energy;
}

//checked and working

int moveTo(vector<int> current, vector<int> occupied){
  //find, if any, a position current amino acid can move to
  //note that input must be as vectors
  int x = current[0];
  int y = current[1];
  vector<int> cd1;
  cd1.push_back(x+1);
  cd1.push_back(y);
  vector<int> cd2;
  cd2.push_back(x-1);
  cd2.push_back(y);
  vector<int> cd3;
  cd3.push_back(x);
  cd3.push_back(y+1);
  vector<int> cd4;
  cd4.push_back(x);
  cd4.push_back(y-1);
  vector<int> cd5;
  cd5.push_back(x+1);
  cd5.push_back(y+1);
  vector<int> cd6;
  cd6.push_back(x-1);
  cd6.push_back(y+1);
  vector<int> cd7;
  cd7.push_back(x+1);
  cd7.push_back(y-1);
  vector<int> cd8;
  cd8.push_back(x-1);
  cd8.push_back(y-1);

  vector<vector<int> > poss_moves;
  poss_moves.push_back(cd1);
  poss_moves.push_back(cd2);
  poss_moves.push_back(cd3);
  poss_moves.push_back(cd4);
  poss_moves.push_back(cd5);
  poss_moves.push_back(cd6);
  poss_moves.push_back(cd7);
  poss_moves.push_back(cd8);

  vector<vector<int> > to_delete;
  for(int i=0;i < 8;i++){
    if (checkList(occupied,poss_moves[i] == true)){
      to_delete.push_back(poss_moves[i]);
    }
  }  
  for(int j=0;j < to_delete.size();j++){   
    poss_moves.erase(find(poss_moves.being(),poss_moves.end(),to_delete[j]));
  }
  
  return poss_moves;
}

//checked and working

double canMove(int current, int occupied ,int poss_moves){
  //check to see if selected amino acid can move to a neighbouring point
  int list_position = find(occupied.begin(),occupied.end(),current);
  int prev = occupied[list_position-1];
  int next = occupied[list_position+1];
  int moves = ();
  for(int i=0;i < poss_moves.size();i++){
    int x = poss_moves[0];
    int y = poss_moves[1];
    if (prev[0]+1 == x || prev[0]-1 == x || prev[1]+1 == y || prev[1]-1 == y){
      if (next[0]+1 == x || next[0]-1 == x || next[1]+1 == y || next[1]-1 == y){
	moves.insert(poss_moves[i]);
      }
    }
  }
}

//to check

double doMove(double E_move, int current, int target){
  //move the selected amino acid to the target position
}

//to check

double length(int occupied, int N){
  //calculate the 'crow flies' distance between protein start and end points

  return (((occupied[0][0]-occupied[N-1])**2)+((occupied[0][1]-structure[N-1][1])**2))**0.5;
}

//to check
