<?php
/**
 * @file
 * bfi_contexts.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bfi_contexts_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-article-field_popularity'
  $field_instances['node-article-field_popularity'] = array(
    'bundle' => 'article',
    'default_value' => array(
      0 => array(
        'radioactivity_energy' => 10,
        'radioactivity_timestamp' => 1390674935,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'radioactivity',
        'settings' => array(
          'accuracy' => 100,
          'energy' => 10,
          'type' => 'none',
        ),
        'type' => 'radioactivity_combo_formatter',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_popularity',
    'label' => 'Popularity',
    'required' => FALSE,
    'settings' => array(
      'profile' => 'default_weekly',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'radioactivity',
      'settings' => array(),
      'type' => 'radioactivity_basic_widget',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_banner_image'
  $field_instances['node-newsletter-field_banner_image'] = array(
    'bundle' => 'newsletter',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_banner_image',
    'label' => 'Banner Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/trimtab',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'default' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-page-field_attribution'
  $field_instances['node-page-field_attribution'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_attribution',
    'label' => 'Attribution',
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

  // Exported field_instance: 'node-page-field_external_file'
  $field_instances['node-page-field_external_file'] = array(
    'bundle' => 'page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_external_file',
    'label' => 'Related File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'attachments/pages',
      'file_extensions' => 'txt pdf doc docx xls xlsx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__content_alpha' => 0,
          'colorbox__content_beta' => 0,
          'colorbox__content_thumb' => 0,
          'colorbox__footer_sponsors' => 0,
          'colorbox__header_banner' => 0,
          'colorbox__large' => 0,
          'colorbox__lit_source_listing' => 0,
          'colorbox__medium' => 0,
          'colorbox__sections_alpha' => 0,
          'colorbox__sections_beta' => 0,
          'colorbox__sections_gamma' => 0,
          'colorbox__sections_thumb' => 0,
          'colorbox__sidebar' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__trimtab_item' => 0,
          'image' => 0,
          'image_content_alpha' => 0,
          'image_content_beta' => 0,
          'image_content_thumb' => 0,
          'image_footer_sponsors' => 0,
          'image_header_banner' => 0,
          'image_large' => 0,
          'image_lit_source_listing' => 0,
          'image_medium' => 0,
          'image_sections_alpha' => 0,
          'image_sections_beta' => 0,
          'image_sections_gamma' => 0,
          'image_sections_thumb' => 0,
          'image_sidebar' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_trimtab_item' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attribution');
  t('Banner Image');
  t('Popularity');
  t('Related File');

  return $field_instances;
}
