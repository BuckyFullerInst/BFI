<table id="header" width="600" align="center">
  <tr>
    <td>

      <?php if ($page['header']): ?>
        <?php print render($page['header']); ?>
      <?php endif; ?>

      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>

    </td>
  </tr>
</table>

<table id="page" width="600" align="center">
  <tr>

    <?php if ($page['sidebar_first']): ?>
      <td width="25%" valign="top">
        <?php print render($page['sidebar_first']); ?>
      </td>
    <?php endif; ?>


    <td width="75%">
      <table id="main">
        <tr>
          <td>

        <?php print render($page['content_bottom']); ?>

          </td>
        </tr>
      </table><!-- /#main -->
    </td>

    <?php if ($page['sidebar_second']): ?>
      <td width="25%" valign="top">
        <?php print render($page['sidebar_second']); ?>
      </td>
    <?php endif; ?>


  </tr>
</table><!-- /#page -->

<table id="footer" width="600" align="center">
  <tr>
    <td>
      <?php if ($page['footer']): ?>
        <?php print render($page['footer']); ?>
      <?php endif; ?>
    </td>
  </tr>
</table>
