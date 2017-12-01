#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include"functions.h"
#include<stdlib.h>
#include<list>
#include<algorithm>
#include<math.h>

bool checklist(int list, int variable);

int randPos(int N);

double totalEnergy(int structure, int N, double J);

int moveTo(int current, int occupied);

double canMove(int current, int occupied, int poss_moves);

double doMove(double E_move, int current, int target);

double length(int occupied, int N);

#endif

