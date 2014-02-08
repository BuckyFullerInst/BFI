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
global $base_path, $base_url;
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

			a {
				color: #EB3F24;
				text-decoration: none;
			}

			h2.block-title {
				padding: 10px 0;
				border-bottom: 2px solid #F0F0F0;
				margin-bottom: 20px;
			}

			.tagline {
				font-size: 12px;
				color: #777;
				font-style: italic;
				text-align: center;
			}

			#block-views-bfi-sidebar-views-popular-2 { display: none; }

			#block-views-bfi-banner-images-b-tt-e .views-row { margin-bottom: 20px; }
			#block-views-bfi-banner-images-b-tt-e .views-row img { margin-bottom: 8px; }
			.tagline a { color: black; }
			//.tagline a:hover { color: #777; }


			.view-bfi-trimtab-email table.views-view-grid td.col-1 { border-right: 20px solid white; }
			.view-bfi-trimtab-email table.views-view-grid td { background-color: #F0F0F0; border-bottom: 20px solid white; }
			.view-bfi-trimtab-email .content { width: 290px;  }
			.view-bfi-trimtab-email .content-desc { padding: 20px; }
			.view-bfi-trimtab-email .content-desc a {
				color: black;
				text-transform: uppercase;
				font-size: 12px;
				margin-top: 10px;
			}
			.view-bfi-trimtab-email .content-desc p {
				padding-top: 10px;
				font-size: 14px;
			}

			.view-bfi-trimtab-email-head .view-content > td { padding: 10px 0 20px; }
			.view-bfi-trimtab-email-head table.views-view-grid td {
				width: 600px;
				padding: 0 0 10px 0;
				border-bottom: 2px solid #F0F0F0;
			}

			#block-views-bfi-trimtab-email-head-idin,
			#block-views-bfi-trimtab-email-idin { width: 290px; float: left; clear: both; }
			#block-views-bfi-trimtab-email-idin td { border-right: 0; }

			#block-views-bfi-trimtab-email-head-store,
			#block-views-bfi-trimtab-email-store { width: 290px; float: right; }
			#block-views-bfi-trimtab-email-store td { border-right: 0; }

			#block-views-bfi-trimtab-email-page-link table.views-view-grid td {
				background-color: transparent;
				border-bottom: 0;
				padding: 10px 0;
				font-size: 12px;
				font-style: italic;
			}

			#block-views-bfi-trimtab-email-head-trimtab table.views-view-grid td {
				text-align: center;
				border-bottom: 0;
				padding: 20px 0 14px;
			}

			#block-views-bfi-banner-images-tt-email-top { width: 600px; }

			#block-views-bfi-banner-images-tt-email-top table.views-view-grid tr {
				position: relative;
				width: 600px;
			}

			#block-views-bfi-banner-images-tt-email-top table.views-view-grid td {
				font-size: 12px;
				color: #777;
				font-style: italic;
				width: 600px;
				text-align: center;
				position: absolute;
				top: 130px;
				padding: 0 180px;
				z-index: 10;
			}

			#block-views-bfi-banner-images-tt-email-top table.views-view-grid td p {
				text-align: center;
				padding: 0 20px 17px;
				width: 200px;
				background-color: white;
			}

			#footer td {
				font-size: 11px;
				background-color: #F0F0F0;
				color: #000;
				padding: 1em;
				margin-top: 2em;
			}

		</style>

		<?php print $head; ?>
		<title><?php print $head_title; ?></title>

	</head>

	<body>
  
		<?php print $page; ?>

	</body>
</html>
