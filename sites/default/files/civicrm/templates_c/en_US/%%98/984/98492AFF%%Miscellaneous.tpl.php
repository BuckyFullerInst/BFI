<?php /* Smarty version 2.6.27, created on 2014-02-13 12:05:35
         compiled from CRM/Admin/Form/Setting/Miscellaneous.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Admin/Form/Setting/Miscellaneous.tpl', 1, false),array('block', 'ts', 'CRM/Admin/Form/Setting/Miscellaneous.tpl', 32, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><div class="crm-block crm-form-block crm-miscellaneous-form-block">
  <div class="crm-submit-buttons"><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'top')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?></div>
    <table class="form-layout">
        <tr class="crm-miscellaneous-form-block-dashboardCacheTimeout">
            <td class="label"><?php echo $this->_tpl_vars['form']['dashboardCacheTimeout']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['dashboardCacheTimeout']['html']; ?>
<br />
                <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>The number of minutes to cache dashlet content on dashboard.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
        </tr>
    </table>

    <table class="form-layout">
        <tr class="crm-miscellaneous-form-block-checksumTimeout">
            <td class="label"><?php echo $this->_tpl_vars['form']['checksumTimeout']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['checksumTimeout']['html']; ?>
<br />
                <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>The number of days before a personalized (hashed) link will expire.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
        </tr>
    </table>

    <table class="form-layout">
        <tr class="crm-miscellaneous-form-block-contact_undelete">
          <td class="label"><?php echo $this->_tpl_vars['form']['contact_undelete']['label']; ?>
</td>
          <td>
            <?php echo $this->_tpl_vars['form']['contact_undelete']['html']; ?>
<br />
            <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><?php echo $this->_tpl_vars['contact_undelete_description']; ?>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
          </td>
        </tr>
        <tr class="crm-miscellaneous-form-block-logging">
          <td class="label"><?php echo $this->_tpl_vars['form']['logging']['label']; ?>
</td>
          <td>
            <?php echo $this->_tpl_vars['form']['logging']['html']; ?>
<br />
          <?php if ($this->_tpl_vars['validTriggerPermission']): ?>
            <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>If enabled, all actions performed on non-cache tables will be logged (in the respective log_* tables).<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
            <div class="status message"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Logging functionality is currently in beta. Please test this feature on a copy of your database prior to using it on a production site.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></div>
          <?php else: ?>
            <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>In order to use this functionality, the installation's database user must have privileges to create triggers (in MySQL 5.0 – and in MySQL 5.1 if binary logging is enabled – this means the SUPER privilege). This install either does not seem to have the required privilege enabled.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>&nbsp;<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>This functionality cannot be enabled on multilingual installations.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
           <?php endif; ?>
          </td>
        </tr>
        <tr class="crm-miscellaneous-form-block-doNotAttachPDFReceipt">
            <td class="label"><?php echo $this->_tpl_vars['form']['doNotAttachPDFReceipt']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['doNotAttachPDFReceipt']['html']; ?>
<br />
                <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>If enabled, CiviCRM sends PDF receipt as an attachment during event signup or online contribution.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
            </td>
        </tr>
        <tr class="crm-miscellaneous-form-block-wkhtmltopdfPath">
            <td class="label"><?php echo $this->_tpl_vars['form']['wkhtmltopdfPath']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['wkhtmltopdfPath']['html']; ?>
<br />
                <p class="description"><?php $this->_tag_stack[] = array('ts', array('1' => "http://code.google.com/p/wkhtmltopdf/")); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><a href="%1">wkhtmltopdf is an alternative utility for generating PDF's</a> which may provide better performance especially if you are generating a large number of PDF letters or receipts. Your system administrator will need to download and install this utility, and enter the executable path here.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
            </td>
        </tr>
        <tr class="crm-miscellaneous-form-block-versionAlert">
            <td class="label"><?php echo $this->_tpl_vars['form']['versionAlert']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['versionAlert']['html']; ?>
<br />
                <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Displays an on-screen alert to users with "Administer CiviCRM" permissions when a new version of CiviCRM is available. This setting will only work if the "Version Check &amp; Statistics Reporting" setting is enabled.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p></td>
        </tr>
        <tr class="crm-miscellaneous-form-block-versionCheck">
            <td class="label"><?php echo $this->_tpl_vars['form']['versionCheck']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['versionCheck']['html']; ?>
<br />
                <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>When enabled, statistics about your CiviCRM installation are reported anonymously to the CiviCRM team to assist in prioritizing ongoing development efforts. The following information is gathered: CiviCRM version, versions of PHP, MySQL and framework (Drupal/Joomla/standalone), and default language. Counts (but no actual data) of the following record types are reported: contacts, activities, cases, relationships, contributions, contribution pages, contribution products, contribution widgets, discounts, price sets, profiles, events, participants, tell-a-friend pages, grants, mailings, memberships, membership blocks, pledges, pledge blocks and active payment processor types.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p></td>
        </tr>
        <tr class="crm-miscellaneous-form-block-max_attachments">
            <td class="label"><?php echo $this->_tpl_vars['form']['max_attachments']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['max_attachments']['html']; ?>
<br />
                <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Maximum number of files (documents, images, etc.) which can attached to emails or activities.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
        </tr>
  <tr class="crm-miscellaneous-form-block-maxFileSize">
      <td class="label"><?php echo $this->_tpl_vars['form']['maxFileSize']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['maxFileSize']['html']; ?>
<br />
                <span class="description"><?php echo $this->_tpl_vars['maxFileSize_description']; ?>
</span></td>
        </tr>
        <tr class="crm-miscellaneous-form-block-secondDegRelPermissions">
            <td class="label"><?php echo $this->_tpl_vars['form']['secondDegRelPermissions']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['secondDegRelPermissions']['html']; ?>
<br />
                <p class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>If enabled, contacts with the permission to edit a related contact will inherit that contact's permission to edit other related contacts.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></p>
            </td>
        </tr>
    </table>
<h3><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>reCAPTCHA Keys<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></h3>
    <div class="description">
        <?php $this->_tag_stack[] = array('ts', array('1' => "https://www.google.com/recaptcha")); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>reCAPTCHA is a free service that helps prevent automated abuse of your site. To use reCAPTCHA on public-facing CiviCRM forms: sign up at <a href="%1" "target=_blank">Google's reCaptcha site</a>; enter the provided public and private reCAPTCHA keys here; then enable reCAPTCHA under Advanced Settings in any Profile.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>
    </div>
    <table class="form-layout">
        <tr class="crm-miscellaneous-form-block-recaptchaPublicKey">
            <td class="label"><?php echo $this->_tpl_vars['form']['recaptchaPublicKey']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['recaptchaPublicKey']['html']; ?>
</td>
        </tr>
        <tr class="crm-miscellaneous-form-block-recaptchaPrivateKey">
            <td class="label"><?php echo $this->_tpl_vars['form']['recaptchaPrivateKey']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['recaptchaPrivateKey']['html']; ?>
</td>
        </tr>
        <tr class="crm-miscellaneous-form-block-recaptchaOptions">
            <td class="label"><?php echo $this->_tpl_vars['form']['recaptchaOptions']['label']; ?>
</td>
            <td><?php echo $this->_tpl_vars['form']['recaptchaOptions']['html']; ?>
<br />
                <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>You can specify the reCAPTCHA theme options as an comma seperated data.(eg: theme:'blackglass', lang : 'fr' ).<br />You can check the available options for reCAPTCHA here <a href="http://code.google.com/apis/recaptcha/docs/customization.html" "target=_blank">Customizing the Look and Feel of reCAPTCHA</a>.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
        </tr>
        </table>
           <div class="crm-submit-buttons"><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'bottom')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?></div>
</div>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>