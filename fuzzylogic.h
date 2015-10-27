#ifndef __FUZZYLOGIC_H__
#define __FUZZYLOGIC_H__

#include <math.h>
#include <set>
#include <stack>
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>


using namespace std;

/////////////////////////////////////////////////////

#define MAX_NO_OF_INPUTS 2
#define MAX_NO_OF_INP_REGIONS 7
#define MAX_NO_OF_OUTPUT_VALUES 9

#define TOO_SMALL 1e-6

//Trapezoidal membership function types
typedef enum {regular_trapezoid, left_trapezoid, right_trapezoid} trapz_type;

//Input parameters
typedef   enum {in_angle, in_distance};  //input indices

//indices of fuzzy sets for angle input
typedef   enum {in_Neg_small, in_Neg_medium, in_Neg_large, in_zero, in_positively_small, in_positively_medium, in_positively_large};  

//indices of fuzzy sets for distance input
typedef   enum {in_near, in_medium, in_far, in_very_far};  

//indices for output steering angle
typedef   enum {out_ze_turn, out_negatively_very_mild_turn, out_negatively_mild_turn, out_negatively_sharp_turn, out_negatively_very_sharp_turn,
out_positively_very_mild_turn, out_positively_mild_turn, out_positively_sharp_turn, out_positively_very_sharp_turn
};

//Fuzzy output terms
typedef  enum {out_very_slow, out_slow, out_medium, out_fast, out_very_fast,  			
	out_wicked_fast};

typedef struct {
   trapz_type tp;
   float a,b,c,d,l_slope,r_slope;
   
}trapezoid;

typedef struct {
   short inp_index[MAX_NO_OF_INPUTS],
	 inp_fuzzy_set[MAX_NO_OF_INPUTS],
	 out_fuzzy_set;
}  rule;

typedef struct {
   bool allocated;
   trapezoid inp_mem_fns [MAX_NO_OF_INPUTS] [MAX_NO_OF_INP_REGIONS];
   rule *rules;
   int no_of_inputs,no_of_inp_regions,no_of_rules,no_of_outputs;
   float output_values[MAX_NO_OF_OUTPUT_VALUES];
} fuzzy_system_rec;



//---------------------------------------------------------------------------






/*  File FLPRCS.C */
trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ);
float fuzzy_system (float inputs[],fuzzy_system_rec fl);
void free_fuzzy_rules (fuzzy_system_rec *fz);





//-------------------------------------------------------------------------
//Pursuit
void initFuzzyRulesTargetPursuitSpeed(fuzzy_system_rec *fl);
void initFuzzyRulesTargetAngle(fuzzy_system_rec *fl);
void initMembershipFunctionsTargetPursuitSpeed(fuzzy_system_rec *fl);
void initMembershipFunctionsTargetAngle(fuzzy_system_rec *fl); 
void initFuzzySystemTargetPursuitSpeed (fuzzy_system_rec *fl);
void initFuzzySystemTargetAngle (fuzzy_system_rec *fl);
//Avoidance
void initFuzzyRulesAvoidanceSpeed(fuzzy_system_rec *fl);
void initFuzzyRulesAvoidanceAngle(fuzzy_system_rec *fl);
void initMembershipFunctionsAvoidanceSpeed(fuzzy_system_rec *fl);
void initMembershipFunctionsAvoidanceAngle(fuzzy_system_rec *fl); 
void initFuzzySystemAvoidanceSpeed (fuzzy_system_rec *fl);
void initFuzzySystemAvoidanceAngle (fuzzy_system_rec *fl);



trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ);
float trapz (float x, trapezoid trz);
float min_of (float values[],int no_of_inps);
float fuzzy_system (float inputs[],fuzzy_system_rec fz);
void free_fuzzy_rules (fuzzy_system_rec *fz);




#endif
