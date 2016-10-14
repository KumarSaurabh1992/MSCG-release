//
//  force_computation.h
//  
//
//  Copyright (c) 2016 The Voth Group at The University of Chicago. All rights reserved.
//

#ifndef _force_computation_h
#define _force_computation_h

#include <array>

#include "trajectory_input.h"
#include "interaction_model.h"

struct MATRIX_DATA;

// Initialization routines to start the FM matrix calculation

void set_up_force_computers(CG_MODEL_DATA* const cg);

// Main routine calling all other matrix element calculation routines

void calculate_frame_fm_matrix(CG_MODEL_DATA* const cg, MATRIX_DATA* const mat, FrameConfig* const frame_config, PairCellList pair_cell_list, ThreeBCellList three_body_cell_list, int trajectory_block_frame_index);

// Free the temps used in FM matrix building, retaining only what is still needed for solution and output.

void free_fm_matrix_building_temps(CG_MODEL_DATA* const cg, MATRIX_DATA* const mat, FrameSource* const frame_source);

#endif
