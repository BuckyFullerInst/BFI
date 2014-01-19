<?php
/**
 * @file
 * bfi_challenge_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bfi_challenge_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bfi_challenge_structure_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function bfi_challenge_structure_default_entityform_type() {
  $items = array();
  $items['bfc_project_review'] = entity_import('entityform_type', '{
    "type" : "bfc_project_review",
    "label" : "BFC Project Review",
    "data" : {
      "draftable" : 1,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submission_rules" : { "rules_bfc_review_note_submission" : "rules_bfc_review_note_submission" },
      "validation_rules" : [],
      "submit_button_text" : "",
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "user_entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "10" : "10",
        "9" : "9",
        "3" : "3",
        "1" : 0,
        "2" : 0,
        "7" : 0,
        "8" : 0,
        "5" : 0,
        "6" : 0,
        "12" : 0,
        "11" : 0,
        "4" : 0
      },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['bfc_project_submit'] = entity_import('entityform_type', '{
    "type" : "bfc_project_submit",
    "label" : "Apply to the Challenge!",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submission_rules" : { "rules_bfc_project_application_submission" : "rules_bfc_project_application_submission" },
      "validation_rules" : [],
      "submit_button_text" : "",
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "user_entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "2" : 0,
        "7" : 0,
        "8" : 0,
        "5" : 0,
        "6" : 0,
        "12" : 0,
        "10" : 0,
        "9" : 0,
        "11" : 0,
        "4" : 0,
        "3" : 0
      },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_homebox().
 */
function bfi_challenge_structure_homebox() {
  $homeboxes = array();

  $homeboxes['bfc_homebox_admin'] = array (
    'regions' => 4,
    'cache' => 1,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_a98510cc53fd8b6870e092f55e37631c' => 
      array (
        'module' => 'views',
        'delta' => 'a98510cc53fd8b6870e092f55e37631c',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -37,
      ),
      'views_e2293864d2f895aa486819e0ea7cdd8a' => 
      array (
        'module' => 'views',
        'delta' => 'e2293864d2f895aa486819e0ea7cdd8a',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -31,
      ),
      'views_payments-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'payments-block_1',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -36,
      ),
      'views_bfi_dashboard_users-block' => 
      array (
        'module' => 'views',
        'delta' => 'bfi_dashboard_users-block',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -30,
      ),
      'views_f9eb66002806ffdb012d1f58f4858f71' => 
      array (
        'module' => 'views',
        'delta' => 'f9eb66002806ffdb012d1f58f4858f71',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -37,
      ),
    ),
    'widths' => 
    array (
      1 => 100,
      2 => 67,
      3 => 33,
      4 => 100,
    ),
    'title' => 'BF Challenge Admin',
    'path' => 'admin/dashboard/challenge/admin',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => 
    array (
      0 => 'bfc admin',
    ),
  );

  $homeboxes['bfc_homebox_reviewer'] = array (
    'regions' => 4,
    'cache' => 1,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_b7c374fafb0d255496807cb07b4a1547' => 
      array (
        'module' => 'views',
        'delta' => 'b7c374fafb0d255496807cb07b4a1547',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -29,
      ),
      'views_a98510cc53fd8b6870e092f55e37631c' => 
      array (
        'module' => 'views',
        'delta' => 'a98510cc53fd8b6870e092f55e37631c',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -37,
      ),
    ),
    'widths' => 
    array (
      1 => 100,
      2 => 67,
      3 => 33,
      4 => 100,
    ),
    'title' => 'BF Challenge Review',
    'path' => 'admin/dashboard/challenge',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => 
    array (
      0 => 'bfc admin',
      1 => 'bfc review team',
    ),
  );


  return $homeboxes;
}
