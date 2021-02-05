#include <bitset>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef unsigned long ul;

vector<unsigned long> binaryConversion(const string);
vector<unsigned long> addPadOf512Bits(const vector<unsigned long>);
vector<unsigned long> resizingTheBlock(vector<unsigned long>);
string computingTheHash(const vector<unsigned long>);
string displayAsHex(unsigned long);
void outputTheBlockState(vector<unsigned long>);
string displayAsBinary(unsigned long);
const bool displayBlockStateAddOne = 0;
const bool displayDistanceFrom512Bit = 0;
const bool displayResultsOfPadding = false;
const bool displayWorkVariablesForT = 0;
const bool displayT1Computation = false;
const bool displayT2Computation = false;
const bool displayTheHashSegments = false;
const bool displayWt = false;
// Defined in accord w/ NIST standard
#define ROTRIGHT(word, bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define SSIG0 (x) (ROTRIGHT(x,7) ^ ROTRIGHT(x, 18) ^ ROTRIGHT(x, 18) ^ ((x) >> 3))
#define SSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define BSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define BSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))

