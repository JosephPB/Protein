#include"functions.h"

int main(int argc, char *argv[]){
  //CHECK IF ARGC == 0
  int pro_len = atoi(argv[1]);
  //int timer = argv[2];
 
  //int counter = 0

  // initialise the random seed to be time
  srand(time(NULL));

  /* initialise the protein structure with numbers 0-19 for the 20
  unique amino acid types */
  int pro_structure[pro_len];
  for(int a = 0; a < pro_len; a++){
    int ri = rand() % 20;
    pro_structure[a] = ri;
  }

  /* initialise the energy matrix with numbers 0-1 for the attaraction
  energies felt between pairs of each of the 20 amino acid types */
  double energy_mat [20][20];
  for(int b = 0; b < 20; b++){
    for(int c = 0; c < 20; c++){
      double rd = (rand() % 100);
      energy_mat[b][c] = rd;
    }
  }

  // initialise protein positions from a non-crossing random walk
  int pro_pos[pro_len][2];
  int steps[2] = {-1,1};
  pro_pos[0][0] = 0;
  pro_pos[0][1] = 0;
  int d = 1;
  while(d != pro_len){
    int coord = rand() % 2;
    if(coord == 0){
      int step = rand() % 2;
      int to_add[2] = {pro_pos[d-1][0]+steps[step],pro_pos[d-1][1]};
      if(checkList(pro_pos,to_add,d) == false){
	pro_pos[d][0] = to_add[0];
	pro_pos[d][1] = to_add[1];
	d = d + 1;
      }
    }
    if(coord == 1){
      int step = rand() % 2;
      int to_add[2] = {pro_pos[d-1][0],pro_pos[d-1][1]+steps[step]};
      if(checkList(pro_pos,to_add,d) == false){
	pro_pos[d][0] = to_add[0];
	pro_pos[d][1] = to_add[1];
	d = d + 1;
      }
    }
  }    

  //choose a an amino acid at random
  int randpos = rand() % pro_len;
  int pro_current[2] = {pro_pos[randpos][0],pro_pos[randpos][1]};

  //find, if any, the possible positions the selected amino acid can move to
  vector<vector<int> > vec_possmoves;
  moveTo(pro_current, pro_pos,pro_len,vec_possmoves);
  

  
  

  //-----------------------------------------------------------------
  //testing
  
  for(int i = 0; i < pro_len; i++){
    cout << pro_structure[i] << ",";    
  }
  cout << "\n";
  
  cout << totalEnergy(pro_structure,pro_len,energy_mat) << "\n";

  for(int g = 0; g < pro_len; g++){
    cout << "(";
    for(int h = 0; h < 2; h++){
      cout << pro_pos[g][h] << ",";    
    }
    cout << ")";
  }
  cout << "\n";

  cout << "random position is (" << pro_current[0] << "," << pro_current[1] << ")\n";

  for(int i = 0; i < vec_possmoves.size(); i++){
    cout << "(";
    for(int j = 0; j < 2; j++){
      cout << vec_possmoves[i][j] << ",";
    }
    cout << ")";
  }
  cout << "\n";
}

