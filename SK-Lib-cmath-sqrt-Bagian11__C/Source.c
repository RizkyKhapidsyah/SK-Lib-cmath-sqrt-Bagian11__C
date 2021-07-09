#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main(void) {  
    printf("sqrt(100) = %f\n", sqrt(100));
    printf("sqrt(2) = %f\n", sqrt(2));
    printf("golden ratio = %f\n", (1 + sqrt(5)) / 2);
    
    printf("sqrt(-0) = %f\n", sqrt(-0.0));
    // penanganan error
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("sqrt(-1.0) = %f\n", sqrt(-1));

    if (errno == EDOM) {
        perror("    errno == EDOM");
    }

    if (fetestexcept(FE_INVALID)) {
        puts("    FE_INVALID was raised");
    }

    _getch();
    return 0;
}