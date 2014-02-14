<?php /* Smarty version 2.6.27, created on 2014-02-13 17:16:35
         compiled from CRM/common/redirectJS.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('block', 'crmScope', 'CRM/common/redirectJS.tpl', 1, false),)), $this); ?>
<?php $this->_tag_stack[] = array('crmScope', array('extensionKey' => "")); $_block_repeat=true;smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start(); ?><html>
<head>
<script type="text/javascript">
  window.location = "<?php echo $this->_tpl_vars['redirectURL']; ?>
"
</script>
<title><?php echo $this->_tpl_vars['title']; ?>
</title>
</head>
<body>
<h2><?php echo $this->_tpl_vars['title']; ?>
</h2>
<p>
<?php echo $this->_tpl_vars['message']; ?>

</p>
</body>
</html><?php $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_crmScope($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>