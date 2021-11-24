#include "unity.h"
#include <parking.h>

/* Modify these two lines according to the project */
#include <parking.h>
#define PROJECT_NAME    "Parking_Management_System"

/* Prototypes for all the test functions */
void test_park(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_park);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_park(void) {
  TEST_ASSERT_EQUAL(1, open(arrival.dat));
  TEST_ASSERT_EQUAL(2, open(depart.dat));
  TEST_ASSERT_EQUAL(3, open(finesheet.dat));
 
    /* Dummy fail*/
  // TEST_ASSERT_EQUAL(0, file does not exist);
  
}