<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<table class="<?php print $classes; ?>">

  <?php if ($title): ?>
    <tr>
      <td>
        <?php print $title; ?>
      </td>
    </tr>
  <?php endif; ?>

  <?php if ($header): ?>
    <tr class="view-header">
      <td>
        <?php print $header; ?>
      </td>
    </tr>
  <?php endif; ?>

  <?php if ($rows): ?>
    <tr class="view-content">
      <td>
        <?php print $rows; ?>
      <td>
    </tr>
  <?php elseif ($empty): ?>
    <tr class="view-empty">
      <td>
        <?php print $empty; ?>
      </td>
    </tr>
  <?php endif; ?>

  <?php if ($footer): ?>
    <tr class="view-footer">
      <td>
        <?php print $footer; ?>
      </td>
    </tr>
  <?php endif; ?>

</table><?php /* class view */ ?>
