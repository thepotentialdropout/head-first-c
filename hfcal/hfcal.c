#include <stdio.h>

void DisplayCalories( float weight, float distance, float coeff){
  printf( "Weight: %3.2f kg\n", weight);
  printf( "Distance: %3.2f km\n", distance);
  printf( "Calories: %3.2f cal\n", weight * distance * coeff);
}
