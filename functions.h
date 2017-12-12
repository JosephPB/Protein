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

using namespace std;

int checkList(int vec[][2],int vbl[],int N);

double totalEnergy(int structure[],int occupied[][2],int N,double J[20][20]);

void moveTo(int current[],int occupied[][2],int N,vector<vector<int> >& vec_poss_moves);

void canMove(int current[],int position, int occupied[][2],int N,vector<vector<int> > vec_poss_moves,vector<vector<int> >& vec_final_poss_moves);

void doMove(double E_move,int occupied[][2],int position,int target[], int temperature);

double length(int occupied[][2], int N);

#endif

