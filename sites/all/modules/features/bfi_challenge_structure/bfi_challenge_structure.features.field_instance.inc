<?php
/**
 * @file
 * bfi_challenge_structure.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bfi_challenge_structure_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-bfc_project_review-field_project_review_feedback'
  $field_instances['entityform-bfc_project_review-field_project_review_feedback'] = array(
    'bundle' => 'bfc_project_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_feedback',
    'label' => 'External Feedback',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-bfc_project_review-field_project_review_note'
  $field_instances['entityform-bfc_project_review-field_project_review_note'] = array(
    'bundle' => 'bfc_project_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_note',
    'label' => 'Internal Comments',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'entityform-bfc_project_review-field_project_review_score_wrap'
  $field_instances['entityform-bfc_project_review-field_project_review_score_wrap'] = array(
    'bundle' => 'bfc_project_review',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_project_review_score_wrap',
    'label' => 'Criteria Scores',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-bfc_project_submit-field_application_questions'
  $field_instances['entityform-bfc_project_submit-field_application_questions'] = array(
    'bundle' => 'bfc_project_submit',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_application_questions',
    'label' => 'Application Questions',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-bfc_project_submit-field_application_terms_accept'
  $field_instances['entityform-bfc_project_submit-field_application_terms_accept'] = array(
    'bundle' => 'bfc_project_submit',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Help text goes here. Need to make this a popup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'fences_wrapper' => 'div',
    'field_name' => 'field_application_terms_accept',
    'label' => 'Terms and Conditions',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_contact_email'
  $field_instances['field_collection_item-field_application_questions-field_project_app_contact_email'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'project_details' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_contact_email',
    'label' => 'Contact Email',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_contact_name'
  $field_instances['field_collection_item-field_application_questions-field_project_app_contact_name'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'project_details' => array(
        'label' => 'inline',
        'module' => 'name',
        'settings' => array(
          'format' => 'default',
          'markup' => 0,
          'multiple' => 'default',
          'multiple_and' => 'text',
          'multiple_delimiter' => ', ',
          'multiple_delimiter_precedes_last' => 'never',
          'multiple_el_al_first' => 1,
          'multiple_el_al_min' => 3,
          'output' => 'default',
        ),
        'type' => 'name_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_contact_name',
    'label' => 'Contact Name',
    'required' => 1,
    'settings' => array(
      'component_css' => '',
      'component_layout' => 'default',
      'credentials_inline' => 0,
      'field_type' => array(
        'credentials' => 'text',
        'family' => 'text',
        'generational' => 'select',
        'given' => 'text',
        'middle' => 'text',
        'title' => 'select',
      ),
      'generational_field' => 'select',
      'inline_css' => array(
        'credentials' => '',
        'family' => '',
        'generational' => '',
        'given' => '',
        'middle' => '',
        'title' => '',
      ),
      'override_format' => 'default',
      'show_component_required_marker' => 0,
      'size' => array(
        'credentials' => 35,
        'family' => 20,
        'generational' => 5,
        'given' => 20,
        'middle' => 20,
        'title' => 6,
      ),
      'title_display' => array(
        'credentials' => 'description',
        'family' => 'title',
        'generational' => 'description',
        'given' => 'title',
        'middle' => 'title',
        'title' => 'description',
      ),
      'title_field' => 'select',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'name',
      'settings' => array(),
      'type' => 'name_widget',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_location'
  $field_instances['field_collection_item-field_application_questions-field_project_app_location'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => array(
      0 => array(
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 0,
              'coords' => 'coords',
              'country' => 0,
              'country_name' => 0,
              'locpick' => 'locpick',
              'map_link' => 'map_link',
              'name' => 'name',
              'postal_code' => 0,
              'province' => 0,
              'province_name' => 0,
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -98,
              ),
              'city' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -97,
              ),
              'country' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => 'us',
                'weight' => -94,
              ),
              'delete_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'is_primary' => array(
                'default' => 0,
              ),
              'latitude' => array(
                'default' => 0,
              ),
              'lid' => array(
                'default' => FALSE,
              ),
              'locpick' => array(
                'collect' => 0,
                'default' => FALSE,
                'nodiff' => TRUE,
                'weight' => -93,
              ),
              'longitude' => array(
                'default' => 0,
              ),
              'name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -100,
              ),
              'phone' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'postal_code' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -95,
              ),
              'province' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -96,
                'widget' => 'select',
              ),
              'source' => array(
                'default' => 0,
              ),
              'street' => array(
                '#parents' => array(
                  0 => 'field_project_app_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -99,
              ),
            ),
          ),
        ),
        'street' => '',
        'additional' => '',
        'city' => '',
        'province' => '',
        'postal_code' => '',
        'country' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'project_details' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_name'
  $field_instances['field_collection_item-field_application_questions-field_project_app_name'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'project_details' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_name',
    'label' => 'Project Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_organization'
  $field_instances['field_collection_item-field_application_questions-field_project_app_organization'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'project_details' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_organization',
    'label' => 'Organization',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_problem'
  $field_instances['field_collection_item-field_application_questions-field_project_app_problem'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'project_details' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_problem',
    'label' => 'The problem',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_app_summary'
  $field_instances['field_collection_item-field_application_questions-field_project_app_summary'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'project_details' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_summary',
    'label' => 'Short Summary',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_application_questions-field_project_applicant_type'
  $field_instances['field_collection_item-field_application_questions-field_project_applicant_type'] = array(
    'bundle' => 'field_application_questions',
    'default_value' => array(
      0 => array(
        'value' => 100,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'project_details' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_applicant_type',
    'label' => 'Applicant Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_antic'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_antic'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_antic',
    'label' => 'Anticipatory',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_comp'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_comp'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_comp',
    'label' => 'Comprehensive',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_ecol'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_ecol'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_ecol',
    'label' => 'Ecologically Responsible',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_feas'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_feas'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_feas',
    'label' => 'Feasible',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_rep'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_rep'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_rep',
    'label' => 'Replicable',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_verif'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_verif'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_verif',
    'label' => 'Verifiable',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_review_ave_vis'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_review_ave_vis'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_ave_vis',
    'label' => 'Visionary',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_rds-field_project_round_eval'
  $field_instances['field_collection_item-field_project_review_score_rds-field_project_round_eval'] = array(
    'bundle' => 'field_project_review_score_rds',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_round_eval',
    'label' => 'Review Round (eval)',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_antic'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_antic'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_antic',
    'label' => 'Anticipatory',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_comp'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_comp'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_comp',
    'label' => 'Comprehensive',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_ecol'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_ecol'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_ecol',
    'label' => 'Ecologically Responsible',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_feas'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_feas'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_feas',
    'label' => 'Feasible',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_rep'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_rep'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_rep',
    'label' => 'Replicable',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_verif'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_verif'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_verif',
    'label' => 'Verifiable',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_project_review_score_wrap-field_project_review_score_vis'
  $field_instances['field_collection_item-field_project_review_score_wrap-field_project_review_score_vis'] = array(
    'bundle' => 'field_project_review_score_wrap',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'style' => 'average',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_score_vis',
    'label' => 'Visionary',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'sites/all/modules/fivestar/widgets/minimal/minimal.css',
        ),
      ),
      'type' => 'stars',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'payment-payment-field_payment_app_id'
  $field_instances['payment-payment-field_payment_app_id'] = array(
    'bundle' => 'payment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'payment',
    'fences_wrapper' => 'div',
    'field_name' => 'field_payment_app_id',
    'label' => 'Application ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'payment-payment-field_payment_type'
  $field_instances['payment-payment-field_payment_type'] = array(
    'bundle' => 'payment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'payment',
    'fences_wrapper' => 'div',
    'field_name' => 'field_payment_type',
    'label' => 'Payment Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'relation-bfc_evaluation-endpoints'
  $field_instances['relation-bfc_evaluation-endpoints'] = array(
    'bundle' => 'bfc_evaluation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'entityform' => 'default',
            'entityform_type' => 'default',
            'file' => 'default',
            'node' => 'default',
            'relation' => 'default',
            'rules_config' => 'default',
            'search_api_index' => 'default',
            'search_api_server' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'endpoints',
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'relation-bfc_evaluation-field_project_round_eval'
  $field_instances['relation-bfc_evaluation-field_project_round_eval'] = array(
    'bundle' => 'bfc_evaluation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_round_eval',
    'label' => 'Review Round (eval)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'relation-bfc_payment-endpoints'
  $field_instances['relation-bfc_payment-endpoints'] = array(
    'bundle' => 'bfc_payment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'entityform' => 'default',
            'entityform_type' => 'default',
            'field_collection_item' => 'default',
            'file' => 'default',
            'node' => 'default',
            'payment' => 'default',
            'payment_method' => 'default',
            'relation' => 'default',
            'rules_config' => 'default',
            'search_api_index' => 'default',
            'search_api_server' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'endpoints',
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-endpoints'
  $field_instances['relation-bfc_reviewer_assignment-endpoints'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'entityform' => 'default',
            'entityform_type' => 'default',
            'file' => 'default',
            'node' => 'default',
            'relation' => 'default',
            'rules_config' => 'default',
            'search_api_index' => 'default',
            'search_api_server' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'endpoints',
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_jury_auth'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_jury_auth'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_jury_auth',
    'label' => 'Jury',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_jury_in'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_jury_in'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_jury_in',
    'label' => 'Jury In',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r1_auth'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r1_auth'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_r1_auth',
    'label' => 'Round 1',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r1_in'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r1_in'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_r1_in',
    'label' => 'R1 In',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r2_auth'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r2_auth'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_r2_auth',
    'label' => 'Round 2',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r2_in'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r2_in'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_r2_in',
    'label' => 'R2 In',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r3_auth'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r3_auth'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'relation',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_review_r3_auth',
    'label' => 'Round 3',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment-field_project_review_r3_in'
  $field_instances['relation-bfc_reviewer_assignment-field_project_review_r3_in'] = array(
    'bundle' => 'bfc_reviewer_assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'field_project_review_r3_in',
    'label' => 'R3 In',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'relation-bfc_reviewer_assignment2-endpoints'
  $field_instances['relation-bfc_reviewer_assignment2-endpoints'] = array(
    'bundle' => 'bfc_reviewer_assignment2',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'entityform' => 'default',
            'entityform_type' => 'default',
            'field_collection_item' => 'default',
            'file' => 'default',
            'node' => 'default',
            'relation' => 'default',
            'rules_config' => 'default',
            'search_api_index' => 'default',
            'search_api_server' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'endpoints',
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-payment_type-description_field'
  $field_instances['taxonomy_term-payment_type-description_field'] = array(
    'bundle' => 'payment_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => 0,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'taxonomy_term-payment_type-name_field'
  $field_instances['taxonomy_term-payment_type-name_field'] = array(
    'bundle' => 'payment_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'user-user-field_project_app_user_applied'
  $field_instances['user-user-field_project_app_user_applied'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'fences_wrapper' => 'div',
    'field_name' => 'field_project_app_user_applied',
    'label' => 'Applied to Challenge this year?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Anticipatory');
  t('Applicant Type');
  t('Application ID');
  t('Application Questions');
  t('Applied to Challenge this year?');
  t('Comprehensive');
  t('Contact Email');
  t('Contact Name');
  t('Criteria Scores');
  t('Description');
  t('Ecologically Responsible');
  t('External Feedback');
  t('Feasible');
  t('Help text goes here. Need to make this a popup.');
  t('Internal Comments');
  t('Jury');
  t('Jury In');
  t('Location');
  t('Name');
  t('Organization');
  t('Payment Type');
  t('Project Name');
  t('R1 In');
  t('R2 In');
  t('R3 In');
  t('Replicable');
  t('Review Round (eval)');
  t('Round 1');
  t('Round 2');
  t('Round 3');
  t('Short Summary');
  t('Terms and Conditions');
  t('The problem');
  t('Verifiable');
  t('Visionary');
  t('endpoints');

  return $field_instances;
}
