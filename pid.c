// PID without the integral term
#include "pid.h"

u16 pid_cal(u16* mag_diff) {
    
    u16 output = 0, error = 0, derivative = 0;
    
    // in the right range
    if (*mag_diff > -IDEAL_DIFF && *mag_diff < IDEAL_DIFF) return INITIAL_POSITION;
    
    // proportional term
    error = IDEAL_DIFF - *mag_diff;
    // derivative term
    derivative = (error - pre_error) / dt;
    
    // determine output and convert to PWM
    output = (K_p*error + K_d*derivative)*K_s;
    
    // Filtering
    if (output < LEFT_MAX_POSITION) output = LEFT_MAX_POSITION;
    if (output > RIGHT_MAX_POSITION) output = RIGHT_MAX_POSITION;
    
    
    // update previous error
    pre_error = error;
    
    return output;
}
