#include"functions.h"

int checkList(const struct occupied * vec,int vbl[],int N){
  //check is an array is in a 3D array of arrays
  int is_in = -1;
  for(int i = 0; i < N; i++){
    if(vec[i].x == vbl[0] && vec[i].y == vbl[1] && vec[i].z == vbl[2]){
      is_in = i;
      break;
    }
  }
  return is_in;
}

int checkStruct(const struct occupied * vec, const struct occupied vbl, int N){
  //check a struct is in an array of structs and updates an array with their positions
  int is_in = -1;
  for(int i = 0; i < N; i++){
    if(vec[i].x == vbl.x && vec[i].y == vbl.y && vec[i].z == vbl.z){
      is_in = i;
      break;
    }
  }
  return is_in;
}

double totalEnergy(int structure[],const struct occupied * occupied,int N,double J[20][20]){
  //calculate the total energy of the stucture
  double energy = 0;
  for(int w = 0; w < N; w++){
    int x = occupied[w].x;
    int y = occupied[w].y;
    int z = occupied[w].z;

    struct occupied poss_positions[8];
    poss_positions[0].x = x+1;
    poss_positions[0].y = y;
    poss_positions[0].z = z;
    poss_positions[1].x = x-1;
    poss_positions[1].y = y;
    poss_positions[1].z = z;
    poss_positions[2].x = x;
    poss_positions[2].y = y+1;
    poss_positions[2].z = z;
    poss_positions[3].x = x;
    poss_positions[3].y = y-1;
    poss_positions[3].z = z;
    poss_positions[4].x = x;
    poss_positions[4].y = y;
    poss_positions[4].z = z+1;
    poss_positions[5].x = x;
    poss_positions[5].y = y;
    poss_positions[5].z = z-1;

    //check if poss_moves coordinates are occupied
    for(int i = 0; i < 8; i++){
      int check = checkStruct(occupied,poss_positions[i],N);
      if(check != -1 && check != w-1 && check != w+1){
	cout << "(" << x << "," << y << "," << z << ") is neighbours with " << "(" << poss_positions[i].x << "," << poss_positions[i].y << "," << poss_positions[i].z << ") with energy " << J[structure[w]][structure[check]] << "\n";
	energy = energy + J[structure[w]][structure[check]];
      } 
    }
  }
  energy = energy/2;
  return energy;
}

void moveTo(int current[],const struct occupied * occupied,int N, vector<vector<int> >& vec_poss_moves){
  //find, if any, a position current amino acid can move to
  int x = current[0];
  int y = current[1];
  int z = current[2];

  struct occupied poss_moves[26];
  poss_moves[0].x = x-1;
  poss_moves[0].y = y-1;
  poss_moves[0].z = z-1;
  poss_moves[1].x = x-1;
  poss_moves[1].y = y-1;
  poss_moves[1].z = z+1;
  poss_moves[2].x = x+1;
  poss_moves[2].y = y-1;
  poss_moves[2].z = z-1;
  poss_moves[3].x = x+1;
  poss_moves[3].y = y-1;
  poss_moves[3].z = z+1;
  poss_moves[4].x = x;
  poss_moves[4].y = y-1;
  poss_moves[4].z = z;
  poss_moves[5].x = x+1;
  poss_moves[5].y = y+1;
  poss_moves[5].z = z-1;
  poss_moves[6].x = x+1;
  poss_moves[6].y = y+1;
  poss_moves[6].z = z+1;
  poss_moves[7].x = x+1;
  poss_moves[7].y = y;
  poss_moves[7].z = z;
  poss_moves[8].x = x-1;
  poss_moves[8].y = y+1;
  poss_moves[8].z = z-1;
  poss_moves[9].x = x-1;
  poss_moves[9].y = y+1;
  poss_moves[9].z = z+1;
  poss_moves[10].x = x;
  poss_moves[10].y = y+1;
  poss_moves[10].z = z;
  poss_moves[11].x = x-1;
  poss_moves[11].y = y;
  poss_moves[11].z = z;
  poss_moves[12].x = x-1;
  poss_moves[12].y = y-1;
  poss_moves[12].z = z;
  poss_moves[13].x = x+1;
  poss_moves[13].y = y-1;
  poss_moves[13].z = z;
  poss_moves[14].x = x+1;
  poss_moves[14].y = y+1;
  poss_moves[14].z = z;
  poss_moves[15].x = x+1;
  poss_moves[15].y = y-1;
  poss_moves[15].z = z;
  poss_moves[16].x = x;
  poss_moves[16].y = y-1;
  poss_moves[16].z = z-1;
  poss_moves[17].x = x;
  poss_moves[17].y = y-1;
  poss_moves[17].z = z+1;
  poss_moves[18].x = x+1;
  poss_moves[18].y = y;
  poss_moves[18].z = z-1;
  poss_moves[19].x = x+1;
  poss_moves[19].y = y;
  poss_moves[19].z = z+1;
  poss_moves[20].x = x;
  poss_moves[20].y = y+1;
  poss_moves[20].z = z-1;
  poss_moves[21].x = x;
  poss_moves[21].y = y+1;
  poss_moves[21].z = z+1;
  poss_moves[22].x = x-1;
  poss_moves[22].y = y;
  poss_moves[22].z = z+1;
  poss_moves[23].x = x-1;
  poss_moves[23].y = y;
  poss_moves[23].z = z-1;
  poss_moves[24].x = x;
  poss_moves[24].y = y;
  poss_moves[24].z = z-1;
  poss_moves[25].x = x;
  poss_moves[25].y = y;
  poss_moves[25].z = z+1;
    
  //check if poss_moves coordinates are occupied
  for(int v = 0; v < 26; v++){
    if(checkStruct(occupied,poss_moves[v],N) == -1){
      vector<int> to_add;
      to_add.push_back(poss_moves[v].x);
      to_add.push_back(poss_moves[v].y);
      to_add.push_back(poss_moves[v].z);
      vec_poss_moves.push_back(to_add);
    }
  }
}
 
void canMove(int current[],int position,const struct occupied * occupied,int N,vector<vector<int> > vec_poss_moves,vector<vector<int> >& vec_final_poss_moves){
  //check to see if selected amino acid can move to a neighbouring point
  //accounting for end amino acid cases
  if(position == 0){
    int nextx = occupied[position+1].x;
    int nexty = occupied[position+1].y;
    int nextz = occupied[position+1].z;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      int z = vec_poss_moves[i][2];
      if(pow(pow((x-nextx),2.0)+pow((y-nexty),2.0)+pow((z-nextz),2.0),0.5) == 1){
	vec_final_poss_moves.push_back(vec_poss_moves[i]);
      }
    }
  }
  else if(position == N-1){
    int prevx = occupied[position-1].x;
    int prevy = occupied[position-1].y;
    int prevz = occupied[position-1].z;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      int z = vec_poss_moves[i][2];
      if(pow(pow((x-prevx),2.0)+pow((y-prevy),2.0)+pow((z-prevz),2.0),0.5) == 1){
	vec_final_poss_moves.push_back(vec_poss_moves[i]);
      }
    }
  }
  else{
    int prevx = occupied[position-1].x;
    int prevy = occupied[position-1].y;
    int prevz = occupied[position-1].z;
    int nextx = occupied[position+1].x;
    int nexty = occupied[position+1].y;
    int nextz = occupied[position+1].z;
    for(int i = 0; i < vec_poss_moves.size(); i++){
      int x = vec_poss_moves[i][0];
      int y = vec_poss_moves[i][1];
      int z = vec_poss_moves[i][2];
      if((pow(pow((x-prevx),2.0)+pow((y-prevy),2.0)+pow((z-prevz),2.0),0.5) == 1) && //
	 (pow(pow((x-nextx),2.0)+pow((y-nexty),2.0)+pow((z-nextz),2.0),0.5) == 1)){
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
      occupied[position].z = previous_pos[2];
    }
  }
}

double length(const struct occupied * occupied, int N){
  //calculate the 'crow flies' distance between protein start and end points

  return pow(pow((occupied[0].x-occupied[N-1].x),2.0)+pow((occupied[0].y-occupied[N-1].y),2.0)+pow((occupied[0].z - occupied[N-1].z),2.0),0.5);  
}
