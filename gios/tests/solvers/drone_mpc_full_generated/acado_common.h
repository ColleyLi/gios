/*
 *    This file was auto-generated using the ACADO Toolkit.
 *    
 *    While ACADO Toolkit is free software released under the terms of
 *    the GNU Lesser General Public License (LGPL), the generated code
 *    as such remains the property of the user who used ACADO Toolkit
 *    to generate this code. In particular, user dependent data of the code
 *    do not inherit the GNU LGPL license. On the other hand, parts of the
 *    generated code that are a direct copy of source code from the
 *    ACADO Toolkit or the software tools it is based on, remain, as derived
 *    work, automatically covered by the LGPL license.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    
 */


#ifndef ACADO_COMMON_H
#define ACADO_COMMON_H

#include <math.h>
#include <string.h>

#ifndef __MATLAB__
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#endif /* __MATLAB__ */

/** \defgroup ACADO ACADO CGT generated module. */
/** @{ */

/** qpOASES QP solver indicator. */
#define ACADO_QPOASES  0
#define ACADO_QPOASES3 1
/** FORCES QP solver indicator.*/
#define ACADO_FORCES   2
/** qpDUNES QP solver indicator.*/
#define ACADO_QPDUNES  3
/** HPMPC QP solver indicator. */
#define ACADO_HPMPC    4
#define ACADO_GENERIC    5

/** Indicator for determining the QP solver used by the ACADO solver code. */
#define ACADO_QP_SOLVER ACADO_QPOASES

#include "acado_qpoases_interface.hpp"


/*
 * Common definitions
 */
/** User defined block based condensing. */
#define ACADO_BLOCK_CONDENSING 0
/** Compute covariance matrix of the last state estimate. */
#define ACADO_COMPUTE_COVARIANCE_MATRIX 0
/** Flag indicating whether constraint values are hard-coded or not. */
#define ACADO_HARDCODED_CONSTRAINT_VALUES 1
/** Indicator for fixed initial state. */
#define ACADO_INITIAL_STATE_FIXED 1
/** Number of control/estimation intervals. */
#define ACADO_N 20
/** Number of online data values. */
#define ACADO_NOD 315
/** Number of path constraints. */
#define ACADO_NPAC 28
/** Number of control variables. */
#define ACADO_NU 5
/** Number of differential variables. */
#define ACADO_NX 8
/** Number of algebraic variables. */
#define ACADO_NXA 0
/** Number of differential derivative variables. */
#define ACADO_NXD 0
/** Number of references/measurements per node on the first N nodes. */
#define ACADO_NY 13
/** Number of references/measurements on the last (N + 1)st node. */
#define ACADO_NYN 8
/** Total number of QP optimization variables. */
#define ACADO_QP_NV 100
/** Number of integration steps per shooting interval. */
#define ACADO_RK_NIS 2
/** Number of Runge-Kutta stages per integration step. */
#define ACADO_RK_NSTAGES 4
/** Single versus double precision data type representation. */
#define ACADO_SINGLE_PRECISION 0
/** Providing interface for arrival cost. */
#define ACADO_USE_ARRIVAL_COST 0
/** Indicator for usage of non-hard-coded linear terms in the objective. */
#define ACADO_USE_LINEAR_TERMS 0
/** Indicator for type of fixed weighting matrices. */
#define ACADO_WEIGHTING_MATRICES_TYPE 1


/*
 * Globally used structure definitions
 */

/** The structure containing the user data.
 * 
 *  Via this structure the user "communicates" with the solver code.
 */
typedef struct ACADOvariables_
{
int dummy;
/** Matrix of size: 21 x 8 (row major format)
 * 
 *  Matrix containing 21 differential variable vectors.
 */
real_t x[ 168 ];

/** Matrix of size: 20 x 5 (row major format)
 * 
 *  Matrix containing 20 control variable vectors.
 */
real_t u[ 100 ];

/** Matrix of size: 21 x 315 (row major format)
 * 
 *  Matrix containing 21 online data vectors.
 */
real_t od[ 6615 ];

/** Column vector of size: 260
 * 
 *  Matrix containing 20 reference/measurement vectors of size 13 for first 20 nodes.
 */
real_t y[ 260 ];

/** Column vector of size: 8
 * 
 *  Reference/measurement vector for the 21. node.
 */
real_t yN[ 8 ];

/** Matrix of size: 13 x 13 (row major format) */
real_t W[ 169 ];

/** Matrix of size: 8 x 8 (row major format) */
real_t WN[ 64 ];

/** Column vector of size: 8
 * 
 *  Current state feedback vector.
 */
real_t x0[ 8 ];


} ACADOvariables;

/** Private workspace used by the auto-generated code.
 * 
 *  Data members of this structure are private to the solver.
 *  In other words, the user code should not modify values of this 
 *  structure. 
 */
typedef struct ACADOworkspace_
{
/** Column vector of size: 64 */
real_t rhs_aux[ 64 ];

real_t rk_ttt;

/** Row vector of size: 432 */
real_t rk_xxx[ 432 ];

/** Matrix of size: 4 x 112 (row major format) */
real_t rk_kkk[ 448 ];

/** Row vector of size: 432 */
real_t state[ 432 ];

/** Column vector of size: 160 */
real_t d[ 160 ];

/** Column vector of size: 260 */
real_t Dy[ 260 ];

/** Column vector of size: 8 */
real_t DyN[ 8 ];

/** Matrix of size: 160 x 8 (row major format) */
real_t evGx[ 1280 ];

/** Matrix of size: 160 x 5 (row major format) */
real_t evGu[ 800 ];

/** Row vector of size: 328 */
real_t objValueIn[ 328 ];

/** Row vector of size: 13 */
real_t objValueOut[ 13 ];

/** Matrix of size: 160 x 8 (row major format) */
real_t Q1[ 1280 ];

/** Matrix of size: 160 x 13 (row major format) */
real_t Q2[ 2080 ];

/** Matrix of size: 100 x 5 (row major format) */
real_t R1[ 500 ];

/** Matrix of size: 100 x 13 (row major format) */
real_t R2[ 1300 ];

/** Matrix of size: 8 x 8 (row major format) */
real_t QN1[ 64 ];

/** Matrix of size: 8 x 8 (row major format) */
real_t QN2[ 64 ];

/** Column vector of size: 904 */
real_t conAuxVar[ 904 ];

/** Row vector of size: 328 */
real_t conValueIn[ 328 ];

/** Row vector of size: 392 */
real_t conValueOut[ 392 ];

/** Column vector of size: 560 */
real_t evH[ 560 ];

/** Matrix of size: 560 x 8 (row major format) */
real_t evHx[ 4480 ];

/** Matrix of size: 560 x 5 (row major format) */
real_t evHu[ 2800 ];

/** Column vector of size: 28 */
real_t evHxd[ 28 ];

/** Column vector of size: 8 */
real_t Dx0[ 8 ];

/** Matrix of size: 8 x 8 (row major format) */
real_t T[ 64 ];

/** Matrix of size: 1680 x 5 (row major format) */
real_t E[ 8400 ];

/** Matrix of size: 1680 x 5 (row major format) */
real_t QE[ 8400 ];

/** Column vector of size: 160 */
real_t Qd[ 160 ];

/** Column vector of size: 168 */
real_t QDy[ 168 ];

/** Matrix of size: 100 x 8 (row major format) */
real_t H10[ 800 ];

/** Matrix of size: 560 x 8 (row major format) */
real_t A01[ 4480 ];

/** Column vector of size: 560 */
real_t pacA01Dx0[ 560 ];

/** Matrix of size: 100 x 100 (row major format) */
real_t H[ 10000 ];

/** Matrix of size: 560 x 100 (row major format) */
real_t A[ 56000 ];

/** Column vector of size: 100 */
real_t g[ 100 ];

/** Column vector of size: 100 */
real_t lb[ 100 ];

/** Column vector of size: 100 */
real_t ub[ 100 ];

/** Column vector of size: 560 */
real_t lbA[ 560 ];

/** Column vector of size: 560 */
real_t ubA[ 560 ];

/** Column vector of size: 100 */
real_t x[ 100 ];

/** Column vector of size: 660 */
real_t y[ 660 ];


} ACADOworkspace;

/* 
 * Forward function declarations. 
 */


/** Performs the integration and sensitivity propagation for one shooting interval.
 *
 *  \param rk_eta Working array to pass the input values and return the results.
 *  \param resetIntegrator The internal memory of the integrator can be reset.
 *
 *  \return Status code of the integrator.
 */
int acado_integrate( real_t* const rk_eta, int resetIntegrator );

/** Export of an ACADO symbolic function.
 *
 *  \param in Input to the exported function.
 *  \param out Output of the exported function.
 */
void acado_rhs_forw(const real_t* in, real_t* out);

/** Preparation step of the RTI scheme.
 *
 *  \return Status of the integration module. =0: OK, otherwise the error code.
 */
int acado_preparationStep(  );

/** Feedback/estimation step of the RTI scheme.
 *
 *  \return Status code of the qpOASES QP solver.
 */
int acado_feedbackStep(  );

/** Solver initialization. Must be called once before any other function call.
 *
 *  \return =0: OK, otherwise an error code of a QP solver.
 */
int acado_initializeSolver(  );

/** Initialize shooting nodes by a forward simulation starting from the first node.
 */
void acado_initializeNodesByForwardSimulation(  );

/** Shift differential variables vector by one interval.
 *
 *  \param strategy Shifting strategy: 1. Initialize node 21 with xEnd. 2. Initialize node 21 by forward simulation.
 *  \param xEnd Value for the x vector on the last node. If =0 the old value is used.
 *  \param uEnd Value for the u vector on the second to last node. If =0 the old value is used.
 */
void acado_shiftStates( int strategy, real_t* const xEnd, real_t* const uEnd );

/** Shift controls vector by one interval.
 *
 *  \param uEnd Value for the u vector on the second to last node. If =0 the old value is used.
 */
void acado_shiftControls( real_t* const uEnd );

/** Get the KKT tolerance of the current iterate.
 *
 *  \return The KKT tolerance value.
 */
real_t acado_getKKT(  );

/** Calculate the objective value.
 *
 *  \return Value of the objective function.
 */
real_t acado_getObjective(  );


/* 
 * Extern declarations. 
 */

extern ACADOworkspace acadoWorkspace;
extern ACADOvariables acadoVariables;

/** @} */

#ifndef __MATLAB__
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif /* __MATLAB__ */

#endif /* ACADO_COMMON_H */
