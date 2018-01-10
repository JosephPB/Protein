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
#include<string>
#include<iomanip>
#include<random>
#include<chrono>

using namespace std;

struct occupied {
  int x;
  int y;
};

int checkList(const struct occupied * vec,int vbl[],int N);

double totalEnergy(int structure[],struct occupied * occupied,int N,double J[20][20]);

void moveTo(int current[],struct occupied * occupied,int N,vector<vector<int> >& vec_poss_moves);

void canMove(int current[],int position,struct occupied * occupied,int N,vector<vector<int> > vec_poss_moves,vector<vector<int> >& vec_final_poss_moves);

void doMove(double E_move,struct occupied * occupied,int position,int target[], int temperature);

double length(struct occupied * occupied,int N);

#endif

