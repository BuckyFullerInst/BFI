<?php /* Smarty version 2.6.27, created on 2014-02-13 12:31:48
         compiled from CRM/Mailing/Form/Component.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Mailing/Form/Component.tpl', 1, false),array('block', 'ts', 'CRM/Mailing/Form/Component.tpl', 28, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><div class="crm-block crm-form-block crm-mailing-component-form-block">
<fieldset><legend><?php if ($this->_tpl_vars['action'] == 1): ?><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>New Mailing Component<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?><?php else: ?><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Edit Mailing Component<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?><?php endif; ?></legend>
  <table class="form-layout">
    <tr class="crm-mailing-component-form-block-name"><td class="label"><?php echo $this->_tpl_vars['form']['name']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['name']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-component_type"><td class="label"><?php echo $this->_tpl_vars['form']['component_type']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['component_type']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-subject"><td class="label"><?php echo $this->_tpl_vars['form']['subject']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['subject']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-body_text"><td class="label"><?php echo $this->_tpl_vars['form']['body_text']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['body_text']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-body_html"><td class="label"><?php echo $this->_tpl_vars['form']['body_html']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['body_html']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-is_default"><td class="label"><?php echo $this->_tpl_vars['form']['is_default']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['is_default']['html']; ?>
</td>
    <tr class="crm-mailing-component-form-block-is_active"><td class="label"><?php echo $this->_tpl_vars['form']['is_active']['label']; ?>
</td><td><?php echo $this->_tpl_vars['form']['is_active']['html']; ?>
</td>
  </table>
</fieldset>
<div class="crm-submit-buttons"><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?></div>
</div>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>