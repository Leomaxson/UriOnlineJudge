#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Maximum number of chars in a word.
#define MAX_WORD_SIZE (50)
// Maxximum number of words in a test case.
#define MAX_NUM_OF_WORDS (50)

/**
 * A word of an instance.
 */
typedef struct SWord {
  int Size;
  char Text[MAX_WORD_SIZE + 1];
} Word;

/**
 * Represents a test case of the problem.
 */
typedef struct STestCase {
  int NumWords;
  int MaxWordTam;
  Word Words[MAX_NUM_OF_WORDS];
} TestCase;

/**
 * Reads a test case from the stdin.
 * testCase Reference to the test case.
 */
void TestCase_Read(TestCase *testCase) {
  int i;

  (void)scanf("%d", &testCase->NumWords);
  for(i = 0; i < testCase->NumWords; i++) {
    (void)scanf("%s", testCase->Words[i].Text);
    testCase->Words[i].Size = strlen(testCase->Words[i].Text);
  }
}

/**
 * Writes a test case into the stdout.
 * testCase Reference to the test case.
 */
void TestCase_Write(TestCase *testCase) {
  int i;

  for(i = 0; i < testCase->NumWords; i++) {
    (void)printf("%*s\n", testCase->MaxWordTam, testCase->Words[i].Text);
  }
}

void  TestCase_Process(TestCase *testCase) {
  int i;

  // Finds the largest word.
  testCase->MaxWordTam = 0;
  for(i = 0; i < testCase->NumWords; i++) {
    if(testCase->Words[i].Size > testCase->MaxWordTam) {
      testCase->MaxWordTam = testCase->Words[i].Size;
    }
  }
}

int main(int argv, char** argc) {
  TestCase t;

  TestCase_Read(&t);
  while(t.NumWords > 0) {
    TestCase_Process(&t);
    TestCase_Write(&t);
    TestCase_Read(&t);
    if(t.NumWords > 0) {
      printf("\n");
    }
  }
  return 0;
}