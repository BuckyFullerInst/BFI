<?php /* Smarty version 2.6.27, created on 2014-02-13 11:55:35
         compiled from CRM/Mailing/Page/Event.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Mailing/Page/Event.tpl', 1, false),array('block', 'ts', 'CRM/Mailing/Page/Event.tpl', 60, false),array('function', 'counter', 'CRM/Mailing/Page/Event.tpl', 46, false),array('function', 'cycle', 'CRM/Mailing/Page/Event.tpl', 48, false),array('function', 'crmURL', 'CRM/Mailing/Page/Event.tpl', 99, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/pager.tpl", 'smarty_include_vars' => array('location' => 'top')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<?php if ($this->_tpl_vars['rows']): ?>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/jsortable.tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php echo '<table id="mailing_event"><thead><tr>'; ?><?php $_from = $this->_tpl_vars['columnHeaders']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['header']):
?><?php echo '<th>'; ?><?php if ($this->_tpl_vars['header']['sort']): ?><?php echo ''; ?><?php $this->assign('key', $this->_tpl_vars['header']['sort']); ?><?php echo ''; ?><?php echo $this->_tpl_vars['sort']->_response[$this->_tpl_vars['key']]['link']; ?><?php echo ''; ?><?php else: ?><?php echo ''; ?><?php echo $this->_tpl_vars['header']['name']; ?><?php echo ''; ?><?php endif; ?><?php echo '</th>'; ?><?php endforeach; endif; unset($_from); ?><?php echo '</tr></thead>'; ?><?php echo smarty_function_counter(array('start' => 0,'skip' => 1,'print' => false), $this);?><?php echo ''; ?><?php $_from = $this->_tpl_vars['rows']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['row']):
?><?php echo '<tr class="'; ?><?php echo smarty_function_cycle(array('values' => "odd-row,even-row"), $this);?><?php echo '">'; ?><?php $_from = $this->_tpl_vars['row']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['value']):
?><?php echo '<td>'; ?><?php echo $this->_tpl_vars['value']; ?><?php echo '</td>'; ?><?php endforeach; endif; unset($_from); ?><?php echo '</tr>'; ?><?php endforeach; endif; unset($_from); ?><?php echo '</table>'; ?>

<?php else: ?>
  <div class="messages status no-popup">
    <div class="icon inform-icon"></div>
    &nbsp;
    <?php $this->_tag_stack[] = array('ts', array('1' => $this->_tpl_vars['title'])); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>There are currently no %1.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>
  </div>
<?php endif; ?>

<div class="action-link">
  <a href="<?php echo $this->_tpl_vars['backUrl']; ?>
">&raquo; <?php echo $this->_tpl_vars['backUrlTitle']; ?>
</a>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/pager.tpl", 'smarty_include_vars' => array('location' => 'bottom')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<?php if ($this->_tpl_vars['pager'] && ( $this->_tpl_vars['pager']->_totalPages > 1 )): ?>
<?php echo '
  <script type="text/javascript">
    var totalPages = '; ?>
<?php echo $this->_tpl_vars['pager']->_totalPages; ?>
<?php echo ';
    cj(function () {
      cj("#crm-container .crm-pager input.form-submit").click(function () {
        submitPagerData(this);
      });
    });

    function submitPagerData(el) {
      var urlParams = \'\';
      var jumpTo = cj(el).parent().children(\'input[type=text]\').val();
      if (parseInt(jumpTo) == "Nan") {
        jumpTo = 1;
      }
      if (jumpTo > totalPages) {
        jumpTo = totalPages;
      }
      '; ?>

      <?php $_from = $this->_tpl_vars['pager']->_linkData; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['k'] => $this->_tpl_vars['val']):
?>
        <?php if ($this->_tpl_vars['k'] != 'crmPID' && $this->_tpl_vars['k'] != 'force' && $this->_tpl_vars['k'] != 'q'): ?>
        <?php echo '
        urlParams += \'&'; ?>
<?php echo $this->_tpl_vars['k']; ?>
=<?php echo $this->_tpl_vars['val']; ?>
<?php echo '\';
        '; ?>

        <?php endif; ?>
      <?php endforeach; endif; unset($_from); ?>
      <?php echo '
      urlParams += \'&crmPID=\' + parseInt(jumpTo);
      var submitUrl = '; ?>
'<?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/mailing/report/event",'q' => "force=1",'h' => 0), $this);?>
'<?php echo ';
      document.location = submitUrl + urlParams;
    }
  </script>
'; ?>

<?php endif; ?>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>