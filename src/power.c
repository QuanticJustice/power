#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prettyprint.h"

double power( double base, double exponent )
{
	double rv = pow( base, exponent );
	prettyprint( (int) rv );
	return rv;
}
