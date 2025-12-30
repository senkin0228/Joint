/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.250
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Dec 30 15:45:02 2025
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
  real_T Motor_state;                  /* '<S3>/Chart' */
  real32_T Saturation_i;               /* '<S219>/Saturation' */
  real32_T ThetaOpen;                  /* '<S3>/Merge' */
  real32_T Merge1;                     /* '<S3>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S41>/Integrator' */
  real32_T Integrator_DSTATE_g;        /* '<S212>/Integrator' */
  real32_T Integrator_DSTATE_go;       /* '<S157>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S63>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S63>/Discrete-Time Integrator' */
  real32_T Integrator_PREV_U;          /* '<S41>/Integrator' */
  real32_T Integrator_PREV_U_l;        /* '<S212>/Integrator' */
  uint32_T AngleLoop_PREV_T;           /* '<S1>/AngleLoop' */
  uint32_T speedloop_PREV_T;           /* '<S1>/speedloop' */
  int16_T Integrator_DSTATE_a;         /* '<S105>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S41>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE_b;  /* '<S212>/Integrator' */
  uint8_T is_active_c3_FOC;            /* '<S3>/Chart' */
  uint8_T is_c3_FOC;                   /* '<S3>/Chart' */
  boolean_T AngleLoop_RESET_ELAPS_T;   /* '<S1>/AngleLoop' */
  boolean_T speedloop_RESET_ELAPS_T;   /* '<S1>/speedloop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ia;                           /* '<Root>/ia' */
  real_T ib;                           /* '<Root>/ib' */
  real_T ic;                           /* '<Root>/ic' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
  real32_T SpeedFd;                    /* '<Root>/SpeedFd' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Real_Theta;                 /* '<Root>/ Real_Theta' */
  real_T AngleRef;                     /* '<Root>/AngleRef' */
  real32_T MechAngle;                  /* '<Root>/MechAngle' */
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
 * Block '<S64>/Gain' : Unused code path elimination
 * Block '<S65>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S3>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope5' : Unused code path elimination
 * Block '<S3>/Scope6' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
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
 * '<S2>'   : 'JointModel/FOC/AngleLoop'
 * '<S3>'   : 'JointModel/FOC/CurrentLoop'
 * '<S4>'   : 'JointModel/FOC/speedloop'
 * '<S5>'   : 'JointModel/FOC/AngleLoop/PID Controller3'
 * '<S6>'   : 'JointModel/FOC/AngleLoop/PID Controller3/Anti-windup'
 * '<S7>'   : 'JointModel/FOC/AngleLoop/PID Controller3/D Gain'
 * '<S8>'   : 'JointModel/FOC/AngleLoop/PID Controller3/External Derivative'
 * '<S9>'   : 'JointModel/FOC/AngleLoop/PID Controller3/Filter'
 * '<S10>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Filter ICs'
 * '<S11>'  : 'JointModel/FOC/AngleLoop/PID Controller3/I Gain'
 * '<S12>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Ideal P Gain'
 * '<S13>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Ideal P Gain Fdbk'
 * '<S14>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Integrator'
 * '<S15>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Integrator ICs'
 * '<S16>'  : 'JointModel/FOC/AngleLoop/PID Controller3/N Copy'
 * '<S17>'  : 'JointModel/FOC/AngleLoop/PID Controller3/N Gain'
 * '<S18>'  : 'JointModel/FOC/AngleLoop/PID Controller3/P Copy'
 * '<S19>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Parallel P Gain'
 * '<S20>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Reset Signal'
 * '<S21>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Saturation'
 * '<S22>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Saturation Fdbk'
 * '<S23>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Sum'
 * '<S24>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Sum Fdbk'
 * '<S25>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tracking Mode'
 * '<S26>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tracking Mode Sum'
 * '<S27>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tsamp - Integral'
 * '<S28>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tsamp - Ngain'
 * '<S29>'  : 'JointModel/FOC/AngleLoop/PID Controller3/postSat Signal'
 * '<S30>'  : 'JointModel/FOC/AngleLoop/PID Controller3/preSat Signal'
 * '<S31>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S32>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S33>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S34>'  : 'JointModel/FOC/AngleLoop/PID Controller3/D Gain/Disabled'
 * '<S35>'  : 'JointModel/FOC/AngleLoop/PID Controller3/External Derivative/Disabled'
 * '<S36>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Filter/Disabled'
 * '<S37>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Filter ICs/Disabled'
 * '<S38>'  : 'JointModel/FOC/AngleLoop/PID Controller3/I Gain/Internal Parameters'
 * '<S39>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S40>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Integrator/Discrete'
 * '<S42>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Integrator ICs/Internal IC'
 * '<S43>'  : 'JointModel/FOC/AngleLoop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'JointModel/FOC/AngleLoop/PID Controller3/N Gain/Disabled'
 * '<S45>'  : 'JointModel/FOC/AngleLoop/PID Controller3/P Copy/Disabled'
 * '<S46>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Reset Signal/Disabled'
 * '<S48>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Saturation/Enabled'
 * '<S49>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S50>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Sum/Sum_PI'
 * '<S51>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Sum Fdbk/Disabled'
 * '<S52>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tracking Mode/Disabled'
 * '<S53>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'JointModel/FOC/AngleLoop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'JointModel/FOC/AngleLoop/PID Controller3/postSat Signal/Forward_Path'
 * '<S57>'  : 'JointModel/FOC/AngleLoop/PID Controller3/preSat Signal/Forward_Path'
 * '<S58>'  : 'JointModel/FOC/CurrentLoop/Anti-Park'
 * '<S59>'  : 'JointModel/FOC/CurrentLoop/Chart'
 * '<S60>'  : 'JointModel/FOC/CurrentLoop/Clark'
 * '<S61>'  : 'JointModel/FOC/CurrentLoop/If Action Subsystem'
 * '<S62>'  : 'JointModel/FOC/CurrentLoop/If Action Subsystem1'
 * '<S63>'  : 'JointModel/FOC/CurrentLoop/If Action Subsystem2'
 * '<S64>'  : 'JointModel/FOC/CurrentLoop/If Action Subsystem3'
 * '<S65>'  : 'JointModel/FOC/CurrentLoop/PID_I'
 * '<S66>'  : 'JointModel/FOC/CurrentLoop/Park'
 * '<S67>'  : 'JointModel/FOC/CurrentLoop/SVPWM'
 * '<S68>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1'
 * '<S69>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2'
 * '<S70>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup'
 * '<S71>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/D Gain'
 * '<S72>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/External Derivative'
 * '<S73>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter'
 * '<S74>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter ICs'
 * '<S75>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/I Gain'
 * '<S76>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain'
 * '<S77>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain Fdbk'
 * '<S78>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator'
 * '<S79>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator ICs'
 * '<S80>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Copy'
 * '<S81>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Gain'
 * '<S82>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/P Copy'
 * '<S83>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Parallel P Gain'
 * '<S84>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Reset Signal'
 * '<S85>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation'
 * '<S86>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation Fdbk'
 * '<S87>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum'
 * '<S88>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum Fdbk'
 * '<S89>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode'
 * '<S90>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode Sum'
 * '<S91>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Integral'
 * '<S92>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Ngain'
 * '<S93>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/postSat Signal'
 * '<S94>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/preSat Signal'
 * '<S95>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S96>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S97>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S98>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/D Gain/Disabled'
 * '<S99>'  : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/External Derivative/Disabled'
 * '<S100>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter/Disabled'
 * '<S101>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Filter ICs/Disabled'
 * '<S102>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/I Gain/External Parameters'
 * '<S103>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain/Passthrough'
 * '<S104>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S105>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator/Discrete'
 * '<S106>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Integrator ICs/Internal IC'
 * '<S107>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S108>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/N Gain/Disabled'
 * '<S109>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/P Copy/Disabled'
 * '<S110>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Parallel P Gain/External Parameters'
 * '<S111>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Reset Signal/Disabled'
 * '<S112>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation/Enabled'
 * '<S113>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Saturation Fdbk/Disabled'
 * '<S114>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum/Sum_PI'
 * '<S115>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Sum Fdbk/Disabled'
 * '<S116>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode/Disabled'
 * '<S117>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S118>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S119>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S120>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/postSat Signal/Forward_Path'
 * '<S121>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller1/preSat Signal/Forward_Path'
 * '<S122>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup'
 * '<S123>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/D Gain'
 * '<S124>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/External Derivative'
 * '<S125>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter'
 * '<S126>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter ICs'
 * '<S127>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/I Gain'
 * '<S128>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain'
 * '<S129>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain Fdbk'
 * '<S130>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator'
 * '<S131>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator ICs'
 * '<S132>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Copy'
 * '<S133>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Gain'
 * '<S134>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/P Copy'
 * '<S135>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Parallel P Gain'
 * '<S136>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Reset Signal'
 * '<S137>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation'
 * '<S138>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation Fdbk'
 * '<S139>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum'
 * '<S140>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum Fdbk'
 * '<S141>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode'
 * '<S142>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode Sum'
 * '<S143>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Integral'
 * '<S144>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Ngain'
 * '<S145>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/postSat Signal'
 * '<S146>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/preSat Signal'
 * '<S147>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S148>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S149>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S150>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/D Gain/Disabled'
 * '<S151>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/External Derivative/Disabled'
 * '<S152>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter/Disabled'
 * '<S153>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Filter ICs/Disabled'
 * '<S154>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/I Gain/External Parameters'
 * '<S155>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain/Passthrough'
 * '<S156>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S157>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator/Discrete'
 * '<S158>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Integrator ICs/Internal IC'
 * '<S159>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S160>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/N Gain/Disabled'
 * '<S161>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/P Copy/Disabled'
 * '<S162>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Parallel P Gain/External Parameters'
 * '<S163>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Reset Signal/Disabled'
 * '<S164>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation/Enabled'
 * '<S165>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Saturation Fdbk/Disabled'
 * '<S166>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum/Sum_PI'
 * '<S167>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Sum Fdbk/Disabled'
 * '<S168>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode/Disabled'
 * '<S169>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S170>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S171>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S172>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/postSat Signal/Forward_Path'
 * '<S173>' : 'JointModel/FOC/CurrentLoop/PID_I/PID Controller2/preSat Signal/Forward_Path'
 * '<S174>' : 'JointModel/FOC/CurrentLoop/SVPWM/Anti-Clark'
 * '<S175>' : 'JointModel/FOC/CurrentLoop/SVPWM/ei_t'
 * '<S176>' : 'JointModel/FOC/speedloop/PID Controller3'
 * '<S177>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup'
 * '<S178>' : 'JointModel/FOC/speedloop/PID Controller3/D Gain'
 * '<S179>' : 'JointModel/FOC/speedloop/PID Controller3/External Derivative'
 * '<S180>' : 'JointModel/FOC/speedloop/PID Controller3/Filter'
 * '<S181>' : 'JointModel/FOC/speedloop/PID Controller3/Filter ICs'
 * '<S182>' : 'JointModel/FOC/speedloop/PID Controller3/I Gain'
 * '<S183>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain'
 * '<S184>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain Fdbk'
 * '<S185>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator'
 * '<S186>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator ICs'
 * '<S187>' : 'JointModel/FOC/speedloop/PID Controller3/N Copy'
 * '<S188>' : 'JointModel/FOC/speedloop/PID Controller3/N Gain'
 * '<S189>' : 'JointModel/FOC/speedloop/PID Controller3/P Copy'
 * '<S190>' : 'JointModel/FOC/speedloop/PID Controller3/Parallel P Gain'
 * '<S191>' : 'JointModel/FOC/speedloop/PID Controller3/Reset Signal'
 * '<S192>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation'
 * '<S193>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation Fdbk'
 * '<S194>' : 'JointModel/FOC/speedloop/PID Controller3/Sum'
 * '<S195>' : 'JointModel/FOC/speedloop/PID Controller3/Sum Fdbk'
 * '<S196>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode'
 * '<S197>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode Sum'
 * '<S198>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Integral'
 * '<S199>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Ngain'
 * '<S200>' : 'JointModel/FOC/speedloop/PID Controller3/postSat Signal'
 * '<S201>' : 'JointModel/FOC/speedloop/PID Controller3/preSat Signal'
 * '<S202>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S203>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S204>' : 'JointModel/FOC/speedloop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S205>' : 'JointModel/FOC/speedloop/PID Controller3/D Gain/Disabled'
 * '<S206>' : 'JointModel/FOC/speedloop/PID Controller3/External Derivative/Disabled'
 * '<S207>' : 'JointModel/FOC/speedloop/PID Controller3/Filter/Disabled'
 * '<S208>' : 'JointModel/FOC/speedloop/PID Controller3/Filter ICs/Disabled'
 * '<S209>' : 'JointModel/FOC/speedloop/PID Controller3/I Gain/Internal Parameters'
 * '<S210>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S211>' : 'JointModel/FOC/speedloop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S212>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator/Discrete'
 * '<S213>' : 'JointModel/FOC/speedloop/PID Controller3/Integrator ICs/Internal IC'
 * '<S214>' : 'JointModel/FOC/speedloop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S215>' : 'JointModel/FOC/speedloop/PID Controller3/N Gain/Disabled'
 * '<S216>' : 'JointModel/FOC/speedloop/PID Controller3/P Copy/Disabled'
 * '<S217>' : 'JointModel/FOC/speedloop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S218>' : 'JointModel/FOC/speedloop/PID Controller3/Reset Signal/Disabled'
 * '<S219>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation/Enabled'
 * '<S220>' : 'JointModel/FOC/speedloop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S221>' : 'JointModel/FOC/speedloop/PID Controller3/Sum/Sum_PI'
 * '<S222>' : 'JointModel/FOC/speedloop/PID Controller3/Sum Fdbk/Disabled'
 * '<S223>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode/Disabled'
 * '<S224>' : 'JointModel/FOC/speedloop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S225>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S226>' : 'JointModel/FOC/speedloop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S227>' : 'JointModel/FOC/speedloop/PID Controller3/postSat Signal/Forward_Path'
 * '<S228>' : 'JointModel/FOC/speedloop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
