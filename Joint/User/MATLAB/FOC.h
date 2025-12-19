/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.191
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Dec 19 11:11:03 2025
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
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Freq;                       /* '<Root>/Freq' */
  real32_T ud;                         /* '<Root>/ud' */
  real32_T uq;                         /* '<Root>/uq' */
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
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion4' : Eliminate redundant data type conversion
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
 * '<S3>'   : 'JointModel/FOC/FreqGenerator'
 * '<S4>'   : 'JointModel/FOC/SVPWM'
 * '<S5>'   : 'JointModel/FOC/FreqGenerator/RangeLimit'
 * '<S6>'   : 'JointModel/FOC/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S7>'   : 'JointModel/FOC/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S8>'   : 'JointModel/FOC/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S9>'   : 'JointModel/FOC/SVPWM/Anti-Clark'
 * '<S10>'  : 'JointModel/FOC/SVPWM/ei_t'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
