#include <stdio.h>

void DisplayCalories( float weight, float distance, float coeff){
  printf( "Weight: %3.2f lbs\n", weight * 2.2046) ;
  printf( "Distance: %3.2f mi\n", distance / 1.609344 );
  printf( "Calories: %3.2f cal\n", weight * distance * coeff );
}
