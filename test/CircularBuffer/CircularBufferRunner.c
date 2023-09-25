#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer){
    RUN_TEST_CASE(CircularBuffer, EmnptyBufferAfterCreate);
    RUN_TEST_CASE(CircularBuffer, CorecttSizeAffterCreate);
    RUN_TEST_CASE(CircularBuffer, PutOneElement);
    RUN_TEST_CASE(CircularBuffer, GetOneElement);

    

}