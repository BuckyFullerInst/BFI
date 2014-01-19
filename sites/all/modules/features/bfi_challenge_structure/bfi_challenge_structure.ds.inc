<?php
/**
 * @file
 * bfi_challenge_structure.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function bfi_challenge_structure_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'project_details';
  $ds_view_mode->label = 'Project Details';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['project_details'] = $ds_view_mode;

  return $export;
}
