/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.183
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Dec 20 11:47:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef FOC_h_
#define FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Motor_state;                  /* '<S1>/Chart' */
  real32_T ThetaOpen;                  /* '<S1>/Merge' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S101>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_k;/* '<S7>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE_a;         /* '<S49>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_FOC;            /* '<S1>/Chart' */
  uint8_T is_c3_FOC;                   /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ia;                           /* '<Root>/ia' */
  real_T ib;                           /* '<Root>/ib' */
  real_T ic;                           /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void FOC_initialize(void);
extern void FOC_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('JointModel/FOC')    - opens subsystem JointModel/FOC
 * hilite_system('JointModel/FOC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'JointModel'
 * '<S1>'   : 'JointModel/FOC'
 * '<S2>'   : 'JointModel/FOC/Anti-Park'
 * '<S3>'   : 'JointModel/FOC/Chart'
 * '<S4>'   : 'JointModel/FOC/Clark'
 * '<S5>'   : 'JointModel/FOC/If Action Subsystem'
 * '<S6>'   : 'JointModel/FOC/If Action Subsystem1'
 * '<S7>'   : 'JointModel/FOC/If Action Subsystem2'
 * '<S8>'   : 'JointModel/FOC/If Action Subsystem3'
 * '<S9>'   : 'JointModel/FOC/PID_I'
 * '<S10>'  : 'JointModel/FOC/Park'
 * '<S11>'  : 'JointModel/FOC/SVPWM'
 * '<S12>'  : 'JointModel/FOC/PID_I/PID Controller1'
 * '<S13>'  : 'JointModel/FOC/PID_I/PID Controller2'
 * '<S14>'  : 'JointModel/FOC/PID_I/PID Controller1/Anti-windup'
 * '<S15>'  : 'JointModel/FOC/PID_I/PID Controller1/D Gain'
 * '<S16>'  : 'JointModel/FOC/PID_I/PID Controller1/External Derivative'
 * '<S17>'  : 'JointModel/FOC/PID_I/PID Controller1/Filter'
 * '<S18>'  : 'JointModel/FOC/PID_I/PID Controller1/Filter ICs'
 * '<S19>'  : 'JointModel/FOC/PID_I/PID Controller1/I Gain'
 * '<S20>'  : 'JointModel/FOC/PID_I/PID Controller1/Ideal P Gain'
 * '<S21>'  : 'JointModel/FOC/PID_I/PID Controller1/Ideal P Gain Fdbk'
 * '<S22>'  : 'JointModel/FOC/PID_I/PID Controller1/Integrator'
 * '<S23>'  : 'JointModel/FOC/PID_I/PID Controller1/Integrator ICs'
 * '<S24>'  : 'JointModel/FOC/PID_I/PID Controller1/N Copy'
 * '<S25>'  : 'JointModel/FOC/PID_I/PID Controller1/N Gain'
 * '<S26>'  : 'JointModel/FOC/PID_I/PID Controller1/P Copy'
 * '<S27>'  : 'JointModel/FOC/PID_I/PID Controller1/Parallel P Gain'
 * '<S28>'  : 'JointModel/FOC/PID_I/PID Controller1/Reset Signal'
 * '<S29>'  : 'JointModel/FOC/PID_I/PID Controller1/Saturation'
 * '<S30>'  : 'JointModel/FOC/PID_I/PID Controller1/Saturation Fdbk'
 * '<S31>'  : 'JointModel/FOC/PID_I/PID Controller1/Sum'
 * '<S32>'  : 'JointModel/FOC/PID_I/PID Controller1/Sum Fdbk'
 * '<S33>'  : 'JointModel/FOC/PID_I/PID Controller1/Tracking Mode'
 * '<S34>'  : 'JointModel/FOC/PID_I/PID Controller1/Tracking Mode Sum'
 * '<S35>'  : 'JointModel/FOC/PID_I/PID Controller1/Tsamp - Integral'
 * '<S36>'  : 'JointModel/FOC/PID_I/PID Controller1/Tsamp - Ngain'
 * '<S37>'  : 'JointModel/FOC/PID_I/PID Controller1/postSat Signal'
 * '<S38>'  : 'JointModel/FOC/PID_I/PID Controller1/preSat Signal'
 * '<S39>'  : 'JointModel/FOC/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S40>'  : 'JointModel/FOC/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S41>'  : 'JointModel/FOC/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S42>'  : 'JointModel/FOC/PID_I/PID Controller1/D Gain/Disabled'
 * '<S43>'  : 'JointModel/FOC/PID_I/PID Controller1/External Derivative/Disabled'
 * '<S44>'  : 'JointModel/FOC/PID_I/PID Controller1/Filter/Disabled'
 * '<S45>'  : 'JointModel/FOC/PID_I/PID Controller1/Filter ICs/Disabled'
 * '<S46>'  : 'JointModel/FOC/PID_I/PID Controller1/I Gain/External Parameters'
 * '<S47>'  : 'JointModel/FOC/PID_I/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'JointModel/FOC/PID_I/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'JointModel/FOC/PID_I/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'JointModel/FOC/PID_I/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'JointModel/FOC/PID_I/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S52>'  : 'JointModel/FOC/PID_I/PID Controller1/N Gain/Disabled'
 * '<S53>'  : 'JointModel/FOC/PID_I/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'JointModel/FOC/PID_I/PID Controller1/Parallel P Gain/External Parameters'
 * '<S55>'  : 'JointModel/FOC/PID_I/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'JointModel/FOC/PID_I/PID Controller1/Saturation/Enabled'
 * '<S57>'  : 'JointModel/FOC/PID_I/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'JointModel/FOC/PID_I/PID Controller1/Sum/Sum_PI'
 * '<S59>'  : 'JointModel/FOC/PID_I/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'JointModel/FOC/PID_I/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'JointModel/FOC/PID_I/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'JointModel/FOC/PID_I/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S63>'  : 'JointModel/FOC/PID_I/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'JointModel/FOC/PID_I/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'JointModel/FOC/PID_I/PID Controller1/preSat Signal/Forward_Path'
 * '<S66>'  : 'JointModel/FOC/PID_I/PID Controller2/Anti-windup'
 * '<S67>'  : 'JointModel/FOC/PID_I/PID Controller2/D Gain'
 * '<S68>'  : 'JointModel/FOC/PID_I/PID Controller2/External Derivative'
 * '<S69>'  : 'JointModel/FOC/PID_I/PID Controller2/Filter'
 * '<S70>'  : 'JointModel/FOC/PID_I/PID Controller2/Filter ICs'
 * '<S71>'  : 'JointModel/FOC/PID_I/PID Controller2/I Gain'
 * '<S72>'  : 'JointModel/FOC/PID_I/PID Controller2/Ideal P Gain'
 * '<S73>'  : 'JointModel/FOC/PID_I/PID Controller2/Ideal P Gain Fdbk'
 * '<S74>'  : 'JointModel/FOC/PID_I/PID Controller2/Integrator'
 * '<S75>'  : 'JointModel/FOC/PID_I/PID Controller2/Integrator ICs'
 * '<S76>'  : 'JointModel/FOC/PID_I/PID Controller2/N Copy'
 * '<S77>'  : 'JointModel/FOC/PID_I/PID Controller2/N Gain'
 * '<S78>'  : 'JointModel/FOC/PID_I/PID Controller2/P Copy'
 * '<S79>'  : 'JointModel/FOC/PID_I/PID Controller2/Parallel P Gain'
 * '<S80>'  : 'JointModel/FOC/PID_I/PID Controller2/Reset Signal'
 * '<S81>'  : 'JointModel/FOC/PID_I/PID Controller2/Saturation'
 * '<S82>'  : 'JointModel/FOC/PID_I/PID Controller2/Saturation Fdbk'
 * '<S83>'  : 'JointModel/FOC/PID_I/PID Controller2/Sum'
 * '<S84>'  : 'JointModel/FOC/PID_I/PID Controller2/Sum Fdbk'
 * '<S85>'  : 'JointModel/FOC/PID_I/PID Controller2/Tracking Mode'
 * '<S86>'  : 'JointModel/FOC/PID_I/PID Controller2/Tracking Mode Sum'
 * '<S87>'  : 'JointModel/FOC/PID_I/PID Controller2/Tsamp - Integral'
 * '<S88>'  : 'JointModel/FOC/PID_I/PID Controller2/Tsamp - Ngain'
 * '<S89>'  : 'JointModel/FOC/PID_I/PID Controller2/postSat Signal'
 * '<S90>'  : 'JointModel/FOC/PID_I/PID Controller2/preSat Signal'
 * '<S91>'  : 'JointModel/FOC/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S92>'  : 'JointModel/FOC/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S93>'  : 'JointModel/FOC/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S94>'  : 'JointModel/FOC/PID_I/PID Controller2/D Gain/Disabled'
 * '<S95>'  : 'JointModel/FOC/PID_I/PID Controller2/External Derivative/Disabled'
 * '<S96>'  : 'JointModel/FOC/PID_I/PID Controller2/Filter/Disabled'
 * '<S97>'  : 'JointModel/FOC/PID_I/PID Controller2/Filter ICs/Disabled'
 * '<S98>'  : 'JointModel/FOC/PID_I/PID Controller2/I Gain/External Parameters'
 * '<S99>'  : 'JointModel/FOC/PID_I/PID Controller2/Ideal P Gain/Passthrough'
 * '<S100>' : 'JointModel/FOC/PID_I/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'JointModel/FOC/PID_I/PID Controller2/Integrator/Discrete'
 * '<S102>' : 'JointModel/FOC/PID_I/PID Controller2/Integrator ICs/Internal IC'
 * '<S103>' : 'JointModel/FOC/PID_I/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S104>' : 'JointModel/FOC/PID_I/PID Controller2/N Gain/Disabled'
 * '<S105>' : 'JointModel/FOC/PID_I/PID Controller2/P Copy/Disabled'
 * '<S106>' : 'JointModel/FOC/PID_I/PID Controller2/Parallel P Gain/External Parameters'
 * '<S107>' : 'JointModel/FOC/PID_I/PID Controller2/Reset Signal/Disabled'
 * '<S108>' : 'JointModel/FOC/PID_I/PID Controller2/Saturation/Enabled'
 * '<S109>' : 'JointModel/FOC/PID_I/PID Controller2/Saturation Fdbk/Disabled'
 * '<S110>' : 'JointModel/FOC/PID_I/PID Controller2/Sum/Sum_PI'
 * '<S111>' : 'JointModel/FOC/PID_I/PID Controller2/Sum Fdbk/Disabled'
 * '<S112>' : 'JointModel/FOC/PID_I/PID Controller2/Tracking Mode/Disabled'
 * '<S113>' : 'JointModel/FOC/PID_I/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'JointModel/FOC/PID_I/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S115>' : 'JointModel/FOC/PID_I/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'JointModel/FOC/PID_I/PID Controller2/postSat Signal/Forward_Path'
 * '<S117>' : 'JointModel/FOC/PID_I/PID Controller2/preSat Signal/Forward_Path'
 * '<S118>' : 'JointModel/FOC/SVPWM/Anti-Clark'
 * '<S119>' : 'JointModel/FOC/SVPWM/ei_t'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
