<?php /* Smarty version 2.6.27, created on 2014-02-13 12:01:48
         compiled from CRM/Core/I18n/Dialog.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Core/I18n/Dialog.tpl', 1, false),array('modifier', 'count', 'CRM/Core/I18n/Dialog.tpl', 26, false),array('function', 'crmURL', 'CRM/Core/I18n/Dialog.tpl', 27, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><?php if (count($this->_tpl_vars['config']->languageLimit) >= 2 && $this->_tpl_vars['translatePermission']): ?>
<a href="#" onclick="loadDialog('<?php echo CRM_Utils_System::crmURL(array('p' => 'civicrm/i18n','q' => "reset=1&table=".($this->_tpl_vars['table'])."&field=".($this->_tpl_vars['field'])."&id=".($this->_tpl_vars['id'])."&snippet=1&context=dialog",'h' => 0), $this);?>
', '<?php echo $this->_tpl_vars['field']; ?>
'); return false;"><img src="<?php echo $this->_tpl_vars['config']->resourceBase; ?>
i/langs.png" /></a><div id="locale-dialog_<?php echo $this->_tpl_vars['field']; ?>
" style="display:none"></div>

<?php echo '
<script type="text/javascript">
function loadDialog( url, fieldName ) {
 cj.ajax({
         url: url,
         success: function( content ) {
             cj("#locale-dialog_" +fieldName ).show( ).html( content ).dialog({
                 modal       : true,
      width       : 290,
      height      : 290,
      resizable   : true,
      bgiframe    : true,
      overlay     : { opacity: 0.5, background: "black" },
      beforeclose : function(event, ui) {
                     cj(this).dialog("destroy");
                       }
             });
         }
      });
}
</script>
'; ?>

<?php endif; ?>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>