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

<table id="footer" width ="600" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
    <td>
    
      This email is sent from:<br /><br />
      The Buckminster Fuller Institute
      {domain.address} p 718 290 9280 | f 718 290 9281 | <a href="http://bfi.org">bfi.org</a> | <a href="mailto:contact@bfi.org">contact@bfi.org</a><br /><br />

      To unsubscribe from this email list, <a href="{action.unsubscribeUrl}">click here</a>.<br />
      To never receive email from The Buckminster Fuller Institute, <a href="{action.optOutUrl}">click here</a>.

    </td>
  </tr>
</table>
