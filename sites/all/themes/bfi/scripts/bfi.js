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

			$('#edit-field-application-questions-und-0-field-project-app-strategy-und-0-value')
				.counter({ type: 'word', goal: 50, append: false,
					target: '#count-field-project-app-strategy'
				});

			$('#edit-field-application-questions-und-0-field-project-app-context-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-context'
				});

			$('#edit-field-application-questions-und-0-field-project-app-3w-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-3w'
				});

			$('#edit-field-application-questions-und-0-field-project-app-impact-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-impact'
				});

			$('#edit-field-application-questions-und-0-field-project-app-impact-long-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-impact-long'
				});

			$('#edit-field-application-questions-und-0-field-project-app-history-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-history'
				});

			$('#edit-field-application-questions-und-0-field-project-app-planning-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-planning'
				});

			$('#edit-field-application-questions-und-0-field-project-app-community-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-community'
				});

			$('#edit-field-application-questions-und-0-field-project-app-team-und-0-value')
				.counter({ type: 'word', goal: 200, append: false,
					target: '#count-field-project-app-team'
				});

			// $("#block-menu-block-2").stick_in_parent();
		}
	};

})(jQuery);
