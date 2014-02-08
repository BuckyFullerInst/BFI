<?php
/**
 * @file
 * bfi_challenge_structure.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function bfi_challenge_structure_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'bfc_evaluation';
  $relation_type->label = 'BFC Evaluation';
  $relation_type->reverse_label = 'BFC Evaluation';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'entityform:bfc_project_review',
  );
  $relation_type->target_bundles = array(
    0 => 'node:project',
  );
  $export['bfc_evaluation'] = $relation_type;

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'bfc_payment';
  $relation_type->label = 'BFC Payment';
  $relation_type->reverse_label = 'BFC Payment';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 1;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'payment:payment',
  );
  $relation_type->target_bundles = array(
    0 => 'node:project',
  );
  $export['bfc_payment'] = $relation_type;

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'bfc_reviewer_assignment';
  $relation_type->label = 'BFC Reviewer Assignment';
  $relation_type->reverse_label = 'BFC Project Assigned to';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 1;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'user:*',
  );
  $relation_type->target_bundles = array(
    0 => 'node:project',
  );
  $export['bfc_reviewer_assignment'] = $relation_type;

  return $export;
}
