
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
void FB_motor(struct FB_motor* inst)
{
	REAL a = inst->u / inst->Ke - inst->out_w;
	REAL b = a / inst->Tm;
	
	inst->integrator.in = b;
	FB_integrator(&inst->integrator);
	
	inst->out_w = inst->integrator.out;
}
