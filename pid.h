volatile int pre_error = 0;
const u16 LEFT_MAX_POSITION = 3100;
const u16 INITIAL_POSITION = 4700;
const u16 RIGHT_MAX_POSITION = 6300;
const u16 IDEAL_DIFF = 20;
const u32 dt = 35;  // in ms
const float K_p = 0.1, K_d = 0.01;    // constants for PID
const float K_s = 3.2;      // constant for conversion from mag_diff to SERVO PWM
u16 pid_cal(u16* mag_diff);

