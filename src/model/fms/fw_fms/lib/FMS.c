/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2032
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Jan 30 23:01:08 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S45>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S80>/Motion State' */
#define FMS_IN_Brake_d                 ((uint8_T)1U)
#define FMS_IN_Hold_l                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)3U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)4U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)5U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_SetSpeed                ((uint8_T)6U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)7U)
#define FMS_IN_Waypoint                ((uint8_T)8U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Manual_e                ((uint8_T)3U)
#define FMS_IN_Mission_g               ((uint8_T)4U)
#define FMS_IN_Other                   ((uint8_T)5U)
#define FMS_IN_Position_f              ((uint8_T)6U)
#define FMS_IN_Stabilize_j             ((uint8_T)7U)

const FMS_Out_Bus FMS_rtZFMS_Out_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* p_cmd */
  0.0F,                                /* q_cmd */
  0.0F,                                /* r_cmd */
  0.0F,                                /* phi_cmd */
  0.0F,                                /* theta_cmd */
  0.0F,                                /* psi_rate_cmd */
  0.0F,                                /* u_cmd */
  0.0F,                                /* v_cmd */
  0.0F,                                /* w_cmd */
  0.0F,                                /* ax_cmd */
  0.0F,                                /* ay_cmd */
  0.0F,                                /* az_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* throttle_cmd */
  0U,                                  /* cmd_mask */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U,                                  /* wp_consume */
  0U,                                  /* wp_current */
  0U,                                  /* reserved */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  /* home */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_lsSw80pJwzMfDv47oR1SCF FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F,
  30.0F,
  13.0F,
  10.0F,
  55.0F,
  50.0F,
  1.0F,
  1.0F,
  1.0F,
  0.95F,
  8.0F,
  0.785398185F,
  0.785398185F,
  30.0F,
  120U,
  1U
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S2>/Constant1'
                                        *   '<S20>/Constant'
                                        *   '<S221>/Constant'
                                        *   '<S148>/Gain'
                                        *   '<S148>/Gain4'
                                        *   '<S148>/Gain5'
                                        *   '<S153>/Constant4'
                                        *   '<S40>/Gain'
                                        *   '<S42>/Gain'
                                        *   '<S43>/Gain1'
                                        *   '<S61>/Gain'
                                        *   '<S63>/Gain1'
                                        *   '<S107>/Gain'
                                        *   '<S107>/Gain1'
                                        *   '<S108>/Gain1'
                                        *   '<S155>/Gain2'
                                        *   '<S155>/Saturation1'
                                        *   '<S156>/L1'
                                        *   '<S156>/R'
                                        *   '<S173>/Gain'
                                        *   '<S173>/Saturation1'
                                        *   '<S174>/vel'
                                        *   '<S197>/Gain'
                                        *   '<S197>/Saturation1'
                                        *   '<S44>/Saturation1'
                                        *   '<S55>/Dead Zone'
                                        *   '<S55>/Gain'
                                        *   '<S58>/Dead Zone'
                                        *   '<S58>/Gain'
                                        *   '<S65>/Saturation1'
                                        *   '<S76>/Dead Zone'
                                        *   '<S76>/Gain'
                                        *   '<S79>/Saturation1'
                                        *   '<S110>/Dead Zone'
                                        *   '<S110>/Gain'
                                        *   '<S111>/Dead Zone'
                                        *   '<S111>/Gain'
                                        *   '<S116>/Dead Zone'
                                        *   '<S116>/Gain'
                                        *   '<S124>/Gain'
                                        *   '<S124>/Saturation1'
                                        *   '<S125>/vel'
                                        *   '<S180>/L1'
                                        *   '<S180>/Saturation1'
                                        *   '<S202>/L1'
                                        *   '<S202>/Saturation1'
                                        *   '<S47>/Gain2'
                                        *   '<S48>/Gain1'
                                        *   '<S53>/Constant'
                                        *   '<S68>/Gain2'
                                        *   '<S69>/Gain1'
                                        *   '<S74>/Constant'
                                        *   '<S82>/L1'
                                        *   '<S83>/Gain6'
                                        *   '<S103>/Constant'
                                        *   '<S131>/L1'
                                        *   '<S131>/Saturation1'
                                        *   '<S50>/Dead Zone'
                                        *   '<S50>/Gain'
                                        *   '<S71>/Dead Zone'
                                        *   '<S71>/Gain'
                                        *   '<S100>/Dead Zone'
                                        *   '<S100>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 70, 87, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S219>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_FMS_T FMS_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FMS_T FMS_Y;

/* Real-time model */
RT_MODEL_FMS_T FMS_M_;
RT_MODEL_FMS_T *const FMS_M = &FMS_M_;

/* Forward declaration for local functions */
static void FMS_Stabilize(void);
static void FMS_Acro(void);
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_Mission(void);
static void FMS_exit_internal_Auto(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Assist(void);
static void FMS_enter_internal_Auto(void);
static void FMS_enter_internal_Arm(void);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for atomic system:
 *    '<S204>/NearbyRefWP'
 *    '<S182>/NearbyRefWP'
 *    '<S133>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_i, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S208>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_i;
  P3P2_idx_0 = sqrtf(P3P2_idx_0 * P3P2_idx_0 + P3P2_idx_1 * P3P2_idx_1);
  if (P3P2_idx_0 <= rtu_L1) {
    *rty_d = P3P2_idx_0;
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    *rty_d = -1.0F;
    rty_P[0] = 0.0F;
    rty_P[1] = 0.0F;
  }
}

/*
 * Output and update for atomic system:
 *    '<S204>/OutRegionRegWP'
 *    '<S182>/OutRegionRegWP'
 *    '<S133>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_l, real32_T rty_P[2])
{
  real32_T u;
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S209>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_l - rtu_P1[1];
  u_tmp = rty_P[0] * rty_P[0] + rty_P[1] * rty_P[1];
  u = (P1P3_idx_0 * rty_P[0] + P1P3_idx_1 * rty_P[1]) / u_tmp;
  if (u <= 0.0F) {
    rty_P[0] = rtu_P1[0];
    rty_P[1] = rtu_P1[1];
  } else if (u >= 1.0F) {
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    /* SignalConversion: '<S209>/TmpSignal ConversionAt SFunction Inport3' */
    P1P3_idx_0 = (u * rty_P[0] + rtu_P1[0]) - rtu_P3;
    P1P3_idx_1 = (u * rty_P[1] + rtu_P1[1]) - rtu_P3_l;
    u += sqrtf(P1P3_idx_0 * P1P3_idx_0 + P1P3_idx_1 * P1P3_idx_1) * 0.5774F /
      sqrtf(u_tmp);
    if (u > 1.0F) {
      u = 1.0F;
    }

    rty_P[0] = u * rty_P[0] + rtu_P1[0];
    rty_P[1] = u * rty_P[1] + rtu_P1[1];
  }
}

/*
 * Output and update for atomic system:
 *    '<S204>/SearchL1RefWP'
 *    '<S182>/SearchL1RefWP'
 *    '<S133>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2],
  real32_T *rty_u)
{
  real32_T A;
  real32_T B;
  real32_T D;
  real32_T a;
  real32_T u1_tmp;
  boolean_T guard1 = false;
  a = rtu_P2[0] - rtu_P1[0];
  A = rtu_P2[1] - rtu_P1[1];
  A = a * a + A * A;

  /* SignalConversion: '<S210>/TmpSignal ConversionAt SFunction Inport3' */
  B = ((rtu_P2[0] - rtu_P1[0]) * (rtu_P1[0] - rtu_P3) + (rtu_P2[1] - rtu_P1[1]) *
       (rtu_P1[1] - rtu_P3_f)) * 2.0F;
  D = B * B - (((((rtu_P3 * rtu_P3 + rtu_P3_f * rtu_P3_f) + rtu_P1[0] * rtu_P1[0])
                 + rtu_P1[1] * rtu_P1[1]) - (rtu_P3 * rtu_P1[0] + rtu_P3_f *
    rtu_P1[1]) * 2.0F) - rtu_L1 * rtu_L1) * (4.0F * A);
  a = -1.0F;
  rty_P[0] = 0.0F;
  rty_P[1] = 0.0F;
  guard1 = false;
  if (D > 0.0F) {
    u1_tmp = sqrtf(D);
    D = (-B + u1_tmp) / (2.0F * A);
    A = (-B - u1_tmp) / (2.0F * A);
    if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
      a = fmaxf(D, A);
      guard1 = true;
    } else if ((D >= 0.0F) && (D <= 1.0F)) {
      a = D;
      guard1 = true;
    } else {
      if ((A >= 0.0F) && (A <= 1.0F)) {
        a = A;
        guard1 = true;
      }
    }
  } else {
    if (D == 0.0F) {
      D = -B / (2.0F * A);
      if ((D >= 0.0F) && (D <= 1.0F)) {
        a = D;
        guard1 = true;
      }
    }
  }

  if (guard1) {
    rty_P[0] = (rtu_P2[0] - rtu_P1[0]) * a + rtu_P1[0];
    rty_P[1] = (rtu_P2[1] - rtu_P1[1]) * a + rtu_P1[1];
  }

  *rty_u = a;
}

/*
 * Output and update for action system:
 *    '<S31>/Unknown'
 *    '<S29>/Unknown'
 *    '<S28>/Unknown'
 *    '<S24>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S154>/Bus Assignment' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S154>/Constant2'
   *  SignalConversion: '<S154>/TmpHiddenBufferAtBus AssignmentInport1'
   */
  *rty_FMS_Out = FMS_rtZFMS_Out_Bus;
  rty_FMS_Out->reset = 1U;
  rty_FMS_Out->status = localC->DataTypeConversion;
  rty_FMS_Out->state = localC->DataTypeConversion1;
  rty_FMS_Out->actuator_cmd[0] = 1000U;
  rty_FMS_Out->actuator_cmd[1] = 1000U;
  rty_FMS_Out->actuator_cmd[2] = 1000U;
  rty_FMS_Out->actuator_cmd[3] = 1000U;
  for (i = 0; i < 12; i++) {
    rty_FMS_Out->actuator_cmd[i + 4] = 0U;
  }

  /* End of BusAssignment: '<S154>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S44>/Hold Control'
 *    '<S65>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S47>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S44>/Hold Control'
 *    '<S65>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S47>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S44>/Hold Control'
 *    '<S65>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S47>/Delay' incorporates:
   *  Gain: '<S49>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S47>/Gain2' incorporates:
   *  Delay: '<S47>/Delay'
   *  Gain: '<S49>/Gain'
   *  Sum: '<S47>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S47>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S44>/Brake Control'
 *    '<S65>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S46>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S46>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S44>/Move Control'
 *    '<S65>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S50>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S50>/Dead Zone' */

  /* Gain: '<S48>/Gain1' incorporates:
   *  Gain: '<S50>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtu_FMS_In_0 *
    FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S45>/Motion Status'
 *    '<S66>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S45>/Motion Status'
 *    '<S66>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S45>/Motion Status'
 *    '<S66>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S45>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c17_FMS == 0U) {
    localDW->is_active_c17_FMS = 1U;
    localDW->is_c17_FMS = FMS_IN_Move;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c17_FMS) {
     case FMS_IN_Brake:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c17_FMS = FMS_IN_Hold;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c17_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S45>/Motion Status' */
}

real_T rt_modd(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u0 == 0.0) {
    y = 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Output and update for function-call system: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const real_T
  rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3], const
  ConstB_VehicleArmAutoMissionL_T *localC)
{
  real_T rtb_Sum2_m;
  real_T rtb_Gain_lq;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_d_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S223>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S224>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S224>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S224>/Multiply1' incorporates:
   *  Product: '<S224>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S224>/Divide' incorporates:
   *  Constant: '<S224>/Constant'
   *  Constant: '<S224>/R'
   *  Sqrt: '<S224>/Sqrt'
   *  Sum: '<S224>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S224>/Product3' incorporates:
   *  Constant: '<S224>/Constant1'
   *  Product: '<S224>/Multiply1'
   *  Sum: '<S224>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S224>/Multiply2' incorporates:
   *  Trigonometry: '<S224>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S223>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S228>/Abs' incorporates:
   *  Abs: '<S231>/Abs1'
   *  Switch: '<S228>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S228>/Switch1' incorporates:
   *  Abs: '<S228>/Abs'
   *  Bias: '<S228>/Bias2'
   *  Bias: '<S228>/Bias3'
   *  Constant: '<S225>/Constant'
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S230>/Constant'
   *  Gain: '<S228>/Gain1'
   *  Product: '<S228>/Multiply'
   *  RelationalOperator: '<S230>/Compare'
   *  Switch: '<S225>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S231>/Switch1' incorporates:
     *  Bias: '<S231>/Bias2'
     *  Bias: '<S231>/Bias3'
     *  Constant: '<S231>/Constant'
     *  Constant: '<S232>/Constant'
     *  Math: '<S231>/Math Function'
     *  RelationalOperator: '<S232>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S231>/Switch1' */

    /* Signum: '<S228>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S228>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S225>/Sum' incorporates:
   *  Sum: '<S223>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S223>/Multiply' incorporates:
   *  Gain: '<S223>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S227>/Switch1' incorporates:
   *  Abs: '<S227>/Abs1'
   *  Bias: '<S227>/Bias2'
   *  Bias: '<S227>/Bias3'
   *  Constant: '<S227>/Constant'
   *  Constant: '<S229>/Constant'
   *  Math: '<S227>/Math Function'
   *  RelationalOperator: '<S229>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S227>/Switch1' */

  /* Product: '<S223>/Multiply' incorporates:
   *  Gain: '<S223>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S223>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S226>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S226>/Sum2' incorporates:
   *  Product: '<S226>/Multiply1'
   *  Product: '<S226>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S226>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S226>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S226>/Sum3' */
  rtb_Sum3 = rtb_Gain_lq - rtb_Sum3;

  /* DataTypeConversion: '<S220>/Data Type Conversion' incorporates:
   *  Gain: '<S223>/Gain'
   *  Sum: '<S223>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_m;
  rty_pos[1] = (real32_T)rtb_Sum3;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Stabilize;

    /* Delay: '<S8>/Delay' */
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S8>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Acro;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Acro(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Acro;

    /* Delay: '<S8>/Delay' */
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S8>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn)
{
  int32_T isEmplaced;
  int32_T newTail;
  Msg_FMS_Cmd *msg;
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead == newTail) {
    isEmplaced = 0;
  } else {
    q->fTail = newTail;
    msg = &q->fArray[newTail];
    msg->fData = *dataIn;
    if (q->fHead == -1) {
      q->fHead = q->fTail;
    }

    isEmplaced = 1;
  }

  return isEmplaced;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_send_M(void)
{
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  if (!(mode_in == PilotMode_None)) {
    switch (cmd_in) {
     case FMS_Cmd_Pause:
     case FMS_Cmd_Return:
      if (((ins_flag & 1U) != 0U) && ((ins_flag & 4U) != 0U) && ((ins_flag & 8U)
           != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) &&
          ((ins_flag & 128U) != 0U)) {
        valid = true;
      }
      break;

     case FMS_Cmd_PreArm:
      if (mode_in == PilotMode_Manual) {
        valid = true;
      } else if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) ||
                 ((ins_flag & 8U) == 0U)) {
      } else {
        switch (mode_in) {
         case PilotMode_Position:
         case PilotMode_Mission:
          if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag
                & 128U) != 0U)) {
            valid = true;
          }
          break;

         case PilotMode_Altitude:
          if ((ins_flag & 128U) != 0U) {
            valid = true;
          }
          break;

         case PilotMode_Stabilize:
          valid = true;
          break;
        }
      }
      break;

     case FMS_Cmd_Continue:
      if ((mode_in == PilotMode_Offboard) || (mode_in == PilotMode_Mission)) {
        valid = true;
      }
      break;

     case FMS_Cmd_Disarm:
      valid = true;
      break;
    }
  }

  return valid;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw > 0.8);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw < -0.8);
}

int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut)
{
  int32_T isPop;
  if (q->fHead == -1) {
    isPop = 0;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = 1;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  return isPop;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_sf_msg_pop_M(void)
{
  boolean_T isPresent;
  if (FMS_DW.M_isValid) {
    isPresent = true;
  } else {
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.Msg_FMS_Cmd_c
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_c[0] : NULL;
    if (FMS_DW.M_msgHandle != NULL) {
      FMS_DW.M_msgDataPtr = &((Msg_FMS_Cmd *)FMS_DW.M_msgHandle)->fData;
      isPresent = true;
      FMS_DW.M_msgReservedData = *(FMS_Cmd *)FMS_DW.M_msgDataPtr;
      FMS_DW.M_isValid = true;
    } else {
      isPresent = false;
      FMS_DW.M_isValid = false;
    }
  }

  return isPresent;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real32_T FMS_norm(const real32_T x[2])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrtf(y);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Mission(void)
{
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_DW.is_Mission = FMS_IN_NextWP;

    /* Inport: '<Root>/Mission_Data' */
    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
    } else {
      FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
      qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
      if (qY > FMS_B.wp_index) {
        qY = 0U;
      }

      FMS_B.wp_consume = (uint8_T)qY;
    }
  } else {
    switch (FMS_DW.is_Mission) {
     case FMS_IN_Disarming:
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Vehicle = FMS_IN_Disarm;
      FMS_B.state = VehicleState_Disarm;
      break;

     case FMS_IN_Hold_l:
      /* Inport: '<Root>/Mission_Data' */
      if (FMS_DW.temporalCounter_i1 >= FMS_U.Mission_Data.param1[FMS_B.wp_index
          - 1] * 250.0F) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_Loiter:
      break;

     case FMS_IN_NextWP:
      if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Takeoff) {
        FMS_DW.is_Mission = FMS_IN_Takeoff_d;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                         FMS_DW.home_p[2]);
        FMS_B.llo[0] = FMS_DW.llo[0];
        FMS_B.llo[1] = FMS_DW.llo[1];
        FMS_B.href = 0.0;
        FMS_B.psio = 0.0;

        /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
        FMS_B.state = VehicleState_Takeoff;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
        FMS_DW.is_Mission = FMS_IN_Waypoint;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                         FMS_DW.home_p[2]);
        FMS_B.llo[0] = FMS_DW.llo[0];
        FMS_B.llo[1] = FMS_DW.llo[1];
        FMS_B.href = 0.0;
        FMS_B.psio = 0.0;

        /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
        FMS_B.state = VehicleState_Mission;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_SetSpeed) {
        FMS_DW.is_Mission = FMS_IN_SetSpeed;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.Cmd_In.set_speed = FMS_U.Mission_Data.param2[FMS_B.wp_index - 1];
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
        FMS_DW.is_Mission = FMS_IN_Return_h;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home_p[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home_p[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state = VehicleState_Return;
      } else {
        FMS_DW.is_Mission = FMS_IN_Loiter;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
        FMS_B.state = VehicleState_Hold;
      }
      break;

     case FMS_IN_Return_h:
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home_p[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home_p[1];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_SetSpeed:
      tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)tmp_0 > 255U) {
        tmp_0 = 255;
      }

      FMS_B.wp_index = (uint8_T)tmp_0;
      FMS_DW.is_Mission = FMS_IN_NextWP;

      /* Inport: '<Root>/Mission_Data' */
      if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
        FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
      } else {
        FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
        qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
        if (qY > FMS_B.wp_index) {
          qY = 0U;
        }

        FMS_B.wp_consume = (uint8_T)qY;
      }
      break;

     case FMS_IN_Takeoff_d:
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_Waypoint:
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
        FMS_B.Cmd_In.set_speed = 0.0F;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] > 0.0F) {
          FMS_DW.is_Mission = FMS_IN_Hold_l;
          FMS_DW.temporalCounter_i1 = 0U;
          FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
          FMS_B.state = VehicleState_Hold;
        } else {
          tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_0;
          FMS_DW.is_Mission = FMS_IN_NextWP;
          if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
            FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
          } else {
            FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
            qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
            if (qY > FMS_B.wp_index) {
              qY = 0U;
            }

            FMS_B.wp_consume = (uint8_T)qY;
          }
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Auto(void)
{
  if (FMS_DW.is_Auto == FMS_IN_Mission) {
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_getArmMode(PilotMode pilotMode)
{
  real_T armMode;
  switch (pilotMode) {
   case PilotMode_Manual:
    armMode = 1.0;
    break;

   case PilotMode_Acro:
    armMode = 2.0;
    break;

   case PilotMode_Stabilize:
    armMode = 2.0;
    break;

   case PilotMode_Altitude:
    armMode = 2.0;
    break;

   case PilotMode_Position:
    armMode = 2.0;
    break;

   case PilotMode_Mission:
    armMode = 3.0;
    break;

   case PilotMode_Offboard:
    armMode = 3.0;
    break;

   default:
    armMode = 0.0;
    break;
  }

  return armMode;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Assist(void)
{
  switch (FMS_B.target_mode) {
   case PilotMode_Acro:
    FMS_DW.is_Assist = FMS_IN_Acro;
    FMS_B.state = VehicleState_Acro;
    break;

   case PilotMode_Stabilize:
    FMS_DW.is_Assist = FMS_IN_Stabilize;
    FMS_B.state = VehicleState_Stabilize;
    break;

   case PilotMode_Altitude:
    FMS_DW.is_Assist = FMS_IN_Altitude;
    FMS_B.state = VehicleState_Altitude;
    break;

   case PilotMode_Position:
    FMS_DW.is_Assist = FMS_IN_Position;
    FMS_B.state = VehicleState_Position;
    break;

   default:
    FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Auto(void)
{
  uint32_T qY;
  switch (FMS_B.target_mode) {
   case PilotMode_Offboard:
    FMS_DW.is_Auto = FMS_IN_Offboard;
    FMS_B.state = VehicleState_Offboard;
    break;

   case PilotMode_Mission:
    FMS_DW.is_Auto = FMS_IN_Mission;
    FMS_DW.llo[0] = FMS_B.BusConversion_InsertedFor_FMSSt.lat_0 *
      57.295779513082323;
    FMS_DW.llo[1] = FMS_B.BusConversion_InsertedFor_FMSSt.lon_0 *
      57.295779513082323;
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_B.Cmd_In.set_speed = 0.0F;
    FMS_DW.is_Mission = FMS_IN_NextWP;

    /* Inport: '<Root>/Mission_Data' */
    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
    } else {
      FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
      qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
      if (qY > FMS_B.wp_index) {
        qY = 0U;
      }

      FMS_B.wp_consume = (uint8_T)qY;
    }

    /* End of Inport: '<Root>/Mission_Data' */
    break;

   default:
    FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Arm(void)
{
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.target_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
    FMS_enter_internal_Auto();
  } else if (tmp == 2.0) {
    FMS_DW.is_Arm = FMS_IN_Assist;
    FMS_enter_internal_Assist();
  } else if (tmp == 1.0) {
    FMS_DW.is_Arm = FMS_IN_Manual;
    if (FMS_B.target_mode == PilotMode_Manual) {
      FMS_DW.is_Manual = FMS_IN_Manual_g;
      FMS_B.state = VehicleState_Manual;
    } else {
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    }
  } else {
    FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_SubMode(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real32_T tmp[2];
  real_T tmp_0;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S233>/Compare' incorporates:
   *  Abs: '<S222>/Abs'
   *  Constant: '<S233>/Constant'
   *  MinMax: '<S222>/Max'
   *  Sum: '<S222>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
  if (FMS_B.Compare_k && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.is_SubMode = FMS_IN_Hold_h;
      FMS_B.state = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold_h:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = ((FMS_DW.M_msgReservedData ==
            FMS_Cmd_Continue) && (FMS_B.target_mode != PilotMode_None));
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Return:
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home_p[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home_p[1];

        /* Constant: '<Root>/ACCEPT_R' */
        if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
          FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
          FMS_DW.is_SubMode = FMS_IN_Hold_h;
          FMS_B.state = VehicleState_Hold;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp_0 = FMS_getArmMode(FMS_B.target_mode);
            if (tmp_0 == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (tmp_0 == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Assist;
              FMS_enter_internal_Assist();
            } else if (tmp_0 == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_g;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
          }
        }
        break;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Arm(void)
{
  if (FMS_DW.is_Arm == FMS_IN_Auto) {
    FMS_exit_internal_Auto();
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real_T tmp;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_c >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    tmp = FMS_getArmMode(FMS_B.target_mode);
    if (tmp == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (tmp == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Land);
    } else {
      c_sf_internal_predicateOutput = false;
    }

    if (c_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
    } else {
      if (FMS_sf_msg_pop_M()) {
        c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Return);
      } else {
        c_sf_internal_predicateOutput = false;
      }

      if (c_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home_p[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home_p[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_SubMode;
        FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
        FMS_DW.stick_val[1] =
          FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
        FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
        FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
        FMS_DW.is_SubMode = FMS_IN_Return;
        FMS_B.state = VehicleState_Return;
      } else {
        switch (FMS_DW.is_Arm) {
         case FMS_IN_Assist:
          if (FMS_B.Compare && ((int32_T)
                                (FMS_B.BusConversion_InsertedFor_FMSSt.flag &
                                 212U) == 212)) {
            FMS_B.Cmd_In.cur_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.cur_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.cur_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Vehicle = FMS_IN_Arm;
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
          } else {
            if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
              FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
            }
          }
          break;

         case FMS_IN_Auto:
          if (FMS_sf_msg_pop_M()) {
            c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            c_sf_internal_predicateOutput = false;
          }

          if (c_sf_internal_predicateOutput) {
            FMS_B.Cmd_In.cur_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.cur_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.cur_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_exit_internal_Auto();
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
          } else {
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
              break;

             case FMS_IN_Mission:
              FMS_Mission();
              break;

             case FMS_IN_Offboard:
              break;
            }
          }
          break;

         case FMS_IN_InvalidArmMode:
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
          }
          break;

         case FMS_IN_SubMode:
          FMS_SubMode();
          break;
        }
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode)
{
  real_T trigger;
  trigger = 0.0;
  switch (pilot_cmd_mode) {
   case PilotMode_Manual:
   case PilotMode_Acro:
   case PilotMode_Stabilize:
    if (pilot_cmd_stick_throttle > -0.7) {
      trigger = 1.0;
    }
    break;

   case PilotMode_Altitude:
   case PilotMode_Position:
    if (pilot_cmd_stick_throttle > 0.1) {
      trigger = 1.0;
    }
    break;
  }

  return trigger;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Vehicle(void)
{
  boolean_T sf_internal_predicateOutput;
  int32_T b_previousEvent;
  int32_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_B.wp_consume = 0U;
    FMS_B.wp_index = 1U;
  }

  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Disarm);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_exit_internal_Arm();
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
      break;
    }

    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_Arm();
      break;

     case FMS_IN_Disarm:
      if (FMS_sf_msg_pop_M()) {
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_PreArm);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        guard1 = true;
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Takeoff);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_DW.prep_takeoff = 1.0;
          sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
            FMS_DW.durationLastReferenceTick_1_k =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
          guard1 = true;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard2 = true;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_k >= 500) {
          guard3 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Takeoff);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            guard3 = true;
          } else if ((FMS_DW.temporalCounter_i1 >= 2500U) || (FMS_DW.sfEvent ==
                      FMS_event_DisarmEvent)) {
            FMS_DW.prep_takeoff = 0.0;
            sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
              FMS_DW.durationLastReferenceTick_1_k =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
            FMS_DW.prep_mission_takeoff = 0.0;
            sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
          } else {
            sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
            if (FMS_DW.chartAbsoluteTimeCounter -
                FMS_DW.durationLastReferenceTick_2 >= 500) {
              guard2 = true;
            }
          }
        }
      }
      break;
    }

    if (guard3) {
      FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

      /* Outputs for Function Call SubSystem: '<S4>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S221>/Reshape' incorporates:
       *  Constant: '<S221>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S4>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_waypoint[2] += FMS_DW.home_p[2];
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Takeoff;
      FMS_B.state = VehicleState_Takeoff;
    }

    if (guard2) {
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          guard6 = true;
        } else {
          b_previousEvent = (int32_T)(FMS_B.wp_index + 1U);
          tmp = b_previousEvent;
          if ((uint32_T)b_previousEvent > 255U) {
            tmp = 255;
          }

          if ((tmp <= FMS_U.Mission_Data.valid_items) &&
              (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
               NAV_Cmd_SetSpeed)) {
            if ((uint32_T)b_previousEvent > 255U) {
              b_previousEvent = 255;
            }

            if (FMS_U.Mission_Data.command[b_previousEvent - 1] == (int32_T)
                NAV_Cmd_Takeoff) {
              guard6 = true;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }
        }
      } else {
        guard4 = true;
      }

      if (guard6) {
        FMS_DW.prep_mission_takeoff = 1.0;
        FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff == 1.0);
        FMS_DW.prep_takeoff = 0.0;
        FMS_DW.condWasTrueAtLastTimeStep_1_k = (FMS_DW.prep_takeoff == 1.0);
        guard4 = true;
      }

      if (guard5) {
        b_previousEvent = FMS_DW.sfEvent;
        FMS_DW.sfEvent = FMS_event_DisarmEvent;

        /* Chart: '<Root>/FMS State Machine' */
        FMS_c11_FMS();
        FMS_DW.sfEvent = b_previousEvent;
        if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
        } else {
          guard4 = true;
        }
      }

      if (guard4) {
        FMS_DW.home_p[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_DW.home_p[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_DW.home_p[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_DW.home_p[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
        FMS_B.state = VehicleState_Standby;
      }

      if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
        sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_c11_FMS(void)
{
  int32_T b_previousEvent;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.mission_timestamp_prev = FMS_U.Mission_Data.timestamp;
    FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
    FMS_DW.cmd_prev = FMS_B.Switch1;
    FMS_DW.cmd_start = FMS_B.Switch1;
    FMS_DW.mode_prev = FMS_B.target_mode;
    FMS_DW.mode_start = FMS_B.target_mode;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
    FMS_DW.is_active_Vehicle = 1U;
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_DW.save_cmd;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch1 !=
             FMS_Cmd_None)) {
          FMS_DW.save_cmd = FMS_B.Switch1;
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_DW.save_cmd,
            FMS_B.target_mode, FMS_B.BusConversion_InsertedFor_FMSSt.flag);
        }
        break;

       case FMS_IN_Send:
        FMS_DW.is_Command_Listener = FMS_IN_Listen;
        break;
      }
    }

    if (FMS_DW.is_active_Combo_Stick != 0U) {
      switch (FMS_DW.is_Combo_Stick) {
       case FMS_IN_Arm:
        if (!FMS_BottomRight(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_n > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
            FMS_DW.durationLastReferenceTick_2_a =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_a > 375) {
            FMS_DW.is_Combo_Stick = FMS_IN_Disarm;
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;
            if (FMS_DW.is_active_Vehicle != 0U) {
              FMS_Vehicle();
            }

            FMS_DW.sfEvent = b_previousEvent;
          } else {
            FMS_DW.bl = FMS_BottomLeft
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
              FMS_DW.durationLastReferenceTick_2_a =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
              FMS_DW.durationLastReferenceTick_1_n =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          }
        }
        break;
      }
    }

    if (FMS_DW.is_active_Vehicle != 0U) {
      FMS_Vehicle();
    }

    if (FMS_DW.is_active_Lost_Return != 0U) {
      switch (FMS_DW.is_Lost_Return) {
       case FMS_IN_Connect:
        if (FMS_B.LogicalOperator2) {
          FMS_DW.is_Lost_Return = FMS_IN_Lost;
          if ((FMS_B.BusConversion_InsertedFor_FMSSt.flag & 221U) != 0U) {
            FMS_DW.M_msgReservedData = FMS_Cmd_Return;
            FMS_sf_msg_send_M();
          }
        }
        break;

       case FMS_IN_Lost:
        if (!FMS_B.LogicalOperator2) {
          FMS_DW.is_Lost_Return = FMS_IN_Connect;
        }
        break;
      }
    }
  }

  /* End of Chart: '<Root>/FMS State Machine' */
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_discard_M(void)
{
  if (FMS_DW.M_isValid) {
    FMS_DW.M_isValid = false;
  }
}

void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T capacity,
                   Msg_FMS_Cmd *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void initialize_msg_local_queues_for(void)
{
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_p, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_c[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T d1;
  boolean_T rtb_Compare_a4;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1_l;
  real32_T rtb_Saturation_fu;
  real32_T rtb_Saturation1_bl;
  real32_T rtb_Divide_h[2];
  real32_T rtb_Switch_fz[3];
  real32_T rtb_Switch2_b;
  int32_T rtb_n;
  real32_T rtb_Switch_a[3];
  MotionState rtb_state_g;
  real32_T rtb_VectorConcatenate[9];
  MotionState rtb_state;
  real32_T rtb_P_ia[2];
  real32_T rtb_P_k[2];
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Switch_b_idx_2;
  real32_T rtb_Switch_b_idx_1;
  real32_T rtb_Switch_b_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/CommandProcess' */
  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  Delay: '<S8>/Delay'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<S8>/Switch1'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S8>/Switch1' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion1'
       *  Delay: '<S8>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare_a4 = (FMS_B.Switch1 == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S7>/SetHome' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if (rtb_Compare_a4 && (FMS_PrevZCX.SetHome_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_Compare_a4;

  /* End of Outputs for SubSystem: '<S7>/SetHome' */

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant1'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  RelationalOperator: '<S13>/FixPt Relational Operator'
   *  Switch: '<S7>/Switch2'
   *  UnitDelay: '<S12>/Delay Input1'
   *  UnitDelay: '<S13>/Delay Input1'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else {
    if (FMS_U.GCS_Cmd.cmd_1 == FMS_DW.DelayInput1_DSTATE_p) {
      FMS_B.Switch1 = FMS_Cmd_None;
    }
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  rtb_Switch2_b = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Switch2_b < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Switch2_b;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S13>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S8>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Acro:
      FMS_Acro();
      break;

     case FMS_IN_Altitude:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.target_mode = PilotMode_Altitude;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     case FMS_IN_Manual_e:
      FMS_B.target_mode = PilotMode_Manual;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Manual:
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
        break;

       case PilotMode_Acro:
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Mission_g:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U)
           != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.target_mode = PilotMode_Mission;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      }
      break;

     case FMS_IN_Other:
      FMS_B.target_mode = FMS_DW.Delay_DSTATE_c;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Manual:
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
        break;

       case PilotMode_Acro:
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Position_f:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_B.target_mode = PilotMode_Position;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      }
      break;

     default:
      FMS_Stabilize();
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S19>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_a4 = (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_e);

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S2>/Logical Operator1'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.GCS_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) || rtb_Compare_a4 ||
      (FMS_PARAM.LOST_RETURN_EN == 0)) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* Logic: '<S2>/Logical Operator2' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S2>/Constant1'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  RelationalOperator: '<S20>/Compare'
   */
  FMS_B.LogicalOperator2 = ((FMS_DW.DiscreteTimeIntegrator_DSTATE >=
    FMS_PARAM.LOST_RETURN_TIME) && (FMS_PARAM.LOST_RETURN_EN != 0));

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  if (rtb_Compare_a4) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  rtb_Compare_a4 = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Compare_a4) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_Compare_a4;
  rtb_Compare_a4 = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Compare_a4) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Compare_a4;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < MAX_uint32_T) {
    FMS_DW.temporalCounter_i1++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.mission_timestamp_prev = FMS_DW.mission_timestamp_start;
  FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.Switch1;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.target_mode;
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_fz[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_a[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_fz[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_a[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_fz[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_a[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* SwitchCase: '<S22>/Switch Case' incorporates:
   *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  switch (FMS_B.state) {
   case VehicleState_Disarm:
   case VehicleState_None:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case VehicleState_Standby:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;
  }

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S24>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S31>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S29>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S28>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S44>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S79>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S65>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S24>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S22>/Disarm' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S25>/Bus Assignment'
     *  BusAssignment: '<S26>/Bus Assignment'
     *  Constant: '<S26>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S26>/Bus Assignment' incorporates:
     *  BusAssignment: '<S25>/Bus Assignment'
     *  Constant: '<S26>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S22>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S22>/Standby' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S25>/Bus Assignment'
     *  BusAssignment: '<S27>/Bus Assignment'
     *  Constant: '<S27>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S27>/Bus Assignment' incorporates:
     *  BusAssignment: '<S25>/Bus Assignment'
     *  Constant: '<S27>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S22>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S22>/Arm' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SwitchCase: '<S24>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
    switch (FMS_B.state) {
     case VehicleState_Land:
     case VehicleState_Return:
     case VehicleState_Takeoff:
     case VehicleState_Hold:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 0;
      break;

     case VehicleState_Offboard:
     case VehicleState_Mission:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 1;
      break;

     case VehicleState_Acro:
     case VehicleState_Stabilize:
     case VehicleState_Altitude:
     case VehicleState_Position:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 2;
      break;

     case VehicleState_Manual:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 3;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 4;
      break;
    }

    /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S31>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S29>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S28>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S79>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S65>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 3:
       case 4:
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S24>/SubMode' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SwitchCase: '<S31>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S31>/Takeoff' incorporates:
         *  ActionPort: '<S153>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S213>/TmpSignal ConversionAtSquareInport1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve;

        /* Sum: '<S214>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S214>/Math Function'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Sum: '<S213>/Sum of Elements'
         */
        rtb_Switch2_b = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S214>/Math Function1' incorporates:
         *  Sum: '<S214>/Sum of Elements'
         *
         * About '<S214>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S214>/Math Function1' */

        /* Switch: '<S214>/Switch' incorporates:
         *  Constant: '<S214>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S214>/Product'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Saturation_fu > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Saturation_fu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S214>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S204>/NearbyRefWP' incorporates:
         *  Constant: '<S202>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation1_bl);

        /* MATLAB Function: '<S204>/SearchL1RefWP' incorporates:
         *  Constant: '<S202>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_fu);

        /* MATLAB Function: '<S204>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S204>/Switch1' incorporates:
         *  Constant: '<S207>/Constant'
         *  RelationalOperator: '<S207>/Compare'
         */
        if (rtb_Saturation1_bl > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S206>/Compare' incorporates:
           *  Constant: '<S206>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_fu >= 0.0F);

          /* Switch: '<S204>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S204>/Switch' */
        }

        /* End of Switch: '<S204>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S205>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S215>/Sum of Elements' incorporates:
         *  Math: '<S215>/Math Function'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S215>/Math Function1' incorporates:
         *  Sum: '<S215>/Sum of Elements'
         *
         * About '<S215>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S215>/Math Function1' */

        /* Switch: '<S215>/Switch' incorporates:
         *  Constant: '<S215>/Constant'
         *  Product: '<S215>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Saturation_fu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S215>/Switch' */

        /* Product: '<S214>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S217>/Sum of Elements' incorporates:
         *  Math: '<S217>/Math Function'
         *  SignalConversion: '<S217>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S217>/Math Function1' incorporates:
         *  Sum: '<S217>/Sum of Elements'
         *
         * About '<S217>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S217>/Math Function1' */

        /* Switch: '<S217>/Switch' incorporates:
         *  Constant: '<S217>/Constant'
         *  Product: '<S217>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_fu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S217>/Switch' */

        /* Product: '<S215>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S218>/Sum of Elements' incorporates:
         *  Math: '<S218>/Math Function'
         *  SignalConversion: '<S218>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S218>/Math Function1' incorporates:
         *  Sum: '<S218>/Sum of Elements'
         *
         * About '<S218>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S218>/Math Function1' */

        /* Switch: '<S218>/Switch' incorporates:
         *  Constant: '<S218>/Constant'
         *  Product: '<S218>/Product'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_fu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S218>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S199>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_fu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation1_bl = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S218>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S217>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S199>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S218>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S217>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S199>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S199>/Divide' incorporates:
         *  Math: '<S200>/Square'
         *  Math: '<S201>/Square'
         *  Sqrt: '<S200>/Sqrt'
         *  Sqrt: '<S201>/Sqrt'
         *  Sum: '<S199>/Sum'
         *  Sum: '<S199>/Sum1'
         *  Sum: '<S200>/Sum of Elements'
         *  Sum: '<S201>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation1_bl * rtb_Saturation1_bl +
          rtb_Saturation_fu * rtb_Saturation_fu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S199>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S199>/Saturation' */

        /* Sum: '<S216>/Subtract' incorporates:
         *  Product: '<S216>/Multiply'
         *  Product: '<S216>/Multiply1'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S212>/Sign1' */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -1.0F;
        } else {
          if (rtb_Saturation_fu > 0.0F) {
            rtb_Saturation_fu = 1.0F;
          }
        }

        /* End of Signum: '<S212>/Sign1' */

        /* Switch: '<S212>/Switch2' incorporates:
         *  Constant: '<S212>/Constant4'
         */
        if (rtb_Saturation_fu == 0.0F) {
          rtb_Saturation_fu = 1.0F;
        }

        /* End of Switch: '<S212>/Switch2' */

        /* DotProduct: '<S212>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S212>/Acos' incorporates:
         *  DotProduct: '<S212>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S212>/Multiply' incorporates:
         *  Trigonometry: '<S212>/Acos'
         */
        rtb_Saturation_fu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S211>/Saturation' */
        if (rtb_Saturation_fu > 1.57079637F) {
          rtb_Saturation_fu = 1.57079637F;
        } else {
          if (rtb_Saturation_fu < -1.57079637F) {
            rtb_Saturation_fu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S211>/Saturation' */

        /* Sqrt: '<S213>/Sqrt' */
        rtb_Saturation1_bl = sqrtf(rtb_Switch2_b);

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S153>/Bus Assignment'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S153>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S153>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S153>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ok;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S211>/Divide' incorporates:
         *  Constant: '<S202>/L1'
         *  Gain: '<S211>/Gain'
         *  Math: '<S211>/Square'
         *  Product: '<S211>/Multiply1'
         *  Trigonometry: '<S211>/Sin'
         */
        rtb_Switch2_b = rtb_Saturation1_bl * rtb_Saturation1_bl * 2.0F *
          arm_sin_f32(rtb_Saturation_fu) / FMS_PARAM.L1;

        /* Saturate: '<S202>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S202>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S197>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S199>/Multiply'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S197>/Sum2'
         *  Sum: '<S199>/Add'
         *  Sum: '<S199>/Subtract'
         */
        rtb_Switch2_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S197>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S153>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S197>/Saturation1' */
        /* End of Outputs for SubSystem: '<S31>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S31>/Land' incorporates:
         *  ActionPort: '<S151>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S151>/Bus Assignment1'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S151>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S151>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S151>/Constant'
         *  Constant: '<S151>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.v_cmd = 0.0F;
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S31>/Land' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S31>/Return' incorporates:
         *  ActionPort: '<S152>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S192>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S192>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S192>/Math Function'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Switch2_b = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S192>/Math Function1' incorporates:
         *  Sum: '<S192>/Sum of Elements'
         *
         * About '<S192>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S192>/Math Function1' */

        /* Switch: '<S192>/Switch' incorporates:
         *  Constant: '<S192>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S192>/Product'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Switch2_b > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Switch2_b;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S192>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S182>/NearbyRefWP' incorporates:
         *  Constant: '<S180>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Switch2_b);

        /* MATLAB Function: '<S182>/SearchL1RefWP' incorporates:
         *  Constant: '<S180>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_fu);

        /* MATLAB Function: '<S182>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S182>/Switch1' incorporates:
         *  Constant: '<S185>/Constant'
         *  RelationalOperator: '<S185>/Compare'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S184>/Compare' incorporates:
           *  Constant: '<S184>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_fu >= 0.0F);

          /* Switch: '<S182>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S182>/Switch' */
        }

        /* End of Switch: '<S182>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S183>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S193>/Sum of Elements' incorporates:
         *  Math: '<S193>/Math Function'
         */
        rtb_Switch2_b = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S193>/Math Function1' incorporates:
         *  Sum: '<S193>/Sum of Elements'
         *
         * About '<S193>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S193>/Math Function1' */

        /* Switch: '<S193>/Switch' incorporates:
         *  Constant: '<S193>/Constant'
         *  Product: '<S193>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S193>/Switch' */

        /* Product: '<S192>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S195>/Sum of Elements' incorporates:
         *  Math: '<S195>/Math Function'
         *  SignalConversion: '<S195>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S195>/Math Function1' incorporates:
         *  Sum: '<S195>/Sum of Elements'
         *
         * About '<S195>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S195>/Math Function1' */

        /* Switch: '<S195>/Switch' incorporates:
         *  Constant: '<S195>/Constant'
         *  Product: '<S195>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Switch2_b;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S195>/Switch' */

        /* Product: '<S193>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S196>/Sum of Elements' incorporates:
         *  Math: '<S196>/Math Function'
         *  SignalConversion: '<S196>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S196>/Math Function1' incorporates:
         *  Sum: '<S196>/Sum of Elements'
         *
         * About '<S196>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S196>/Math Function1' */

        /* Switch: '<S196>/Switch' incorporates:
         *  Constant: '<S196>/Constant'
         *  Product: '<S196>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S196>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S176>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch2_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S196>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S195>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S176>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S196>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S195>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S176>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S176>/Divide' incorporates:
         *  Math: '<S177>/Square'
         *  Math: '<S178>/Square'
         *  Sqrt: '<S177>/Sqrt'
         *  Sqrt: '<S178>/Sqrt'
         *  Sum: '<S176>/Sum'
         *  Sum: '<S176>/Sum1'
         *  Sum: '<S177>/Sum of Elements'
         *  Sum: '<S178>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Switch2_b * rtb_Switch2_b) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S176>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S176>/Saturation' */

        /* Sum: '<S194>/Subtract' incorporates:
         *  Product: '<S194>/Multiply'
         *  Product: '<S194>/Multiply1'
         */
        rtb_Switch_b_idx_2 = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S190>/Sign1' */
        if (rtb_Switch_b_idx_2 < 0.0F) {
          rtb_Switch_b_idx_2 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_2 > 0.0F) {
            rtb_Switch_b_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S190>/Sign1' */

        /* Switch: '<S190>/Switch2' incorporates:
         *  Constant: '<S190>/Constant4'
         */
        if (rtb_Switch_b_idx_2 == 0.0F) {
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S190>/Switch2' */

        /* DotProduct: '<S190>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S190>/Acos' incorporates:
         *  DotProduct: '<S190>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S190>/Multiply' incorporates:
         *  Trigonometry: '<S190>/Acos'
         */
        rtb_Switch_b_idx_2 *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S189>/Saturation' */
        if (rtb_Switch_b_idx_2 > 1.57079637F) {
          rtb_Switch_b_idx_2 = 1.57079637F;
        } else {
          if (rtb_Switch_b_idx_2 < -1.57079637F) {
            rtb_Switch_b_idx_2 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S189>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S191>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S191>/Square'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Sum: '<S191>/Sum of Elements'
         */
        rtb_Switch2_b = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S152>/Bus Assignment1'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S152>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S174>/Switch2' incorporates:
         *  Constant: '<S179>/Constant'
         *  RelationalOperator: '<S179>/Compare'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
        } else {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Constant: '<S174>/vel'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S174>/Switch2' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S189>/Divide' incorporates:
         *  Constant: '<S180>/L1'
         *  Gain: '<S189>/Gain'
         *  Math: '<S189>/Square'
         *  Product: '<S189>/Multiply1'
         *  Trigonometry: '<S189>/Sin'
         */
        rtb_Switch2_b = rtb_Switch2_b * rtb_Switch2_b * 2.0F * arm_sin_f32
          (rtb_Switch_b_idx_2) / FMS_PARAM.L1;

        /* Saturate: '<S180>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S180>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S173>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S176>/Multiply'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S173>/Sum2'
         *  Sum: '<S176>/Add'
         *  Sum: '<S176>/Subtract'
         */
        rtb_Switch2_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S173>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S152>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S173>/Saturation1' */
        /* End of Outputs for SubSystem: '<S31>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S31>/Hold' incorporates:
           *  ActionPort: '<S150>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S31>/Switch Case' incorporates:
           *  Delay: '<S155>/Delay'
           *  Delay: '<S160>/start_vel'
           */
          FMS_DW.icLoad_n = 1U;
          FMS_DW.icLoad_b = 1U;

          /* End of InitializeConditions for SubSystem: '<S31>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S31>/Hold' incorporates:
         *  ActionPort: '<S150>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S167>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S167>/Math Function'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Switch2_b = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S167>/Math Function1' incorporates:
         *  Sum: '<S167>/Sum of Elements'
         *
         * About '<S167>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S167>/Math Function1' */

        /* Switch: '<S167>/Switch' incorporates:
         *  Constant: '<S167>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S167>/Product'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Switch2_b > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_fz[0] = FMS_U.INS_Out.vn;
          rtb_Switch_fz[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S167>/Switch' */

        /* Delay: '<S160>/start_vel' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (FMS_DW.icLoad_n != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.start_vel_DSTATE_g[0] = FMS_U.INS_Out.vn;
          FMS_DW.start_vel_DSTATE_g[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Sum: '<S172>/Sum of Elements' incorporates:
         *  Delay: '<S160>/start_vel'
         *  Math: '<S172>/Math Function'
         */
        rtb_Switch2_b = FMS_DW.start_vel_DSTATE_g[0] *
          FMS_DW.start_vel_DSTATE_g[0] + FMS_DW.start_vel_DSTATE_g[1] *
          FMS_DW.start_vel_DSTATE_g[1];

        /* Math: '<S172>/Math Function1' incorporates:
         *  Sum: '<S172>/Sum of Elements'
         *
         * About '<S172>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S172>/Math Function1' */

        /* Switch: '<S172>/Switch' incorporates:
         *  Constant: '<S172>/Constant'
         *  Delay: '<S160>/start_vel'
         *  Product: '<S172>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_a[0] = FMS_DW.start_vel_DSTATE_g[0];
          rtb_Switch_a[1] = FMS_DW.start_vel_DSTATE_g[1];
          rtb_Switch_a[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S172>/Switch' */

        /* Product: '<S167>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S170>/Sum of Elements' incorporates:
         *  Math: '<S170>/Math Function'
         *  SignalConversion: '<S170>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S170>/Math Function1' incorporates:
         *  Sum: '<S170>/Sum of Elements'
         *
         * About '<S170>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S170>/Math Function1' */

        /* Switch: '<S170>/Switch' incorporates:
         *  Constant: '<S170>/Constant'
         *  Product: '<S170>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S170>/Switch' */

        /* MinMax: '<S158>/Max' incorporates:
         *  Constant: '<S156>/L1'
         *  Constant: '<S156>/R'
         *  Gain: '<S158>/Gain'
         */
        rtb_Saturation_fu = fmaxf(FMS_PARAM.LOITER_R, 0.5F * FMS_PARAM.L1);

        /* MATLAB Function: '<S158>/SearchL1RefWP' incorporates:
         *  Constant: '<S156>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_k[0] = 0.0F;
        rtb_P_k[1] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.cur_waypoint[0]) &&
            (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.cur_waypoint[1]) &&
            (rtb_Saturation_fu == FMS_PARAM.L1)) {
          rtb_n = 0;
        } else {
          rtb_Switch_b_idx_0 = FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_P_ia[0] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0;
          rtb_Switch_b_idx_0 = FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R;
          rtb_Switch2_b = sqrtf(rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0 +
                                rtb_P_ia[0]);
          rtb_Saturation1_bl = FMS_PARAM.L1 * FMS_PARAM.L1;
          rtb_Switch_b_idx_2 = ((rtb_Switch2_b * rtb_Switch2_b +
            rtb_Saturation1_bl) - rtb_Saturation_fu * rtb_Saturation_fu) / (2.0F
            * rtb_Switch2_b);
          rtb_Switch_b_idx_1 /= rtb_Switch2_b;
          rtb_Switch_b_idx_0 /= rtb_Switch2_b;
          rtb_Switch2_b = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_2;
          if (rtb_Switch2_b > rtb_Saturation1_bl) {
            rtb_n = 0;
          } else if (rtb_Switch2_b == rtb_Saturation1_bl) {
            rtb_n = 1;
            rtb_P_k[0] = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
              FMS_U.INS_Out.x_R;
            rtb_P_k[1] = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
              FMS_U.INS_Out.y_R;
          } else {
            rtb_n = 2;
            rtb_Switch2_b = sqrtf(rtb_Saturation1_bl - rtb_Switch2_b);
            rtb_P_k[0] = (rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
                          FMS_U.INS_Out.x_R) + rtb_Switch2_b *
              -rtb_Switch_b_idx_0;
            rtb_P_k[1] = (rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
                          FMS_U.INS_Out.y_R) + rtb_Switch2_b *
              rtb_Switch_b_idx_1;
          }
        }

        /* End of MATLAB Function: '<S158>/SearchL1RefWP' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* RelationalOperator: '<S161>/Compare' incorporates:
         *  Constant: '<S161>/Constant'
         */
        rtb_Compare_a4 = (rtb_n > 0);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S158>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_P_ia[0] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_P_ia[1] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Switch: '<S158>/Switch' incorporates:
         *  Constant: '<S156>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S158>/OutRegionRegWP'
         *  Product: '<S172>/Divide'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Compare_a4) {
          rtb_Switch2_b = rtb_P_k[0];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S158>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch2_b = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch2_b = rtb_Switch_a[0] / rtb_Switch_a[2] * FMS_PARAM.L1 +
            FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S159>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Switch_b_idx_1 = rtb_Switch2_b - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S158>/Switch' incorporates:
         *  Constant: '<S156>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S158>/OutRegionRegWP'
         *  Product: '<S172>/Divide'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Compare_a4) {
          rtb_Switch2_b = rtb_P_k[1];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S158>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Switch2_b = FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch2_b = rtb_Switch_a[1] / rtb_Switch_a[2] * FMS_PARAM.L1 +
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S159>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Switch_b_idx_0 = rtb_Switch2_b - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S168>/Sum of Elements' incorporates:
         *  Math: '<S168>/Math Function'
         */
        rtb_Switch2_b = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1 +
          rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Math: '<S168>/Math Function1' incorporates:
         *  Sum: '<S168>/Sum of Elements'
         *
         * About '<S168>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S168>/Math Function1' */

        /* Switch: '<S168>/Switch' incorporates:
         *  Constant: '<S168>/Constant'
         *  Product: '<S168>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_a[0] = rtb_Switch_b_idx_1;
          rtb_Switch_a[1] = rtb_Switch_b_idx_0;
          rtb_Switch_a[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S168>/Switch' */

        /* Product: '<S168>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Sum: '<S171>/Sum of Elements' incorporates:
         *  Math: '<S171>/Math Function'
         *  SignalConversion: '<S171>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S171>/Math Function1' incorporates:
         *  Sum: '<S171>/Sum of Elements'
         *
         * About '<S171>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S171>/Math Function1' */

        /* Switch: '<S171>/Switch' incorporates:
         *  Constant: '<S171>/Constant'
         *  Product: '<S171>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_a[0] = rtb_Divide_h[1];
          rtb_Switch_a[1] = rtb_Divide_h[0];
          rtb_Switch_a[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_a[0] = 0.0F;
          rtb_Switch_a[1] = 0.0F;
          rtb_Switch_a[2] = 1.0F;
        }

        /* End of Switch: '<S171>/Switch' */

        /* Product: '<S171>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

        /* Product: '<S170>/Divide' */
        rtb_P_k[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S171>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Product: '<S170>/Divide' */
        rtb_P_k[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S166>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S166>/Square'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Sum: '<S166>/Sum of Elements'
         */
        rtb_Switch2_b = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S164>/Square' */
        rtb_Switch_b_idx_0 = rtb_Switch2_b * rtb_Switch2_b;

        /* Sum: '<S169>/Subtract' incorporates:
         *  Product: '<S169>/Multiply'
         *  Product: '<S169>/Multiply1'
         */
        rtb_Switch2_b = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S165>/Sign1' */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -1.0F;
        } else {
          if (rtb_Switch2_b > 0.0F) {
            rtb_Switch2_b = 1.0F;
          }
        }

        /* End of Signum: '<S165>/Sign1' */

        /* Switch: '<S165>/Switch2' incorporates:
         *  Constant: '<S165>/Constant4'
         */
        if (rtb_Switch2_b == 0.0F) {
          rtb_Switch2_b = 1.0F;
        }

        /* End of Switch: '<S165>/Switch2' */

        /* DotProduct: '<S165>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S165>/Acos' incorporates:
         *  DotProduct: '<S165>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S165>/Multiply' incorporates:
         *  Trigonometry: '<S165>/Acos'
         */
        rtb_Switch2_b *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S164>/Saturation' */
        if (rtb_Switch2_b > 1.57079637F) {
          rtb_Switch2_b = 1.57079637F;
        } else {
          if (rtb_Switch2_b < -1.57079637F) {
            rtb_Switch2_b = -1.57079637F;
          }
        }

        /* End of Saturate: '<S164>/Saturation' */

        /* Delay: '<S155>/Delay' incorporates:
         *  Gain: '<S157>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (FMS_DW.icLoad_b != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE = -FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S150>/Bus Assignment'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S150>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S150>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S150>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
        FMS_Y.FMS_Out.u_cmd = 15.0F;

        /* Product: '<S164>/Divide' incorporates:
         *  Constant: '<S156>/L1'
         *  Gain: '<S164>/Gain'
         *  Product: '<S164>/Multiply1'
         *  Trigonometry: '<S164>/Sin'
         */
        rtb_Switch2_b = 2.0F * rtb_Switch_b_idx_0 * arm_sin_f32(rtb_Switch2_b) /
          FMS_PARAM.L1;

        /* Saturate: '<S159>/Saturation' */
        if (rtb_Switch2_b > 9.81F) {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = 9.81F;
        } else if (rtb_Switch2_b < -9.81F) {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -9.81F;
        } else {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S159>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S155>/Gain2' incorporates:
         *  Delay: '<S155>/Delay'
         *  Gain: '<S157>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Sum: '<S155>/Sum'
         */
        rtb_Switch2_b = (FMS_DW.Delay_DSTATE - (-FMS_U.INS_Out.h_R)) *
          FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S155>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S150>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S155>/Saturation1' */

        /* Update for Delay: '<S160>/start_vel' */
        FMS_DW.icLoad_n = 0U;

        /* Update for Delay: '<S155>/Delay' */
        FMS_DW.icLoad_b = 0U;

        /* End of Outputs for SubSystem: '<S31>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S31>/Unknown' incorporates:
         *  ActionPort: '<S154>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S31>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S31>/Switch Case' */
      /* End of Outputs for SubSystem: '<S24>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S24>/Auto' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* SwitchCase: '<S29>/Switch Case' incorporates:
       *  RelationalOperator: '<S122>/FixPt Relational Operator'
       *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S122>/Delay Input1'
       *
       * Block description for '<S122>/Delay Input1':
       *
       *  Store in Global RAM
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Offboard:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 0;
        break;

       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S29>/Offboard' incorporates:
         *  ActionPort: '<S120>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S120>/Bus Assignment'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S120>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S120>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S29>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S29>/Mission' incorporates:
           *  ActionPort: '<S119>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S29>/Switch Case' incorporates:
           *  UnitDelay: '<S122>/Delay Input1'
           *
           * Block description for '<S122>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S29>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Mission' incorporates:
         *  ActionPort: '<S119>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S119>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S123>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Math: '<S143>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S122>/FixPt Relational Operator'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S122>/Delay Input1'
         *
         * Block description for '<S122>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S143>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S143>/Math Function'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Switch2_b = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S143>/Math Function1' incorporates:
         *  Sum: '<S143>/Sum of Elements'
         *
         * About '<S143>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S143>/Math Function1' */

        /* Switch: '<S143>/Switch' incorporates:
         *  Constant: '<S143>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S143>/Product'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        if (rtb_Switch2_b > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_b_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_2 = rtb_Switch2_b;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S143>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S133>/NearbyRefWP' incorporates:
         *  Constant: '<S131>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Switch2_b);

        /* MATLAB Function: '<S133>/SearchL1RefWP' incorporates:
         *  Constant: '<S131>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_fu);

        /* MATLAB Function: '<S133>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S133>/Switch1' incorporates:
         *  Constant: '<S136>/Constant'
         *  RelationalOperator: '<S136>/Compare'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S135>/Compare' incorporates:
           *  Constant: '<S135>/Constant'
           */
          rtb_Compare_a4 = (rtb_Saturation_fu >= 0.0F);

          /* Switch: '<S133>/Switch' */
          if (!rtb_Compare_a4) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S133>/Switch' */
        }

        /* End of Switch: '<S133>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S134>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S144>/Sum of Elements' incorporates:
         *  Math: '<S144>/Math Function'
         */
        rtb_Switch2_b = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S144>/Math Function1' incorporates:
         *  Sum: '<S144>/Sum of Elements'
         *
         * About '<S144>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S144>/Math Function1' */

        /* Switch: '<S144>/Switch' incorporates:
         *  Constant: '<S144>/Constant'
         *  Product: '<S144>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[0];
          rtb_Switch_fz[1] = rtb_Divide_h[1];
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S144>/Switch' */

        /* Product: '<S143>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S146>/Sum of Elements' incorporates:
         *  Math: '<S146>/Math Function'
         *  SignalConversion: '<S146>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S146>/Math Function1' incorporates:
         *  Sum: '<S146>/Sum of Elements'
         *
         * About '<S146>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S146>/Math Function1' */

        /* Switch: '<S146>/Switch' incorporates:
         *  Constant: '<S146>/Constant'
         *  Product: '<S146>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Switch2_b;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S146>/Switch' */

        /* Product: '<S144>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S147>/Sum of Elements' incorporates:
         *  Math: '<S147>/Math Function'
         *  SignalConversion: '<S147>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S147>/Math Function1' incorporates:
         *  Sum: '<S147>/Sum of Elements'
         *
         * About '<S147>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch2_b < 0.0F) {
          rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
        } else {
          rtb_Switch2_b = sqrtf(rtb_Switch2_b);
        }

        /* End of Math: '<S147>/Math Function1' */

        /* Switch: '<S147>/Switch' incorporates:
         *  Constant: '<S147>/Constant'
         *  Product: '<S147>/Product'
         */
        if (rtb_Switch2_b > 0.0F) {
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Switch2_b;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S147>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S127>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch2_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S147>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S146>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S127>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S147>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S146>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S127>/Sum1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S127>/Divide' incorporates:
         *  Math: '<S128>/Square'
         *  Math: '<S129>/Square'
         *  Sqrt: '<S128>/Sqrt'
         *  Sqrt: '<S129>/Sqrt'
         *  Sum: '<S127>/Sum'
         *  Sum: '<S127>/Sum1'
         *  Sum: '<S128>/Sum of Elements'
         *  Sum: '<S129>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Switch2_b * rtb_Switch2_b) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S127>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S127>/Saturation' */

        /* Sum: '<S145>/Subtract' incorporates:
         *  Product: '<S145>/Multiply'
         *  Product: '<S145>/Multiply1'
         */
        rtb_Switch_b_idx_2 = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S141>/Sign1' */
        if (rtb_Switch_b_idx_2 < 0.0F) {
          rtb_Switch_b_idx_2 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_2 > 0.0F) {
            rtb_Switch_b_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S141>/Sign1' */

        /* Switch: '<S141>/Switch2' incorporates:
         *  Constant: '<S141>/Constant4'
         */
        if (rtb_Switch_b_idx_2 == 0.0F) {
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S141>/Switch2' */

        /* DotProduct: '<S141>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S141>/Acos' incorporates:
         *  DotProduct: '<S141>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S141>/Multiply' incorporates:
         *  Trigonometry: '<S141>/Acos'
         */
        rtb_Switch_b_idx_2 *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S140>/Saturation' */
        if (rtb_Switch_b_idx_2 > 1.57079637F) {
          rtb_Switch_b_idx_2 = 1.57079637F;
        } else {
          if (rtb_Switch_b_idx_2 < -1.57079637F) {
            rtb_Switch_b_idx_2 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S140>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S142>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S142>/Square'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Sum: '<S142>/Sum of Elements'
         */
        rtb_Switch2_b = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                              FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S123>/Bus Assignment'
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S123>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S123>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S125>/Switch2' incorporates:
         *  Constant: '<S130>/Constant'
         *  RelationalOperator: '<S130>/Compare'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
        } else {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Constant: '<S125>/vel'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S125>/Switch2' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S140>/Divide' incorporates:
         *  Constant: '<S131>/L1'
         *  Gain: '<S140>/Gain'
         *  Math: '<S140>/Square'
         *  Product: '<S140>/Multiply1'
         *  Trigonometry: '<S140>/Sin'
         */
        rtb_Switch2_b = rtb_Switch2_b * rtb_Switch2_b * 2.0F * arm_sin_f32
          (rtb_Switch_b_idx_2) / FMS_PARAM.L1;

        /* Saturate: '<S131>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S131>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S124>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S127>/Multiply'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S124>/Sum2'
         *  Sum: '<S127>/Add'
         *  Sum: '<S127>/Subtract'
         */
        rtb_Switch2_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S124>/Saturation1' */
        if (rtb_Switch2_b > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Switch2_b < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S123>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Switch2_b;
        }

        /* End of Saturate: '<S124>/Saturation1' */
        /* End of Outputs for SubSystem: '<S119>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S122>/Delay Input1' incorporates:
         *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S122>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S29>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S29>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S29>/Switch Case' */
      /* End of Outputs for SubSystem: '<S24>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S24>/Assist' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* SwitchCase: '<S28>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Acro:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S79>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S65>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S28>/Acro' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  BusAssignment: '<S33>/Bus Assignment'
         *  Constant: '<S33>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S38>/Gain'
         *  Gain: '<S38>/Gain1'
         *  Gain: '<S38>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S39>/Saturation' incorporates:
         *  Constant: '<S39>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         *  Sum: '<S39>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch2_b = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S39>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S39>/Constant5'
         *  Gain: '<S39>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S39>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Switch2_b), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S28>/Acro' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S28>/Stabilize' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  BusAssignment: '<S36>/Bus Assignment'
         *  Constant: '<S36>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S110>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S110>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S107>/Gain'
         *  Gain: '<S110>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Switch2_b * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S111>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S111>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S107>/Gain1'
         *  Gain: '<S111>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.theta_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Switch2_b * -FMS_PARAM.PITCH_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S116>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S116>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S108>/Gain1'
         *  Gain: '<S116>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch2_b * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Saturate: '<S109>/Saturation' incorporates:
         *  Constant: '<S109>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         *  Sum: '<S109>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch2_b = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S109>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Constant: '<S109>/Constant5'
         *  Gain: '<S109>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S109>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Switch2_b), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S28>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S28>/Altitude' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S28>/Switch Case' incorporates:
           *  Chart: '<S45>/Motion Status'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S28>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S28>/Altitude' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S45>/Motion Status' incorporates:
         *  Abs: '<S45>/Abs'
         *  Abs: '<S45>/Abs1'
         *  Constant: '<S53>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S53>/Compare'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S44>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_g) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_m) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S44>/Hold Control' incorporates:
             *  ActionPort: '<S47>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S44>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S44>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S44>/Hold Control' incorporates:
           *  ActionPort: '<S47>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S44>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S44>/Brake Control' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S44>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S44>/Move Control' incorporates:
           *  ActionPort: '<S48>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S44>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S44>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  BusAssignment: '<S34>/Bus Assignment'
         *  Constant: '<S34>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S55>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S55>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S42>/Gain'
         *  Gain: '<S55>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Switch2_b * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S58>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S58>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S43>/Gain1'
         *  Gain: '<S58>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch2_b * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S40>/Gain1' incorporates:
         *  Bias: '<S40>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        rtb_Switch2_b = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S40>/Saturation' incorporates:
         *  Gain: '<S40>/Gain1'
         */
        if (rtb_Switch2_b > 1.0F) {
          rtb_Switch2_b = 1.0F;
        } else {
          if (rtb_Switch2_b < 0.0F) {
            rtb_Switch2_b = 0.0F;
          }
        }

        /* End of Saturate: '<S40>/Saturation' */

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S40>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Switch2_b;

        /* Saturate: '<S44>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S44>/Saturation1' */
        /* End of Outputs for SubSystem: '<S28>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S28>/Position' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S28>/Switch Case' incorporates:
           *  Chart: '<S66>/Motion Status'
           *  Chart: '<S80>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

          /* End of SystemReset for SubSystem: '<S28>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S28>/Position' incorporates:
         *  ActionPort: '<S35>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S106>/Trigonometric Function1' incorporates:
         *  Gain: '<S105>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Trigonometry: '<S106>/Trigonometric Function3'
         */
        rtb_Switch2_b = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_VectorConcatenate[0] = rtb_Switch2_b;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S106>/Trigonometric Function' incorporates:
         *  Gain: '<S105>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  Trigonometry: '<S106>/Trigonometric Function2'
         */
        rtb_Switch_b_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_VectorConcatenate[1] = rtb_Switch_b_idx_0;

        /* SignalConversion: '<S106>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S106>/Constant3'
         */
        rtb_VectorConcatenate[2] = 0.0F;

        /* Gain: '<S106>/Gain' */
        rtb_VectorConcatenate[3] = -rtb_Switch_b_idx_0;

        /* Trigonometry: '<S106>/Trigonometric Function3' */
        rtb_VectorConcatenate[4] = rtb_Switch2_b;

        /* SignalConversion: '<S106>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S106>/Constant4'
         */
        rtb_VectorConcatenate[5] = 0.0F;

        /* SignalConversion: '<S106>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S66>/Motion Status' incorporates:
         *  Abs: '<S66>/Abs'
         *  Abs: '<S66>/Abs1'
         *  Constant: '<S74>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S74>/Compare'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus_j);

        /* RelationalOperator: '<S103>/Compare' incorporates:
         *  Abs: '<S80>/Abs1'
         *  Constant: '<S103>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        rtb_Compare_a4 = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S80>/Motion State' incorporates:
         *  Abs: '<S80>/Abs'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_h;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_d:
            rtb_state = MotionState_Brake;

            /* Product: '<S80>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S23>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_VectorConcatenate_0[rtb_n] = rtb_VectorConcatenate[rtb_n + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate[rtb_n + 3] *
                                    FMS_U.INS_Out.ve +
                                    rtb_VectorConcatenate[rtb_n] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            }

            /* End of Product: '<S80>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_0[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_l;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_a4) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_h;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_l:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_a4) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_h;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_a4) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_d;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S80>/Motion State' */

        /* SwitchCase: '<S79>/Switch Case' incorporates:
         *  Math: '<S93>/Square'
         *  Product: '<S99>/Divide'
         *  Sum: '<S85>/Subtract'
         *  Switch: '<S84>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_l) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S79>/Hold Control' incorporates:
             *  ActionPort: '<S82>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S79>/Switch Case' incorporates:
             *  Delay: '<S86>/start_vel'
             *  Delay: '<S86>/start_wp'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_c = 1U;

            /* End of InitializeConditions for SubSystem: '<S79>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S79>/Hold Control' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S94>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S94>/Math Function'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          rtb_Switch2_b = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
            * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S94>/Math Function1' incorporates:
           *  Sum: '<S94>/Sum of Elements'
           *
           * About '<S94>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch2_b < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Switch2_b));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Switch2_b);
          }

          /* End of Math: '<S94>/Math Function1' */

          /* Switch: '<S94>/Switch' incorporates:
           *  Constant: '<S94>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S94>/Product'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_fz[0] = FMS_U.INS_Out.vn;
            rtb_Switch_fz[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_fz[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_fz[0] = 0.0F;
            rtb_Switch_fz[1] = 0.0F;
            rtb_Switch_fz[2] = 1.0F;
          }

          /* End of Switch: '<S94>/Switch' */

          /* Delay: '<S86>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Sum: '<S99>/Sum of Elements' incorporates:
           *  Delay: '<S86>/start_vel'
           *  Math: '<S99>/Math Function'
           */
          rtb_Switch2_b = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0]
            + FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S99>/Math Function1' incorporates:
           *  Sum: '<S99>/Sum of Elements'
           *
           * About '<S99>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch2_b < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Switch2_b));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Switch2_b);
          }

          /* End of Math: '<S99>/Math Function1' */

          /* Switch: '<S99>/Switch' incorporates:
           *  Constant: '<S99>/Constant'
           *  Delay: '<S86>/start_vel'
           *  Product: '<S99>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = FMS_DW.start_vel_DSTATE[0];
            rtb_Switch_a[1] = FMS_DW.start_vel_DSTATE[1];
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S99>/Switch' */

          /* Product: '<S94>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Sum: '<S97>/Sum of Elements' incorporates:
           *  Math: '<S97>/Math Function'
           *  SignalConversion: '<S97>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Switch2_b = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
            rtb_Divide_h[0];

          /* Math: '<S97>/Math Function1' incorporates:
           *  Sum: '<S97>/Sum of Elements'
           *
           * About '<S97>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch2_b < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Switch2_b));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Switch2_b);
          }

          /* End of Math: '<S97>/Math Function1' */

          /* Switch: '<S97>/Switch' incorporates:
           *  Constant: '<S97>/Constant'
           *  Product: '<S97>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_fz[0] = rtb_Divide_h[1];
            rtb_Switch_fz[1] = rtb_Divide_h[0];
            rtb_Switch_fz[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_fz[0] = 0.0F;
            rtb_Switch_fz[1] = 0.0F;
            rtb_Switch_fz[2] = 1.0F;
          }

          /* End of Switch: '<S97>/Switch' */

          /* Delay: '<S86>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S84>/SearchL1RefWP' incorporates:
           *  Delay: '<S86>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          rtb_Divide_h[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_h[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S99>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* MATLAB Function: '<S84>/SearchL1RefWP' */
          rtb_Switch2_b = rtb_Switch_b_idx_0 * rtb_Divide_h[0];
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0;

          /* Product: '<S99>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* MATLAB Function: '<S84>/SearchL1RefWP' incorporates:
           *  Constant: '<S82>/L1'
           *  Delay: '<S86>/start_wp'
           */
          rtb_Switch2_b += rtb_Switch_b_idx_0 * rtb_Divide_h[1];
          rtb_Switch_b_idx_2 = 2.0F * rtb_Switch2_b;
          rtb_P_k[0] = 0.0F;
          rtb_P_k[1] = 0.0F;
          rtb_Saturation_fu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_2 -
            ((rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
              rtb_Divide_h[1]) - FMS_PARAM.L1 * FMS_PARAM.L1) * 4.0F;
          rtb_Switch2_b = -1.0F;
          if (rtb_Saturation_fu > 0.0F) {
            rtb_Switch2_b = sqrtf(rtb_Saturation_fu);
            rtb_Switch2_b = fmaxf((-rtb_Switch_b_idx_2 + rtb_Switch2_b) / 2.0F,
                                  (-rtb_Switch_b_idx_2 - rtb_Switch2_b) / 2.0F);
            rtb_P_k[0] = rtb_Switch2_b * rtb_Switch_b_idx_1 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_P_k[1] = rtb_Switch2_b * rtb_Switch_b_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (rtb_Saturation_fu == 0.0F) {
              rtb_Switch2_b = -rtb_Switch_b_idx_2 / 2.0F;
              rtb_P_k[0] = rtb_Switch2_b * rtb_Switch_b_idx_1 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_P_k[1] = rtb_Switch2_b * rtb_Switch_b_idx_0 +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S87>/Compare' incorporates:
           *  Constant: '<S87>/Constant'
           *  MATLAB Function: '<S84>/SearchL1RefWP'
           */
          rtb_Compare_a4 = (rtb_Switch2_b > 0.0F);

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S84>/OutRegionRefWP' incorporates:
           *  Delay: '<S86>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          rtb_Switch2_b = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_Switch_b_idx_1 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1])
            * rtb_Switch_b_idx_0;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_b_idx_2 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Saturation_fu = fabsf((rtb_Switch2_b * rtb_Switch_b_idx_1 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Saturation_fu > 1.29246971E-26F) {
            d1 = 1.0F;
            rtb_Switch_b_idx_2 = rtb_Saturation_fu;
          } else {
            rtb_Saturation1_bl = rtb_Saturation_fu / 1.29246971E-26F;
            d1 = rtb_Saturation1_bl * rtb_Saturation1_bl;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Saturation_fu = fabsf((rtb_Switch2_b * rtb_Switch_b_idx_0 +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Saturation_fu > rtb_Switch_b_idx_2) {
            rtb_Saturation1_bl = rtb_Switch_b_idx_2 / rtb_Saturation_fu;
            d1 = d1 * rtb_Saturation1_bl * rtb_Saturation1_bl + 1.0F;
            rtb_Switch_b_idx_2 = rtb_Saturation_fu;
          } else {
            rtb_Saturation1_bl = rtb_Saturation_fu / rtb_Switch_b_idx_2;
            d1 += rtb_Saturation1_bl * rtb_Saturation1_bl;
          }

          d1 = rtb_Switch_b_idx_2 * sqrtf(d1);
          rtb_Switch_b_idx_2 = d1 * 0.577350259F + rtb_Switch2_b;

          /* Switch: '<S84>/Switch' incorporates:
           *  Delay: '<S86>/start_wp'
           *  MATLAB Function: '<S84>/OutRegionRefWP'
           */
          if (rtb_Compare_a4) {
            rtb_Switch2_b = rtb_P_k[0];
          } else {
            rtb_Switch2_b = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S85>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Switch2_b - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S95>/Math Function' */
          rtb_Divide_h[0] = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;
          rtb_P_k[0] = rtb_Switch_b_idx_1;

          /* Switch: '<S84>/Switch' incorporates:
           *  Delay: '<S86>/start_wp'
           *  MATLAB Function: '<S84>/OutRegionRefWP'
           *  Sum: '<S85>/Subtract'
           */
          if (rtb_Compare_a4) {
            rtb_Switch2_b = rtb_P_k[1];
          } else {
            rtb_Switch2_b = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S85>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S23>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Switch2_b - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S95>/Math Function' incorporates:
           *  Math: '<S93>/Square'
           */
          rtb_Switch2_b = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;

          /* Sum: '<S95>/Sum of Elements' incorporates:
           *  Math: '<S95>/Math Function'
           */
          rtb_Saturation_fu = rtb_Switch2_b + rtb_Divide_h[0];

          /* Math: '<S95>/Math Function1' incorporates:
           *  Sum: '<S95>/Sum of Elements'
           *
           * About '<S95>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S95>/Math Function1' */

          /* Switch: '<S95>/Switch' incorporates:
           *  Constant: '<S95>/Constant'
           *  Product: '<S95>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = rtb_P_k[0];
            rtb_Switch_a[1] = rtb_Switch_b_idx_1;
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S95>/Switch' */

          /* Product: '<S95>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Sum: '<S98>/Sum of Elements' incorporates:
           *  Math: '<S98>/Math Function'
           *  SignalConversion: '<S98>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0]
            * rtb_Divide_h[0];

          /* Math: '<S98>/Math Function1' incorporates:
           *  Sum: '<S98>/Sum of Elements'
           *
           * About '<S98>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S98>/Math Function1' */

          /* Switch: '<S98>/Switch' incorporates:
           *  Constant: '<S98>/Constant'
           *  Product: '<S98>/Product'
           */
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_a[0] = rtb_Divide_h[1];
            rtb_Switch_a[1] = rtb_Divide_h[0];
            rtb_Switch_a[2] = rtb_Switch_b_idx_0;
          } else {
            rtb_Switch_a[0] = 0.0F;
            rtb_Switch_a[1] = 0.0F;
            rtb_Switch_a[2] = 1.0F;
          }

          /* End of Switch: '<S98>/Switch' */

          /* Product: '<S98>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* Product: '<S97>/Divide' */
          rtb_P_ia[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_P_k[0] *= rtb_P_k[0];

          /* Product: '<S98>/Divide' incorporates:
           *  Math: '<S93>/Square'
           */
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Product: '<S97>/Divide' */
          rtb_P_ia[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sqrt: '<S92>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S92>/Square'
           *  SignalConversion: '<S23>/Signal Copy1'
           *  Sum: '<S92>/Sum of Elements'
           */
          rtb_Switch_b_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Gain: '<S90>/Gain' incorporates:
           *  Math: '<S90>/Square'
           */
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0 * 2.0F;

          /* Sum: '<S96>/Subtract' incorporates:
           *  Product: '<S96>/Multiply'
           *  Product: '<S96>/Multiply1'
           */
          rtb_Switch_b_idx_0 = rtb_Divide_h[0] * rtb_P_ia[1] - rtb_Divide_h[1] *
            rtb_P_ia[0];

          /* Signum: '<S91>/Sign1' */
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_b_idx_0 > 0.0F) {
              rtb_Switch_b_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S91>/Sign1' */

          /* Switch: '<S91>/Switch2' incorporates:
           *  Constant: '<S91>/Constant4'
           */
          if (rtb_Switch_b_idx_0 == 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }

          /* End of Switch: '<S91>/Switch2' */

          /* DotProduct: '<S91>/Dot Product' */
          rtb_Switch_b_idx_2 = rtb_P_ia[0] * rtb_Divide_h[0] + rtb_P_ia[1] *
            rtb_Divide_h[1];

          /* Trigonometry: '<S91>/Acos' incorporates:
           *  DotProduct: '<S91>/Dot Product'
           */
          if (rtb_Switch_b_idx_2 > 1.0F) {
            rtb_Switch_b_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_b_idx_2 < -1.0F) {
              rtb_Switch_b_idx_2 = -1.0F;
            }
          }

          /* Product: '<S91>/Multiply' incorporates:
           *  Trigonometry: '<S91>/Acos'
           */
          rtb_Switch_b_idx_0 *= acosf(rtb_Switch_b_idx_2);

          /* Saturate: '<S90>/Saturation' */
          if (rtb_Switch_b_idx_0 > 1.57079637F) {
            rtb_Switch_b_idx_0 = 1.57079637F;
          } else {
            if (rtb_Switch_b_idx_0 < -1.57079637F) {
              rtb_Switch_b_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S90>/Saturation' */

          /* Product: '<S90>/Divide' incorporates:
           *  Constant: '<S82>/L1'
           *  Constant: '<S90>/Constant'
           *  MinMax: '<S90>/Max'
           *  MinMax: '<S90>/Min'
           *  Product: '<S90>/Multiply1'
           *  Sqrt: '<S93>/Sqrt'
           *  Sum: '<S93>/Sum of Elements'
           *  Trigonometry: '<S90>/Sin'
           */
          FMS_B.Merge_p = arm_sin_f32(rtb_Switch_b_idx_0) * rtb_Switch_b_idx_1 /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Switch2_b + rtb_P_k[0]), 0.5F));

          /* Update for Delay: '<S86>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S86>/start_wp' */
          FMS_DW.icLoad_c = 0U;

          /* End of Outputs for SubSystem: '<S79>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S79>/Brake Control' incorporates:
           *  ActionPort: '<S81>/Action Port'
           */
          /* SignalConversion: '<S81>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
           *  Constant: '<S81>/Brake Speed'
           */
          FMS_B.Merge_p = 0.0F;

          /* End of Outputs for SubSystem: '<S79>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S79>/Move Control' incorporates:
           *  ActionPort: '<S83>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* DeadZone: '<S100>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S23>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Switch2_b = 0.0F;
          } else {
            rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S100>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Gain: '<S83>/Gain6' incorporates:
           *  Gain: '<S100>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Switch2_b *
            FMS_PARAM.ACC_Y_LIM;

          /* End of Outputs for SubSystem: '<S79>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S79>/Switch Case' */

        /* SwitchCase: '<S65>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy1'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ba;
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        switch (rtb_state_g) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_ba) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ba != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S65>/Hold Control' incorporates:
             *  ActionPort: '<S68>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S65>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_l);

            /* End of SystemReset for SubSystem: '<S65>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S65>/Hold Control' incorporates:
           *  ActionPort: '<S68>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_l);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S65>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S65>/Brake Control' incorporates:
           *  ActionPort: '<S67>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S65>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S65>/Move Control' incorporates:
           *  ActionPort: '<S69>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S65>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S65>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  BusAssignment: '<S35>/Bus Assignment'
         *  Constant: '<S35>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S76>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch2_b = 0.0F;
        } else {
          rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S76>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S63>/Gain1'
         *  Gain: '<S76>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch2_b * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S61>/Gain1' incorporates:
         *  Bias: '<S61>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S23>/Signal Copy2'
         */
        rtb_Switch2_b = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S61>/Saturation' incorporates:
         *  Gain: '<S61>/Gain1'
         */
        if (rtb_Switch2_b > 1.0F) {
          rtb_Switch2_b = 1.0F;
        } else {
          if (rtb_Switch2_b < 0.0F) {
            rtb_Switch2_b = 0.0F;
          }
        }

        /* End of Saturate: '<S61>/Saturation' */

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  Gain: '<S61>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Switch2_b;

        /* Saturate: '<S79>/Saturation1' */
        if (FMS_B.Merge_p > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (FMS_B.Merge_p < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_p;
        }

        /* End of Saturate: '<S79>/Saturation1' */

        /* Saturate: '<S65>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S25>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S65>/Saturation1' */
        /* End of Outputs for SubSystem: '<S28>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S28>/Unknown' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S28>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S28>/Switch Case' */
      /* End of Outputs for SubSystem: '<S24>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S24>/Manual' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* Saturate: '<S149>/Saturation' incorporates:
       *  Constant: '<S149>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S23>/Signal Copy2'
       *  Sum: '<S149>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Switch2_b = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Switch2_b = 0.0F;
      } else {
        rtb_Switch2_b = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S149>/Saturation' */
      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* DataTypeConversion: '<S148>/Data Type Conversion' incorporates:
       *  Constant: '<S149>/Constant5'
       *  Gain: '<S149>/Gain4'
       *  Sum: '<S149>/Add'
       */
      rtb_DataTypeConversion = (uint16_T)fmodf(floorf(500.0F * rtb_Switch2_b +
        1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* DataTypeConversion: '<S148>/Data Type Conversion1' incorporates:
       *  Bias: '<S148>/Bias1'
       *  Gain: '<S148>/Gain'
       *  Gain: '<S148>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S23>/Signal Copy2'
       */
      rtb_Switch2_b = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV *
        FMS_U.Pilot_Cmd.stick_roll * 500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      rtb_DataTypeConversion1_l = (uint16_T)(rtb_Switch2_b < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Switch2_b : (int32_T)(uint16_T)
        rtb_Switch2_b);

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S25>/Bus Assignment'
       *  BusAssignment: '<S30>/Bus Assignment'
       *  Constant: '<S30>/Constant'
       *  SignalConversion: '<S30>/TmpHiddenBufferAtBus AssignmentInport1'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S30>/Bus Assignment' incorporates:
       *  BusAssignment: '<S25>/Bus Assignment'
       *  Constant: '<S30>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
      FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_l;
      FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_l;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* DataTypeConversion: '<S148>/Data Type Conversion2' incorporates:
       *  Bias: '<S148>/Bias2'
       *  Gain: '<S148>/Gain2'
       *  Gain: '<S148>/Gain4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S23>/Signal Copy2'
       */
      rtb_Switch2_b = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
        FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S30>/Bus Assignment' incorporates:
       *  BusAssignment: '<S25>/Bus Assignment'
       *  DataTypeConversion: '<S148>/Data Type Conversion2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_Switch2_b < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Switch2_b : (int32_T)(uint16_T)
        rtb_Switch2_b);

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* DataTypeConversion: '<S148>/Data Type Conversion3' incorporates:
       *  Bias: '<S148>/Bias3'
       *  Gain: '<S148>/Gain3'
       *  Gain: '<S148>/Gain5'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S23>/Signal Copy2'
       */
      rtb_Switch2_b = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV *
        FMS_U.Pilot_Cmd.stick_yaw * 500.0F + 1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S30>/Bus Assignment' incorporates:
       *  BusAssignment: '<S25>/Bus Assignment'
       *  DataTypeConversion: '<S148>/Data Type Conversion3'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_Switch2_b < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Switch2_b : (int32_T)(uint16_T)
        rtb_Switch2_b);
      for (rtb_n = 0; rtb_n < 10; rtb_n++) {
        FMS_Y.FMS_Out.actuator_cmd[rtb_n + 6] = 0U;
      }

      /* End of Outputs for SubSystem: '<S24>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S25>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S24>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S24>/Switch Case' */
    /* End of Outputs for SubSystem: '<S22>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S22>/Switch Case' */

  /* BusAssignment: '<S25>/Bus Assignment' incorporates:
   *  Constant: '<S25>/Constant'
   *  DataStoreRead: '<S25>/Data Store Read'
   *  DataTypeConversion: '<S25>/Data Type Conversion'
   *  DiscreteIntegrator: '<S219>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S25>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S219>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_e = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator1_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
}

/* Model initialize function */
void FMS_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FMS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &FMS_B), 0,
                sizeof(B_FMS_T));

  {
    FMS_B.state = VehicleState_None;
    FMS_B.target_mode = PilotMode_None;
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* states (dwork) */
  (void) memset((void *)&FMS_DW, 0,
                sizeof(DW_FMS_T));

  /* external inputs */
  (void)memset(&FMS_U, 0, sizeof(ExtU_FMS_T));

  /* external outputs */
  FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

  /* Start for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S22>/Arm' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S24>/SubMode' */
  /* Start for SwitchCase: '<S31>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S24>/SubMode' */

  /* Start for IfAction SubSystem: '<S24>/Auto' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S24>/Auto' */

  /* Start for IfAction SubSystem: '<S24>/Assist' */
  /* Start for SwitchCase: '<S28>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S28>/Altitude' */
  /* Start for SwitchCase: '<S44>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* End of Start for SubSystem: '<S28>/Altitude' */

  /* Start for IfAction SubSystem: '<S28>/Position' */
  /* Start for SwitchCase: '<S79>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S65>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;

  /* End of Start for SubSystem: '<S28>/Position' */
  /* End of Start for SubSystem: '<S24>/Assist' */
  /* End of Start for SubSystem: '<S22>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Lost_Return = 0U;
  FMS_DW.is_Lost_Return = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = FMS_Cmd_None;
  FMS_DW.prep_takeoff = 0.0;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_DW.prep_mission_takeoff = 0.0;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S31>/Hold' */
  /* InitializeConditions for Delay: '<S160>/start_vel' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for Delay: '<S155>/Delay' */
  FMS_DW.icLoad_b = 1U;

  /* End of SystemInitialize for SubSystem: '<S31>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S24>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/Mission' */
  /* InitializeConditions for UnitDelay: '<S122>/Delay Input1'
   *
   * Block description for '<S122>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S29>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S24>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S28>/Altitude' */
  /* SystemInitialize for Chart: '<S45>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S44>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S44>/Hold Control' */

  /* SystemInitialize for Merge: '<S44>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S28>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S28>/Position' */
  /* SystemInitialize for Chart: '<S66>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S80>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S79>/Hold Control' */
  /* InitializeConditions for Delay: '<S86>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S86>/start_wp' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S79>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S65>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_l);

  /* End of SystemInitialize for SubSystem: '<S65>/Hold Control' */

  /* SystemInitialize for Merge: '<S65>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S79>/Merge' */
  FMS_B.Merge_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S28>/Position' */
  /* End of SystemInitialize for SubSystem: '<S24>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S22>/Arm' */
  /* End of SystemInitialize for SubSystem: '<Root>/FMS Commander' */
}

/* Model terminate function */
void FMS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
