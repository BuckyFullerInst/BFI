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
        'views-bfi_banner_images-banner' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-banner',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-bfi_banner_images-parents' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-parents',
          'region' => 'content_top',
          'weight' => '-9',
        ),
        'views-bfi_banner_images-grandparents' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-grandparents',
          'region' => 'content_top',
          'weight' => '-8',
        ),
        'views-47d40cd0e7c3396c6481198c3f1b15a5' => array(
          'module' => 'views',
          'delta' => '47d40cd0e7c3396c6481198c3f1b15a5',
          'region' => 'content_top',
          'weight' => '-7',
        ),
        'views-bfi_banner_images-attribution' => array(
          'module' => 'views',
          'delta' => 'bfi_banner_images-attribution',
          'region' => 'content_attribution',
          'weight' => '-10',
        ),
        'easy_social-easy_social_block_1' => array(
          'module' => 'easy_social',
          'delta' => 'easy_social_block_1',
          'region' => 'content_social',
          'weight' => '-9',
        ),
        'views-bfi_submenu_listing-block' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-block',
          'region' => 'content_bottom',
          'weight' => '-10',
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
        'views-bfi_sidebar_views-popular' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_architecture';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/architecture' => 'dymaxion-forum/architecture',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_arch' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_arch',
          'region' => 'content_bottom',
          'weight' => '-6',
        ),
        'views-bfi_sidebar_views-popular_arch' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_arch',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_architecture'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_art';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/art' => 'dymaxion-forum/art',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_art' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_art',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-bfi_sidebar_views-popular_art' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_art',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_art'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_design';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/design' => 'dymaxion-forum/design',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_design' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_design',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
        'views-198aa8e650f291d2f163c273e17ff7d5' => array(
          'module' => 'views',
          'delta' => '198aa8e650f291d2f163c273e17ff7d5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_design'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_engineering';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/engineering' => 'dymaxion-forum/engineering',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_eng' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_eng',
          'region' => 'content_bottom',
          'weight' => '-5',
        ),
        'views-bfi_sidebar_views-popular_eng' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_eng',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_engineering'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_science';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/science' => 'dymaxion-forum/science',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_science' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_science',
          'region' => 'content_bottom',
          'weight' => '-7',
        ),
        'views-bc51f2e94a753d35eb942cf290ac9c1c' => array(
          'module' => 'views',
          'delta' => 'bc51f2e94a753d35eb942cf290ac9c1c',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_science'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_section';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum*' => 'dymaxion-forum*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_disciplines_box-block' => array(
          'module' => 'views',
          'delta' => 'bfi_disciplines_box-block',
          'region' => 'sidebar_second',
          'weight' => '-52',
        ),
        'views-bfi_sidebar_views-postings' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-postings',
          'region' => 'sidebar_second',
          'weight' => '-51',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_section'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bfi_dymax_forum_tech';
  $context->description = '';
  $context->tag = 'dymax_forum';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dymaxion-forum/technology' => 'dymaxion-forum/technology',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-bfi_submenu_listing-df_tech' => array(
          'module' => 'views',
          'delta' => 'bfi_submenu_listing-df_tech',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-bfi_sidebar_views-popular_tech' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-popular_tech',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('dymax_forum');
  $export['bfi_dymax_forum_tech'] = $context;

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
          'weight' => '-50',
        ),
        'views-bfi_sidebar_views-store' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-store',
          'region' => 'sidebar_second',
          'weight' => '-45',
        ),
        'views-bfi_sidebar_views-block_1' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-block_1',
          'region' => 'sidebar_second',
          'weight' => '-40',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
        'views-bfi_sidebar_views-postings' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-postings',
          'region' => 'sidebar_second',
          'weight' => '-30',
        ),
        'views-bfi_sidebar_views-updates' => array(
          'module' => 'views',
          'delta' => 'bfi_sidebar_views-updates',
          'region' => 'sidebar_second',
          'weight' => '-25',
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
  $context->reactions = array();
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
        'views--exp-bfi_general_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-bfi_general_search-page',
          'region' => 'header',
          'weight' => '-9',
        ),
        'nice_menus-1' => array(
          'module' => 'nice_menus',
          'delta' => '1',
          'region' => 'header',
          'weight' => '-8',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_second',
          'weight' => '-50',
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
        'views-8f81a8316fbe675060caeac6459fd097' => array(
          'module' => 'views',
          'delta' => '8f81a8316fbe675060caeac6459fd097',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-bfi_trimtab_sections-trends' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-trends',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-bfi_trimtab_sections-resources' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-resources',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-bfi_trimtab_sections-events' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_sections-events',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-bfi_trimtab_item_order-block_1' => array(
          'module' => 'views',
          'delta' => 'bfi_trimtab_item_order-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-1030ffb2b32d54d5f5df812c53dedbd7' => array(
          'module' => 'views',
          'delta' => '1030ffb2b32d54d5f5df812c53dedbd7',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-cf4317e48216ab43f7701ecd5b693678' => array(
          'module' => 'views',
          'delta' => 'cf4317e48216ab43f7701ecd5b693678',
          'region' => 'sidebar_second',
          'weight' => '-8',
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
