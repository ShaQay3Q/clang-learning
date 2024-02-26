#include "./src/cs50.h"
#include <stdio.h>

void avarage_scores(int number);
float return_avrage(int scores[4]);

int main(void) {

  int scores[4];
  for (int i = 0; i<4; i++){
    scores[i] = get_int("Score: ");
  }
  printf("Average: %f\n", return_avrage(scores));

  // int dig = get_int("for how many? > ");
  // avarage_scores(dig);
}

float return_avrage(int scores[4]){
    // int length = sizeof(scores[4]);
    int sum = 0;
    for(int i = 0; i <4; i++){
        sum = sum + scores[i];
    }
    return (float)sum/4;
}

// int[] get_scores(int n){
//       int scores[n];
//       for (int i = 0; i<n; i++){
//             scores[i] = get_int("Score: ");
//       }
//       return scores[n];
// }

void avarage_scores(int number) {
  int scores_sum = 0;
  int i;
  for (i = 0; i < number; i++) {
    scores_sum = scores_sum + get_int("score: ");
  }
  float avrage = (float)scores_sum / i;
  printf("Avrage: %f\n", avrage);
}
