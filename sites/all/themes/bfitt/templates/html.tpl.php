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
			table {
				border-spacing: 0;
				border-collapse: collapse;
			}
			table tr, table td {
				margin: 0;
				padding: 0;
			}
			p, h1, h2, h3, h4, h5, h6 {
				margin: 0;
				padding: 0;
			}
			#header, #page, #footer {
				width: 600px;
			}
		</style>

		<?php print $head; ?>
		<title><?php print $head_title; ?></title>

	</head>

	<body>
  
		<?php print $page; ?>

	</body>
</html>
