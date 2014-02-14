<?php /* Smarty version 2.6.27, created on 2014-02-13 12:04:50
         compiled from CRM/Admin/Form/Setting/Mapping.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/Admin/Form/Setting/Mapping.tpl', 1, false),array('block', 'ts', 'CRM/Admin/Form/Setting/Mapping.tpl', 28, false),array('function', 'help', 'CRM/Admin/Form/Setting/Mapping.tpl', 28, false),array('modifier', 'crmAddClass', 'CRM/Admin/Form/Setting/Mapping.tpl', 39, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><div class="crm-block crm-form-block crm-map-form-block">
<div id="help">
    <?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>CiviCRM includes plugins for several mapping and geocoding web services. When your users save a contact or event location address, a geocoding service will convert the address into geographical coordinates, which are required for mapping. Yahoo&rsquo;s geocoder will also automatically populate the postal code field. Mapping services allow your users to display addresses on a map.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?> <?php echo smarty_function_help(array('id' => 'map-intro-id'), $this);?>

</div>
    <div class="crm-submit-buttons"><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'top')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?></div>
    <table class="form-layout-compressed">
         <tr class="crm-map-form-block-mapProvider">
             <td><?php echo $this->_tpl_vars['form']['mapProvider']['label']; ?>
</td>
             <td><?php echo $this->_tpl_vars['form']['mapProvider']['html']; ?>
<br />
             <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Choose the mapping provider that has the best coverage for the majority of your contact addresses.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
         </tr>
         <tr class="crm-map-form-block-mapAPIKey">
             <td><?php echo $this->_tpl_vars['form']['mapAPIKey']['label']; ?>
</td>
             <td><?php echo ((is_array($_tmp=$this->_tpl_vars['form']['mapAPIKey']['html'])) ? $this->_run_mod_handler('crmAddClass', true, $_tmp, 'huge') : smarty_modifier_crmAddClass($_tmp, 'huge')); ?>
<br />
             <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Enter your API Key or Application ID. An API Key is currently optional for Google Maps API, but may be helpful diagnosing any problems and required for higher volumes of requests. Refer to developers.google.com for the latest information.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
         </tr>
         <tr class="crm-map-form-block-geoProvider">
             <td><?php echo $this->_tpl_vars['form']['geoProvider']['label']; ?>
</td>
             <td><?php echo $this->_tpl_vars['form']['geoProvider']['html']; ?>
<br />
             <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>You may choose a different webservice for geocoding. This is required if there is no geo-coding plugin for your selected mapping provider. You can leave the Geocoding fields blank if you are using Google as your mapping provider.<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
         </tr>
         <tr class="crm-map-form-block-geoAPIKey">
             <td><?php echo $this->_tpl_vars['form']['geoAPIKey']['label']; ?>
</td>
             <td><?php echo ((is_array($_tmp=$this->_tpl_vars['form']['geoAPIKey']['html'])) ? $this->_run_mod_handler('crmAddClass', true, $_tmp, 'huge') : smarty_modifier_crmAddClass($_tmp, 'huge')); ?>
<br />
             <span class="description"><?php $this->_tag_stack[] = array('ts', array()); $_block_repeat=true;smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?>Enter the API key or Application ID associated with your geocoding provider (not required for Yahoo).<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_ts($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?></span></td>
         </tr>
    </table>
    <div class="crm-submit-buttons"><?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "CRM/common/formButtons.tpl", 'smarty_include_vars' => array('location' => 'bottom')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?></div>
</div>
<?php echo '
<script type="text/javascript">
cj(function() {
  showHideMapAPIkey( cj(\'#mapProvider\').val( ) );
});
function showHideMapAPIkey( mapProvider ) {
  if ( mapProvider && ( mapProvider == \'OpenStreetMaps\' ) ) {
    cj(\'#Mapping tr.crm-map-form-block-mapAPIKey\').hide( );
  } else {
    cj(\'#Mapping tr.crm-map-form-block-mapAPIKey\').show( );
  }
}
</script>
'; ?>

<?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>