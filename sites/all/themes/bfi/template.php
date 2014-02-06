<?php


// For adding discipline body classes to Dymax Forum items
function bfi_preprocess_html(&$vars) {
	$node = menu_get_object();
	if (isset($node->field_disciplines)) {
		$disciplines = field_view_field('node', $node, 'field_disciplines');
		foreach ($disciplines as $key => $discipline) {
			if (is_numeric($key)) {
			  $vars['classes_array'][] = 'taxo-'.strtolower(str_replace(' ', '-', str_replace(' + ', '-', $discipline['#title'])));
			}
		}
	}
  if (isset($node->field_person_type)) {
    $types = field_view_field('node', $node, 'field_person_type');
    foreach ($types as $key => $type) {
      if (is_numeric($key)) {
        $vars['classes_array'][] = strtolower(str_replace(' ', '-', $type['#title']));
      }
    }
  }
  if (isset($node->field_year)) {
    $years = field_view_field('node', $node, 'field_year');
    foreach ($years as $key => $year) {
      if (is_numeric($key)) {
        $vars['classes_array'][] = 'year-'.strip_tags($year['#markup']);
      }
    }
  }
  if (isset($node->field_banner_image['und'][0])) {
    $vars['classes_array'][] = 'banner-image';
  }
}

/**
* Returns a list of blocks.
* Uses Drupal block interface and appends any blocks assigned by the Context module.
*/
function bfi_block_list($region) {
  // Code referenced from Fusion Core theme.
  $drupal_list = block_list($region);
  if (module_exists('context') && $context = context_get_plugin('reaction', 'block')) {
    $context_list = $context->block_list($region);
    $drupal_list = array_merge($context_list, $drupal_list);
  }
  return $drupal_list;
}

/**
* Implements template_preprocess_block().
*/
function bfi_preprocess_block(&$vars) {
  // Adds 'first' and 'last' class to blocks for styling.
  $block_count = count(bfi_block_list($vars['block']->region));

  if ($vars['block_id'] == 1 || $block_count == 1) {
    $vars['classes_array'][] = 'block-first';
  }
  if ($vars['block_id'] == $block_count) {
    $vars['classes_array'][] = 'block-last';
  }
}
