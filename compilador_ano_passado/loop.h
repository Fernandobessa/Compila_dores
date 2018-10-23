#include <iostream>
// #include <map>
#include <string>
#include <vector>
// #include <stdio.h>
// #include <stdlib.h>

using namespace std;

typedef struct Loop {
    // comeco, final e continue - LABEL
    // continue pode ser igual comeco? [to-do]
    string comecoL;
    string fimL;
    string contL;
}Loop;

typedef struct {
    vector<Loop> loops;
} Loop_stack;

void pushLoop(Loop loop, Loop_stack* tack)
{
   tack->loops.push_back(loop); 
}

Loop popLoop(Loop_stack* tack)
{
    Loop loop = tack->loops.back();
    
    tack->loops.pop_back();
    return loop;
}

Loop getLoop (Loop_stack* tack)
{
    Loop loop = tack->loops.back();
    
    return loop;
}

Loop_stack* criarLoopStack()
{
    return (Loop_stack*) malloc(sizeof(Loop_stack));
}