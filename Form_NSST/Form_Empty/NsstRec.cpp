#include "NsstRec.h"
#include "MatlabFuncs.h"
#include "NSSTFuncs.h"

/// <summary>
///		This function performs the inverse(local) nonsubsampled shearlet transform as given
/// </summary>
/// <param name="dst">
///		dst - the nonsubsampled shearlet coefficients
/// </param>
/// <param name="lpfilt">
///		lpfilt - the filter to be used for the Laplacian Pyramid / ATrous decomposition using the codes
/// </param>
/// <returns>
///		the reconstructed image
/// </returns>
Matrix* NsstRec1(Cont* dst, const char* lpfilt) {

	int level = dst->matNums - 1;
	
	Cont* y = new Cont(level + 1);
	y->mats[0] = dst->mats[0];

	for (int i = 1; i <= level; i++)		
		y->mats[i] = Sum(dst->mats[i], 3);
	
	
	return AtrousRec(y, lpfilt);
}