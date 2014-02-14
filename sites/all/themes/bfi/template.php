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

/**
* BFI edit of theme_form_element from drupal/includes/form.inc, a la https://groups.drupal.org/node/206593#comment-747503
*/
function bfi_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      if (!empty($element['#description'])) {
        $output .= '<div class="description">' . $element['#description'] . "</div>\n";
      }
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      if ($element['#type'] == 'textarea') {
        $output .= '<div id="count-'.str_replace('_', '-', $element['#field_name']).'" class="word-count"></div>';
      }
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      if ($element['#type'] == 'textarea') {
        $output .= '<div id="count-'.str_replace('_', '-', $element['#field_name']).'" class="word-count"></div>';
      }
      if (!empty($element['#description'])) {
        $output .= '<div class="description">' . $element['#description'] . "</div>\n";
      }
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      if (!empty($element['#description'])) {
        $output .= '<div class="description">' . $element['#description'] . "</div>\n";
      }
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      if ($element['#type'] == 'textarea') {
        $output .= '<div id="count-'.str_replace('_', '-', $element['#field_name']).'" class="word-count"></div>';
      }
      break;
  }

  $output .= "</div>\n";

  return $output;
}
