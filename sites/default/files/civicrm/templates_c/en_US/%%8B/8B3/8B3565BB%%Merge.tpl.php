<?php /* Smarty version 2.6.27, created on 2014-02-13 21:07:30
         compiled from CRM/Contact/Form/Merge.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Contact/Form/Merge.tpl', 1, false),array('block', 'ts', 'CRM/Contact/Form/Merge.tpl', 28, false),array('function', 'help', 'CRM/Contact/Form/Merge.tpl', 28, false),array('function', 'crmURL', 'CRM/Contact/Form/Merge.tpl', 38, false),array('function', 'cycle', 'CRM/Contact/Form/Merge.tpl', 49, false),array('modifier', 'substr', 'CRM/Contact/Form/Merge.tpl', 60, false),array('modifier', 'strrpos', 'CRM/Contact/Form/Merge.tpl', 66, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><div class="crm-block crm-form-block crm-contact-merge-form-block">
<div id="help">
<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Click <strong>Merge</strong> to move data from the Duplicate Contact on the left into the Main Contact. In addition to the contact data (address, phone, email...), you may choose to move all or some of the related activity records (groups, contributions, memberships, etc.).<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> <?php echo smarty_function_help(array('id' => 'intro'), $this);?>

</div>

<div class="crm-submit-buttons"><?php if ($this->_tpl_vars['prev']): ?><a href="<?php echo $this->_tpl_vars['prev']; ?>
" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><< Prev<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a><?php endif; ?><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'top')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?><?php if ($this->_tpl_vars['next']): ?><a href="<?php echo $this->_tpl_vars['next']; ?>
" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Next >><?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a><?php endif; ?></div>

<div class="action-link">
      <a href="<?php echo $this->_tpl_vars['flip']; ?>
">&raquo; <?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Flip between original and duplicate contacts.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></a>
</div>

<div class="action-link">
       <a id='notDuplicate' href="#" title=<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Mark this pair as not a duplicate.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> onClick="processDupes( <?php echo $this->_tpl_vars['main_cid']; ?>
, <?php echo $this->_tpl_vars['other_cid']; ?>
, 'dupe-nondupe', 'merge-contact', '<?php echo CRM_Utils_System::crmURL(array('p' => "civicrm/contact/dedupefind",'q' => "reset=1&action=update&rgid=".($this->_tpl_vars['rgid'])), $this);?>
' );return false;">&raquo; <?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Mark this pair as not a duplicate.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></a>
</div>

<table>
  <tr class="columnheader">
    <th>&nbsp;</th>
    <th><a href="<?php echo CRM_Utils_System::crmURL(array('p' => 'civicrm/contact/view','q' => "reset=1&cid=".($this->_tpl_vars['other_cid'])), $this);?>
"><?php echo $this->_tpl_vars['other_name']; ?>
&nbsp;<em><?php echo $this->_tpl_vars['other_contact_subtype']; ?>
</em></a> (<?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>duplicate<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>)</th>
    <th><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Mark All<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?><br />==<?php echo $this->_tpl_vars['form']['toggleSelect']['html']; ?>
 ==&gt;</th>
    <th><a href="<?php echo CRM_Utils_System::crmURL(array('p' => 'civicrm/contact/view','q' => "reset=1&cid=".($this->_tpl_vars['main_cid'])), $this);?>
"><?php echo $this->_tpl_vars['main_name']; ?>
&nbsp;<em><?php echo $this->_tpl_vars['main_contact_subtype']; ?>
</em></a></th>
  </tr>
  <?php $_from = $this->_tpl_vars['rows']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['field'] => $this->_tpl_vars['row']):
?>
     <tr class="<?php echo smarty_function_cycle(array('values' => "odd-row,even-row"), $this);?>
">
        <td><?php echo $this->_tpl_vars['row']['title']; ?>
</td>
        <td>
           <?php if (! is_array ( $this->_tpl_vars['row']['other'] )): ?>
               <?php echo $this->_tpl_vars['row']['other']; ?>

           <?php else: ?>
               <?php echo $this->_tpl_vars['row']['other']['fileName']; ?>

           <?php endif; ?>
        </td>
        <td style='white-space: nowrap'><?php if ($this->_tpl_vars['form'][$this->_tpl_vars['field']]): ?>==<?php echo $this->_tpl_vars['form'][$this->_tpl_vars['field']]['html']; ?>
==&gt;<?php endif; ?></td>
        <td>
            <?php if (((is_array($_tmp=$this->_tpl_vars['row']['title'])) ? $this->_run_mod_handler('substr', true, $_tmp, 0, 5) : substr($_tmp, 0, 5)) == 'Email' || ((is_array($_tmp=$this->_tpl_vars['row']['title'])) ? $this->_run_mod_handler('substr', true, $_tmp, 0, 7) : substr($_tmp, 0, 7)) == 'Address' || ((is_array($_tmp=$this->_tpl_vars['row']['title'])) ? $this->_run_mod_handler('substr', true, $_tmp, 0, 2) : substr($_tmp, 0, 2)) == 'IM' || ((is_array($_tmp=$this->_tpl_vars['row']['title'])) ? $this->_run_mod_handler('substr', true, $_tmp, 0, 6) : substr($_tmp, 0, 6)) == 'OpenID' || ((is_array($_tmp=$this->_tpl_vars['row']['title'])) ? $this->_run_mod_handler('substr', true, $_tmp, 0, 5) : substr($_tmp, 0, 5)) == 'Phone'): ?>

          <?php $this->assign('position', ((is_array($_tmp=$this->_tpl_vars['field'])) ? $this->_run_mod_handler('strrpos', true, $_tmp, '_') : strrpos($_tmp, '_'))); ?>
                <?php $this->assign('blockId', ((is_array($_tmp=$this->_tpl_vars['field'])) ? $this->_run_mod_handler('substr', true, $_tmp, $this->_tpl_vars['position']+1) : substr($_tmp, $this->_tpl_vars['position']+1))); ?>
                <?php $this->assign('blockName', ((is_array($_tmp=$this->_tpl_vars['field'])) ? $this->_run_mod_handler('substr', true, $_tmp, 14, $this->_tpl_vars['position']-14) : substr($_tmp, 14, $this->_tpl_vars['position']-14))); ?>

                <?php echo $this->_tpl_vars['form']['location'][$this->_tpl_vars['blockName']][$this->_tpl_vars['blockId']]['locTypeId']['html']; ?>
&nbsp;
                <?php if ($this->_tpl_vars['blockName'] == 'email' || $this->_tpl_vars['blockName'] == 'phone'): ?>
     <span id="main_<?php echo $this->_tpl_vars['blockName']; ?>
_<?php echo $this->_tpl_vars['blockId']; ?>
_overwrite"><?php if ($this->_tpl_vars['row']['main']): ?>(overwrite)<?php echo $this->_tpl_vars['form']['location'][$this->_tpl_vars['blockName']][$this->_tpl_vars['blockId']]['operation']['html']; ?>
&nbsp;<br /><?php else: ?>(add)<?php endif; ?></span>
    <?php echo '
    <script type="text/javascript">
    function mergeBlock(blockname, element, blockId) {
        var allBlock = '; ?>
<?php echo $this->_tpl_vars['mainLocBlock']; ?>
<?php echo ';
        var block    = eval( "allBlock." + \'main_\'+ blockname + element.value);
        if(blockname == \'email\' || blockname == \'phone\'){
           var label = \'(overwrite)\'+ \'<span id="main_blockname_blockId_overwrite">'; ?>
<?php echo $this->_tpl_vars['form']['location'][$this->_tpl_vars['blockName']][$this->_tpl_vars['blockId']]['operation']['html']; ?>
<?php echo '<br /></span>\';
        }
        else {
          label = \'(overwrite)<br />\';
        }

        if ( !block ) {
                  block = \'\';
           label   = \'(add)\';
           }
         cj( "#main_"+ blockname +"_" + blockId ).html( block );
         cj( "#main_"+ blockname +"_" + blockId +"_overwrite" ).html( label );
    }
    </script>
    '; ?>

    <?php else: ?>
    <span id="main_<?php echo $this->_tpl_vars['blockName']; ?>
_<?php echo $this->_tpl_vars['blockId']; ?>
_overwrite"><?php if ($this->_tpl_vars['row']['main']): ?>(overwrite)<br /><?php else: ?>(add)<?php endif; ?></span>
                <?php endif; ?>

            <?php endif; ?>
                        <span id="main_<?php echo $this->_tpl_vars['blockName']; ?>
_<?php echo $this->_tpl_vars['blockId']; ?>
">
              <?php if (! is_array ( $this->_tpl_vars['row']['main'] )): ?>
                <?php echo $this->_tpl_vars['row']['main']; ?>

              <?php else: ?>
                <?php echo $this->_tpl_vars['row']['main']['fileName']; ?>

              <?php endif; ?>
            </span>
        </td>
     </tr>
  <?php endforeach; endif; unset($_from); ?>

  <?php $_from = $this->_tpl_vars['rel_tables']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['paramName'] => $this->_tpl_vars['params']):
?>
    <?php if ($this->_tpl_vars['paramName'] == 'move_rel_table_users'): ?>
      <tr class="<?php echo smarty_function_cycle(array('values' => "even-row,odd-row"), $this);?>
">
      <th><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Move related...<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></th><td><?php if ($this->_tpl_vars['otherUfId']): ?><a target="_blank" href="<?php echo $this->_tpl_vars['params']['other_url']; ?>
"><?php echo $this->_tpl_vars['otherUfName']; ?>
</a></td><td style='white-space: nowrap'>==<?php echo $this->_tpl_vars['form'][$this->_tpl_vars['paramName']]['html']; ?>
==&gt;<?php else: ?><td style='white-space: nowrap'></td><?php endif; ?></td><td><?php if ($this->_tpl_vars['mainUfId']): ?><a target="_blank" href="<?php echo $this->_tpl_vars['params']['main_url']; ?>
"><?php echo $this->_tpl_vars['mainUfName']; ?>
</a><?php endif; ?></td>
    </tr>
    <?php else: ?>
    <tr class="<?php echo smarty_function_cycle(array('values' => "even-row,odd-row"), $this);?>
">
      <th><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Move related...<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></th><td><a href="<?php echo $this->_tpl_vars['params']['other_url']; ?>
"><?php echo $this->_tpl_vars['params']['title']; ?>
</a></td><td style='white-space: nowrap'>==<?php echo $this->_tpl_vars['form'][$this->_tpl_vars['paramName']]['html']; ?>
==&gt;</td><td><a href="<?php echo $this->_tpl_vars['params']['main_url']; ?>
"><?php echo $this->_tpl_vars['params']['title']; ?>
</a><?php if ($this->_tpl_vars['form']['operation'][$this->_tpl_vars['paramName']]['add']['html']): ?>&nbsp;<?php echo $this->_tpl_vars['form']['operation'][$this->_tpl_vars['paramName']]['add']['html']; ?>
<?php endif; ?></td>
    </tr>
    <?php endif; ?>
  <?php endforeach; endif; unset($_from); ?>
</table>
<div class='form-item'>
  <!--<p><?php echo $this->_tpl_vars['form']['moveBelongings']['html']; ?>
 <?php echo $this->_tpl_vars['form']['moveBelongings']['label']; ?>
</p>-->
  <!--<p><?php echo $this->_tpl_vars['form']['deleteOther']['html']; ?>
 <?php echo $this->_tpl_vars['form']['deleteOther']['label']; ?>
</p>-->
</div>
<div class="message status">
    <p><strong><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>WARNING: The duplicate contact record WILL BE DELETED after the merge is complete.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></strong></p>
    <?php if ($this->_tpl_vars['user']): ?>
      <p><strong><?php $this->_tag_stack[] = array('ts', array('1' => $this->_tpl_vars['config']->userFramework)); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>There are %1 user accounts associated with both the original and duplicate contacts. Ensure that the Drupal User you want to retain is on the right - if necessary use the 'Flip between original and duplicate contacts.' option at top to swap the positions of the two records before doing the merge.
The user record associated with the duplicate contact will not be deleted, but will be un-linked from the associated contact record (which will be deleted).
You will need to manually delete that user (click on the link to open Drupal User account in new screen). You may need to give thought to how you handle any content or contents associated with that user.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></strong></p>
    <?php endif; ?>
    <?php if ($this->_tpl_vars['other_contact_subtype']): ?>
      <p><strong>The duplicate contact (the one that will be deleted) is a <em><?php echo $this->_tpl_vars['other_contact_subtype']; ?>
</em>. Any data related to this will be lost forever (there is no undo) if you complete the merge.</strong></p>
    <?php endif; ?>
</div>

<div class="crm-submit-buttons"><?php if ($this->_tpl_vars['prev']): ?><a href="<?php echo $this->_tpl_vars['prev']; ?>
" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><< Prev<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a><?php endif; ?><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'bottom')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?><?php if ($this->_tpl_vars['next']): ?><a href="<?php echo $this->_tpl_vars['next']; ?>
" class="button"><span><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Next >><?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></a><?php endif; ?></div>
</div>

<?php echo '
<script type="text/javascript">

cj(document).ready(function(){
    cj(\'table td input.form-checkbox\').each(function() {
       var ele = null;
       var element = cj(this).attr(\'id\').split(\'_\',3);

       switch ( element[\'1\'] ) {
           case \'addressee\':
                 var ele = \'#\' + element[\'0\'] + \'_\' + element[\'1\'];
                 break;

           case \'email\':
           case \'postal\':
                 var ele = \'#\' + element[\'0\'] + \'_\' + element[\'1\'] + \'_\' + element[\'2\'];
                 break;
       }

       if( ele ) {
          cj(this).bind( \'click\', function() {

              if( cj( this).attr( \'checked\' ) ){
                  cj(\'input\' + ele ).attr(\'checked\', true );
                  cj(\'input\' + ele + \'_custom\' ).attr(\'checked\', true );
              } else {
                  cj(\'input\' + ele ).attr(\'checked\', false );
                  cj(\'input\' + ele + \'_custom\' ).attr(\'checked\', false );
              }
          });
       }
    });
});

</script>
'; ?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/dedupe.tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>