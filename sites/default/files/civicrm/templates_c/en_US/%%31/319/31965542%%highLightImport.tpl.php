<?php /* Smarty version 2.6.27, created on 2014-02-13 15:13:35
         compiled from CRM/common/highLightImport.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/common/highLightImport.tpl', 1, false),array('modifier', 'implode', 'CRM/common/highLightImport.tpl', 29, false),array('modifier', 'json_encode', 'CRM/common/highLightImport.tpl', 34, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><?php echo '
cj(function($) {
  var highlightedFields = ["'; ?>
<?php echo ((is_array($_tmp='","')) ? $this->_run_mod_handler('implode', true, $_tmp, $this->_tpl_vars['highlightedFields']) : implode($_tmp, $this->_tpl_vars['highlightedFields'])); ?>
<?php echo '"];
  $.each(highlightedFields, function() {
    $(\'select[id^="mapper"][id$="_0"] option[value=\'+ this + \']\').append(\' *\').css({"color":"#FF0000"});
  });
  '; ?>
<?php if ($this->_tpl_vars['relationship']): ?><?php echo '
  var highlightedRelFields = '; ?>
<?php echo json_encode($this->_tpl_vars['highlightedRelFields']); ?>
<?php echo ';
  function highlight() {
    var select, fields = highlightedRelFields[$(this).val()];
    if (fields) {
      select = $(this).next();
      $.each(fields, function() {
        $(\'option[value=\'+ this + \']\', select).append(\' *\').css({"color":"#FF0000"});
      });
    }
  }
  $(\'select[id^="mapper"][id$="_0"]\').each(highlight).click(highlight);
  '; ?>
<?php endif; ?><?php echo '
});
'; ?>

<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>