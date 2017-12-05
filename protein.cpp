#include"functions.h"

using namespace std;

int main(int argc, char *argv[]){
  //CHECK IF ARGC == 0
  //int timer = argv[2];
  int pro_len = 20;

  //int counter = 0
  // initialise the random seed to be time
  srand(time(NULL));

  /* initialise the protein structure with numbers 0-19 for the 20
  unique amino acid types */
  vector<int> pro_structure;
  while(pro_structure.size() < pro_len){
    int ri = rand() % 20;
    pro_structure.push_back(ri);
  }

  /* initialise the energy matrix with numbers 0-1 for the attaraction
  energies felt between pairs of each of the 20 amino acid types */
  vector<vector<double> > energy_mat;
  for(int a; a < 20; a++){
    vector<double> column;
    for(int b; b < 20; b++){
      double rd = (rand() % 100);
      column.push_back(rd);
    }
    energy_mat.push_back(column);
  }

  /*FIX ENERGY CALLING
  cout << pro_structure[0] << "\n";
  cout << pro_structure[1] << "\n";
  int * first;
  int * second;
  first = &pro_structure[0];
  second = &pro_structure[1];
  int en = energy_mat[*first][*second];
  cout << en;*/
  
  //-----------------------------------------------------------------
  //testing
  for(int i = 0; i < pro_len; i++){
    cout << pro_structure[i] << ",";    
  }
  cout << "\n";
  
  for(int j = 0; j < 20; j++){
    for(int k = 0; k < 20; k++){
      cout << energy_mat[j][k] << ",";
    }
    cout << "\n";
  }
  
}

