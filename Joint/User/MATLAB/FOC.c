/*
 * File: FOC.c
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

#include "FOC.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>
#include <float.h>

/* Named constants for Chart: '<S1>/Chart' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Add2;
  real_T rtb_Gain2;
  real32_T rtb_Add_a;
  real32_T rtb_DeadZone;
  real32_T rtb_Gain_h;
  real32_T rtb_Min1;
  real32_T rtb_Sum1_a;
  real32_T rtb_Sum1_n;
  real32_T rtb_Sum_m;
  real32_T rtb_TrigonometricFunction;
  real32_T rtb_TrigonometricFunction1;
  int16_T rtb_IProdOut;
  int8_T tmp;
  int8_T tmp_0;

  /* Outputs for Atomic SubSystem: '<Root>/FOC' */
  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add'
   */
  rtb_Add2 = 0.66666666666666663 * rtU.ia - (rtU.ib + rtU.ic) *
    0.33333333333333331;

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_FOC == 0U) {
    rtDW.is_active_c3_FOC = 1U;
    rtDW.is_c3_FOC = IN_IDLE;
  } else {
    switch (rtDW.is_c3_FOC) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000) {
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_c3_FOC = IN_OpenStage;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0F) {
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_c3_FOC = IN_AlignStage;
      } else {
        rtDW.Motor_state = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c3_FOC = IN_RunStage;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC = IN_IDLE;
      } else {
        rtDW.Motor_state = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC = IN_IDLE;
      } else {
        rtDW.Motor_state = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant'
     *  SignalConversion generated from: '<S5>/theta_fd'
     */
    rtDW.ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  SignalConversion generated from: '<S5>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/theta_fd'
     */
    rtDW.ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/iq_ref'
     */
    rtDW.Merge1 = 2.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S7>/Constant1'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
     *  Math: '<S7>/Mod'
     */
    rtDW.ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_k,
      6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant5'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTAT_k += 0.0001F *
      rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE += 0.0111701069F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S8>/Constant1'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
     *  Math: '<S8>/Mod'
     */
    rtDW.ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE,
      6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant8'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0335103199F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Trigonometry: '<S1>/Trigonometric Function1' */
  rtb_TrigonometricFunction1 = cosf(rtDW.ThetaOpen);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add1'
   */
  rtb_Gain2 = (rtU.ib - rtU.ic) * 0.57735026918962573;

  /* Trigonometry: '<S1>/Trigonometric Function' */
  rtb_TrigonometricFunction = sinf(rtDW.ThetaOpen);

  /* Sum: '<S9>/Sum1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Sum: '<S10>/Add'
   */
  rtb_Sum1_a = 0.0F - ((real32_T)(rtb_Add2 * rtb_TrigonometricFunction1) +
                       (real32_T)(rtb_Gain2 * rtb_TrigonometricFunction));

  /* Sum: '<S58>/Sum' incorporates:
   *  Constant: '<S9>/Constant3'
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Product: '<S54>/PProd Out'
   */
  rtb_DeadZone = rtb_Sum1_a * 35.0F + (real32_T)rtDW.Integrator_DSTATE_a *
    0.0001F;

  /* Saturate: '<S56>/Saturation' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_Min1 = 12.4707661F;
  } else if (rtb_DeadZone < -12.4707661F) {
    rtb_Min1 = -12.4707661F;
  } else {
    rtb_Min1 = rtb_DeadZone;
  }

  /* End of Saturate: '<S56>/Saturation' */

  /* Sum: '<S9>/Sum7' incorporates:
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Sum: '<S10>/Add1'
   */
  rtb_Sum_m = rtDW.Merge1 - ((real32_T)(rtb_Gain2 * rtb_TrigonometricFunction1)
    - (real32_T)(rtb_Add2 * rtb_TrigonometricFunction));

  /* Sum: '<S110>/Sum' incorporates:
   *  Constant: '<S9>/Constant1'
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Product: '<S106>/PProd Out'
   */
  rtb_Sum1_n = rtb_Sum_m * 35.0F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S108>/Saturation' */
  if (rtb_Sum1_n > 12.4707661F) {
    rtb_Gain_h = 12.4707661F;
  } else if (rtb_Sum1_n < -12.4707661F) {
    rtb_Gain_h = -12.4707661F;
  } else {
    rtb_Gain_h = rtb_Sum1_n;
  }

  /* End of Saturate: '<S108>/Saturation' */

  /* Sum: '<S2>/Add' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_Add_a = rtb_Min1 * rtb_TrigonometricFunction1 - rtb_Gain_h *
    rtb_TrigonometricFunction;

  /* Product: '<S2>/Product3' */
  rtb_TrigonometricFunction1 *= rtb_Gain_h;

  /* DeadZone: '<S41>/DeadZone' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_DeadZone -= 12.4707661F;
  } else if (rtb_DeadZone >= -12.4707661F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -12.4707661F;
  }

  /* End of DeadZone: '<S41>/DeadZone' */

  /* Product: '<S46>/IProd Out' incorporates:
   *  Constant: '<S9>/Constant4'
   */
  rtb_IProdOut = (int16_T)floorf(rtb_Sum1_a * 0.17F);

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_Sum1_n > 12.4707661F) {
    rtb_Sum1_n -= 12.4707661F;
  } else if (rtb_Sum1_n >= -12.4707661F) {
    rtb_Sum1_n = 0.0F;
  } else {
    rtb_Sum1_n -= -12.4707661F;
  }

  /* End of DeadZone: '<S93>/DeadZone' */

  /* Product: '<S98>/IProd Out' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  rtb_Sum_m *= 0.17F;

  /* Switch: '<S91>/Switch1' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S91>/Constant2'
   *  RelationalOperator: '<S91>/fix for DT propagation issue'
   */
  if (rtb_Sum1_n > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant3'
   *  Constant: '<S91>/Constant4'
   *  RelationalOperator: '<S91>/fix for DT propagation issue1'
   */
  if (rtb_Sum_m > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant1'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   *  RelationalOperator: '<S91>/Relational Operator'
   *  Switch: '<S91>/Switch1'
   *  Switch: '<S91>/Switch2'
   */
  if ((rtb_Sum1_n != 0.0F) && (tmp == tmp_0)) {
    rtb_Sum1_a = 0.0F;
  } else {
    rtb_Sum1_a = rtb_Sum_m;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Gain: '<S118>/Gain' */
  rtb_Gain_h = -0.5F * rtb_Add_a;

  /* Gain: '<S118>/Gain1' incorporates:
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Add1'
   */
  rtb_Sum1_n = (rtb_Min1 * rtb_TrigonometricFunction +
                rtb_TrigonometricFunction1) * 0.866025388F;

  /* Sum: '<S118>/Sum' */
  rtb_Sum_m = rtb_Gain_h + rtb_Sum1_n;

  /* Sum: '<S118>/Sum1' */
  rtb_Sum1_n = rtb_Gain_h - rtb_Sum1_n;

  /* Gain: '<S119>/Gain' incorporates:
   *  MinMax: '<S119>/Min'
   *  MinMax: '<S119>/Min1'
   *  Sum: '<S119>/Sum'
   */
  rtb_Gain_h = (fminf(fminf(rtb_Add_a, rtb_Sum_m), rtb_Sum1_n) + fmaxf(fmaxf
    (rtb_Add_a, rtb_Sum_m), rtb_Sum1_n)) * -0.5F;

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S39>/Constant2'
   *  RelationalOperator: '<S39>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S39>/Clamping_zero'
   *  Constant: '<S39>/Constant3'
   *  Constant: '<S39>/Constant4'
   *  RelationalOperator: '<S39>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Logic: '<S39>/AND3'
   *  RelationalOperator: '<S39>/Equal1'
   *  RelationalOperator: '<S39>/Relational Operator'
   *  Switch: '<S39>/Switch1'
   *  Switch: '<S39>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0;
  }

  /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
   *  Switch: '<S39>/Switch'
   */
  rtDW.Integrator_DSTATE_a += rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S101>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_Sum1_a;

  /* Outport: '<Root>/tABC' incorporates:
   *  Constant: '<S11>/Constant'
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/PWM_HalfPeriod'
   *  Inport: '<Root>/v_bus'
   *  Product: '<S11>/Divide'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  rtY.tABC[0] = (-(rtb_Gain_h + rtb_Add_a) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[1] = (-(rtb_Gain_h + rtb_Sum_m) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[2] = (-(rtb_Gain_h + rtb_Sum1_n) / rtU.v_bus + 0.5F) * 8000.0F;

  /* End of Outputs for SubSystem: '<Root>/FOC' */
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
