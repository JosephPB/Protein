#include"functions.h"

int checkList(const struct occupied * vec,int vbl[],int N){
  //check is avariable is in array
  int is_in = -1;
  for(int z = 0; z < N; z++){
    if(vec[z].x == vbl[0] && vec[z].y == vbl[1]){
      is_in = z;
      break;
    }
  }
  return is_in;
}

double totalEnergy(int structure[],struct occupied * occupied,int N,double J[20][20]){
  //calculate the total energy of the stucture
  double energy = 0;
  for(int w = 0; w < N; w++){
    int x = occupied[w].x;
    int y = occupied[w].y;

    int poss_positions[4][2] = {{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
    
    //check if poss_moves coordinates are occupied
    for(int v = 0; v < 4; v++){
      int check = checkList(occupied,poss_positions[v],N);
      if(check != -1 && check != w+1 && check != w-1){
	cout << "(" << x << "," << y << ") is neighbours with " << "(" << poss_positions[v][0] << "," << poss_positions[v][1] << ") with energy " << J[structure[w]][structure[check]] << "\n";
	energy = energy + J[structure[w]][structure[check]];
      }
    }
  }
  energy = energy/2;
  return energy;
}

void moveTo(int current[],struct occupied * occupied,int N, vector<vector<int> >& vec_poss_moves){
  //find, if any, a position current amino acid can move to
  int x = current[0];
  int y = current[1];

  int poss_moves[8][2] = {{x+1,y},{x-1,y},{x,y+1},{x,y-1},{x+1,y+1},{x-1,y+1},{x+1,y-1},{x-1,y-1}};

  //check if poss_moves coordinates are occupied
  for(int v = 0; v < 8; v++){
    if(checkList(occupied,poss_moves[v],N) == -1){
      vector<int> to_add;
      to_add.push_back(poss_moves[v][0]);
      to_add.push_back(poss_moves[v][1]);
      vec_poss_moves.push_back(to_add);
    }
  }
}
 
void canMove(int current[],int position,struct occupied * occupied,int N,vector<vector<int> > vec_poss_moves,vector<vector<int> >& vec_final_poss_moves){
  //check to see if selected amino acid can move to a neighbouring point
  //accounting for end amino acid cases
  if(position == 0){
    int nextx = occupied[position+1].x;
    int nexty = occupied[position+1].y;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      if(pow(pow((x-nextx),2.0)+pow((y-nexty),2.0),0.5) == 1){
	vec_final_poss_moves.push_back(vec_poss_moves[i]);
      }
    }
  }
  else if(position == N-1){
    int prevx = occupied[position-1].x;
    int prevy = occupied[position-1].y;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      if(pow(pow((x-prevx),2.0)+pow((y-prevy),2.0),0.5) == 1){
	vec_final_poss_moves.push_back(vec_poss_moves[i]);
      }
    }
  }
  else{
    int prevx = occupied[position-1].x;
    int prevy = occupied[position-1].y;
    int nextx = occupied[position+1].x;
    int nexty = occupied[position+1].y;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      if((pow(pow((x-prevx),2.0)+pow((y-prevy),2.0),0.5) == 1) && //
	 (pow(pow((x-nextx),2.0)+pow((y-nexty),2.0),0.5) == 1)){
	vec_final_poss_moves.push_back(vec_poss_moves[i]);
      }
    }
  }
}

void doMove(double E_move,struct occupied * occupied,int position,int previous_pos[], int temperature){
  //move the selected amino acid to the target position if it satisfies the conditions
  if(E_move < 0){
    cout << "moving will lower energy, moving... \n";
  }
  else{
    double boltzmann_constant = 1; //1.38064852*pow(10,-23);
    double boltzmann = exp(-E_move/(boltzmann_constant*temperature));
    cout << "fluctuation enegy is: " << boltzmann << "\n";
    double random = (double)rand() / (double)((unsigned)RAND_MAX +1);
    cout << "random barrier is: " <<  random << "\n";
    if(boltzmann > random){
      cout << "energy fluctuations greater than random barrier, moving... \n";
    }
    else{
      occupied[position].x = previous_pos[0];
      occupied[position].y = previous_pos[1];
    }
  }
}

//should I have srand ^^^ as I've declared it already in my main file? Do I NEED to pass a reference to change occupied?

double length(struct occupied * occupied, int N){
  //calculate the 'crow flies' distance between protein start and end points

  return pow(pow((occupied[0].x-occupied[N-1].x),2.0)+pow((occupied[0].y-occupied[N-1].y),2.0),0.5);  
  }
