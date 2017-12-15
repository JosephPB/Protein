#include"functions.h"

int main(int argc, char *argv[]){

  cout << fixed;
  cout << setprecision(8);
  
  int pro_len;
  cout << "Number of amino acids in protein chain: ";
  cin >> pro_len;
  char unfolded;
  cout << "Initialise an unfolded protein (y/n): ";
  cin >> unfolded;
  int temp;
  cout << "Temperature: ";
  cin >> temp;
  char e_type;
  cout << "Energy matrix ditribution (integer uniform/random uniform/jumps -1,1): ";
  cin >> e_type;
  double range_start;
  double range_end;
  if(e_type == 'i' || e_type == 'r'){
    cout << "Beginning at range: ";
    cin >> range_start;
    cout << "Ending at range: ";
    cin >> range_end;
  }
  int timer;
  cout << "Number of Monte Carlo time steps: ";
  cin >> timer;
 
  //initialise the random seed to be time
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
  double number;
  if(e_type == 'i'){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution (range_start,range_end);
    for(int b = 0; b < 20; b++){
      for(int c = 0; c <= b; c++){
	number = distribution(generator);
	energy_mat[b][c] = number;
	energy_mat[c][b] = number;
      }
    }
  }
  if(e_type == 'j'){
    int sign[2] = {-1,1};
    for(int b = 0; b < 20; b++){
      for(int c = 0; c <= b; c++){
        number = sign[rand() % 2];
	energy_mat[b][c] = number;
	energy_mat[c][b] = number;
      }
    }
  }
  if(e_type == 'r'){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution (range_start,range_end);
    for(int b = 0; b < 20; b++){
      for(int c = 0; c <= b; c++){
	number = distribution(generator);
	energy_mat[b][c] = number;
	energy_mat[c][b] = number;
      }
    }
  }

  //initialise protein positions
  int pro_pos[pro_len][2];
  if(unfolded == 'y'){
    for(int i = 0; i < pro_len; i++){
      pro_pos[i][0] = i;
      pro_pos[i][1] = 0;
    }
  }
  else if(unfolded == 'n'){
    int steps[2] = {-1,1};
    pro_pos[0][0] = 0;
    pro_pos[0][1] = 0;
    int d = 1;
    int counter = 0;
    while(d != pro_len){
      int coord = rand() % 2;
      if(coord == 0){
	int step = rand() % 2;
	int to_add[2] = {pro_pos[d-1][0]+steps[step],pro_pos[d-1][1]};
	if(checkList(pro_pos,to_add,d) == -1){
	  pro_pos[d][0] = to_add[0];
	  pro_pos[d][1] = to_add[1];
	  d = d + 1;
	}
	else{
	  counter = counter + 1;
	  if(counter == pro_len * 5){
	    cout << "time elapsed for random walk\n";
	    return EXIT_FAILURE;
	  }
	}
      }
      if(coord == 1){
	int step = rand() % 2;
	int to_add[2] = {pro_pos[d-1][0],pro_pos[d-1][1]+steps[step]};
	if(checkList(pro_pos,to_add,d) == -1){
	  pro_pos[d][0] = to_add[0];
	  pro_pos[d][1] = to_add[1];
	  d = d + 1;
	}
	else{
	  counter = counter + 1;
	  if(counter == pro_len * 5){
	    cout << "time elapsed for random walk\n";
	    return EXIT_FAILURE;
	  }
	}
      }
    }
  }

  for(int i = 0; i < pro_len; i++){
    cout << "(";
    for(int j = 0; j < 2; j++){
      cout << pro_pos[i][j] << ",";
    }
    cout << ")";
  }
  cout << "\n";

  double energy = totalEnergy(pro_structure,pro_pos,pro_len,energy_mat);
  
  cout << "energy is: " << energy << "\n";

  double len = length(pro_pos,pro_len);

  char cont;
  cout << "Would you like to continue to the time steps? (y/n) ";
  cin >> cont;
  if(cont == 'n'){
    return EXIT_FAILURE;
  }

  int counter2 = 0;

  //set up csv file
  remove("data.csv");
  ofstream outputFile;
  string filename = ("data.csv");
  outputFile.open(filename);
  outputFile << "time" << "," << "energy" << "," << "length" << "," << temp << "," << pro_len << endl;
  outputFile << counter2 << "," << energy << "," << len << endl;

  while(counter2 != timer-1){
    //choose a an amino acid at random
    int randpos = rand() % pro_len;
    cout << "randpos is: " << randpos << "\n";
    int pro_current[2] = {pro_pos[randpos][0],pro_pos[randpos][1]};

    //find, if any, the possible positions the selected amino acid can move to
    vector<vector<int> > vec_possmoves;
    moveTo(pro_current, pro_pos,pro_len,vec_possmoves);
    cout << "poss moves are: ";
    for(int i = 0; i < vec_possmoves.size(); i++){
      cout << "(";
      for(int j = 0; j < 2; j++){
	cout << vec_possmoves[i][j] << ",";
      }
      cout << ")";
    }
    cout << "\n";
    vector<vector<int> > vec_finalpossmoves;
    if(vec_possmoves.size() != 0){
      canMove(pro_current,randpos,pro_pos,pro_len,vec_possmoves,vec_finalpossmoves);
      if(vec_finalpossmoves.size() != 0){
	cout << "final moves are: ";
	for(int i = 0; i < vec_finalpossmoves.size(); i++){
	  cout << "(";
	  for(int j = 0; j < 2; j++){
	    cout << vec_finalpossmoves[i][j] << ",";
	  }
	  cout << ")";
	}
	cout << "\n";

    
	//account for more than one possible move
	int randpos2 = rand() % vec_finalpossmoves.size();
	int to_move[2];
	to_move[0] = vec_finalpossmoves[randpos2][0];
	to_move[1] = vec_finalpossmoves[randpos2][1];

	cout << "want to move (" << pro_pos[randpos][0] << "," << pro_pos[randpos][1] << ") to (" << to_move[0] << "," << to_move[1] << ")\n";
    
	//calculate energy difference
	int newpro_pos[pro_len][2];
	copy(&pro_pos[0][0], &pro_pos[0][0]+pro_len*2, &newpro_pos[0][0]);
	newpro_pos[randpos][0] = to_move[0];
	newpro_pos[randpos][1] = to_move[1];
	double deltaE = totalEnergy(pro_structure,newpro_pos,pro_len,energy_mat) - totalEnergy(pro_structure,pro_pos,pro_len,energy_mat);

	cout << "energy difference is: " << deltaE << "\n";
    
	/* move amino acid if the move lowers the energy or is less that the thermal
	   fluctuations */
	doMove(deltaE,pro_pos,randpos,to_move,temp);

	cout << "moved\n";
	for(int i = 0; i < pro_len; i++){
	  cout << "(";
	  for(int j = 0; j < 2; j++){
	    cout << pro_pos[i][j] << ",";
	  }
	  cout << ")";
	}
	cout << "\n";

	energy = totalEnergy(pro_structure,pro_pos,pro_len,energy_mat);
	
	cout << "new energy is: " << energy << "\n";

	//calculate the 'length' of the protein
	len = length(pro_pos,pro_len);
	cout << "the crow flies length is: " << len << "\n";
      }
      else{
	cout << "there are no possible final moves\n";
      }
    }
    else{
      cout << "there are no possible moves\n";
    }
    counter2 = counter2 + 1;
    
    outputFile << counter2 << "," << energy << "," << len << endl;
  }
  outputFile.close();
  return 0;
}

