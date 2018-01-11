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

struct occupied{
  int x;
  int y;
  int z;
};

int checkList(const struct occupied * vec,int vbl[],int N);

int checkStruct(const struct occupied * vec, const struct occupied vbl, int N);

void checkVariable(string makeup, int structure[],int N, char key[]);

double totalEnergy(int structure[],const struct occupied * occupied,int N,double J[20][20]);

void moveTo(int current[],const struct occupied * occupied,int N,vector<vector<int> >& vec_poss_moves);

void canMove(int current[],int position,const struct occupied * occupied,int N,vector<vector<int> > vec_poss_moves,vector<vector<int> >& vec_final_poss_moves);

void doMove(double E_move,struct occupied * occupied,int position,int target[], int temperature);

double length(const struct occupied * occupied,int N);

extern double miyazawa[20][20];

#endif

