<?php /* Smarty version 2.6.27, created on 2014-02-13 17:15:53
         compiled from CRM/Contact/Page/DedupeFind.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Contact/Page/DedupeFind.tpl', 1, false),array('block', 'ts', 'CRM/Contact/Page/DedupeFind.tpl', 30, false),array('function', 'crmURL', 'CRM/Contact/Page/DedupeFind.tpl', 39, false),array('function', 'cycle', 'CRM/Contact/Page/DedupeFind.tpl', 41, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><?php if ($this->_tpl_vars['action'] == 2 || $this->_tpl_vars['action'] == 16): ?>
<div class="form-item">
  <table class='pagerDisplay'>
    <thead>
    <tr class="columnheader"><th id="nosort"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Contact<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> 1</th><th id="nosort"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Contact<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> 2 (<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Duplicate<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>)</th><th id="nosort"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Threshold<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></th><th id="nosort">&nbsp;</th></tr>
    </thead>
  </table>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/jsortable.tpl", 'smarty_include_vars' => array('sourceUrl' => $this->_tpl_vars['sourceUrl'],'useAjax' => 1)));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php if ($this->_tpl_vars['cid']): ?>
    <table style="width: 45%; float: left; margin: 10px;">
      <tr class="columnheader"><th colspan="2"><?php $this->_tag_stack[] = array('ts', array('1' => $this->_tpl_vars['main_contacts'][$this->_tpl_vars['cid']])); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Merge %1 with<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></th></tr>
      <?php $_from = $this->_tpl_vars['dupe_contacts'][$this->_tpl_vars['cid']]; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['dupe_id'] => $this->_tpl_vars['dupe_name']):
?>
        <?php if ($this->_tpl_vars['dupe_name']): ?>
          <?php ob_start(); ?><a href="<?php echo CRM_Utils_System::crmURL(array('p' => 'civicrm/contact/view','q' => "reset=1&cid=".($this->_tpl_vars['dupe_id'])), $this);?>
"><?php echo $this->_tpl_vars['dupe_name']; ?>
</a><?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('link', ob_get_contents());ob_end_clean(); ?>
          <?php ob_start(); ?><a href="<?php echo CRM_Utils_System::crmURL(array('p' => 'civicrm/contact/merge','q' => "reset=1&cid=".($this->_tpl_vars['cid'])."&oid=".($this->_tpl_vars['dupe_id'])), $this);?>
"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>merge<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></a><?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('merge', ob_get_contents());ob_end_clean(); ?>
          <tr class="<?php echo smarty_function_cycle(array('values' => "odd-row,even-row"), $this);?>
">
      <td><?php echo $this->_tpl_vars['link']; ?>
</td>
      <td style="text-align: right"><?php echo $this->_tpl_vars['merge']; ?>
</td>
      <td style="text-align: right"><a id='notDuplicate' href="#" title=<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>not a duplicate<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> onClick="processDupes( <?php echo $this->_tpl_vars['main']['srcID']; ?>
, <?php echo $this->_tpl_vars['main']['dstID']; ?>
, 'dupe-nondupe' );return false;"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>not a duplicate<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></a></td>
      </tr>
        <?php endif; ?>
      <?php endforeach; endif; unset($_from); ?>
    </table>
  <?php endif; ?>
</div>

<?php if ($this->_tpl_vars['context'] == 'search'): ?>
   <a href="<?php echo $this->_tpl_vars['backURL']; ?>
" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Done<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a>
<?php else: ?>
   <?php if ($this->_tpl_vars['gid']): ?>
      <?php ob_start(); ?><?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/dedupefind",'q' => "reset=1&rgid=".($this->_tpl_vars['rgid'])."&gid=".($this->_tpl_vars['gid'])."&action=renew",'a' => 1), $this);?>
<?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('backURL', ob_get_contents());ob_end_clean(); ?>
   <?php else: ?>
      <?php ob_start(); ?><?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/dedupefind",'q' => "reset=1&rgid=".($this->_tpl_vars['rgid'])."&action=renew",'a' => 1), $this);?>
<?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('backURL', ob_get_contents());ob_end_clean(); ?>
   <?php endif; ?>
   <a href="<?php echo $this->_tpl_vars['backURL']; ?>
" title="<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Refresh List of Duplicates<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>" onclick="return confirm('<?php $this->_tag_stack[] = array('ts', array('escape' => 'js')); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>This will refresh the duplicates list. Click OK to proceed.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>');" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Refresh Duplicates<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a>

   <?php if ($this->_tpl_vars['gid']): ?>
      <?php ob_start(); ?><?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/dedupefind",'q' => "reset=1&rgid=".($this->_tpl_vars['rgid'])."&gid=".($this->_tpl_vars['gid'])."&action=map",'a' => 1), $this);?>
<?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('backURL', ob_get_contents());ob_end_clean(); ?>
   <?php else: ?>
      <?php ob_start(); ?><?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/dedupefind",'q' => "reset=1&rgid=".($this->_tpl_vars['rgid'])."&action=map",'a' => 1), $this);?>
<?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('backURL', ob_get_contents());ob_end_clean(); ?>
   <?php endif; ?>
   <a href="<?php echo $this->_tpl_vars['backURL']; ?>
" title="<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Batch Merge Duplicate Contacts<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>" onclick="return confirm('<?php $this->_tag_stack[] = array('ts', array('escape' => 'js')); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>This will run the batch merge process on the listed duplicates. The operation will run in safe mode - only records with no direct data conflicts will be merged. Click OK to proceed if you are sure you wish to run this operation.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>');" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Batch Merge Duplicates<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a>

   <?php ob_start(); ?><?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/deduperules",'q' => "reset=1",'a' => 1), $this);?>
<?php $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('backURL', ob_get_contents());ob_end_clean(); ?>
  <a href="<?php echo $this->_tpl_vars['backURL']; ?>
" class="button crm-button-type-cancel"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Done<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a>
<?php endif; ?>
<div style="clear: both;"></div>
<?php else: ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/Contact/Form/DedupeFind.tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<?php endif; ?>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => 'CRM/common/dedupe.tpl', 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<?php echo '
<script type="text/javascript">
var oTable = null;
</script>
'; ?>

<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>