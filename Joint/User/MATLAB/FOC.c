/*
 * File: FOC.c
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

#include "FOC.h"
#include "mw_cmsis.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void FOC_step(void)
{
  real32_T rtb_Add;
  real32_T rtb_Min;
  real32_T rtb_Sum;
  real32_T rtb_Sum1_o;
  real32_T rtb_Sum_m;

  /* Outputs for Atomic SubSystem: '<Root>/FOC' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Sum = 0.000628318521F * rtU.Freq + rtDW.UnitDelay_DSTATE;

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   */
  if (rtb_Sum > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Sum -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  } else if (rtb_Sum < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum += 6.28318548F;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
  }

  /* End of If: '<S5>/If' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_Sum_m = arm_cos_f32(rtb_Sum);

  /* Trigonometry: '<S1>/SinCos' */
  rtb_Sum1_o = arm_sin_f32(rtb_Sum);

  /* Sum: '<S2>/Add' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_Add = rtU.ud * rtb_Sum_m - rtU.uq * rtb_Sum1_o;

  /* Gain: '<S9>/Gain' */
  rtb_Min = -0.5F * rtb_Add;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add1'
   */
  rtb_Sum1_o = (rtU.ud * rtb_Sum1_o + rtU.uq * rtb_Sum_m) * 0.866025388F;

  /* Sum: '<S9>/Sum' */
  rtb_Sum_m = rtb_Min + rtb_Sum1_o;

  /* Sum: '<S9>/Sum1' */
  rtb_Sum1_o = rtb_Min - rtb_Sum1_o;

  /* Gain: '<S10>/Gain' incorporates:
   *  MinMax: '<S10>/Min'
   *  MinMax: '<S10>/Min1'
   *  Sum: '<S10>/Sum'
   */
  rtb_Min = (fminf(fminf(rtb_Add, rtb_Sum_m), rtb_Sum1_o) + fmaxf(fmaxf(rtb_Add,
    rtb_Sum_m), rtb_Sum1_o)) * -0.5F;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum;

  /* Outport: '<Root>/tABC' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/PWM_HalfPeriod'
   *  Inport: '<Root>/v_bus'
   *  Product: '<S4>/Divide'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  rtY.tABC[0] = (-(rtb_Min + rtb_Add) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[1] = (-(rtb_Min + rtb_Sum_m) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[2] = (-(rtb_Min + rtb_Sum1_o) / rtU.v_bus + 0.5F) * 8000.0F;

  /* End of Outputs for SubSystem: '<Root>/FOC' */
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
