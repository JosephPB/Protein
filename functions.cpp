#include"functions.h"

bool checkList(int vec[][2],int vbl[],int N){
  //check is variable is in array
  bool is_in = false;
  for(int z = 0; z < N; z++){
    if(vec[z][0] == vbl[0] && vec[z][1] == vbl[1]){
      is_in = true;
      break;
    }
  }
  return is_in;
}

//checked and working

double totalEnergy(int structure[],int N,double J[20][20]){
  //calculate the total energy of the stucture
  //note that input must be as vectors
  
  int energy = 0;
  for(int w=0;w < (N-1);w++){
    energy = energy + J[structure[w]][structure[w+1]];
  }
  return energy;
}

//checked and working

void moveTo(int current[],int occupied[][2],int N, vector<vector<int> >& vec_poss_moves){
  //find, if any, a position current amino acid can move to
  //----think about wrapping----
  int x = current[0];
  int y = current[1];

  int poss_moves[8][2] = {{x+1,y},{x-1,y},{x,y+1},{x,y-1},{x+1,y+1},{x-1,y+1},{x+1,y-1},{x-1,y+1}};

  //check if poss_moves coordinates are occupied
  for(int v = 0;v < 8;v++){
    if(checkList(occupied,poss_moves[v],N) == false){
      vector<int> to_add;
      to_add.push_back(poss_moves[v][0]);
      to_add.push_back(poss_moves[v][1]);
      vec_poss_moves.push_back(to_add);
    }
  }
}
 
//checked and working
/*
vector<vector<int> > canMove(vector<int> current, vector<vector<int> > occupied ,vector<vector<int> > poss_moves){
  //check to see if selected amino acid can move to a neighbouring point
  vector<vector<int> >::iterator it = find(occupied.begin(),occupied.end(),current);
  int list_position = distance(occupied.begin(),it);
  vector<int> prev = occupied[list_position-1];
  vector<int> next = occupied[list_position+1];
  vector<vector<int> > moves;
  for(int i=0;i < poss_moves.size();i++){
    int x = poss_moves[i][0];
    int y = poss_moves[i][1];
    if (prev[0]+1 == x || prev[0]-1 == x || prev[1]+1 == y || prev[1]-1 == y){
      if (next[0]+1 == x || next[0]-1 == x || next[1]+1 == y || next[1]-1 == y){
	moves.push_back(poss_moves[i]);
      }
    }
  }
  return moves;
}

//to check

double doMove(double E_move, int current, int target){
  //move the selected amino acid to the target position
  
}

//to check

double length(vector<vector<int> > occupied, int N){
  //calculate the 'crow flies' distance between protein start and end points

  return pow(pow((occupied[0][0]-occupied[N-1][0]),2.0)+pow((occupied[0][1]-occupied[N-1][1]),2.0),0.5);  
}

//checked and working
*/
