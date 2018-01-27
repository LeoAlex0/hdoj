#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const long double map[]={100,98.3399,96.6937,95.0616,93.4433,91.8391,90.2488,
    88.6725,87.1102,85.5618,84.0274,82.507,81.0006,79.5081,78.0297,76.5652,
    75.1141,73.6758,72.2516,70.8414,69.4451,68.0628,66.6944,65.3401,63.9997,
    62.6733,61.3608,60.0624,58.7779,57.5074,56.2508,55.0083,53.7785,52.5623,
    51.36,50.1717,48.9974,47.8377,46.6921,45.5603,44.4426,43.3388,42.2491,
    41.1733,40.1114,39.0635,38.0297,37.0097,36.0021,35.0085,34.0288,33.0632,
    32.1115,31.1738,30.25,29.3402,28.4445,27.5627,26.6948,25.841,25.0011,
    24.1752,23.3632,22.5646,21.779,21.0073,20.2496,19.5059,18.7762,18.0604,
    17.3586,16.6708,15.997,15.3378,14.6926,14.0614,13.4442,12.8409,12.2516,
    11.6751,11.1121,10.5631,10.028,9.50693,8.99986,8.50674,8.0276,7.56244,
    7.11125,6.67405,6.25081,5.84153,5.44626,5.06493,4.69743,4.34242,4.00137,
    3.67431,3.36123,3.0621,2.77698,2.5058,2.2486,2.00539,1.77613,1.56085,
    1.35954,1.17221,0.998873,0.840193,0.694776,0.5624,0.44402,0.339614,
    0.249174,0.172701,0.110208,0.0616975,0.0271682,0.00658951,0};


int main(int argc, char const *argv[]) {
    double D;
    ios::sync_with_stdio(false);

    cout<<setiosflags(ios::fixed)<<setpr