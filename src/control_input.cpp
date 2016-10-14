//
//  control_input.c
//  
//
//  Copyright (c) 2016 The Voth Group at The University of Chicago. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include "misc.h"

#include "control_input.h"

static const int kMaxLine = 200;

// Internal function prototypes.

void set_control_parameter(const char* parameter_name, const char* val, ControlInputs* const control_input, const int line);

// A simple list-based parser.

void set_control_parameter(const char* parameter_name, const char* val, ControlInputs* const control_input, const int line)
{
    if (strcmp("block_size", parameter_name) == 0) sscanf(val, "%d", &control_input->frames_per_traj_block);
    else if (strcmp("use_statistical_reweighting", parameter_name) == 0) sscanf(val, "%d", &control_input->use_statistical_reweighting);
    else if (strcmp("dynamic_types", parameter_name) == 0) sscanf(val, "%d", &control_input->dynamic_types);
    else if (strcmp("dynamic_state_sampling", parameter_name) == 0) sscanf(val, "%d", &control_input->dynamic_state_sampling);
    else if (strcmp("dynamic_state_samples_per_frame", parameter_name) == 0) sscanf(val, "%d", &control_input->dynamic_state_samples_per_frame);
    else if (strcmp("bootstrapping_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->bootstrapping_flag);
    else if (strcmp("bootstrapping_full_output_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->bootstrapping_full_output_flag);
    else if (strcmp("bootstrapping_num_estimates", parameter_name) == 0) sscanf(val, "%d", &control_input->bootstrapping_num_estimates);
    else if (strcmp("bootstrapping_num_subsamples", parameter_name) == 0) sscanf(val, "%d", &control_input->bootstrapping_num_subsamples);
    else if (strcmp("random_num_seed", parameter_name) == 0) sscanf(val, "%lu", &control_input->random_num_seed);
    else if (strcmp("constrain_pressure_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->pressure_constraint_flag);
    else if (strcmp("start_frame", parameter_name) == 0) sscanf(val, "%d", &control_input->starting_frame);
    else if (strcmp("n_frames", parameter_name) == 0) sscanf(val, "%d", &control_input->n_frames);
    else if (strcmp("nonbonded_cutoff", parameter_name) == 0) sscanf(val, "%lf", &control_input->pair_nonbonded_cutoff);
    else if (strcmp("pair_nonbonded_basis_set_resolution", parameter_name) == 0) sscanf(val, "%lf", &control_input->pair_nonbonded_fm_binwidth);
    else if (strcmp("pair_bond_basis_set_resolution", parameter_name) == 0) sscanf(val, "%lf", &control_input->pair_bond_fm_binwidth);
    else if (strcmp("angle_basis_set_resolution", parameter_name) == 0) sscanf(val, "%lf", &control_input->angle_fm_binwidth);
    else if (strcmp("dihedral_basis_set_resolution", parameter_name) == 0) sscanf(val, "%lf", &control_input->dihedral_fm_binwidth);
    else if (strcmp("pair_nonbonded_bspline_basis_order", parameter_name) == 0) sscanf(val, "%d", &control_input->nonbonded_bspline_k);
    else if (strcmp("pair_bond_bspline_basis_order", parameter_name) == 0) sscanf(val, "%d", &control_input->pair_bond_bspline_k);
    else if (strcmp("angle_bspline_basis_order", parameter_name) == 0) sscanf(val, "%d", &control_input->angle_bspline_k);
    else if (strcmp("dihedral_bspline_basis_order", parameter_name) == 0) sscanf(val, "%d", &control_input->dihedral_bspline_k);
    else if (strcmp("basis_type", parameter_name) == 0) sscanf(val, "%d", &control_input->basis_set_type);
    else if (strcmp("matrix_type", parameter_name) == 0) sscanf(val, "%d", &control_input->matrix_type);
    else if (strcmp("pair_nonbonded_output_binwidth", parameter_name) == 0) sscanf(val, "%lf", &control_input->pair_nonbonded_output_binwidth);
    else if (strcmp("pair_bond_output_binwidth", parameter_name) == 0) sscanf(val, "%lf", &control_input->pair_bond_output_binwidth);
    else if (strcmp("angle_output_binwidth", parameter_name) == 0) sscanf(val, "%lf", &control_input->angle_output_binwidth);
    else if (strcmp("dihedral_output_binwidth", parameter_name) == 0) sscanf(val, "%lf", &control_input->dihedral_output_binwidth);
    else if (strcmp("primary_output_style", parameter_name) == 0) sscanf(val, "%d", &control_input->output_style);
    else if (strcmp("itnlim", parameter_name) == 0) sscanf(val, "%d", &control_input->itnlim);
    else if (strcmp("rcond", parameter_name) == 0) sscanf(val, "%lf", &control_input->rcond);
	else if (strcmp("sparse_safety_factor", parameter_name) == 0) sscanf(val, "%lf", &control_input->sparse_safety_factor);
	else if (strcmp("num_sparse_threads", parameter_name) == 0) sscanf(val, "%d", &control_input->num_sparse_threads);
    else if (strcmp("max_pair_bonds_per_site", parameter_name) == 0) sscanf(val, "%d", &control_input->max_pair_bonds_per_site);
    else if (strcmp("max_angles_per_site", parameter_name) == 0) sscanf(val, "%d", &control_input->max_angles_per_site);
    else if (strcmp("max_dihedrals_per_site", parameter_name) == 0) sscanf(val, "%d", &control_input->max_dihedrals_per_site);
    else if (strcmp("output_solution_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->output_solution_flag);
    else if (strcmp("lanyuan_iterative_method_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->iterative_calculation_flag);
    else if (strcmp("regularization_scalar", parameter_name) == 0) sscanf(val, "%lf", &control_input->tikhonov_regularization_param);
    else if (strcmp("regularization_style", parameter_name) == 0) sscanf(val, "%d", &control_input->regularization_style);
    else if (strcmp("angle_type", parameter_name) == 0) sscanf(val, "%d", &control_input->angle_interaction_style);
    else if (strcmp("dihedral_type", parameter_name) == 0) sscanf(val, "%d", &control_input->dihedral_interaction_style);
    else if (strcmp("three_body_nonbonded_style", parameter_name) == 0) sscanf(val, "%d", &control_input->three_body_flag);
    else if (strcmp("three_body_nonbonded_basis_set_resolution", parameter_name) == 0) sscanf(val, "%lf", &control_input->three_body_fm_binwidth);
    else if (strcmp("three_body_nonbonded_output_binwidth", parameter_name) == 0) sscanf(val, "%lf", &control_input->three_body_nonbonded_output_binwidth);
    else if (strcmp("three_body_nonbonded_bspline_basis_order", parameter_name) == 0) sscanf(val, "%d", &control_input->three_body_bspline_k);
    else if (strcmp("output_residual_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->output_residual);
    else if (strcmp("bayesian_mscg_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->bayesian_flag);
    else if (strcmp("bayesian_max_iterations", parameter_name) == 0) sscanf(val, "%d", &control_input->bayesian_max_iter);
    else if (strcmp("stillinger_weber_gamma", parameter_name) == 0) sscanf(val, "%lf", &control_input->gamma);
    else if (strcmp("three_body_nonbonded_exclusion_type", parameter_name) == 0) sscanf(val, "%d", &control_input->three_body_nonbonded_exclusion_flag);
	else if (strcmp("excluded_style", parameter_name) == 0) sscanf(val, "%d", &control_input->excluded_style);
    else if (strcmp("output_spline_coeffs_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->output_spline_coeffs_flag);
    else if (strcmp("output_normal_equations_rhs_flag", parameter_name) == 0) sscanf(val, "%d", &control_input->output_normal_equations_rhs_flag);
    else if (strcmp("output_pair_nonbonded_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_pair_nonbonded_parameter_distribution);
    else if (strcmp("output_pair_bond_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_pair_bond_parameter_distribution);
    else if (strcmp("output_angle_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_angle_parameter_distribution);
    else if (strcmp("output_dihedral_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_dihedral_parameter_distribution);
    else if (strcmp("output_pair_nonbonded_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_pair_nonbonded_parameter_distribution);
	else if (strcmp("output_pair_bond_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_pair_bond_parameter_distribution);
	else if (strcmp("output_angle_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_angle_parameter_distribution);
	else if (strcmp("output_dihedral_parameter_distribution", parameter_name) == 0) sscanf(val, "%d", &control_input->output_dihedral_parameter_distribution);
    else if (strcmp("iterative_update_rate_coeff", parameter_name) == 0) sscanf(val, "%lf", &control_input->iterative_update_rate_coeff);
    else if (strcmp("temperature", parameter_name) == 0) return; //sscanf(val, "%lf", &control_input->temperature);
    else printf("Warning: Unknown parameter name '%s' in control.in: line %d!\n", parameter_name, line);
}

// Set all defaults and then read the file to overwrite those defaults as necessary.

void reset_control_defaults_and_read_control_input(ControlInputs* const control_input)
{
    char buff[kMaxLine];
    
    // Set defaults for all control.in parameters
    
    control_input->frames_per_traj_block = 10;
    control_input->use_statistical_reweighting = 0;
    control_input->pressure_constraint_flag = 0;
    control_input->dynamic_types = 0;
    control_input->dynamic_state_sampling = 0;
    control_input->dynamic_state_samples_per_frame = 1;
    control_input->bootstrapping_flag = 0;
    control_input->bootstrapping_full_output_flag = 0;
	control_input->bootstrapping_num_estimates = 1;
	control_input->bootstrapping_num_subsamples = 1;
    control_input->random_num_seed = 1;
    control_input->starting_frame = 1;
    control_input->n_frames = 10;
    control_input->pair_nonbonded_cutoff = 1.0;
    control_input->pair_nonbonded_fm_binwidth = 0.05;
    control_input->pair_bond_fm_binwidth = 0.05;
    control_input->angle_fm_binwidth = 0.05;
    control_input->dihedral_fm_binwidth = 0.05;
    control_input->nonbonded_bspline_k = 4;
    control_input->pair_bond_bspline_k = 4;
    control_input->angle_bspline_k = 4;
    control_input->dihedral_bspline_k = 4;
    control_input->basis_set_type = 0;
    control_input->matrix_type = 0;
    control_input->pair_nonbonded_output_binwidth = 0.002;
    control_input->pair_bond_output_binwidth = 0.002;
    control_input->angle_output_binwidth = 0.002;
    control_input->dihedral_output_binwidth = 0.002;
    control_input->output_style = 0;
    control_input->itnlim = 0;
    control_input->rcond = -1.0;
	control_input->sparse_safety_factor = 0.20;
    control_input->num_sparse_threads = 1;
    control_input->max_pair_bonds_per_site = 4;
    control_input->max_angles_per_site = 12;
    control_input->max_dihedrals_per_site = 36;
    control_input->output_solution_flag = 0;
    control_input->iterative_calculation_flag = 0;
    control_input->tikhonov_regularization_param = 0.0;
    control_input->regularization_style = 0;
    control_input->angle_interaction_style = 0;
    control_input->dihedral_interaction_style = 0;
    control_input->three_body_flag = 0;
    control_input->three_body_fm_binwidth = 1.0;
    control_input->three_body_nonbonded_output_binwidth = 0.2;
    control_input->three_body_bspline_k = 4;
    control_input->output_residual = 0;
    control_input->bayesian_flag = 0;
    control_input->bayesian_max_iter = 1;
    control_input->gamma = 0.12;
    control_input->three_body_nonbonded_exclusion_flag = 0;
    control_input->excluded_style = 2;
    control_input->output_spline_coeffs_flag = 0;
    control_input->output_normal_equations_rhs_flag = 0;
    control_input->output_pair_nonbonded_parameter_distribution = 0;
    control_input->output_pair_bond_parameter_distribution = 0;
    control_input->output_angle_parameter_distribution = 0;
    control_input->output_dihedral_parameter_distribution = 0;
    control_input->iterative_update_rate_coeff = 1.0;
    
    // Read control.in to set all specified parameters to new values.
    
    FILE* control_in;
    char left[50];
    char right[50];
    control_in = open_file("control.in", "r");
    
    int line = 1;
    while (fgets(buff, kMaxLine, control_in) != NULL) {
        sscanf(buff, "%s%s", left, right);
        set_control_parameter(left, right, control_input, line);
        line++;
    }
    fclose(control_in);
}
