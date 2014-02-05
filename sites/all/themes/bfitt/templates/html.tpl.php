<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?>
<html lang="en">
	<head>

	<!--	<link href="<?php echo $base_url.'/'.drupal_get_path('theme', 'bfitt'); ?>/styles/email-style.css" rel="stylesheet" type="text/css" /> 	-->
		<style type="text/css">
			body { font-family: DIN, "Helvetica Neue", Helvetica, Arial, sans-serif; }
			table {
				border-spacing: 0;
				border-collapse: collapse;
			}
			table tr, table td {
				margin: 0;
				padding: 0;
				vertical-align: top;
			}
			p, h1, h2, h3, h4, h5, h6 {
				margin: 0;
				padding: 0;
			}
			#header, #page, #footer {
				width: 600px;
			}

			h2.block-title {
				padding: 10px 0;
				border-bottom: 2px solid #F0F0F0;
				margin-bottom: 20px;
			}
			table.views-view-grid td.col-1 { padding-right: 20px; }
			table.views-view-grid td { padding-bottom: 20px; }

			#block-views-bfi-sidebar-views-popular-2 { display: none; }

			table#block-views-bfi-trimtab-email-block-5 { float: left; width: 300px; }
			table#block-views-bfi-trimtab-email-block-5 table.views-view-grid td.col-1 { padding-right: 10px; }

			table#block-views-bfi-trimtab-email-block-6 { float: right; width: 300px; }
			table#block-views-bfi-trimtab-email-block-6 table.views-view-grid td.col-1 { padding-left: 10px; padding-right: 0; }

		</style>

		<?php print $head; ?>
		<title><?php print $head_title; ?></title>

	</head>

	<body>
  
		<?php print $page; ?>

	</body>
</html>
