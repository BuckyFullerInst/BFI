<?php
/**
 * @file
 * bfi_challenge_structure.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bfi_challenge_structure_user_default_roles() {
  $roles = array();

  // Exported role: bfc admin.
  $roles['bfc admin'] = array(
    'name' => 'bfc admin',
    'weight' => 9,
  );

  // Exported role: bfc applicant.
  $roles['bfc applicant'] = array(
    'name' => 'bfc applicant',
    'weight' => 6,
  );

  // Exported role: bfc juror.
  $roles['bfc juror'] = array(
    'name' => 'bfc juror',
    'weight' => 7,
  );

  // Exported role: bfc review team.
  $roles['bfc review team'] = array(
    'name' => 'bfc review team',
    'weight' => 8,
  );

  return $roles;
}
