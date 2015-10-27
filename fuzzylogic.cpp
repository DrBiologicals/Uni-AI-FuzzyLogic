#include <algorithm>

#include "fuzzylogic.h"



/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules
//Target Pursuit Speed
void initFuzzyRulesTargetPursuitSpeed(fuzzy_system_rec *fl) {
	
   int i;
   for (i = 0;i < fl->no_of_rules;i++) {  
       //(*fl).rules[i].inp_index[0] = in_angle; //alternatively
       fl->rules[i].inp_index[0] = in_angle;
       fl->rules[i].inp_index[1] = in_distance;
   }
 
	//Fuzzy Set for distance in_very_far
   fl->rules[0].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[0].inp_fuzzy_set[1] = in_very_far;
   fl->rules[0].out_fuzzy_set = out_very_fast;

   fl->rules[1].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[1].inp_fuzzy_set[1] = in_very_far;
   fl->rules[1].out_fuzzy_set = out_fast;	
	
	fl->rules[2].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[2].inp_fuzzy_set[1] = in_very_far;
   fl->rules[2].out_fuzzy_set = out_fast;

	fl->rules[3].inp_fuzzy_set[0] = in_zero;
   fl->rules[3].inp_fuzzy_set[1] = in_very_far;
   fl->rules[3].out_fuzzy_set = out_wicked_fast;	
	
	fl->rules[4].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[4].inp_fuzzy_set[1] = in_very_far;
   fl->rules[4].out_fuzzy_set = out_very_fast;

	fl->rules[5].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[5].inp_fuzzy_set[1] = in_very_far;
   fl->rules[5].out_fuzzy_set = out_fast;
	
	fl->rules[6].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[6].inp_fuzzy_set[1] = in_very_far;
   fl->rules[6].out_fuzzy_set = out_fast;
	
	//Fuzzy Set for distance in_far
   fl->rules[7].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[7].inp_fuzzy_set[1] = in_far;
   fl->rules[7].out_fuzzy_set = out_very_fast;

   fl->rules[8].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[8].inp_fuzzy_set[1] = in_far;
   fl->rules[8].out_fuzzy_set = out_fast;	
	
	fl->rules[9].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[9].inp_fuzzy_set[1] = in_far;
   fl->rules[9].out_fuzzy_set = out_medium;

	fl->rules[10].inp_fuzzy_set[0] = in_zero;
   fl->rules[10].inp_fuzzy_set[1] = in_far;
   fl->rules[10].out_fuzzy_set = out_very_fast;	
	
	fl->rules[11].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[11].inp_fuzzy_set[1] = in_far;
   fl->rules[11].out_fuzzy_set = out_very_fast;

	fl->rules[12].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[12].inp_fuzzy_set[1] = in_far;
   fl->rules[12].out_fuzzy_set = out_fast;
	
	fl->rules[13].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[13].inp_fuzzy_set[1] = in_far;
   fl->rules[13].out_fuzzy_set = out_medium;
	
	//Fuzzy Set for distance in_medium
   fl->rules[14].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[14].inp_fuzzy_set[1] = in_medium;
   fl->rules[14].out_fuzzy_set = out_slow;

   fl->rules[15].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[15].inp_fuzzy_set[1] = in_medium;
   fl->rules[15].out_fuzzy_set = out_medium;	
	
	fl->rules[16].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[16].inp_fuzzy_set[1] = in_medium;
   fl->rules[16].out_fuzzy_set = out_medium;

	fl->rules[17].inp_fuzzy_set[0] = in_zero;
   fl->rules[17].inp_fuzzy_set[1] = in_medium;
   fl->rules[17].out_fuzzy_set = out_medium;	
	
	fl->rules[18].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[18].inp_fuzzy_set[1] = in_medium;
   fl->rules[18].out_fuzzy_set = out_slow;

	fl->rules[19].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[19].inp_fuzzy_set[1] = in_medium;
   fl->rules[19].out_fuzzy_set = out_medium;
	
	fl->rules[20].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[20].inp_fuzzy_set[1] = in_medium;
   fl->rules[20].out_fuzzy_set = out_medium;
	
	//Fuzzy Set for distance in_near
   fl->rules[21].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[21].inp_fuzzy_set[1] = in_near;
   fl->rules[21].out_fuzzy_set = out_very_slow;

   fl->rules[22].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[22].inp_fuzzy_set[1] = in_near;
   fl->rules[22].out_fuzzy_set = out_slow;	
	
	fl->rules[23].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[23].inp_fuzzy_set[1] = in_near;
   fl->rules[23].out_fuzzy_set = out_slow;

	fl->rules[24].inp_fuzzy_set[0] = in_zero;
   fl->rules[24].inp_fuzzy_set[1] = in_near;
   fl->rules[24].out_fuzzy_set = out_very_slow;	
	
	fl->rules[25].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[25].inp_fuzzy_set[1] = in_near;
   fl->rules[25].out_fuzzy_set = out_very_slow;

	fl->rules[26].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[26].inp_fuzzy_set[1] = in_near;
   fl->rules[26].out_fuzzy_set = out_slow;
	
	fl->rules[27].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[27].inp_fuzzy_set[1] = in_near;
   fl->rules[27].out_fuzzy_set = out_slow;

	return;
}
//Target Angle
void initFuzzyRulesTargetAngle(fuzzy_system_rec *fl) {
	
   int i;
   for (i = 0;i < fl->no_of_rules;i++) {  
       //(*fl).rules[i].inp_index[0] = in_angle; //alternatively
       fl->rules[i].inp_index[0] = in_angle;
       fl->rules[i].inp_index[1] = in_distance;
   }
 
	//Fuzzy Set for distance in_very_far
   fl->rules[0].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[0].inp_fuzzy_set[1] = in_very_far;
   fl->rules[0].out_fuzzy_set = out_positively_mild_turn;

   fl->rules[1].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[1].inp_fuzzy_set[1] = in_very_far;
   fl->rules[1].out_fuzzy_set = out_positively_sharp_turn;	
	
	fl->rules[2].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[2].inp_fuzzy_set[1] = in_very_far;
   fl->rules[2].out_fuzzy_set = out_positively_very_sharp_turn;

	fl->rules[3].inp_fuzzy_set[0] = in_zero;
   fl->rules[3].inp_fuzzy_set[1] = in_very_far;
   fl->rules[3].out_fuzzy_set = out_ze_turn;	
	
	fl->rules[4].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[4].inp_fuzzy_set[1] = in_very_far;
   fl->rules[4].out_fuzzy_set = out_negatively_mild_turn;

	fl->rules[5].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[5].inp_fuzzy_set[1] = in_very_far;
   fl->rules[5].out_fuzzy_set = out_negatively_sharp_turn;
	
	fl->rules[6].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[6].inp_fuzzy_set[1] = in_very_far;
   fl->rules[6].out_fuzzy_set = out_negatively_very_sharp_turn;
	
	//Fuzzy Set for distance in_far
   fl->rules[7].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[7].inp_fuzzy_set[1] = in_far;
   fl->rules[7].out_fuzzy_set = out_positively_sharp_turn;

   fl->rules[8].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[8].inp_fuzzy_set[1] = in_far;
   fl->rules[8].out_fuzzy_set = out_positively_sharp_turn;	
	
	fl->rules[9].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[9].inp_fuzzy_set[1] = in_far;
   fl->rules[9].out_fuzzy_set = out_positively_very_sharp_turn;

	fl->rules[10].inp_fuzzy_set[0] = in_zero;
   fl->rules[10].inp_fuzzy_set[1] = in_far;
   fl->rules[10].out_fuzzy_set = out_ze_turn;	
	
	fl->rules[11].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[11].inp_fuzzy_set[1] = in_far;
   fl->rules[11].out_fuzzy_set = out_negatively_sharp_turn;

	fl->rules[12].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[12].inp_fuzzy_set[1] = in_far;
   fl->rules[12].out_fuzzy_set = out_negatively_sharp_turn;
	
	fl->rules[13].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[13].inp_fuzzy_set[1] = in_far;
   fl->rules[13].out_fuzzy_set = out_negatively_very_sharp_turn;
	
	//Fuzzy Set for distance in_medium
   fl->rules[14].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[14].inp_fuzzy_set[1] = in_medium;
   fl->rules[14].out_fuzzy_set = out_positively_mild_turn;

   fl->rules[15].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[15].inp_fuzzy_set[1] = in_medium;
   fl->rules[15].out_fuzzy_set = out_positively_sharp_turn;	
	
	fl->rules[16].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[16].inp_fuzzy_set[1] = in_medium;
   fl->rules[16].out_fuzzy_set = out_positively_very_sharp_turn;

	fl->rules[17].inp_fuzzy_set[0] = in_zero;
   fl->rules[17].inp_fuzzy_set[1] = in_medium;
   fl->rules[17].out_fuzzy_set = out_ze_turn;	
	
	fl->rules[18].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[18].inp_fuzzy_set[1] = in_medium;
   fl->rules[18].out_fuzzy_set = out_negatively_mild_turn;

	fl->rules[19].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[19].inp_fuzzy_set[1] = in_medium;
   fl->rules[19].out_fuzzy_set = out_negatively_sharp_turn;
	
	fl->rules[20].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[20].inp_fuzzy_set[1] = in_medium;
   fl->rules[20].out_fuzzy_set = out_negatively_very_sharp_turn;
	
	//Fuzzy Set for distance in_near
   fl->rules[21].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[21].inp_fuzzy_set[1] = in_near;
   fl->rules[21].out_fuzzy_set = out_positively_very_mild_turn;

   fl->rules[22].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[22].inp_fuzzy_set[1] = in_near;
   fl->rules[22].out_fuzzy_set = out_positively_mild_turn;	
	
	fl->rules[23].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[23].inp_fuzzy_set[1] = in_near;
   fl->rules[23].out_fuzzy_set = out_positively_sharp_turn;

	fl->rules[24].inp_fuzzy_set[0] = in_zero;
   fl->rules[24].inp_fuzzy_set[1] = in_near;
   fl->rules[24].out_fuzzy_set = out_ze_turn;	
	
	fl->rules[25].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[25].inp_fuzzy_set[1] = in_near;
   fl->rules[25].out_fuzzy_set = out_negatively_very_mild_turn;

	fl->rules[26].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[26].inp_fuzzy_set[1] = in_near;
   fl->rules[26].out_fuzzy_set = out_negatively_mild_turn;
	
	fl->rules[27].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[27].inp_fuzzy_set[1] = in_near;
   fl->rules[27].out_fuzzy_set = out_negatively_sharp_turn;

	return;
}
//Avoidance Speed
void initFuzzyRulesAvoidanceSpeed(fuzzy_system_rec *fl) {
	
   int i;
   for (i = 0;i < fl->no_of_rules;i++) {  
       //(*fl).rules[i].inp_index[0] = in_angle; //alternatively
       fl->rules[i].inp_index[0] = in_angle;
       fl->rules[i].inp_index[1] = in_distance;
   }
 
	//Fuzzy Set for distance in_very_far
   fl->rules[0].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[0].inp_fuzzy_set[1] = in_very_far;
   fl->rules[0].out_fuzzy_set = out_slow;

   fl->rules[1].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[1].inp_fuzzy_set[1] = in_very_far;
   fl->rules[1].out_fuzzy_set = out_medium;	
	
	fl->rules[2].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[2].inp_fuzzy_set[1] = in_very_far;
   fl->rules[2].out_fuzzy_set = out_medium;

	fl->rules[3].inp_fuzzy_set[0] = in_zero;
   fl->rules[3].inp_fuzzy_set[1] = in_very_far;
   fl->rules[3].out_fuzzy_set = out_slow;	
	
	fl->rules[4].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[4].inp_fuzzy_set[1] = in_very_far;
   fl->rules[4].out_fuzzy_set = out_slow;

	fl->rules[5].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[5].inp_fuzzy_set[1] = in_very_far;
   fl->rules[5].out_fuzzy_set = out_medium;
	
	fl->rules[6].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[6].inp_fuzzy_set[1] = in_very_far;
   fl->rules[6].out_fuzzy_set = out_medium;
	
	//Fuzzy Set for distance in_far
   fl->rules[7].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[7].inp_fuzzy_set[1] = in_far;
   fl->rules[7].out_fuzzy_set = out_medium;

   fl->rules[8].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[8].inp_fuzzy_set[1] = in_far;
   fl->rules[8].out_fuzzy_set = out_fast;	
	
	fl->rules[9].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[9].inp_fuzzy_set[1] = in_far;
   fl->rules[9].out_fuzzy_set = out_fast;

	fl->rules[10].inp_fuzzy_set[0] = in_zero;
   fl->rules[10].inp_fuzzy_set[1] = in_far;
   fl->rules[10].out_fuzzy_set = out_medium;	
	
	fl->rules[11].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[11].inp_fuzzy_set[1] = in_far;
   fl->rules[11].out_fuzzy_set = out_medium;

	fl->rules[12].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[12].inp_fuzzy_set[1] = in_far;
   fl->rules[12].out_fuzzy_set = out_fast;
	
	fl->rules[13].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[13].inp_fuzzy_set[1] = in_far;
   fl->rules[13].out_fuzzy_set = out_fast;
	
	//Fuzzy Set for distance in_medium
   fl->rules[14].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[14].inp_fuzzy_set[1] = in_medium;
   fl->rules[14].out_fuzzy_set = out_fast;

   fl->rules[15].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[15].inp_fuzzy_set[1] = in_medium;
   fl->rules[15].out_fuzzy_set = out_very_fast;	
	
	fl->rules[16].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[16].inp_fuzzy_set[1] = in_medium;
   fl->rules[16].out_fuzzy_set = out_very_fast;

	fl->rules[17].inp_fuzzy_set[0] = in_zero;
   fl->rules[17].inp_fuzzy_set[1] = in_medium;
   fl->rules[17].out_fuzzy_set = out_fast;	
	
	fl->rules[18].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[18].inp_fuzzy_set[1] = in_medium;
   fl->rules[18].out_fuzzy_set = out_fast;

	fl->rules[19].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[19].inp_fuzzy_set[1] = in_medium;
   fl->rules[19].out_fuzzy_set = out_very_fast;
	
	fl->rules[20].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[20].inp_fuzzy_set[1] = in_medium;
   fl->rules[20].out_fuzzy_set = out_very_fast;
	
	//Fuzzy Set for distance in_near
   fl->rules[21].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[21].inp_fuzzy_set[1] = in_near;
   fl->rules[21].out_fuzzy_set = out_very_fast;

   fl->rules[22].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[22].inp_fuzzy_set[1] = in_near;
   fl->rules[22].out_fuzzy_set = out_wicked_fast;	
	
	fl->rules[23].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[23].inp_fuzzy_set[1] = in_near;
   fl->rules[23].out_fuzzy_set = out_wicked_fast;

	fl->rules[24].inp_fuzzy_set[0] = in_zero;
   fl->rules[24].inp_fuzzy_set[1] = in_near;
   fl->rules[24].out_fuzzy_set = out_very_fast;	
	
	fl->rules[25].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[25].inp_fuzzy_set[1] = in_near;
   fl->rules[25].out_fuzzy_set = out_very_fast;

	fl->rules[26].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[26].inp_fuzzy_set[1] = in_near;
   fl->rules[26].out_fuzzy_set = out_wicked_fast;
	
	fl->rules[27].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[27].inp_fuzzy_set[1] = in_near;
   fl->rules[27].out_fuzzy_set = out_wicked_fast;

	return;
}
//Avoidance angle
void initFuzzyRulesAvoidanceAngle(fuzzy_system_rec *fl) {
	
   int i;
   for (i = 0;i < fl->no_of_rules;i++) {  
       //(*fl).rules[i].inp_index[0] = in_angle; //alternatively
       fl->rules[i].inp_index[0] = in_angle;
       fl->rules[i].inp_index[1] = in_distance;
   }
 
	//Fuzzy Set for distance in_very_far
   fl->rules[0].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[0].inp_fuzzy_set[1] = in_very_far;
   fl->rules[0].out_fuzzy_set = out_ze_turn;

   fl->rules[1].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[1].inp_fuzzy_set[1] = in_very_far;
   fl->rules[1].out_fuzzy_set = out_ze_turn;	
	
	fl->rules[2].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[2].inp_fuzzy_set[1] = in_very_far;
   fl->rules[2].out_fuzzy_set = out_ze_turn;

	fl->rules[3].inp_fuzzy_set[0] = in_zero;
   fl->rules[3].inp_fuzzy_set[1] = in_very_far;
   fl->rules[3].out_fuzzy_set = out_negatively_very_mild_turn;	
	
	fl->rules[4].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[4].inp_fuzzy_set[1] = in_very_far;
   fl->rules[4].out_fuzzy_set = out_ze_turn;

	fl->rules[5].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[5].inp_fuzzy_set[1] = in_very_far;
   fl->rules[5].out_fuzzy_set = out_ze_turn;
	
	fl->rules[6].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[6].inp_fuzzy_set[1] = in_very_far;
   fl->rules[6].out_fuzzy_set = out_ze_turn;
	
	//Fuzzy Set for distance in_far
   fl->rules[7].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[7].inp_fuzzy_set[1] = in_far;
   fl->rules[7].out_fuzzy_set = out_negatively_very_mild_turn;

   fl->rules[8].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[8].inp_fuzzy_set[1] = in_far;
   fl->rules[8].out_fuzzy_set = out_negatively_very_mild_turn;	
	
	fl->rules[9].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[9].inp_fuzzy_set[1] = in_far;
   fl->rules[9].out_fuzzy_set = out_ze_turn;

	fl->rules[10].inp_fuzzy_set[0] = in_zero;
   fl->rules[10].inp_fuzzy_set[1] = in_far;
   fl->rules[10].out_fuzzy_set = out_positively_mild_turn;	
	
	fl->rules[11].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[11].inp_fuzzy_set[1] = in_far;
   fl->rules[11].out_fuzzy_set = out_positively_very_mild_turn;

	fl->rules[12].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[12].inp_fuzzy_set[1] = in_far;
   fl->rules[12].out_fuzzy_set = out_positively_very_mild_turn;
	
	fl->rules[13].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[13].inp_fuzzy_set[1] = in_far;
   fl->rules[13].out_fuzzy_set = out_ze_turn;
	
	//Fuzzy Set for distance in_medium
   fl->rules[14].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[14].inp_fuzzy_set[1] = in_medium;
   fl->rules[14].out_fuzzy_set = out_negatively_mild_turn;

   fl->rules[15].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[15].inp_fuzzy_set[1] = in_medium;
   fl->rules[15].out_fuzzy_set = out_negatively_mild_turn;	
	
	fl->rules[16].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[16].inp_fuzzy_set[1] = in_medium;
   fl->rules[16].out_fuzzy_set = out_negatively_very_mild_turn;

	fl->rules[17].inp_fuzzy_set[0] = in_zero;
   fl->rules[17].inp_fuzzy_set[1] = in_medium;
   fl->rules[17].out_fuzzy_set = out_negatively_sharp_turn;	
	
	fl->rules[18].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[18].inp_fuzzy_set[1] = in_medium;
   fl->rules[18].out_fuzzy_set = out_positively_mild_turn;

	fl->rules[19].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[19].inp_fuzzy_set[1] = in_medium;
   fl->rules[19].out_fuzzy_set = out_positively_mild_turn;
	
	fl->rules[20].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[20].inp_fuzzy_set[1] = in_medium;
   fl->rules[20].out_fuzzy_set = out_positively_very_mild_turn;
	
	//Fuzzy Set for distance in_near
   fl->rules[21].inp_fuzzy_set[0] = in_Neg_small;
   fl->rules[21].inp_fuzzy_set[1] = in_near;
   fl->rules[21].out_fuzzy_set = out_negatively_sharp_turn;

   fl->rules[22].inp_fuzzy_set[0] = in_Neg_medium;
   fl->rules[22].inp_fuzzy_set[1] = in_near;
   fl->rules[22].out_fuzzy_set = out_negatively_sharp_turn;	
	
	fl->rules[23].inp_fuzzy_set[0] = in_Neg_large;
   fl->rules[23].inp_fuzzy_set[1] = in_near;
   fl->rules[23].out_fuzzy_set = out_negatively_mild_turn;

	fl->rules[24].inp_fuzzy_set[0] = in_zero;
   fl->rules[24].inp_fuzzy_set[1] = in_near;
   fl->rules[24].out_fuzzy_set = out_negatively_very_sharp_turn;	
	
	fl->rules[25].inp_fuzzy_set[0] = in_positively_small;
   fl->rules[25].inp_fuzzy_set[1] = in_near;
   fl->rules[25].out_fuzzy_set = out_positively_sharp_turn;

	fl->rules[26].inp_fuzzy_set[0] = in_positively_medium;
   fl->rules[26].inp_fuzzy_set[1] = in_near;
   fl->rules[26].out_fuzzy_set = out_positively_sharp_turn;
	
	fl->rules[27].inp_fuzzy_set[0] = in_positively_large;
   fl->rules[27].inp_fuzzy_set[1] = in_near;
   fl->rules[27].out_fuzzy_set = out_positively_mild_turn;

	return;
}
void initMembershipFunctionsTargetAngle(fuzzy_system_rec *fl) {  
		//angle   
   fl->inp_mem_fns[in_angle][in_Neg_large] = init_trapz(-50.0f,-40.0f,0.0f,0.0f,  									
		left_trapezoid);
   fl->inp_mem_fns[in_angle][in_Neg_medium] = init_trapz(-50.0f,-40.0f,-30.0f,-20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_Neg_small] = init_trapz(-30.0f,-20.0f,-10.0f,0.0f,								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_zero] = init_trapz(-10.0f,0.0f,0.0f,10.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_small] = init_trapz(0.0f,10.0f,20.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_medium] = init_trapz(20.0f,30.0f,40.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_large] = init_trapz(40.0f,50.0f,0.0f,0.0f,  									
		right_trapezoid);
	
	//distance  
   fl->inp_mem_fns[in_distance][in_near] = init_trapz(5.0f,20.0f,0,0,  									
		left_trapezoid);
   fl->inp_mem_fns[in_distance][in_medium] = init_trapz(5.0f,20.0f,35.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_far] = init_trapz(35.0f,50.0f,65.0f,85.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_very_far] = init_trapz(65.0f,85.0f,0.0f,0.0f, 								            
		right_trapezoid);
   return;
}
void initMembershipFunctionsTargetPursuitSpeed(fuzzy_system_rec *fl) {	
		//angle   
   fl->inp_mem_fns[in_angle][in_Neg_large] = init_trapz(-50.0f,-40.0f,0.0f,0.0f,  									
		left_trapezoid);
   fl->inp_mem_fns[in_angle][in_Neg_medium] = init_trapz(-50.0f,-40.0f,-30.0f,-20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_Neg_small] = init_trapz(-30.0f,-20.0f,-10.0f,0.0f,								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_zero] = init_trapz(-10.0f,0.0f,0.0f,10.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_small] = init_trapz(0.0f,10.0f,20.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_medium] = init_trapz(20.0f,30.0f,40.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_large] = init_trapz(40.0f,50.0f,0.0f,0.0f,  									
		right_trapezoid);
	
	//distance  
   fl->inp_mem_fns[in_distance][in_near] = init_trapz(5.0f,20.0f,0,0,  									
		left_trapezoid);
   fl->inp_mem_fns[in_distance][in_medium] = init_trapz(5.0f,20.0f,35.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_far] = init_trapz(35.0f,50.0f,65.0f,85.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_very_far] = init_trapz(65.0f,85.0f,0.0f,0.0f, 								            
		right_trapezoid);
   return;
}
void initMembershipFunctionsAvoidanceAngle(fuzzy_system_rec *fl) {  
		//angle   
   fl->inp_mem_fns[in_angle][in_Neg_large] = init_trapz(-50.0f,-40.0f,0.0f,0.0f,  									
		left_trapezoid);
   fl->inp_mem_fns[in_angle][in_Neg_medium] = init_trapz(-50.0f,-40.0f,-30.0f,-20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_Neg_small] = init_trapz(-30.0f,-20.0f,-10.0f,0.0f,								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_zero] = init_trapz(-10.0f,0.0f,0.0f,10.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_small] = init_trapz(0.0f,10.0f,20.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_medium] = init_trapz(20.0f,30.0f,40.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_large] = init_trapz(40.0f,50.0f,0.0f,0.0f,  									
		right_trapezoid);
	
	//distance  
   fl->inp_mem_fns[in_distance][in_near] = init_trapz(5.0f,10.0f,0,0,  									
		left_trapezoid);
   fl->inp_mem_fns[in_distance][in_medium] = init_trapz(5.0f,10.0f,15.0f,20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_far] = init_trapz(15.0f,20.0f,25.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_very_far] = init_trapz(25.0f,30.0f,0.0f,0.0f, 								            
		right_trapezoid);
   return;
}
void initMembershipFunctionsAvoidanceSpeed(fuzzy_system_rec *fl) {	
		//angle   
   fl->inp_mem_fns[in_angle][in_Neg_large] = init_trapz(-50.0f,-40.0f,0.0f,0.0f,  									
		left_trapezoid);
   fl->inp_mem_fns[in_angle][in_Neg_medium] = init_trapz(-50.0f,-40.0f,-30.0f,-20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_Neg_small] = init_trapz(-30.0f,-20.0f,-10.0f,0.0f,								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_zero] = init_trapz(-10.0f,0.0f,0.0f,10.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_small] = init_trapz(0.0f,10.0f,20.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_medium] = init_trapz(20.0f,30.0f,40.0f,50.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_angle][in_positively_large] = init_trapz(40.0f,50.0f,0.0f,0.0f,  									
		right_trapezoid);
	
	//distance  
   fl->inp_mem_fns[in_distance][in_near] = init_trapz(5.0f,10.0f,0,0,  									
		left_trapezoid);
   fl->inp_mem_fns[in_distance][in_medium] = init_trapz(5.0f,10.0f,15.0f,20.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_far] = init_trapz(15.0f,20.0f,25.0f,30.0f, 								            
		regular_trapezoid);
	fl->inp_mem_fns[in_distance][in_very_far] = init_trapz(25.0f,30.0f,0.0f,0.0f, 								            
		right_trapezoid);
   return;
}
void initFuzzySystemTargetPursuitSpeed (fuzzy_system_rec *fl) {
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 28;
   fl->no_of_inp_regions = 7;
   fl->no_of_outputs = 6;
	//distance outputs
   fl->output_values [out_very_slow] = 0.15f;
   fl->output_values [out_slow] = 0.3f;
   fl->output_values [out_medium] = 0.45f;
   fl->output_values [out_fast] = 0.65f;
   fl->output_values [out_very_fast] = 0.75f;
	fl->output_values [out_wicked_fast] = 0.9f;
   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
	initFuzzyRulesTargetPursuitSpeed(fl);
   initMembershipFunctionsTargetPursuitSpeed(fl);
   return;
}
void initFuzzySystemTargetAngle (fuzzy_system_rec *fl) {
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 28;
   fl->no_of_inp_regions = 7;
   fl->no_of_outputs = 9;
	//angle outputs
	fl->output_values [out_ze_turn] = 0.0f;
   fl->output_values [out_negatively_very_mild_turn] = -0.75f;
   fl->output_values [out_negatively_mild_turn] = -2.0f;
   fl->output_values [out_negatively_sharp_turn] = -5.0f;
   fl->output_values [out_negatively_very_sharp_turn] = -10.0f;
	fl->output_values [out_positively_very_mild_turn] = 0.75f;
	fl->output_values [out_positively_mild_turn] = 2.0f;
   fl->output_values [out_positively_sharp_turn] = 5.0f;
   fl->output_values [out_positively_very_sharp_turn] = 10.0f;
   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
	initFuzzyRulesTargetAngle(fl);
   initMembershipFunctionsTargetAngle(fl);
   return;
}
void initFuzzySystemAvoidanceSpeed (fuzzy_system_rec *fl) {
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 28;
   fl->no_of_inp_regions = 7;
   fl->no_of_outputs = 6;
	//distance outputs
   fl->output_values [out_very_slow] = 0.1f;
   fl->output_values [out_slow] = 0.2f;
   fl->output_values [out_medium] = 0.3f;
   fl->output_values [out_fast] = 0.4f;
   fl->output_values [out_very_fast] = 0.5f;
	fl->output_values [out_wicked_fast] = 0.6f;
   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
	initFuzzyRulesAvoidanceSpeed(fl);
   initMembershipFunctionsAvoidanceSpeed(fl);
   return;
}
void initFuzzySystemAvoidanceAngle (fuzzy_system_rec *fl) {
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 28;
   fl->no_of_inp_regions = 7;
   fl->no_of_outputs = 9;
	//angle outputs
	fl->output_values [out_ze_turn] = 0.0f;
   fl->output_values [out_negatively_very_mild_turn] = -0.75f;
   fl->output_values [out_negatively_mild_turn] = -2.0f;
   fl->output_values [out_negatively_sharp_turn] = -5.0f;
   fl->output_values [out_negatively_very_sharp_turn] = -10.0f;
	fl->output_values [out_positively_very_mild_turn] = 0.75f;
	fl->output_values [out_positively_mild_turn] = 2.0f;
   fl->output_values [out_positively_sharp_turn] = 5.0f;
   fl->output_values [out_positively_very_sharp_turn] = 10.0f;
   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
	initFuzzyRulesAvoidanceAngle(fl);
   initMembershipFunctionsAvoidanceAngle(fl);
   return;
}
//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
	
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
	   
      case regular_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 1.0/(trz.c - trz.d);
         	 break;
	 
      case left_trapezoid:
         	 trz.r_slope = 1.0/(trz.a - trz.b);
         	 trz.l_slope = 0.0;
         	 break;
	 
      case right_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 0.0;
         	 break;
   }  /* end switch  */
   
   return trz;
}  /* end function */


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {
	   
      case left_trapezoid:
         	 if (x <= trz.a)
         	    return 1.0;
         	 if (x >= trz.b)
         	    return 0.0;
         	 /* a < x < b */
         	 return trz.r_slope * (x - trz.b);
	 
	 
      case right_trapezoid:
         	 if (x <= trz.a)
         	    return 0.0;
         	 if (x >= trz.b)
         	    return 1.0;
         	 /* a < x < b */
         	 return trz.l_slope * (x - trz.a);
	 
      case regular_trapezoid:
         	 if ((x <= trz.a) || (x >= trz.d))
         	    return 0.0;
         	 if ((x >= trz.b) && (x <= trz.c))
         	    return 1.0;
         	 if ((x >= trz.a) && (x <= trz.b))
         	    return trz.l_slope * (x - trz.a);
         	 if ((x >= trz.c) && (x <= trz.d))
         	    return  trz.r_slope * (x - trz.d);
         	    
	 }  /* End switch  */
	 
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}


//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0f,sum2 = 0.0f,weight;
   float m_values[MAX_NO_OF_INPUTS];
   
   for (i = 0;i < fz.no_of_rules;i++) {
       for (j = 0;j < fz.no_of_inputs;j++) {
			variable_index = fz.rules[i].inp_index[j];
			fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
			m_values[j] = trapz(inputs[variable_index],
			fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
       weight = min_of (m_values,fz.no_of_inputs);
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
	} /* end i  */
  if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //getch();
      exit(1);
      return 0.0;
   }
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

