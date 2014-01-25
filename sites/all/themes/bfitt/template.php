<?php

/**
 * Process variables to format email messages.
 *
 * @see htmlmail.tpl.php
 */
function bfitt_preprocess_htmlmail(&$variables) {
  // Run the default preprocess function.
  template_preprocess_htmlmail($variables);

  // Use the 'HTML Email' text format for the message body.
  $variables['body'] = check_markup($variables['body'], 'html_email');
}
