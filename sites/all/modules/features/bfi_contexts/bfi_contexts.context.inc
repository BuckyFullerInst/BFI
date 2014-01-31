<?php
/**
 * @file
 * bfi_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bfi_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfc_application_form';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'challenge/apply' => 'challenge/apply',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-fc58129dab47746eaf01d16ae51c7e6d' => array(
          'module' => 'views',
          'delta' => 'fc58129dab47746eaf01d16ae51c7e6d',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['bfc_application_form'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfc_cycle_year_selector';
  $context->description = '';
  $context->tag = 'challenge';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
    'domain' => array(
      'values' => array(
        2 => 2,
      ),
    ),
    'path' => array(
      'values' => array(
        'year/*' => 'year/*',
        '~year/*/projects/*' => '~year/*/projects/*',
        'node/*/projects' => 'node/*/projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfc_project_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'bfc_project_listing-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('challenge');
  $export['bfc_cycle_year_selector'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfc_project_review_bfc_admin';
  $context->description = 'For supplying project-related material for Reviewers';
  $context->tag = 'challenge';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'bfc admin' => 'bfc admin',
        'superadmin' => 'superadmin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7f914fe777df77812bb293c8af6bbea0' => array(
          'module' => 'views',
          'delta' => '7f914fe777df77812bb293c8af6bbea0',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-af0e4b467db63818d88bb95349665e55' => array(
          'module' => 'views',
          'delta' => 'af0e4b467db63818d88bb95349665e55',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-8d6fb823ca6881b691504a151363c038' => array(
          'module' => 'views',
          'delta' => '8d6fb823ca6881b691504a151363c038',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-bfc_project_review_notes-jury' => array(
          'module' => 'views',
          'delta' => 'bfc_project_review_notes-jury',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-f1a838a0ad5986fef938812d5e72dc47' => array(
          'module' => 'views',
          'delta' => 'f1a838a0ad5986fef938812d5e72dc47',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-33c0fed31daf9ea008f82ba69c06f1ce' => array(
          'module' => 'views',
          'delta' => '33c0fed31daf9ea008f82ba69c06f1ce',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-540cdf1f12655653694f808c7352a534' => array(
          'module' => 'views',
          'delta' => '540cdf1f12655653694f808c7352a534',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-248d3e28de469f98fc57c69ee7cc318f' => array(
          'module' => 'views',
          'delta' => '248d3e28de469f98fc57c69ee7cc318f',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-d7f7aa5b42d25dc3e2f90220ee23c9b3' => array(
          'module' => 'views',
          'delta' => 'd7f7aa5b42d25dc3e2f90220ee23c9b3',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For supplying project-related material for Reviewers');
  t('challenge');
  $export['bfc_project_review_bfc_admin'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfc_project_review_jurors';
  $context->description = 'For supplying project-related material for Non-Reviewers';
  $context->tag = 'challenge';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'bfc juror' => 'bfc juror',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7f914fe777df77812bb293c8af6bbea0' => array(
          'module' => 'views',
          'delta' => '7f914fe777df77812bb293c8af6bbea0',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-af0e4b467db63818d88bb95349665e55' => array(
          'module' => 'views',
          'delta' => 'af0e4b467db63818d88bb95349665e55',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-8d6fb823ca6881b691504a151363c038' => array(
          'module' => 'views',
          'delta' => '8d6fb823ca6881b691504a151363c038',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-bfc_project_review_notes-jury' => array(
          'module' => 'views',
          'delta' => 'bfc_project_review_notes-jury',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-f1a838a0ad5986fef938812d5e72dc47' => array(
          'module' => 'views',
          'delta' => 'f1a838a0ad5986fef938812d5e72dc47',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-f4b773ea3cb1d603e2d6e56113f183ae' => array(
          'module' => 'views',
          'delta' => 'f4b773ea3cb1d603e2d6e56113f183ae',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-bb0bdc09f84fa6762a0fffee0e07607f' => array(
          'module' => 'views',
          'delta' => 'bb0bdc09f84fa6762a0fffee0e07607f',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-967808a84516d23bc12cbc6ae3c3ea36' => array(
          'module' => 'views',
          'delta' => '967808a84516d23bc12cbc6ae3c3ea36',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-d7f7aa5b42d25dc3e2f90220ee23c9b3' => array(
          'module' => 'views',
          'delta' => 'd7f7aa5b42d25dc3e2f90220ee23c9b3',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For supplying project-related material for Non-Reviewers');
  t('challenge');
  $export['bfc_project_review_jurors'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfc_project_review_reviewers';
  $context->description = 'For supplying project-related material for Reviewers';
  $context->tag = 'challenge';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'bfc review team' => 'bfc review team',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7f914fe777df77812bb293c8af6bbea0' => array(
          'module' => 'views',
          'delta' => '7f914fe777df77812bb293c8af6bbea0',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-af0e4b467db63818d88bb95349665e55' => array(
          'module' => 'views',
          'delta' => 'af0e4b467db63818d88bb95349665e55',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-8d6fb823ca6881b691504a151363c038' => array(
          'module' => 'views',
          'delta' => '8d6fb823ca6881b691504a151363c038',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-bfc_project_review_notes-jury' => array(
          'module' => 'views',
          'delta' => 'bfc_project_review_notes-jury',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-f1a838a0ad5986fef938812d5e72dc47' => array(
          'module' => 'views',
          'delta' => 'f1a838a0ad5986fef938812d5e72dc47',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-f4b773ea3cb1d603e2d6e56113f183ae' => array(
          'module' => 'views',
          'delta' => 'f4b773ea3cb1d603e2d6e56113f183ae',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-bb0bdc09f84fa6762a0fffee0e07607f' => array(
          'module' => 'views',
          'delta' => 'bb0bdc09f84fa6762a0fffee0e07607f',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-248d3e28de469f98fc57c69ee7cc318f' => array(
          'module' => 'views',
          'delta' => '248d3e28de469f98fc57c69ee7cc318f',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-d7f7aa5b42d25dc3e2f90220ee23c9b3' => array(
          'module' => 'views',
          'delta' => 'd7f7aa5b42d25dc3e2f90220ee23c9b3',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For supplying project-related material for Reviewers');
  t('challenge');
  $export['bfc_project_review_reviewers'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_content_meta';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'blog_post' => 'blog_post',
        'newsletter' => 'newsletter',
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_attribution-block' => array(
          'module' => 'views',
          'delta' => 'bfi_attribution-block',
          'region' => 'content_attribution',
          'weight' => '-10',
        ),
        'views-bfi_banner_images-attribution' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-attribution',
          'region' => 'content_attribution',
          'weight' => '-9',
        ),
        'views-bfi_submenu_listing-block' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block',
          'region' => 'content_bottom',
          'weight' => '66',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['bfi_content_meta'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
    'path' => array(
      'values' => array(
        'dymaxion-forum' => 'dymaxion-forum',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-bfi_sidebar_views-popular_df' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_df',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_front';
  $context->description = 'Stuff for front page';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'front' => 'front',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_front_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'bfi_front_slideshow-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-bfi_front_slideshow-bfi_up' => array(
          'module' => 'views',
          'delta' => 'bfi_front_slideshow-bfi_up',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-bfi_front_slideshow-bfi_supp' => array(
          'module' => 'views',
          'delta' => 'bfi_front_slideshow-bfi_supp',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-bfi_front_slideshow-chall_up' => array(
          'module' => 'views',
          'delta' => 'bfi_front_slideshow-chall_up',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-bfi_front_slideshow-bfc_supp' => array(
          'module' => 'views',
          'delta' => 'bfi_front_slideshow-bfc_supp',
          'region' => 'content',
          'weight' => '-5',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '-83',
        ),
        'views-bfi_sidebar_views-store' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-store',
          'region' => 'sidebar_second',
          'weight' => '-82',
        ),
        'views-bfi_sidebar_views-block_1' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-block_1',
          'region' => 'sidebar_second',
          'weight' => '-81',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_second',
          'weight' => '-80',
        ),
        'views-bfi_sidebar_views-popular_2' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_2',
          'region' => 'sidebar_second',
          'weight' => '-79',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Stuff for front page');
  t('theme');
  $export['bfi_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_front_challenge';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'challenge' => 'challenge',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfc_landing_page-block' => array(
          'module' => 'views',
          'delta' => 'bfc_landing_page-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['bfi_front_challenge'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_logo';
  $context->description = 'BFI Logo, Top menu, static sidebar, etc. for all pages';
  $context->tag = 'theme';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfc_site_logo-block' => array(
          'module' => 'views',
          'delta' => 'bfc_site_logo-block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'header',
          'weight' => '-9',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'header',
          'weight' => '-8',
        ),
        'views--exp-bfi_general_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-bfi_general_search-page',
          'region' => 'header',
          'weight' => '-7',
        ),
        'nice_menus-1' => array(
          'module' => 'nice_menus',
          'delta' => '1',
          'region' => 'header',
          'weight' => '-6',
        ),
        'views-bfi_content_image_thumbs-block' => array(
          'module' => 'views',
          'delta' => 'bfi_content_image_thumbs-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-65',
        ),
        'menu-menu-footer-about-bfi' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-about-bfi',
          'region' => 'footer_left',
          'weight' => '-60',
        ),
        'menu-menu-footer-challenge' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-challenge',
          'region' => 'footer_left',
          'weight' => '-59',
        ),
        'menu-menu-footer-buckminster-fuller' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-buckminster-fuller',
          'region' => 'footer_left',
          'weight' => '-58',
        ),
        'menu-menu-footer-news-events' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-news-events',
          'region' => 'footer_left',
          'weight' => '-57',
        ),
        'menu-menu-footer-get-involved' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-get-involved',
          'region' => 'footer_left',
          'weight' => '-56',
        ),
        'views-bfc_site_logo-block_1' => array(
          'module' => 'views',
          'delta' => 'bfc_site_logo-block_1',
          'region' => 'footer_right',
          'weight' => '-61',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'footer_right',
          'weight' => '-60',
        ),
        'views-bfc_site_logo-footer_social' => array(
          'module' => 'views',
          'delta' => 'bfc_site_logo-footer_social',
          'region' => 'footer_right',
          'weight' => '-10',
        ),
        'views-bfi_footer_views-sponsors' => array(
          'module' => 'views',
          'delta' => 'bfi_footer_views-sponsors',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('BFI Logo, Top menu, static sidebar, etc. for all pages');
  t('theme');
  $export['bfi_logo'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_search';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_banner_images-search' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-search',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'facetapi-10Hl8auKZeWrH1ublFXu0654TABceuPZ' => array(
          'module' => 'facetapi',
          'delta' => '10Hl8auKZeWrH1ublFXu0654TABceuPZ',
          'region' => 'sidebar_second',
          'weight' => '-64',
        ),
        'facetapi-9Hzyc6IjVP3DID7o1IyJCcTRq9N0PRF0' => array(
          'module' => 'facetapi',
          'delta' => '9Hzyc6IjVP3DID7o1IyJCcTRq9N0PRF0',
          'region' => 'sidebar_second',
          'weight' => '-63',
        ),
        'facetapi-GXSffu3DMd0t2i7f6aRYUlalKl1G6dWL' => array(
          'module' => 'facetapi',
          'delta' => 'GXSffu3DMd0t2i7f6aRYUlalKl1G6dWL',
          'region' => 'sidebar_second',
          'weight' => '-62',
        ),
        'facetapi-DqZH4dk34xji1vZuZl6PRJWdN2RAtLiX' => array(
          'module' => 'facetapi',
          'delta' => 'DqZH4dk34xji1vZuZl6PRJWdN2RAtLiX',
          'region' => 'sidebar_second',
          'weight' => '-61',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['bfi_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_trimtab';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'trimtab' => 'trimtab',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-block_2' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block_2',
          'region' => 'content_bottom',
          'weight' => '-48',
        ),
        'views-bfi_submenu_listing-block' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block',
          'region' => 'content_bottom',
          'weight' => '-47',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['bfi_trimtab'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_trimtab_email';
  $context->description = 'For applying custom theme to email version of trimtab';
  $context->tag = 'trimtab';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/email' => 'node/*/email',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_trimtab_email-block_1' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-bfi_trimtab_email-block_2' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_2',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-bfi_trimtab_email-block_3' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_3',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'views-bfi_trimtab_email-block_4' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_4',
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'views-bfi_trimtab_email-block_5' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-bfi_trimtab_email-block_6' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_email-block_6',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-490233f35cc56f95ed44506677503753' => array(
          'module' => 'views',
          'delta' => '490233f35cc56f95ed44506677503753',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('For applying custom theme to email version of trimtab');
  t('trimtab');
  $export['bfi_trimtab_email'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_trimtab_sections';
  $context->description = '';
  $context->tag = 'trimtab';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'newsletter' => 'newsletter',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-17df2e3d3ee2445b994727a727a501f3' => array(
          'module' => 'views',
          'delta' => '17df2e3d3ee2445b994727a727a501f3',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-43bf4275ebf9289d7821508ee5126c60' => array(
          'module' => 'views',
          'delta' => '43bf4275ebf9289d7821508ee5126c60',
          'region' => 'content_top',
          'weight' => '-9',
        ),
        'views-bfi_trimtab_sections-updates' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-updates',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-bfi_trimtab_sections-trends' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-trends',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-bfi_trimtab_sections-resources' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-resources',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'views-bfi_trimtab_sections-events' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-events',
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'views-bfi_trimtab_sections-project' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-project',
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'views-bfi_trimtab_sections-store' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-store',
          'region' => 'content_bottom',
          'weight' => '-5',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'content_bottom',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('trimtab');
  $export['bfi_trimtab_sections'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_updates';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-bfi/updates' => 'about-bfi/updates',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-updates' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-updates',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-bfi_sidebar_views-updates_note' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-updates_note',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['bfi_updates'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'testing';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'testing' => 'testing',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-bfi_submenu_listing-block' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['testing'] = $context;

  return $export;
}
