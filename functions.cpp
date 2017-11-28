#include<iostream>
#include"functions.h"
#include<stdlib.h>
#include<list>
#include<algorithm>

using namespace std;


bool checkList(vector<double> vec, int vbl){
  //check is variable is in vector
  if (find(vec.begin(),vec.end(),vbl) != vec.end()){
    return true;
  }
  else{
    return false;
  }
}
//checked and working

//Easier at this stage to randomly calculate your positions without calling a function to do so (can come back to this later if necessary)

double totalEnergy(int structure, int N, double J){
  //calculate the total energy of the stucture
  
  int energy = 0;
  for(int i=0;i < (N-1);i++){
    energy = energy + J[structure[i]][structure[i+1]];
  }
  
  return energy;
}

//to check

int moveTo(int current, int occupied){
  //find, if any, a position current amino acid can move to
  
  int x = current[0];
  int y = current[1];
  int poss_moves = ((x+1,y),(x-1,y),(x,y+1),(x,y-1),(x+1,y+1),(x-1,y+1),(x+1,y-1),(x-1,y-1));
  int to_delete = ();
  for(int i=0;i < 8;i++){
    if (checkList(occupied,poss_moves[i] == true)){
      to_delete.insert(poss_moves[i]);
    }
  }  
  for(int j=0;j < to_delete.size();j++){
    poss_moves.remove(to_delete[j]);
  }
  
  return poss_moves;
}

//to check

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
