/*
 * ##### Sasson - advanced drupal theming. #####
 *
 * SITENAME scripts.
 *
 */

(function($) {
  
  // DUPLICATE AND UNCOMMENT
  // Drupal.behaviors.behaviorName = {
  //   attach: function (context, settings) {
  //     // Do some magic...
  //   }
  // };

	Drupal.behaviors.behaviorName = {
		attach: function (context, settings) {
			$('body.page-node-93 #block-views-bfc-landing-page-block td:not(:has(div))').css('background-color', 'transparent');
			$('body.node-type-newsletter .view-bfi-trimtab-sections td:not(:has(div))').css('background-color', 'transparent');
		}
	};

})(jQuery);
