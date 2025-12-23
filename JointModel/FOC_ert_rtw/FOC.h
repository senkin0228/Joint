/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.220
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Dec 23 10:27:47 2025
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
  real_T Motor_state;                  /* '<S2>/Chart' */
  real32_T Saturation;                 /* '<S165>/Saturation' */
  real32_T ThetaOpen;                  /* '<S2>/Merge' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S158>/Integrator' */
  real32_T Integrator_DSTATE_g;        /* '<S103>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S9>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T Integrator_PREV_U;          /* '<S158>/Integrator' */
  uint32_T speedloop_PREV_T;           /* '<S1>/speedloop' */
  int16_T Integrator_DSTATE_a;         /* '<S51>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S158>/Integrator' */
  uint8_T is_active_c3_FOC;            /* '<S2>/Chart' */
  uint8_T is_c3_FOC;                   /* '<S2>/Chart' */
  boolean_T speedloop_RESET_ELAPS_T;   /* '<S1>/speedloop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ia;                           /* '<Root>/ia' */
  real_T ib;                           /* '<Root>/ib' */
  real_T ic;                           /* '<Root>/ic' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real32_T SpeedFd;                    /* '<Root>/SpeedFd' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Real_Theta;                 /* '<Root>/ Real_Theta' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tABC[3];                    /* '<Root>/tABC' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
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
 * Block '<S11>/Scope4' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope3' : Unused code path elimination
 * Block '<S2>/Scope4' : Unused code path elimination
 * Block '<S2>/Scope5' : Unused code path elimination
 * Block '<S2>/Scope6' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
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
 * '<S2>'   : 'JointModel/FOC/CurrentLoop'
 * '<S3>'   : 'JointModel/FOC/speedloop'
 * '<S4>'   : 'JointModel/FOC/CurrentLoop/Anti-Park'
 * '<S5>'   : 'JointModel/FOC/CurrentLoop/Chart'
 * '<S6>'   : 'JointModel/FOC/CurrentLoop/Clark'
 * '<S7>'   : 'JointModel/FOC/CurrentLoop/If Action Subsystem'
 * '<S8>'   : 'JointModel/FOC/CurrentLoop/If Action Subsystem1'
 * '<S9>'   : 'JointModel/FOC/CurrentLoop/If Action Subsystem2'
 * '<S10>'  : 'JointModel/FOC/CurrentLoop/If Action Subsystem3'
 * '<S11>'  : 'JointModel/FOC/CurrentLoop/PID_I'
 * '<S12>'  : 'JointModel/FOC/CurrentLoop/Park'
 * '<S13>'  : 'JointModel/FOC/CurrentLoop/SVPWM'
 * '<S14>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1'
 * '<S15>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2'
 * '<S16>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup'
 * '<S17>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/D Gain'
 * '<S18>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/External Derivative'
 * '<S19>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter'
 * '<S20>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter ICs'
 * '<S21>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/I Gain'
 * '<S22>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain'
 * '<S23>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator'
 * '<S25>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator ICs'
 * '<S26>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Copy'
 * '<S27>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Gain'
 * '<S28>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/P Copy'
 * '<S29>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Parallel P Gain'
 * '<S30>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Reset Signal'
 * '<S31>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation'
 * '<S32>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum'
 * '<S34>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum Fdbk'
 * '<S35>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode'
 * '<S36>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/postSat Signal'
 * '<S40>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/preSat Signal'
 * '<S41>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S43>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S44>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/D Gain/Disabled'
 * '<S45>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/External Derivative/Disabled'
 * '<S46>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter/Disabled'
 * '<S47>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter ICs/Disabled'
 * '<S48>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/I Gain/External Parameters'
 * '<S49>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain/Passthrough'
 * '<S50>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S51>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator/Discrete'
 * '<S52>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator ICs/Internal IC'
 * '<S53>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S54>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Gain/Disabled'
 * '<S55>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/P Copy/Disabled'
 * '<S56>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Parallel P Gain/External Parameters'
 * '<S57>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Reset Signal/Disabled'
 * '<S58>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation/Enabled'
 * '<S59>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation Fdbk/Disabled'
 * '<S60>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum/Sum_PI'
 * '<S61>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum Fdbk/Disabled'
 * '<S62>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode/Disabled'
 * '<S63>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S64>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S65>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S66>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/postSat Signal/Forward_Path'
 * '<S67>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/preSat Signal/Forward_Path'
 * '<S68>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup'
 * '<S69>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/D Gain'
 * '<S70>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/External Derivative'
 * '<S71>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter'
 * '<S72>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter ICs'
 * '<S73>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/I Gain'
 * '<S74>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain'
 * '<S75>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain Fdbk'
 * '<S76>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator'
 * '<S77>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator ICs'
 * '<S78>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Copy'
 * '<S79>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Gain'
 * '<S80>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/P Copy'
 * '<S81>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Parallel P Gain'
 * '<S82>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Reset Signal'
 * '<S83>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation'
 * '<S84>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation Fdbk'
 * '<S85>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum'
 * '<S86>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum Fdbk'
 * '<S87>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode'
 * '<S88>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode Sum'
 * '<S89>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Integral'
 * '<S90>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Ngain'
 * '<S91>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/postSat Signal'
 * '<S92>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/preSat Signal'
 * '<S93>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S94>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S95>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S96>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/D Gain/Disabled'
 * '<S97>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/External Derivative/Disabled'
 * '<S98>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter/Disabled'
 * '<S99>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter ICs/Disabled'
 * '<S100>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/I Gain/External Parameters'
 * '<S101>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain/Passthrough'
 * '<S102>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S103>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator/Discrete'
 * '<S104>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator ICs/Internal IC'
 * '<S105>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S106>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Gain/Disabled'
 * '<S107>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/P Copy/Disabled'
 * '<S108>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Parallel P Gain/External Parameters'
 * '<S109>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Reset Signal/Disabled'
 * '<S110>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation/Enabled'
 * '<S111>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation Fdbk/Disabled'
 * '<S112>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum/Sum_PI'
 * '<S113>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum Fdbk/Disabled'
 * '<S114>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode/Disabled'
 * '<S115>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S116>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S117>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S118>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/postSat Signal/Forward_Path'
 * '<S119>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/preSat Signal/Forward_Path'
 * '<S120>' : 'JointModel/FOC/CurrentLoop/SVPWM/Anti-Clark'
 * '<S121>' : 'JointModel/FOC/CurrentLoop/SVPWM/ei_t'
 * '<S122>' : 'JointModel/FOC/speedloop/PID Controller3'
 * '<S123>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup'
 * '<S124>' : 'JointModel/FOC/speedloop/PID Controller3/D Gain'
 * '<S125>' : 'JointModel/FOC/speedloop/PID Controller3/External Derivative'
 * '<S126>' : 'JointModel/FOC/speedloop/PID Controller3/Filter'
 * '<S127>' : 'JointModel/FOC/speedloop/PID Controller3/Filter ICs'
 * '<S128>' : 'JointModel/FOC/speedloop/PID Controller3/I Gain'
 * '<S129>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain'
 * '<S130>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain Fdbk'
 * '<S131>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator'
 * '<S132>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator ICs'
 * '<S133>' : 'JointModel/FOC/speedloop/PID Controller3/N Copy'
 * '<S134>' : 'JointModel/FOC/speedloop/PID Controller3/N Gain'
 * '<S135>' : 'JointModel/FOC/speedloop/PID Controller3/P Copy'
 * '<S136>' : 'JointModel/FOC/speedloop/PID Controller3/Parallel P Gain'
 * '<S137>' : 'JointModel/FOC/speedloop/PID Controller3/Reset Signal'
 * '<S138>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation'
 * '<S139>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation Fdbk'
 * '<S140>' : 'JointModel/FOC/speedloop/PID Controller3/Sum'
 * '<S141>' : 'JointModel/FOC/speedloop/PID Controller3/Sum Fdbk'
 * '<S142>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode'
 * '<S143>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode Sum'
 * '<S144>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Integral'
 * '<S145>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Ngain'
 * '<S146>' : 'JointModel/FOC/speedloop/PID Controller3/postSat Signal'
 * '<S147>' : 'JointModel/FOC/speedloop/PID Controller3/preSat Signal'
 * '<S148>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S149>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S150>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S151>' : 'JointModel/FOC/speedloop/PID Controller3/D Gain/Disabled'
 * '<S152>' : 'JointModel/FOC/speedloop/PID Controller3/External Derivative/Disabled'
 * '<S153>' : 'JointModel/FOC/speedloop/PID Controller3/Filter/Disabled'
 * '<S154>' : 'JointModel/FOC/speedloop/PID Controller3/Filter ICs/Disabled'
 * '<S155>' : 'JointModel/FOC/speedloop/PID Controller3/I Gain/Internal Parameters'
 * '<S156>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S157>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S158>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator/Discrete'
 * '<S159>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator ICs/Internal IC'
 * '<S160>' : 'JointModel/FOC/speedloop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S161>' : 'JointModel/FOC/speedloop/PID Controller3/N Gain/Disabled'
 * '<S162>' : 'JointModel/FOC/speedloop/PID Controller3/P Copy/Disabled'
 * '<S163>' : 'JointModel/FOC/speedloop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S164>' : 'JointModel/FOC/speedloop/PID Controller3/Reset Signal/Disabled'
 * '<S165>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation/Enabled'
 * '<S166>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S167>' : 'JointModel/FOC/speedloop/PID Controller3/Sum/Sum_PI'
 * '<S168>' : 'JointModel/FOC/speedloop/PID Controller3/Sum Fdbk/Disabled'
 * '<S169>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode/Disabled'
 * '<S170>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S171>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S172>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S173>' : 'JointModel/FOC/speedloop/PID Controller3/postSat Signal/Forward_Path'
 * '<S174>' : 'JointModel/FOC/speedloop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
