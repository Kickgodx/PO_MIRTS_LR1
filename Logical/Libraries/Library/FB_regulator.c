
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_regulator(struct FB_regulator* inst)
{
	REAL a = inst->e * inst->k_p;
	REAL b = inst->e * inst->k_i;
	a = a > inst->max_abs_value ? inst->max_abs_value : a;
	a = a < -inst->max_abs_value ? -inst->max_abs_value : a;
	inst->integrator.in = b + inst->iyOld;
	FB_integrator(&inst->integrator);
	REAL sum = a + inst->integrator.out;
	inst->u = sum;
	inst->u = inst->u >inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < -inst->max_abs_value ? -inst->max_abs_value : inst->u;
	inst->iyOld = inst->u - sum;
}
