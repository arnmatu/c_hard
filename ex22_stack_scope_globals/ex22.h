#ifndef __ex22_h__
#define __ex22_h__

//makes the THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;

//gets and sets an internal static variable ex22.c
int get_age();
void set_age(int age);

//updates a static variable that's inside update ratio
double update_ratio(double ratio);

void print_size();

#endif
