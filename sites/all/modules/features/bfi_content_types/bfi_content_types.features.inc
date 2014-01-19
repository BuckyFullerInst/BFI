<?php
/**
 * @file
 * bfi_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bfi_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bfi_content_types_node_info() {
  $items = array(
    'admin_input' => array(
      'name' => t('Admin Input'),
      'base' => 'node_content',
      'description' => t('Solely admin content type to hold reusable bits of content across applications'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('BFI Update'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like BFI Operations-centric news, updates, press releases, etc. Blog posts should be under the Dymaxion Forum Post content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'bfc_cycle' => array(
      'name' => t('BFC Cycle'),
      'base' => 'node_content',
      'description' => t('Content type for managing overall status and process of BF Challenge cycle. Admin-side only'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'bfc_fee_payment_page' => array(
      'name' => t('BFC Fee Payment Page'),
      'base' => 'node_content',
      'description' => t('Content type for holding fee payment form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog_post' => array(
      'name' => t('Dymaxion Forum Post'),
      'base' => 'node_content',
      'description' => t('Use <i>blog posts</i> specifically for blog postings (i.e. Dymaxion Forum, etc.) This will eventually be replicated across Facebook and Twitter, so keep it snappy.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'literature_source' => array(
      'name' => t('Literature Source'),
      'base' => 'node_content',
      'description' => t('Use the <i>source</i> type for any kind of publication: books, periodicals, forwards, etc... anything that\'s in print (or digital, for that matter)!'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'newsletter' => array(
      'name' => t('Trimtab Issue'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Static Page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Holder for all <i>person</i>-related content, i.e. Staff, Board, Authors, Users, etc. This is in NO WAY linked to Drupal Core user system.'),
      'has_title' => '1',
      'title_label' => t('Person'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('BFC Project'),
      'base' => 'node_content',
      'description' => t('This is the main upstream content type for holding all BF Challenge Project-related data. All other displays of Challenge and Idea Index content flow downhill from here.'),
      'has_title' => '1',
      'title_label' => t('Project Name'),
      'help' => '',
    ),
    'site_image' => array(
      'name' => t('Site Image'),
      'base' => 'node_content',
      'description' => t('ONLY for Admins to include images into site, without having to associate with pre-existing content item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
