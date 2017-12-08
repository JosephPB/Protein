#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include"functions.h"
#include<stdlib.h>
#include<list>
#include<algorithm>
#include<math.h>
#include<time.h>
#include<vector>
#include<sstream>
#include<fstream>
#include<iterator>

using namespace std;

bool checkList(int vec[][2],int vbl[],int N);

double totalEnergy(int structure[],int N,double J[20][20]);

void moveTo(int current[],int occupied[][2],int N,vector<vector<int> >& vec_poss_moves);

//double canMove(int current, int occupied, int poss_moves);

//double doMove(double E_move, int current, int target);

//double length(vector<vector<int> > occupied, int N);

#endif

