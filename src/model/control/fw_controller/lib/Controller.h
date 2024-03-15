/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1086
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jan 15 09:50:49 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"
#include "arm_math.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T _DSTATE;                    /* '<S42>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S43>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S14>/Discrete-Time Integrator' */
  real32_T _DSTATE_m;                  /* '<S45>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S46>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S42>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S43>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S14>/Discrete-Time Integrator' */
  int8_T _PrevResetState_k;            /* '<S45>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_m;/* '<S46>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S43>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S46>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Zero1;                /* '<S42>/Zero1' */
  const real32_T Constant[3];          /* '<S14>/Constant' */
  const real32_T Zero;                 /* '<S45>/Zero' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Disarm_Value
   * Referenced by: '<S29>/Disarm'
   */
  uint16_T Disarm_Value[6];

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S29>/Standby'
   */
  uint16_T Standby_Value[6];
} ConstP_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  FMS_Out_Bus FMS_Out;                 /* '<Root>/FMS_Out' */
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtY_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* External data declarations for dependent source files */
extern const Control_Out_Bus Controller_rtZControl_Out_Bus;/* Control_Out_Bus ground */
extern const ConstB_Controller_T Controller_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Controller_T Controller_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_VdEoPQWX2EedVH2abVW5XB CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S6>/Gain'
                                                    *   '<S6>/Gain1'
                                                    *   '<S6>/balabnce_ratio2'
                                                    *   '<S6>/balance_ratio'
                                                    *   '<S6>/pitch_ff'
                                                    *   '<S6>/thorttle_ff'
                                                    *   '<S6>/ucmd2pitch'
                                                    *   '<S6>/ucmd2thor'
                                                    *   '<S6>/wcmd2pitch'
                                                    *   '<S6>/wcmd2thor'
                                                    *   '<S7>/Saturation'
                                                    *   '<S8>/FF'
                                                    *   '<S8>/FF_limit'
                                                    *   '<S8>/PI_limit'
                                                    *   '<S35>/P_control'
                                                    *   '<S36>/P_control'
                                                    *   '<S12>/trim_speed'
                                                    *   '<S13>/trim_speed'
                                                    *   '<S26>/Constant1'
                                                    *   '<S26>/Constant12'
                                                    *   '<S26>/Constant2'
                                                    *   '<S26>/Constant7'
                                                    *   '<S38>/Constant'
                                                    *   '<S39>/Constant'
                                                    *   '<S41>/Gain'
                                                    *   '<S42>/ '
                                                    *   '<S42>/Gain3'
                                                    *   '<S44>/Gain'
                                                    *   '<S45>/Gain'
                                                    *   '<S47>/Constant'
                                                    *   '<S14>/gain1'
                                                    *   '<S14>/gain2'
                                                    *   '<S14>/gain3'
                                                    *   '<S14>/Discrete-Time Integrator'
                                                    *   '<S15>/gain1'
                                                    *   '<S15>/gain2'
                                                    *   '<S15>/gain3'
                                                    *   '<S19>/Pitch Offset'
                                                    *   '<S19>/Saturation'
                                                    *   '<S20>/Constant1'
                                                    *   '<S20>/Constant2'
                                                    */
extern struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
                                                     * Referenced by: '<S3>/Constant'
                                                     */

/* Model entry point functions */
extern void Controller_init(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Reshape' : Reshape block reduction
 * Block '<S18>/Logical Operator1' : Eliminated due to no operation
 * Block '<S25>/Reshape' : Reshape block reduction
 * Block '<S34>/Logical Operator' : Eliminated due to no operation
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/Bus_Constructor'
 * '<S2>'   : 'Controller/Controller'
 * '<S3>'   : 'Controller/Bus_Constructor/timestamp'
 * '<S4>'   : 'Controller/Controller/Attitude_Control'
 * '<S5>'   : 'Controller/Controller/Control_Allocation'
 * '<S6>'   : 'Controller/Controller/TECS_Core'
 * '<S7>'   : 'Controller/Controller/Velocity_Control'
 * '<S8>'   : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S9>'   : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S10>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S11>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S12>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S13>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S14>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S15>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S16>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S17>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S18>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S19>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S20>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S21>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S22>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S23>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S24>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S25>'  : 'Controller/Controller/Control_Allocation/Fixwing'
 * '<S26>'  : 'Controller/Controller/Control_Allocation/Fixwing/Effective_Matrix1'
 * '<S27>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select'
 * '<S28>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select1'
 * '<S29>'  : 'Controller/Controller/Control_Allocation/Fixwing/actuator_cmd_routing'
 * '<S30>'  : 'Controller/Controller/Control_Allocation/Fixwing/throttle_mapping'
 * '<S31>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select/Compare To Constant'
 * '<S32>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select1/Compare To Constant'
 * '<S33>'  : 'Controller/Controller/TECS_Core/path_angle_control'
 * '<S34>'  : 'Controller/Controller/TECS_Core/phi_cmd'
 * '<S35>'  : 'Controller/Controller/TECS_Core/pitch_pid_out'
 * '<S36>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out'
 * '<S37>'  : 'Controller/Controller/TECS_Core/velocity_control'
 * '<S38>'  : 'Controller/Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S39>'  : 'Controller/Controller/TECS_Core/path_angle_control/Subsystem1'
 * '<S40>'  : 'Controller/Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S41>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S42>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S43>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S44>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S45>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S46>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S47>'  : 'Controller/Controller/TECS_Core/velocity_control/speed_ax_out'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
