/*
 * File: FOC.c
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.227
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Dec 24 11:15:07 2025
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

/* Named constants for Chart: '<S2>/Chart' */
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
static void rate_scheduler(void);
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

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
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
  real32_T Integrator;
  real32_T rtb_Add_a;
  real32_T rtb_DeadZone;
  real32_T rtb_Gain_h;
  real32_T rtb_IntegralGain;
  real32_T rtb_Sum1_a;
  real32_T rtb_Sum1_n;
  real32_T rtb_Sum_m;
  real32_T rtb_TrigonometricFunction1;
  uint32_T speedloop_ELAPS_T;
  int16_T rtb_IProdOut;
  int8_T tmp;
  int8_T tmp_0;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/speedloop'
     */
    if (rtDW.speedloop_RESET_ELAPS_T) {
      speedloop_ELAPS_T = 0U;
    } else {
      speedloop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.speedloop_PREV_T;
    }

    rtDW.speedloop_PREV_T = rtM->Timing.clockTick1;
    rtDW.speedloop_RESET_ELAPS_T = false;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Inport: '<Root>/SpeedFd'
     *  Inport: '<Root>/SpeedRef'
     */
    rtb_IntegralGain = (real32_T)rtU.SpeedRef - rtU.SpeedFd;

    /* DiscreteIntegrator: '<S158>/Integrator' */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S158>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else {
      /* DiscreteIntegrator: '<S158>/Integrator' */
      Integrator = 0.001F * (real32_T)speedloop_ELAPS_T * rtDW.Integrator_PREV_U
        + rtDW.Integrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S158>/Integrator' */

    /* Sum: '<S167>/Sum' incorporates:
     *  Gain: '<S163>/Proportional Gain'
     */
    rtb_DeadZone = 0.3389F * rtb_IntegralGain + Integrator;

    /* Saturate: '<S165>/Saturation' incorporates:
     *  DeadZone: '<S150>/DeadZone'
     */
    if (rtb_DeadZone > 3.0F) {
      /* Saturate: '<S165>/Saturation' */
      rtDW.Saturation = 3.0F;
      rtb_DeadZone -= 3.0F;
    } else {
      if (rtb_DeadZone < -3.0F) {
        /* Saturate: '<S165>/Saturation' */
        rtDW.Saturation = -3.0F;
      } else {
        /* Saturate: '<S165>/Saturation' */
        rtDW.Saturation = rtb_DeadZone;
      }

      if (rtb_DeadZone >= -3.0F) {
        rtb_DeadZone = 0.0F;
      } else {
        rtb_DeadZone -= -3.0F;
      }
    }

    /* End of Saturate: '<S165>/Saturation' */

    /* Gain: '<S155>/Integral Gain' */
    rtb_IntegralGain *= 0.0144F;

    /* Update for DiscreteIntegrator: '<S158>/Integrator' */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE = Integrator;

    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Clamping_zero'
     *  Constant: '<S148>/Constant'
     *  Constant: '<S148>/Constant2'
     *  RelationalOperator: '<S148>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    /* Switch: '<S148>/Switch2' incorporates:
     *  Constant: '<S148>/Clamping_zero'
     *  Constant: '<S148>/Constant3'
     *  Constant: '<S148>/Constant4'
     *  RelationalOperator: '<S148>/fix for DT propagation issue1'
     */
    if (rtb_IntegralGain > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S148>/Switch' incorporates:
     *  Constant: '<S148>/Clamping_zero'
     *  Logic: '<S148>/AND3'
     *  RelationalOperator: '<S148>/Equal1'
     *  RelationalOperator: '<S148>/Relational Operator'
     *  Switch: '<S148>/Switch1'
     *  Switch: '<S148>/Switch2'
     */
    if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
      /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
       *  Constant: '<S148>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S158>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_IntegralGain;
    }

    /* End of Switch: '<S148>/Switch' */
    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */
  }

  /* Outputs for Atomic SubSystem: '<S1>/CurrentLoop' */
  /* Sum: '<S6>/Add2' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S6>/Add'
   */
  rtb_Add2 = 0.66666666666666663 * rtU.ia - (rtU.ib + rtU.ic) *
    0.33333333333333331;

  /* Chart: '<S2>/Chart' incorporates:
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

  /* End of Chart: '<S2>/Chart' */

  /* SwitchCase: '<S2>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/theta_fd'
     */
    rtDW.ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/theta_fd'
     */
    rtDW.ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 2.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant1'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
     *  Math: '<S9>/Mod'
     */
    rtDW.ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE,
      6.28318548F);

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S2>/Constant5'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F *
      rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE += 0.0153588969F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Inport: '<Root>/ Real_Theta'
     *  SignalConversion generated from: '<S10>/ Real_Theta'
     */
    rtDW.ThetaOpen = rtU.Real_Theta;

    /* Merge: '<S2>/Merge1' incorporates:
     *  SignalConversion generated from: '<S10>/iq_ref'
     */
    rtDW.Merge1 = rtDW.Saturation;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Trigonometry: '<S2>/Trigonometric Function1' */
  rtb_TrigonometricFunction1 = cosf(rtDW.ThetaOpen);

  /* Gain: '<S6>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S6>/Add1'
   */
  rtb_Gain2 = (rtU.ib - rtU.ic) * 0.57735026918962573;

  /* Trigonometry: '<S2>/Trigonometric Function' */
  rtb_IntegralGain = sinf(rtDW.ThetaOpen);

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Add'
   */
  rtb_Sum1_a = 0.0F - ((real32_T)(rtb_Add2 * rtb_TrigonometricFunction1) +
                       (real32_T)(rtb_Gain2 * rtb_IntegralGain));

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DiscreteIntegrator: '<S51>/Integrator'
   *  Product: '<S56>/PProd Out'
   */
  Integrator = rtb_Sum1_a * 0.26F + (real32_T)rtDW.Integrator_DSTATE_a * 0.0001F;

  /* Saturate: '<S58>/Saturation' */
  if (Integrator > 12.4707661F) {
    rtb_DeadZone = 12.4707661F;
  } else if (Integrator < -12.4707661F) {
    rtb_DeadZone = -12.4707661F;
  } else {
    rtb_DeadZone = Integrator;
  }

  /* End of Saturate: '<S58>/Saturation' */

  /* Sum: '<S11>/Sum7' incorporates:
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Add1'
   */
  rtb_Sum_m = rtDW.Merge1 - ((real32_T)(rtb_Gain2 * rtb_TrigonometricFunction1)
    - (real32_T)(rtb_Add2 * rtb_IntegralGain));

  /* Sum: '<S112>/Sum' incorporates:
   *  Constant: '<S11>/Constant1'
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  Product: '<S108>/PProd Out'
   */
  rtb_Sum1_n = rtb_Sum_m * 0.26F + rtDW.Integrator_DSTATE_g;

  /* Saturate: '<S110>/Saturation' */
  if (rtb_Sum1_n > 12.4707661F) {
    rtb_Gain_h = 12.4707661F;
  } else if (rtb_Sum1_n < -12.4707661F) {
    rtb_Gain_h = -12.4707661F;
  } else {
    rtb_Gain_h = rtb_Sum1_n;
  }

  /* End of Saturate: '<S110>/Saturation' */

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   */
  rtb_Add_a = rtb_DeadZone * rtb_TrigonometricFunction1 - rtb_Gain_h *
    rtb_IntegralGain;

  /* Product: '<S4>/Product3' */
  rtb_TrigonometricFunction1 *= rtb_Gain_h;

  /* DeadZone: '<S43>/DeadZone' */
  if (Integrator > 12.4707661F) {
    Integrator -= 12.4707661F;
  } else if (Integrator >= -12.4707661F) {
    Integrator = 0.0F;
  } else {
    Integrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S43>/DeadZone' */

  /* Product: '<S48>/IProd Out' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  rtb_IProdOut = (int16_T)floorf(rtb_Sum1_a * 35.0F);

  /* DeadZone: '<S95>/DeadZone' */
  if (rtb_Sum1_n > 12.4707661F) {
    rtb_Sum1_n -= 12.4707661F;
  } else if (rtb_Sum1_n >= -12.4707661F) {
    rtb_Sum1_n = 0.0F;
  } else {
    rtb_Sum1_n -= -12.4707661F;
  }

  /* End of DeadZone: '<S95>/DeadZone' */

  /* Product: '<S100>/IProd Out' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  rtb_Sum_m *= 35.0F;

  /* Switch: '<S93>/Switch1' incorporates:
   *  Constant: '<S93>/Clamping_zero'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S93>/Constant2'
   *  RelationalOperator: '<S93>/fix for DT propagation issue'
   */
  if (rtb_Sum1_n > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S93>/Clamping_zero'
   *  Constant: '<S93>/Constant3'
   *  Constant: '<S93>/Constant4'
   *  RelationalOperator: '<S93>/fix for DT propagation issue1'
   */
  if (rtb_Sum_m > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/Clamping_zero'
   *  Constant: '<S93>/Constant1'
   *  Logic: '<S93>/AND3'
   *  RelationalOperator: '<S93>/Equal1'
   *  RelationalOperator: '<S93>/Relational Operator'
   *  Switch: '<S93>/Switch1'
   *  Switch: '<S93>/Switch2'
   */
  if ((rtb_Sum1_n != 0.0F) && (tmp == tmp_0)) {
    rtb_Sum1_a = 0.0F;
  } else {
    rtb_Sum1_a = rtb_Sum_m;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Gain: '<S120>/Gain' */
  rtb_Gain_h = -0.5F * rtb_Add_a;

  /* Gain: '<S120>/Gain1' incorporates:
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Add1'
   */
  rtb_Sum1_n = (rtb_DeadZone * rtb_IntegralGain + rtb_TrigonometricFunction1) *
    0.866025388F;

  /* Sum: '<S120>/Sum' */
  rtb_Sum_m = rtb_Gain_h + rtb_Sum1_n;

  /* Sum: '<S120>/Sum1' */
  rtb_Sum1_n = rtb_Gain_h - rtb_Sum1_n;

  /* Gain: '<S121>/Gain' incorporates:
   *  MinMax: '<S121>/Min'
   *  MinMax: '<S121>/Min1'
   *  Sum: '<S121>/Sum'
   */
  rtb_Gain_h = (fminf(fminf(rtb_Add_a, rtb_Sum_m), rtb_Sum1_n) + fmaxf(fmaxf
    (rtb_Add_a, rtb_Sum_m), rtb_Sum1_n)) * -0.5F;

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant2'
   *  RelationalOperator: '<S41>/fix for DT propagation issue'
   */
  if (Integrator > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/Clamping_zero'
   *  Constant: '<S41>/Constant3'
   *  Constant: '<S41>/Constant4'
   *  RelationalOperator: '<S41>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Logic: '<S41>/AND3'
   *  RelationalOperator: '<S41>/Equal1'
   *  RelationalOperator: '<S41>/Relational Operator'
   *  Switch: '<S41>/Switch1'
   *  Switch: '<S41>/Switch2'
   */
  if ((Integrator != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0;
  }

  /* Update for DiscreteIntegrator: '<S51>/Integrator' incorporates:
   *  Switch: '<S41>/Switch'
   */
  rtDW.Integrator_DSTATE_a += rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' */
  rtDW.Integrator_DSTATE_g += 0.0001F * rtb_Sum1_a;

  /* Outport: '<Root>/tABC' incorporates:
   *  Constant: '<S13>/Constant'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/PWM_HalfPeriod'
   *  Inport: '<Root>/v_bus'
   *  Product: '<S13>/Divide'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum1'
   */
  rtY.tABC[0] = (-(rtb_Gain_h + rtb_Add_a) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[1] = (-(rtb_Gain_h + rtb_Sum_m) / rtU.v_bus + 0.5F) * 8000.0F;
  rtY.tABC[2] = (-(rtb_Gain_h + rtb_Sum1_n) / rtU.v_bus + 0.5F) * 8000.0F;

  /* End of Outputs for SubSystem: '<S1>/CurrentLoop' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/speedloop'
   */
  rtDW.speedloop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S158>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
