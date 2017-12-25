#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define DEG2RAD0.017453293F

typedef struct {
	float x,y,z;
} point3f_t;
typedef struct {
	uint32_t x,y,z;
} point3i32_t;
/*

https://en.wikipedia.org/wiki/Fast_inverse_square_root

Fast inverse square-root
*/

inline float q_rsqt(float number){
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*) &i;
	y = y * (threehalfs - (x2 * y * y));

	return y;
}
/*

	complement filter

*/
float pid_p = 0.4f;
float pid_i = 0.001f;

point3f_t pid_d = {0.0f, 0.0f, 0.0f};

float q0,q1,q2,q3;
float z_acc = 1.0F;
int is_calibrated = 0;

void imu_init(){
	q0 = 1.0F;
	q1 = q2 = q3 = 0.0F;
}
void imu_9dof(point3f_t acc, point3f_t gyro, int *status, float dt){

}
