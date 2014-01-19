<?php
/**
 * @file
 * bfi_challenge_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bfi_challenge_structure_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'bfc_project_current_round_as_title';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BFC Project Current Round (as Title)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$return = FALSE;

if ($node = menu_get_object()) {
  global $user;
  if (isset($user->roles[9]) || isset($user->roles[3])) {		// For review team

    $user_rids = relation_query(\'user\', $user->uid)
      ->related(\'node\', $node->nid)
      ->execute();
    $user_rels = entity_load(\'relation\', array_keys($user_rids));
    
    if (count($user_rels) == 1) {
      $user_rel_wrapper = entity_metadata_wrapper(\'relation\', reset($user_rels));
      $round_node = $node->field_project_round[\'und\'][0][\'value\'];    // Matching against current round of project node
      switch ($round_node) {    // Matching current node round to user-authorized rounds
        case 1:
        if ($user_rel_wrapper->field_project_review_r1_auth->value() && !$user_rel_wrapper->field_project_review_r1_in->value()) $return = TRUE;
          break;
        case 2:
          if ($user_rel_wrapper->field_project_review_r2_auth->value() && !$user_rel_wrapper->field_project_review_r2_in->value()) $return = TRUE;
          break;
        case 3:
          if ($user_rel_wrapper->field_project_review_r3_auth->value() && !$user_rel_wrapper->field_project_review_r3_in->value()) $return = TRUE;
          break;
      }
    }
  }
}


return $return;
';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Review Round */
  $handler->display->display_options['fields']['field_project_round']['id'] = 'field_project_round';
  $handler->display->display_options['fields']['field_project_round']['table'] = 'field_data_field_project_round';
  $handler->display->display_options['fields']['field_project_round']['field'] = 'field_project_round';
  $handler->display->display_options['fields']['field_project_round']['label'] = '';
  $handler->display->display_options['fields']['field_project_round']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['text'] = '[field_project_round] Feedback';
  $handler->display->display_options['fields']['field_project_round']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_round']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_project_round']['element_class'] = 'project-round-fake-title';
  $handler->display->display_options['fields']['field_project_round']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_round']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_round']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_round']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_round']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_round']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_round']['field_api_classes'] = 1;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: for Review Team */
  $handler = $view->new_display('block', 'for Review Team', 'block');

  /* Display: for Jurors */
  $handler = $view->new_display('block', 'for Jurors', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$return = FALSE;

if ($node = menu_get_object()) {
  global $user;
  if (isset($user->roles[10]) || isset($user->roles[3])) {		// For review team

    $user_rids = relation_query(\'user\', $user->uid)
      ->related(\'node\', $node->nid)
      ->execute();
    $user_rels = entity_load(\'relation\', array_keys($user_rids));
    
    if (count($user_rels) == 1) {
      $user_rel_wrapper = entity_metadata_wrapper(\'relation\', reset($user_rels));
      $round_node = $node->field_project_round[\'und\'][0][\'value\'];    // Matching against current round of project node
      switch ($round_node) {    // Matching current node round to user-authorized rounds
        case 4:
          if ($user_rel_wrapper->field_project_review_jury_auth->value() && !$user_rel_wrapper->field_project_review_jury_in->value()) $return = TRUE;
          break;
      }
    }
  }
}


return $return;
';
  $export['bfc_project_current_round_as_title'] = $view;

  $view = new view;
  $view->name = 'bfc_project_listing';
  $view->description = 'Generic view for listing each year\'s projects';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BFC Project Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'BFC Project Listing';
  $handler->display->display_options['access']['type'] = 'node_types_role';
  $handler->display->display_options['access']['role'] = array(
    11 => '11',
    10 => '10',
    9 => '9',
    3 => '3',
  );
  $handler->display->display_options['access']['node_types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '$cycle = node_load($view->args[0]);
$year_c = substr($cycle->field_year[LANGUAGE_NONE][0][\'value\'], 0, 4);

$project = node_load($data->nid);
$year_p = substr($project->field_year[LANGUAGE_NONE][0][\'value\'], 0, 4);

if ($year_c == $year_p) return FALSE;
else return TRUE;';

  /* Display: General Listing by Year */
  $handler = $view->new_display('page', 'General Listing by Year', 'page');
  $handler->display->display_options['path'] = 'node/%/projects';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year Jump List */
  $handler = $view->new_display('block', 'Year Jump List', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = 0;
  $handler->display->display_options['style_options']['path'] = 'title';
  $handler->display->display_options['style_options']['default_value'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = 'You are viewing Challenge info from <?php $path = drupal_get_path_alias(current_path()); $path_first = substr($path, 0, 4); if ($path_first == \'year\') $year = substr($path, 5, 10); else if ($path_first == \'node\') { $parts = explode(\'/\', $path); $node = node_load($parts[1]); $year = substr($node->field_year[LANGUAGE_NONE][0][\'value\'], 0, 4); } echo $year; ?>. Please select year via the menu below:';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_year']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_year']['element_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_year']['field_api_classes'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Year (field_year) */
  $handler->display->display_options['sorts']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['sorts']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['sorts']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['sorts']['field_year_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bfc_cycle' => 'bfc_cycle',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['bfc_project_listing'] = $view;

  $view = new view;
  $view->name = 'bfc_project_meta_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BFC Project Meta-Details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project Details';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no Notes for this round yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Field: Application Questions */
  $handler->display->display_options['fields']['field_application_questions']['id'] = 'field_application_questions';
  $handler->display->display_options['fields']['field_application_questions']['table'] = 'field_data_field_application_questions';
  $handler->display->display_options['fields']['field_application_questions']['field'] = 'field_application_questions';
  $handler->display->display_options['fields']['field_application_questions']['label'] = '';
  $handler->display->display_options['fields']['field_application_questions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_questions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_questions']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['element_type'] = '0';
  $handler->display->display_options['fields']['field_application_questions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_questions']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_application_questions']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_questions']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_application_questions']['settings'] = array(
    'view_mode' => 'project_details',
  );
  $handler->display->display_options['fields']['field_application_questions']['field_api_classes'] = 1;
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_year']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_year']['element_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_year']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_year']['field_api_classes'] = 1;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_status']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_status']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_status']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_project_status']['field_api_classes'] = 1;
  /* Field: Content: Review Round */
  $handler->display->display_options['fields']['field_project_round']['id'] = 'field_project_round';
  $handler->display->display_options['fields']['field_project_round']['table'] = 'field_data_field_project_round';
  $handler->display->display_options['fields']['field_project_round']['field'] = 'field_project_round';
  $handler->display->display_options['fields']['field_project_round']['label'] = 'Review';
  $handler->display->display_options['fields']['field_project_round']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_round']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_round']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_round']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_round']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_round']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_round']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_round']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_round']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_round']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_round']['field_api_classes'] = 1;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'details');
  $handler->display->display_options['block_description'] = 'Project Details';
  $export['bfc_project_meta_details'] = $view;

  $view = new view;
  $view->name = 'bfc_project_review_all_reviewers_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'BFC Project Review All Reviewers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Assign Reviewers';
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$return = FALSE;

$project = menu_get_object();
if ($project->field_project_round[LANGUAGE_NONE][0][\'value\']) $return = TRUE;

return $return;';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no Review Team members yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_bfc_project_review_assign_reviewer_if_not_assigned' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Assign',
    ),
    'rules_component::rules_bfc_project_review_take_out_reviewer' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Remove',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Edit',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'name' => 'name',
          'mail' => 'mail',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'E-mail',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Reviewer';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
	$value = 0;
	$node = menu_get_object();
	if ($node->type == \'project\') {
		$node_id = $node->nid;
		$user_id = $data->uid;
		$rel_ids = relation_query(\'user\', $user_id)
			->related(\'node\', $node_id)
			->execute();
		$rels = entity_load(\'relation\', array_keys($rel_ids));
		if (count($rels) == 1) {
			$value = 1;
			$rel_wrapper = entity_metadata_wrapper(\'relation\', reset($rels)); // Wrapping fetch relation with Entity API wrapper (https://drupal.org/node/1021556)

			// Tallying up round 1
			if ($rel_wrapper->field_project_review_r1_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r1_in->value()) $value = $value += 1;

			// Tallying up round 2
			if ($rel_wrapper->field_project_review_r2_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r2_in->value()) $value = $value += 1;

			// Tallying up round 3
			if ($rel_wrapper->field_project_review_r3_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r3_in->value()) $value = $value += 1;
		}
	}
	print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'R1';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r1_val = round($ass_val / 100) % 10;
		switch ($r1_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	} else {
		print \'N/A\';
	}

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'R2';
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r1_val = round($ass_val / 10) % 10;
		switch ($r1_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'R3';
  $handler->display->display_options['fields']['php_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r3_val = $ass_val % 10;
		switch ($r3_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	}

?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    9 => '9',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;

  /* Display: Reviewers - Admin Panel */
  $handler = $view->new_display('block', 'Reviewers - Admin Panel', 'block');

  /* Display: Reviewers - Review Team Panel */
  $handler = $view->new_display('block', 'Reviewers - Review Team Panel', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Reviewers';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Reviewer';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
	$value = 0;
	$node = menu_get_object();
	if ($node->type == \'project\') {
		$node_id = $node->nid;
		$user_id = $data->uid;
		$rel_ids = relation_query(\'user\', $user_id)
			->related(\'node\', $node_id)
			->execute();
		$rels = entity_load(\'relation\', array_keys($rel_ids));
		if (count($rels) == 1) {
			$value = 1;
			$rel_wrapper = entity_metadata_wrapper(\'relation\', reset($rels)); // Wrapping fetch relation with Entity API wrapper (https://drupal.org/node/1021556)

			// Tallying up round 1
			if ($rel_wrapper->field_project_review_r1_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r1_in->value()) $value = $value += 1;

			// Tallying up round 2
			if ($rel_wrapper->field_project_review_r2_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r2_in->value()) $value = $value += 1;

			// Tallying up round 3
			if ($rel_wrapper->field_project_review_r3_auth->value()) $value = $value*10 + 1;
			else $value *= 10;
			if ($rel_wrapper->field_project_review_r3_in->value()) $value = $value += 1;
		}
	}
	print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'R1';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r1_val = round($ass_val / 100) % 10;
		switch ($r1_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	} else {
		print \'N/A\';
	}

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'R2';
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r1_val = round($ass_val / 10) % 10;
		switch ($r1_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'R3';
  $handler->display->display_options['fields']['php_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
	$ass_val = (int) $view->style_plugin->rendered_fields[$view->row_index][\'php\'];
	if ($ass_val) {
		$r3_val = $ass_val % 10;
		switch ($r3_val) {
			case 2:
				print \'<i class="icon-check-sign"></i>\';
				break;
			case 1:
				print \'<i class="icon-check-minus"></i>\';
				break;
			case 0:
				print \'<i class="icon-check-empty"></i>\';
				break;
		}
	}

?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';

  /* Display: Jurors - Admin Panel */
  $handler = $view->new_display('block', 'Jurors - Admin Panel', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Assign Jurors';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no Jurors yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_bfc_project_review_assign_reviewer_if_not_assigned' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Assign',
    ),
    'rules_component::rules_bfc_project_review_take_out_reviewer' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Remove',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Edit',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'name' => 'name',
          'mail' => 'mail',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'E-mail',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Juror';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Jury Round';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
	$node = menu_get_object();
	if ($node->type == \'project\') {
		$node_id = $node->nid;
		$user_id = $data->uid;
		$rel_ids = relation_query(\'user\', $user_id)
			->related(\'node\', $node_id)
			->execute();
		$rels = entity_load(\'relation\', array_keys($rel_ids));
		if (count($rels) == 1) {
			$value = 1;
			$rel_wrapper = entity_metadata_wrapper(\'relation\', reset($rels)); // Wrapping fetch relation with Entity API wrapper (https://drupal.org/node/1021556)

			// Tallying up Jury round
			if ($rel_wrapper->field_project_review_jury_auth->value()) {
				if ($rel_wrapper->field_project_review_jury_in->value()) print \'<i class="icon-check-sign"></i>\';
				else print \'<i class="icon-check-minus"></i>\';
			} else print \'<i class="icon-check-empty"></i>\';
		} else print \'N/A\';
	}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;

  /* Display: Jurors - Review Team Panel */
  $handler = $view->new_display('block', 'Jurors - Review Team Panel', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jurors';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no Jurors yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Juror';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Jury Round';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
	$node = menu_get_object();
	if ($node->type == \'project\') {
		$node_id = $node->nid;
		$user_id = $data->uid;
		$rel_ids = relation_query(\'user\', $user_id)
			->related(\'node\', $node_id)
			->execute();
		$rels = entity_load(\'relation\', array_keys($rel_ids));
		if (count($rels) == 1) {
			$value = 1;
			$rel_wrapper = entity_metadata_wrapper(\'relation\', reset($rels)); // Wrapping fetch relation with Entity API wrapper (https://drupal.org/node/1021556)

			// Tallying up Jury round
			if ($rel_wrapper->field_project_review_jury_auth->value()) {
				if ($rel_wrapper->field_project_review_jury_in->value()) print \'<i class="icon-check-sign"></i>\';
				else print \'<i class="icon-check-minus"></i>\';
			} else print \'<i class="icon-check-empty"></i>\';
		} else print \'N/A\';
	}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
  $export['bfc_project_review_all_reviewers_admin'] = $view;

  $view = new view;
  $view->name = 'bfc_project_review_form_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform_type';
  $view->human_name = 'BFC Form Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$return = FALSE;

if ($node = menu_get_object()) {
  global $user;
  if (isset($user->roles[9]) || isset($user->roles[10]) || isset($user->roles[3])) {		// For review team

    $user_rids = relation_query(\'user\', $user->uid)
      ->related(\'node\', $node->nid)
      ->execute();
    $user_rels = entity_load(\'relation\', array_keys($user_rids));
    
    if (count($user_rels) == 1) {
      $user_rel_wrapper = entity_metadata_wrapper(\'relation\', reset($user_rels));
      $round_node = $node->field_project_round[\'und\'][0][\'value\'];    // Matching against current round of project node
      switch ($round_node) {    // Matching current node round to user-authorized rounds
        case 1:
        if ($user_rel_wrapper->field_project_review_r1_auth->value() && !$user_rel_wrapper->field_project_review_r1_in->value()) $return = TRUE;
          break;
        case 2:
          if ($user_rel_wrapper->field_project_review_r2_auth->value() && !$user_rel_wrapper->field_project_review_r2_in->value()) $return = TRUE;
          break;
        case 3:
          if ($user_rel_wrapper->field_project_review_r3_auth->value() && !$user_rel_wrapper->field_project_review_r3_in->value()) $return = TRUE;
          break;
        case 4:
          if ($user_rel_wrapper->field_project_review_jury_auth->value() && !$user_rel_wrapper->field_project_review_jury_in->value()) $return = TRUE;
          break;
      }
    }
  }
}


return $return;';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Entityform Type: Rendered Entityform Type */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_entityform_type';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  /* Filter criterion: Entityform Type: Machine-readable name */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform_type';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'bfc_project_review';

  /* Display: Project Review */
  $handler = $view->new_display('block', 'Project Review', 'block');

  /* Display: Application */
  $handler = $view->new_display('block', 'Application', 'application');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Type: Machine-readable name */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform_type';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'bfc_project_submit';
  $export['bfc_project_review_form_block'] = $view;

  $view = new view;
  $view->name = 'bfc_project_review_notes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BFC Project Review Notes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Round 1 Evaluations';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no Notes for this round yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Relation: BFC Evaluation (node → entityform) */
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['id'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['table'] = 'node';
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['field'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['label'] = 'review';
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['required'] = 1;
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['r_index'] = '1';
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['entity_deduplication_left'] = 0;
  $handler->display->display_options['relationships']['relation_bfc_evaluation_entityform']['entity_deduplication_right'] = 0;
  /* Relationship: Entityform: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'entityform';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['relationships']['user']['label'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = 1;
  /* Relationship: Entityform: Relation: BFC Evaluation (entityform → relation) */
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['id'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['table'] = 'entityform';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['field'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['label'] = 'review relation';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['required'] = 0;
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['r_index'] = '-1';
  $handler->display->display_options['relationships']['relation_base_left_bfc_evaluation']['entity_deduplication_left'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Entityform: Edit Link */
  $handler->display->display_options['fields']['edit_entityform']['id'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['edit_entityform']['field'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['fields']['edit_entityform']['label'] = '';
  $handler->display->display_options['fields']['edit_entityform']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_entityform']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_entityform']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_entityform']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_entityform']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['edit_entityform']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_entityform']['hide_alter_empty'] = 1;
  /* Field: Entityform: Internal Comments */
  $handler->display->display_options['fields']['field_project_review_note']['id'] = 'field_project_review_note';
  $handler->display->display_options['fields']['field_project_review_note']['table'] = 'field_data_field_project_review_note';
  $handler->display->display_options['fields']['field_project_review_note']['field'] = 'field_project_review_note';
  $handler->display->display_options['fields']['field_project_review_note']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['fields']['field_project_review_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_review_note']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_note']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_review_note']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_review_note']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  $handler->display->display_options['fields']['field_project_review_note']['field_api_classes'] = 1;
  /* Field: Entityform: External Feedback */
  $handler->display->display_options['fields']['field_project_review_feedback']['id'] = 'field_project_review_feedback';
  $handler->display->display_options['fields']['field_project_review_feedback']['table'] = 'field_data_field_project_review_feedback';
  $handler->display->display_options['fields']['field_project_review_feedback']['field'] = 'field_project_review_feedback';
  $handler->display->display_options['fields']['field_project_review_feedback']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_feedback']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_review_feedback']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_feedback']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_review_feedback']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_review_feedback']['field_api_classes'] = 1;
  /* Field: Entityform: Criteria Scores */
  $handler->display->display_options['fields']['field_project_review_score_wrap']['id'] = 'field_project_review_score_wrap';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['table'] = 'field_data_field_project_review_score_wrap';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['field'] = 'field_project_review_score_wrap';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['relationship'] = 'relation_bfc_evaluation_entityform';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['label'] = '';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_review_score_wrap']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_review_score_wrap']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_project_review_score_wrap']['field_api_classes'] = 1;
  /* Sort criterion: Entityform: Date submitted */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['relationship'] = 'relation_bfc_evaluation_entityform';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Field: Review Round (eval) (field_project_round_eval) */
  $handler->display->display_options['filters']['field_project_round_eval_value']['id'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['table'] = 'field_data_field_project_round_eval';
  $handler->display->display_options['filters']['field_project_round_eval_value']['field'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['relationship'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['filters']['field_project_round_eval_value']['value'] = array(
    1 => '1',
  );

  /* Display: Round 1 */
  $handler = $view->new_display('block', 'Round 1', 'round_1');
  $handler->display->display_options['block_description'] = 'BFC Project Review Evals R1';

  /* Display: Round 2 */
  $handler = $view->new_display('block', 'Round 2', 'round_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Round 2 Evaluations';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Field: Review Round (eval) (field_project_round_eval) */
  $handler->display->display_options['filters']['field_project_round_eval_value']['id'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['table'] = 'field_data_field_project_round_eval';
  $handler->display->display_options['filters']['field_project_round_eval_value']['field'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['relationship'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['filters']['field_project_round_eval_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['block_description'] = 'BFC Project Review Evals R2';

  /* Display: Round 3 */
  $handler = $view->new_display('block', 'Round 3', 'round_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Round 3 Evaluations';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Field: Review Round (eval) (field_project_round_eval) */
  $handler->display->display_options['filters']['field_project_round_eval_value']['id'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['table'] = 'field_data_field_project_round_eval';
  $handler->display->display_options['filters']['field_project_round_eval_value']['field'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['relationship'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['filters']['field_project_round_eval_value']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['block_description'] = 'BFC Project Review Evals R3';

  /* Display: Jury Round */
  $handler = $view->new_display('block', 'Jury Round', 'jury');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jury Evaluations';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Field: Review Round (eval) (field_project_round_eval) */
  $handler->display->display_options['filters']['field_project_round_eval_value']['id'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['table'] = 'field_data_field_project_round_eval';
  $handler->display->display_options['filters']['field_project_round_eval_value']['field'] = 'field_project_round_eval_value';
  $handler->display->display_options['filters']['field_project_round_eval_value']['relationship'] = 'relation_base_left_bfc_evaluation';
  $handler->display->display_options['filters']['field_project_round_eval_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['block_description'] = 'BFC Project Review Evals Jury';
  $export['bfc_project_review_notes'] = $view;

  $view = new view;
  $view->name = 'bfc_project_review_team_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'BFC Project Review Team Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['bfc_project_review_team_listing'] = $view;

  $view = new view;
  $view->name = 'bfc_site_logo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BFC Site Logo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_image']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site_image' => 'site_image',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    38 => '38',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'admin_tags';

  /* Display: Logo */
  $handler = $view->new_display('block', 'Logo', 'block');
  $handler->display->display_options['block_caching'] = '8';

  /* Display: Logo Small */
  $handler = $view->new_display('block', 'Logo Small', 'block_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site_image' => 'site_image',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    52 => '52',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'admin_tags';
  $handler->display->display_options['block_caching'] = '8';
  $export['bfc_site_logo'] = $view;

  $view = new view;
  $view->name = 'payments_custom';
  $view->description = 'Custom admin view of payments replacing broken stock one';
  $view->tag = 'default';
  $view->base_table = 'payment';
  $view->human_name = 'Payments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Payments 2';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'payment.payment.view.any';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Payment: Payment method */
  $handler->display->display_options['relationships']['pmid']['id'] = 'pmid';
  $handler->display->display_options['relationships']['pmid']['table'] = 'payment';
  $handler->display->display_options['relationships']['pmid']['field'] = 'pmid';
  $handler->display->display_options['relationships']['pmid']['required'] = 0;
  /* Relationship: Payment: Line items */
  $handler->display->display_options['relationships']['pid_line_item']['id'] = 'pid_line_item';
  $handler->display->display_options['relationships']['pid_line_item']['table'] = 'payment';
  $handler->display->display_options['relationships']['pid_line_item']['field'] = 'pid_line_item';
  $handler->display->display_options['relationships']['pid_line_item']['required'] = 0;
  /* Relationship: Payment: Last status item */
  $handler->display->display_options['relationships']['psiid_last']['id'] = 'psiid_last';
  $handler->display->display_options['relationships']['psiid_last']['table'] = 'payment';
  $handler->display->display_options['relationships']['psiid_last']['field'] = 'psiid_last';
  $handler->display->display_options['relationships']['psiid_last']['required'] = 0;
  /* Relationship: Payment: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'payment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'werwe';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/payment2';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Payments 2';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $export['payments_custom'] = $view;

  return $export;
}
