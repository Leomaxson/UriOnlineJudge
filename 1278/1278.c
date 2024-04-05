#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Maximum number of chars in a line of the test case (including the \n).
#define MAX_LINE_SIZE (50 + 1)
// Maxximum number of lines in a test case.
#define MAX_NUM_OF_LINES (100)

/**
 * A line of an instance containing words and spaces.
 */
typedef struct SLine {
    int Length;
    char Text[MAX_LINE_SIZE + 1];
} Line;

/**
 * Remove the exceding spaces of a line.
 * @param line Line to remove the spaces that are not necessary.
 */
void Line_RemoveSpaces(Line *line) {
    char *token, text[MAX_LINE_SIZE + 1];

    token = strtok(line->Text, " \n");
    line->Length = sprintf(text, "%s", token);
    token = strtok(NULL, " \n");
    while(token != NULL) {
        line->Length += sprintf(&text[line->Length], " %s", token);
        token = strtok(NULL, " \n");
    }
    strcpy(line->Text, text);
}

/**
 * Represents a test case of the problem.
 */
typedef struct STestCase {
    int NumLines;
    int MaxLineTam;
    Line Lines[MAX_NUM_OF_LINES];
} TestCase;

/**
 * Reads a test case from the stdin.
 * testCase Reference to the test case.
 */
void TestCase_Read(TestCase *testCase) {
    int i;

    (void)scanf("%d", &testCase->NumLines);
    (void)fgets(testCase->Lines[0].Text, MAX_LINE_SIZE, stdin);

    for(i = 0; i < testCase->NumLines; i++) {
        (void)fgets(testCase->Lines[i].Text, MAX_LINE_SIZE, stdin);
    }
}

/**
 * Writes a test case into the stdout.
 * testCase Reference to the test case.
 */
void TestCase_Write(TestCase *testCase) {
    int i;

    for(i = 0; i < testCase->NumLines; i++) {
        (void)printf("%*s\n", testCase->MaxLineTam, testCase->Lines[i].Text);
    }
}

void  TestCase_Process(TestCase *testCase) {
    int i;

    // Removes the exceding spaces of each line and finds the largest resulting line.
    testCase->MaxLineTam = 0;
    for(i = 0; i < testCase->NumLines; i++) {
        Line_RemoveSpaces(&testCase->Lines[i]);
        if(testCase->Lines[i].Length > testCase->MaxLineTam) {
            testCase->MaxLineTam = testCase->Lines[i].Length;
        }
    }
}

int main(int argv, char** argc) {
    TestCase t;

    TestCase_Read(&t);
    while(t.NumLines > 0) {
        TestCase_Process(&t);
        TestCase_Write(&t);
        TestCase_Read(&t);
        if(t.NumLines > 0) {
            (void)printf("\n");
        }
    }
    return 0;
}