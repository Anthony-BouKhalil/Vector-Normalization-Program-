#include "assign2funcs.h"

/*Name: readInput
  Purpose: read user input
  Parameters: void
  Return Values: void
  Input: user input
  Output: if bad input, error message outputted, will terminate if 0 as first input or EOF inputted
*/
void readInput(void) {
  static int ExitCode = GoodInput; /*variable to exit with GoodInput macro = 0 or BadInput macro = 1*/
  int numOfArgs; /*number of vectors represented in the first argument for a new set of data*/
  int valueOfNumOfArgs = scanf("%d", &numOfArgs); /*value that stores the type of data read from stdin, 1 represents valid data*/

  if (valueOfNumOfArgs == EOF)
      exit(ExitCode);

  else if (valueOfNumOfArgs != 1) { /*If the data read is not valid*/
    fprintf(stderr,"BAD INPUT\n");
    ExitCode=BadInput;
    while ((getchar()) != '\n'); /*clears the input buffer*/
    readInput();
  }

  if (numOfArgs == 0)
    exit(ExitCode);

  else if (numOfArgs < 0 || numOfArgs > MAX) {
    fprintf(stderr,"BAD INPUT\n");
    ExitCode=BadInput;
    while ((getchar()) != '\n'); /*clears the input buffer*/
    readInput();
  }

  else {
    double vectorArray[numOfArgs]; /*Array to store the double vectors*/

    for (int i=1; i<=numOfArgs;i++) { /*i is the index for for-loop*/
      int valueOfVectorArray = scanf("%lf", &vectorArray[i]);  /*value that stores the type of data read from stdin, 1 represents valid data*/

      if (valueOfVectorArray == EOF)
          exit(ExitCode);

      else if (valueOfVectorArray != 1) { /*If the data read is not valid*/
        fprintf(stderr,"BAD INPUT\n");
        ExitCode=BadInput;
        while ((getchar()) != '\n'); /*clears the input buffer*/
        readInput();
      }
    }
  printVector(vectorArray, numOfArgs); /*call to the printVector function*/
  }
}


/*Name: printVector
  Purpose: prints vector array
  Parameters: vectorArray[] the array of vectors, numOfArgs the length of the vector array
  Return Values: void
  Input: vectorArray[], numOfArgs
  Output: prints the vector array
*/
void printVector(double vectorArray[], int numOfArgs){
  printf("VECTOR: [ ");
  for (int i=1; i<=numOfArgs;i++) { /*i is the index for for-loop*/
    if (i == numOfArgs)
      printf("%.3lf ", vectorArray[i]);
    else
      printf("%.3lf, ", vectorArray[i]);
  }

  printf("]");
  while ((getchar()) != '\n'); /*clears the input buffer*/
  normalize(vectorArray, numOfArgs); /*call to the normalize function*/
}


/*Name: normalize
  Purpose: normalizes each vector in the array
  Parameters: vectorArray[] the array of vectors, numOfArgs the length of the vector array
  Return Values: void
  Input: vectorArray[], numOfArgs
  Output: prints the normalized vector array
*/
void normalize(double vectorArray[], int numOfArgs) {
  double N; /*accumulates the sum of values in the vectorArray[] */
  double numSquared; /*represents the square of a vector in the vectorArray[]*/

  for (int i=1; i<=numOfArgs;i++) { /*i is the index for for-loop*/
     numSquared=vectorArray[i] * vectorArray[i];
     N=N + numSquared;
  }
  N=sqrt(N);

  for (int i=1; i<=numOfArgs;i++) { /*i is the index for for-loop*/
    vectorArray[i]=vectorArray[i]/N;
  }

  printNormalizedVector(vectorArray, numOfArgs); /*call to the printNormalizeVector function*/
}


/*Name: printNormalizedVector
  Purpose: prints normalized vector array
  Parameters: vectorArray[] the array of vectors, numOfArgs the length of the vector array
  Return Values: void
  Input: vectorArray[], numOfArgs
  Output: prints the normalized vector array
*/
void printNormalizedVector(double vectorArray[], int numOfArgs) {
  printf(" NORMALIZED: [ ");
  for (int i=1; i<=numOfArgs;i++) { /*i is the index for for-loop*/
     if (i == numOfArgs)
      printf("%.3lf ", vectorArray[i]);
     else
      printf("%.3lf, ", vectorArray[i]);
  }
  printf("]\n");
  readInput(); /*continue to read from the input buffer*/
}

                                     
