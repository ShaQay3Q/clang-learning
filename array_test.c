#include "./src/cs50.h"
#include <stdio.h>

void avarage_scores(int number);
float return_avrage(int scores[]);
float average(int length, int scores[]);

// define a global value, so it stays the same throught the code
int N = 3;

int main(void) {

    // int n = get_int("Number of scores: ");
    int scores[N];

    for (int i = 0; i < N; i++) {
        scores[i] = get_int("Score: ");
    }
    printf("Average: %f\n", average(N, scores));

  // int dig = get_int("for how many? > ");
  // avarage_scores(dig);
}

float average(int length, int scores[]){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += scores[i];
    }
    return sum;
}

float return_avrage(int scores[]) {
  // int length = sizeof(scores[4]);
    int sum = 0;
    int length = sizeof(*scores);
    for (int i = 0; i < length; i++) {
        sum += scores[i];
    }
    return (float)sum / length;
}

// int[] get_scores(int n){
//       int scores[n];
//       for (int i = 0; i<n; i++){
//             scores[i] = get_int("Score: ");
//       }
//       return scores;
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
