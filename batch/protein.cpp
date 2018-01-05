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
  cout << "Energy matrix ditribution (integer uniform/random uniform/jumps -1,1): "; //enter i/r/j
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
  int seeder;
  cout << "Seed for process (0/seed): "; //enter 0 for no seed
  cin >> seeder;

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
    unsigned seed;
    if(seeder != 0){
      seed = seeder;
    }
    else{
      seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
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
    unsigned seed;
    if(seeder != 0){
      seed = seeder;
    }
    else{
      seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
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

  //initialise the random seed to be time
  srand(time(NULL));
  if(seeder != 0){
    srand(seeder);
  }
  
  //initialise protein positions
  struct occupied pro_pos[pro_len];
  if(unfolded == 'y'){
    for(int i = 0; i < pro_len; i++){
      pro_pos[i].x = i;
      pro_pos[i].y = 0;
      pro_pos[i].z = 0;
    }
  }
  else if(unfolded == 'n'){
    int steps[2] = {-1,1};
    pro_pos[0].x = 0;
    pro_pos[0].y = 0;
    pro_pos[0].z = 0;
    int d = 1;
    int counter = 0;
    while(d != pro_len){
      int coord = rand() % 3;
      if(coord == 0){
	int step = rand() % 2;
	int to_add[3] = {pro_pos[d-1].x+steps[step],pro_pos[d-1].y,pro_pos[d-1].z};
	if(checkList(pro_pos,to_add,d) == -1){
	  pro_pos[d].x = to_add[0];
	  pro_pos[d].y = to_add[1];
	  pro_pos[d].z = to_add[2];
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
	int to_add[3] = {pro_pos[d-1].x,pro_pos[d-1].y+steps[step],pro_pos[d-1].z};
	if(checkList(pro_pos,to_add,d) == -1){
	  pro_pos[d].x = to_add[0];
	  pro_pos[d].y = to_add[1];
	  pro_pos[d].z = to_add[2];
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
      if(coord == 2){
	int step = rand() % 2;
	int to_add[3] = {pro_pos[d-1].x,pro_pos[d-1].y,pro_pos[d-1].z+steps[step]};
	if(checkList(pro_pos,to_add,d) == -1){
	  pro_pos[d].x = to_add[0];
	  pro_pos[d].y = to_add[1];
	  pro_pos[d].z = to_add[2];
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
    cout << pro_pos[i].x << "," << pro_pos[i].y << "," << pro_pos[i].z << ")";
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
  string spro_len = to_string(pro_len);
  string stemp = to_string(temp);
  string filename;
  if(seeder != 0){
    filename = ("~/mt/batch/users/jbullock/plotting/seededTis" + stemp + "Lis" + spro_len +  ".csv");
  }
  else{
    filename = ("~/mt/batch/users/jbullock/plotting/Tis" + stemp + "Lis" + spro_len +  ".csv");
  }
  ofstream outputFile;
  outputFile.open(filename);
  outputFile << "time" << "," << "energy" << "," << "length" << "," << temp << "," << pro_len << endl;
  outputFile << counter2 << "," << energy << "," << len << endl;

  srand(time(NULL));
  while(counter2 != timer-1){
    //choose a an amino acid at random
    int randpos = rand() % pro_len;
    cout << "randpos is: " << randpos << "\n";
    int pro_current[3] = {pro_pos[randpos].x,pro_pos[randpos].y,pro_pos[randpos].z};

    //find, if any, the possible positions the selected amino acid can move to
    vector<vector<int> > vec_possmoves;
    moveTo(pro_current, pro_pos,pro_len,vec_possmoves);
    cout << "poss moves are: ";
    for(int i = 0; i < vec_possmoves.size(); i++){
      cout << "(";
      for(int j = 0; j < 3; j++){
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
	  for(int j = 0; j < 3; j++){
	    cout << vec_finalpossmoves[i][j] << ",";
	  }
	  cout << ")";
	}
	cout << "\n";

    
	//account for more than one possible move
	int randpos2 = rand() % vec_finalpossmoves.size();
	int to_move[3];
	to_move[0] = vec_finalpossmoves[randpos2][0];
	to_move[1] = vec_finalpossmoves[randpos2][1];
	to_move[2] = vec_finalpossmoves[randpos2][2];

	cout << "want to move (" << pro_pos[randpos].x << "," << pro_pos[randpos].y << "," <<pro_pos[randpos].z << ") to (" << to_move[0] << "," << to_move[1] << "," << to_move[2] << ")\n";
    
	//calculate energy difference
	double init_energy = totalEnergy(pro_structure,pro_pos,pro_len,energy_mat);
	pro_pos[randpos].x = to_move[0];
	pro_pos[randpos].y = to_move[1];
	pro_pos[randpos].z = to_move[2];
	double deltaE = totalEnergy(pro_structure,pro_pos,pro_len,energy_mat) - init_energy; 

	cout << "energy difference is: " << deltaE << "\n";
    
	/* move amino acid if the move lowers the energy or is less that the thermal
	   fluctuations */
	doMove(deltaE,pro_pos,randpos,pro_current,temp);

	cout << "moved\n";
	for(int i = 0; i < pro_len; i++){
	  cout << "(" << pro_pos[i].x << "," << pro_pos[i].y << "," << pro_pos[i].z << ")";
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

