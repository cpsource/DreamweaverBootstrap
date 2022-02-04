
//
// Bob has decided to forward declare his function
// for Alice and writes the following:
//

unsigned short m(int *(*n)(int *o));

// Please fully explain m,n, and o

//
// During a code review, Bob and Alice are
// arguing about which is right. They
// have come to you. What do you say?
//

Bob Writes  : int main(int argc, char *argv);
Alice Writes: int main(int argc, char **argv);

