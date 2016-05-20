
// Author John B. Crossley
// Exam (05/19/2016))
//

// next line used to toggle testmode
#define testMode

//
//CMPS 335
//Exam framework.
//Name this program lab8.cpp.
//Write code to perform a unit-test on a function.
//Function name: bodyShapeIndex().
//
//SBSI is can be a measure of health for some people.
//
//Range of data is from the following source...
//http://journals.plos.org/plosone/article?id=10.1371/journal.pone.0144639
//
//The SBSI formula has four input values.
//
//	                                      Average     SD
//	                                      ---------   --------
//	. body surface area (cm^2)            18074.000   2168.000
//	. vertical trunk circumference (cm)     174.924     11.908
//	. height (cm)                           167.726     10.102
//	. waist circumference (cm)               92.190     13.229
//
//The formula is:
//
//   (height^(7/4)) * (waistCircumference^(5/6))
//   --------------------------------------------
//   bodySurfaceArea * verticalTrunkCircumference
//
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
using namespace std;


typedef double Flt;

#ifdef testMode
//Define floating-point standard
double testArray [] = 
{157,	79,	163,	15906,	0.102431072,
157,	79,	163,	18074,	0.102144331,
157,	79,	163,	20242,	0.080489509,
157,	79,	175,	15906,	0.083407227,
157,	79,	175,	18074,	0.083963005,
157,	79,	175,	20242,	0.074970228,
157,	79,	187,	15906,	0.089284838,
157,	79,	187,	18074,	0.078575005,
157,	79,	187,	20242,	0.070259304,
157,	92,	163,	15906,	0.116196238,
157,	92,	163,	18074,	0.102346352,
157,	92,	163,	20242,	0.091384644,
157,	92,	175,	15906,	0.118321639,
157,	92,	175,	18074,	0.105328316,
157,	92,	175,	20242,	0.085118268,
157,	92,	187,	15906,	0.101370517,
157,	92,	187,	18074,	0.089210991,
157,	92,	187,	20242,	0.079656133,
157,	105,	163,	15906,	0.129837524,
157,	105,	163,	18074,	0.114263343,
157,	105,	163,	20242,	0.102025277,
157,	105,	175,	15906,	0.120934380,
157,	105,	175,	18074,	0.106428142,
157,	105,	175,	20242,	0.095029258,
157,	105,	187,	15906,	0.113173885,
157,	105,	187,	18074,	0.099598529,
157,	105,	187,	20242,	0.088931124,
167,	79,	163,	15906,	0.114119839,
167,	79,	163,	18074,	0.100431015,
167,	79,	163,	20242,	0.089674447,
167,	79,	175,	15906,	0.106294479,
167,	79,	175,	18074,	0.093544317,
167,	79,	175,	20242,	0.083525342,
167,	79,	187,	15906,	0.099473443,
167,	79,	187,	18074,	0.087541473,
167,	79,	187,	20242,	0.078165427,
167,	92,	163,	15906,	0.129567207,
167,	92,	163,	18074,	0.114025451,
167,	92,	163,	20242,	0.101812864,
167,	92,	175,	15906,	0.120682599,
167,	92,	175,	18074,	0.106206563,
167,	92,	175,	20242,	0.094831411,
167,	92,	187,	15906,	0.112938261,
167,	92,	187,	18074,	0.099391168,
167,	92,	187,	20242,	0.088745973,
167,	105,	163,	15906,	0.144653737,
167,	105,	163,	18074,	0.127302332,
167,	105,	163,	20242,	0.113667737,
167,	105,	175,	15906,	0.134734624,
167,	105,	175,	18074,	0.118573029,
167,	105,	175,	20242,	0.105873378,
167,	105,	187,	15906,	0.126088552,
167,	105,	187,	18074,	0.110964064,
167,	105,	187,	20242,	0.099079365,
177,	79,	163,	15906,	0.126345722,
177,	79,	163,	18074,	0.111190387,
177,	79,	163,	20242,	0.099281448,
177,	79,	175,	15906,	0.117682016,
177,	79,	175,	18074,	0.103565904,
177,	79,	175,	20242,	0.092473577,
177,	79,	187,	15906,	0.110130229,
177,	79,	187,	18074,	0.096919963,
177,	79,	187,	20242,	0.086539444,
177,	92,	163,	15906,	0.143447997,
177,	92,	163,	18074,	0.126241222,
177,	92,	163,	20242,	0.112720277,
177,	92,	175,	15906,	0.133611563,
177,	92,	175,	18074,	0.117584681,
177,	92,	175,	20242,	0.104990887,
177,	92,	187,	15906,	0.125037559,
177,	92,	187,	18074,	0.110039140,
177,	92,	187,	20242,	0.098253503,
177,	105,	163,	15906,	0.160150777,
177,	105,	163,	18074,	0.140940481,
177,	105,	163,	20242,	0.125845186,
177,	105,	175,	15906,	0.139169009,
177,	105,	175,	18074,	0.121275991,
177,	105,	175,	20242,	0.117215802,
177,	105,	187,	15906,	0.139596666,
177,	105,	187,	18074,	0.122851863,
177,	105,	187,	20242,	0.109693932
};



#endif 
double testTolerance (double test);


//Structure to hold components of the SBSI furmula.
//h    height;
//wc   waist circumference;
//bsa  body surface area;
//vtc  vertical trunk circumference;
struct SBSI {
	Flt h;
	Flt wc;
	Flt bsa;
	Flt vtc;
};
Flt bodyShapeIndex(SBSI *sbsi);

int main(int argc, char *argv[])
{
	// SBSI sbsi;
	//

        cout << endl;
        
        cout << "argv[0]" << argv[0] << endl;
        cout << "argv[1]" << argv[1] << endl;
        cout << "argv[2]" << argv[2] << endl;
        cout << endl;
        cout << endl;

#ifndef testMode
	cout << "cs335 Surface-based body shape index calculator.\n";
	cout << endl;
	cout << "Input your 4 values now.\n";
	cout << " . height\n";
	cout << " . waist circumference\n";
	cout << " . body surface area\n";
	cout << " . vertical trunk circumference\n";

	cin >> sbsi.h >> sbsi.wc >> sbsi.bsa >> sbsi.vtc;
	//
	Flt val = bodyShapeIndex(&sbsi);
	cout << "Thanks.\n";
	cout << "Your SBSI index is: " << val << endl;
	cout << endl;
#endif 

#ifdef testMode        
        // ZERO based
        // row * numOfcols + item position
        // cout << "test data main" << testArray[8*5+4] << endl;
        printf ("test double precision out %2.10lf", testArray[8*5+4]);
        cout << endl;
        // testTolerance(testArray[8*5+4]);
        cout << endl;
        testTolerance (atof(argv[2]));
        
#endif         
	return 0;
}


#ifdef testMode
double testTolerance (double userTolerance) {

    // setup test vals...
    SBSI sbsi;
//    sbsi.bsa = 15906;
//    sbsi.h = 157;
//    sbsi.vtc = 175;
//    sbsi.wc = 92;
    
    // int done = 0;
    int row = 0;
    int col = 5;
    
    double testResults;
    
    // int outSideTol = 0;
    while (row < 82) {
        
        
        sbsi.bsa = testArray[row*col+3];
        sbsi.h = testArray[row*col+0];
        sbsi.vtc = testArray[row*col+2];
        sbsi.wc = testArray[row*col+1];
        row += 1;

        testResults = bodyShapeIndex(&sbsi);        
        

        
    printf ("test results from testTolerance %2.11lf", testResults);
    if ( fabs(testResults) - fabs(testArray[row*col+4]) > userTolerance) {
            printf ("<--- outside tolerance");

    }
    cout << endl;
        
    }
        
        

            
    
//    cout << "test data from testTolerance: " << testArray[3*5+3] << endl;
//    cout << "passed val:" << test << endl;
//    cout << endl;
//    cout << endl;
//    printf ("testResults %2.10lf", testArray[12*5+4]);
//    cout << endl;
//    printf ("test datatestTolerance %2.11lf", testArray[12*5+4]);
//    cout << endl;
//    printf ("test results from testTolerance %2.11lf", testResults);
//    cout << endl;
    cout << endl;

        
        return 0;
    
}

#endif 
//------------------------------------------
//Do not modify this function on the exam.
//------------------------------------------
Flt bodyShapeIndex(SBSI *sbsi)
{
	// Calculate SBSI --- Surface-based Body Shape Index
	//    (height^(7/4)) * (waistCircumference^(5/6))
	//    --------------------------------------------
	//    bodySurfaceArea * verticalTrunkCircumference
	//
	Flt ret = 0.0;
	Flt p1 = 7.0 / 4.0;
	Flt p2 = 5.0 / 6.0;
	Flt n1 = pow(sbsi->h, p1);
	Flt n2 = pow(sbsi->wc, p2);
	Flt d1 = sbsi->bsa;
	Flt d2 = sbsi->vtc;
	Flt r1 = (n1 * n2);
	Flt r2 = (d1 * d2);
	if (r2 != 0.0)
		ret = (r1 / r2);
	return ret;
}
